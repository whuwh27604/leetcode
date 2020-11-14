/* 环形子数组的最大和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个由整数数组 A 表示的环形数组 C，求 C 的非空子数组的最大可能和。

在此处，环形数组意味着数组的末端将会与开头相连呈环状。（形式上，当0 <= i < A.length 时 C[i] = A[i]，且当 i >= 0 时 C[i+A.length] = C[i]）

此外，子数组最多只能包含固定缓冲区 A 中的每个元素一次。（形式上，对于子数组 C[i], C[i+1], ..., C[j]，不存在 i <= k1, k2 <= j 其中 k1 % A.length = k2 % A.length）

 

示例 1：

输入：[1,-2,3,-2]
输出：3
解释：从子数组 [3] 得到最大和 3
示例 2：

输入：[5,-3,5]
输出：10
解释：从子数组 [5,5] 得到最大和 5 + 5 = 10
示例 3：

输入：[3,-1,2,-1]
输出：4
解释：从子数组 [2,-1,3] 得到最大和 2 + (-1) + 3 = 4
示例 4：

输入：[3,-2,2,-3]
输出：3
解释：从子数组 [3] 和 [3,-2,2] 都可以得到最大和 3
示例 5：

输入：[-2,-3,-1]
输出：-1
解释：从子数组 [-1] 得到最大和 -1
 

提示：

-30000 <= A[i] <= 30000
1 <= A.length <= 30000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-sum-circular-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        /* 分两种情况：1、maxSubSum不跨越A的末尾，则直接参考 53. 最大子序和 求解
           2、maxSubSum跨越A的末尾，则数组被划分为A[0,x]+A[x+1,y]+A[y+1,size-1]，其中A[y+1,size-1]+A[0,x]构成了maxSubSum。
           由于totalSum是一定的，此时A[x+1,y]一定是不跨越A的末尾的minSubSum，所以答案是maxSubSum和totalSum-minSubSum中大的一个。
           minSubSum需要注意边界条件，不能包含A[0]和A[size-1]，因为如果minSubSum是A[0,x]，那么maxSubSum就是A[x+1,size-1]，此时maxSubSum并没有跨越A的末尾 */
        int i, size = A.size();
        int preMaxSum = 0, maxSubSum = INT_MIN, preMinSum = 0, minSubSum = INT_MAX, totalSum = 0;

        for (i = 0; i < size; ++i) {
            preMaxSum = max(preMaxSum + A[i], A[i]);
            maxSubSum = max(maxSubSum, preMaxSum);

            if ((i != 0) && (i != size - 1)) {  // 求minSubSum时不包含首尾两点
                preMinSum = min(preMinSum + A[i], A[i]);
                minSubSum = min(minSubSum, preMinSum);
            }

            totalSum += A[i];
        }

        return (size > 2) ? max(maxSubSum, totalSum - minSubSum) : maxSubSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 1,-2,3,-2 };
    check.checkInt(3, o.maxSubarraySumCircular(A));

    A = { 5,-3,5 };
    check.checkInt(10, o.maxSubarraySumCircular(A));

    A = { 3,-1,2,-1 };
    check.checkInt(4, o.maxSubarraySumCircular(A));

    A = { 3,-2,2,-3 };
    check.checkInt(3, o.maxSubarraySumCircular(A));

    A = { -2,-3,-1 };
    check.checkInt(-1, o.maxSubarraySumCircular(A));

    A = { -1,-2,-3,10 };
    check.checkInt(10, o.maxSubarraySumCircular(A));

    A = { 1,2,3,-10 };
    check.checkInt(6, o.maxSubarraySumCircular(A));

    A = { -2 };
    check.checkInt(-2, o.maxSubarraySumCircular(A));
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
