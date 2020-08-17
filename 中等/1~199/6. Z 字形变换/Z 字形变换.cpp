/* Z 字形变换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zigzag-conversion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }

        string z;
        int group = 2 * numRows - 2;
        int i, j, len = s.size();

        for (i = 0; i < len; i += group) {
            z += s[i];
        }

        for (j = 1; j < numRows - 1; j++) {
            for (i = j; i < len; i += group) {
                z += s[i];

                int next = i + group - 2 * j;
                if (next < len) {
                    z += s[next];
                }
            }
        }

        for (i = numRows - 1; i < len; i += group) {
            z += s[i];
        }

        return z;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("LCIRETOESIIGEDHN", o.convert("LEETCODEISHIRING", 3));
    check.checkString("LDREOEIIECIHNTSG", o.convert("LEETCODEISHIRING", 4));
    check.checkString("LEETCODEISHIRING", o.convert("LEETCODEISHIRING", 1));
    check.checkString("LECDIHRNETOESIIG", o.convert("LEETCODEISHIRING", 2));
    check.checkString("LEETCODEISHIRING", o.convert("LEETCODEISHIRING", 16));
    check.checkString("LNEIGERTICHOSDIE", o.convert("LEETCODEISHIRING", 8));
    check.checkString("LEGENTICROIDHESI", o.convert("LEETCODEISHIRING", 9));
    check.checkString("aiqybhjprxzfcgkoswaedflntvbdemuc", o.convert("abcdefghijklmnopqrstuvwxyzabcdef", 5));
    check.checkString("aiqygbhjprxzfcgkoswaedflntvbdemuc", o.convert("abcdefghijklmnopqrstuvwxyzabcdefg", 5));
    check.checkString("aiqygbhjprxzfhcgkoswaedflntvbdemuc", o.convert("abcdefghijklmnopqrstuvwxyzabcdefgh", 5));
    check.checkString("aiqygbhjprxzfhcgkoswaeidflntvbdemuc", o.convert("abcdefghijklmnopqrstuvwxyzabcdefghi", 5));
    check.checkString("aiqygbhjprxzfhcgkoswaeidflntvbdjemuc", o.convert("abcdefghijklmnopqrstuvwxyzabcdefghij", 5));
    check.checkString("aiqygbhjprxzfhcgkoswaeidflntvbdjemuck", o.convert("abcdefghijklmnopqrstuvwxyzabcdefghijk", 5));
    check.checkString("aiqygbhjprxzfhcgkoswaeidflntvbdjlemuck", o.convert("abcdefghijklmnopqrstuvwxyzabcdefghijkl", 5));
    check.checkString("aiqygbhjprxzfhcgkoswaeimdflntvbdjlemuck", o.convert("abcdefghijklmnopqrstuvwxyzabcdefghijklm", 5));
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
