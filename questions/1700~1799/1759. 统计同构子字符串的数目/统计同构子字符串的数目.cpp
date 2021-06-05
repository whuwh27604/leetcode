/* 统计同构子字符串的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，返回 s 中 同构子字符串 的数目。由于答案可能很大，只需返回对 109 + 7 取余 后的结果。

同构字符串 的定义为：如果一个字符串中的所有字符都相同，那么该字符串就是同构字符串。

子字符串 是字符串中的一个连续字符序列。

 

示例 1：

输入：s = "abbcccaa"
输出：13
解释：同构子字符串如下所列：
"a"   出现 3 次。
"aa"  出现 1 次。
"b"   出现 2 次。
"bb"  出现 1 次。
"c"   出现 3 次。
"cc"  出现 2 次。
"ccc" 出现 1 次。
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13
示例 2：

输入：s = "xy"
输出：2
解释：同构子字符串是 "x" 和 "y" 。
示例 3：

输入：s = "zzzzz"
输出：15
 

提示：

1 <= s.length <= 105
s 由小写字符串组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-number-of-homogenous-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        s += 'Z';
        long long homogenous = 0, count = 1;

        for (int i = 1; i < (int)s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++count;
            }
            else {
                homogenous = (homogenous + (count + 1) * count / 2) % 1000000007;
                count = 1;
            }
        }

        return (int)homogenous;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(13, o.countHomogenous("abbcccaa"));
    check.checkInt(2, o.countHomogenous("xy"));
    check.checkInt(15, o.countHomogenous("zzzzz"));
    check.checkInt(1, o.countHomogenous("z"));
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
