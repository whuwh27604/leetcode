/* 每种字符至少取 K 个.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由字符 'a'、'b'、'c' 组成的字符串 s 和一个非负整数 k 。每分钟，你可以选择取走 s 最左侧 还是 最右侧 的那个字符。

你必须取走每种字符 至少 k 个，返回需要的 最少 分钟数；如果无法取到，则返回 -1 。



示例 1：

输入：s = "aabaaaacaabc", k = 2
输出：8
解释：
从 s 的左侧取三个字符，现在共取到两个字符 'a' 、一个字符 'b' 。
从 s 的右侧取五个字符，现在共取到四个字符 'a' 、两个字符 'b' 和两个字符 'c' 。
共需要 3 + 5 = 8 分钟。
可以证明需要的最少分钟数是 8 。
示例 2：

输入：s = "a", k = 1
输出：-1
解释：无法取到一个字符 'b' 或者 'c'，所以返回 -1 。


提示：

1 <= s.length <= 105
s 仅由字母 'a'、'b'、'c' 组成
0 <= k <= s.length
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) {
            return 0;
        }

        int a = 0, b = 0, c = 0;
        count(s, a, b, c);
        if (a < k || b < k || c < k) {
            return -1;
        }

        a -= k, b -= k, c -= k;
        int aa = 0, bb = 0, cc = 0, size = s.size(), left = 0, maxLen = 0;

        for (int right = 0; right < size; ++right) {
            if (s[right] == 'a') {
                ++aa;
            }
            else if (s[right] == 'b') {
                ++bb;
            }
            else {
                ++cc;
            }

            while (aa > a || bb > b || cc > c) {
                if (s[left] == 'a') {
                    --aa;
                }
                else if (s[left] == 'b') {
                    --bb;
                }
                else {
                    --cc;
                }
                ++left;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return size - maxLen;
    }

    void count(string& s, int& a, int& b, int& c) {
        for (char ch : s) {
            if (ch == 'a') {
                ++a;
            }
            else if (ch == 'b') {
                ++b;
            }
            else {
                ++c;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(8, o.takeCharacters("aabaaaacaabc", 2));
    check.checkInt(-1, o.takeCharacters("a", 1));
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
