/* 蜡烛之间的盘子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从 0 开始的字符串 s ，它只包含字符 '*' 和 '|' ，其中 '*' 表示一个 盘子 ，'|' 表示一支 蜡烛 。

同时给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [lefti, righti] 表示 子字符串 s[lefti...righti] （包含左右端点的字符）。对于每个查询，你需要找到 子字符串中 在 两支蜡烛之间 的盘子的 数目 。如果一个盘子在 子字符串中 左边和右边 都 至少有一支蜡烛，那么这个盘子满足在 两支蜡烛之间 。

比方说，s = "||**||**|*" ，查询 [3, 8] ，表示的是子字符串 "*||**|" 。子字符串中在两支蜡烛之间的盘子数目为 2 ，子字符串中右边两个盘子在它们左边和右边 都 至少有一支蜡烛。
请你返回一个整数数组 answer ，其中 answer[i] 是第 i 个查询的答案。

 

示例 1:



输入：s = "**|**|***|", queries = [[2,5],[5,9]]
输出：[2,3]
解释：
- queries[0] 有两个盘子在蜡烛之间。
- queries[1] 有三个盘子在蜡烛之间。
示例 2:



输入：s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
输出：[9,0,0,0,0]
解释：
- queries[0] 有 9 个盘子在蜡烛之间。
- 另一个查询没有盘子在蜡烛之间。
 

提示：

3 <= s.length <= 105
s 只包含字符 '*' 和 '|' 。
1 <= queries.length <= 105
queries[i].length == 2
0 <= lefti <= righti < s.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plates-between-candles
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int i, size = s.size(), left = -1, right = size, sum = 0;
        vector<int> lefts(size), rights(size), presum(size), ans(queries.size());

        for (i = 0; i < size; ++i) {
            if (s[i] == '|') {
                left = i;
            }
            else {
                ++sum;
            }

            lefts[i] = left;
            presum[i] = sum;
        }

        for (i = size - 1; i >= 0; --i) {
            if (s[i] == '|') {
                right = i;
            }

            rights[i] = right;
        }

        for (i = 0; i < (int)queries.size(); ++i) {
            left = rights[queries[i][0]], right = lefts[queries[i][1]];
            ans[i] = left < right ? presum[right] - presum[left] : 0;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> queries = { {2,5},{5,9} };
    vector<int> actual = o.platesBetweenCandles("**|**|***|", queries);
    vector<int> expected = { 2,3 };
    check.checkIntVector(expected, actual);

    queries = { {1,17},{4,5},{14,17},{5,11},{15,16} };
    actual = o.platesBetweenCandles("***|**|*****|**||**|*", queries);
    expected = { 9,0,0,0,0 };
    check.checkIntVector(expected, actual);

    queries = { {1,1} };
    actual = o.platesBetweenCandles("***", queries);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    queries = { {1,1} };
    actual = o.platesBetweenCandles("|||", queries);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    queries = { {0,2} };
    actual = o.platesBetweenCandles("|*|", queries);
    expected = { 1 };
    check.checkIntVector(expected, actual);
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
