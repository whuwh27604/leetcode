/* 检查整数及其两倍数是否存在.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr，请你检查是否存在两个整数 N 和 M，满足 N 是 M 的两倍（即，N = 2 * M）。

更正式地，检查是否存在两个下标 i 和 j 满足：

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
 

示例 1：

输入：arr = [10,2,5,3]
输出：true
解释：N = 10 是 M = 5 的两倍，即 10 = 2 * 5 。
示例 2：

输入：arr = [7,1,14,11]
输出：true
解释：N = 14 是 M = 7 的两倍，即 14 = 2 * 7 。
示例 3：

输入：arr = [3,1,7,11]
输出：false
解释：在该情况下不存在 N 和 M 满足 N = 2 * M 。
 

提示：

2 <= arr.length <= 500
-10^3 <= arr[i] <= 10^3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-n-and-its-double-exist
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int table[2001] = {0};
        int i, len = arr.size();

        for (i = 0; i < len; i++) {
            table[arr[i] + 1000]++;
        }

        for (i = 0; i < len; i++) {
            if ((arr[i] > 500) || (arr[i] < -500)) {
                continue;
            }

            if (arr[i] == 0) {
                if (table[1000] >= 2) {
                    return true;
                }
                continue;
            }

            if (table[arr[i] * 2 + 1000] != 0) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> arr = { 10,2,5,3 };
    check.checkBool(true, o.checkIfExist(arr));

    arr = { 7,1,14,11 };
    check.checkBool(true, o.checkIfExist(arr));

    arr = { 3,1,7,11 };
    check.checkBool(false, o.checkIfExist(arr));

    arr = { 500,1000,1000 };
    check.checkBool(true, o.checkIfExist(arr));

    arr = { -500,-1000,-500 };
    check.checkBool(true, o.checkIfExist(arr));

    arr = { 0,1000,-1000 };
    check.checkBool(false, o.checkIfExist(arr));

    arr = { 0,0,1000,-1000 };
    check.checkBool(true, o.checkIfExist(arr));
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
