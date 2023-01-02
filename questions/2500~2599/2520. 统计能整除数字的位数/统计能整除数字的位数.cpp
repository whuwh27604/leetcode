/* 统计能整除数字的位数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 num ，返回 num 中能整除 num 的数位的数目。

如果满足 nums % val == 0 ，则认为整数 val 可以整除 nums 。



示例 1：

输入：num = 7
输出：1
解释：7 被自己整除，因此答案是 1 。
示例 2：

输入：num = 121
输出：2
解释：121 可以被 1 整除，但无法被 2 整除。由于 1 出现两次，所以返回 2 。
示例 3：

输入：num = 1248
输出：4
解释：1248 可以被它每一位上的数字整除，因此答案是 4 。


提示：

1 <= num <= 109
num 的数位中不含 0
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countDigits(int num) {
        int count = 0, number = num;

        while (number != 0) {
            int n = number % 10;
            number /= 10;

            if (num % n == 0) {
                ++count;
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.countDigits(7));
    check.checkInt(2, o.countDigits(121));
    check.checkInt(4, o.countDigits(1248));
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
