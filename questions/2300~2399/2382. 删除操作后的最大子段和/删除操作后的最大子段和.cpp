/* 删除操作后的最大子段和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的整数数组 nums 和 removeQueries ，两者长度都为 n 。对于第 i 个查询，nums 中位于下标 removeQueries[i] 处的元素被删除，将 nums 分割成更小的子段。

一个 子段 是 nums 中连续 正 整数形成的序列。子段和 是子段中所有元素的和。

请你返回一个长度为 n 的整数数组 answer ，其中 answer[i]是第 i 次删除操作以后的 最大 子段和。

注意：一个下标至多只会被删除一次。

 

示例 1：

输入：nums = [1,2,5,6,1], removeQueries = [0,3,2,4,1]
输出：[14,7,2,2,0]
解释：用 0 表示被删除的元素，答案如下所示：
查询 1 ：删除第 0 个元素，nums 变成 [0,2,5,6,1] ，最大子段和为子段 [2,5,6,1] 的和 14 。
查询 2 ：删除第 3 个元素，nums 变成 [0,2,5,0,1] ，最大子段和为子段 [2,5] 的和 7 。
查询 3 ：删除第 2 个元素，nums 变成 [0,2,0,0,1] ，最大子段和为子段 [2] 的和 2 。
查询 4 ：删除第 4 个元素，nums 变成 [0,2,0,0,0] ，最大子段和为子段 [2] 的和 2 。
查询 5 ：删除第 1 个元素，nums 变成 [0,0,0,0,0] ，最大子段和为 0 ，因为没有任何子段存在。
所以，我们返回 [14,7,2,2,0] 。
示例 2：

输入：nums = [3,2,11,1], removeQueries = [3,2,1,0]
输出：[16,5,3,0]
解释：用 0 表示被删除的元素，答案如下所示：
查询 1 ：删除第 3 个元素，nums 变成 [3,2,11,0] ，最大子段和为子段 [3,2,11] 的和 16 。
查询 2 ：删除第 2 个元素，nums 变成 [3,2,0,0] ，最大子段和为子段 [3,2] 的和 5 。
查询 3 ：删除第 1 个元素，nums 变成 [3,0,0,0] ，最大子段和为子段 [3] 的和 3 。
查询 5 ：删除第 0 个元素，nums 变成 [0,0,0,0] ，最大子段和为 0 ，因为没有任何子段存在。
所以，我们返回 [16,5,3,0] 。
 

提示：

n == nums.length == removeQueries.length
1 <= n <= 105
1 <= nums[i] <= 109
0 <= removeQueries[i] < n
removeQueries 中所有数字 互不相同 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-segment-sum-after-removals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        vector<long long> ans(n);

        vector<long long> presums(n + 1, 0);
        for (int i = 0; i < (int)nums.size(); ++i) {
            presums[i + 1] = presums[i] + nums[i];
        }

        map<int, int> segments;
        segments[0] = n - 1;
        map<long long, int> sums;
        sums[presums[n]] = 1;

        for (int i = 0; i < n; ++i) {
            int query = removeQueries[i];
            auto iter = segments.upper_bound(query);
            --iter;  // 找到query所在的segment
            int start = iter->first, end = iter->second;
            segments.erase(iter);  // 删除该segment
            long long sum = presums[end + 1] - presums[start];            
            if (--sums[sum] == 0) {
                sums.erase(sum);
            }

            // 插入拆分后的两个新segment
            if (start != end) {
                if (query == start) {
                    ++sums[presums[end + 1] - presums[start + 1]];
                    segments[start + 1] = end;
                }
                else if (query == end) {
                    ++sums[presums[end] - presums[start]];
                    segments[start] = end - 1;
                }
                else {
                    ++sums[presums[query] - presums[start]];
                    segments[start] = query - 1;
                    ++sums[presums[end + 1] - presums[query + 1]];
                    segments[query + 1] = end;
                }
            }

            ans[i] = (sums.empty() ? 0 : (--sums.end())->first);
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,5,6,1 };
    vector<int> removeQueries = { 0,3,2,4,1 };
    vector<long long> actual = o.maximumSegmentSum(nums, removeQueries);
    vector<long long> expected = { 14,7,2,2,0 };
    check.checkLongLongVector(expected, actual);

    nums = { 3,2,11,1 };
    removeQueries = { 3,2,1,0 };
    actual = o.maximumSegmentSum(nums, removeQueries);
    expected = { 16,5,3,0 };
    check.checkLongLongVector(expected, actual);
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
