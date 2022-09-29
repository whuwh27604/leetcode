/* 网页瀑布流.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
网页布局中有一种瀑布流布局方式，表现为参差不齐的多栏布局。随着页面滚动条向下，还会不断加载数据块并附加至当前尾部。页面在加载时遵循以下规则：

当有数据块需要加载时，优先加载在高度最短的那一列；
若存在多个高度相同且最短的情况，则加载在其中最靠左的那一列
已知当前网页共分割为 num 列，该网页有若干数据块可以加载，block[i] 表示第 i 个数据块的高度。当页面按顺序加载完所有的数据块后，请返回高度最大的那一列的高度。

示例 1：

输入：num = 3, block = [5,9,8,6]

输出：11

解释：如下图所示，返回 11
image.png

示例 2：

输入：num = 2, block = [9,1,1,1,1,1]

输出：9

提示：

0 < num <= 100
0 < block.length <= 10^4
0 < block[i] <= 10^3
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getLengthOfWaterfallFlow(int num, vector<int>& block) {
        map<int, int> heights = { {0,num} };

        for (int height : block) {
            int minHeight = heights.begin()->first;

            if (--heights.begin()->second == 0) {
                heights.erase(heights.begin());
            }

            ++heights[minHeight + height];
        }

        return heights.rbegin()->first;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> block = { 5,9,8,6 };
    check.checkInt(11, o.getLengthOfWaterfallFlow(3, block));

    block = { 9,1,1,1,1,1 };
    check.checkInt(9, o.getLengthOfWaterfallFlow(2, block));
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
