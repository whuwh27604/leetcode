/* 强密码检验器 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果一个密码满足以下所有条件，我们称它是一个 强 密码：

它有至少 8 个字符。
至少包含 一个小写英文 字母。
至少包含 一个大写英文 字母。
至少包含 一个数字 。
至少包含 一个特殊字符 。特殊字符为："!@#$%^&*()-+" 中的一个。
它 不 包含 2 个连续相同的字符（比方说 "aab" 不符合该条件，但是 "aba" 符合该条件）。
给你一个字符串 password ，如果它是一个 强 密码，返回 true，否则返回 false 。

 

示例 1：

输入：password = "IloveLe3tcode!"
输出：true
解释：密码满足所有的要求，所以我们返回 true 。
示例 2：

输入：password = "Me+You--IsMyDream"
输出：false
解释：密码不包含数字，且包含 2 个连续相同的字符。所以我们返回 false 。
示例 3：

输入：password = "1aB!"
输出：false
解释：密码不符合长度要求。所以我们返回 false 。
 

提示：

1 <= password.length <= 100
password 包含字母，数字和 "!@#$%^&*()-+" 这些特殊字符。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/strong-password-checker-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) {
            return false;
        }

        bool hasLowercase = false, hasUppercase = false, hasDigit = false, hasSpecial = false;
        char prev = 0;
        unordered_set<char> specials = { '!','@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+' };

        for (char c : password) {
            if (c == prev) {
                return false;
            }

            if (c >= 'a' && c <= 'z') {
                hasLowercase = true;
            }

            if (c >= 'A' && c <= 'Z') {
                hasUppercase = true;
            }

            if (c >= '0' && c <= '9') {
                hasDigit = true;
            }

            if (specials.count(c) != 0) {
                hasSpecial = true;
            }

            prev = c;
        }

        return hasLowercase && hasUppercase && hasDigit && hasSpecial;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.strongPasswordCheckerII("IloveLe3tcode!"));
    check.checkBool(false, o.strongPasswordCheckerII("Me+You--IsMyDream"));
    check.checkBool(false, o.strongPasswordCheckerII("1aB!"));
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
