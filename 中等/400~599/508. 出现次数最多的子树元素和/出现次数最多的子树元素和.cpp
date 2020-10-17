/* 出现次数最多的子树元素和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二叉树的根结点，请你找出出现次数最多的子树元素和。一个结点的「子树元素和」定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。

你需要返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。

 

示例 1：
输入:

  5
 /  \
2   -3
返回 [2, -3, 4]，所有的值均只出现一次，以任意顺序返回所有值。

示例 2：
输入：

  5
 /  \
2   -5
返回 [2]，只有 2 出现两次，-5 只出现 1 次。

 

提示： 假设任意子树元素和均可以用 32 位有符号整数表示。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/most-frequent-subtree-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        unordered_map<int, int> sumFrequence;
        (void)LRD4Sum(root, sumFrequence);

        vector<int> mostFrequentSum;
        int mostFrequence = 0;

        for (auto iter = sumFrequence.begin(); iter != sumFrequence.end(); iter++) {
            if (iter->second > mostFrequence) {
                mostFrequentSum = { iter->first };
                mostFrequence = iter->second;
            }
            else if (iter->second == mostFrequence) {
                mostFrequentSum.push_back(iter->first);
            }
        }

        return mostFrequentSum;
    }

    int LRD4Sum(TreeNode* root, unordered_map<int, int>& sumFrequence) {
        int sumLeft = 0, sumRight = 0;

        if (root->left) {
            sumLeft = LRD4Sum(root->left, sumFrequence);
        }

        if (root->right) {
            sumRight = LRD4Sum(root->right, sumFrequence);
        }

        int sum = root->val + sumLeft + sumRight;
        auto iter = sumFrequence.find(sum);
        if (iter == sumFrequence.end()) {
            sumFrequence[sum] = 1;
        }
        else {
            iter->second++;
        }

        return sum;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.findFrequentTreeSum(NULL);
    vector<int> expected = {};
    check.checkIntVector(expected, actual);

    TreeNode node1(5);
    actual = o.findFrequentTreeSum(&node1);
    expected = { 5 };
    check.checkIntVector(expected, actual);

    node1.val = 0;
    TreeNode node2(5);
    node1.left = &node2;
    actual = o.findFrequentTreeSum(&node1);
    expected = { 5 };
    check.checkIntVector(expected, actual);

    node1.val = 5;
    node2.val = 0;
    node1.left = &node2;
    actual = o.findFrequentTreeSum(&node1);
    expected = { 0,5 };
    check.checkIntVector(expected, actual);

    node1.val = 5;
    node2.val = 2;
    TreeNode node3(-3);
    node1.left = &node2;
    node1.right = &node3;
    actual = o.findFrequentTreeSum(&node1);
    expected = { 2,-3,4 };
    check.checkIntVector(expected, actual);

    node1.val = 5;
    node2.val = 2;
    node3.val = -5;
    node1.left = &node2;
    node1.right = &node3;
    actual = o.findFrequentTreeSum(&node1);
    expected = { 2 };
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
