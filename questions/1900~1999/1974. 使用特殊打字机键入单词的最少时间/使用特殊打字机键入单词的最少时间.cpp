/* 使用特殊打字机键入单词的最少时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个特殊打字机，它由一个 圆盘 和一个 指针 组成， 圆盘上标有小写英文字母 'a' 到 'z'。只有 当指针指向某个字母时，它才能被键入。指针 初始时 指向字符 'a' 。


每一秒钟，你可以执行以下操作之一：

将指针 顺时针 或者 逆时针 移动一个字符。
键入指针 当前 指向的字符。
给你一个字符串 word ，请你返回键入 word 所表示单词的 最少 秒数 。

 

示例 1：

输入：word = "abc"
输出：5
解释：
单词按如下操作键入：
- 花 1 秒键入字符 'a' in 1 ，因为指针初始指向 'a' ，故不需移动指针。
- 花 1 秒将指针顺时针移到 'b' 。
- 花 1 秒键入字符 'b' 。
- 花 1 秒将指针顺时针移到 'c' 。
- 花 1 秒键入字符 'c' 。
示例 2：

输入：word = "bza"
输出：7
解释：
单词按如下操作键入：
- 花 1 秒将指针顺时针移到 'b' 。
- 花 1 秒键入字符 'b' 。
- 花 2 秒将指针逆时针移到 'z' 。
- 花 1 秒键入字符 'z' 。
- 花 1 秒将指针顺时针移到 'a' 。
- 花 1 秒键入字符 'a' 。
示例 3：

输入：word = "zjpc"
输出：34
解释：
单词按如下操作键入：
- 花 1 秒将指针逆时针移到 'z' 。
- 花 1 秒键入字符 'z' 。
- 花 10 秒将指针顺时针移到 'j' 。
- 花 1 秒键入字符 'j' 。
- 花 6 秒将指针顺时针移到 'p' 。
- 花 1 秒键入字符 'p' 。
- 花 13 秒将指针逆时针移到 'c' 。
- 花 1 秒键入字符 'c' 。
 

提示：

1 <= word.length <= 100
word 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-time-to-type-word-using-special-typewriter
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minTimeToType(string word) {
        int time = 0;
        char current = 'a';

        for (char c : word) {
            int second = abs(c - current);
            time += min(second, 26 - second);
            current = c;
        }

        return time + word.size();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(5, o.minTimeToType("abc"));
    check.checkInt(7, o.minTimeToType("bza"));
    check.checkInt(34, o.minTimeToType("zjpc"));
    check.checkInt(1, o.minTimeToType("a"));
    check.checkInt(453, o.minTimeToType("qeryuiyerfhklhpflzxvbbdfwouierhzbmzaldfherifuakjznznaf"));
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
