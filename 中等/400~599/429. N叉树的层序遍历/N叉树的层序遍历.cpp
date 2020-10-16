/* N叉树的层序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。

例如，给定一个 3叉树 :

 



 

返回其层序遍历:

[
     [1],
     [3,2,4],
     [5,6]
]
 

说明:

树的深度不会超过 1000。
树的节点总数不会超过 5000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/N_aryTreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == NULL) {
            return {};
        }

        vector<vector<int>> values;
        traverse(values, root, 0);

        return values;
    }

    // 严格来说还是DFS，不是BFS，只是控制了输出结果的位置达到BFS的效果
    void traverse(vector<vector<int>>& values, Node* root, int level) {
        if ((int)values.size() <= level) {
            values.push_back({});
        }

        values[level].push_back(root->val);

        for (Node* child : root->children) {
            traverse(values, child, level + 1);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> actual = o.levelOrder(NULL);
    vector<vector<int>> expected = {};
    check.checkIntVectorVector(expected, actual);

    Node node1(1);
    actual = o.levelOrder(&node1);
    expected = { {1} };
    check.checkIntVectorVector(expected, actual);

    Node node2(3);
    Node node3(2);
    Node node4(4);
    node1.children.push_back(&node2);
    node1.children.push_back(&node3);
    node1.children.push_back(&node4);
    actual = o.levelOrder(&node1);
    expected = { {1},{3,2,4} };
    check.checkIntVectorVector(expected, actual);

    Node node5(5);
    Node node6(6);
    node3.children.push_back(&node5);
    node3.children.push_back(&node6);
    actual = o.levelOrder(&node1);
    expected = { {1},{3,2,4},{5,6} };
    check.checkIntVectorVector(expected, actual);
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
