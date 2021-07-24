/* 不同的循环子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 text ，请你返回满足下述条件的 不同 非空子字符串的数目：

可以写成某个字符串与其自身相连接的形式（即，可以写为 a + a，其中 a 是某个字符串）。
例如，abcabc 就是 abc 和它自身连接形成的。

 

示例 1：

输入：text = "abcabcabc"
输出：3
解释：3 个子字符串分别为 "abcabc"，"bcabca" 和 "cabcab" 。
示例 2：

输入：text = "leetcodeleetcode"
输出：2
解释：2 个子字符串为 "ee" 和 "leetcodeleetcode" 。
 

提示：

1 <= text.length <= 2000
text 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distinct-echo-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int i, j, size = text.size(), echoStrs = 0;
        vector<int> preHash(size + 1), power(size + 1);
        vector<unordered_set<int>> seen(size + 1);

        prepare(text, preHash, power);

        for (i = 0; i < size - 1; ++i) {
            for (j = i + 1; 2 * j - i <= size; ++j) {
                int len = j - i;
                int hash1 = getHash(preHash, power, i, j - 1);
                if (seen[len].count(hash1) != 0) {
                    continue;
                }

                int hash2 = getHash(preHash, power, j, j + len - 1);
                if (hash1 != hash2) {
                    continue;
                }

                if (realMatch(text, i, j)) {
                    ++echoStrs;
                    seen[len].insert(hash1);
                }
            }
        }

        return echoStrs;
    }

    void prepare(string& text, vector<int>& preHash, vector<int>& power) {
        int size = text.size(), base = 31;

        preHash[0] = 0;
        power[0] = 1;

        for (int i = 1; i <= size; ++i) {
            preHash[i] = (int)(((long long)preHash[i - 1] * base + text[i - 1]) % mod);
            power[i] = (int)((long long)power[i - 1] * base % mod);
        }
    }

    int getHash(vector<int>& preHash, vector<int>& power, int left, int right) {
        return (int)((preHash[right + 1] - (long long)preHash[left] * power[right - left + 1] % mod + mod) % mod);
    }

    bool realMatch(string& text, int s1, int s2) {
        for (int i = s1; i < s2; ++i) {
            if (text[i] != text[s2 - s1 + i]) {
                return false;
            }
        }

        return true;
    }

private:
    int mod = 1000000007;
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.distinctEchoSubstrings("abcabcabc"));
    check.checkInt(2, o.distinctEchoSubstrings("leetcodeleetcode"));
    check.checkInt(0, o.distinctEchoSubstrings("z"));
    check.checkInt(1, o.distinctEchoSubstrings("zz"));
    check.checkInt(47, o.distinctEchoSubstrings("azazazazazazazazazazazazazazazazazazazazazazazazazazazazazazazazazazazazazazazazazazazazazazazaz"));
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
