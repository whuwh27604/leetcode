/* 重复 N 次的元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在大小为 2N 的数组 A 中有 N+1 个不同的元素，其中有一个元素重复了 N 次。

返回重复了 N 次的那个元素。

 

示例 1：

输入：[1,2,3,3]
输出：3
示例 2：

输入：[2,1,2,5,3,2]
输出：2
示例 3：

输入：[5,1,5,2,5,3,5,4]
输出：5
 

提示：

4 <= A.length <= 10000
0 <= A[i] < 10000
A.length 为偶数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-repeated-element-in-size-2n-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (unsigned int i = 0; i < (A.size() - 3); i++) {
            int number = repeatedNum(A[i], A[i + 1], A[i + 2], A[i + 3]);
            if (number != -1) {
                return number;
            }
        }

        return -1;
    }

    int repeatedNum(int a, int b, int c, int d) {
        if ((a == b) || (a == c) || (a == d)) {
            return a;
        }

        if ((b == c) || (b == d)) {
            return b;
        }

        if (c == d) {
            return c;
        }

        return -1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 1,2,3,3 };
    check.checkInt(3, o.repeatedNTimes(A));

    A = { 1,2,3,4,4,4 };
    check.checkInt(4, o.repeatedNTimes(A));

    A = { 0,0,1,2 };
    check.checkInt(0, o.repeatedNTimes(A));
    
    A = { 2,1,2,5,3,2 };
    check.checkInt(2, o.repeatedNTimes(A));

    A = { 5,1,5,2,5,3,5,4 };
    check.checkInt(5, o.repeatedNTimes(A));

    A = { 1,2,3,4,5,6,6,6,6,6 };
    check.checkInt(6, o.repeatedNTimes(A));

    A = { 9,5,6,9 };
    check.checkInt(9, o.repeatedNTimes(A));
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
