/* 克隆图.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。

图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。

class Node {
    public int val;
    public List<Node> neighbors;
}
 

测试用例格式：

简单起见，每个节点的值都和它的索引相同。例如，第一个节点值为 1（val = 1），第二个节点值为 2（val = 2），以此类推。该图在测试用例中使用邻接列表表示。

邻接列表 是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。

给定节点将始终是图中的第一个节点（值为 1）。你必须将 给定节点的拷贝 作为对克隆图的引用返回。

 

示例 1：



输入：adjList = [[2,4],[1,3],[2,4],[1,3]]
输出：[[2,4],[1,3],[2,4],[1,3]]
解释：
图中有 4 个节点。
节点 1 的值是 1，它有两个邻居：节点 2 和 4 。
节点 2 的值是 2，它有两个邻居：节点 1 和 3 。
节点 3 的值是 3，它有两个邻居：节点 2 和 4 。
节点 4 的值是 4，它有两个邻居：节点 1 和 3 。
示例 2：



输入：adjList = [[]]
输出：[[]]
解释：输入包含一个空列表。该图仅仅只有一个值为 1 的节点，它没有任何邻居。
示例 3：

输入：adjList = []
输出：[]
解释：这个图是空的，它不含任何节点。
示例 4：



输入：adjList = [[2],[1]]
输出：[[2],[1]]
 

提示：

节点数不超过 100 。
每个节点值 Node.val 都是唯一的，1 <= Node.val <= 100。
无向图是一个简单图，这意味着图中没有重复的边，也没有自环。
由于图是无向的，如果节点 p 是节点 q 的邻居，那么节点 q 也必须是节点 p 的邻居。
图是连通图，你可以从给定节点访问到所有节点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/clone-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../header/GraphNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> visited;
        return DFS(node, visited);
    }

    Node* DFS(Node* node, unordered_map<Node*, Node*>& visited) {
        auto iter = visited.find(node);
        if (iter != visited.end()) {
            return iter->second;
        }

        Node* cloneNode = new Node(node->val);
        visited.insert({ node, cloneNode });

        for (Node* neighbor : node->neighbors) {
            Node* cloneNeighbor = DFS(neighbor, visited);
            cloneNode->neighbors.push_back(cloneNeighbor);
        }

        return cloneNode;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    Node node1(1);
    Node node2(2);
    Node node3(3);
    Node node4(4);
    node1.neighbors = { &node2, &node4 };
    node2.neighbors = { &node1, &node3 };
    node3.neighbors = { &node2, &node4 };
    node4.neighbors = { &node1, &node3 };
    Node* actual = o.cloneGraph(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->neighbors[0]->val);
    check.checkInt(4, actual->neighbors[1]->val);
    check.checkInt(1, actual->neighbors[0]->neighbors[0]->val);
    check.checkInt(3, actual->neighbors[0]->neighbors[1]->val);
    check.checkInt(1, actual->neighbors[1]->neighbors[0]->val);
    check.checkInt(3, actual->neighbors[1]->neighbors[1]->val);
    check.checkInt(2, actual->neighbors[0]->neighbors[1]->neighbors[0]->val);
    check.checkInt(4, actual->neighbors[0]->neighbors[1]->neighbors[1]->val);

    node1.neighbors = {};
    actual = o.cloneGraph(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(0, actual->neighbors.size());

    node1.neighbors = { &node2 };
    node2.neighbors = { &node1 };
    actual = o.cloneGraph(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->neighbors[0]->val);
    check.checkInt(1, actual->neighbors[0]->neighbors[0]->val);

    check.checkPoint(NULL, o.cloneGraph(NULL));
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
