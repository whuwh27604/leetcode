/* 二叉树任务调度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
任务调度优化是计算机性能优化的关键任务之一。在任务众多时，不同的调度策略可能会得到不同的总体执行时间，因此寻求一个最优的调度方案是非常有必要的。

通常任务之间是存在依赖关系的，即对于某个任务，你需要先完成他的前导任务（如果非空），才能开始执行该任务。我们保证任务的依赖关系是一棵二叉树，其中 root 为根任务，root.left 和 root.right 为他的两个前导任务（可能为空），root.val 为其自身的执行时间。

在一个 CPU 核执行某个任务时，我们可以在任何时刻暂停当前任务的执行，并保留当前执行进度。在下次继续执行该任务时，会从之前停留的进度开始继续执行。暂停的时间可以不是整数。

现在，系统有两个 CPU 核，即我们可以同时执行两个任务，但是同一个任务不能同时在两个核上执行。给定这颗任务树，请求出所有任务执行完毕的最小时间。

示例 1：



输入：root = [47, 74, 31]

输出：121

解释：根节点的左右节点可以并行执行31分钟，剩下的43+47分钟只能串行执行，因此总体执行时间是121分钟。

示例 2：



输入：root = [15, 21, null, 24, null, 27, 26]

输出：87

示例 3：



输入：root = [1,3,2,null,null,4,4]

输出：7.5

限制：

1 <= 节点数量 <= 1000
1 <= 单节点执行时间 <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-ren-wu-diao-du
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double minimalExecTime(TreeNode* root) {
        /* 对任意树记总时间是t，并行时间是p，串行时间是s；左右子树分别是tl，pl，sl，tr，pr，sr
           1、串行时间s = t - 2 * p
           2、假设tl > tr，如果sl = tl - 2 * pl <= tr，最优策略是左子树先并行tl - tr的任务，此时左子树剩下tr，右子树剩下tr，可以一直并行。
              这样p取到最大值(tl + tr) / 2
           3、如果sl = tl - 2 * pl > tr，那么左子树的串行时间可以完全匹配右子树的所有任务还有剩余，此时p最大值为pl + tr
           4、ans = s + p = t - p = tl + tr + val - p
              p = max((tl + tr) / 2, pl + tr, pr + tl)
              ans = max((tl + tr) / 2, tl - pl, tr - pr) + val = max((tl + tr) / 2, ans(l), ans(r)) + val */

        pair<int, double> ans = DFS(root);

        return ans.second;
    }

    pair<int, double> DFS(TreeNode* root) {  // { t,ans }
        if (root == NULL) {
            return { 0,0 };
        }

        pair<int, double> left = DFS(root->left);
        pair<int, double> right = DFS(root->right);

        return { left.first + right.first + root->val, max({((double)left.first + right.first) / 2, left.second, right.second}) + root->val };
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 47,74,31 };
    check.checkDouble(121, o.minimalExecTime(createTree(values)));

    values = { 15,21,INT_MIN,24,INT_MIN,27,26 };
    check.checkDouble(87, o.minimalExecTime(createTree(values)));

    values = { 1,3,2,INT_MIN,INT_MIN,4,4 };
    check.checkDouble(7.5, o.minimalExecTime(createTree(values)));
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
