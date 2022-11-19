/* 根据限制分割消息.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 message 和一个正整数 limit 。

你需要根据 limit 将 message 分割 成一个或多个 部分 。每个部分的结尾都是 "<a/b>" ，其中 "b" 用分割出来的总数 替换， "a" 用当前部分所在的编号 替换 ，编号从 1 到 b 依次编号。除此以外，除了最后一部分长度 小于等于 limit 以外，其他每一部分（包括结尾部分）的长度都应该 等于 limit 。

你需要确保分割后的结果数组，删掉每部分的结尾并 按顺序 连起来后，能够得到 message 。同时，结果数组越短越好。

请你返回 message  分割后得到的结果数组。如果无法按要求分割 message ，返回一个空数组。



示例 1：

输入：message = "this is really a very awesome message", limit = 9
输出：["thi<1/14>","s i<2/14>","s r<3/14>","eal<4/14>","ly <5/14>","a v<6/14>","ery<7/14>"," aw<8/14>","eso<9/14>","me<10/14>"," m<11/14>","es<12/14>","sa<13/14>","ge<14/14>"]
解释：
前面 9 个部分分别从 message 中得到 3 个字符。
接下来的 5 个部分分别从 message 中得到 2 个字符。
这个例子中，包含最后一个部分在内，每个部分的长度都为 9 。
可以证明没有办法分割成少于 14 个部分。
示例 2：

输入：message = "short message", limit = 15
输出：["short mess<1/2>","age<2/2>"]
解释：
在给定限制下，字符串可以分成两个部分：
- 第一个部分包含 10 个字符，长度为 15 。
- 第二个部分包含 3 个字符，长度为 8 。


提示：

1 <= message.length <= 104
message 只包含小写英文字母和 ' ' 。
1 <= limit <= 104
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        int size = message.size();
        vector<string> ans;

        for (int digits = 1; digits < 6; ++digits) {
            if (getLongestMessage(digits, limit) >= size) {
                split(message, size, digits, limit, ans);
                break;
            }
        }

        return ans;
    }

    int getLongestMessage(int digits, int limit) {
        vector<int> count = { 0,9,90,900,9000,90000 };
        int len = 0;

        for (int i = 1; i <= digits; ++i) {
            int left = limit - i - digits - 3;
            if (left > 0) {
                len += left * count[i];
            }
        }

        return len;
    }

    void split(string& message, int size, int digits, int limit, vector<string>& ans) {
        int i = 0, part = 1;

        while (i < size) {
            string numerator = to_string(part++);
            int len = min(limit - 3 - (int)numerator.size() - digits, size - i);
            string s(message, i, len);
            s += '<';
            s += numerator;
            s += '/';
            ans.push_back(s);
            i += len;
        }

        string denominator = to_string(--part);
        for (string& s : ans) {
            s += denominator;
            s += '>';
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> actual = o.splitMessage("this is really a very awesome message", 9);
    vector<string> expected = { "thi<1/14>","s i<2/14>","s r<3/14>","eal<4/14>","ly <5/14>","a v<6/14>","ery<7/14>"," aw<8/14>","eso<9/14>","me<10/14>"," m<11/14>","es<12/14>","sa<13/14>","ge<14/14>" };
    check.checkStringVector(expected, actual);

    actual = o.splitMessage("short message", 15);
    expected = { "short mess<1/2>","age<2/2>" };
    check.checkStringVector(expected, actual);

    actual = o.splitMessage("aaaabbbbccccddddeeee", 8);
    expected = { "aaa<1/7>","abb<2/7>","bbc<3/7>","ccc<4/7>","ddd<5/7>","dee<6/7>","ee<7/7>" };
    check.checkStringVector(expected, actual);

    actual = o.splitMessage("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 9);
    expected = { "aaa<1/95>","aaa<2/95>","aaa<3/95>","aaa<4/95>","aaa<5/95>","aaa<6/95>","aaa<7/95>","aaa<8/95>","aaa<9/95>","aa<10/95>","aa<11/95>","aa<12/95>","aa<13/95>","aa<14/95>","aa<15/95>","aa<16/95>","aa<17/95>","aa<18/95>","aa<19/95>","aa<20/95>","aa<21/95>","aa<22/95>","aa<23/95>","aa<24/95>","aa<25/95>","aa<26/95>","aa<27/95>","aa<28/95>","aa<29/95>","aa<30/95>","aa<31/95>","aa<32/95>","aa<33/95>","aa<34/95>","aa<35/95>","aa<36/95>","aa<37/95>","aa<38/95>","aa<39/95>","aa<40/95>","aa<41/95>","aa<42/95>","aa<43/95>","aa<44/95>","aa<45/95>","aa<46/95>","aa<47/95>","aa<48/95>","aa<49/95>","aa<50/95>","aa<51/95>","aa<52/95>","aa<53/95>","aa<54/95>","aa<55/95>","aa<56/95>","aa<57/95>","aa<58/95>","aa<59/95>","aa<60/95>","aa<61/95>","aa<62/95>","aa<63/95>","aa<64/95>","aa<65/95>","aa<66/95>","aa<67/95>","aa<68/95>","aa<69/95>","aa<70/95>","aa<71/95>","aa<72/95>","aa<73/95>","aa<74/95>","aa<75/95>","aa<76/95>","aa<77/95>","aa<78/95>","aa<79/95>","aa<80/95>","aa<81/95>","aa<82/95>","aa<83/95>","aa<84/95>","aa<85/95>","aa<86/95>","aa<87/95>","aa<88/95>","aa<89/95>","aa<90/95>","aa<91/95>","aa<92/95>","aa<93/95>","aa<94/95>","a<95/95>" };
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
