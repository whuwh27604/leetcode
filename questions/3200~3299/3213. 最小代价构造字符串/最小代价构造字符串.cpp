/* 最小代价构造字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 target、一个字符串数组 words 以及一个整数数组 costs，这两个数组长度相同。

设想一个空字符串 s。

你可以执行以下操作任意次数（包括零次）：

选择一个在范围  [0, words.length - 1] 的索引 i。
将 words[i] 追加到 s。
该操作的成本是 costs[i]。
返回使 s 等于 target 的 最小 成本。如果不可能，返回 -1。



示例 1：

输入： target = "abcdef", words = ["abdef","abc","d","def","ef"], costs = [100,1,1,10,5]

输出： 7

解释：

选择索引 1 并以成本 1 将 "abc" 追加到 s，得到 s = "abc"。
选择索引 2 并以成本 1 将 "d" 追加到 s，得到 s = "abcd"。
选择索引 4 并以成本 5 将 "ef" 追加到 s，得到 s = "abcdef"。
示例 2：

输入： target = "aaaa", words = ["z","zz","zzz"], costs = [1,10,100]

输出： -1

解释：

无法使 s 等于 target，因此返回 -1。



提示：

1 <= target.length <= 5 * 104
1 <= words.length == costs.length <= 5 * 104
1 <= words[i].length <= target.length
所有 words[i].length 的总和小于或等于 5 * 104
target 和 words[i] 仅由小写英文字母组成。
1 <= costs[i] <= 104
*/

#include <iostream>
#include <map>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int sizeT = (int)target.size(), sizeS = (int)words.size();

        vector<int> hashT(sizeT + 1, 0), powerBase(sizeT + 1, 0);
        getTHash(target, sizeT, hashT, powerBase);

        map<int, unordered_map<int, int>> minCosts;  // { len, { key,cost } }
        getMinCost(sizeS, words, costs, minCosts);

        return getMinimumCost(sizeT, hashT, powerBase, minCosts);
    }

    void getTHash(string& target, int sizeT, vector<int>& hashT, vector<int>& powerBase) {
        powerBase[0] = 1;

        for (int i = 0; i < sizeT; ++i) {
            powerBase[i + 1] = (long long)powerBase[i] * base % mod;
            hashT[i + 1] = ((long long)hashT[i] * base + target[i]) % mod;
        }
    }

    int hash(vector<int>& hashT, vector<int>& powerBase, int left, int right) {  // target[left, right]的hash值
        return (int)((hashT[right + 1] - (long long)hashT[left] * powerBase[right + 1 - left] % mod + mod) % mod);
    }

    int hash(string& s) {  // 字符串word的hash值
        long long key = 0;

        for (char c : s) {
            key = (key * base + c) % mod;
        }

        return (int)key;
    }

    void getMinCost(int sizeS, vector<string>& words, vector<int>& costs, map<int, unordered_map<int, int>>& minCosts) {
        for (int i = 0; i < sizeS; ++i) {
            int key = hash(words[i]);
            int len = (int)words[i].size();

            if (minCosts[len].count(key) == 0) {
                minCosts[len][key] = costs[i];
            }
            else {  // 注意costs[word]可能有重复的，取较小的一个
                minCosts[len][key] = min(minCosts[len][key], costs[i]);
            }
        }
    }

    int getMinimumCost(int sizeT, vector<int>& hashT, vector<int>& powerBase, map<int, unordered_map<int, int>>& minCosts) {
        int inf = INT_MAX / 2;
        vector<int> dp(sizeT + 1, inf);
        dp[0] = 0;

        for (int i = 1; i <= sizeT; ++i) {
            for (auto& kv : minCosts) {  // 这里枚举长度，最多只有sqrt(sum(word.size))个长度，每个长度最多只可能有一个匹配，从而避免枚举所有word
                int len = kv.first;
                if (len > i) {
                    break;
                }

                int key = hash(hashT, powerBase, i - len, i - 1);
                if (kv.second.count(key) != 0) {
                    dp[i] = min(dp[i], dp[i - len] + kv.second[key]);
                }
            }
        }

        return dp.back() == inf ? -1 : dp.back();
    }

    int mod = 1000000007;
    int base = 9907;
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> words = { "abdef","abc","d","def","ef" };
    vector<int> costs = { 100,1,1,10,5 };
    check.checkInt(7, o.minimumCost("abcdef", words, costs));

    words = { "z","zz","zzz" };
    costs = { 1,10,100 };
    check.checkInt(-1, o.minimumCost("aaaa", words, costs));
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
