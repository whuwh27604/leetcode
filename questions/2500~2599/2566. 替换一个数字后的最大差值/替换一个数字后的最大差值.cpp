/* 替换一个数字后的最大差值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 num 。你知道 Danny Mittal 会偷偷将 0 到 9 中的一个数字 替换 成另一个数字。

请你返回将 num 中 恰好一个 数字进行替换后，得到的最大值和最小值的差位多少。

注意：

当 Danny 将一个数字 d1 替换成另一个数字 d2 时，Danny 需要将 nums 中所有 d1 都替换成 d2 。
Danny 可以将一个数字替换成它自己，也就是说 num 可以不变。
Danny 可以将数字分别替换成两个不同的数字分别得到最大值和最小值。
替换后得到的数字可以包含前导 0 。
Danny Mittal 获得周赛 326 前 10 名，让我们恭喜他。


示例 1：

输入：num = 11891
输出：99009
解释：
为了得到最大值，我们将数字 1 替换成数字 9 ，得到 99899 。
为了得到最小值，我们将数字 1 替换成数字 0 ，得到 890 。
两个数字的差值为 99009 。
示例 2：

输入：num = 90
输出：99
解释：
可以得到的最大值是 99（将 0 替换成 9），最小值是 0（将 9 替换成 0）。
所以我们得到 99 。


提示：

1 <= num <= 108
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        return getMax(s) - getMin(s);
    }

    int getMax(string num) {
        int i = 0, size = num.size();
        char c = 0;

        for (; i < size; ++i) {
            if (num[i] != '9') {
                c = num[i];
                break;
            }
        }

        for (; i < size; ++i) {
            if (num[i] == c) {
                num[i] = '9';
            }
        }

        return stoi(num);
    }

    int getMin(string num) {
        char first = num[0];

        for (char& c : num) {
            if (c == first) {
                c = '0';
            }
        }

        return stoi(num);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(99009, o.minMaxDifference(11891));
    check.checkInt(99, o.minMaxDifference(90));
    check.checkInt(9, o.minMaxDifference(9));
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
