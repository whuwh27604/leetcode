/* 从二叉树一个节点到另一个节点每一步的方向.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵 二叉树 的根节点 root ，这棵二叉树总共有 n 个节点。每个节点的值为 1 到 n 中的一个整数，且互不相同。给你一个整数 startValue ，表示起点节点 s 的值，和另一个不同的整数 destValue ，表示终点节点 t 的值。

请找到从节点 s 到节点 t 的 最短路径 ，并以字符串的形式返回每一步的方向。每一步用 大写 字母 'L' ，'R' 和 'U' 分别表示一种方向：

'L' 表示从一个节点前往它的 左孩子 节点。
'R' 表示从一个节点前往它的 右孩子 节点。
'U' 表示从一个节点前往它的 父 节点。
请你返回从 s 到 t 最短路径 每一步的方向。

 

示例 1：



输入：root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
输出："UURL"
解释：最短路径为：3 → 1 → 5 → 2 → 6 。
示例 2：



输入：root = [2,1], startValue = 2, destValue = 1
输出："L"
解释：最短路径为：2 → 1 。
 

提示：

树中节点数目为 n 。
2 <= n <= 105
1 <= Node.val <= n
树中所有节点的值 互不相同 。
1 <= startValue, destValue <= n
startValue != destValue

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<int> path, startPath, destPath;

        DFS(root, 0, path, startValue, destValue, startPath, destPath);

        return getDirections(startPath, destPath);
    }

    void DFS(TreeNode* root, int dir, vector<int>& path, int startValue, int destValue, vector<int>& startPath, vector<int>& destPath) {
        if (root == NULL) {
            return;
        }

        path.push_back(dir + root->val);

        if (root->val == startValue) {
            startPath = path;
        }

        if (root->val == destValue) {
            destPath = path;
        }

        if (!startPath.empty() && !destPath.empty()) {
            return;
        }

        DFS(root->left, dirLeft, path, startValue, destValue, startPath, destPath);
        DFS(root->right, dirRight, path, startValue, destValue, startPath, destPath);
        path.pop_back();
    }

    string getDirections(vector<int>& startPath, vector<int>& destPath) {
        string directions;
        int i, startSize = startPath.size(), destSize = destPath.size();

        for (i = 0; i < startSize && i < destSize && startPath[i] == destPath[i]; ++i) {}

        if (i == startSize) {
            for (; i < destSize; ++i) {
                directions += ((destPath[i] & dirLeft) == 0 ? 'R' : 'L');
            }
        }
        else if (i == destSize) {
            directions += string(startSize - i, 'U');
        }
        else {
            directions += string(startSize - i, 'U');

            for (; i < destSize; ++i) {
                directions += ((destPath[i] & dirLeft) == 0 ? 'R' : 'L');
            }
        }

        return directions;
    }

private:
    int dirLeft = (1 << 24);
    int dirRight = (1 << 25);
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 5,1,2,3,INT_MIN,6,4 };
    check.checkString("UURL", o.getDirections(createTree(values), 3, 6));

    values = { 5,1,2,3,INT_MIN,6,4 };
    check.checkString("UULL", o.getDirections(createTree(values), 6, 3));

    values = { 5,1,2,3,INT_MIN,6,4 };
    check.checkString("URR", o.getDirections(createTree(values), 1, 4));

    values = { 5,1,2,3,INT_MIN,6,4 };
    check.checkString("ULL", o.getDirections(createTree(values), 2, 3));

    values = { 5,1,2,3,INT_MIN,6,4 };
    check.checkString("LL", o.getDirections(createTree(values), 5, 3));

    values = { 5,1,2,3,INT_MIN,6,4 };
    check.checkString("RR", o.getDirections(createTree(values), 5, 4));

    values = { 5,1,2,3,INT_MIN,6,4 };
    check.checkString("RL", o.getDirections(createTree(values), 5, 6));

    values = { 2,1 };
    check.checkString("L", o.getDirections(createTree(values), 2, 1));

    values = { 2,1 };
    check.checkString("U", o.getDirections(createTree(values), 1, 2));
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
