/* 检查两个字符串是否几乎相等.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果两个字符串 word1 和 word2 中从 'a' 到 'z' 每一个字母出现频率之差都 不超过 3 ，那么我们称这两个字符串 word1 和 word2 几乎相等 。

给你两个长度都为 n 的字符串 word1 和 word2 ，如果 word1 和 word2 几乎相等 ，请你返回 true ，否则返回 false 。

一个字母 x 的出现 频率 指的是它在字符串中出现的次数。

 

示例 1：

输入：word1 = "aaaa", word2 = "bccb"
输出：false
解释：字符串 "aaaa" 中有 4 个 'a' ，但是 "bccb" 中有 0 个 'a' 。
两者之差为 4 ，大于上限 3 。
示例 2：

输入：word1 = "abcdeef", word2 = "abaaacc"
输出：true
解释：word1 和 word2 中每个字母出现频率之差至多为 3 ：
- 'a' 在 word1 中出现了 1 次，在 word2 中出现了 4 次，差为 3 。
- 'b' 在 word1 中出现了 1 次，在 word2 中出现了 1 次，差为 0 。
- 'c' 在 word1 中出现了 1 次，在 word2 中出现了 2 次，差为 1 。
- 'd' 在 word1 中出现了 1 次，在 word2 中出现了 0 次，差为 1 。
- 'e' 在 word1 中出现了 2 次，在 word2 中出现了 0 次，差为 2 。
- 'f' 在 word1 中出现了 1 次，在 word2 中出现了 0 次，差为 1 。
示例 3：

输入：word1 = "cccddabba", word2 = "babababab"
输出：true
解释：word1 和 word2 中每个字母出现频率之差至多为 3 ：
- 'a' 在 word1 中出现了 2 次，在 word2 中出现了 4 次，差为 2 。
- 'b' 在 word1 中出现了 2 次，在 word2 中出现了 5 次，差为 3 。
- 'c' 在 word1 中出现了 3 次，在 word2 中出现了 0 次，差为 3 。
- 'd' 在 word1 中出现了 2 次，在 word2 中出现了 0 次，差为 2 。
 

提示：

n == word1.length == word2.length
1 <= n <= 100
word1 和 word2 都只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-whether-two-strings-are-almost-equivalent
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int i, size = word1.size();
        vector<int> count1('z' + 1, 0), count2('z' + 1, 0);

        for (i = 0; i < size; ++i) {
            ++count1[word1[i]];
            ++count2[word2[i]];
        }

        for (i = 'a'; i <= 'z'; ++i) {
            if (abs(count1[i] - count2[i]) > 3) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(false, o.checkAlmostEquivalent("aaaa", "bccb"));
    check.checkBool(true, o.checkAlmostEquivalent("abcdeef", "abaaacc"));
    check.checkBool(true, o.checkAlmostEquivalent("cccddabba", "babababab"));
    check.checkBool(true, o.checkAlmostEquivalent("z", "x"));
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
