/* 从先序遍历还原二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们从二叉树的根节点 root 开始进行深度优先搜索。

在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。（如果节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。

如果节点只有一个子节点，那么保证该子节点为左子节点。

给出遍历输出 S，还原树并返回其根节点 root。

 

示例 1：



输入："1-2--3--4-5--6--7"
输出：[1,2,5,3,4,6,7]
示例 2：



输入："1-2--3---4-5--6---7"
输出：[1,2,5,3,null,6,null,4,null,7]
示例 3：



输入："1-401--349---90--88"
输出：[1,401,null,349,88,90]
 

提示：

原始树中的节点数介于 1 和 1000 之间。
每个节点的值介于 1 和 10 ^ 9 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        int i = 0, size = S.size(), depth = 0;
        stack<TreeNode*> nodes;
        TreeNode* node = NULL;

        TreeNode* root = getNode(S, i, depth);
        nodes.push(root);

        while (i < size) {
            depth = 0;
            TreeNode* next = getNode(S, i, depth);  // 获取下一个节点

            while ((int)nodes.size() >= depth) {  // 找到父节点
                node = nodes.top();
                nodes.pop();
            }

            if (node != NULL) {
                if (node->left == NULL) {
                    node->left = next;  // 设置父子关系
                }
                else {
                    node->right = next;
                }

                nodes.push(node);
                nodes.push(next);  // 节点入栈，模拟DFS
            }
        }

        return root;
    }

    TreeNode* getNode(string& s, int& index, int& depth) {
        int size = s.size(), value = 0;

        for (; index < size; ++index) {
            if (s[index] == '-') {
                if (value != 0) {
                    break;
                }
                ++depth;
            }
            else {
                value = value * 10 + s[index] - '0';
            }
        }

        return new TreeNode(value);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 123 };
    check.checkTree(createTree(values), o.recoverFromPreorder("123"));

    values = { 1,2,5,3,4,6,7 };
    check.checkTree(createTree(values), o.recoverFromPreorder("1-2--3--4-5--6--7"));

    values = { 1,2,5,3,INT_MIN,6,INT_MIN,4,INT_MIN,7 };
    check.checkTree(createTree(values), o.recoverFromPreorder("1-2--3---4-5--6---7"));

    values = { 1,401,INT_MIN,349,88,90 };
    check.checkTree(createTree(values), o.recoverFromPreorder("1-401--349---90--88"));

    values = { 1,2,5,33,4,618,7,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,111,INT_MIN,5555 };
    check.checkTree(createTree(values), o.recoverFromPreorder("1-2--33--4-5--618--7---111----5555"));
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
