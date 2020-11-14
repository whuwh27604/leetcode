/* 重构字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。

若可行，输出任意可行的结果。若不可行，返回空字符串。

示例 1:

输入: S = "aab"
输出: "aba"
示例 2:

输入: S = "aaab"
输出: ""
注意:

S 只包含小写字母并且长度在[1, 500]区间内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorganize-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        string reorganized;
        priority_queue<pair<int, char>> lettersCount;
        countLetters(S, lettersCount);

        if (lettersCount.top().first > (int)(S.size() + 1) / 2) {
            return "";
        }

        while (!lettersCount.empty()) {  // 贪心算法，每次取出个数最多的两个字符交替输出
            int count1 = lettersCount.top().first;
            char letter1 = lettersCount.top().second;
            lettersCount.pop();

            if (lettersCount.empty()) {
                reorganized += letter1;
                break;
            }

            int count2 = lettersCount.top().first;
            char letter2 = lettersCount.top().second;
            lettersCount.pop();

            for (int i = 0; i < count2; i++) {
                reorganized += letter1;
                reorganized += letter2;
            }

            if (count1 > count2) {
                lettersCount.push({ count1 - count2, letter1 });
            }
        }

        return reorganized;
    }

    void countLetters(string& s, priority_queue<pair<int, char>>& lettersCount) {
        int letters['z' + 1] = { 0 };

        for (char c : s) {
            letters[c]++;
        }

        for (char i = 'a'; i <= 'z'; i++) {
            if (letters[i] != 0) {
                lettersCount.push({ letters[i], i });
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("a", o.reorganizeString("a"));
    check.checkString("ba", o.reorganizeString("ab"));
    check.checkString("", o.reorganizeString("aa"));
    check.checkString("aba", o.reorganizeString("aab"));
    check.checkString("", o.reorganizeString("aaab"));
    check.checkString("abababacacada", o.reorganizeString("aaaaaaabbbccd"));
    check.checkString("bababadc", o.reorganizeString("aaabbbcd"));
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
