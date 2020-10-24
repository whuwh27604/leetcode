/* 两个非重叠子数组的最大和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出非负整数数组 A ，返回两个非重叠（连续）子数组中元素的最大和，子数组的长度分别为 L 和 M。（这里需要澄清的是，长为 L 的子数组可以出现在长为 M 的子数组之前或之后。）

从形式上看，返回最大的 V，而 V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) 并满足下列条件之一：

 

0 <= i < i + L - 1 < j < j + M - 1 < A.length, 或
0 <= j < j + M - 1 < i < i + L - 1 < A.length.
 

示例 1：

输入：A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
输出：20
解释：子数组的一种选择中，[9] 长度为 1，[6,5] 长度为 2。
示例 2：

输入：A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
输出：29
解释：子数组的一种选择中，[3,8,1] 长度为 3，[8,9] 长度为 2。
示例 3：

输入：A = [2,1,5,6,0,9,5,0,3,8], L = 4, M = 3
输出：31
解释：子数组的一种选择中，[5,6,0,9] 长度为 4，[0,3,8] 长度为 3。
 

提示：

L >= 1
M >= 1
L + M <= A.length <= 1000
0 <= A[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-sum-of-two-non-overlapping-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int i, size = A.size(), sum = 0;
        int maxL = 0, maxM = 0, maxLM = 0, maxML = 0;
        vector<int> preSum(size + 1, 0), sumL(size, 0), sumM(size, 0);

        for (i = 0; i < size; ++i) {
            preSum[i + 1] = preSum[i] + A[i];

            if (i + 1 >= L) {
                sumL[i + 1 - L] = preSum[i + 1] - preSum[i + 1 - L];  // sumL[i]表示A从i开始L个数的和
            }
            
            if (i + 1 >= M) {
                sumM[i + 1 - M] = preSum[i + 1] - preSum[i + 1 - M];  // sumM[i]表示A从i开始M个数的和
            }
        }

        for (i = L; i <= size - M; ++i) {  // 假设L在左边，M在右边，遍历L到size-M，每次固定sumM[i]，找出最大的L
            maxL = max(maxL, sumL[i - L]);
            maxLM = max(maxLM, maxL + sumM[i]);
        }

        maxL = maxM = 0;
        for (i = M; i <= size - L; ++i) {  // 假设M在左边，L在右边，遍历M到size-L，每次固定sumL[i]，找出最大的M
            maxM = max(maxM, sumM[i - M]);
            maxML = max(maxML, maxM + sumL[i]);
        }

        return max(maxLM, maxML);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 0,6,5,2,2,5,1,9,4 };
    check.checkInt(20, o.maxSumTwoNoOverlap(A, 1, 2));

    A = { 3,8,1,3,2,1,8,9,0 };
    check.checkInt(29, o.maxSumTwoNoOverlap(A, 3, 2));

    A = { 2,1,5,6,0,9,5,0,3,8 };
    check.checkInt(31, o.maxSumTwoNoOverlap(A, 4, 3));

    A = { 2,8 };
    check.checkInt(10, o.maxSumTwoNoOverlap(A, 1, 1));

    A = { 1,2,3,4,5 };
    check.checkInt(15, o.maxSumTwoNoOverlap(A, 2, 3));
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
