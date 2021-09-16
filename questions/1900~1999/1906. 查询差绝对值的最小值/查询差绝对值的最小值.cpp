/* 查询差绝对值的最小值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个数组 a 的 差绝对值的最小值 定义为：0 <= i < j < a.length 且 a[i] != a[j] 的 |a[i] - a[j]| 的 最小值。如果 a 中所有元素都 相同 ，那么差绝对值的最小值为 -1 。

比方说，数组 [5,2,3,7,2] 差绝对值的最小值是 |2 - 3| = 1 。注意答案不为 0 ，因为 a[i] 和 a[j] 必须不相等。
给你一个整数数组 nums 和查询数组 queries ，其中 queries[i] = [li, ri] 。对于每个查询 i ，计算 子数组 nums[li...ri] 中 差绝对值的最小值 ，子数组 nums[li...ri] 包含 nums 数组（下标从 0 开始）中下标在 li 和 ri 之间的所有元素（包含 li 和 ri 在内）。

请你返回 ans 数组，其中 ans[i] 是第 i 个查询的答案。

子数组 是一个数组中连续的一段元素。

|x| 的值定义为：

如果 x >= 0 ，那么值为 x 。
如果 x < 0 ，那么值为 -x 。
 

示例 1：

输入：nums = [1,3,4,8], queries = [[0,1],[1,2],[2,3],[0,3]]
输出：[2,1,4,1]
解释：查询结果如下：
- queries[0] = [0,1]：子数组是 [1,3] ，差绝对值的最小值为 |1-3| = 2 。
- queries[1] = [1,2]：子数组是 [3,4] ，差绝对值的最小值为 |3-4| = 1 。
- queries[2] = [2,3]：子数组是 [4,8] ，差绝对值的最小值为 |4-8| = 4 。
- queries[3] = [0,3]：子数组是 [1,3,4,8] ，差的绝对值的最小值为 |3-4| = 1 。
示例 2：

输入：nums = [4,5,2,2,7,10], queries = [[2,3],[0,2],[0,5],[3,5]]
输出：[-1,1,1,3]
解释：查询结果如下：
- queries[0] = [2,3]：子数组是 [2,2] ，差绝对值的最小值为 -1 ，因为所有元素相等。
- queries[1] = [0,2]：子数组是 [4,5,2] ，差绝对值的最小值为 |4-5| = 1 。
- queries[2] = [0,5]：子数组是 [4,5,2,2,7,10] ，差绝对值的最小值为 |4-5| = 1 。
- queries[3] = [3,5]：子数组是 [2,7,10] ，差绝对值的最小值为 |7-10| = 3 。
 

提示：

2 <= nums.length <= 105
1 <= nums[i] <= 100
1 <= queries.length <= 2 * 104
0 <= li < ri < nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-absolute-difference-queries
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int index = 0;
        vector<int> ans(queries.size());

        vector<vector<int>> countPresum(101, vector<int>(nums.size() + 1, 0));
        getCountPresum(nums, countPresum);

        for (auto& query : queries) {
            int prev = -1, minDiff = INT_MAX;

            for (int num = 1; num < 101; ++num) {
                if (countPresum[num][query[1] + 1] != countPresum[num][query[0]]) {  // num在查询区间出现过
                    if (prev != -1) {
                        minDiff = min(minDiff, num - prev);
                    }

                    prev = num;
                }
            }

            ans[index++] = minDiff == INT_MAX ? -1 : minDiff;
        }

        return ans;
    }

    void getCountPresum(vector<int>& nums, vector<vector<int>>& countPresum) {
        for (int i = 0; i < (int)nums.size(); ++i) {
            for (int num = 1; num < 101; ++num) {
                countPresum[num][i + 1] = countPresum[num][i] + (num == nums[i] ? 1 : 0);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,4,8 };
    vector<vector<int>> queries = { {0,1},{1,2},{2,3},{0,3} };
    vector<int> actual = o.minDifference(nums, queries);
    vector<int> expected = { 2,1,4,1 };
    check.checkIntVector(expected, actual);

    nums = { 4,5,2,2,7,10 };
    queries = { {2,3},{0,2},{0,5},{3,5} };
    actual = o.minDifference(nums, queries);
    expected = { -1,1,1,3 };
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
