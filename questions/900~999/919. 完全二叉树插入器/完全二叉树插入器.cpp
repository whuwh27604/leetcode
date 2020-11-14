/* 完全二叉树插入器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
完全二叉树是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。

设计一个用完全二叉树初始化的数据结构 CBTInserter，它支持以下几种操作：

CBTInserter(TreeNode root) 使用头节点为 root 的给定树初始化该数据结构；
CBTInserter.insert(int v)  向树中插入一个新节点，节点类型为 TreeNode，值为 v 。使树保持完全二叉树的状态，并返回插入的新节点的父节点的值；
CBTInserter.get_root() 将返回树的头节点。
 

示例 1：

输入：inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
输出：[null,1,[1,2]]
示例 2：

输入：inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
输出：[null,3,4,[1,2,3,4,5,6,7,8]]
 

提示：

最初给定的树是完全二叉树，且包含 1 到 1000 个节点。
每个测试用例最多调用 CBTInserter.insert  操作 10000 次。
给定节点或插入节点的每个值都在 0 到 5000 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/complete-binary-tree-inserter
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class CBTInserter {
public:
    CBTInserter(TreeNode* rootNode) {
        root = rootNode;
        bfs.push(root);

        TreeNode* node = root;
        while (node->left != NULL && node->right != NULL) {
            bfs.push(node->left);
            bfs.push(node->right);
            bfs.pop();
            node = bfs.front();
        }
    }

    int insert(int v) {
        TreeNode* node = bfs.front();

        if (node->left == NULL) {
            node->left = new TreeNode(v);
        }
        else {
            node->right = new TreeNode(v);
            bfs.push(node->left);
            bfs.push(node->right);
            bfs.pop();
        }

        return node->val;
    }

    TreeNode* get_root() {
        return root;
    }

private:
    TreeNode* root;
    queue<TreeNode*> bfs;
};

int main()
{
    CheckResult check;
    
    vector<int> values = { 1 };
    TreeNode* root = createTree(values);
    CBTInserter o1(root);
    check.checkInt(1, o1.insert(2));
    check.checkInt(1, o1.insert(3));
    check.checkInt(2, o1.insert(4));
    check.checkInt(2, o1.insert(5));
    check.checkInt(3, o1.insert(6));
    check.checkInt(3, o1.insert(7));
    check.checkPoint(root, o1.get_root());

    values = { 1,2,3,4,5,6 };
    root = createTree(values);
    CBTInserter o2(root);
    check.checkInt(3, o2.insert(7));
    check.checkInt(4, o2.insert(8));
    check.checkInt(4, o2.insert(7));
    check.checkInt(5, o2.insert(8));
    check.checkInt(5, o2.insert(7));
    check.checkInt(6, o2.insert(8));
    check.checkPoint(root, o2.get_root());
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
