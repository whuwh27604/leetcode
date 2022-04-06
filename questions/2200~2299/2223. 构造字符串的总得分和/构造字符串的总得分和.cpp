/* 构造字符串的总得分和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你需要从空字符串开始 构造 一个长度为 n 的字符串 s ，构造的过程为每次给当前字符串 前面 添加 一个 字符。构造过程中得到的所有字符串编号为 1 到 n ，其中长度为 i 的字符串编号为 si 。

比方说，s = "abaca" ，s1 == "a" ，s2 == "ca" ，s3 == "aca" 依次类推。
si 的 得分 为 si 和 sn 的 最长公共前缀 的长度（注意 s == sn ）。

给你最终的字符串 s ，请你返回每一个 si 的 得分之和 。

 

示例 1：

输入：s = "babab"
输出：9
解释：
s1 == "b" ，最长公共前缀是 "b" ，得分为 1 。
s2 == "ab" ，没有公共前缀，得分为 0 。
s3 == "bab" ，最长公共前缀为 "bab" ，得分为 3 。
s4 == "abab" ，没有公共前缀，得分为 0 。
s5 == "babab" ，最长公共前缀为 "babab" ，得分为 5 。
得分和为 1 + 0 + 3 + 0 + 5 = 9 ，所以我们返回 9 。
示例 2 ：

输入：s = "azbazbzaz"
输出：14
解释：
s2 == "az" ，最长公共前缀为 "az" ，得分为 2 。
s6 == "azbzaz" ，最长公共前缀为 "azb" ，得分为 3 。
s9 == "azbazbzaz" ，最长公共前缀为 "azbazbzaz" ，得分为 9 。
其他 si 得分均为 0 。
得分和为 2 + 3 + 9 = 14 ，所以我们返回 14 。
 

提示：

1 <= s.length <= 105
s 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-scores-of-built-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long sumScores(string s) {
        int size = s.length();
        vector<int> z(size, 0);
        long long sum = size;

        for (int i = 1, left = 0, right = 0; i < size; ++i) {
            z[i] = max(min(z[i - left], right - i + 1), 0);

            while (i + z[i] < size && s[z[i]] == s[i + z[i]]) {
                left = i;
                right = i + z[i];
                ++z[i];
            }

            sum += z[i];
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkLongLong(9, o.sumScores("babab"));
    check.checkLongLong(14, o.sumScores("azbazbzaz"));
    check.checkLongLong(1, o.sumScores("z"));
    check.checkLongLong(455, o.sumScores("bababazbazbzazbababazbazbzazbababazbazbzazbababazbazbzazbababazbazbzazbababazbazbzazbababazbazbzaz"));
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
