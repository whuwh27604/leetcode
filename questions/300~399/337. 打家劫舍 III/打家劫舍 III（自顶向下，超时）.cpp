/* 打家劫舍 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \
     3   1

输出: 7
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
示例 2:

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int rob(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int robbing = root->val;
        robbing += (root->left == NULL ? 0 : rob(root->left->left) + rob(root->left->right));
        robbing += (root->right == NULL ? 0 : rob(root->right->left) + rob(root->right->right));

        int noRobbing = rob(root->left) + rob(root->right);

        return max(robbing, noRobbing);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.rob(NULL));

    TreeNode node1(1);
    TreeNode node2(10000);
    TreeNode node3(1);
    TreeNode node4(1);
    TreeNode node5(1);
    TreeNode node6(1000);
    TreeNode node7(1000);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    check.checkInt(12000, o.rob(&node1));

    node1.val = 5;
    node1.left = node1.right = NULL;
    check.checkInt(5, o.rob(&node1));

    node1.val = 5;
    node2.val = 3;
    node1.left = &node2;
    node1.right = NULL;
    node2.left = node2.right = NULL;
    check.checkInt(5, o.rob(&node1));

    node1.val = 5;
    node2.val = 8;
    node1.left = &node2;
    node1.right = NULL;
    node2.left = node2.right = NULL;
    check.checkInt(8, o.rob(&node1));

    node1.val = 5;
    node2.val = 1;
    node3.val = 2;
    node1.left = &node2;
    node1.right = &node3;
    node2.left = node2.right = NULL;
    node3.left = node3.right = NULL;
    check.checkInt(5, o.rob(&node1));

    node1.val = 5;
    node2.val = 3;
    node3.val = 4;
    node1.left = &node2;
    node1.right = &node3;
    node2.left = node2.right = NULL;
    node3.left = node3.right = NULL;
    check.checkInt(7, o.rob(&node1));

    node1.val = 3;
    node2.val = 2;
    node3.val = 3;
    node4.val = 3;
    node5.val = 1;
    node1.left = &node2;
    node1.right = &node3;
    node2.left = NULL;
    node2.right = &node4;
    node3.left = NULL;
    node3.right = &node5;
    node4.left = node4.right = NULL;
    node5.left = node5.right = NULL;
    check.checkInt(7, o.rob(&node1));

    node1.val = 3;
    node2.val = 4;
    node3.val = 5;
    node4.val = 1;
    node5.val = 3;
    node6.val = 1;
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = NULL;
    node3.right = &node6;
    node4.left = node4.right = NULL;
    node5.left = node5.right = NULL;
    node6.left = node6.right = NULL;
    check.checkInt(9, o.rob(&node1));
    
    TreeNode* root = NULL;
    list<TreeNode*> nodes;
    int lrCount = 0;
    ifstream in("D:/ProgramData/Microsoft/VisualStudio/myproject/打家劫舍 III/a.txt", ios::binary);
    string fileContext;
    in >> fileContext;
    fileContext.push_back(',');
    string::size_type start = 0;
    string::size_type position = fileContext.find(',');
    while (position != fileContext.npos) {
        TreeNode* node = NULL;
        if (fileContext[start] == 'n') {
            // NULL;
        }
        else {
            string oneNumber(fileContext, start, position - start + 1);
            stringstream ss;
            ss << oneNumber;
            int number;
            ss >> number;
            node = new TreeNode(number);
            if (root == NULL) {
                root = node;
            }
        }

        if (nodes.empty()) {
            nodes.push_back(node);
        }
        else {
            lrCount++;
            if (node != NULL) {
                nodes.push_back(node);
            }
            TreeNode* tmp = nodes.front();
            if (lrCount == 1) {
                tmp->left = node;
            }
            else {
                tmp->right = node;
            }
            if (lrCount == 2) {
                lrCount = 0;
                nodes.pop_front();
            }
        }

        position++;
        start = position;
        position = fileContext.find(',', position);
    }
    check.checkInt(27106502, o.rob(root));
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
