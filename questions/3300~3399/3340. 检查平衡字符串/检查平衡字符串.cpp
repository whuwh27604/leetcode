/* 检查平衡字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个仅由数字 0 - 9 组成的字符串 num。如果偶数下标处的数字之和等于奇数下标处的数字之和，则认为该数字字符串是一个 平衡字符串。

如果 num 是一个 平衡字符串，则返回 true；否则，返回 false。



示例 1：

输入：num = "1234"

输出：false

解释：

偶数下标处的数字之和为 1 + 3 = 4，奇数下标处的数字之和为 2 + 4 = 6。
由于 4 不等于 6，num 不是平衡字符串。
示例 2：

输入：num = "24123"

输出：true

解释：

偶数下标处的数字之和为 2 + 1 + 3 = 6，奇数下标处的数字之和为 4 + 2 = 6。
由于两者相等，num 是平衡字符串。


提示：

2 <= num.length <= 100
num 仅由数字 0 - 9 组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isBalanced(string num) {
        int size = (int)num.size(), odd = 0, even = 0;

        for (int i = 0; i < size; ++i) {
            if ((i & 1) == 0) {
                even += (num[i] - '0');
            }
            else {
                odd += (num[i] - '0');
            }
        }

        return even == odd;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(false, o.isBalanced("1234"));
    check.checkBool(true, o.isBalanced("24123"));
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
