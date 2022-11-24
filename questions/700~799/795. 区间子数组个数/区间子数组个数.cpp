/* 区间子数组个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个元素都是正整数的数组A ，正整数 L 以及 R (L <= R)。

求连续、非空且其中最大元素满足大于等于L 小于等于R的子数组个数。

例如 :
输入:
A = [2, 1, 4, 3]
L = 2
R = 3
输出: 3
解释: 满足条件的子数组: [2], [2, 1], [3].
注意:

L, R  和 A[i] 都是整数，范围在 [0, 10^9]。
数组 A 的长度范围在[1, 50000]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-subarrays-with-bounded-maximum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        /* 记小于L的数为0，大于L小于R的数为1，大于R的数为2，则数组被2划分为各段，比如01200100010210，问题转化为求各段包含1的子数组的个数总和
           而各段又被1划分为各子段，包含1的子数组个数等于总的子数组个数减去只包含0的子数组个数
           比如00100010，包含1的子数组个数等于8*(8+1)/2-2*(2+1)/2-3*(3+1)/2-1*(1+1)/2 */
        A.push_back(R + 1);
        long long consecutive0 = 0, consecutive01 = 0, numSubarrTotal = 0, numSubarrOnly0 = 0;

        for (int num : A) {
            if (num < L) {
                consecutive0++;
                consecutive01++;
            }
            else if ((num >= L) && (num <= R)) {
                consecutive01++;
                numSubarrOnly0 += (consecutive0 * (consecutive0 + 1) / 2);
                consecutive0 = 0;
            }
            else {
                numSubarrOnly0 += (consecutive0 * (consecutive0 + 1) / 2);
                numSubarrTotal += (consecutive01 * (consecutive01 + 1) / 2 - numSubarrOnly0);
                consecutive0 = 0;
                consecutive01 = 0;
                numSubarrOnly0 = 0;
            }
        }

        return (int)numSubarrTotal;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 2,1,4,3 };
    check.checkInt(3, o.numSubarrayBoundedMax(A, 2, 3));
    
    A = { 73,55,36,5,55,14,9,7,72,52 };
    check.checkInt(22, o.numSubarrayBoundedMax(A, 32, 69));

    A = { 1,1,1,1 };
    check.checkInt(10, o.numSubarrayBoundedMax(A, 1, 2));

    A = { 1 };
    check.checkInt(0, o.numSubarrayBoundedMax(A, 2, 3));

    A = { 2 };
    check.checkInt(1, o.numSubarrayBoundedMax(A, 2, 3));

    A = { 1,2,3,4,5,6,7,8,9,10,1,2,3,4,5 };
    check.checkInt(18, o.numSubarrayBoundedMax(A, 4, 5));
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
