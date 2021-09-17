/* 删除一个字符串中所有出现的给定子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 s 和 part ，请你对 s 反复执行以下操作直到 所有 子字符串 part 都被删除：

找到 s 中 最左边 的子字符串 part ，并将它从 s 中删除。
请你返回从 s 中删除所有 part 子字符串以后得到的剩余字符串。

一个 子字符串 是一个字符串中连续的字符序列。

 

示例 1：

输入：s = "daabcbaabcbc", part = "abc"
输出："dab"
解释：以下操作按顺序执行：
- s = "daabcbaabcbc" ，删除下标从 2 开始的 "abc" ，得到 s = "dabaabcbc" 。
- s = "dabaabcbc" ，删除下标从 4 开始的 "abc" ，得到 s = "dababc" 。
- s = "dababc" ，删除下标从 3 开始的 "abc" ，得到 s = "dab" 。
此时 s 中不再含有子字符串 "abc" 。
示例 2：

输入：s = "axxxxyyyyb", part = "xy"
输出："ab"
解释：以下操作按顺序执行：
- s = "axxxxyyyyb" ，删除下标从 4 开始的 "xy" ，得到 s = "axxxyyyb" 。
- s = "axxxyyyb" ，删除下标从 3 开始的 "xy" ，得到 s = "axxyyb" 。
- s = "axxyyb" ，删除下标从 2 开始的 "xy" ，得到 s = "axyb" 。
- s = "axyb" ，删除下标从 1 开始的 "xy" ，得到 s = "ab" 。
此时 s 中不再含有子字符串 "xy" 。
 

提示：

1 <= s.length <= 1000
1 <= part.length <= 1000
s​​​​​​ 和 part 只包小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-all-occurrences-of-a-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos = 0;

        while ((pos = s.find(part)) != string::npos) {
            s.erase(pos, part.size());
        }

        return s;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("dab", o.removeOccurrences("daabcbaabcbc", "abc"));
    check.checkString("ab", o.removeOccurrences("axxxxyyyyb", "xy"));
    check.checkString("a", o.removeOccurrences("a", "b"));
    check.checkString("", o.removeOccurrences("a", "a"));
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
