/* 文本左右对齐.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
示例:

输入:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
示例 2:

输入:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。
     第二行同样为左对齐，这是因为这行只包含一个单词。
示例 3:

输入:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/text-justification
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int start = 0, end = 0, wordsNum = words.size(), len = 0;
        vector<string> ans;

        for (end = 0; end < wordsNum; ++end) {
            if (len + (int)words[end].size() + end - start <= maxWidth) {
                len += words[end].size();
                continue;
            }

            int spaceNum = maxWidth - len;
            ans.push_back("");

            for (; start < end - 1; ++start) {
                ans.back() += words[start];
                int space = spaceNum % (end - start - 1) == 0 ? spaceNum / (end - start - 1) : spaceNum / (end - start - 1) + 1;
                ans.back().append(space, ' ');
                spaceNum -= space;
            }

            ans.back() += words[start++];
            ans.back().append(maxWidth - ans.back().size(), ' ');
            len = words[end].size();
        }

        ans.push_back("");
        for (; start < end; ++start) {
            ans.back() += words[start];
            ans.back() += ' ';
        }

        ans.back().pop_back();
        ans.back().append(maxWidth - ans.back().size(), ' ');

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "This","is","an","example","of","text","justification." };
    vector<string> actual = o.fullJustify(words, 16);
    vector<string> expected = { "This    is    an","example  of text","justification.  " };
    check.checkStringVector(expected, actual);

    words = { "What","must","be","acknowledgment","shall","be" };
    actual = o.fullJustify(words, 16);
    expected = { "What   must   be","acknowledgment  ","shall be        " };
    check.checkStringVector(expected, actual);

    words = { "Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do" };
    actual = o.fullJustify(words, 20);
    expected = { "Science  is  what we","understand      well","enough to explain to","a  computer.  Art is","everything  else  we","do                  " };
    check.checkStringVector(expected, actual);

    words = { "a","b","c" };
    actual = o.fullJustify(words, 1);
    expected = { "a","b","c" };
    check.checkStringVector(expected, actual);

    words = { "a","b","c" };
    actual = o.fullJustify(words, 2);
    expected = { "a ","b ","c " };
    check.checkStringVector(expected, actual);

    words = { "a","b","c" };
    actual = o.fullJustify(words, 5);
    expected = { "a b c" };
    check.checkStringVector(expected, actual);

    words = { "a","b","c" };
    actual = o.fullJustify(words, 7);
    expected = { "a b c  " };
    check.checkStringVector(expected, actual);
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
