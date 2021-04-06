/* 截断句子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
句子 是一个单词列表，列表中的单词之间用单个空格隔开，且不存在前导或尾随空格。每个单词仅由大小写英文字母组成（不含标点符号）。

例如，"Hello World"、"HELLO" 和 "hello world hello world" 都是句子。
给你一个句子 s​​​​​​ 和一个整数 k​​​​​​ ，请你将 s​​ 截断 ​，​​​使截断后的句子仅含 前 k​​​​​​ 个单词。返回 截断 s​​​​​​ 后得到的句子。

 

示例 1：

输入：s = "Hello how are you Contestant", k = 4
输出："Hello how are you"
解释：
s 中的单词为 ["Hello", "how" "are", "you", "Contestant"]
前 4 个单词为 ["Hello", "how", "are", "you"]
因此，应当返回 "Hello how are you"
示例 2：

输入：s = "What is the solution to this problem", k = 4
输出："What is the solution"
解释：
s 中的单词为 ["What", "is" "the", "solution", "to", "this", "problem"]
前 4 个单词为 ["What", "is", "the", "solution"]
因此，应当返回 "What is the solution"
示例 3：

输入：s = "chopper is not a tanuki", k = 5
输出："chopper is not a tanuki"
 

提示：

1 <= s.length <= 500
k 的取值范围是 [1,  s 中单词的数目]
s 仅由大小写英文字母和空格组成
s 中的单词之间由单个空格隔开
不存在前导或尾随空格

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/truncate-sentence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        string truncated;
        int count = 0;

        for (char c : s) {
            if (c == ' ') {
                if (++count == k) {
                    break;
                }
            }

            truncated += c;
        }

        return truncated;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("Hello how are you", o.truncateSentence("Hello how are you Contestant", 4));
    check.checkString("What is the solution", o.truncateSentence("What is the solution to this problem", 4));
    check.checkString("chopper is not a tanuki", o.truncateSentence("chopper is not a tanuki", 5));
    check.checkString("a", o.truncateSentence("a", 1));
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
