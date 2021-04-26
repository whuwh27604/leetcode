/* 段式回文.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
段式回文 其实与 一般回文 类似，只不过是最小的单位是 一段字符 而不是 单个字母。

举个例子，对于一般回文 "abcba" 是回文，而 "volvo" 不是，但如果我们把 "volvo" 分为 "vo"、"l"、"vo" 三段，则可以认为 “(vo)(l)(vo)” 是段式回文（分为 3 段）。

 

给你一个字符串 text，在确保它满足段式回文的前提下，请你返回 段 的 最大数量 k。

如果段的最大数量为 k，那么存在满足以下条件的 a_1, a_2, ..., a_k：

每个 a_i 都是一个非空字符串；
将这些字符串首位相连的结果 a_1 + a_2 + ... + a_k 和原始字符串 text 相同；
对于所有1 <= i <= k，都有 a_i = a_{k+1 - i}。
 

示例 1：

输入：text = "ghiabcdefhelloadamhelloabcdefghi"
输出：7
解释：我们可以把字符串拆分成 "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)"。
示例 2：

输入：text = "merchant"
输出：1
解释：我们可以把字符串拆分成 "(merchant)"。
示例 3：

输入：text = "antaprezatepzapreanta"
输出：11
解释：我们可以把字符串拆分成 "(a)(nt)(a)(pre)(za)(tpe)(za)(pre)(a)(nt)(a)"。
示例 4：

输入：text = "aaa"
输出：3
解释：我们可以把字符串拆分成 "(a)(a)(a)"。
 

提示：

text 仅由小写英文字符组成。
1 <= text.length <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-chunked-palindrome-decomposition
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestDecomposition(string text) {
        // 贪心策略是正确的，证明过程还比较繁琐，略...
        int size = text.size(), left = 0, right = size - 1, end, substrs = 0;

        while (left <= right) {
            for (end = left; end < right; ++end) {
                if (text[end] != text[right]) {
                    continue;
                }

                int len = end - left + 1;
                if (string(text, left, len) == string(text, right - len + 1, len)) {
                    break;
                }
            }

            substrs += (end < right ? 2 : 1);
            right -= (end - left + 1);
            left = end + 1;
        }

        return substrs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.longestDecomposition("a"));
    check.checkInt(2, o.longestDecomposition("aa"));
    check.checkInt(3, o.longestDecomposition("aaa"));
    check.checkInt(1, o.longestDecomposition("merchant"));
    check.checkInt(11, o.longestDecomposition("antaprezatepzapreanta"));
    check.checkInt(7, o.longestDecomposition("ghiabcdefhelloadamhelloabcdefghi"));
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
