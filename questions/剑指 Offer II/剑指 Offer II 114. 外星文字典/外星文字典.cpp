/* 外星文字典.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
现有一种使用英语字母的外星文语言，这门语言的字母顺序与英语顺序不同。

给定一个字符串列表 words ，作为这门语言的词典，words 中的字符串已经 按这门新语言的字母顺序进行了排序 。

请你根据该词典还原出此语言中已知的字母顺序，并 按字母递增顺序 排列。若不存在合法字母顺序，返回 "" 。若存在多种可能的合法字母顺序，返回其中 任意一种 顺序即可。

字符串 s 字典顺序小于 字符串 t 有两种情况：

在第一个不同字母处，如果 s 中的字母在这门外星语言的字母顺序中位于 t 中字母之前，那么 s 的字典顺序小于 t 。
如果前面 min(s.length, t.length) 字母都相同，那么 s.length < t.length 时，s 的字典顺序也小于 t 。
 

示例 1：

输入：words = ["wrt","wrf","er","ett","rftt"]
输出："wertf"
示例 2：

输入：words = ["z","x"]
输出："zx"
示例 3：

输入：words = ["z","x","z"]
输出：""
解释：不存在合法字母顺序，因此返回 "" 。
 

提示：

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] 仅由小写英文字母组成
 

注意：本题与主站 269 题相同： https://leetcode-cn.com/problems/alien-dictionary/

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/Jf1JuT
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<char>> adjs('z' + 1);
        vector<bool> exist('z' + 1, false);
        vector<int> indegrees('z' + 1, 0);

        if (!getAdjs(words, adjs, exist)) {
            return "";
        }

        getIndegrees(adjs, indegrees);

        return topSort(adjs, exist, indegrees);
    }

    bool getAdjs(vector<string>& words, vector<vector<char>>& adjs, vector<bool>& exist) {
        int i, j, size = words.size();

        for (char c : words[0]) {
            exist[c] = true;
        }

        for (i = 1; i < size; ++i) {
            for (char c : words[i]) {
                exist[c] = true;
            }

            int len1 = words[i - 1].size(), len2 = words[i].size(), len = min(len1, len2);

            for (j = 0; j < len; ++j) {
                if (words[i - 1][j] != words[i][j]) {
                    adjs[words[i - 1][j]].push_back(words[i][j]);
                    break;
                }
            }

            if (j == len && len1 > len2) {
                return false;
            }
        }

        return true;
    }

    void getIndegrees(vector<vector<char>>& adjs, vector<int>& indegrees) {
        for (char from = 'a'; from <= 'z'; ++from) {
            for (char to : adjs[from]) {
                ++indegrees[to];
            }
        }
    }

    string topSort(vector<vector<char>>& adjs, vector<bool>& exist, vector<int>& indegrees) {
        queue<char> zeroIndegrees;
        string ans;

        for (char c = 'a'; c <= 'z'; ++c) {
            if (exist[c] && indegrees[c] == 0) {
                zeroIndegrees.push(c);  // 所有度数为0的点入队列
            }
        }

        while (!zeroIndegrees.empty()) {
            char from = zeroIndegrees.front();
            zeroIndegrees.pop();
            ans += from;  // 按出队列顺序加入答案

            for (char to : adjs[from]) {
                if (--indegrees[to] == 0) {  // 该节点所有下一跳度数减1，如果减为0了就加入队列
                    zeroIndegrees.push(to);
                }
            }
        }

        for (char c = 'a'; c <= 'z'; ++c) {
            if (indegrees[c] != 0) {  // 如果排序结束后还有度数不为0的点，说明存在环路，无法给出合理的顺序
                return "";
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "wrt","wrf","er","ett","rftt" };
    check.checkString("wertf", o.alienOrder(words));

    words = { "z","x" };
    check.checkString("zx", o.alienOrder(words));

    words = { "z","x","z" };
    check.checkString("", o.alienOrder(words));
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
