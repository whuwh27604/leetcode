/* 举报垃圾信息.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串数组 message 和一个字符串数组 bannedWords。

如果数组中 至少 存在两个单词与 bannedWords 中的任一单词 完全相同，则该数组被视为 垃圾信息。

如果数组 message 是垃圾信息，则返回 true；否则返回 false。



示例 1：

输入： message = ["hello","world","leetcode"], bannedWords = ["world","hello"]

输出： true

解释：

数组 message 中的 "hello" 和 "world" 都出现在数组 bannedWords 中。

示例 2：

输入： message = ["hello","programming","fun"], bannedWords = ["world","programming","leetcode"]

输出： false

解释：

数组 message 中只有一个单词（"programming"）出现在数组 bannedWords 中。



提示：

1 <= message.length, bannedWords.length <= 105
1 <= message[i].length, bannedWords[i].length <= 15
message[i] 和 bannedWords[i] 都只由小写英文字母组成。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> bans;
        int cnt = 0;

        for (string& word : bannedWords) {
            bans.insert(word);
        }

        for (string& word : message) {
            if (bans.count(word) != 0) {
                ++cnt;
            }
        }

        return cnt > 1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> message = { "a","a","b" };
    vector<string> bannedWords = { "a","e" };
    check.checkBool(true, o.reportSpam(message, bannedWords));

    message = { "hello","world","leetcode" };
    bannedWords = { "world","hello" };
    check.checkBool(true, o.reportSpam(message, bannedWords));

    message = { "hello","programming","fun" };
    bannedWords = { "world","programming","leetcode" };
    check.checkBool(false, o.reportSpam(message, bannedWords));
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
