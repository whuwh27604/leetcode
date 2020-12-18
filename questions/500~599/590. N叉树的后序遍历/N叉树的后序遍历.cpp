/* N叉树的后序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个 N 叉树，返回其节点值的后序遍历。

例如，给定一个 3叉树 :

 



 

返回其后序遍历: [5,6,3,2,4,1].

 

说明: 递归法很简单，你可以使用迭代法完成此题吗?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../header/N_aryTreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> values;
        if (root == NULL) {
            return values;
        }

        stack<Node*> allNodes;
        allNodes.push(root);
        while (!allNodes.empty()) {
            Node* node = allNodes.top();
            allNodes.pop();
            values.push_back(node->val);

            for (auto iter = node->children.begin(); iter != node->children.end(); iter++) {
                allNodes.push(*iter);
            }
        }

        reverse(values.begin(), values.end());
        return values;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    Node node1(1);
    Node node2(3);
    Node node3(2);
    Node node4(4);
    Node node5(5);
    Node node6(6);
    node1.children.push_back(&node2);
    node1.children.push_back(&node3);
    node1.children.push_back(&node4);
    node2.children.push_back(&node5);
    node2.children.push_back(&node6);
    vector<int> actual = o.postorder(&node1);
    vector<int> expected = { 5,6,3,2,4,1 };
    check.checkIntVector(expected, actual);

    actual = o.postorder(NULL);
    expected = {  };
    check.checkIntVector(expected, actual);

    actual = o.postorder(&node6);
    expected = { 6 };
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
