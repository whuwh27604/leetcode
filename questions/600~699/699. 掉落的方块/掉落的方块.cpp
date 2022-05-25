/* 掉落的方块.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在无限长的数轴（即 x 轴）上，我们根据给定的顺序放置对应的正方形方块。

第 i 个掉落的方块（positions[i] = (left, side_length)）是正方形，其中 left 表示该方块最左边的点位置(positions[i][0])，side_length 表示该方块的边长(positions[i][1])。

每个方块的底部边缘平行于数轴（即 x 轴），并且从一个比目前所有的落地方块更高的高度掉落而下。在上一个方块结束掉落，并保持静止后，才开始掉落新方块。

方块的底边具有非常大的粘性，并将保持固定在它们所接触的任何长度表面上（无论是数轴还是其他方块）。邻接掉落的边不会过早地粘合在一起，因为只有底边才具有粘性。

 

返回一个堆叠高度列表 ans 。每一个堆叠高度 ans[i] 表示在通过 positions[0], positions[1], ..., positions[i] 表示的方块掉落结束后，目前所有已经落稳的方块堆叠的最高高度。

 

 

示例 1:

输入: [[1, 2], [2, 3], [6, 1]]
输出: [2, 5, 5]
解释:

第一个方块 positions[0] = [1, 2] 掉落：
_aa
_aa
-------
方块最大高度为 2 。

第二个方块 positions[1] = [2, 3] 掉落：
__aaa
__aaa
__aaa
_aa__
_aa__
--------------
方块最大高度为5。
大的方块保持在较小的方块的顶部，不论它的重心在哪里，因为方块的底部边缘有非常大的粘性。

第三个方块 positions[1] = [6, 1] 掉落：
__aaa
__aaa
__aaa
_aa
_aa___a
--------------
方块最大高度为5。

因此，我们返回结果[2, 5, 5]。
 

示例 2:

输入: [[100, 100], [200, 100]]
输出: [100, 100]
解释: 相邻的方块不会过早地卡住，只有它们的底部边缘才能粘在表面上。
 

注意:

1 <= positions.length <= 1000.
1 <= positions[i][0] <= 10^8.
1 <= positions[i][1] <= 10^6.

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/falling-squares
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Section {
public:
    int left;
    int right;
    int height;

    Section(int left_, int right_, int height_) : left(left_), right(right_), height(height_) {}

    bool isOverlap(int start, int end) {
        return (start >= left && start <= right) || (end >= left && end <= right) || (start < left && end > right);
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int i, size = positions.size(), maxHeight = 0;
        vector<Section> sections;
        vector<int> ans(size);

        for (i = 0; i < size; ++i) {
            int side = positions[i][1], height = side, start = positions[i][0], end = start + height - 1;

            for (Section& section : sections) {
                if (section.isOverlap(start, end)) {
                    height = max(height, section.height + side);
                }
            }

            sections.push_back(Section(start, end, height));
            maxHeight = max(maxHeight, height);
            ans[i] = maxHeight;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> positions = { {1,2},{2,3},{6,1} };
    vector<int> actual = o.fallingSquares(positions);
    vector<int> expected = { 2,5,5 };
    check.checkIntVector(expected, actual);

    positions = { {100,100},{200,100} };
    actual = o.fallingSquares(positions);
    expected = { 100,100 };
    check.checkIntVector(expected, actual);

    positions = { {9,1},{6,5},{6,7} };
    actual = o.fallingSquares(positions);
    expected = { 1,6,13 };
    check.checkIntVector(expected, actual);
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
