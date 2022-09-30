/* 重复的彩灯树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一棵结构为二叉树的圣诞树 root 挂满了彩灯，各节点值表示彩灯的颜色。

如果两棵子树具有 相同的结构 和 相同的彩灯颜色分布，则它们是 重复 的。

请返回这棵树上所有 重复的子树。



注意：

对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。


示例 1：



输入：root = [1,3,3,null,2,null,2]
输出：[[3,null,2],[2]]
示例 2：



输入：root = [3,3,2,null,2]
输出：[[2]]
示例 3：



输入：root = [1,3,3,null,2,2]
输出：[[2]]


提示：

树中的结点数在[1,6000]范围内。
-200 <= Node.val <= 200
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<TreeNode*> lightDistribution(TreeNode* root) {
        unordered_map<string, pair<TreeNode*, bool>> keyNodes;
        vector<TreeNode*> dups;

        (void)serial(root, keyNodes, dups);

        return dups;
    }

    string serial(TreeNode* root, unordered_map<string, pair<TreeNode*, bool>>& keyNodes, vector<TreeNode*>& dups) {
        string key;

        if (root != NULL) {
            key = 'V';
            key += to_string(root->val);
            key += 'L';
            key += serial(root->left, keyNodes, dups);
            key += 'R';
            key += serial(root->right, keyNodes, dups);

            if (keyNodes.count(key) == 0) {
                keyNodes[key] = { root,false };
            }
            else {
                if (!keyNodes[key].second) {
                    keyNodes[key].second = true;
                    dups.push_back(keyNodes[key].first);
                }
            }
        }

        return key;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,3,3,INT_MIN,2,INT_MIN,2 };
    TreeNode* root = createTree(values);
    vector<TreeNode*> actual = o.lightDistribution(root);
    check.checkInt(2, (int)actual.size());
    check.checkPoint(root->left->right, actual[0]);
    check.checkPoint(root->left, actual[1]);

    values = { 3,3,2,INT_MIN,2 };
    root = createTree(values);
    actual = o.lightDistribution(root);
    check.checkInt(1, (int)actual.size());
    check.checkPoint(root->left->right, actual[0]);

    values = { 1,3,3,INT_MIN,2,2 };
    root = createTree(values);
    actual = o.lightDistribution(root);
    check.checkInt(1, (int)actual.size());
    check.checkPoint(root->left->right, actual[0]);
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
