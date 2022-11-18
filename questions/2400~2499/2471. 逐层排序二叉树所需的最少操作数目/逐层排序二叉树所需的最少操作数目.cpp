/* 逐层排序二叉树所需的最少操作数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 值互不相同 的二叉树的根节点 root 。

在一步操作中，你可以选择 同一层 上任意两个节点，交换这两个节点的值。

返回每一层按 严格递增顺序 排序所需的最少操作数目。

节点的 层数 是该节点和根节点之间的路径的边数。



示例 1 ：


输入：root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
输出：3
解释：
- 交换 4 和 3 。第 2 层变为 [3,4] 。
- 交换 7 和 5 。第 3 层变为 [5,6,8,7] 。
- 交换 8 和 7 。第 3 层变为 [5,6,7,8] 。
共计用了 3 步操作，所以返回 3 。
可以证明 3 是需要的最少操作数目。
示例 2 ：


输入：root = [1,3,2,7,6,5,4]
输出：3
解释：
- 交换 3 和 2 。第 2 层变为 [2,3] 。
- 交换 7 和 4 。第 3 层变为 [4,6,5,7] 。
- 交换 6 和 5 。第 3 层变为 [4,5,6,7] 。
共计用了 3 步操作，所以返回 3 。
可以证明 3 是需要的最少操作数目。
示例 3 ：


输入：root = [1,2,3,4,5,6]
输出：0
解释：每一层已经按递增顺序排序，所以返回 0 。


提示：

树中节点的数目在范围 [1, 105] 。
1 <= Node.val <= 105
树中的所有值 互不相同 。
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int opers = 0;
        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int i, size = nodes.size();
            vector<int> nums;
            unordered_map<int, int> numIndices;

            for (i = 0; i < size; ++i) {
                TreeNode* node = nodes.front();
                nodes.pop();
                nums.push_back(node->val);
                numIndices[node->val] = i;

                if (node->left != NULL) {
                    nodes.push(node->left);
                }

                if (node->right != NULL) {
                    nodes.push(node->right);
                }
            }

            opers += getOpers(nums, numIndices);
        }

        return opers;
    }

    int getOpers(vector<int>& nums, unordered_map<int, int>& numIndices) {
        int i, size = nums.size(), opers = 0;
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());

        for (i = 0; i < size; ++i) {
            if (tmp[i] != nums[i]) {
                numIndices[nums[i]] = numIndices[tmp[i]];
                nums[numIndices[tmp[i]]] = nums[i];
                ++opers;
            }
        }

        return opers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,4,3,7,6,8,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,9,INT_MIN,10 };
    check.checkInt(3, o.minimumOperations(createTree(values)));

    values = { 1,3,2,7,6,5,4 };
    check.checkInt(3, o.minimumOperations(createTree(values)));

    values = { 1,2,3,4,5,6 };
    check.checkInt(0, o.minimumOperations(createTree(values)));

    values = { 1,3,2,7,6,5,4,15,14,13,12,11,10,9,8 };
    check.checkInt(7, o.minimumOperations(createTree(values)));
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
