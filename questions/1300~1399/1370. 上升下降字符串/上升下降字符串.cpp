/* 上升下降字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，请你根据下面的算法重新构造字符串：

从 s 中选出 最小 的字符，将它 接在 结果字符串的后面。
从 s 剩余字符中选出 最小 的字符，且该字符比上一个添加的字符大，将它 接在 结果字符串后面。
重复步骤 2 ，直到你没法从 s 中选择字符。
从 s 中选出 最大 的字符，将它 接在 结果字符串的后面。
从 s 剩余字符中选出 最大 的字符，且该字符比上一个添加的字符小，将它 接在 结果字符串后面。
重复步骤 5 ，直到你没法从 s 中选择字符。
重复步骤 1 到 6 ，直到 s 中所有字符都已经被选过。
在任何一步中，如果最小或者最大字符不止一个 ，你可以选择其中任意一个，并将其添加到结果字符串。

请你返回将 s 中字符重新排序后的 结果字符串 。

 

示例 1：

输入：s = "aaaabbbbcccc"
输出："abccbaabccba"
解释：第一轮的步骤 1，2，3 后，结果字符串为 result = "abc"
第一轮的步骤 4，5，6 后，结果字符串为 result = "abccba"
第一轮结束，现在 s = "aabbcc" ，我们再次回到步骤 1
第二轮的步骤 1，2，3 后，结果字符串为 result = "abccbaabc"
第二轮的步骤 4，5，6 后，结果字符串为 result = "abccbaabccba"
示例 2：

输入：s = "rat"
输出："art"
解释：单词 "rat" 在上述算法重排序以后变成 "art"
示例 3：

输入：s = "leetcode"
输出："cdelotee"
示例 4：

输入：s = "ggggggg"
输出："ggggggg"
示例 5：

输入：s = "spo"
输出："ops"
 

提示：

1 <= s.length <= 500
s 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/increasing-decreasing-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string sortString(string s) {
        int i, len = s.size(), charTable['z' + 1] = { 0 };

        for (i = 0; i < len; i++) {
            charTable[s[i]]++;
        }

        string ans;
        while (len > 0) {
            char charactor = 'a' - 1;
            while ((nextChar(charTable, charactor)) != -1) {
                ans += charactor;
                len--;
            }

            charactor = 'z' + 1;
            while ((prevChar(charTable, charactor)) != -1) {
                ans += charactor;
                len--;
            }
        }

        return ans;
    }

    int nextChar(int* charTable, char& charactor) {
        for (char i = charactor + 1; i <= 'z'; i++) {
            if (charTable[i] != 0) {
                charTable[i]--;
                charactor = i;
                return 0;
            }
        }

        return -1;
    }

    int prevChar(int* charTable, char& charactor) {
        for (char i = charactor - 1; i >= 'a'; i--) {
            if (charTable[i] != 0) {
                charTable[i]--;
                charactor = i;
                return 0;
            }
        }

        return -1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("abccbaabccba", o.sortString("aaaabbbbcccc"));
    check.checkString("art", o.sortString("rat"));
    check.checkString("cdelotee", o.sortString("leetcode"));
    check.checkString("ggggggg", o.sortString("ggggggg"));
    check.checkString("ops", o.sortString("spo"));
    check.checkString("a", o.sortString("a"));
    check.checkString("z", o.sortString("z"));
    check.checkString("az", o.sortString("za"));
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
