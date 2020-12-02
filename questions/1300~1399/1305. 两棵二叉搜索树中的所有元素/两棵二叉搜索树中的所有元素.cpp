/* 两棵二叉搜索树中的所有元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你 root1 和 root2 这两棵二叉搜索树。

请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.

 

示例 1：



输入：root1 = [2,1,4], root2 = [1,0,3]
输出：[0,1,1,2,3,4]
示例 2：

输入：root1 = [0,-10,10], root2 = [5,1,7,0,2]
输出：[-10,0,0,1,2,5,7,10]
示例 3：

输入：root1 = [], root2 = [5,1,7,0,2]
输出：[0,1,2,5,7]
示例 4：

输入：root1 = [0,-10,10], root2 = []
输出：[-10,0,10]
示例 5：



输入：root1 = [1,null,8], root2 = [8,1]
输出：[1,1,8,8]
 

提示：

每棵树最多有 5000 个节点。
每个节点的值在 [-10^5, 10^5] 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> values1, values2;
        LDR(root1, values1);
        LDR(root2, values2);

        vector<int> allElements(values1.size() + values2.size());
        mergeSort(values1, values2, allElements);

        return allElements;
    }

    void LDR(TreeNode* root, vector<int>& values) {
        if (root != NULL) {
            LDR(root->left, values);
            values.push_back(root->val);
            LDR(root->right, values);
        }
    }

    void mergeSort(vector<int>& values1, vector<int>& values2, vector<int>& allElements) {
        int i = 0, j = 0, k = 0, size1 = values1.size(), size2 = values2.size();

        while (i < size1 && j < size2) {
            if (values1[i] < values2[j]) {
                allElements[k++] = values1[i++];
            }
            else {
                allElements[k++] = values2[j++];
            }
        }

        while (i < size1) {
            allElements[k++] = values1[i++];
        }

        while (j < size2) {
            allElements[k++] = values2[j++];
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values1 = { 2,1,4 };
    vector<int> values2 = { 1,0,3 };
    vector<int> actual = o.getAllElements(createTree(values1), createTree(values2));
    vector<int> expected = { 0,1,1,2,3,4 };
    check.checkIntVector(expected, actual);

    values1 = { 0,-10,10 };
    values2 = { 5,1,7,0,2 };
    actual = o.getAllElements(createTree(values1), createTree(values2));
    expected = { -10,0,0,1,2,5,7,10 };
    check.checkIntVector(expected, actual);

    values1 = {  };
    values2 = { 5,1,7,0,2 };
    actual = o.getAllElements(createTree(values1), createTree(values2));
    expected = { 0,1,2,5,7 };
    check.checkIntVector(expected, actual);

    values1 = { 0,-10,10 };
    values2 = {  };
    actual = o.getAllElements(createTree(values1), createTree(values2));
    expected = { -10,0,10 };
    check.checkIntVector(expected, actual);

    values1 = { 1,INT_MIN,8 };
    values2 = { 8,1 };
    actual = o.getAllElements(createTree(values1), createTree(values2));
    expected = { 1,1,8,8 };
    check.checkIntVector(expected, actual);

    values1 = { 1 };
    values2 = { 8 };
    actual = o.getAllElements(createTree(values1), createTree(values2));
    expected = { 1,8 };
    check.checkIntVector(expected, actual);
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
