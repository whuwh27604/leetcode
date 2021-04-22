/* 非重叠矩形中的随机点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非重叠轴对齐矩形的列表 rects，写一个函数 pick 随机均匀地选取矩形覆盖的空间中的整数点。

提示：

整数点是具有整数坐标的点。
矩形周边上的点包含在矩形覆盖的空间中。
第 i 个矩形 rects [i] = [x1，y1，x2，y2]，其中 [x1，y1] 是左下角的整数坐标，[x2，y2] 是右上角的整数坐标。
每个矩形的长度和宽度不超过 2000。
1 <= rects.length <= 100
pick 以整数坐标数组 [p_x, p_y] 的形式返回一个点。
pick 最多被调用10000次。
 

示例 1：

输入:
["Solution","pick","pick","pick"]
[[[[1,1,5,5]]],[],[],[]]
输出:
[null,[4,1],[4,1],[3,3]]
示例 2：

输入:
["Solution","pick","pick","pick","pick","pick"]
[[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
输出:
[null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]
 

输入语法的说明：

输入是两个列表：调用的子例程及其参数。Solution 的构造函数有一个参数，即矩形数组 rects。pick 没有参数。参数总是用列表包装的，即使没有也是如此。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/random-point-in-non-overlapping-rectangles
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <random>
#include <unordered_map>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        int start = 0;

        for (auto& rect : rects) {
            startRects[start] = rect;
            start += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
        }

        size = totalStart = start;
    }

    vector<int> pick() {
        if (size == 0) {  // 所有点都被选过一次了
            reset();
        }

        int rnum = rd() % size--;

        // 随机选择一个位置，如果这个位置还没有被挑选过，那么挑选它；如果已经被挑选了，那么挑选它映射的位置
        int pos = picked.count(rnum) == 0 ? rnum : picked[rnum];

        // 将选中的这个位置映射到最后一个位置，如果最后一个位置已经挑选了，那么映射到它挑选时映射的位置
        picked[rnum] = picked.count(size) == 0 ? size : picked[size];

        return getPoint(pos);
    }

    vector<int> getPoint(int pos) {
        auto iter = startRects.upper_bound(pos);
        --iter;
        pos -= iter->first;
        auto& rect = iter->second;
        int column = rect[3] - rect[1] + 1;
        return { rect[0] + pos / column , rect[1] + pos % column };
    }

    void reset() {
        picked.clear();
        size = totalStart;
    }

private:
    random_device rd;
    unordered_map<int, int> picked;
    map<int, vector<int>> startRects;
    int size;
    int totalStart;
};

int main()
{
    CheckResult check;

    vector<vector<int>> rects = { {1,1,5,5} };
    Solution o1(rects);
    vector<vector<int>> actual;
    for (int i = 0; i < 25; ++i) {
        actual.push_back(o1.pick());
    }
    vector<vector<int>> expected = { {1,1},{2,1},{3,1},{4,1},{5,1},{1,2},{2,2},{3,2},{4,2},{5,2},{1,3},{2,3},{3,3},{4,3},{5,3},{1,4},{2,4},{3,4},{4,4},{5,4},{1,5},{2,5},{3,5},{4,5},{5,5} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    rects = { {1,1,2,2} };
    Solution o2(rects);
    actual.clear();
    for (int i = 0; i < 8; ++i) {
        actual.push_back(o2.pick());
    }
    expected = { {1,1},{2,1},{1,2},{2,2},{1,1},{2,1},{1,2},{2,2} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    rects = { {-2,-2,-1,-1},{1,0,3,0} };
    Solution o3(rects);
    actual.clear();
    for (int i = 0; i < 7; ++i) {
        actual.push_back(o3.pick());
    }
    expected = { {-2,-2},{-2,-1},{-1,-2},{-1,-1},{1,0},{2,0},{3,0} };
    check.checkIntVectorRandomOrderVector(expected, actual);
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
