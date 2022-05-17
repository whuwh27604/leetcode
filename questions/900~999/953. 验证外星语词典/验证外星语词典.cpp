/* 验证外星语词典.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。

给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。

 

示例 1：

输入：words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
输出：true
解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。
示例 2：

输入：words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
输出：false
解释：在该语言的字母表中，'d' 位于 'l' 之后，那么 words[0] > words[1]，因此单词序列不是按字典序排列的。
示例 3：

输入：words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
输出：false
解释：当前三个字符 "app" 匹配时，第二个字符串相对短一些，然后根据词典编纂规则 "apple" > "app"，因为 'l' > '∅'，其中 '∅' 是空白字符，定义为比任何其他字符都小（更多信息）。
 

提示：

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
在 words[i] 和 order 中的所有字符都是英文小写字母。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/verifying-an-alien-dictionary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> char2Number;

        for (int i = 0; i < 26; ++i) {
            char2Number[order[i]] = i;
        }

        for (int j = 1; j < (int)words.size(); ++j) {
            if (!isLessEqual(words[j - 1], words[j], char2Number)) {
                return false;
            }
        }

        return true;
    }

    bool isLessEqual(string& word1, string& word2, unordered_map<char, int>& char2Number) {
        int len1 = word1.size(), len2 = word2.size(), minLen = min(len1, len2);

        for (int i = 0; i < minLen; ++i) {
            if (char2Number[word1[i]] < char2Number[word2[i]]) {
                return true;
            }
            else if (char2Number[word1[i]] > char2Number[word2[i]]) {
                return false;
            }
        }

        return len1 <= len2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "hello","leetcode" };
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    check.checkBool(true, o.isAlienSorted(words, order));

    words = { "word","world","row" };
    order = "worldabcefghijkmnpqstuvxyz";
    check.checkBool(false, o.isAlienSorted(words, order));

    words = { "apple","app" };
    order = "abcdefghijklmnopqrstuvwxyz";
    check.checkBool(false, o.isAlienSorted(words, order));

    words = { "w" };
    order = "worldabcefghijkmnpqstuvxyz";
    check.checkBool(true, o.isAlienSorted(words, order));

    words = { "w","wh" };
    order = "worldabcefghijkmnpqstuvxyz";
    check.checkBool(true, o.isAlienSorted(words, order));

    words = { "apple","apple" };
    order = "abcdefghijklmnopqrstuvwxyz";
    check.checkBool(true, o.isAlienSorted(words, order));
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
