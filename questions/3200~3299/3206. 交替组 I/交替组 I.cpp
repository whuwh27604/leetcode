/* 交替组 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 colors ，它表示一个由红色和蓝色瓷砖组成的环，第 i 块瓷砖的颜色为 colors[i] ：

colors[i] == 0 表示第 i 块瓷砖的颜色是 红色 。
colors[i] == 1 表示第 i 块瓷砖的颜色是 蓝色 。
环中连续 3 块瓷砖的颜色如果是 交替 颜色（也就是说中间瓷砖的颜色与它 左边 和 右边 的颜色都不同），那么它被称为一个 交替 组。

请你返回 交替 组的数目。

注意 ，由于 colors 表示一个 环 ，第一块 瓷砖和 最后一块 瓷砖是相邻的。



示例 1：

输入：colors = [1,1,1]

输出：0

解释：



示例 2：

输入：colors = [0,1,0,0,1]

输出：3

解释：



交替组包括：





提示：

3 <= colors.length <= 100
0 <= colors[i] <= 1
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int size = (int)colors.size(), count = 0;

        if (colors[0] != colors[1] && colors[0] != colors[size - 1]) {
            ++count;
        }

        if (colors[size - 1] != colors[size - 2] && colors[size - 1] != colors[0]) {
            ++count;
        }

        for (int i = 1; i < size - 1; ++i) {
            if (colors[i] != colors[i - 1] && colors[i] != colors[i + 1]) {
                ++count;
            }
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> colors = { 1,1,1 };
    check.checkInt(0, o.numberOfAlternatingGroups(colors));

    colors = { 0,1,0,0,1 };
    check.checkInt(3, o.numberOfAlternatingGroups(colors));
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
