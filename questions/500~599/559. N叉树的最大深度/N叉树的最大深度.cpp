/* N叉树的最大深度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个 N 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

例如，给定一个 3叉树 :

 



 

我们应返回其最大深度，3。

说明:

树的深度不会超过 1000。
树的节点总不会超过 5000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <list>
#include "../header/N_aryTreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) {
            return 0;
        }

        list<Node*> allNodes;
        allNodes.push_back(root);
        int depth = 0;

        while (!allNodes.empty()) {
            int i, len = allNodes.size();
            for (i = 0; i < len; i++) {
                Node* node = allNodes.front();
                for (unsigned int j = 0; j < node->children.size(); j++) {
                    allNodes.push_back(node->children[j]);
                }
                allNodes.pop_front();
            }

            depth++;
        }

        return depth;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    Node node1;
    Node node2;
    Node node3;
    Node node4;
    Node node5;
    Node node6;
    node1.children.push_back(&node2);
    node1.children.push_back(&node3);
    node1.children.push_back(&node4);
    node3.children.push_back(&node5);
    node3.children.push_back(&node6);
    check.checkInt(3, o.maxDepth(&node1));

    check.checkInt(0, o.maxDepth(NULL));

    node1.children.clear();
    check.checkInt(1, o.maxDepth(&node1));

    node1.children.push_back(&node2);
    node2.children.clear();
    node2.children.push_back(&node3);
    node3.children.clear();
    node3.children.push_back(&node4);
    node4.children.clear();
    node4.children.push_back(&node5);
    node5.children.clear();
    node5.children.push_back(&node6);
    check.checkInt(6, o.maxDepth(&node1));
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
