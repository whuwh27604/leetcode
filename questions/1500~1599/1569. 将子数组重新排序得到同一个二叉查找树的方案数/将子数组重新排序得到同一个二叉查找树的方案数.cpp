/* 将子数组重新排序得到同一个二叉查找树的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 nums 表示 1 到 n 的一个排列。我们按照元素在 nums 中的顺序依次插入一个初始为空的二叉查找树（BST）。请你统计将 nums 重新排序后，统计满足如下条件的方案数：重排后得到的二叉查找树与 nums 原本数字顺序得到的二叉查找树相同。

比方说，给你 nums = [2,1,3]，我们得到一棵 2 为根，1 为左孩子，3 为右孩子的树。数组 [2,3,1] 也能得到相同的 BST，但 [3,2,1] 会得到一棵不同的 BST 。

请你返回重排 nums 后，与原数组 nums 得到相同二叉查找树的方案数。

由于答案可能会很大，请将结果对 10^9 + 7 取余数。

 

示例 1：



输入：nums = [2,1,3]
输出：1
解释：我们将 nums 重排， [2,3,1] 能得到相同的 BST 。没有其他得到相同 BST 的方案了。
示例 2：



输入：nums = [3,4,5,1,2]
输出：5
解释：下面 5 个数组会得到相同的 BST：
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]
示例 3：



输入：nums = [1,2,3]
输出：0
解释：没有别的排列顺序能得到相同的 BST 。
示例 4：



输入：nums = [3,1,2,5,4,6]
输出：19
示例  5：

输入：nums = [9,4,2,1,3,6,5,7,8,14,11,10,12,13,16,15,17,18]
输出：216212978
解释：得到相同 BST 的方案数是 3216212999。将它对 10^9 + 7 取余后得到 216212978。
 

提示：

1 <= nums.length <= 1000
1 <= nums[i] <= nums.length
nums 中所有数 互不相同 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-ways-to-reorder-array-to-get-same-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class BSTNode {
public:
    int val;
    BSTNode* left;
    BSTNode* right;
    BSTNode() : val(0), left(NULL), right(NULL) {}
    BSTNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size() + 1;
        vector<int> factorial(n);
        vector<int> inverse(n);
        vector<int> count(n, 0);  // 对每一个节点，需要统计以它为根的子树有多少个节点
        vector<int> ways(n);  // 对每一个节点，需要统计以它为根的子树构筑的方法数
        vector<vector<int>> edges(n);

        /* 1、n1个x、n2个y、n3个z...的排列方法数是(n1 + n2 + n3 + ...)! / (n1! * n2! * n3! * ...)
           2、对任意节点node，它有子节点c1、c2、c3...，构筑方法记为ways，以节点为根的子树节点个数记为count，
              首先认为子树内的节点是一样的，那么可以根据1计算出排列数；然后每个子树内的节点有ways[c1/c2/c3...]种排列，所以总的排列数就是以上相乘，
              即 (count[c1] + count[c2] + count[c3] + ...)! / (count[c1]! * count[c2]! * count[c3]! * ...) * ways[c1]! * ways[c2]! * ways[c3]! * ...。
           3、除法取模转换为乘法逆元 */

        calcFactorials(n, factorial, inverse);
        BSTNode* root = buildTree(nums);
        DFS(root, factorial, inverse, count, ways);

        return (ways[nums[0]] - 1 + mod) % mod;
    }

    void calcFactorials(int n, vector<int>& factorial, vector<int>& inverse) {
        long long num = 1;
        factorial[0] = inverse[0] = 1;

        for (int i = 1; i < n; ++i) {
            num = (num * i) % mod;
            factorial[i] = (int)num;
            inverse[i] = fastPower(factorial[i], mod - 2);
        }
    }

    int fastPower(int x, int n) {
        long long ans = 1;
        int bit = 1;

        while (n != 0) {
            if ((n & bit) != 0) {
                ans = (ans * x) % mod;
            }

            n &= ~bit;
            bit <<= 1;
            x = ((long long)x * x) % mod;
        }

        return (int)ans;
    }

    BSTNode* buildTree(vector<int>& nums) {
        BSTNode* root = new BSTNode(nums[0]);

        for (int i = 1; i < (int)nums.size(); ++i) {
            BSTNode* current = root;
            int num = nums[i];

            while (current != NULL) {
                if (current->val < num) {
                    if (current->left == NULL) {
                        current->left = new BSTNode(num);
                        current = NULL;
                    }
                    else {
                        current = current->left;
                    }
                }
                else {
                    if (current->right == NULL) {
                        current->right = new BSTNode(num);
                        current = NULL;
                    }
                    else {
                        current = current->right;
                    }
                }
            }
        }

        return root;
    }

    void DFS(BSTNode* root, vector<int>& factorial, vector<int>& inverse, vector<int>& count, vector<int>& ways) {
        ways[root->val] = 1;

        if (root->left != NULL) {
            DFS(root->left, factorial, inverse, count, ways);
            count[root->val] += count[root->left->val];
            ways[root->val] = (long long)ways[root->val] * ways[root->left->val] % mod * inverse[count[root->left->val]] % mod;
        }

        if (root->right != NULL) {
            DFS(root->right, factorial, inverse, count, ways);
            count[root->val] += count[root->right->val];
            ways[root->val] = (long long)ways[root->val] * ways[root->right->val] % mod * inverse[count[root->right->val]] % mod;
        }

        ways[root->val] = (long long)ways[root->val] * factorial[count[root->val]] % mod;
        count[root->val] += 1;
    }

private:
    int mod = 1000000007;
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,1,3 };
    check.checkInt(1, o.numOfWays(nums));

    nums = { 3,4,5,1,2 };
    check.checkInt(5, o.numOfWays(nums));

    nums = { 1,2,3 };
    check.checkInt(0, o.numOfWays(nums));

    nums = { 3,1,2,5,4,6 };
    check.checkInt(19, o.numOfWays(nums));

    nums = { 9,4,2,1,3,6,5,7,8,14,11,10,12,13,16,15,17,18 };
    check.checkInt(216212978, o.numOfWays(nums));

    nums = { 1 };
    check.checkInt(0, o.numOfWays(nums));
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
