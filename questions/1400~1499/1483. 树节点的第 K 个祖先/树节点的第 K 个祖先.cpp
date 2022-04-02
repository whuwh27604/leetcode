/* 树节点的第 K 个祖先.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵树，树上有 n 个节点，按从 0 到 n-1 编号。树以父节点数组的形式给出，其中 parent[i] 是节点 i 的父节点。树的根节点是编号为 0 的节点。

树节点的第 k 个祖先节点是从该节点到根节点路径上的第 k 个节点。

实现 TreeAncestor 类：

TreeAncestor（int n， int[] parent） 对树和父数组中的节点数初始化对象。
getKthAncestor(int node, int k) 返回节点 node 的第 k 个祖先节点。如果不存在这样的祖先节点，返回 -1 。
 

示例 1：



输入：
["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
[[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]

输出：
[null,1,0,-1]

解释：
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);

treeAncestor.getKthAncestor(3, 1);  // 返回 1 ，它是 3 的父节点
treeAncestor.getKthAncestor(5, 2);  // 返回 0 ，它是 5 的祖父节点
treeAncestor.getKthAncestor(6, 3);  // 返回 -1 因为不存在满足要求的祖先节点
 

提示：

1 <= k <= n <= 5 * 104
parent[0] == -1 表示编号为 0 的节点是根节点。
对于所有的 0 < i < n ，0 <= parent[i] < n 总成立
0 <= node < n
至多查询 5 * 104 次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-ancestor-of-a-tree-node
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        index = 0;
        indices.resize(n);
        nodeLayers.resize(n);
        children.resize(n);
        getChildren(n, parent);
        DLR(0, 0);
    }

    int getKthAncestor(int node, int k) {
        int layer = nodeLayers[node];

        if (layer < k) {
            return -1;
        }

        auto& target = layerNodes[layer - k];  // 祖先所在的layer
        int left = 0, right = target.size() - 1, ancestor = -1;

        while (left <= right) {  // 二分查找
            int middle = (left + right) / 2;

            if (indices[target[middle]] < indices[node]) {  // middle节点在node前面，是一个候选答案，在前面并挨着node最近的一个是最终答案
                ancestor = target[middle];
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }

        return ancestor;
    }

    void getChildren(int n, vector<int>& parent) {
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }
    }

    void DLR(int root, int layer) {  // 先序DFS，这样每一个节点的祖先一定在它前面访问到
        indices[root] = index++;  // 按访问顺序分配index
        nodeLayers[root] = layer;  // 记录该节点所在的layer
        
        if (layerNodes.size() == layer) {  // 记录该layer的所有节点
            layerNodes.push_back({ root });
        }
        else {
            layerNodes[layer].push_back(root);
        }

        for (int child : children[root]) {
            DLR(child, layer + 1);
        }
    }

private:
    int index;
    vector<int> indices;
    vector<int> nodeLayers;
    vector<vector<int>> children;
    vector<vector<int>> layerNodes;
};

int main()
{
    CheckResult check;

    vector<int> parent = { -1,0,0,1,1,2,2 };
    TreeAncestor o1(7, parent);
    check.checkInt(1, o1.getKthAncestor(3, 1));
    check.checkInt(0, o1.getKthAncestor(5, 2));
    check.checkInt(-1, o1.getKthAncestor(6, 3));

    parent = { -1,0,0,1,2,0,1,3,6,1 };
    TreeAncestor o2(10, parent);
    check.checkInt(-1, o2.getKthAncestor(8, 6));
    check.checkInt(-1, o2.getKthAncestor(9, 7));
    check.checkInt(0, o2.getKthAncestor(1, 1));
    check.checkInt(-1, o2.getKthAncestor(2, 5));
    check.checkInt(0, o2.getKthAncestor(4, 2));
    check.checkInt(0, o2.getKthAncestor(7, 3));
    check.checkInt(-1, o2.getKthAncestor(3, 7));
    check.checkInt(-1, o2.getKthAncestor(9, 6));
    check.checkInt(-1, o2.getKthAncestor(3, 5));
    check.checkInt(-1, o2.getKthAncestor(8, 8));

    parent = { -1,8,9,2,3,4,5,6,7,0 };
    TreeAncestor o3(10, parent);
    check.checkInt(7, o3.getKthAncestor(1, 2));
    check.checkInt(5, o3.getKthAncestor(1, 4));
    check.checkInt(9, o3.getKthAncestor(1, 8));
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
