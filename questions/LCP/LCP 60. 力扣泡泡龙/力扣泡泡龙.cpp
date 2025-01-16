/* 力扣泡泡龙.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
欢迎各位勇者来到力扣城，本次试炼主题为「力扣泡泡龙」。

游戏初始状态的泡泡形如二叉树 root，每个节点值对应了该泡泡的分值。勇者最多可以击破一个节点泡泡，要求满足：

被击破的节点泡泡 至多 只有一个子节点泡泡
当被击破的节点泡泡有子节点泡泡时，则子节点泡泡将取代被击破泡泡的位置
注：即整棵子树泡泡上移

请问在击破一个节点泡泡操作或无击破操作后，二叉泡泡树的最大「层和」是多少。

注意：

「层和」为同一高度的所有节点的分值之和
示例 1：

输入：root = [6,0,3,null,8]

输出：11

解释：勇者的最佳方案如图所示image.png

示例 2：

输入：root = [5,6,2,4,null,null,1,3,5]

输出：9

解释：勇者击破 6 节点，此时「层和」最大为 3+5+1 = 9image.png

示例 3：

输入：root = [-5,1,7]

输出：8

解释：勇者不击破节点，「层和」最大为 1+7 = 8

提示：

2 <= 树中节点个数 <= 10^5
-10000 <= 树中节点的值 <= 10000
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getMaxLayerSum(TreeNode* root) {
        init();
        DFS1(root, 0);
        indices.resize(layerPresum.size(), 0);
        getNoPierceMaxSum();
        DFS2(root, 0);

        return maxSum;
    }

    void init() {
        maxSum = INT_MIN;
        indices.clear();
        layerPresum.clear();
        downLefts.clear();
        downRights.clear();
        visited.clear();
    }

    void DFS1(TreeNode* node, int layer) {  // 第一次DFS收集必要的信息
        if (node == NULL) {
            return;
        }

        if (layerPresum.size() == layer) {
            layerPresum.push_back({ 0 });
            downLefts.push_back({ 0 });
            downRights.push_back({ 0 });
        }

        layerPresum[layer].push_back(layerPresum[layer].back() + node->val);  // 更新该层的前缀和
        downLefts[layer].push_back(layerPresum.size() > layer + 1 ? (int)layerPresum[layer + 1].size() - 1 : 0);  // 当遍历到node节点时，下一层已经存在的节点不会随node上升

        DFS1(node->left, layer + 1);
        DFS1(node->right, layer + 1);

        downRights[layer].push_back(layerPresum.size() > layer + 1 ? (int)layerPresum[layer + 1].size() - 1 : 0);  // 当从node节点返回时，下一层已经存在的节点有可能随node上升
    }

    void DFS2(TreeNode* node, int layer) {  // 第二次DFS尝试戳破泡泡
        if (node == NULL) {
            return;
        }

        ++indices[layer];  // 遍历到node时，分配的index

        if (node->left == NULL || node->right == NULL) {  // 任何一个子节点为空可戳破
            pierce(layer, indices[layer], indices[layer]);
        }

        DFS2(node->left, layer + 1);
        DFS2(node->right, layer + 1);
    }

    void getNoPierceMaxSum() {
        for (auto& presum : layerPresum) {
            maxSum = max(maxSum, presum.back());
        }
    }

    void pierce(int layer, int left, int right) {
        long long key = getKey(layer, left, right);
        if (visited.count(key) != 0) {  // 如果已经戳破过该区段，不再尝试
            return;
        }

        int dLeft = downLefts[layer][left], dRight = downRights[layer][right];

        if (dLeft == dRight) {  // 没有下一层了，本层的sum减去戳破区段
            if ((int)layerPresum[layer].size() - 1 > right - left + 1) {  // 本层戳破以后，要还剩下泡泡才能更新sum，否则没有泡泡的sum = 0是没有意义的
                maxSum = max(maxSum, layerPresum[layer].back() - (layerPresum[layer][right] - layerPresum[layer][left - 1]));
            }
        }
        else {  // 下一层有泡泡要上升，本层的sum减去戳破区段，再加上下一层上升的区段
            maxSum = max(maxSum, layerPresum[layer].back() - (layerPresum[layer][right] - layerPresum[layer][left - 1]) + (layerPresum[layer + 1][dRight] - layerPresum[layer + 1][dLeft]));
            pierce(layer + 1, dLeft + 1, dRight);  // 有泡泡要上升的情况下，递归调用到下一层
        }

        visited.insert(key);
    }

    long long getKey(int layer, int left, int right) {
        return ((long long)layer << 40) | ((long long)left << 20) | right;
    }

    int maxSum = INT_MIN;
    vector<int> indices;  // 遍历到某一层时，节点在该层的索引，从1开始
    vector<vector<int>> layerPresum;  // 每一层的前缀和
    vector<vector<int>> downLefts;  // 对当前节点，下一层左边最后一个不随该节点被戳破而上升的节点
    vector<vector<int>> downRights;  // 对当前节点，下一层右边最后一个随该节点被戳破而上升的节点
    unordered_set<long long> visited;  // 记录已经计算过的被戳破的区段，这样的区段不会超过2n个
};

TreeNode* generate() {
    TreeNode* root = new TreeNode(1);
    TreeNode* cur = root;
    for (int i = 0; i < 39999; ++i) {
        cur->left = new TreeNode(1);
        cur = cur->left;
    }
    cur = root;
    for (int i = 0; i < 39999; ++i) {
        cur->right = new TreeNode(1);
        cur = cur->right;
    }
    cur = root;
    for (int i = 0; i < 39999; ++i) {
        cur = cur->left;
        if (i & 1) cur->right = new TreeNode(1);
    }
    return root;
}

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 6,0,3,INT_MIN,8 };
    check.checkInt(11, o.getMaxLayerSum(createTree(values)));

    values = { 5,6,2,4,INT_MIN,INT_MIN,1,3,5 };
    check.checkInt(9, o.getMaxLayerSum(createTree(values)));

    values = { -5,1,7 };
    check.checkInt(8, o.getMaxLayerSum(createTree(values)));

    values = { -1,INT_MIN,-2,INT_MIN,-3,INT_MIN,-4,INT_MIN,-5,INT_MIN,-6 };
    check.checkInt(-1, o.getMaxLayerSum(createTree(values)));

    values = { 1,0,-5,3,INT_MIN,INT_MIN,4,-1,INT_MIN,INT_MIN,6,4,-2 };
    check.checkInt(9, o.getMaxLayerSum(createTree(values)));

    values = { 5,6,2,4,INT_MIN,INT_MIN,1,3,5 };
    check.checkInt(9, o.getMaxLayerSum(createTree(values)));

    check.checkInt(3, o.getMaxLayerSum(generate()));
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
