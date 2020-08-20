/* 652. 寻找重复的子树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

两棵树重复是指它们具有相同的结构以及相同的结点值。

示例 1：

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
下面是两个重复的子树：

      2
     /
    4
和

    4
因此，你需要以列表的形式返回上述重复子树的根结点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-duplicate-subtrees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        unordered_map<string, int> serials;
        vector<TreeNode*> duplicateSubtrees;

        (void)DFS(root, serials, duplicateSubtrees);
        return duplicateSubtrees;
    }

    string DFS(TreeNode* root, unordered_map<string, int>& serials, vector<TreeNode*>& duplicateSubtrees) {
        string serial = 'V' + to_string(root->val);

        if (root->left != NULL) {
            serial += ('L' + DFS(root->left, serials, duplicateSubtrees));
        }
        else {
            serial += "LN";
        }

        if (root->right != NULL) {
            serial += ('R' + DFS(root->right, serials, duplicateSubtrees));
        }
        else {
            serial += "RN";
        }

        auto iter = serials.find(serial);
        if (iter == serials.end()) {
            serials[serial] = 1;
        }
        else {
            iter->second++;
            if (iter->second == 2) {
                duplicateSubtrees.push_back(root);
            }
        }

        return serial;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(2);
    TreeNode node6(4);
    TreeNode node7(4);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = NULL;
    node3.left = &node5;
    node3.right = &node6;
    node5.left = &node7;
    node5.right = NULL;
    vector<TreeNode*> actual = o.findDuplicateSubtrees(&node1);
    check.checkInt(2, actual.size());
    check.checkInt(4, actual[0]->val);
    check.checkInt(2, actual[1]->val);

    actual = o.findDuplicateSubtrees(NULL);
    check.checkInt(0, actual.size());

    node1.val = node2.val = node3.val = node4.val = node5.val = node6.val = node7.val = 0;
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = NULL;
    node3.left = NULL;
    node3.right = &node5;
    node5.left = &node6;
    node5.right = &node7;
    node6.left = node6.right = NULL;
    node7.left = node7.right = NULL;
    actual = o.findDuplicateSubtrees(&node1);
    check.checkInt(1, actual.size());
    check.checkInt(0, actual[0]->val);

    node1.val = 2;
    node2.val = node3.val = 1;
    node1.left = &node2;
    node1.right = &node3;
    node2.left = node2.right = NULL;
    node3.left = node3.right = NULL;
    actual = o.findDuplicateSubtrees(&node1);
    check.checkInt(1, actual.size());
    check.checkInt(1, actual[0]->val);
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
