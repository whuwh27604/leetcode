/* 字符串元音游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小红和小明在玩一个字符串元音游戏。

给你一个字符串 s，小红和小明将轮流参与游戏，小红 先 开始：

在小红的回合，她必须移除 s 中包含 奇数 个元音的任意 非空
子字符串
。
在小明的回合，他必须移除 s 中包含 偶数 个元音的任意 非空
子字符串
。
第一个无法在其回合内进行移除操作的玩家输掉游戏。假设小红和小明都采取 最优策略 。

如果小红赢得游戏，返回 true，否则返回 false。

英文元音字母包括：a, e, i, o, 和 u。



示例 1：

输入： s = "leetcoder"

输出： true

解释：
小红可以执行如下移除操作来赢得游戏：

小红先手，她可以移除加下划线的子字符串 s = "leetcoder"，其中包含 3 个元音。结果字符串为 s = "der"。
小明接着，他可以移除加下划线的子字符串 s = "der"，其中包含 0 个元音。结果字符串为 s = "er"。
小红再次操作，她可以移除整个字符串 s = "er"，其中包含 1 个元音。
又轮到小明，由于字符串为空，无法执行移除操作，因此小红赢得游戏。
示例 2：

输入： s = "bbcd"

输出： false

解释：
小红在她的第一回合无法执行移除操作，因此小红输掉了游戏。



提示：

1 <= s.length <= 105
s 仅由小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        /* 1、没有元音，小红无法操作，小红lost
           2、有奇数个元音，小红拿走全部，小明无法操作，小红win
           3、有偶数n个元音，小红拿走n - 1个，小明无法拿走剩下的1个，下一回合小红拿走所有，小红win */
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.doesAliceWin("leetcoder"));
    check.checkBool(true, o.doesAliceWin("a"));
    check.checkBool(true, o.doesAliceWin("e"));
    check.checkBool(true, o.doesAliceWin("i"));
    check.checkBool(true, o.doesAliceWin("o"));
    check.checkBool(true, o.doesAliceWin("u"));
    check.checkBool(false, o.doesAliceWin("bbcd"));
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
