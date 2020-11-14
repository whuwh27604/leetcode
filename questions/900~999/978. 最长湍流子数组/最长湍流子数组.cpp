/* 最长湍流子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
当 A 的子数组 A[i], A[i+1], ..., A[j] 满足下列条件时，我们称其为湍流子数组：

若 i <= k < j，当 k 为奇数时， A[k] > A[k+1]，且当 k 为偶数时，A[k] < A[k+1]；
或 若 i <= k < j，当 k 为偶数时，A[k] > A[k+1] ，且当 k 为奇数时， A[k] < A[k+1]。
也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。

返回 A 的最大湍流子数组的长度。

 

示例 1：

输入：[9,4,2,10,7,8,8,1,9]
输出：5
解释：(A[1] > A[2] < A[3] > A[4] < A[5])
示例 2：

输入：[4,8,12,16]
输出：2
示例 3：

输入：[100]
输出：1
 

提示：

1 <= A.length <= 40000
0 <= A[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-turbulent-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int i, size = A.size();
        int sign, prevSign = 0, turbulenceLen = 1, maxTurbulenceLen = 1;

        for (i = 1; i < size; ++i) {
            sign = (A[i] > A[i - 1]) ? 1 : ((A[i] < A[i - 1]) ? -1 : 0);

            if (sign * prevSign == -1) {
                ++turbulenceLen;
            }
            else {
                maxTurbulenceLen = (maxTurbulenceLen > turbulenceLen) ? maxTurbulenceLen : turbulenceLen;
                turbulenceLen = (sign == 0 ? 1 : 2);
            }

            prevSign = sign;
        }

        return (maxTurbulenceLen > turbulenceLen) ? maxTurbulenceLen : turbulenceLen;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 100 };
    check.checkInt(1, o.maxTurbulenceSize(A));

    A = { 100,100 };
    check.checkInt(1, o.maxTurbulenceSize(A));

    A = { 100,100,100 };
    check.checkInt(1, o.maxTurbulenceSize(A));

    A = { 100,101 };
    check.checkInt(2, o.maxTurbulenceSize(A));

    A = { 4,8,12,16 };
    check.checkInt(2, o.maxTurbulenceSize(A));

    A = { 9,4,2,10,7,8,8,1,9 };
    check.checkInt(5, o.maxTurbulenceSize(A));

    A = { 1,9,1,9,1,9 };
    check.checkInt(6, o.maxTurbulenceSize(A));

    A = { 0,1,9,1,9,1,9 };
    check.checkInt(6, o.maxTurbulenceSize(A));
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
