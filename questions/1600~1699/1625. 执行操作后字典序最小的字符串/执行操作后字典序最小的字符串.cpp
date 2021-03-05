/* 执行操作后字典序最小的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 以及两个整数 a 和 b 。其中，字符串 s 的长度为偶数，且仅由数字 0 到 9 组成。

你可以在 s 上按任意顺序多次执行下面两个操作之一：

累加：将  a 加到 s 中所有下标为奇数的元素上（下标从 0 开始）。数字一旦超过 9 就会变成 0，如此循环往复。例如，s = "3456" 且 a = 5，则执行此操作后 s 变成 "3951"。
轮转：将 s 向右轮转 b 位。例如，s = "3456" 且 b = 1，则执行此操作后 s 变成 "6345"。
请你返回在 s 上执行上述操作任意次后可以得到的 字典序最小 的字符串。

如果两个字符串长度相同，那么字符串 a 字典序比字符串 b 小可以这样定义：在 a 和 b 出现不同的第一个位置上，字符串 a 中的字符出现在字母表中的时间早于 b 中的对应字符。例如，"0158” 字典序比 "0190" 小，因为不同的第一个位置是在第三个字符，显然 '5' 出现在 '9' 之前。

 

示例 1：

输入：s = "5525", a = 9, b = 2
输出："2050"
解释：执行操作如下：
初态："5525"
轮转："2555"
累加："2454"
累加："2353"
轮转："5323"
累加："5222"
累加："5121"
轮转："2151"
累加："2050"​​​​​​​​​​​​
无法获得字典序小于 "2050" 的字符串。
示例 2：

输入：s = "74", a = 5, b = 1
输出："24"
解释：执行操作如下：
初态："74"
轮转："47"
累加："42"
轮转："24"​​​​​​​​​​​​
无法获得字典序小于 "24" 的字符串。
示例 3：

输入：s = "0011", a = 4, b = 2
输出："0011"
解释：无法获得字典序小于 "0011" 的字符串。
示例 4：

输入：s = "43987654", a = 7, b = 3
输出："00553311"
 

提示：

2 <= s.length <= 100
s.length 是偶数
s 仅由数字 0 到 9 组成
1 <= a <= 9
1 <= b <= s.length - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lexicographically-smallest-string-after-applying-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int i, size = s.size(), rotateBits = gcd(b, size), rotateTimes = size / rotateBits;
        string smallestStr = s, doubleS = s + s;

        for (i = 1; i <= rotateTimes; ++i) {
            string rotatedS = string(doubleS, size - i * rotateBits, size);  // 按步长rotate字符串s
            smallestStr = min(smallestStr, getMinString(rotatedS, a, rotateBits));
        }

        return smallestStr;
    }

    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }

    string getMinString(string& s, int a, int bits) {
        string minStr = s;
        int addValue = getAddValue(s[1], a);  // 把奇数位加到最小
        add(minStr, addValue, 1);

        if ((bits & 1) == 1) {  // 如果rotate奇数位，那么偶数位的数字也能够被加到最小
            addValue = getAddValue(s[0], a);
            add(minStr, addValue, 0);
        }

        return minStr;
    }

    int getAddValue(char c, int a) {
        int num = c - '0';

        if (a == 5) {
            return num < 5 ? 0 : 5;
        }
        else if ((a & 1) == 1) {  // a为1、3、7、9，总能把c加到0
            return (10 - num) % 10;
        }
        else {  // a为偶数，c为偶数总能加到0，c为奇数总能加到1
            return (num & 1) == 1 ? (11 - num) % 10 : (10 - num) % 10;
        }
    }

    void add(string& minStr, int addValue, int pos) {
        for (int i = pos; i < (int)minStr.size(); i += 2) {
            minStr[i] = (minStr[i] - '0' + addValue) % 10 + '0';
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("2050", o.findLexSmallestString("5525", 9, 2));
    check.checkString("24", o.findLexSmallestString("74", 5, 1));
    check.checkString("0011", o.findLexSmallestString("0011", 4, 2));
    check.checkString("00553311", o.findLexSmallestString("43987654", 7, 3));
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
