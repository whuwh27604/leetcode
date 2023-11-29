/* 查找包含给定字符的单词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串数组 words 和一个字符 x 。

请你返回一个 下标数组 ，表示下标在数组中对应的单词包含字符 x 。

注意 ，返回的数组可以是 任意 顺序。



示例 1：

输入：words = ["leet","code"], x = "e"
输出：[0,1]
解释："e" 在两个单词中都出现了："leet" 和 "code" 。所以我们返回下标 0 和 1 。
示例 2：

输入：words = ["abc","bcd","aaaa","cbc"], x = "a"
输出：[0,2]
解释："a" 在 "abc" 和 "aaaa" 中出现了，所以我们返回下标 0 和 2 。
示例 3：

输入：words = ["abc","bcd","aaaa","cbc"], x = "z"
输出：[]
解释："z" 没有在任何单词中出现。所以我们返回空数组。


提示：

1 <= words.length <= 50
1 <= words[i].length <= 50
x 是一个小写英文字母。
words[i] 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        for (int i = 0; i < (int)words.size(); ++i) {
            for (char c : words[i]) {
                if (c == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "leet","code" };
    vector<int> actual = o.findWordsContaining(words, 'e');
    vector<int> expected = { 0,1 };
    check.checkIntVectorRandomOrder(expected, actual);

    words = { "abc","bcd","aaaa","cbc" };
    actual = o.findWordsContaining(words, 'a');
    expected = { 0,2 };
    check.checkIntVectorRandomOrder(expected, actual);

    words = { "abc","bcd","aaaa","cbc" };
    actual = o.findWordsContaining(words, 'z');
    expected = { };
    check.checkIntVectorRandomOrder(expected, actual);
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
