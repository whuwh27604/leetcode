/* 二倍数对数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个长度为偶数的整数数组 A，只有对 A 进行重组后可以满足 “对于每个 0 <= i < len(A) / 2，都有 A[2 * i + 1] = 2 * A[2 * i]” 时，返回 true；否则，返回 false。

 

示例 1：

输入：[3,1,3,6]
输出：false
示例 2：

输入：[2,1,2,6]
输出：false
示例 3：

输入：[4,-2,2,-4]
输出：true
解释：我们可以用 [-2,-4] 和 [2,4] 这两组组成 [-2,-4,2,4] 或是 [2,4,-2,-4]
示例 4：

输入：[1,2,4,16,8,4]
输出：false
 

提示：

0 <= A.length <= 30000
A.length 为偶数
-100000 <= A[i] <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/array-of-doubled-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int, int> positive, negative;
        partition(A, positive, negative);

        return checkPositive(positive) && checkNegative(negative);
    }

    void partition(vector<int>& A, map<int, int>& positive, map<int, int>& negative) {
        for (int num : A) {
            if (num >= 0) {
                if (positive.count(num) == 0) {
                    positive[num] = 1;
                }
                else {
                    ++positive[num];
                }
            }
            else {
                if (negative.count(num) == 0) {
                    negative[num] = 1;
                }
                else {
                    ++negative[num];
                }
            }
        }
    }

    bool checkPositive(map<int, int>& positive) {
        for (auto iter = positive.begin(); iter != positive.end(); ++iter) {
            if (iter->second == 0) {
                continue;
            }

            int doubled = iter->first * 2;
            if (positive.count(doubled) == 0 || positive[doubled] < iter->second) {
                return false;
            }

            positive[doubled] -= iter->second;
        }

        return true;
    }

    bool checkNegative(map<int, int>& negative) {
        for (auto iter = negative.rbegin(); iter != negative.rend(); ++iter) {
            if (iter->second == 0) {
                continue;
            }

            int doubled = iter->first * 2;
            if (negative.count(doubled) == 0 || negative[doubled] < iter->second) {
                return false;
            }

            negative[doubled] -= iter->second;
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 3,1,3,6 };
    check.checkBool(false, o.canReorderDoubled(A));

    A = { 2,1,2,6 };
    check.checkBool(false, o.canReorderDoubled(A));

    A = { 4,-2,2,-4 };
    check.checkBool(true, o.canReorderDoubled(A));

    A = { 1,2,4,16,8,4 };
    check.checkBool(false, o.canReorderDoubled(A));

    A = { 1,2,4,16,8,8 };
    check.checkBool(true, o.canReorderDoubled(A));

    A = {  };
    check.checkBool(true, o.canReorderDoubled(A));

    A = { 0,0,0,1 };
    check.checkBool(false, o.canReorderDoubled(A));

    A = { 0,0,0,0 };
    check.checkBool(true, o.canReorderDoubled(A));

    A = { -8,-4,-4,-2,-2,-1,0,0,1,2,2,4,4,8 };
    check.checkBool(true, o.canReorderDoubled(A));
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
