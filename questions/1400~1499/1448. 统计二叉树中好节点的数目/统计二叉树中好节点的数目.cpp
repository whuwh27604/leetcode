/* 统计二叉树中好节点的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵根为 root 的二叉树，请你返回二叉树中好节点的数目。

「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。

 

示例 1：



输入：root = [3,1,4,3,null,1,5]
输出：4
解释：图中蓝色节点为好节点。
根节点 (3) 永远是个好节点。
节点 4 -> (3,4) 是路径中的最大值。
节点 5 -> (3,4,5) 是路径中的最大值。
节点 3 -> (3,1,3) 是路径中的最大值。
示例 2：



输入：root = [3,3,null,4,2]
输出：3
解释：节点 2 -> (3, 3, 2) 不是好节点，因为 "3" 比它大。
示例 3：

输入：root = [1]
输出：1
解释：根节点是好节点。
 

提示：

二叉树中节点数目范围是 [1, 10^5] 。
每个节点权值的范围是 [-10^4, 10^4] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-good-nodes-in-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int count = 0;

        DFS(root, INT_MIN, count);

        return count;
    }

    void DFS(TreeNode* root, int maximum, int& count) {
        if (maximum <= root->val) {
            ++count;
        }

        maximum = max(maximum, root->val);

        if (root->left != NULL) {
            DFS(root->left, maximum, count);
        }

        if (root->right != NULL) {
            DFS(root->right, maximum, count);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 3,1,4,3,INT_MIN,1,5 };
    check.checkInt(4, o.goodNodes(createTree(values)));

    values = { 3,3,INT_MIN,4,2 };
    check.checkInt(3, o.goodNodes(createTree(values)));

    values = { 1 };
    check.checkInt(1, o.goodNodes(createTree(values)));
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
