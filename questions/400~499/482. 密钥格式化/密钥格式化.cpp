/* 密钥格式化.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个密钥字符串 S ，只包含字母，数字以及 '-'（破折号）。其中， N 个 '-' 将字符串分成了 N+1 组。

给你一个数字 K，请你重新格式化字符串，除了第一个分组以外，每个分组要包含 K 个字符；而第一个分组中，至少要包含 1 个字符。两个分组之间需要用 '-'（破折号）隔开，并且将所有的小写字母转换为大写字母。

给定非空字符串 S 和数字 K，按照上面描述的规则进行格式化。

 

示例 1：

输入：S = "5F3Z-2e-9-w", K = 4
输出："5F3Z-2E9W"
解释：字符串 S 被分成了两个部分，每部分 4 个字符；
     注意，两个额外的破折号需要删掉。
示例 2：

输入：S = "2-5g-3-J", K = 2
输出："2-5G-3J"
解释：字符串 S 被分成了 3 个部分，按照前面的规则描述，第一部分的字符可以少于给定的数量，其余部分皆为 2 个字符。
 

提示:

S 的长度可能很长，请按需分配大小。K 为正整数。
S 只包含字母数字（a-z，A-Z，0-9）以及破折号'-'
S 非空

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/license-key-formatting
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int numbersWithoutDash = 0;
        unsigned int i;
        for (i = 0; i < S.size(); i++) {
            if (S[i] == '-') {
                continue;
            }
            numbersWithoutDash++;
        }

        if (numbersWithoutDash == 0) {
            return "";
        }

        int numbersFirstGroup = (numbersWithoutDash % K);
        int numbersNewFormat = (numbersWithoutDash + (numbersWithoutDash / K));
        if (numbersFirstGroup == 0) {
            numbersFirstGroup = K;
            numbersNewFormat--;
        }

        string newFormat;
        newFormat.reserve(numbersNewFormat);
        int count = 0;
        for (i = 0; i < S.size(); i++) {
            if (S[i] == '-') {
                continue;
            }

            newFormat.push_back(toupper(S[i]));
            count++;
            if (count == numbersFirstGroup) {
                break;
            }
        }

        count = 0;
        for (i = (i + 1); i < S.size(); i++) {
            if (S[i] == '-') {
                continue;
            }

            if (count == 0) {
                newFormat.push_back('-');
            }

            newFormat.push_back(toupper(S[i]));
            count++;
            if (count == K) {
                count = 0;
            }
        }

        return newFormat;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string S = "5F3Z-2e-9-w";
    string expected = "5F3Z-2E9W";
    check.checkString(expected, o.licenseKeyFormatting(S, 4));

    S = "-5F3Z-2e-9-w";
    expected = "5F-3Z2-E9W";
    check.checkString(expected, o.licenseKeyFormatting(S, 3));

    S = "--5F3Z-2e-9-w-";
    expected = "5F-3Z2-E9W";
    check.checkString(expected, o.licenseKeyFormatting(S, 3));

    S = "--5F3Z-2e-9-ww---";
    expected = "5F3-Z2E-9WW";
    check.checkString(expected, o.licenseKeyFormatting(S, 3));

    S = "--5F3Z-2e-9-ww---";
    expected = "5-F-3-Z-2-E-9-W-W";
    check.checkString(expected, o.licenseKeyFormatting(S, 1));

    S = "-5F3Z-2e-9-w";
    expected = "5-F3Z2E9W";
    check.checkString(expected, o.licenseKeyFormatting(S, 7));

    S = "-5F3Z-2e-9-w";
    expected = "5F3Z2E9W";
    check.checkString(expected, o.licenseKeyFormatting(S, 8));

    S = "2-5g-3-J";
    expected = "2-5G-3J";
    check.checkString(expected, o.licenseKeyFormatting(S, 2));

    S = "2-5g-3-J";
    expected = "2-5-G-3-J";
    check.checkString(expected, o.licenseKeyFormatting(S, 1));

    S = "2-5g-3-J";
    expected = "25G3J";
    check.checkString(expected, o.licenseKeyFormatting(S, 100));

    S = "---";
    expected = "";
    check.checkString(expected, o.licenseKeyFormatting(S, 3));

    S = "---a";
    expected = "A";
    check.checkString(expected, o.licenseKeyFormatting(S, 3));
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
