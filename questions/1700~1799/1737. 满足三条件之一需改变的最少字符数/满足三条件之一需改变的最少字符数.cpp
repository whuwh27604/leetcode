/* 满足三条件之一需改变的最少字符数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 a 和 b ，二者均由小写字母组成。一步操作中，你可以将 a 或 b 中的 任一字符 改变为 任一小写字母 。

操作的最终目标是满足下列三个条件 之一 ：

a 中的 每个字母 在字母表中 严格小于 b 中的 每个字母 。
b 中的 每个字母 在字母表中 严格小于 a 中的 每个字母 。
a 和 b 都 由 同一个 字母组成。
返回达成目标所需的 最少 操作数。

 

示例 1：

输入：a = "aba", b = "caa"
输出：2
解释：满足每个条件的最佳方案分别是：
1) 将 b 变为 "ccc"，2 次操作，满足 a 中的每个字母都小于 b 中的每个字母；
2) 将 a 变为 "bbb" 并将 b 变为 "aaa"，3 次操作，满足 b 中的每个字母都小于 a 中的每个字母；
3) 将 a 变为 "aaa" 并将 b 变为 "aaa"，2 次操作，满足 a 和 b 由同一个字母组成。
最佳的方案只需要 2 次操作（满足条件 1 或者条件 3）。
示例 2：

输入：a = "dabadd", b = "cda"
输出：3
解释：满足条件 1 的最佳方案是将 b 变为 "eee" 。
 

提示：

1 <= a.length, b.length <= 105
a 和 b 只由小写字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> countA(26), countB(26);

        countLetters(a, countA);
        countLetters(b, countB);

        return min({ operationsALessB(countA, countB), operationsALessB(countB, countA), operationsOneLetter(countA, countB, a.size() + b.size()) });
    }

    void countLetters(string& s, vector<int>& count) {
        for (char c : s) {
            ++count[c - 'a'];
        }
    }

    void getPresum(vector<int>& count, vector<int>& presum) {
        presum[0] = 0;

        for (int i = 0; i < 26; ++i) {
            presum[i + 1] = presum[i] + count[i];
        }
    }

    int operationsALessB(vector<int>& countA, vector<int>& countB) {
        vector<int> presumA(27), presumB(27);
        int minOperations = INT_MAX;

        getPresum(countA, presumA);
        getPresum(countB, presumB);

        for (int i = 1; i < 26; ++i) {
            minOperations = min(minOperations, presumA[26] - presumA[i] + presumB[i]);
        }

        return minOperations;
    }

    int operationsOneLetter(vector<int>& countA, vector<int>& countB, int totalSize) {
        int minOperations = INT_MAX;

        for (int i = 0; i < 26; ++i) {
            minOperations = min(minOperations, totalSize - countA[i] - countB[i]);
        }

        return minOperations;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.minCharacters("aba", "caa"));
    check.checkInt(3, o.minCharacters("dabadd", "cda"));
    check.checkInt(3, o.minCharacters("cda", "dabadd"));
    check.checkInt(2, o.minCharacters("abe", "ace"));
    check.checkInt(14, o.minCharacters("abcdefghijklmn", "nmlkjihgfedcba"));
    check.checkInt(0, o.minCharacters("a", "a"));
    check.checkInt(0, o.minCharacters("a", "b"));
    check.checkInt(1, o.minCharacters("zzzzz", "abcdefghijklmnopqrstuvwxyz"));
    check.checkInt(1, o.minCharacters("abcdefghijklmnopqrstuvwxyz", "zzzzz"));
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
