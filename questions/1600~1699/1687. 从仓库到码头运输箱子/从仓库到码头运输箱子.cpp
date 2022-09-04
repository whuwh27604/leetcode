﻿/* 从仓库到码头运输箱子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有一辆货运卡车，你需要用这一辆车把一些箱子从仓库运送到码头。这辆卡车每次运输有 箱子数目的限制 和 总重量的限制 。

给你一个箱子数组 boxes 和三个整数 portsCount, maxBoxes 和 maxWeight ，其中 boxes[i] = [ports​​i​, weighti] 。

ports​​i 表示第 i 个箱子需要送达的码头， weightsi 是第 i 个箱子的重量。
portsCount 是码头的数目。
maxBoxes 和 maxWeight 分别是卡车每趟运输箱子数目和重量的限制。
箱子需要按照 数组顺序 运输，同时每次运输需要遵循以下步骤：

卡车从 boxes 队列中按顺序取出若干个箱子，但不能违反 maxBoxes 和 maxWeight 限制。
对于在卡车上的箱子，我们需要 按顺序 处理它们，卡车会通过 一趟行程 将最前面的箱子送到目的地码头并卸货。如果卡车已经在对应的码头，那么不需要 额外行程 ，箱子也会立马被卸货。
卡车上所有箱子都被卸货后，卡车需要 一趟行程 回到仓库，从箱子队列里再取出一些箱子。
卡车在将所有箱子运输并卸货后，最后必须回到仓库。

请你返回将所有箱子送到相应码头的 最少行程 次数。

 

示例 1：

输入：boxes = [[1,1],[2,1],[1,1]], portsCount = 2, maxBoxes = 3, maxWeight = 3
输出：4
解释：最优策略如下：
- 卡车将所有箱子装上车，到达码头 1 ，然后去码头 2 ，然后再回到码头 1 ，最后回到仓库，总共需要 4 趟行程。
所以总行程数为 4 。
注意到第一个和第三个箱子不能同时被卸货，因为箱子需要按顺序处理（也就是第二个箱子需要先被送到码头 2 ，然后才能处理第三个箱子）。
示例 2：

输入：boxes = [[1,2],[3,3],[3,1],[3,1],[2,4]], portsCount = 3, maxBoxes = 3, maxWeight = 6
输出：6
解释：最优策略如下：
- 卡车首先运输第一个箱子，到达码头 1 ，然后回到仓库，总共 2 趟行程。
- 卡车运输第二、第三、第四个箱子，到达码头 3 ，然后回到仓库，总共 2 趟行程。
- 卡车运输第五个箱子，到达码头 3 ，回到仓库，总共 2 趟行程。
总行程数为 2 + 2 + 2 = 6 。
示例 3：

输入：boxes = [[1,4],[1,2],[2,1],[2,1],[3,2],[3,4]], portsCount = 3, maxBoxes = 6, maxWeight = 7
输出：6
解释：最优策略如下：
- 卡车运输第一和第二个箱子，到达码头 1 ，然后回到仓库，总共 2 趟行程。
- 卡车运输第三和第四个箱子，到达码头 2 ，然后回到仓库，总共 2 趟行程。
- 卡车运输第五和第六个箱子，到达码头 3 ，然后回到仓库，总共 2 趟行程。
总行程数为 2 + 2 + 2 = 6 。
示例 4：

输入：boxes = [[2,4],[2,5],[3,1],[3,2],[3,7],[3,1],[4,4],[1,3],[5,2]], portsCount = 5, maxBoxes = 5, maxWeight = 7
输出：14
解释：最优策略如下：
- 卡车运输第一个箱子，到达码头 2 ，然后回到仓库，总共 2 趟行程。
- 卡车运输第二个箱子，到达码头 2 ，然后回到仓库，总共 2 趟行程。
- 卡车运输第三和第四个箱子，到达码头 3 ，然后回到仓库，总共 2 趟行程。
- 卡车运输第五个箱子，到达码头 3 ，然后回到仓库，总共 2 趟行程。
- 卡车运输第六和第七个箱子，到达码头 3 ，然后去码头 4 ，然后回到仓库，总共 3 趟行程。
- 卡车运输第八和第九个箱子，到达码头 1 ，然后去码头 5 ，然后回到仓库，总共 3 趟行程。
总行程数为 2 + 2 + 2 + 2 + 3 + 3 = 14 。
 

提示：

1 <= boxes.length <= 105
1 <= portsCount, maxBoxes, maxWeight <= 105
1 <= ports​​i <= portsCount
1 <= weightsi <= maxWeight

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/delivering-boxes-from-storage-to-ports
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int size = boxes.size();
        vector<int> tripPresums(size + 1, 0);
        vector<long long> weightPresums(size + 1, 0);

        getPresums(size, boxes, tripPresums, weightPresums);

        return getMinTrips(tripPresums, weightPresums, size, maxBoxes, maxWeight);
    }

    void getPresums(int size, vector<vector<int>>& boxes, vector<int>& tripPresums, vector<long long>& weightPresums) {
        weightPresums[1] = boxes[0][1];

        for (int i = 1; i < size; ++i) {
            tripPresums[i + 1] = tripPresums[i] + (boxes[i][0] == boxes[i - 1][0] ? 0 : 1);
            weightPresums[i + 1] = weightPresums[i] + boxes[i][1];
        }
    }

    /* minTrips[i] = min(minTrips[j] + trips[j + 1, i] + 2), where [j + 1, i] is valid ONE ship, means (i - j <= maxBoxes) && (weightPresums[i] - weightPresums[j] <= maxWeight)
       trips[j + 1, i] = tripPresums[i] - tripPresums[j + 1]
       minTrips[i] = min(minTrips[j] + tripPresums[i] - tripPresums[j + 1] + 2) = min(minTrips[j] - tripPresums[j + 1]) + tripPresums[i] + 2 */
    int getMinTrips(vector<int>& tripPresums, vector<long long>& weightPresums, int size, int maxBoxes, int maxWeight) {
        deque<int> validJs = { 0 };  // 合法的[j, i]具有单调性，用一个单调队列来保存
        vector<int> minTrips(size + 1, 0), minJs(size + 1, 0);  // minTrips[i]表示[0, i]的最小trips数；minJs[j]表示合法[j + 1, i]里面最小的minTrips[j] - tripPresums[j + 1]

        for (int i = 1; i <= size; ++i) {
            while (!validJs.empty() && (i - validJs.front() > maxBoxes || weightPresums[i] - weightPresums[validJs.front()] > maxWeight)) {
                validJs.pop_front();  // 移除不合法的j
            }

            minTrips[i] = minJs[validJs.front()] + tripPresums[i] + 2;

            if (i != size) {
                minJs[i] = minTrips[i] - tripPresums[i + 1];

                while (!validJs.empty() && minJs[i] <= minJs[validJs.back()]) {
                    validJs.pop_back();  // 移除较大的minJs，保证其单调性，这样队列头部就是最小的合法的minJs
                }

                validJs.push_back(i);
            }
        }

        return minTrips[size];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> boxes = { {1,1},{2,1},{1,1} };
    check.checkInt(4, o.boxDelivering(boxes, 2, 3, 3));

    boxes = { {1,2},{3,3},{3,1},{3,1},{2,4} };
    check.checkInt(6, o.boxDelivering(boxes, 3, 3, 6));

    boxes = { {1,4},{1,2},{2,1},{2,1},{3,2},{3,4} };
    check.checkInt(6, o.boxDelivering(boxes, 3, 6, 7));

    boxes = { {2,4},{2,5},{3,1},{3,2},{3,7},{3,1},{4,4},{1,3},{5,2} };
    check.checkInt(14, o.boxDelivering(boxes, 5, 5, 7));
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
