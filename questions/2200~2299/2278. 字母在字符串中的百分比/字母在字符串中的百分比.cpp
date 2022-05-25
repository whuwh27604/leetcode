/* 字母在字符串中的百分比.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个字符 letter ，返回在 s 中等于 letter 字符所占的 百分比 ，向下取整到最接近的百分比。

 

示例 1：

输入：s = "foobar", letter = "o"
输出：33
解释：
等于字母 'o' 的字符在 s 中占到的百分比是 2 / 6 * 100% = 33% ，向下取整，所以返回 33 。
示例 2：

输入：s = "jjjj", letter = "k"
输出：0
解释：
等于字母 'k' 的字符在 s 中占到的百分比是 0% ，所以返回 0 。
 

提示：

1 <= s.length <= 100
s 由小写英文字母组成
letter 是一个小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/percentage-of-letter-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;

        for (char c : s) {
            if (c == letter) {
                ++count;
            }
        }

        return 100 * count / s.size();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(33, o.percentageLetter("foobar", 'o'));
    check.checkInt(0, o.percentageLetter("jjjj", 'k'));
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
