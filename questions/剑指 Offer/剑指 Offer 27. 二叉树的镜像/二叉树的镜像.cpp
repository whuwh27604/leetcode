/* 二叉树的镜像.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

 

示例 1：

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
 

限制：

0 <= 节点个数 <= 1000

注意：本题与主站 226 题相同：https://leetcode-cn.com/problems/invert-binary-tree/

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        DFS(root);

        return root;
    }

    void DFS(TreeNode* root) {
        if (root != NULL) {
            swap(root->left, root->right);
            DFS(root->left);
            DFS(root->right);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 4,2,7,1,3,6,9 };
    TreeNode* actual = o.mirrorTree(createTree(values));
    values = { 4,7,2,9,6,3,1 };
    check.checkTree(actual, createTree(values));
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
