/* 每个元音包含偶数次的最长子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。

 

示例 1：

输入：s = "eleetminicoworoep"
输出：13
解释：最长子字符串是 "leetminicowor" ，它包含 e，i，o 各 2 个，以及 0 个 a，u 。
示例 2：

输入：s = "leetcodeisgreat"
输出：5
解释：最长子字符串是 "leetc" ，其中包含 2 个 e 。
示例 3：

输入：s = "bcbcbc"
输出：6
解释：这个示例中，字符串 "bcbcbc" 本身就是最长的，因为所有的元音 a，e，i，o，u 都出现了 0 次。
 

提示：

1 <= s.length <= 5 x 10^5
s 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int i, size = s.size(), longestSubstr = 0;
        int state = 0;
        vector<int> stateIndices(32, -2);
        stateIndices[0] = -1;
        vector<int> charIndices = { 0,-1,-1,-1,1,-1,-1,-1,2,-1,-1,-1,-1,-1,3,-1,-1,-1,-1,-1,4,-1,-1,-1,-1,-1 };


        for (i = 0; i < size; ++i) {
            int index = charIndices[s[i] - 'a'];
            if (index != -1) {  // 元音
                state ^= (1 << index);  // 该元音状态取反，即奇数变偶数，偶数变奇数
                if (stateIndices[state] != -2) {  // 这个状态已经出现过，说明2次出现的中间子串元音个数全部是偶数
                    longestSubstr = max(longestSubstr, i - stateIndices[state]);
                }
                else {  // 该状态没有出现过，记录下第一次出现的索引
                    stateIndices[state] = i;
                }
            }
            else {  // 辅音，需要计算可能的最大长度
                longestSubstr = max(longestSubstr, i - stateIndices[state]);
            }
        }

        return longestSubstr;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(13, o.findTheLongestSubstring("eleetminicoworoep"));
    check.checkInt(5, o.findTheLongestSubstring("leetcodeisgreat"));
    check.checkInt(6, o.findTheLongestSubstring("bcbcbc"));
    check.checkInt(2, o.findTheLongestSubstring("abc"));
    check.checkInt(1, o.findTheLongestSubstring("b"));
    check.checkInt(0, o.findTheLongestSubstring("a"));
    check.checkInt(2, o.findTheLongestSubstring("aa"));
    check.checkInt(52, o.findTheLongestSubstring("abcdefghijklmnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcba"));
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
