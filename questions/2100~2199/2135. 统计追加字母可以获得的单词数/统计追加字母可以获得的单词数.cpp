/* 统计追加字母可以获得的单词数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的字符串数组 startWords 和 targetWords 。每个字符串都仅由 小写英文字母 组成。

对于 targetWords 中的每个字符串，检查是否能够从 startWords 中选出一个字符串，执行一次 转换操作 ，得到的结果与当前 targetWords 字符串相等。

转换操作 如下面两步所述：

追加 任何 不存在 于当前字符串的任一小写字母到当前字符串的末尾。
例如，如果字符串为 "abc" ，那么字母 'd'、'e' 或 'y' 都可以加到该字符串末尾，但 'a' 就不行。如果追加的是 'd' ，那么结果字符串为 "abcd" 。
重排 新字符串中的字母，可以按 任意 顺序重新排布字母。
例如，"abcd" 可以重排为 "acbd"、"bacd"、"cbda"，以此类推。注意，它也可以重排为 "abcd" 自身。
找出 targetWords 中有多少字符串能够由 startWords 中的 任一 字符串执行上述转换操作获得。返回 targetWords 中这类 字符串的数目 。

注意：你仅能验证 targetWords 中的字符串是否可以由 startWords 中的某个字符串经执行操作获得。startWords  中的字符串在这一过程中 不 发生实际变更。

 

示例 1：

输入：startWords = ["ant","act","tack"], targetWords = ["tack","act","acti"]
输出：2
解释：
- 为了形成 targetWords[0] = "tack" ，可以选用 startWords[1] = "act" ，追加字母 'k' ，并重排 "actk" 为 "tack" 。
- startWords 中不存在可以用于获得 targetWords[1] = "act" 的字符串。
  注意 "act" 确实存在于 startWords ，但是 必须 在重排前给这个字符串追加一个字母。
- 为了形成 targetWords[2] = "acti" ，可以选用 startWords[1] = "act" ，追加字母 'i' ，并重排 "acti" 为 "acti" 自身。
示例 2：

输入：startWords = ["ab","a"], targetWords = ["abc","abcd"]
输出：1
解释：
- 为了形成 targetWords[0] = "abc" ，可以选用 startWords[0] = "ab" ，追加字母 'c' ，并重排为 "abc" 。
- startWords 中不存在可以用于获得 targetWords[1] = "abcd" 的字符串。
 

提示：

1 <= startWords.length, targetWords.length <= 5 * 104
1 <= startWords[i].length, targetWords[j].length <= 26
startWords 和 targetWords 中的每个字符串都仅由小写英文字母组成
在 startWords 或 targetWords 的任一字符串中，每个字母至多出现一次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-words-obtained-after-adding-a-letter
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        vector<unordered_set<int>> startMasks(27);
        int count = 0;

        getStartMasks(startWords, startMasks);

        for (string& word : targetWords) {
            if (search(word, startMasks)) {
                ++count;
            }
        }

        return count;
    }

    void getStartMasks(vector<string>& startWords, vector<unordered_set<int>>& startMasks) {
        for (string& word : startWords) {
            int mask = 0;

            for (char c : word) {
                mask |= (1 << (c - 'a'));
            }

            startMasks[word.size()].insert(mask);
        }
    }

    bool search(string& word, vector<unordered_set<int>>& startMasks) {
        int mask = 0, bit;

        for (char c : word) {
            mask |= (1 << (c - 'a'));
        }

        for (bit = 1; bit < (1 << 26); bit <<= 1) {
            if ((mask & bit) != 0 && startMasks[word.size() - 1].count(mask ^ bit) != 0) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> startWords = { "ant","act","tack" };
    vector<string> targetWords = { "tack","act","acti" };
    check.checkInt(2, o.wordCount(startWords, targetWords));

    startWords = { "ab","a" };
    targetWords = { "abc","abcd" };
    check.checkInt(1, o.wordCount(startWords, targetWords));

    startWords = { "z" };
    targetWords = { "z" };
    check.checkInt(0, o.wordCount(startWords, targetWords));

    startWords = { "z" };
    targetWords = { "za" };
    check.checkInt(1, o.wordCount(startWords, targetWords));

    startWords = { "g","fo","j" };
    targetWords = { "jg","fov" };
    check.checkInt(2, o.wordCount(startWords, targetWords));
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
