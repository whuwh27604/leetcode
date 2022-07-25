/* 第一个出现两次的字母.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由小写英文字母组成的字符串 s ，请你找出并返回第一个出现 两次 的字母。

注意：

如果 a 的 第二次 出现比 b 的 第二次 出现在字符串中的位置更靠前，则认为字母 a 在字母 b 之前出现两次。
s 包含至少一个出现两次的字母。
 

示例 1：

输入：s = "abccbaacz"
输出："c"
解释：
字母 'a' 在下标 0 、5 和 6 处出现。
字母 'b' 在下标 1 和 4 处出现。
字母 'c' 在下标 2 、3 和 7 处出现。
字母 'z' 在下标 8 处出现。
字母 'c' 是第一个出现两次的字母，因为在所有字母中，'c' 第二次出现的下标是最小的。
示例 2：

输入：s = "abcdd"
输出："d"
解释：
只有字母 'd' 出现两次，所以返回 'd' 。
 

提示：

2 <= s.length <= 100
s 由小写英文字母组成
s 包含至少一个重复字母

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/first-letter-to-appear-twice
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> exist('z' + 1, false);

        for (char c : s) {
            if (exist[c]) {
                return c;
            }

            exist[c] = true;
        }

        return 'a';
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkChar('c', o.repeatedCharacter("abccbaacz"));
    check.checkChar('d', o.repeatedCharacter("abcdd"));
    check.checkChar('a', o.repeatedCharacter("aa"));
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
