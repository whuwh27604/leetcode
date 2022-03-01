/* 使两字符串互为字母异位词的最少步骤数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 s 和 t 。在一步操作中，你可以给 s 或者 t 追加 任一字符 。

返回使 s 和 t 互为 字母异位词 所需的最少步骤数。

字母异位词 指字母相同但是顺序不同（或者相同）的字符串。

 

示例 1：

输入：s = "leetcode", t = "coats"
输出：7
解释：
- 执行 2 步操作，将 "as" 追加到 s = "leetcode" 中，得到 s = "leetcodeas" 。
- 执行 5 步操作，将 "leede" 追加到 t = "coats" 中，得到 t = "coatsleede" 。
"leetcodeas" 和 "coatsleede" 互为字母异位词。
总共用去 2 + 5 = 7 步。
可以证明，无法用少于 7 步操作使这两个字符串互为字母异位词。
示例 2：

输入：s = "night", t = "thing"
输出：0
解释：给出的字符串已经互为字母异位词。因此，不需要任何进一步操作。
 

提示：

1 <= s.length, t.length <= 2 * 105
s 和 t 由小写英文字符组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnt1('z' + 1, 0), cnt2('z' + 1, 0);

        count(s, cnt1);
        count(t, cnt2);

        return getMinSteps(cnt1, cnt2);
    }

    void count(string& s, vector<int>& cnt) {
        for (char c : s) {
            ++cnt[c];
        }
    }

    int getMinSteps(vector<int>& cnt1, vector<int>& cnt2) {
        int steps = 0;

        for (char c = 'a'; c <= 'z'; ++c) {
            steps += abs(cnt1[c] - cnt2[c]);
        }

        return steps;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(7, o.minSteps("leetcode", "coats"));
    check.checkInt(0, o.minSteps("night", "thing"));
    check.checkInt(2, o.minSteps("a", "z"));
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
