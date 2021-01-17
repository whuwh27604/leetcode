/* 字符频次唯一的最小删除次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果字符串 s 中 不存在 两个不同字符 频次 相同的情况，就称 s 是 优质字符串 。

给你一个字符串 s，返回使 s 成为 优质字符串 需要删除的 最小 字符数。

字符串中字符的 频次 是该字符在字符串中的出现次数。例如，在字符串 "aab" 中，'a' 的频次是 2，而 'b' 的频次是 1 。

 

示例 1：

输入：s = "aab"
输出：0
解释：s 已经是优质字符串。
示例 2：

输入：s = "aaabbbcc"
输出：2
解释：可以删除两个 'b' , 得到优质字符串 "aaabcc" 。
另一种方式是删除一个 'b' 和一个 'c' ，得到优质字符串 "aaabbc" 。
示例 3：

输入：s = "ceabaacb"
输出：2
解释：可以删除两个 'c' 得到优质字符串 "eabaab" 。
注意，只需要关注结果字符串中仍然存在的字符。（即，频次为 0 的字符会忽略不计。）
 

提示：

1 <= s.length <= 105
s 仅含小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-deletions-to-make-character-frequencies-unique
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> letterFrequencies(26, 0);
        int deletions = 0;

        for (char c : s) {
            ++letterFrequencies[c - 'a'];
        }

        sort(letterFrequencies.begin(), letterFrequencies.end());

        for (int i = 25; i > 0; --i) {
            if (letterFrequencies[i - 1] >= letterFrequencies[i]) {
                int target = letterFrequencies[i] == 0 ? 0 : letterFrequencies[i] - 1;
                deletions += (letterFrequencies[i - 1] - target);
                letterFrequencies[i - 1] = target;
            }
        }

        return deletions;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(0, o.minDeletions("aab"));
    check.checkInt(2, o.minDeletions("aaabbbcc"));
    check.checkInt(2, o.minDeletions("ceabaacb"));
    check.checkInt(0, o.minDeletions("x"));
    check.checkInt(15, o.minDeletions("aaabbbcccdddeeefffggg"));
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
