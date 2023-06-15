/* 判断一个数是否迷人.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个三位数整数 n 。

如果经过以下修改得到的数字 恰好 包含数字 1 到 9 各一次且不包含任何 0 ，那么我们称数字 n 是 迷人的 ：

将 n 与数字 2 * n 和 3 * n 连接 。
如果 n 是迷人的，返回 true，否则返回 false 。

连接 两个数字表示把它们首尾相接连在一起。比方说 121 和 371 连接得到 121371 。



示例 1：

输入：n = 192
输出：true
解释：我们将数字 n = 192 ，2 * n = 384 和 3 * n = 576 连接，得到 192384576 。这个数字包含 1 到 9 恰好各一次。
示例 2：

输入：n = 100
输出：false
解释：我们将数字 n = 100 ，2 * n = 200 和 3 * n = 300 连接，得到 100200300 。这个数字不符合上述条件。


提示：

100 <= n <= 999
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isFascinating(int n) {
        vector<bool> exist(10, false);

        if (!toDigit(n, exist) || !toDigit(n * 2, exist) || !toDigit(n * 3, exist)) {
            return false;
        }

        for (int i = 1; i < 10; ++i) {
            if (!exist[i]) {
                return false;
            }
        }

        return true;
    }

    bool toDigit(int n, vector<bool>& exist) {
        while (n != 0) {
            int digit = n % 10;
            n /= 10;

            if (exist[digit]) {
                return false;
            }

            exist[digit] = true;
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.isFascinating(192));
    check.checkBool(false, o.isFascinating(100));
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
