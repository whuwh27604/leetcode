/* 输出二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个 m*n 的二维字符串数组中输出二叉树，并遵守以下规则：

行数 m 应当等于给定二叉树的高度。
列数 n 应当总是奇数。
根节点的值（以字符串格式给出）应当放在可放置的第一行正中间。根节点所在的行与列会将剩余空间划分为两部分（左下部分和右下部分）。你应该将左子树输出在左下部分，右子树输出在右下部分。左下和右下部分应当有相同的大小。即使一个子树为空而另一个非空，你不需要为空的子树输出任何东西，但仍需要为另一个子树留出足够的空间。然而，如果两个子树都为空则不需要为它们留出任何空间。
每个未使用的空间应包含一个空的字符串""。
使用相同的规则输出子树。
示例 1:

输入:
     1
    /
   2
输出:
[["", "1", ""],
 ["2", "", ""]]
示例 2:

输入:
     1
    / \
   2   3
    \
     4
输出:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
示例 3:

输入:
      1
     / \
    2   5
   /
  3
 /
4
输出:
[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
注意: 二叉树的高度在范围 [1, 10] 中。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/print-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int width = (int)pow(2, height) - 1;
        vector<vector<string>> tree(height, vector<string>(width, ""));
        
        DFS(tree, root, 0, 0, width - 1);
        return tree;
    }

    int getHeight(TreeNode* root) {
        return (root == NULL) ? 0 : max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    void DFS(vector<vector<string>>& tree, TreeNode* root, int layer, int leftIndex, int rightIndex) {
        int middle = (leftIndex + rightIndex) / 2;
        tree[layer][middle] = to_string(root->val);

        if (root->left != NULL) {
            DFS(tree, root->left, layer + 1, leftIndex, middle - 1);
        }

        if (root->right != NULL) {
            DFS(tree, root->right, layer + 1, middle + 1, rightIndex);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(5);
    TreeNode node4(3);
    TreeNode node5(4);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = NULL;
    node4.left = &node5;
    node4.right = NULL;
    vector<vector<string>> actual = o.printTree(&node1);
    vector<vector<string>> expected = { {"",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""},
        {"",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""},
        {"",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""},
        {"4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""} };
    check.checkStringVectorVector(expected, actual);

    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    node1.left = &node2;
    node1.right = &node3;
    node2.left = NULL;
    node2.right = &node4;
    node3.left = NULL;
    node3.right = NULL;
    node4.left = NULL;
    node4.right = NULL;
    actual = o.printTree(&node1);
    expected = { {"", "", "", "1", "", "", ""},{"", "2", "", "", "", "3", ""},{"", "", "4", "", "", "", ""} };
    check.checkStringVectorVector(expected, actual);

    node1.val = 1;
    node2.val = 2;
    node1.left = &node2;
    node1.right = NULL;
    node2.left = NULL;
    node2.right = NULL;
    actual = o.printTree(&node1);
    expected = { {"", "1", ""},{"2", "", ""} };
    check.checkStringVectorVector(expected, actual);

    node1.val = 1;
    node1.left = NULL;
    node1.right = NULL;
    actual = o.printTree(&node1);
    expected = { {"1"} };
    check.checkStringVectorVector(expected, actual);
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
