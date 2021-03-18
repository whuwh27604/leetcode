/* 删列造序 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定由 N 个小写字母字符串组成的数组 A，其中每个字符串长度相等。

选取一个删除索引序列，对于 A 中的每个字符串，删除对应每个索引处的字符。

比如，有 A = ["babca","bbazb"]，删除索引序列 {0, 1, 4}，删除后 A 为["bc","az"]。

假设，我们选择了一组删除索引 D，那么在执行删除操作之后，最终得到的数组的行中的每个元素都是按字典序排列的。

清楚起见，A[0] 是按字典序排列的（即，A[0][0] <= A[0][1] <= ... <= A[0][A[0].length - 1]），A[1] 是按字典序排列的（即，A[1][0] <= A[1][1] <= ... <= A[1][A[1].length - 1]），依此类推。

请你返回 D.length 的最小可能值。

 

示例 1：

输入：["babca","bbazb"]
输出：3
解释：
删除 0、1 和 4 这三列后，最终得到的数组是 A = ["bc", "az"]。
这两行是分别按字典序排列的（即，A[0][0] <= A[0][1] 且 A[1][0] <= A[1][1]）。
注意，A[0] > A[1] —— 数组 A 不一定是按字典序排列的。
示例 2：

输入：["edcba"]
输出：4
解释：如果删除的列少于 4 列，则剩下的行都不会按字典序排列。
示例 3：

输入：["ghi","def","abc"]
输出：0
解释：所有行都已按字典序排列。
 

提示：

1 <= A.length <= 100
1 <= A[i].length <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-columns-to-make-sorted-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        /* 令dp[i]表示以第i列为结尾构成LIS的长度，那么dp[i+1]=max(dp[j],dp[k]...)+1，其中j、k...列和i+1列可以构成一个升序 */
        int i, j, k, row = strs.size(), column = strs[0].size(), LIS = 1;
        vector<int> dp(column, 1);

        for (j = 1; j < column; ++j) {
            for (k = 0; k < j; ++k) {
                for (i = 0; i < row && strs[i][k] <= strs[i][j]; ++i) {}
                if (i == row) {
                    dp[j] = max(dp[j], dp[k] + 1);
                }
            }

            LIS = max(LIS, dp[j]);
        }

        return column - LIS;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> strs = { "babca","bbazb" };
    check.checkInt(3, o.minDeletionSize(strs));

    strs = { "edcba" };
    check.checkInt(4, o.minDeletionSize(strs));

    strs = { "ghi","def","abc" };
    check.checkInt(0, o.minDeletionSize(strs));
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
