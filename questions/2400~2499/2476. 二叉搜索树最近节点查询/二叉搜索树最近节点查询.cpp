/* 二叉搜索树最近节点查询.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 二叉搜索树 的根节点 root ，和一个由正整数组成、长度为 n 的数组 queries 。

请你找出一个长度为 n 的 二维 答案数组 answer ，其中 answer[i] = [mini, maxi] ：

mini 是树中小于等于 queries[i] 的 最大值 。如果不存在这样的值，则使用 -1 代替。
maxi 是树中大于等于 queries[i] 的 最小值 。如果不存在这样的值，则使用 -1 代替。
返回数组 answer 。



示例 1 ：



输入：root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], queries = [2,5,16]
输出：[[2,2],[4,6],[15,-1]]
解释：按下面的描述找出并返回查询的答案：
- 树中小于等于 2 的最大值是 2 ，且大于等于 2 的最小值也是 2 。所以第一个查询的答案是 [2,2] 。
- 树中小于等于 5 的最大值是 4 ，且大于等于 5 的最小值是 6 。所以第二个查询的答案是 [4,6] 。
- 树中小于等于 16 的最大值是 15 ，且大于等于 16 的最小值不存在。所以第三个查询的答案是 [15,-1] 。
示例 2 ：



输入：root = [4,null,9], queries = [3]
输出：[[-1,4]]
解释：树中不存在小于等于 3 的最大值，且大于等于 3 的最小值是 4 。所以查询的答案是 [-1,4] 。


提示：

树中节点的数目在范围 [2, 105] 内
1 <= Node.val <= 106
n == queries.length
1 <= n <= 105
1 <= queries[i] <= 106
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> values;
        vector<vector<int>> ans;

        getValues(root, values);

        for (int query : queries) {
            vector<int> res(2);
            auto iter = lower_bound(values.begin(), values.end(), query);
            res[1] = iter == values.end() ? -1 : *iter;
            if (iter == values.end()) {
                res[0] = *(--iter);
            }
            else {
                if (*iter == query) {
                    res[0] = query;
                }
                else {
                    res[0] = iter == values.begin() ? -1 : *(--iter);
                }
            }

            ans.push_back(res);
        }

        return ans;
    }

    void getValues(TreeNode* root, vector<int>& values) {
        if (root != NULL) {
            getValues(root->left, values);
            values.push_back(root->val);
            getValues(root->right, values);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 6,2,13,1,4,9,15,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,14 };
    vector<int> queries = { 2,5,16 };
    vector<vector<int>> actual = o.closestNodes(createTree(values), queries);
    vector<vector<int>> expected = { {2,2},{4,6},{15,-1} };
    check.checkIntVectorVector(expected, actual);

    values = { 4,INT_MIN,9 };
    queries = { 3 };
    actual = o.closestNodes(createTree(values), queries);
    expected = { {-1,4} };
    check.checkIntVectorVector(expected, actual);
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
