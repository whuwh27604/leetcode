/* 字符串的总引力.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
字符串的 引力 定义为：字符串中 不同 字符的数量。

例如，"abbca" 的引力为 3 ，因为其中有 3 个不同字符 'a'、'b' 和 'c' 。
给你一个字符串 s ，返回 其所有子字符串的总引力 。

子字符串 定义为：字符串中的一个连续字符序列。

 

示例 1：

输入：s = "abbca"
输出：28
解释："abbca" 的子字符串有：
- 长度为 1 的子字符串："a"、"b"、"b"、"c"、"a" 的引力分别为 1、1、1、1、1，总和为 5 。
- 长度为 2 的子字符串："ab"、"bb"、"bc"、"ca" 的引力分别为 2、1、2、2 ，总和为 7 。
- 长度为 3 的子字符串："abb"、"bbc"、"bca" 的引力分别为 2、2、3 ，总和为 7 。
- 长度为 4 的子字符串："abbc"、"bbca" 的引力分别为 3、3 ，总和为 6 。
- 长度为 5 的子字符串："abbca" 的引力为 3 ，总和为 3 。
引力总和为 5 + 7 + 7 + 6 + 3 = 28 。
示例 2：

输入：s = "code"
输出：20
解释："code" 的子字符串有：
- 长度为 1 的子字符串："c"、"o"、"d"、"e" 的引力分别为 1、1、1、1 ，总和为 4 。
- 长度为 2 的子字符串："co"、"od"、"de" 的引力分别为 2、2、2 ，总和为 6 。
- 长度为 3 的子字符串："cod"、"ode" 的引力分别为 3、3 ，总和为 6 。
- 长度为 4 的子字符串："code" 的引力为 4 ，总和为 4 。
引力总和为 4 + 6 + 6 + 4 = 20 。
 

提示：

1 <= s.length <= 105
s 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/total-appeal-of-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long appealSum(string s) {
        vector<int> prevs(26, -1);
        int i, size = s.size();
        long long sum = 0;

        // 考虑字符s[i]，它前面一个相同字符的索引为prev，那么区间[prev + 1, size)内所有包含s[i]的子数组，s[i]都要贡献一个引力值
        for (i = 0; i < size; ++i) {
            int idx = s[i] - 'a';
            sum += (((long long)i - prevs[idx]) * ((long long)size - i));
            prevs[idx] = i;
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkLongLong(28, o.appealSum("abbca"));
    check.checkLongLong(20, o.appealSum("code"));
    check.checkLongLong(1, o.appealSum("z"));
    check.checkLongLong(15, o.appealSum("zzzzz"));
    check.checkLongLong(30275, o.appealSum("aabbccddeeffggaabbccddeeffggaabbccddeeffggaabbccddeeffggaabbccddeeffggaabbccddeeffggaabbccddeeffgg"));
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
