/* 使用机器人打印字典序最小的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个机器人，机器人当前有一个空字符串 t 。执行以下操作之一，直到 s 和 t 都变成空字符串：

删除字符串 s 的 第一个 字符，并将该字符给机器人。机器人把这个字符添加到 t 的尾部。
删除字符串 t 的 最后一个 字符，并将该字符给机器人。机器人将该字符写到纸上。
请你返回纸上能写出的字典序最小的字符串。

 

示例 1：

输入：s = "zza"
输出："azz"
解释：用 p 表示写出来的字符串。
一开始，p="" ，s="zza" ，t="" 。
执行第一个操作三次，得到 p="" ，s="" ，t="zza" 。
执行第二个操作三次，得到 p="azz" ，s="" ，t="" 。
示例 2：

输入：s = "bac"
输出："abc"
解释：用 p 表示写出来的字符串。
执行第一个操作两次，得到 p="" ，s="c" ，t="ba" 。
执行第二个操作两次，得到 p="ab" ，s="c" ，t="" 。
执行第一个操作，得到 p="ab" ，s="" ，t="c" 。
执行第二个操作，得到 p="abc" ，s="" ，t="" 。
示例 3：

输入：s = "bdda"
输出："addb"
解释：用 p 表示写出来的字符串。
一开始，p="" ，s="bdda" ，t="" 。
执行第一个操作四次，得到 p="" ，s="" ，t="bdda" 。
执行第二个操作四次，得到 p="addb" ，s="" ，t="" 。
 

提示：

1 <= s.length <= 105
s 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/using-a-robot-to-print-the-lexicographically-smallest-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        int index = 0;
        vector<int> cnt(26, 0);
        string t, p;

        count(s, cnt);
        next(cnt, index);

        for (char c : s) {
            while (!t.empty() && t.back() <= ('a' + index)) {  // 贪心，栈顶元素是剩余里面的最小值则一直输出
                p += t.back();
                t.pop_back();
            }

            t += c;
            --cnt[c - 'a'];
            next(cnt, index);
        }

        t2p(t, p);

        return p;
    }

    void count(string& s, vector<int>& cnt) {
        for (char c : s) {
            ++cnt[c - 'a'];
        }
    }

    void next(vector<int>& cnt, int& index) {
        while (index < 26 && cnt[index] == 0) {
            ++index;
        }
    }

    void t2p(string& t, string& p) {
        while (!t.empty()) {
            p += t.back();
            t.pop_back();
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("azz", o.robotWithString("zza"));
    check.checkString("abc", o.robotWithString("bac"));
    check.checkString("addb", o.robotWithString("bdda"));
    check.checkString("a", o.robotWithString("a"));
    check.checkString("axz", o.robotWithString("zxa"));
    check.checkString("fnohopzv", o.robotWithString("vzhofnpo"));
    check.checkString("aaaaaaaaaaaaddbcbzzddbcbzzddbcbzzddbcbzz", o.robotWithString("zzabacbddazzabacbddazzabacbddazzabacbdda"));
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
