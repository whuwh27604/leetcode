/* Bigram 分词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出第一个词 first 和第二个词 second，考虑在某些文本 text 中可能以 "first second third" 形式出现的情况，其中 second 紧随 first 出现，third 紧随 second 出现。

对于每种这样的情况，将第三个词 "third" 添加到答案中，并返回答案。

 

示例 1：

输入：text = "alice is a good girl she is a good student", first = "a", second = "good"
输出：["girl","student"]
示例 2：

输入：text = "we will we will rock you", first = "we", second = "will"
输出：["we","rock"]
 

提示：

1 <= text.length <= 1000
text 由一些用空格分隔的单词组成，每个单词都由小写英文字母组成
1 <= first.length, second.length <= 10
first 和 second 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/occurrences-after-bigram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <list>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        text.insert(text.begin(), 1, ' ');
        text.push_back(' ');

        unsigned int i = 0, len = text.size(), preSpaceIndex = 0;
        list<string> forwardTwoWords;
        vector<string> thirdWords;

        for (i = 1; i < len; i++) {
            if (text[i] != ' ') {
                continue;
            }

            string word(text, preSpaceIndex + 1, i - preSpaceIndex - 1);
            preSpaceIndex = i;

            if (word.empty()) {
                continue;
            }

            if (forwardTwoWords.size() != 2) {
                forwardTwoWords.push_back(word);
                continue;
            }

            if ((forwardTwoWords.front() == first) && (forwardTwoWords.back() == second)) {
                thirdWords.push_back(word);
            }

            forwardTwoWords.push_back(word);
            forwardTwoWords.pop_front();
        }

        return thirdWords;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> actual = o.findOcurrences("alice is a good girl she is a good student", "a", "good");
    vector<string> expected = { "girl","student" };
    check.checkStringVector(expected, actual);

    actual = o.findOcurrences("alice is a  good  girl she is a good student", "a", "good");
    expected = { "girl","student" };
    check.checkStringVector(expected, actual);

    actual = o.findOcurrences("a", "a", "a");
    expected = {  };
    check.checkStringVector(expected, actual);

    actual = o.findOcurrences("a a", "a", "a");
    expected = {  };
    check.checkStringVector(expected, actual);

    actual = o.findOcurrences("a a a", "a", "a");
    expected = { "a" };
    check.checkStringVector(expected, actual);

    actual = o.findOcurrences("a a a a", "a", "a");
    expected = { "a","a" };
    check.checkStringVector(expected, actual);

    actual = o.findOcurrences(" a  a  a  a ", "a", "a");
    expected = { "a","a" };
    check.checkStringVector(expected, actual);

    actual = o.findOcurrences("a b a b a b a b", "a", "b");
    expected = { "a","a","a" };
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
