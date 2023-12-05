/* 统计完全子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 word 和一个整数 k 。

如果 word 的一个子字符串 s 满足以下条件，我们称它是 完全字符串：

s 中每个字符 恰好 出现 k 次。
相邻字符在字母表中的顺序 至多 相差 2 。也就是说，s 中两个相邻字符 c1 和 c2 ，它们在字母表中的位置相差 至多 为 2 。
请你返回 word 中 完全 子字符串的数目。

子字符串 指的是一个字符串中一段连续 非空 的字符序列。



示例 1：

输入：word = "igigee", k = 2
输出：3
解释：完全子字符串需要满足每个字符恰好出现 2 次，且相邻字符相差至多为 2 ：igigee, igigee, igigee 。
示例 2：

输入：word = "aaabbbccc", k = 3
输出：6
解释：完全子字符串需要满足每个字符恰好出现 3 次，且相邻字符相差至多为 2 ：aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc 。


提示：

1 <= word.length <= 105
word 只包含小写英文字母。
1 <= k <= word.length
*/

#include <iostream>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int size = word.size(), start = 0, end, completeStrings = 0;
        int* count = new int[(size + 1) * 26]();
        int* cnt = new int[26]();

        for (int i = 0; i < size; ++i) {  // 统计字符个数前缀和
            ++cnt[word[i] - 'a'];
            for (int j = 0; j < 26; ++j) {
                count[(i + 1) * 26 + j] = cnt[j];
            }
        }

        while (start < size) {  // 前后字符相隔超过2的地方分割字符串
            end = start + 1;

            while (end != size && abs(word[end] - word[end - 1]) <= 2) {
                ++end;
            }

            completeStrings += countCompleteSubstrings(count, start, end, k);
            start = end;
        }

        return completeStrings;
    }

    int countCompleteSubstrings(int* count, int start, int end, int k) {
        int size = end - start, completeStrings = 0;

        for (int cs = 1; cs < 27; ++cs) {  // 枚举字符个数
            int len = cs * k;
            if (len > size) {
                break;
            }

            for (int i = start; i <= end - len; ++i) {  // 滑动窗口枚举substring
                int left = i * 26, right = (i + len) * 26;
                bool valid = true;

                for (int j = 0; j < 26; ++j, ++left, ++right) {
                    int cnt = count[right] - count[left];  // 前缀和计算字符的个数
                    if (cnt != 0 && cnt != k) {  // 窗口内的每一个字符都应该是 k 个
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    ++completeStrings;
                }
            }
        }

        return completeStrings;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.countCompleteSubstrings("igigee", 2));
    check.checkInt(6, o.countCompleteSubstrings("aaabbbccc", 3));
    check.checkInt(100000, o.countCompleteSubstrings(getString("./testcase1.txt"), 1));
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
