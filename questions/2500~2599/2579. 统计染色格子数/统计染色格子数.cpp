/* 统计染色格子数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个无穷大的二维网格图，一开始所有格子都未染色。给你一个正整数 n ，表示你需要执行以下步骤 n 分钟：

第一分钟，将 任一 格子染成蓝色。
之后的每一分钟，将与蓝色格子相邻的 所有 未染色格子染成蓝色。
下图分别是 1、2、3 分钟后的网格图。


请你返回 n 分钟之后 被染色的格子 数目。



示例 1：

输入：n = 1
输出：1
解释：1 分钟后，只有 1 个蓝色的格子，所以返回 1 。
示例 2：

输入：n = 2
输出：5
解释：2 分钟后，有 4 个在边缘的蓝色格子和 1 个在中间的蓝色格子，所以返回 5 。


提示：

1 <= n <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        return n * ((long long)n - 1) * 2 + 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkLongLong(1, o.coloredCells(1));
    check.checkLongLong(5, o.coloredCells(2));
    check.checkLongLong(13, o.coloredCells(3));
    check.checkLongLong(25, o.coloredCells(4));
    check.checkLongLong(19999800001, o.coloredCells(100000));
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
