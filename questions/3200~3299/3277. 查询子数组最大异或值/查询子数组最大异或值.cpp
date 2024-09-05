/* 查询子数组最大异或值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由 n 个整数组成的数组 nums，以及一个大小为 q 的二维整数数组 queries，其中 queries[i] = [li, ri]。

对于每一个查询，你需要找出 nums[li..ri] 中任意
子数组
 的 最大异或值。

数组的异或值 需要对数组 a 反复执行以下操作，直到只剩一个元素，剩下的那个元素就是 异或值：

对于除最后一个下标以外的所有下标 i，同时将 a[i] 替换为 a[i] XOR a[i + 1] 。
移除数组的最后一个元素。
返回一个大小为 q 的数组 answer，其中 answer[i] 表示查询 i 的答案。



示例 1：

输入： nums = [2,8,4,32,16,1], queries = [[0,2],[1,4],[0,5]]

输出： [12,60,60]

解释：

在第一个查询中，nums[0..2] 的子数组分别是 [2], [8], [4], [2, 8], [8, 4], 和 [2, 8, 4]，它们的异或值分别为 2, 8, 4, 10, 12, 和 6。查询的答案是 12，所有异或值中的最大值。

在第二个查询中，nums[1..4] 的子数组中最大的异或值是子数组 nums[1..4] 的异或值，为 60。

在第三个查询中，nums[0..5] 的子数组中最大的异或值是子数组 nums[1..4] 的异或值，为 60。

示例 2：

输入： nums = [0,7,3,2,8,5,1], queries = [[0,3],[1,5],[2,4],[2,6],[5,6]]

输出： [7,14,11,14,5]

解释：

下标	nums[li..ri]	最大异或值子数组	子数组最大异或值
0	[0, 7, 3, 2]	[7]	7
1	[7, 3, 2, 8, 5]	[7, 3, 2, 8]	14
2	[3, 2, 8]	[3, 2, 8]	11
3	[3, 2, 8, 5, 1]	[2, 8, 5, 1]	14
4	[5, 1]	[5]	5


提示：

1 <= n == nums.length <= 2000
0 <= nums[i] <= 231 - 1
1 <= q == queries.length <= 105
queries[i].length == 2
queries[i] = [li, ri]
0 <= li <= ri <= n - 1
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = (int)nums.size(), m = (int)queries.size();
        vector<vector<int>> xorVals(n, vector<int>(n, 0)), maxVals(n, vector<int>(n, 0));
        vector<int> ans(m);

        getXorValues(n, nums, xorVals);
        getMaxValues(n, xorVals, maxVals);
        getMaxSubXor(m, queries, maxVals, ans);

        return ans;
    }

    void getXorValues(int n, vector<int>& nums, vector<vector<int>>& xorVals) {
        for (int i = 0; i < n; ++i) {
            xorVals[i][i] = nums[i];
        }

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                int j = i + len - 1;
                xorVals[i][j] = xorVals[i][j - 1] ^ xorVals[i + 1][j];
            }
        }
    }

    void getMaxValues(int n, vector<vector<int>>& xorVals, vector<vector<int>>& maxVals) {
        for (int i = 0; i < n; ++i) {
            maxVals[i][i] = xorVals[i][i];
        }

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                int j = i + len - 1;
                maxVals[i][j] = max({ xorVals[i][j],maxVals[i + 1][j],maxVals[i][j - 1] });
            }
        }
    }

    void getMaxSubXor(int m, vector<vector<int>>& queries, vector<vector<int>>& maxVals, vector<int>& ans) {
        for (int i = 0; i < m; ++i) {
            ans[i] = maxVals[queries[i][0]][queries[i][1]];
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2,8,4,32,16,1 };
    vector<vector<int>> queries = { {0,2},{1,4},{0,5} };
    vector<int> actual = o.maximumSubarrayXor(nums, queries);
    vector<int> expected = { 12,60,60 };
    check.checkIntVector(expected, actual);
    
    nums = { 0,7,3,2,8,5,1 };
    queries = { {0,3},{1,5},{2,4},{2,6},{5,6} };
    actual = o.maximumSubarrayXor(nums, queries);
    expected = { 7,14,11,14,5 };
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
