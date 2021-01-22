/* 十-二进制数的最少数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果一个十进制数字不含任何前导零，且每一位上的数字不是 0 就是 1 ，那么该数字就是一个 十-二进制数 。例如，101 和 1100 都是 十-二进制数，而 112 和 3001 不是。

给你一个表示十进制整数的字符串 n ，返回和为 n 的 十-二进制数 的最少数目。

 

示例 1：

输入：n = "32"
输出：3
解释：10 + 11 + 11 = 32
示例 2：

输入：n = "82734"
输出：8
示例 3：

输入：n = "27346209830709182346"
输出：9
 

提示：

1 <= n.length <= 105
n 仅由数字组成
n 不含任何前导零并总是表示正整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        return (int)(*max_element(n.begin(), n.end()) - '0');
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.minPartitions("32"));
    check.checkInt(8, o.minPartitions("82734"));
    check.checkInt(9, o.minPartitions("27346209830709182346"));
    check.checkInt(1, o.minPartitions("1"));
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
