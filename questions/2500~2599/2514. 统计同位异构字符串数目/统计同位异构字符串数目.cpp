/* 统计同位异构字符串数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，它包含一个或者多个单词。单词之间用单个空格 ' ' 隔开。

如果字符串 t 中第 i 个单词是 s 中第 i 个单词的一个 排列 ，那么我们称字符串 t 是字符串 s 的同位异构字符串。

比方说，"acb dfe" 是 "abc def" 的同位异构字符串，但是 "def cab" 和 "adc bef" 不是。
请你返回 s 的同位异构字符串的数目，由于答案可能很大，请你将它对 109 + 7 取余 后返回。



示例 1：

输入：s = "too hot"
输出：18
解释：输入字符串的一些同位异构字符串为 "too hot" ，"oot hot" ，"oto toh" ，"too toh" 以及 "too oht" 。
示例 2：

输入：s = "aa"
输出：1
解释：输入字符串只有一个同位异构字符串。


提示：

1 <= s.length <= 105
s 只包含小写英文字母和空格 ' ' 。
相邻单词之间由单个空格隔开。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

int maxLen = 100000, mod = 1000000007;
vector<long long> factorials(maxLen + 1), inverses(maxLen + 1);

long long fastPower(long long x, int n) {
    long long ans = 1;
    int index = 1;

    while (n != 0) {
        if ((n & index) != 0) {
            ans = (ans * x) % mod;
        }

        n &= ~index;
        index <<= 1;
        x = (x * x) % mod;
    }

    return ans;
}

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        factorials[0] = 1;

        for (int i = 1; i <= maxLen; ++i) {
            factorials[i] = factorials[i - 1] * i % mod;
            inverses[i] = fastPower(factorials[i], mod - 2);
        }
    }
}

class Solution {
public:
    int countAnagrams(string s) {
        init();

        long long count = 1;
        s += ' ';
        int pos = 0, size = s.size();

        while (pos != size) {
            int space = s.find(' ', pos);
            string word(s, pos, space - pos);
            count = count * countSingleWord(word) % mod;
            pos = space + 1;
        }

        return (int)count;
    }

    long long countSingleWord(string& word) {
        vector<int> letters(26, 0);
        long long count = factorials[word.size()];

        for (char c : word) {
            ++letters[c - 'a'];
        }

        for (int letter : letters) {
            if (letter != 0) {
                count = count * inverses[letter] % mod;
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(18, o.countAnagrams("too hot"));
    check.checkInt(1, o.countAnagrams("aa"));
    check.checkInt(522745762, o.countAnagrams("adfafdadhflkhfalkdhqyerouqyeroqudznvzcnvzcmznmvldfhadkhfasdsqoiyeryqouiyeroqyreoiqznzmcnvzmcvnzcmvnzcnmvznzcnvzvcn"));
    check.checkInt(147156888, o.countAnagrams("adfafdadhflkhfalkdhqy erouqyeroqudznvzcnvzcmznmvldf hadkhfasdsqoiyeryqouiyeroqy reoiqznzmcnvzmcvnzcmvnzc nmvznzcnvzvcn"));
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
