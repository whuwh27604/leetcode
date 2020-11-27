/* 在受污染的二叉树中查找元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出一个满足下述规则的二叉树：

root.val == 0
如果 treeNode.val == x 且 treeNode.left != null，那么 treeNode.left.val == 2 * x + 1
如果 treeNode.val == x 且 treeNode.right != null，那么 treeNode.right.val == 2 * x + 2
现在这个二叉树受到「污染」，所有的 treeNode.val 都变成了 -1。

请你先还原二叉树，然后实现 FindElements 类：

FindElements(TreeNode* root) 用受污染的二叉树初始化对象，你需要先把它还原。
bool find(int target) 判断目标值 target 是否存在于还原后的二叉树中并返回结果。
 

示例 1：



输入：
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
输出：
[null,false,true]
解释：
FindElements findElements = new FindElements([-1,null,-1]);
findElements.find(1); // return False
findElements.find(2); // return True
示例 2：



输入：
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
输出：
[null,true,true,false]
解释：
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False
示例 3：



输入：
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
输出：
[null,true,false,false,true]
解释：
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True
 

提示：

TreeNode.val == -1
二叉树的高度不超过 20
节点的总数在 [1, 10^4] 之间
调用 find() 的总次数在 [1, 10^4] 之间
0 <= target <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-elements-in-a-contaminated-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class FindElements {
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        DFS(root);
    }

    void DFS(TreeNode* root) {
        values.insert(root->val);

        if (root->left != NULL) {
            root->left->val = 2 * root->val + 1;
            DFS(root->left);
        }

        if (root->right != NULL) {
            root->right->val = 2 * root->val + 2;
            DFS(root->right);
        }
    }

    bool find(int target) {
        return values.count(target) == 1;
    }

private:
    unordered_set<int> values;
};

int main()
{
    CheckResult check;

    vector<int> values = { -1,INT_MIN,-1 };
    FindElements o1(createTree(values));
    check.checkBool(true, o1.find(0));
    check.checkBool(false, o1.find(1));
    check.checkBool(true, o1.find(2));

    values = { -1,-1,-1,-1,-1 };
    FindElements o2(createTree(values));
    check.checkBool(true, o2.find(0));
    check.checkBool(true, o2.find(1));
    check.checkBool(true, o2.find(2));
    check.checkBool(true, o2.find(3));
    check.checkBool(true, o2.find(4));
    check.checkBool(false, o2.find(5));
    check.checkBool(false, o2.find(6));

    values = { -1,INT_MIN,-1,-1,INT_MIN,-1 };
    FindElements o3(createTree(values));
    check.checkBool(true, o3.find(0));
    check.checkBool(true, o3.find(2));
    check.checkBool(true, o3.find(5));
    check.checkBool(true, o3.find(11));
    check.checkBool(false, o3.find(1));
    check.checkBool(false, o3.find(3));
    check.checkBool(false, o3.find(8));
    check.checkBool(false, o3.find(12));

    values = { -1 };
    FindElements o4(createTree(values));
    check.checkBool(true, o4.find(0));
    check.checkBool(false, o4.find(1));
    check.checkBool(false, o4.find(2));
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
