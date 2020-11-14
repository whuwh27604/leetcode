/* 叶值的最小代价生成树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 arr，考虑所有满足以下条件的二叉树：

每个节点都有 0 个或是 2 个子节点。
数组 arr 中的值与树的中序遍历中每个叶节点的值一一对应。（知识回顾：如果一个节点有 0 个子节点，那么该节点为叶节点。）
每个非叶节点的值等于其左子树和右子树中叶节点的最大值的乘积。
在所有这样的二叉树中，返回每个非叶节点的值的最小可能总和。这个和的值是一个 32 位整数。

 

示例：

输入：arr = [6,2,4]
输出：32
解释：
有两种可能的树，第一种的非叶节点的总和为 36，第二种非叶节点的总和为 32。

    24            24
   /  \          /  \
  12   4        6    8
 /  \               / \
6    2             2   4
 

提示：

2 <= arr.length <= 40
1 <= arr[i] <= 15
答案保证是一个 32 位带符号整数，即小于 2^31。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-cost-tree-from-leaf-values
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int start = 0, end = 0, size = arr.size();
        vector<vector<int>> dp(size, vector<int>(size, INT_MAX));  // dp[start][end]表示arr[start,end]的最小非叶节点和

        while (end < size) {
            if (start == end) {
                dp[start][end] = 0;  // 只有一个元素时，只能是叶子节点，非叶节点和是0
            }
            else if (start + 1 == end) {
                dp[start][end] = arr[start] * arr[end];  // 两个元素时，只能是一个非叶节点的两个叶子节点，非叶节点和就是这两个叶子节点的乘积
            }
            else {  // 更多元素时，将数组划分为左右两个数组，必定存在一个root，它的左子树由左数组构成，右子树由右数组构成
                for (int split = start + 1; split <= end; ++split) {  // 遍历所有可能，找最小的非叶节点和
                    int i, leftMaxLeaf = 0, rightMaxLeaf = 0;  // 分别找到左右子树叶子的最大值

                    for (i = start; i < split; ++i) {
                        leftMaxLeaf = max(leftMaxLeaf, arr[i]);
                    }

                    for (i = split; i <= end; ++i) {
                        rightMaxLeaf = max(rightMaxLeaf, arr[i]);
                    }

                    int nonleafSum = leftMaxLeaf * rightMaxLeaf;  // root.val等于左右子树叶子最大值的乘积
                    nonleafSum += dp[start][split - 1];  // 左子树的最小非叶节点和
                    nonleafSum += dp[split][end];  // 右子树的最小非叶节点和
                    dp[start][end] = min(dp[start][end], nonleafSum);
                }
            }

            if (++end == size) {  // 左上往右下递推求解
                end = size - start;
                start = 0;
            }
            else {
                ++start;
            }
        }

        return dp[0][size - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 6,2,4 };
    check.checkInt(32, o.mctFromLeafValues(arr));

    arr = { 3,5 };
    check.checkInt(15, o.mctFromLeafValues(arr));

    arr = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    check.checkInt(2465, o.mctFromLeafValues(arr));
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
