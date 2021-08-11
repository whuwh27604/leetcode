/* 检查是否所有字符出现次数相同.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，如果 s 是一个 好 字符串，请你返回 true ，否则请返回 false 。

如果 s 中出现过的 所有 字符的出现次数 相同 ，那么我们称字符串 s 是 好 字符串。

 

示例 1：

输入：s = "abacbc"
输出：true
解释：s 中出现过的字符为 'a'，'b' 和 'c' 。s 中所有字符均出现 2 次。
示例 2：

输入：s = "aaabb"
输出：false
解释：s 中出现过的字符为 'a' 和 'b' 。
'a' 出现了 3 次，'b' 出现了 2 次，两者出现次数不同。
 

提示：

1 <= s.length <= 1000
s 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-all-characters-have-equal-number-of-occurrences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> count('z' + 1, 0);
        int i, occurrences = 0;

        for (char c : s) {
            ++count[c];
        }

        for (i = 'a'; i <= 'z'; ++i) {
            if (count[i] != 0) {
                occurrences = count[i];
                break;
            }
        }

        for (i += 1; i <= 'z'; ++i) {
            if (count[i] != 0 && count[i] != occurrences) {
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

    check.checkBool(true, o.areOccurrencesEqual("z"));
    check.checkBool(true, o.areOccurrencesEqual("aaaaaaaa"));
    check.checkBool(true, o.areOccurrencesEqual("abacbc"));
    check.checkBool(true, o.areOccurrencesEqual("abcdefg"));
    check.checkBool(false, o.areOccurrencesEqual("aaabb"));
    check.checkBool(false, o.areOccurrencesEqual("abcdefgg"));
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
