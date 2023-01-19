/* 堆箱子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
堆箱子。给你一堆n个箱子，箱子宽 wi、深 di、高 hi。箱子不能翻转，将箱子堆起来时，下面箱子的宽度、高度和深度必须大于上面的箱子。实现一种方法，搭出最高的一堆箱子。箱堆的高度为每个箱子高度的总和。

输入使用数组[wi, di, hi]表示每个箱子。

示例1:

 输入：box = [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
 输出：6
示例2:

 输入：box = [[1, 1, 1], [2, 3, 4], [2, 6, 7], [3, 4, 5]]
 输出：10
提示:

箱子的数目不大于3000个。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Box {
public:
    int w;
    int d;
    int h;

    Box(int wi, int di, int hi) : w(wi), d(di), h(hi) {}

    bool operator<(const Box& o) const {
        if (w != o.w) {
            return w < o.w;
        }

        if (d != o.d) {
            return d < o.d;
        }

        return h < o.h;
    }
};

class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        int size = box.size();
        if (size == 0) {
            return 0;
        }

        vector<Box> boxes;

        for (auto& b : box) {
            boxes.push_back(Box(b[0], b[1], b[2]));
        }

        sort(boxes.begin(), boxes.end());
        vector<int> dp(size);
        dp[0] = boxes[0].h;

        for (int i = 1; i < size; ++i) {
            dp[i] = boxes[i].h;

            for (int j = 0; j < i; ++j) {
                if (boxes[j].w < boxes[i].w && boxes[j].d < boxes[i].d && boxes[j].h < boxes[i].h) {
                    dp[i] = max(dp[i], dp[j] + boxes[i].h);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> box = { {1,1,1},{2,2,2},{3,3,3} };
    check.checkInt(6, o.pileBox(box));

    box = { {1,1,1},{2,3,4},{2,6,7},{3,4,5} };
    check.checkInt(10, o.pileBox(box));

    box = {};
    check.checkInt(0, o.pileBox(box));
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
