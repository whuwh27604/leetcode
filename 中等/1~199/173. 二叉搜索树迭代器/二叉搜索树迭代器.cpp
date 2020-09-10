// 二叉搜索树迭代器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        index = 0;

        if (root == NULL) {
            return;
        }
        LDR(root, values);
    }

    /** @return the next smallest number */
    int next() {
        return values[index++];
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (index <= ((int)values.size() - 1));
    }

    void LDR(TreeNode* root, vector<int>& values) {
        if (root->left != NULL) {
            LDR(root->left, values);
        }

        values.push_back(root->val);

        if (root->right != NULL) {
            LDR(root->right, values);
        }
    }

    vector<int> values;
    int index;
};

int main()
{
    CheckResult check;

    BSTIterator o(NULL);
    check.checkBool(false, o.hasNext());

    TreeNode node1(1);
    BSTIterator o1(&node1);
    check.checkBool(true, o1.hasNext());
    check.checkInt(1, o1.next());
    check.checkBool(false, o1.hasNext());

    TreeNode node2(2);
    node1.right = &node2;
    BSTIterator o2(&node1);
    check.checkBool(true, o2.hasNext());
    check.checkInt(1, o2.next());
    check.checkBool(true, o2.hasNext());
    check.checkInt(2, o2.next());
    check.checkBool(false, o2.hasNext());

    TreeNode node3(3);
    node1.val = 2;
    node2.val = 1;
    node1.left = &node2;
    node1.right = &node3;
    BSTIterator o3(&node1);
    check.checkBool(true, o3.hasNext());
    check.checkInt(1, o3.next());
    check.checkBool(true, o3.hasNext());
    check.checkInt(2, o3.next());
    check.checkBool(true, o3.hasNext());
    check.checkInt(3, o3.next());
    check.checkBool(false, o3.hasNext());

    TreeNode node4(9);
    TreeNode node5(20);
    node1.val = 7;
    node2.val = 3;
    node3.val = 15;
    node1.left = &node2;
    node1.right = &node3;
    node3.left = &node4;
    node3.right = &node5;
    BSTIterator o4(&node1);
    check.checkBool(true, o4.hasNext());
    check.checkInt(3, o4.next());
    check.checkBool(true, o4.hasNext());
    check.checkInt(7, o4.next());
    check.checkBool(true, o4.hasNext());
    check.checkInt(9, o4.next());
    check.checkBool(true, o4.hasNext());
    check.checkInt(15, o4.next());
    check.checkBool(true, o4.hasNext());
    check.checkInt(20, o4.next());
    check.checkBool(false, o4.hasNext());
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
