/* 根据描述创建二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维整数数组 descriptions ，其中 descriptions[i] = [parenti, childi, isLefti] 表示 parenti 是 childi 在 二叉树 中的 父节点，二叉树中各节点的值 互不相同 。此外：

如果 isLefti == 1 ，那么 childi 就是 parenti 的左子节点。
如果 isLefti == 0 ，那么 childi 就是 parenti 的右子节点。
请你根据 descriptions 的描述来构造二叉树并返回其 根节点 。

测试用例会保证可以构造出 有效 的二叉树。

 

示例 1：



输入：descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
输出：[50,20,80,15,17,19]
解释：根节点是值为 50 的节点，因为它没有父节点。
结果二叉树如上图所示。
示例 2：



输入：descriptions = [[1,2,1],[2,3,0],[3,4,1]]
输出：[1,2,null,null,3,4]
解释：根节点是值为 1 的节点，因为它没有父节点。
结果二叉树如上图所示。
 

提示：

1 <= descriptions.length <= 104
descriptions[i].length == 3
1 <= parenti, childi <= 105
0 <= isLefti <= 1
descriptions 所描述的二叉树是一棵有效二叉树

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/create-binary-tree-from-descriptions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"
#include "../header/TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, vector<pair<int, int>>> adjs;

        int root = getAdjs(descriptions, adjs);
        TreeNode* tree = new TreeNode(root);
        DFS(tree, adjs);

        return tree;
    }

    int getAdjs(vector<vector<int>>& descriptions, unordered_map<int, vector<pair<int, int>>>& adjs) {
        unordered_set<int> parents, children;

        for (auto& description : descriptions) {
            adjs[description[0]].push_back({ description[1], description[2] });
            parents.insert(description[0]);
            children.insert(description[1]);
        }

        for (int parent : parents) {
            if (children.count(parent) == 0) {
                return parent;
            }
        }

        return 0;
    }

    void DFS(TreeNode* root, unordered_map<int, vector<pair<int, int>>>& adjs) {
        for (auto& adj : adjs[root->val]) {
            TreeNode* node = new TreeNode(adj.first);

            if (adj.second == 1) {
                root->left = node;
            }
            else {
                root->right = node;
            }

            DFS(node, adjs);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> descriptions = { {20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1} };
    TreeNode* actual = o.createBinaryTree(descriptions);
    vector<int> values = { 50,20,80,15,17,19 };
    TreeNode* expected = createTree(values);
    check.checkTree(expected, actual);

    descriptions = { {1,2,1},{2,3,0},{3,4,1} };
    actual = o.createBinaryTree(descriptions);
    values = { 1,2,INT_MIN,INT_MIN,3,4 };
    expected = createTree(values);
    check.checkTree(expected, actual);
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
