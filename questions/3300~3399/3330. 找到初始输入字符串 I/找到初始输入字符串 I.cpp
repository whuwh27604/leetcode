/* 找到初始输入字符串 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Alice 正在她的电脑上输入一个字符串。但是她打字技术比较笨拙，她 可能 在一个按键上按太久，导致一个字符被输入 多次 。

尽管 Alice 尽可能集中注意力，她仍然可能会犯错 至多 一次。

给你一个字符串 word ，它表示 最终 显示在 Alice 显示屏上的结果。

请你返回 Alice 一开始可能想要输入字符串的总方案数。



示例 1：

输入：word = "abbcccc"

输出：5

解释：

可能的字符串包括："abbcccc" ，"abbccc" ，"abbcc" ，"abbc" 和 "abcccc" 。

示例 2：

输入：word = "abcd"

输出：1

解释：

唯一可能的字符串是 "abcd" 。

示例 3：

输入：word = "aaaa"

输出：4



提示：

1 <= word.length <= 100
word 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int size = (int)word.size(), count = 1;

        for (int i = 1; i < size; ++i) {
            if (word[i] == word[i - 1]) {
                ++count;
            }
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(5, o.possibleStringCount("abbcccc"));
    check.checkInt(1, o.possibleStringCount("abcd"));
    check.checkInt(4, o.possibleStringCount("aaaa"));
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
