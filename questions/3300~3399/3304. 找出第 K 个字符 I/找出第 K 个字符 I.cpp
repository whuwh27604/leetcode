/* 找出第 K 个字符 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Alice 和 Bob 正在玩一个游戏。最初，Alice 有一个字符串 word = "a"。

给定一个正整数 k。

现在 Bob 会要求 Alice 执行以下操作 无限次 :

将 word 中的每个字符 更改 为英文字母表中的 下一个 字符来生成一个新字符串，并将其 追加 到原始的 word。
例如，对 "c" 进行操作生成 "cd"，对 "zb" 进行操作生成 "zbac"。

在执行足够多的操作后， word 中 至少 存在 k 个字符，此时返回 word 中第 k 个字符的值。

注意，在操作中字符 'z' 可以变成 'a'。



示例 1:

输入：k = 5

输出："b"

解释：

最初，word = "a"。需要进行三次操作:

生成的字符串是 "b"，word 变为 "ab"。
生成的字符串是 "bc"，word 变为 "abbc"。
生成的字符串是 "bccd"，word 变为 "abbcbccd"。
示例 2:

输入：k = 10

输出："c"



提示：

1 <= k <= 500
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";

        while (s.size() < k) {
            string t = s;

            for (char& c : t) {
                c = (c == 'z' ? 'a' : c + 1);
            }

            s += t;
        }

        return s[k - 1];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkChar('b', o.kthCharacter(5));
    check.checkChar('c', o.kthCharacter(10));
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
