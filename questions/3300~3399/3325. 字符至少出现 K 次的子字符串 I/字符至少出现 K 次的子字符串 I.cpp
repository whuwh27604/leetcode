/* 字符至少出现 K 次的子字符串 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个整数 k，在 s 的所有子字符串中，请你统计并返回 至少有一个 字符 至少出现 k 次的子字符串总数。

子字符串 是字符串中的一个连续、 非空 的字符序列。



示例 1：

输入： s = "abacb", k = 2

输出： 4

解释：

符合条件的子字符串如下：

"aba"（字符 'a' 出现 2 次）。
"abac"（字符 'a' 出现 2 次）。
"abacb"（字符 'a' 出现 2 次）。
"bacb"（字符 'b' 出现 2 次）。
示例 2：

输入： s = "abcde", k = 1

输出： 15

解释：

所有子字符串都有效，因为每个字符至少出现一次。



提示：

1 <= s.length <= 3000
1 <= k <= s.length
s 仅由小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int size = (int)s.size(), right = 0, mask = 0, idx = 0, subs = 0;
        vector<int> count(26, 0);

        for (int left = 0; left < size; ++left) {
            while (right < size && mask == 0) {
                idx = s[right++] - 'a';
                if (++count[idx] == k) {
                    mask |= (1 << idx);
                }
            }

            if (mask != 0) {
                subs += (size - right + 1);
            }

            idx = s[left] - 'a';
            if (--count[idx] == k - 1) {
                mask ^= (1 << idx);
            }
        }

        return subs;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(4, o.numberOfSubstrings("abacb", 2));
    check.checkInt(15, o.numberOfSubstrings("abcde", 1));
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
