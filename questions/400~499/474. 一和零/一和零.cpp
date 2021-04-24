/* 一和零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

 

示例 1：

输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
输出：4
解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。
示例 2：

输入：strs = ["10", "0", "1"], m = 1, n = 1
输出：2
解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
 

提示：

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] 仅由 '0' 和 '1' 组成
1 <= m, n <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ones-and-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int i, j, k, size = strs.size(), maxForm = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        dp[0][0] = 0;

        for (k = 0; k < size; ++k) {
            int zeros = 0, ones = 0;
            for (char c : strs[k]) {
                c == '0' ? ++zeros : ++ones;
            }

            for (i = m - zeros; i >= 0; --i) {
                for (j = n - ones; j >= 0; --j) {
                    if (dp[i][j] != -1) {
                        dp[i + zeros][j + ones] = max(dp[i + zeros][j + ones], dp[i][j] + 1);
                    }
                }
            }
        }

        for (i = 0; i <= m; ++i) {
            for (j = 0; j <= n; ++j) {
                maxForm = max(maxForm, dp[i][j]);
            }
        }

        return maxForm;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> strs = { "10","0001","111001","1","0" };
    check.checkInt(4, o.findMaxForm(strs, 5, 3));

    strs = { "10","0","1" };
    check.checkInt(2, o.findMaxForm(strs, 1, 1));

    strs = { "10","0001","111001","1","0" };
    check.checkInt(3, o.findMaxForm(strs, 4, 3));

    strs = { "0","0","1","1" };
    check.checkInt(4, o.findMaxForm(strs, 2, 2));

    strs = { "1100" };
    check.checkInt(0, o.findMaxForm(strs, 1, 1));

    strs = { "10" };
    check.checkInt(1, o.findMaxForm(strs, 1, 1));

    strs = { "0","11","01","0","101","1","1","1","0","0","0","0","1","0","11","1","1","1000" };
    check.checkInt(17, o.findMaxForm(strs, 9, 14));

    strs = { "0","11","1000","01","0","101","1","1","1","0","0","0","0","1","0","0110101","0","11","01","00","01111","0011","1","1000","0","11101","1","0","10","0111" };
    check.checkInt(17, o.findMaxForm(strs, 9, 80));
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
