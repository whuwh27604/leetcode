/* 删除子串后的字符串最小长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个仅由 大写 英文字符组成的字符串 s 。

你可以对此字符串执行一些操作，在每一步操作中，你可以从 s 中删除 任一个 "AB" 或 "CD" 子字符串。

通过执行操作，删除所有 "AB" 和 "CD" 子串，返回可获得的最终字符串的 最小 可能长度。

注意，删除子串后，重新连接出的字符串可能会产生新的 "AB" 或 "CD" 子串。



示例 1：

输入：s = "ABFCACDB"
输出：2
解释：你可以执行下述操作：
- 从 "ABFCACDB" 中删除子串 "AB"，得到 s = "FCACDB" 。
- 从 "FCACDB" 中删除子串 "CD"，得到 s = "FCAB" 。
- 从 "FCAB" 中删除子串 "AB"，得到 s = "FC" 。
最终字符串的长度为 2 。
可以证明 2 是可获得的最小长度。
示例 2：

输入：s = "ACBBD"
输出：5
解释：无法执行操作，字符串长度不变。


提示：

1 <= s.length <= 100
s 仅由大写英文字母组成
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minLength(string s) {
        string t = "T";

        for (char c : s) {
            if ((c == 'B' && t.back() == 'A') || (c == 'D' && t.back() == 'C')) {
                t.pop_back();
            }
            else {
                t.push_back(c);
            }
        }

        return (int)t.size() - 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.minLength("ABFCACDB"));
    check.checkInt(5, o.minLength("ACBBD"));
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
