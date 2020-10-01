/* 替换后的最长重复字符.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。在执行上述操作后，找到包含重复字母的最长子串的长度。

注意:
字符串长度 和 k 不会超过 104。

示例 1:

输入:
s = "ABAB", k = 2

输出:
4

解释:
用两个'A'替换为两个'B',反之亦然。
示例 2:

输入:
s = "AABABBA", k = 1

输出:
4

解释:
将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-repeating-character-replacement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        /* 假设最后找到的最长子串是xxx...x，其中真正的x有j个，另外k个是替换来的。那么意味着在滑动窗口(j+k)时，某一时刻窗口内有j个x。
           所以问题就变成了滑动窗口，统计窗口内字符的数量，根据字符的最大个数扩展窗口。能够扩展到的最大窗口就是答案 */
        int i, size = s.size(), maxCount = 0;
        int charCount[91] = { 0 };
        
        // 构建初始窗口，大小为一个maxCount+k，此时刚好可以把其他k个字符替换为最多的这个字符，组成第一个最长子串
        for (i = 0; i < size; i++) {
            charCount[s[i]]++;
            maxCount = max(maxCount, charCount[s[i]]);
            if (i + 1 - maxCount == k) {
                break;
            }
        }

        int left = 0, right = (i == size) ? size : i + 1;
        while (right < size) {
            if (++charCount[s[right]] > maxCount) {  // 有新的最大值，扩展窗口
                maxCount = charCount[s[right]];
                right++;
            }
            else {  // 平移窗口，把最左边的字符减1
                charCount[s[left]]--;
                left++;
                right++;
            }
        }

        return right - left;  // 返回窗口大小
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(4, o.characterReplacement("ABAB", 2));
    check.checkInt(1, o.characterReplacement("ABAB", 0));
    check.checkInt(3, o.characterReplacement("ABAB", 1));
    check.checkInt(4, o.characterReplacement("ABAB", 3));
    check.checkInt(2, o.characterReplacement("AABABBA", 0));
    check.checkInt(4, o.characterReplacement("AABABBA", 1));
    check.checkInt(5, o.characterReplacement("AABABBA", 2));
    check.checkInt(7, o.characterReplacement("AABABBA", 3));
    check.checkInt(7, o.characterReplacement("AABABBA", 4));
    check.checkInt(0, o.characterReplacement("", 0));
    check.checkInt(0, o.characterReplacement("", 1));
    check.checkInt(1, o.characterReplacement("A", 0));
    check.checkInt(1, o.characterReplacement("A", 1));
    check.checkInt(1, o.characterReplacement("AB", 0));
    check.checkInt(2, o.characterReplacement("AB", 1));
    check.checkInt(2, o.characterReplacement("AB", 5));
    check.checkInt(2, o.characterReplacement("AA", 3));
    check.checkInt(5, o.characterReplacement("AAABCDEDFG", 2));
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
