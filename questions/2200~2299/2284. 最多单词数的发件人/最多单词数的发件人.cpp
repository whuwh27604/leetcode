/* 最多单词数的发件人.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个聊天记录，共包含 n 条信息。给你两个字符串数组 messages 和 senders ，其中 messages[i] 是 senders[i] 发出的一条 信息 。

一条 信息 是若干用单个空格连接的 单词 ，信息开头和结尾不会有多余空格。发件人的 单词计数 是这个发件人总共发出的 单词数 。注意，一个发件人可能会发出多于一条信息。

请你返回发出单词数 最多 的发件人名字。如果有多个发件人发出最多单词数，请你返回 字典序 最大的名字。

注意：

字典序里，大写字母小于小写字母。
"Alice" 和 "alice" 是不同的名字。
 

示例 1：

输入：messages = ["Hello userTwooo","Hi userThree","Wonderful day Alice","Nice day userThree"], senders = ["Alice","userTwo","userThree","Alice"]
输出："Alice"
解释：Alice 总共发出了 2 + 3 = 5 个单词。
userTwo 发出了 2 个单词。
userThree 发出了 3 个单词。
由于 Alice 发出单词数最多，所以我们返回 "Alice" 。
示例 2：

输入：messages = ["How is leetcode for everyone","Leetcode is useful for practice"], senders = ["Bob","Charlie"]
输出："Charlie"
解释：Bob 总共发出了 5 个单词。
Charlie 总共发出了 5 个单词。
由于最多单词数打平，返回字典序最大的名字，也就是 Charlie 。
 

提示：

n == messages.length == senders.length
1 <= n <= 104
1 <= messages[i].length <= 100
1 <= senders[i].length <= 10
messages[i] 包含大写字母、小写字母和 ' ' 。
messages[i] 中所有单词都由 单个空格 隔开。
messages[i] 不包含前导和后缀空格。
senders[i] 只包含大写英文字母和小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/sender-with-largest-word-count
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int i, size = senders.size(), maxWords = 0;
        unordered_map<string, int> count;
        string maxSender;

        for (i = 0; i < size; ++i) {
            count[senders[i]] += getWords(messages[i]);
        }

        for (auto& cnt : count) {
            if (cnt.second > maxWords) {
                maxWords = cnt.second;
                maxSender = cnt.first;
            }
            else if (cnt.second == maxWords && cnt.first > maxSender) {
                maxSender = cnt.first;
            }
        }

        return maxSender;
    }

    int getWords(string& message) {
        int words = 1;

        for (char c : message) {
            if (c == ' ') {
                ++words;
            }
        }

        return words;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> messages = { "Hello userTwooo","Hi userThree","Wonderful day Alice","Nice day userThree" };
    vector<string> senders = { "Alice","userTwo","userThree","Alice" };
    check.checkString("Alice", o.largestWordCount(messages, senders));

    messages = { "How is leetcode for everyone","Leetcode is useful for practice" };
    senders = { "Bob","Charlie" };
    check.checkString("Charlie", o.largestWordCount(messages, senders));

    messages = { "a","a" };
    senders = { "B","b" };
    check.checkString("b", o.largestWordCount(messages, senders));

    messages = { "a","a" };
    senders = { "B","Bb" };
    check.checkString("Bb", o.largestWordCount(messages, senders));
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
