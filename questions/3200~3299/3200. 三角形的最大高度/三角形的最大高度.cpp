/* 三角形的最大高度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数 red 和 blue，分别表示红色球和蓝色球的数量。你需要使用这些球来组成一个三角形，满足第 1 行有 1 个球，第 2 行有 2 个球，第 3 行有 3 个球，依此类推。

每一行的球必须是 相同 颜色，且相邻行的颜色必须 不同。

返回可以实现的三角形的 最大 高度。



示例 1：

输入： red = 2, blue = 4

输出： 3

解释：



上图显示了唯一可能的排列方式。

示例 2：

输入： red = 2, blue = 1

输出： 2

解释：


上图显示了唯一可能的排列方式。

示例 3：

输入： red = 1, blue = 1

输出： 1

示例 4：

输入： red = 10, blue = 1

输出： 2

解释：


上图显示了唯一可能的排列方式。



提示：

1 <= red, blue <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(getHeight(red, blue), getHeight(blue, red));
    }

    int getHeight(int red, int blue) {
        int height = 1, which = 0;
        bool inc = true;

        while (inc) {
            inc = false;

            if (which == 0 && red >= height) {
                red -= height++;
                inc = true;
            }
            else if (which == 1 && blue >= height) {
                blue -= height++;
                inc = true;
            }

            which ^= 1;
        }

        return height - 1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(3, o.maxHeightOfTriangle(2, 4));
    check.checkInt(2, o.maxHeightOfTriangle(2, 1));
    check.checkInt(1, o.maxHeightOfTriangle(1, 1));
    check.checkInt(2, o.maxHeightOfTriangle(10, 1));
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
