/* 生成交替二进制字符串的最少操作数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个仅由字符 '0' 和 '1' 组成的字符串 s 。一步操作中，你可以将任一 '0' 变成 '1' ，或者将 '1' 变成 '0' 。

交替字符串 定义为：如果字符串中不存在相邻两个字符相等的情况，那么该字符串就是交替字符串。例如，字符串 "010" 是交替字符串，而字符串 "0100" 不是。

返回使 s 变成 交替字符串 所需的 最少 操作数。

 

示例 1：

输入：s = "0100"
输出：1
解释：如果将最后一个字符变为 '1' ，s 就变成 "0101" ，即符合交替字符串定义。
示例 2：

输入：s = "10"
输出：0
解释：s 已经是交替字符串。
示例 3：

输入：s = "1111"
输出：2
解释：需要 2 步操作得到 "0101" 或 "1010" 。
 

提示：

1 <= s.length <= 104
s[i] 是 '0' 或 '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-changes-to-make-alternating-binary-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        char c1 = '0', c2 = '1';
        int operations1 = 0, operations2 = 0;

        for (char c : s) {
            if (c == c1) {
                ++operations2;
            }
            else {
                ++operations1;
            }

            swap(c1, c2);
        }

        return min(operations1, operations2);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.minOperations("0100"));
    check.checkInt(0, o.minOperations("10"));
    check.checkInt(2, o.minOperations("1111"));
    check.checkInt(0, o.minOperations("1"));
    check.checkInt(2, o.minOperations("111000"));
    check.checkInt(23, o.minOperations("11111111111100000000000010010111000111110100101001"));
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
