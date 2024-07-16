/* 交换后字典序最小的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个仅由数字组成的字符串 s，在最多交换一次 相邻 且具有相同 奇偶性 的数字后，返回可以得到的
字典序最小的字符串
。

如果两个数字都是奇数或都是偶数，则它们具有相同的奇偶性。例如，5 和 9、2 和 4 奇偶性相同，而 6 和 9 奇偶性不同。



示例 1：

输入： s = "45320"

输出： "43520"

解释：

s[1] == '5' 和 s[2] == '3' 都具有相同的奇偶性，交换它们可以得到字典序最小的字符串。

示例 2：

输入： s = "001"

输出： "001"

解释：

无需进行交换，因为 s 已经是字典序最小的。



提示：

2 <= s.length <= 100
s 仅由数字组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 1; i < (int)s.size(); ++i) {
            if (s[i] < s[i - 1] && (s[i] & 1) == (s[i - 1] & 1)) {
                swap(s[i], s[i - 1]);
                break;
            }
        }

        return s;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("43520", o.getSmallestString("45320"));
    check.checkString("001", o.getSmallestString("001"));
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
