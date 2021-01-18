/* 单调数列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果数组是单调递增或单调递减的，那么它是单调的。

如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。 如果对于所有 i <= j，A[i]> = A[j]，那么数组 A 是单调递减的。

当给定的数组 A 是单调数组时返回 true，否则返回 false。

 

示例 1：

输入：[1,2,2,3]
输出：true
示例 2：

输入：[6,5,4,4]
输出：true
示例 3：

输入：[1,3,2]
输出：false
示例 4：

输入：[1,2,4,5]
输出：true
示例 5：

输入：[1,1,1]
输出：true
 

提示：

1 <= A.length <= 50000
-100000 <= A[i] <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/monotonic-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool increasing = false, decreasing = false;
        int a = A[0], b;

        for (unsigned int i = 1; i < A.size(); i++) {
            b = A[i];
            if (b > a) {
                increasing = true;
            }
            else if (a > b) {
                decreasing = true;
            }

            if (increasing && decreasing) {
                return false;
            }

            a = b;
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 1,2,2,3 };
    check.checkBool(true, o.isMonotonic(A));

    A = { 6,5,4,4 };
    check.checkBool(true, o.isMonotonic(A));

    A = { 1,3,2 };
    check.checkBool(false, o.isMonotonic(A));

    A = { 1,2,4,5 };
    check.checkBool(true, o.isMonotonic(A));

    A = { 1,1,1 };
    check.checkBool(true, o.isMonotonic(A));

    A = { 1 };
    check.checkBool(true, o.isMonotonic(A));

    A = { 1,1,2,3 };
    check.checkBool(true, o.isMonotonic(A));

    A = { 1,1,0,-2 };
    check.checkBool(true, o.isMonotonic(A));

    A = { 5,5,6,4 };
    check.checkBool(false, o.isMonotonic(A));

    A = { 5,4,4,5 };
    check.checkBool(false, o.isMonotonic(A));
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
