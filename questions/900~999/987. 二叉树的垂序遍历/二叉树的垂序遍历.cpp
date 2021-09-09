/* 二叉树的垂序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定二叉树，按垂序遍历返回其结点值。

对位于 (X, Y) 的每个结点而言，其左右子结点分别位于 (X-1, Y-1) 和 (X+1, Y-1)。

把一条垂线从 X = -infinity 移动到 X = +infinity ，每当该垂线与结点接触时，我们按从上到下的顺序报告结点的值（ Y 坐标递减）。

如果两个结点位置相同，则首先报告的结点值较小。

按 X 坐标顺序返回非空报告的列表。每个报告都有一个结点值列表。

 

示例 1：



输入：[3,9,20,null,null,15,7]
输出：[[9],[3,15],[20],[7]]
解释：
在不丧失其普遍性的情况下，我们可以假设根结点位于 (0, 0)：
然后，值为 9 的结点出现在 (-1, -1)；
值为 3 和 15 的两个结点分别出现在 (0, 0) 和 (0, -2)；
值为 20 的结点出现在 (1, -1)；
值为 7 的结点出现在 (2, -2)。
示例 2：



输入：[1,2,3,4,5,6,7]
输出：[[4],[2],[1,5,6],[3],[7]]
解释：
根据给定的方案，值为 5 和 6 的两个结点出现在同一位置。
然而，在报告 "[1,5,6]" 中，结点值 5 排在前面，因为 5 小于 6。
 

提示：

树的结点数介于 1 和 1000 之间。
每个结点值介于 0 和 1000 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include <set>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //   x        y       vals
        map<int, map<int, multiset<int>>> nodes;
        DFS(root, 0, 0, nodes);

        vector<vector<int>> ans;
        output(nodes, ans);

        return ans;
    }

    void DFS(TreeNode* root, int x, int y, map<int, map<int, multiset<int>>>& nodes) {
        nodes[x][y].insert(root->val);

        if (root->left != NULL) {
            DFS(root->left, x - 1, y - 1, nodes);
        }

        if (root->right != NULL) {
            DFS(root->right, x + 1, y - 1, nodes);
        }
    }

    void output(map<int, map<int, multiset<int>>>& nodes, vector<vector<int>>& ans) {
        for (auto itX = nodes.begin(); itX != nodes.end(); ++itX) {
            ans.push_back({});

            for (auto itY = itX->second.rbegin(); itY != itX->second.rend(); ++itY) {
                for (auto itV = itY->second.begin(); itV != itY->second.end(); ++itV) {
                    ans.back().push_back(*itV);
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 3,9,20,INT_MIN,INT_MIN,15,7 };
    vector<vector<int>> actual = o.verticalTraversal(createTree(values));
    vector<vector<int>> expected = { {9},{3,15},{20},{7} };
    check.checkIntVectorVector(expected, actual);

    values = { 1,2,3,4,5,6,7 };
    actual = o.verticalTraversal(createTree(values));
    expected = { {4},{2},{1,5,6},{3},{7} };
    check.checkIntVectorVector(expected, actual);

    values = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
    actual = o.verticalTraversal(createTree(values));
    expected = { {16},{8},{4,17,18,20,24},{2,9,10,12},{1,5,6,19,21,22,25,26,28},{3,11,13,14},{7,23,27,29,30},{15},{31} };
    check.checkIntVectorVector(expected, actual);

    values = { 1 };
    actual = o.verticalTraversal(createTree(values));
    expected = { {1} };
    check.checkIntVectorVector(expected, actual);

    values = { 3,1,4,0,2,2 };
    actual = o.verticalTraversal(createTree(values));
    expected = { {0},{1},{3,2,2},{4} };
    check.checkIntVectorVector(expected, actual);

    values = { 1,5,6 };
    actual = o.verticalTraversal(createTree(values));
    expected = { {5},{1},{6} };
    check.checkIntVectorVector(expected, actual);
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
