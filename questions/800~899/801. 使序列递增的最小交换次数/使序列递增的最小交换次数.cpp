/* 使序列递增的最小交换次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们有两个长度相等且不为空的整型数组 A 和 B 。

我们可以交换 A[i] 和 B[i] 的元素。注意这两个元素在各自的序列中应该处于相同的位置。

在交换过一些元素之后，数组 A 和 B 都应该是严格递增的（数组严格递增的条件仅为A[0] < A[1] < A[2] < ... < A[A.length - 1]）。

给定数组 A 和 B ，请返回使得两个数组均保持严格递增状态的最小交换次数。假设给定的输入总是有效的。

示例:
输入: A = [1,3,5,4], B = [1,2,3,7]
输出: 1
解释:
交换 A[3] 和 B[3] 后，两个数组如下:
A = [1, 3, 5, 7] ， B = [1, 2, 3, 4]
两个数组均为严格递增的。
注意:

A, B 两个数组的长度总是相等的，且长度的范围为 [1, 1000]。
A[i], B[i] 均为 [0, 2000]区间内的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-swaps-to-make-sequences-increasing
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int i, size = A.size();
        /* dp[i].first表示如果A[i-1]/B[i-1]不交换，从A[i]/B[i]位置到结尾递增，需要交换的次数，
           dp[i].second表示如果A[i-1]/B[i-1]交换，从A[i]/B[i]位置到结尾递增，需要交换的次数 */
        vector<pair<int, int>> dp(size + 1, pair<int, int>{INT_MAX, INT_MAX});
        dp[size] = { 0, 0 };

        for (i = size - 1; i > 0; --i) {
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {  // A[i - 1]、A[i]和B[i - 1]、B[i]已经是递增的
                dp[i].first = dp[i + 1].first;  // A[i-1]/B[i-1]没有交换，所以A[i]/B[i]也不用交换，剩下还需要dp[i + 1].first
                dp[i].second = 1 + dp[i + 1].second;  // A[i-1]/B[i-1]交换了，A[i]/B[i]也需要跟着交换，剩下还需要dp[i+1].second次
            }

            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {  // 交换A[i]/B[i]后形成递增
                dp[i].first = min(dp[i].first, 1 + dp[i + 1].second);  // 因为题目有解，所以只能是上面两种情况。同时满足时取小的
                dp[i].second = min(dp[i].second, dp[i + 1].first);
            }
        }

        return min(dp[1].first, 1 + dp[1].second);  // A[0]/B[0]不需要和前面的字符比较，选择交换和不交换两种情况小的即可
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 1,3,5,4 };
    vector<int> B = { 1,2,3,7 };
    check.checkInt(1, o.minSwap(A, B));

    A = { 2,1,6,9,10,13,13,16,19,26,23,24,25,27,32,31,35,36,37,39 };
    B = { 0,5,8,8,10,12,14,15,22,22,28,29,30,31,30,33,33,36,37,38 };
    check.checkInt(6, o.minSwap(A, B));

    A = { 2 };
    B = { 0 };
    check.checkInt(0, o.minSwap(A, B));

    A = { 2,1 };
    B = { 0,3 };
    check.checkInt(1, o.minSwap(A, B));
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
