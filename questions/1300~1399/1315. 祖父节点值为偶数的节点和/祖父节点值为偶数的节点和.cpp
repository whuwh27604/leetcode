/* 祖父节点值为偶数的节点和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵二叉树，请你返回满足以下条件的所有节点的值之和：

该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。）
如果不存在祖父节点值为偶数的节点，那么返回 0 。

 

示例：



输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
输出：18
解释：图中红色节点的祖父节点的值为偶数，蓝色节点为这些红色节点的祖父节点。
 

提示：

树中节点的数目在 1 到 10^4 之间。
每个节点的值在 1 到 100 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-nodes-with-even-valued-grandparent
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;

        DFS(root, 0, sum);

        return sum;
    }

    void DFS(TreeNode* root, unsigned int flag, int& sum) {
        if (root != NULL) {
            if ((flag & 0b10) != 0) {
                sum += root->val;
            }

            flag = ((flag << 1) | ((root->val & 1) == 1 ? 0 : 1));
            DFS(root->left, flag, sum);
            DFS(root->right, flag, sum);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 6,7,8,2,7,1,3,9,INT_MIN,1,4,INT_MIN,INT_MIN,INT_MIN,5 };
    check.checkInt(18, o.sumEvenGrandparent(createTree(values)));

    values = { 6 };
    check.checkInt(0, o.sumEvenGrandparent(createTree(values)));

    values = { 6,7,8 };
    check.checkInt(0, o.sumEvenGrandparent(createTree(values)));

    values = { 1,2,INT_MIN,3,INT_MIN,4,INT_MIN,5,INT_MIN,6,INT_MIN,7,INT_MIN,8,INT_MIN,9,INT_MIN,10 };
    check.checkInt(28, o.sumEvenGrandparent(createTree(values)));
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
