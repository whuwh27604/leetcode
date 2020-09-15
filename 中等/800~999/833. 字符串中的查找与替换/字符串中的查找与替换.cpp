/* 字符串中的查找与替换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
对于某些字符串 S，我们将执行一些替换操作，用新的字母组替换原有的字母组（不一定大小相同）。

每个替换操作具有 3 个参数：起始索引 i，源字 x 和目标字 y。规则是如果 x 从原始字符串 S 中的位置 i 开始，那么我们将用 y 替换出现的 x。如果没有，我们什么都不做。

举个例子，如果我们有 S = “abcd” 并且我们有一些替换操作 i = 2，x = “cd”，y = “ffff”，那么因为 “cd” 从原始字符串 S 中的位置 2 开始，我们将用 “ffff” 替换它。

再来看 S = “abcd” 上的另一个例子，如果我们有替换操作 i = 0，x = “ab”，y = “eee”，以及另一个替换操作 i = 2，x = “ec”，y = “ffff”，那么第二个操作将不执行任何操作，因为原始字符串中 S[2] = 'c'，与 x[0] = 'e' 不匹配。

所有这些操作同时发生。保证在替换时不会有任何重叠： S = "abc", indexes = [0, 1], sources = ["ab","bc"] 不是有效的测试用例。

 

示例 1：

输入：S = "abcd", indexes = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]
输出："eeebffff"
解释：
"a" 从 S 中的索引 0 开始，所以它被替换为 "eee"。
"cd" 从 S 中的索引 2 开始，所以它被替换为 "ffff"。
示例 2：

输入：S = "abcd", indexes = [0,2], sources = ["ab","ec"], targets = ["eee","ffff"]
输出："eeecd"
解释：
"ab" 从 S 中的索引 0 开始，所以它被替换为 "eee"。
"ec" 没有从原始的 S 中的索引 2 开始，所以它没有被替换。
 

提示：

0 <= indexes.length = sources.length = targets.length <= 100
0 < indexes[i] < S.length <= 1000
给定输入中的所有字符都是小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-and-replace-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int i, j, size = S.size();
        vector<int> replace(size, -1);
        string replacedString;

        for (i = 0; i < (int)indexes.size(); ++i) {
            replace[indexes[i]] = i;
        }

        for (i = 0; i < size; ++i) {
            int replaceIndex = replace[i];
            if (replaceIndex == -1) {
                replacedString += S[i];
                continue;
            }

            int replaceLen = sources[replaceIndex].size();
            for (j = 0; j < replaceLen; ++j) {
                if (S[i + j] != sources[replaceIndex][j]) {
                    break;
                }
            }

            if (j == replaceLen) {
                replacedString += targets[replaceIndex];
                i += (j - 1);
            }
            else {
                replacedString += S[i];
            }
        }

        return replacedString;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> indexes = { 0,2 };
    vector<string> sources = { "a","cd" };
    vector<string> targets = { "eee","ffff" };
    check.checkString("eeebffff", o.findReplaceString("abcd", indexes, sources, targets));

    indexes = { 0,2 };
    sources = { "ab","ec" };
    targets = { "eee","ffff" };
    check.checkString("eeecd", o.findReplaceString("abcd", indexes, sources, targets));

    indexes = { 4,6,1 };
    sources = { "md","tjgb","jf" };
    targets = { "foe","oov","e" };
    check.checkString("jjievdtjfb", o.findReplaceString("jjievdtjfb", indexes, sources, targets));

    indexes = { 0,1,2 };
    sources = { "a","a","a" };
    targets = { "bb","bb","bb" };
    check.checkString("bbbbbb", o.findReplaceString("aaa", indexes, sources, targets));

    indexes = { 0,1 };
    sources = { "ab","aa" };
    targets = { "bb","bbbb" };
    check.checkString("abbbb", o.findReplaceString("aaa", indexes, sources, targets));
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
