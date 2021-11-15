/* 每棵子树内缺失的最小基因值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一棵根节点为 0 的 家族树 ，总共包含 n 个节点，节点编号为 0 到 n - 1 。给你一个下标从 0 开始的整数数组 parents ，其中 parents[i] 是节点 i 的父节点。由于节点 0 是 根 ，所以 parents[0] == -1 。

总共有 105 个基因值，每个基因值都用 闭区间 [1, 105] 中的一个整数表示。给你一个下标从 0 开始的整数数组 nums ，其中 nums[i] 是节点 i 的基因值，且基因值 互不相同 。

请你返回一个数组 ans ，长度为 n ，其中 ans[i] 是以节点 i 为根的子树内 缺失 的 最小 基因值。

节点 x 为根的 子树 包含节点 x 和它所有的 后代 节点。

 

示例 1：



输入：parents = [-1,0,0,2], nums = [1,2,3,4]
输出：[5,1,1,1]
解释：每个子树答案计算结果如下：
- 0：子树包含节点 [0,1,2,3] ，基因值分别为 [1,2,3,4] 。5 是缺失的最小基因值。
- 1：子树只包含节点 1 ，基因值为 2 。1 是缺失的最小基因值。
- 2：子树包含节点 [2,3] ，基因值分别为 [3,4] 。1 是缺失的最小基因值。
- 3：子树只包含节点 3 ，基因值为 4 。1是缺失的最小基因值。
示例 2：



输入：parents = [-1,0,1,0,3,3], nums = [5,4,6,2,1,3]
输出：[7,1,1,4,2,1]
解释：每个子树答案计算结果如下：
- 0：子树内包含节点 [0,1,2,3,4,5] ，基因值分别为 [5,4,6,2,1,3] 。7 是缺失的最小基因值。
- 1：子树内包含节点 [1,2] ，基因值分别为 [4,6] 。 1 是缺失的最小基因值。
- 2：子树内只包含节点 2 ，基因值为 6 。1 是缺失的最小基因值。
- 3：子树内包含节点 [3,4,5] ，基因值分别为 [2,1,3] 。4 是缺失的最小基因值。
- 4：子树内只包含节点 4 ，基因值为 1 。2 是缺失的最小基因值。
- 5：子树内只包含节点 5 ，基因值为 3 。1 是缺失的最小基因值。
示例 3：

输入：parents = [-1,2,3,0,2,4,1], nums = [2,3,4,5,6,7,8]
输出：[1,1,1,1,1,1,1]
解释：所有子树都缺失基因值 1 。
 

提示：

n == parents.length == nums.length
2 <= n <= 105
对于 i != 0 ，满足 0 <= parents[i] <= n - 1
parents[0] == -1
parents 表示一棵合法的树。
1 <= nums[i] <= 105
nums[i] 互不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-missing-genetic-value-in-each-subtree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size(), node = 0, minMissing = 1;
        vector<vector<int>> children(n);
        vector<int> minMissings(n, 1);
        vector<bool> visited(n, false);
        vector<bool> isMissing(100001, true);

        getChildren(n, parents, children);

        for (node = 0; node < n && nums[node] != 1; ++node) {}

        if (node != n) {
            while (node != -1) {
                DFS(node, children, nums, visited, isMissing);

                while (!isMissing[minMissing]) {
                    ++minMissing;
                }

                minMissings[node] = minMissing;
                node = parents[node];
            }
        }        

        return minMissings;
    }

    void getChildren(int n, vector<int>& parents, vector<vector<int>>& children) {
        for (int i = 1; i < n; ++i) {
            children[parents[i]].push_back(i);
        }
    }

    void DFS(int node, vector<vector<int>>& children, vector<int>& nums, vector<bool>& visited, vector<bool>& isMissing) {
        if (!visited[node]) {
            visited[node] = true;
            isMissing[nums[node]] = false;

            for (int next : children[node]) {
                DFS(next, children, nums, visited, isMissing);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> parents = { -1,0,0,2 };
    vector<int> nums = { 1,2,3,4 };
    vector<int> actual = o.smallestMissingValueSubtree(parents, nums);
    vector<int> expected = { 5,1,1,1 };
    check.checkIntVector(expected, actual);

    parents = { -1,0,1,0,3,3 };
    nums = { 5,4,6,2,1,3 };
    actual = o.smallestMissingValueSubtree(parents, nums);
    expected = { 7,1,1,4,2,1 };
    check.checkIntVector(expected, actual);

    parents = { -1,2,3,0,2,4,1 };
    nums = { 2,3,4,5,6,7,8 };
    actual = o.smallestMissingValueSubtree(parents, nums);
    expected = { 1,1,1,1,1,1,1 };
    check.checkIntVector(expected, actual);

    parents = { -1,0,0,0,2 };
    nums = { 6,4,3,2,1 };
    actual = o.smallestMissingValueSubtree(parents, nums);
    expected = { 5,1,2,1,2 };
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
