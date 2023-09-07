/* 统计一个字符串的 k 子序列美丽值最大的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个整数 k 。

k 子序列指的是 s 的一个长度为 k 的 子序列 ，且所有字符都是 唯一 的，也就是说每个字符在子序列里只出现过一次。

定义 f(c) 为字符 c 在 s 中出现的次数。

k 子序列的 美丽值 定义为这个子序列中每一个字符 c 的 f(c) 之 和 。

比方说，s = "abbbdd" 和 k = 2 ，我们有：

f('a') = 1, f('b') = 3, f('d') = 2
s 的部分 k 子序列为：
"abbbdd" -> "ab" ，美丽值为 f('a') + f('b') = 4
"abbbdd" -> "ad" ，美丽值为 f('a') + f('d') = 3
"abbbdd" -> "bd" ，美丽值为 f('b') + f('d') = 5
请你返回一个整数，表示所有 k 子序列 里面 美丽值 是 最大值 的子序列数目。由于答案可能很大，将结果对 109 + 7 取余后返回。

一个字符串的子序列指的是从原字符串里面删除一些字符（也可能一个字符也不删除），不改变剩下字符顺序连接得到的新字符串。

注意：

f(c) 指的是字符 c 在字符串 s 的出现次数，不是在 k 子序列里的出现次数。
两个 k 子序列如果有任何一个字符在原字符串中的下标不同，则它们是两个不同的子序列。所以两个不同的 k 子序列可能产生相同的字符串。


示例 1：

输入：s = "bcca", k = 2
输出：4
解释：s 中我们有 f('a') = 1 ，f('b') = 1 和 f('c') = 2 。
s 的 k 子序列为：
bcca ，美丽值为 f('b') + f('c') = 3
bcca ，美丽值为 f('b') + f('c') = 3
bcca ，美丽值为 f('b') + f('a') = 2
bcca ，美丽值为 f('c') + f('a') = 3
bcca ，美丽值为 f('c') + f('a') = 3
总共有 4 个 k 子序列美丽值为最大值 3 。
所以答案为 4 。
示例 2：

输入：s = "abbcd", k = 4
输出：2
解释：s 中我们有 f('a') = 1 ，f('b') = 2 ，f('c') = 1 和 f('d') = 1 。
s 的 k 子序列为：
abbcd ，美丽值为 f('a') + f('b') + f('c') + f('d') = 5
abbcd ，美丽值为 f('a') + f('b') + f('c') + f('d') = 5
总共有 2 个 k 子序列美丽值为最大值 5 。
所以答案为 2 。


提示：

1 <= s.length <= 2 * 105
1 <= k <= s.length
s 只包含小写英文字母。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        vector<int> count(26, 0);
        map<int, int, greater<int>> mp;
        long long ans = 1;

        for (char c : s) {
            ++count[c - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                ++mp[count[i]];
            }
        }

        for (auto iter = mp.begin(); iter != mp.end() && k != 0; ++iter) {
            if (iter->second <= k) {
                ans = ans * fastPower(iter->first, iter->second) % mod;
                k -= iter->second;
            }
            else {
                ans = ans * fastPower(iter->first, k) % mod * combination(iter->second, k) % mod;
                k = 0;
            }
        }

        return k == 0 ? (int)ans : 0;
    }

    long long fastPower(long long x, int n) {
        long long ans = 1;

        while (n > 0) {
            if ((n & 1) == 1) {
                ans = ans * x % mod;
            }

            x = x * x % mod;
            n >>= 1;
        }

        return ans;
    }

    int combination(int x, int y) {
        vector<vector<int>> comb(x + 1, vector<int>(y + 1, 0));
        comb[0][0] = 1;

        for (int i = 1; i <= x; ++i) {
            comb[i][0] = 1;

            for (int j = 1; j <= y && j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;  // 从x个数取y个的组合，等于从x - 1个数取y个的组合（不取最后一个数）加上从x - 1个数取y - 1个数（取最后一个数）
            }
        }

        return comb[x][y];
    }

private:
    int mod = 1000000007;
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.countKSubsequencesWithMaxBeauty("bcca", 2));
    check.checkInt(2, o.countKSubsequencesWithMaxBeauty("abbcd", 4));
    check.checkInt(3, o.countKSubsequencesWithMaxBeauty("fkp", 2));
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
