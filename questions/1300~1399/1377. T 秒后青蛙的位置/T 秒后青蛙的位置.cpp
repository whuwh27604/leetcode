/* T 秒后青蛙的位置.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵由 n 个顶点组成的无向树，顶点编号从 1 到 n。青蛙从 顶点 1 开始起跳。规则如下：

在一秒内，青蛙从它所在的当前顶点跳到另一个 未访问 过的顶点（如果它们直接相连）。
青蛙无法跳回已经访问过的顶点。
如果青蛙可以跳到多个不同顶点，那么它跳到其中任意一个顶点上的机率都相同。
如果青蛙不能跳到任何未访问过的顶点上，那么它每次跳跃都会停留在原地。
无向树的边用数组 edges 描述，其中 edges[i] = [fromi, toi] 意味着存在一条直接连通 fromi 和 toi 两个顶点的边。

返回青蛙在 t 秒后位于目标顶点 target 上的概率。

 

示例 1：



输入：n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target = 4
输出：0.16666666666666666
解释：上图显示了青蛙的跳跃路径。青蛙从顶点 1 起跳，第 1 秒 有 1/3 的概率跳到顶点 2 ，然后第 2 秒 有 1/2 的概率跳到顶点 4，因此青蛙在 2 秒后位于顶点 4 的概率是 1/3 * 1/2 = 1/6 = 0.16666666666666666 。
示例 2：



输入：n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target = 7
输出：0.3333333333333333
解释：上图显示了青蛙的跳跃路径。青蛙从顶点 1 起跳，有 1/3 = 0.3333333333333333 的概率能够 1 秒 后跳到顶点 7 。
 

 

提示：

1 <= n <= 100
edges.length == n - 1
edges[i].length == 2
1 <= ai, bi <= n
1 <= t <= 50
1 <= target <= n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/frog-position-after-t-seconds
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if (target == 1) {
            return n == 1 ? 1 : 0;  // 除非只有一个节点，否则青蛙跳走了再也不回来了
        }

        vector<vector<int>> adjs(n + 1);
        vector<int> path;

        getAdjs(edges, adjs);
        (void)getPath(1, 0, target, adjs, path);

        return getProbability(adjs, path, t, target);
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    bool getPath(int node, int parent, int target, vector<vector<int>>& adjs, vector<int>& path) {
        if (node == target) {
            return true;
        }

        path.push_back(node);

        for (int next : adjs[node]) {
            if (next != parent && getPath(next, node, target, adjs, path)) {
                return true;
            }
        }

        path.pop_back();

        return false;
    }

    double getProbability(vector<vector<int>>& adjs, vector<int>& path, int t, int target) {
        int size = path.size();

        if ((t < size) || (t > size && adjs[target].size() > 1)) {  // 时间不够，不能到达target；或者时间有多的并且target还有下一跳，那么青蛙跳走了
            return 0;
        }

        double probability = 1.0 / adjs[1].size();

        for (int i = 1; i < size; ++i) {
            probability /= (adjs[path[i]].size() - 1);
        }

        return probability;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {1,2},{1,3},{1,7},{2,4},{2,6},{3,5} };
    check.checkDouble(0.16666666666666666, o.frogPosition(7, edges, 2, 4));

    edges = { {1,2},{1,3},{1,7},{2,4},{2,6},{3,5} };
    check.checkDouble(0.3333333333333333, o.frogPosition(7, edges, 1, 7));

    edges = { {2,1},{3,2} };
    check.checkDouble(1.0, o.frogPosition(3, edges, 1, 2));

    edges = { {2,1},{3,2},{4,2},{5,2},{6,5},{7,1},{8,3},{9,1},{10,1} };
    check.checkDouble(0.25, o.frogPosition(10, edges, 1, 9));

    edges = { {2,1},{3,2},{4,1},{5,1},{6,4},{7,1},{8,7} };
    check.checkDouble(0, o.frogPosition(8, edges, 7, 7));

    edges = {  };
    check.checkDouble(1, o.frogPosition(1, edges, 7, 1));

    edges = { {1,2},{1,3},{1,7},{2,4},{2,6},{3,5} };
    check.checkDouble(0.166667, o.frogPosition(7, edges, 20, 6));
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
