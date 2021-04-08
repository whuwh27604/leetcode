﻿/* 可以形成最大正方形的矩形数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 rectangles ，其中 rectangles[i] = [li, wi] 表示第 i 个矩形的长度为 li 、宽度为 wi 。

如果存在 k 同时满足 k <= li 和 k <= wi ，就可以将第 i 个矩形切成边长为 k 的正方形。例如，矩形 [4,6] 可以切成边长最大为 4 的正方形。

设 maxLen 为可以从矩形数组 rectangles 切分得到的 最大正方形 的边长。

返回可以切出边长为 maxLen 的正方形的矩形 数目 。

 

示例 1：

输入：rectangles = [[5,8],[3,9],[5,12],[16,5]]
输出：3
解释：能从每个矩形中切出的最大正方形边长分别是 [5,3,5,5] 。
最大正方形的边长为 5 ，可以由 3 个矩形切分得到。
示例 2：

输入：rectangles = [[2,3],[3,7],[4,3],[3,7]]
输出：3
 

提示：

1 <= rectangles.length <= 1000
rectangles[i].length == 2
1 <= li, wi <= 109
li != wi

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-rectangles-that-can-form-the-largest-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = 0, count = 0;

        for (auto& rectangle : rectangles) {
            int len = min(rectangle[0], rectangle[1]);

            if (len > maxLen) {
                maxLen = len;
                count = 1;
            }
            else if (len == maxLen) {
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

    vector<vector<int>> rectangles = { {5,8},{3,9},{5,12},{16,5} };
    check.checkInt(3, o.countGoodRectangles(rectangles));

    rectangles = { {2,3},{3,7},{4,3},{3,7} };
    check.checkInt(3, o.countGoodRectangles(rectangles));

    rectangles = { {3,3} };
    check.checkInt(1, o.countGoodRectangles(rectangles));
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
