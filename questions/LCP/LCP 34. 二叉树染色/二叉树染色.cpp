/* 二叉树染色.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小扣有一个根结点为 root 的二叉树模型，初始所有结点均为白色，可以用蓝色染料给模型结点染色，模型的每个结点有一个 val 价值。小扣出于美观考虑，希望最后二叉树上每个蓝色相连部分的结点个数不能超过 k 个，求所有染成蓝色的结点价值总和最大是多少？

示例 1：

输入：root = [5,2,3,4], k = 2

输出：12

解释：结点 5、3、4 染成蓝色，获得最大的价值 5+3+4=12


示例 2：

输入：root = [4,1,3,9,null,null,2], k = 2

输出：16

解释：结点 4、3、9 染成蓝色，获得最大的价值 4+3+9=16


提示：

1 <= k <= 10
1 <= val <= 10000
1 <= 结点数量 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-ran-se-UGC
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxValue(TreeNode* root, int k) {
        vector<int> dp = DFS(root, k);

        return max(dp[0], dp[1]);  // 首节点可能作为第一个，也可能不选它
    }

    vector<int> DFS(TreeNode* root, int k) {
        if (root == NULL) {
            return vector<int>(k + 1, 0);
        }

        vector<int> dpLeft = DFS(root->left, k);
        vector<int> dpRight = DFS(root->right, k);

        vector<int> dp(k + 1, 0);
        dp[0] = max(dpLeft[0], dpLeft[1]) + max(dpRight[0], dpRight[1]);  // root不选择，那么左右子树都选最大的
        dp[k] = root->val + dpLeft[0] + dpRight[0];  // root作为第k个，左右节点必然都不能再选

        for (int i = 1; i < k; ++i) {  // root作为第i个，还剩k - i个可选
            dp[i] = max(dpLeft[0] + max(dpRight[0], dpRight[i + 1]),  // 左边不选，右边最多可从i+1开始
                dpRight[0] + max(dpLeft[0], dpLeft[i + 1]));  // 右边不选，左边最多可从i+1开始

            for (int j = 1; j < k - i; ++j) {  // 左边选j个，右边选k - i - j个
                dp[i] = max(dp[i], dpLeft[k + 1 - j] + dpRight[k + 1 - (k - i - j)]);
            }

            dp[i] += root->val;
        }

        return dp;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 5,2,3,4 };
    check.checkInt(12, o.maxValue(createTree(values), 2));

    values = { 4,1,3,9,INT_MIN,INT_MIN,2 };
    check.checkInt(16, o.maxValue(createTree(values), 2));

    values = { 5 };
    check.checkInt(5, o.maxValue(createTree(values), 1));

    values = { 1,3,INT_MIN,5,INT_MIN,7,INT_MIN,9 };
    check.checkInt(15, o.maxValue(createTree(values), 1));

    values = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    check.checkInt(115, o.maxValue(createTree(values), 3));

    values = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    check.checkInt(115, o.maxValue(createTree(values), 5));

    values = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    check.checkInt(119, o.maxValue(createTree(values), 7));

    values = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    check.checkInt(119, o.maxValue(createTree(values), 9));

    values = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
    check.checkInt(399, o.maxValue(createTree(values), 1));

    values = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
    check.checkInt(399, o.maxValue(createTree(values), 2));

    values = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
    check.checkInt(474, o.maxValue(createTree(values), 4));

    values = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
    check.checkInt(491, o.maxValue(createTree(values), 8));

    values = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
    check.checkInt(491, o.maxValue(createTree(values), 10));

    values = { 31,INT_MIN,11,5,INT_MIN,36,16,79,56,34,78,28,32,88,84,58,INT_MIN,67,98,INT_MIN,INT_MIN,INT_MIN,38,91,INT_MIN,69,73,93,INT_MIN,84,INT_MIN,70,88,96,94,2,34,68,11,43,50,84,21,35,34,INT_MIN,23,40,INT_MIN,14,22,49,INT_MIN,INT_MIN,18,24,INT_MIN,68,12,98,79,33,78,99,91,56,INT_MIN,73,96,75,22,9,16,81,85,70,58,21,77,71,37,25,44,57,55,INT_MIN,INT_MIN,59,87,94,84,53,28,INT_MIN,88,74,26,91,32,26,41,INT_MIN,57,43,2,16,58,29,54,31,INT_MIN,83,INT_MIN,59,98,INT_MIN,INT_MIN,75,INT_MIN,47,32,9,14,92 };
    check.checkInt(3290, o.maxValue(createTree(values), 1));
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
