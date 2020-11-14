/* 冗余连接.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在本问题中, 树指的是一个连通且无环的无向图。

输入一个图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组。每一个边的元素是一对[u, v] ，满足 u < v，表示连接顶点u 和v的无向图的边。

返回一条可以删去的边，使得结果图是一个有着N个节点的树。如果有多个答案，则返回二维数组中最后出现的边。答案边 [u, v] 应满足相同的格式 u < v。

示例 1：

输入: [[1,2], [1,3], [2,3]]
输出: [2,3]
解释: 给定的无向图为:
  1
 / \
2 - 3
示例 2：

输入: [[1,2], [2,3], [3,4], [1,4], [1,5]]
输出: [1,4]
解释: 给定的无向图为:
5 - 1 - 2
    |   |
    4 - 3
注意:

输入的二维数组大小在 3 到 1000。
二维数组中的整数在1到N之间，其中N是输入数组的大小。
更新(2017-09-26):
我们已经重新检查了问题描述及测试用例，明确图是无向 图。对于有向图详见冗余连接II。对于造成任何不便，我们深感歉意。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/redundant-connection
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parents(edges.size() + 1, 0);
        init(parents);

        for (vector<int>& edge : edges) {
            if (!unionSet(edge, parents)) {
                return edge;
            }
        }

        return {};  // 一定有解，不会走到这里
    }

    void init(vector<int>& parents) {
        for (int i = 0; i < (int)parents.size(); ++i) {
            parents[i] = i;  // 初始化每个点的parent为自己
        }
    }

    int findParent(int x, vector<int>& parents) {
        if (x != parents[x]) {
            parents[x] = findParent(parents[x], parents);  // 找到最新的parent之后注意要更新之
        }

        return parents[x];
    }

    bool unionSet(vector<int>& edge, vector<int>& parents) {
        int x = edge[0], y = edge[1];
        int parentX = findParent(x, parents), parentY = findParent(y, parents);  // 更新节点parent到当前最新
        if (parentX == parentY) {
            return false;  // parent相同说明已经连通了，此次edge再加进来就会形成环路
        }

        parents[parentX] = parentY;  // 两个不同的集合，合并它们
        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> edges = { {1,2},{1,3},{2,3} };
    vector<int> actual = o.findRedundantConnection(edges);
    vector<int> expected = { 2,3 };
    check.checkIntVector(expected, actual);

    edges = { {2,3},{1,3},{1,2} };
    actual = o.findRedundantConnection(edges);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    edges = { {1,2},{1,3},{1,3} };
    actual = o.findRedundantConnection(edges);
    expected = { 1,3 };
    check.checkIntVector(expected, actual);

    edges = { {1,2},{2,3},{3,4},{1,4},{1,5} };
    actual = o.findRedundantConnection(edges);
    expected = { 1,4 };
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
