/* 导航装置.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小扣参加的秋日市集景区共有 N 个景点，景点编号为 1~N。景点内设有 N−1 条双向道路，使所有景点形成了一个二叉树结构，根结点记为 root，景点编号即为节点值。

由于秋日市集景区的结构特殊，游客很容易迷路，主办方决定在景区的若干个景点设置导航装置，按照所在景点编号升序排列后定义装置编号为 1 ~ M。导航装置向游客发送数据，数据内容为列表 [游客与装置 1 的相对距离,游客与装置 2 的相对距离,...,游客与装置 M 的相对距离]。由于游客根据导航装置发送的信息来确认位置，因此主办方需保证游客在每个景点接收的数据信息皆不相同。请返回主办方最少需要设置多少个导航装置。

示例 1：

输入：root = [1,2,null,3,4]

输出：2

解释：在景点 1、3 或景点 1、4 或景点 3、4 设置导航装置。

image.png

示例 2：

输入：root = [1,2,3,4]

输出：1

解释：在景点 3、4 设置导航装置皆可。

image.png

提示：

2 <= N <= 50000
二叉树的非空节点值为 1~N 的一个排列。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int navigation(TreeNode* root) {
        // 结论：对任意3叉节点，必须2个方向上有装置
        int count = 0;
        bool both = false;
        bool left = DFS(root->left, count, both);
        bool right = DFS(root->right, count, both);
        if ((!left || !right) && !both) {
            ++count;
        }

        return count;
    }

    // 先假设root节点放了一个装置，统计以node为根节点的子树是否有装置
    bool DFS(TreeNode* node, int& count, bool& both) {
        if (node == NULL) {
            return false;
        }

        bool left = DFS(node->left, count, both);
        bool right = DFS(node->right, count, both);

        if (node->left != NULL && node->right != NULL) {  // 3叉节点
            if (!left && !right) {
                ++count;  // 两边都没有，必须要放一个
            }
            both = (left && right);

            return true;  // 3叉节点一定会有装置
        }

        return left || right;  // 非3叉节点直接返回子树的情况
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 1,2,INT_MIN,3,4 };
    check.checkInt(2, o.navigation(createTree(values)));

    values = { 1,2,3,4 };
    check.checkInt(1, o.navigation(createTree(values)));
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
