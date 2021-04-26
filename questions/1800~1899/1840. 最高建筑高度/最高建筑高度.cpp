/* 最高建筑高度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一座城市里，你需要建 n 栋新的建筑。这些新的建筑会从 1 到 n 编号排成一列。

这座城市对这些新建筑有一些规定：

每栋建筑的高度必须是一个非负整数。
第一栋建筑的高度 必须 是 0 。
任意两栋相邻建筑的高度差 不能超过  1 。
除此以外，某些建筑还有额外的最高高度限制。这些限制会以二维整数数组 restrictions 的形式给出，其中 restrictions[i] = [idi, maxHeighti] ，表示建筑 idi 的高度 不能超过 maxHeighti 。

题目保证每栋建筑在 restrictions 中 至多出现一次 ，同时建筑 1 不会 出现在 restrictions 中。

请你返回 最高 建筑能达到的 最高高度 。

 

示例 1：


输入：n = 5, restrictions = [[2,1],[4,1]]
输出：2
解释：上图中的绿色区域为每栋建筑被允许的最高高度。
我们可以使建筑高度分别为 [0,1,2,1,2] ，最高建筑的高度为 2 。
示例 2：


输入：n = 6, restrictions = []
输出：5
解释：上图中的绿色区域为每栋建筑被允许的最高高度。
我们可以使建筑高度分别为 [0,1,2,3,4,5] ，最高建筑的高度为 5 。
示例 3：


输入：n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
输出：5
解释：上图中的绿色区域为每栋建筑被允许的最高高度。
我们可以使建筑高度分别为 [0,1,2,3,3,4,4,5,4,3] ，最高建筑的高度为 5 。
 

提示：

2 <= n <= 109
0 <= restrictions.length <= min(n - 1, 105)
2 <= idi <= n
idi 是 唯一的 。
0 <= maxHeighti <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-building-height
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] < v2[0];
}

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        int i, size = restrictions.size();
        if (size == 0) {
            return n - 1;
        }

        sort(restrictions.begin(), restrictions.end(), vectorCompare);

        restrictions[0][1] = min(restrictions[0][1], restrictions[0][0] - 1);
        for (i = 1; i < size; ++i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0]);
        }

        for (i = size - 2; i >= 0; --i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]);
        }

        int maxHeight = restrictions[0][1];
        for (i = 1; i < size; ++i) {
            maxHeight = max(maxHeight, (restrictions[i - 1][1] + restrictions[i][1] + restrictions[i][0] - restrictions[i - 1][0]) / 2);
        }

        return max(maxHeight, restrictions[size - 1][1] + n - restrictions[size - 1][0]);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> restrictions = { {2,1},{4,1} };
    check.checkInt(2, o.maxBuilding(5, restrictions));

    restrictions = { };
    check.checkInt(5, o.maxBuilding(6, restrictions));

    restrictions = { {5,3},{2,5},{7,4},{10,3} };
    check.checkInt(5, o.maxBuilding(10, restrictions));

    restrictions = { {8,5},{9,0},{6,2},{4,0},{3,2},{10,0},{5,3},{7,3},{2,4} };
    check.checkInt(2, o.maxBuilding(10, restrictions));
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
