/* 砖墙.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你的面前有一堵矩形的、由多行砖块组成的砖墙。 这些砖块高度相同但是宽度不同。你现在要画一条自顶向下的、穿过最少砖块的垂线。

砖墙由行的列表表示。 每一行都是一个代表从左至右每块砖的宽度的整数列表。

如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。你需要找出怎样画才能使这条线穿过的砖块数量最少，并且返回穿过的砖块数量。

你不能沿着墙的两个垂直边缘之一画线，这样显然是没有穿过一块砖的。

 

示例：

输入: [[1,2,2,1],
      [3,1,2],
      [1,3,2],
      [2,4],
      [3,1,2],
      [1,3,1,1]]

输出: 2

解释:

 

提示：

每一行砖块的宽度之和应该相等，并且不能超过 INT_MAX。
每一行砖块的数量在 [1,10,000] 范围内， 墙的高度在 [1,10,000] 范围内， 总的砖块数量不超过 20,000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/brick-wall
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> gapCount;
        int i, j, row = wall.size(), maxGapCount = 0;

        for (i = 0; i < row; i++) {
            int gapPosition = 0;
            int column = wall[i].size();
            for (j = 0; j < column - 1; j++) {
                gapPosition += wall[i][j];
                auto iter = gapCount.find(gapPosition);
                if (iter == gapCount.end()) {
                    gapCount[gapPosition] = 1;
                }
                else {
                    iter->second++;
                }

                maxGapCount = max(maxGapCount, gapCount[gapPosition]);
            }
        }

        return wall.size() - maxGapCount;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> wall = { {1,2,2,1},{3,1,2},{1,3,2},{2,4},{3,1,2},{1,3,1,1} };
    check.checkInt(2, o.leastBricks(wall));

    wall = { {1},{1},{1} };
    check.checkInt(3, o.leastBricks(wall));

    wall = { {1} };
    check.checkInt(1, o.leastBricks(wall));

    wall = { {1,2} };
    check.checkInt(0, o.leastBricks(wall));
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
