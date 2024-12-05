/* 二叉树灯饰.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
「力扣嘉年华」的中心广场放置了一个巨型的二叉树形状的装饰树。每个节点上均有一盏灯和三个开关。节点值为 0 表示灯处于「关闭」状态，节点值为 1 表示灯处于「开启」状态。每个节点上的三个开关各自功能如下：

开关 1：切换当前节点的灯的状态；
开关 2：切换 以当前节点为根 的子树中，所有节点上的灯的状态；
开关 3：切换 当前节点及其左右子节点（若存在的话） 上的灯的状态；
给定该装饰的初始状态 root，请返回最少需要操作多少次开关，可以关闭所有节点的灯。

示例 1：

输入：root = [1,1,0,null,null,null,1]
输出：2
解释：以下是最佳的方案之一，如图所示

示例 2：

输入：root = [1,1,1,1,null,null,1]
输出：1
解释：以下是最佳的方案，如图所示

示例 3：

输入：root = [0,null,0]
输出：0
解释：无需操作开关，当前所有节点上的灯均已关闭
提示：

1 <= 节点个数 <= 10^5
0 <= Node.val <= 1
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Oper {
public:
    int allOpen;  // 全开
    int allClose;  // 全关
    int openClose;  // 根节点开，其它关
    int closeOpen;  // 根节点关，其它开

    Oper() : allOpen(0), allClose(0), openClose(0), closeOpen(0) {}
};

class Solution {
public:
    int closeLampInTree(TreeNode* root) {
        return DFS(root).allClose;
    }

    Oper DFS(TreeNode* node) {
        Oper oper;
        
        if (node == NULL) {
            return oper;
        }

        Oper left = DFS(node->left);
        Oper right = DFS(node->right);

        if (node->val == 0) {
            oper.allClose = left.allClose + right.allClose;
            oper.allClose = min(oper.allClose, left.allOpen + right.allOpen + 2);
            oper.allClose = min(oper.allClose, left.openClose + right.openClose + 2);
            oper.allClose = min(oper.allClose, left.closeOpen + right.closeOpen + 2);
            oper.allOpen = left.allOpen + right.allOpen + 1;
            oper.allOpen = min(oper.allOpen, left.allClose + right.allClose + 1);
            oper.allOpen = min(oper.allOpen, left.openClose + right.openClose + 3);
            oper.allOpen = min(oper.allOpen, left.closeOpen + right.closeOpen + 1);
            oper.openClose = left.allClose + right.allClose + 1;
            oper.openClose = min(oper.openClose, left.allOpen + right.allOpen + 1);
            oper.openClose = min(oper.openClose, left.openClose + right.openClose + 1);
            oper.openClose = min(oper.openClose, left.closeOpen + right.closeOpen + 3);
            oper.closeOpen = left.allOpen + right.allOpen;
            oper.closeOpen = min(oper.closeOpen, left.allClose + right.allClose + 2);
            oper.closeOpen = min(oper.closeOpen, left.openClose + right.openClose + 2);
            oper.closeOpen = min(oper.closeOpen, left.closeOpen + right.closeOpen + 2);
        }
        else {
            oper.allClose = left.allClose + right.allClose + 1;
            oper.allClose = min(oper.allClose, left.allOpen + right.allOpen + 1);
            oper.allClose = min(oper.allClose, left.openClose + right.openClose + 1);
            oper.allClose = min(oper.allClose, left.closeOpen + right.closeOpen + 3);
            oper.allOpen = left.allOpen + right.allOpen;
            oper.allOpen = min(oper.allOpen, left.allClose + right.allClose + 2);
            oper.allOpen = min(oper.allOpen, left.openClose + right.openClose + 2);
            oper.allOpen = min(oper.allOpen, left.closeOpen + right.closeOpen + 2);
            oper.openClose = left.allClose + right.allClose;
            oper.openClose = min(oper.openClose, left.allOpen + right.allOpen + 2);
            oper.openClose = min(oper.openClose, left.openClose + right.openClose + 2);
            oper.openClose = min(oper.openClose, left.closeOpen + right.closeOpen + 2);
            oper.closeOpen = left.allOpen + right.allOpen + 1;
            oper.closeOpen = min(oper.closeOpen, left.allClose + right.allClose + 1);
            oper.closeOpen = min(oper.closeOpen, left.openClose + right.openClose + 3);
            oper.closeOpen = min(oper.closeOpen, left.closeOpen + right.closeOpen + 1);
        }

        return oper;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 1,1,0,INT_MIN,INT_MIN,INT_MIN,1 };
    check.checkInt(2, o.closeLampInTree(createTree(values)));

    values = { 1,1,1,1,INT_MIN,INT_MIN,1 };
    check.checkInt(1, o.closeLampInTree(createTree(values)));

    values = { 0,INT_MIN,0 };
    check.checkInt(0, o.closeLampInTree(createTree(values)));
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
