/* 所有排列中的最大和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个整数数组 nums ，和一个查询数组 requests ，其中 requests[i] = [starti, endi] 。第 i 个查询求 nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi] 的结果 ，starti 和 endi 数组索引都是 从 0 开始 的。

你可以任意排列 nums 中的数字，请你返回所有查询结果之和的最大值。

由于答案可能会很大，请你将它对 109 + 7 取余 后返回。

 

示例 1：

输入：nums = [1,2,3,4,5], requests = [[1,3],[0,1]]
输出：19
解释：一个可行的 nums 排列为 [2,1,3,4,5]，并有如下结果：
requests[0] -> nums[1] + nums[2] + nums[3] = 1 + 3 + 4 = 8
requests[1] -> nums[0] + nums[1] = 2 + 1 = 3
总和为：8 + 3 = 11。
一个总和更大的排列为 [3,5,4,2,1]，并有如下结果：
requests[0] -> nums[1] + nums[2] + nums[3] = 5 + 4 + 2 = 11
requests[1] -> nums[0] + nums[1] = 3 + 5  = 8
总和为： 11 + 8 = 19，这个方案是所有排列中查询之和最大的结果。
示例 2：

输入：nums = [1,2,3,4,5,6], requests = [[0,1]]
输出：11
解释：一个总和最大的排列为 [6,5,4,3,2,1] ，查询和为 [11]。
示例 3：

输入：nums = [1,2,3,4,5,10], requests = [[0,2],[1,3],[1,1]]
输出：47
解释：一个和最大的排列为 [4,10,5,3,2,1] ，查询结果分别为 [19,18,10]。
 

提示：

n == nums.length
1 <= n <= 105
0 <= nums[i] <= 105
1 <= requests.length <= 105
requests[i].length == 2
0 <= starti <= endi < n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-sum-obtained-of-any-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int i, size = nums.size();
        long long sum = 0;
        vector<int> reqTimes(size + 1, 0);

        getReqTimes(requests, reqTimes);
        sort(reqTimes.begin(), reqTimes.end());
        sort(nums.begin(), nums.end());

        for (i = size; i >= 0 && reqTimes[i] != 0; --i) {
            sum += (long long)reqTimes[i] * nums[i - 1];
        }

        return (int)(sum % 1000000007);
    }

    void getReqTimes(vector<vector<int>>& requests, vector<int>& reqTimes) {
        for (auto& request : requests) {
            ++reqTimes[request[0]];
            --reqTimes[request[1] + 1];
        }

        for (int i = 1; i < (int)reqTimes.size(); ++i) {
            reqTimes[i] += reqTimes[i - 1];
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,4,5 };
    vector<vector<int>> requests = { {1,3},{0,1} };
    check.checkInt(19, o.maxSumRangeQuery(nums, requests));

    nums = { 1,2,3,4,5,6 };
    requests = { {0,1} };
    check.checkInt(11, o.maxSumRangeQuery(nums, requests));

    nums = { 1,2,3,4,5,10 };
    requests = { {0,2},{1,3},{1,1} };
    check.checkInt(47, o.maxSumRangeQuery(nums, requests));
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
