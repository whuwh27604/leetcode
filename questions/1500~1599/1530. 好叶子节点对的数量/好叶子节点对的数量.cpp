/* 好叶子节点对的数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你二叉树的根节点 root 和一个整数 distance 。

如果二叉树中两个 叶 节点之间的 最短路径长度 小于或者等于 distance ，那它们就可以构成一组 好叶子节点对 。

返回树中 好叶子节点对的数量 。

 

示例 1：

 



输入：root = [1,2,3,null,4], distance = 3
输出：1
解释：树的叶节点是 3 和 4 ，它们之间的最短路径的长度是 3 。这是唯一的好叶子节点对。
示例 2：



输入：root = [1,2,3,4,5,6,7], distance = 3
输出：2
解释：好叶子节点对为 [4,5] 和 [6,7] ，最短路径长度都是 2 。但是叶子节点对 [4,6] 不满足要求，因为它们之间的最短路径长度为 4 。
示例 3：

输入：root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
输出：1
解释：唯一的好叶子节点对是 [2,5] 。
示例 4：

输入：root = [100], distance = 1
输出：0
示例 5：

输入：root = [1,1,1], distance = 2
输出：1
 

提示：

tree 的节点数在 [1, 2^10] 范围内。
每个节点的值都在 [1, 100] 之间。
1 <= distance <= 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-good-leaf-nodes-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int pairs = 0;

        (void)DFS(root, distance, pairs);

        return pairs;
    }

    vector<int> DFS(TreeNode* root, int distance, int& pairs) {
        vector<int> allLeavesDistance(distance, 0), leftLeavesDistance(distance, 0), rightLeavesDistance(distance, 0);

        if (root->left == NULL && root->right == NULL) {
            allLeavesDistance[0] = 1;  // 如果是一个叶子节点，返回距离为0的节点有1个
            return allLeavesDistance;
        }

        if (root->left != NULL) {
            leftLeavesDistance = DFS(root->left, distance, pairs);  // 统计左子树中，所有叶子节点到left的距离，每个距离值的个数
        }

        if (root->right != NULL) {
            rightLeavesDistance = DFS(root->right, distance, pairs);  // 统计右子树中，所有叶子节点到right的距离，每个距离值的个数
        }

        for (int i = 0; i <= distance - 2; ++i) {
            for (int j = distance - 2 - i; j >= 0; --j) {
                pairs += leftLeavesDistance[i] * rightLeavesDistance[j];  // 计算左右子树中的叶子节点能够构成的距离小于等于distance的pair对，它们的最短路径有公共的祖先root
            }
        }

        for (int i = 1; i < distance; ++i) {
            allLeavesDistance[i] = leftLeavesDistance[i - 1] + rightLeavesDistance[i - 1];  // 到root的距离等于到left、right的距离加1，合并左右子树形成到root的距离的个数
        }

        return allLeavesDistance;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,2,3,INT_MIN,4 };
    check.checkInt(1, o.countPairs(createTree(values), 3));

    values = { 1,2,3,4,5,6,7 };
    check.checkInt(2, o.countPairs(createTree(values), 3));
    check.checkInt(0, o.countPairs(createTree(values), 1));
    check.checkInt(2, o.countPairs(createTree(values), 2));
    check.checkInt(6, o.countPairs(createTree(values), 4));
    check.checkInt(6, o.countPairs(createTree(values), 5));

    values = { 7,1,4,6,INT_MIN,5,3,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2 };
    check.checkInt(1, o.countPairs(createTree(values), 3));
    check.checkInt(2, o.countPairs(createTree(values), 4));
    check.checkInt(3, o.countPairs(createTree(values), 5));

    values = { 100 };
    check.checkInt(0, o.countPairs(createTree(values), 1));

    values = { 100,200 };
    check.checkInt(0, o.countPairs(createTree(values), 1));

    values = { 1,1,INT_MIN,1,INT_MIN,1,INT_MIN,1,INT_MIN,1,INT_MIN,1 };
    check.checkInt(0, o.countPairs(createTree(values), 1));

    values = { 1,1,1 };
    check.checkInt(1, o.countPairs(createTree(values), 2));
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
