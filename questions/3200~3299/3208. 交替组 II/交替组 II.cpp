/* 交替组 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 colors 和一个整数 k ，colors表示一个由红色和蓝色瓷砖组成的环，第 i 块瓷砖的颜色为 colors[i] ：

colors[i] == 0 表示第 i 块瓷砖的颜色是 红色 。
colors[i] == 1 表示第 i 块瓷砖的颜色是 蓝色 。
环中连续 k 块瓷砖的颜色如果是 交替 颜色（也就是说除了第一块和最后一块瓷砖以外，中间瓷砖的颜色与它 左边 和 右边 的颜色都不同），那么它被称为一个 交替 组。

请你返回 交替 组的数目。

注意 ，由于 colors 表示一个 环 ，第一块 瓷砖和 最后一块 瓷砖是相邻的。



示例 1：

输入：colors = [0,1,0,1,0], k = 3

输出：3

解释：



交替组包括：



示例 2：

输入：colors = [0,1,0,0,1,0,1], k = 6

输出：2

解释：



交替组包括：



示例 3：

输入：colors = [1,1,0,1], k = 4

输出：0

解释：





提示：

3 <= colors.length <= 105
0 <= colors[i] <= 1
3 <= k <= colors.length
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int size = (int)colors.size(), len = 1, count = 0;

        for (int i = 1; i < size + k - 1; ++i) {
            if (colors[i % size] != colors[(i - 1) % size]) {
                if (++len >= k) {
                    ++count;
                }
            }
            else {
                len = 1;
            }
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> colors = { 0,1,0,1,0 };
    check.checkInt(3, o.numberOfAlternatingGroups(colors, 3));

    colors = { 0,1,0,0,1,0,1 };
    check.checkInt(2, o.numberOfAlternatingGroups(colors, 6));

    colors = { 1,1,0,1 };
    check.checkInt(0, o.numberOfAlternatingGroups(colors, 4));

    colors = { 1,0,1,0,1,0 };
    check.checkInt(6, o.numberOfAlternatingGroups(colors, 3));
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
