/* 感染二叉树需要的总时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵二叉树的根节点 root ，二叉树中节点的值 互不相同 。另给你一个整数 start 。在第 0 分钟，感染 将会从值为 start 的节点开始爆发。

每分钟，如果节点满足以下全部条件，就会被感染：

节点此前还没有感染。
节点与一个已感染节点相邻。
返回感染整棵树需要的分钟数。

 

示例 1：


输入：root = [1,5,3,null,4,10,6,9,2], start = 3
输出：4
解释：节点按以下过程被感染：
- 第 0 分钟：节点 3
- 第 1 分钟：节点 1、10、6
- 第 2 分钟：节点5
- 第 3 分钟：节点 4
- 第 4 分钟：节点 9 和 2
感染整棵树需要 4 分钟，所以返回 4 。
示例 2：


输入：root = [1], start = 1
输出：0
解释：第 0 分钟，树中唯一一个节点处于感染状态，返回 0 。
 

提示：

树中节点的数目在范围 [1, 105] 内
1 <= Node.val <= 105
每个节点的值 互不相同
树中必定存在值为 start 的节点

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> adjs(100001);

        getAdjs(root, -1, adjs);

        return BFS(adjs, start);
    }

    void getAdjs(TreeNode* node, int parent, vector<vector<int>>& adjs) {
        if (parent != -1) {
            adjs[node->val].push_back(parent);
        }

        if (node->left != NULL) {
            adjs[node->val].push_back(node->left->val);
            getAdjs(node->left, node->val, adjs);
        }

        if (node->right != NULL) {
            adjs[node->val].push_back(node->right->val);
            getAdjs(node->right, node->val, adjs);
        }
    }

    int BFS(vector<vector<int>>& adjs, int start) {
        vector<bool> visited(100001, false);
        visited[start] = true;
        queue<int> bfs;
        bfs.push(start);
        int minutes = -1;

        while (!bfs.empty()) {
            ++minutes;
            int i, size = bfs.size();

            for (i = 0; i < size; ++i) {
                int node = bfs.front();
                bfs.pop();

                for (int next : adjs[node]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        bfs.push(next);
                    }
                }
            }
        }

        return minutes;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,5,3,INT_MIN,4,10,6,9,2 };
    check.checkInt(4, o.amountOfTime(createTree(values), 3));

    values = { 1 };
    check.checkInt(0, o.amountOfTime(createTree(values), 1));
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
