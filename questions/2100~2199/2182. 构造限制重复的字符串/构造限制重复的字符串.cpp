/* 构造限制重复的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个整数 repeatLimit ，用 s 中的字符构造一个新字符串 repeatLimitedString ，使任何字母 连续 出现的次数都不超过 repeatLimit 次。你不必使用 s 中的全部字符。

返回 字典序最大的 repeatLimitedString 。

如果在字符串 a 和 b 不同的第一个位置，字符串 a 中的字母在字母表中出现时间比字符串 b 对应的字母晚，则认为字符串 a 比字符串 b 字典序更大 。如果字符串中前 min(a.length, b.length) 个字符都相同，那么较长的字符串字典序更大。

 

示例 1：

输入：s = "cczazcc", repeatLimit = 3
输出："zzcccac"
解释：使用 s 中的所有字符来构造 repeatLimitedString "zzcccac"。
字母 'a' 连续出现至多 1 次。
字母 'c' 连续出现至多 3 次。
字母 'z' 连续出现至多 2 次。
因此，没有字母连续出现超过 repeatLimit 次，字符串是一个有效的 repeatLimitedString 。
该字符串是字典序最大的 repeatLimitedString ，所以返回 "zzcccac" 。
注意，尽管 "zzcccca" 字典序更大，但字母 'c' 连续出现超过 3 次，所以它不是一个有效的 repeatLimitedString 。
示例 2：

输入：s = "aababab", repeatLimit = 2
输出："bbabaa"
解释：
使用 s 中的一些字符来构造 repeatLimitedString "bbabaa"。
字母 'a' 连续出现至多 2 次。
字母 'b' 连续出现至多 2 次。
因此，没有字母连续出现超过 repeatLimit 次，字符串是一个有效的 repeatLimitedString 。
该字符串是字典序最大的 repeatLimitedString ，所以返回 "bbabaa" 。
注意，尽管 "bbabaaa" 字典序更大，但字母 'a' 连续出现超过 2 次，所以它不是一个有效的 repeatLimitedString 。
 

提示：

1 <= repeatLimit <= s.length <= 105
s 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-string-with-repeat-limit
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count('z' + 1, 0);

        for (char c : s) {
            ++count[c];
        }

        string ans;
        bool limit = false;
        int current = 'z', next = current;
        getNext(count, next);

        while (current >= 'a') {
            if (count[current] == 0) {  // 最大字符已经写完，移动current、next指针并解除限制
                current = next;
                getNext(count, next);
                limit = false;
            }

            if (current < 'a') {
                break;
            }

            if (limit) {  // 如果被限制了，那么需要插入一个next
                if (count[next] == 0) {  // 已经没有next了，不能再加入任何字符
                    break;
                }
                else {
                    ans += (char)next;  // 插入next

                    if (--count[next] == 0) {  // 如果next被清零，移动到下一个位置
                        getNext(count, next);
                    }
                }
            }

            int cnt = min(repeatLimit, count[current]);  // 加入最多repeatLimit个current
            ans += string(cnt, (char)current);
            count[current] -= cnt;
            limit = true;  // 限制继续加入current
        }

        return ans;
    }

    void getNext(vector<int>& count, int& next) {
        for (--next; next >= 'a'; --next) {
            if (count[next] != 0) {
                break;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("zzcccac", o.repeatLimitedString("cczazcc", 3));
    check.checkString("bbabaa", o.repeatLimitedString("aababab", 2));
    check.checkString("bababa", o.repeatLimitedString("aababab", 1));
    check.checkString("bbbbbabbbbbabbbbbabbbbbabbbbbabbbbbabbbaaaaa", o.repeatLimitedString("aabababaabababaabababaabababaabababaabababaabababaabababaabababaabababaababab", 5));
    check.checkString("z", o.repeatLimitedString("z", 4));
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
