/* 二叉树中所有距离为 K 的结点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 K 。

返回到目标结点 target 距离为 K 的所有结点的值的列表。 答案可以以任何顺序返回。

 

示例 1：

输入：root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
输出：[7,4,1]
解释：
所求结点为与目标结点（值为 5）距离为 2 的结点，
值分别为 7，4，以及 1



注意，输入的 "root" 和 "target" 实际上是树上的结点。
上面的输入仅仅是对这些对象进行了序列化描述。
 

提示：

给定的树是非空的。
树上的每个结点都具有唯一的值 0 <= node.val <= 500 。
目标结点 target 是树上的结点。
0 <= K <= 1000.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<TreeNode*> path;
        path.push_back(root);
        (void)findTarget(root, target, path);

        int index = path.size() - 1;
        path.push_back(NULL);
        queue<TreeNode*> bfs;
        bfs.push(target);

        while (!bfs.empty() && (K != 0)) {
            int size = bfs.size();

            for (int i = 0; i < size; ++i) {
                TreeNode* node = bfs.front();
                bfs.pop();

                if ((node->left != NULL) && (index < 0 || node->left != path[index + 1])) {
                    bfs.push(node->left);
                }

                if ((node->right != NULL) && (index < 0 || node->right != path[index + 1])) {
                    bfs.push(node->right);
                }

                if ((index > 0) && (node == path[index])) {
                    bfs.push(path[index - 1]);
                }
            }

            --index;
            --K;
        }

        vector<int> distanceKs;
        while (!bfs.empty()) {
            distanceKs.push_back(bfs.front()->val);
            bfs.pop();
        }

        return distanceKs;
    }

    bool findTarget(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (root == target) {
            return true;
        }

        if (root->left != NULL) {
            path.push_back(root->left);
            if (findTarget(root->left, target, path)) {
                return true;
            }
            path.pop_back();
        }

        if (root->right != NULL) {
            path.push_back(root->right);
            if (findTarget(root->right, target, path)) {
                return true;
            }
            path.pop_back();
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode node1(3);
    TreeNode node2(5);
    TreeNode node3(1);
    TreeNode node4(6);
    TreeNode node5(2);
    TreeNode node6(0);
    TreeNode node7(8);
    TreeNode node8(7);
    TreeNode node9(4);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node5.left = &node8;
    node5.right = &node9;
    vector<int> actual = o.distanceK(&node1, &node2, 2);
    vector<int> expected = { 1,4,7 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.distanceK(&node1, &node2, 0);
    expected = { 5 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.distanceK(&node1, &node2, 1);
    expected = { 2,3,6 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.distanceK(&node1, &node2, 3);
    expected = { 0,8 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.distanceK(&node1, &node2, 4);
    expected = {  };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.distanceK(&node1, &node1, 0);
    expected = { 3 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.distanceK(&node1, &node1, 1);
    expected = { 5,1 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.distanceK(&node1, &node1, 2);
    expected = { 6,2,0,8 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.distanceK(&node1, &node1, 3);
    expected = { 7,4 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.distanceK(&node1, &node1, 4);
    expected = {  };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.distanceK(&node1, &node8, 0);
    expected = { 7 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.distanceK(&node1, &node8, 1);
    expected = { 2 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.distanceK(&node1, &node8, 2);
    expected = { 4,5 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.distanceK(&node1, &node8, 3);
    expected = { 6,3 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.distanceK(&node1, &node8, 4);
    expected = { 1 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.distanceK(&node1, &node8, 5);
    expected = { 0,8 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.distanceK(&node1, &node8, 6);
    expected = {  };
    check.checkIntVectorRandomOrder(expected, actual);

    node1.left = node1.right = NULL;
    actual = o.distanceK(&node1, &node1, 0);
    expected = { 3 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.distanceK(&node1, &node1, 1);
    expected = {  };
    check.checkIntVectorRandomOrder(expected, actual);
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
