/* 不重叠回文子字符串的最大数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个 正 整数 k 。

从字符串 s 中选出一组满足下述条件且 不重叠 的子字符串：

每个子字符串的长度 至少 为 k 。
每个子字符串是一个 回文串 。
返回最优方案中能选择的子字符串的 最大 数目。

子字符串 是字符串中一个连续的字符序列。



示例 1 ：

输入：s = "abaccdbbd", k = 3
输出：2
解释：可以选择 s = "abaccdbbd" 中斜体加粗的子字符串。"aba" 和 "dbbd" 都是回文，且长度至少为 k = 3 。
可以证明，无法选出两个以上的有效子字符串。
示例 2 ：

输入：s = "adbcda", k = 2
输出：0
解释：字符串中不存在长度至少为 2 的回文子字符串。


提示：

1 <= k <= s.length <= 2000
s 仅由小写英文字母组成
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Manacher {
public:
    Manacher(string& s) {
        preprocess(s);
        radii.resize(ms.size());
        calculate();
    }

    void preprocess(string& s) {
        ms += "@#";  // 首尾添加字符@、$，可以简化后面算法的边界处理

        for (char c : s) {
            ms += c;
            ms += '#';  // 每个字符前后插入#，可以使奇偶回文都变为奇回文，简化算法的处理
        }

        ms += '$';
    }

    void calculate() {
        /*   symmetryMaxRight   symmetryI     center          i            maxRight
        ------------|---------------|------------|------------|---------------|-------- */
        int i, size = ms.size();
        int center, maxRight = 0;

        for (i = 1; i < size - 1; i++) {
            if (i < maxRight) {
                /* （2 * center - i）是symmetryI，分三种情况可证明下面这句话成立：
                   1、radii[symmetryI]大于(symmetryI-symmetryMaxRight)，则radii[i]=(symmetryI-symmetryMaxRight)=(maxRight-i)，不能再大
                   2、radii[symmetryI]小于(symmetryI-symmetryMaxRight)，则radii[i]=radii[symmetryI]，不能再大
                   3、radii[symmetryI]等于(symmetryI-symmetryMaxRight)，则radii[i]=radii[symmetryI]=(maxRight-i)，然后执行下面的while语句继续拓展 */
                radii[i] = min(radii[2 * center - i], maxRight - i);
            }
            else {
                radii[i] = 1;
            }

            // 中心拓展找最大的半径，预处理在首尾添加的不同字符保证不会越界
            while (ms[i - radii[i]] == ms[i + radii[i]]) {
                radii[i]++;
            }

            // 每走一步i，都要维护maxRight。我们希望maxRight尽可能往右，这样才能更有机会执行if (i < maxRight)提高效率
            if (maxRight < i + radii[i]) {
                center = i;
                maxRight = i + radii[i];
            }
        }
    }

    bool isPalindrome(int start, int end) {
        return radii[(start + 1) + (end + 1)] / 2 >= (end - start + 2) / 2;
    }

private:
    string ms;
    vector<int> radii;
};

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int size = s.size();
        vector<int> dp(size + 1, 0);
        Manacher ms(s);

        if (ms.isPalindrome(size - k, size - 1)) {
            dp[size - k] = 1;
        }

        for (int i = size - k - 1; i >= 0; --i) {
            dp[i] = dp[i + 1];

            if (ms.isPalindrome(i, i + k - 1)) {
                dp[i] = max(dp[i], 1 + dp[i + k]);
            }

            if (ms.isPalindrome(i, i + k)) {
                dp[i] = max(dp[i], 1 + dp[i + k + 1]);
            }
        }

        return dp[0];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.maxPalindromes("abaccdbbd", 3));
    check.checkInt(0, o.maxPalindromes("adbcda", 2));
    check.checkInt(5, o.maxPalindromes("aaaaa", 1));
    check.checkInt(4, o.maxPalindromes("aaaaaaaa", 2));
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
