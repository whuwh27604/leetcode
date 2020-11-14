/* 构建回文串检测.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s，请你对 s 的子串进行检测。

每次检测，待检子串都可以表示为 queries[i] = [left, right, k]。我们可以 重新排列 子串 s[left], ..., s[right]，并从中选择 最多 k 项替换成任何小写英文字母。 

如果在上述检测过程中，子串可以变成回文形式的字符串，那么检测结果为 true，否则结果为 false。

返回答案数组 answer[]，其中 answer[i] 是第 i 个待检子串 queries[i] 的检测结果。

注意：在替换时，子串中的每个字母都必须作为 独立的 项进行计数，也就是说，如果 s[left..right] = "aaa" 且 k = 2，我们只能替换其中的两个字母。（另外，任何检测都不会修改原始字符串 s，可以认为每次检测都是独立的）

 

示例：

输入：s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
输出：[true,false,false,true,true]
解释：
queries[0] : 子串 = "d"，回文。
queries[1] : 子串 = "bc"，不是回文。
queries[2] : 子串 = "abcd"，只替换 1 个字符是变不成回文串的。
queries[3] : 子串 = "abcd"，可以变成回文的 "abba"。 也可以变成 "baab"，先重新排序变成 "bacd"，然后把 "cd" 替换为 "ab"。
queries[4] : 子串 = "abcda"，可以变成回文的 "abcba"。
 

提示：

1 <= s.length, queries.length <= 10^5
0 <= queries[i][0] <= queries[i][1] < s.length
0 <= queries[i][2] <= s.length
s 中只有小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/can-make-palindrome-from-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), false);
        int index = 0;
        vector<vector<int>> preSum;
        vector<int> letters(26, 0);
        preSum.push_back(letters);

        for (char c : s) {
            ++letters[c - 'a'];
            preSum.push_back(letters);
        }

        for (vector<int>& query : queries) {
            int singleCount = 0;

            for (int i = 0; i < 26; ++i) {
                if (((preSum[query[1] + 1][i] - preSum[query[0]][i]) & 1) == 1) {
                    ++singleCount;
                }
            }

            ans[index++] = (singleCount / 2 <= query[2]);
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> queries = { {3,3,0},{1,2,0},{0,3,1},{0,3,2},{0,4,1} };
    vector<bool> actual = o.canMakePaliQueries("abcda", queries);
    vector<bool> expected = { true,false,false,true,true };
    check.checkBoolVector(expected, actual);

    queries = { {1,1,1},{2,3,0},{3,3,1},{0,3,2},{1,3,3},{2,3,1},{3,3,1},{0,3,0},{1,1,1},{2,3,0},{3,3,1},{0,3,1},{1,1,1} };
    actual = o.canMakePaliQueries("hunu", queries);
    expected = { true,false,true,true,true,true,true,false,true,false,true,true,true };
    check.checkBoolVector(expected, actual);

    queries = { {0,1,0} ,{5,6,2},{5,5,1},{2,3,2} };
    actual = o.canMakePaliQueries("ofcvmry", queries);
    expected = { false,true,true,true };
    check.checkBoolVector(expected, actual);
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
