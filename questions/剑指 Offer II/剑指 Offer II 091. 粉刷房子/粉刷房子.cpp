/* 粉刷房子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
假如有一排房子，共 n 个，每个房子可以被粉刷成红色、蓝色或者绿色这三种颜色中的一种，你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。

当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。每个房子粉刷成不同颜色的花费是以一个 n x 3 的正整数矩阵 costs 来表示的。

例如，costs[0][0] 表示第 0 号房子粉刷成红色的成本花费；costs[1][2] 表示第 1 号房子粉刷成绿色的花费，以此类推。

请计算出粉刷完所有房子最少的花费成本。

 

示例 1：

输入: costs = [[17,2,17],[16,16,5],[14,3,19]]
输出: 10
解释: 将 0 号房子粉刷成蓝色，1 号房子粉刷成绿色，2 号房子粉刷成蓝色。
     最少花费: 2 + 5 + 3 = 10。
示例 2：

输入: costs = [[7,6,2]]
输出: 2
 

提示:

costs.length == n
costs[i].length == 3
1 <= n <= 100
1 <= costs[i][j] <= 20
 

注意：本题与主站 256 题相同：https://leetcode-cn.com/problems/paint-house/

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/JEj789
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int minCost0 = 0, minCost1 = 0, minCost2 = 0;

        for (auto& cost : costs) {
            int tmp0 = min(minCost1, minCost2) + cost[0];
            int tmp1 = min(minCost0, minCost2) + cost[1];
            int tmp2 = min(minCost0, minCost1) + cost[2];
            minCost0 = tmp0;
            minCost1 = tmp1;
            minCost2 = tmp2;
        }

        return min({ minCost0, minCost1, minCost2 });
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> costs = { {17,2,17},{16,16,5},{14,3,19} };
    check.checkInt(10, o.minCost(costs));

    costs = { {7,6,2} };
    check.checkInt(2, o.minCost(costs));
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
