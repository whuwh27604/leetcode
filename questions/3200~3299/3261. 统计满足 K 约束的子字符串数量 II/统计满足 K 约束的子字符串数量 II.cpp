/* 统计满足 K 约束的子字符串数量 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 二进制 字符串 s 和一个整数 k。

另给你一个二维整数数组 queries ，其中 queries[i] = [li, ri] 。

如果一个 二进制字符串 满足以下任一条件，则认为该字符串满足 k 约束：

字符串中 0 的数量最多为 k。
字符串中 1 的数量最多为 k。
返回一个整数数组 answer ，其中 answer[i] 表示 s[li..ri] 中满足 k 约束 的
子字符串
 的数量。



示例 1：

输入：s = "0001111", k = 2, queries = [[0,6]]

输出：[26]

解释：

对于查询 [0, 6]， s[0..6] = "0001111" 的所有子字符串中，除 s[0..5] = "000111" 和 s[0..6] = "0001111" 外，其余子字符串都满足 k 约束。

示例 2：

输入：s = "010101", k = 1, queries = [[0,5],[1,4],[2,3]]

输出：[15,9,3]

解释：

s 的所有子字符串中，长度大于 3 的子字符串都不满足 k 约束。



提示：

1 <= s.length <= 105
s[i] 是 '0' 或 '1'
1 <= k <= s.length
1 <= queries.length <= 105
queries[i] == [li, ri]
0 <= li <= ri < s.length
所有查询互不相同
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = (int)s.size(), m = (int)queries.size();
        int left = 0, zero = 0, one = 0;
        vector<int> lefts(n);
        vector<long long> presum(n + 1, 0), ans(m);

        for (int right = 0; right < n; ++right) {
            s[right] == '0' ? ++zero : ++one;

            while (zero > k && one > k) {
                s[left++] == '0' ? --zero : --one;
            }

            lefts[right] = left;  // lefts数组单调递增
            presum[right + 1] = presum[right] + right - left + 1;
        }

        for (int i = 0; i < m; ++i) {
            int ql = queries[i][0], qr = queries[i][1];
            int mid = (int)distance(lefts.begin(), lower_bound(lefts.begin(), lefts.end(), ql));  // 第一个lefts[right] >= ql的位置
            if (mid <= qr) {
                ans[i] = presum[qr + 1] - presum[mid];  // 区间[mid, qr]的right，其left落在区间[ql, qr]，所以合法数组全部加入答案
                int len = mid - ql;  // 区间[ql, mid - 1]的right，其left在ql左边，所以每个right，合法数组只能统计到ql，个数依次是[1,2,...,len]
                ans[i] += ((long long)1 + len) * len / 2;
            }
            else {  // 所有right的lefts[right]都在ql左边
                int len = qr - ql + 1;
                ans[i] = ((long long)1 + len) * len / 2;
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> queries = { {0,5},{1,4},{2,3} };
    vector<long long> actual = o.countKConstraintSubstrings("010101", 1, queries);
    vector<long long> expected = { 15,9,3 };
    check.checkLongLongVector(expected, actual);

    queries = { {0,6} };
    actual = o.countKConstraintSubstrings("0001111", 2, queries);
    expected = { 26 };
    check.checkLongLongVector(expected, actual);
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
