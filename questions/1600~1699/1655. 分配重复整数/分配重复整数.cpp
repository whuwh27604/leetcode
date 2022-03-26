/* 分配重复整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 nums ，这个数组中至多有 50 个不同的值。同时你有 m 个顾客的订单 quantity ，其中，整数 quantity[i] 是第 i 位顾客订单的数目。请你判断是否能将 nums 中的整数分配给这些顾客，且满足：

第 i 位顾客 恰好 有 quantity[i] 个整数。
第 i 位顾客拿到的整数都是 相同的 。
每位顾客都满足上述两个要求。
如果你可以分配 nums 中的整数满足上面的要求，那么请返回 true ，否则返回 false 。

 

示例 1：

输入：nums = [1,2,3,4], quantity = [2]
输出：false
解释：第 0 位顾客没办法得到两个相同的整数。
示例 2：

输入：nums = [1,2,3,3], quantity = [2]
输出：true
解释：第 0 位顾客得到 [3,3] 。整数 [1,2] 都没有被使用。
示例 3：

输入：nums = [1,1,2,2], quantity = [2,2]
输出：true
解释：第 0 位顾客得到 [1,1] ，第 1 位顾客得到 [2,2] 。
 

提示：

n == nums.length
1 <= n <= 105
1 <= nums[i] <= 1000
m == quantity.length
1 <= m <= 10
1 <= quantity[i] <= 105
nums 中至多有 50 个不同的数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distribute-repeating-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        int m = quantity.size(), maxMask = (1 << m);
        vector<int> counts, sums(maxMask);

        count(nums, counts);
        getSums(quantity, m, sums);

        return distributable(counts, quantity, sums);
    }

    void count(vector<int>& nums, vector<int>& counts) {
        unordered_map<int, int> cnts;

        for (int num : nums) {
            ++cnts[num];
        }

        for (auto& cnt : cnts) {
            counts.push_back(cnt.second);
        }
    }

    void getSums(vector<int>& quantity, int m, vector<int>& sums) {
        int maxMask = (1 << m);

        for (int subset = 0; subset < maxMask; ++subset) {
            int sum = 0;

            for (int i = 0, bit = 1; i < m; ++i, bit <<= 1) {
                if ((subset & bit) != 0) {
                    sum += quantity[i];
                }
            }

            sums[subset] = sum;
        }
    }

    bool distributable(vector<int>& counts, vector<int>& quantity, vector<int>& sums) {
        int i, subset, size = counts.size(), m = quantity.size(), maxMask = (1 << m);
        vector<vector<bool>> dp(size, vector<bool>(maxMask, false));  // dp[i][subset]表示counts[0, i]是否可以满足quantity的子集subset

        for (i = 0; i < size; ++i) {
            dp[i][0] = true;

            for (subset = 1; subset < maxMask; ++subset) {
                if (i > 0 && dp[i - 1][subset]) {  // 不需要counts[i]，counts[0, i - 1]已经可以满足subset
                    dp[i][subset] = true;
                    continue;
                }

                for (int ssubset1 = subset; ssubset1 != 0; ssubset1 = (ssubset1 - 1) & subset) {  // 枚举subset的所有子集
                    int ssubset2 = subset ^ ssubset1;  // subset里面除子集ssubset1以外的子集
                    
                    // counts[i]可以满足ssubset1，counts[0, i - 1]可以满足ssubset2，那么counts[0, i]可以满足subset
                    if (counts[i] >= sums[ssubset1] && ((i == 0 && ssubset2 == 0) || (i != 0 && dp[i - 1][ssubset2]))) {
                        dp[i][subset] = true;
                        break;
                    }
                }
            }
        }

        return dp[size - 1][maxMask - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,4 };
    vector<int> quantity = { 2 };
    check.checkBool(false, o.canDistribute(nums, quantity));

    nums = { 1,2,3,3 };
    quantity = { 2 };
    check.checkBool(true, o.canDistribute(nums, quantity));

    nums = { 1,1,2,2 };
    quantity = { 2,2 };
    check.checkBool(true, o.canDistribute(nums, quantity));

    nums = { 1,1,1,1,2,2,2 };
    quantity = { 3,2,2 };
    check.checkBool(true, o.canDistribute(nums, quantity));

    nums = { 1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,26,26,27,27,28,28,29,29,30,30,31,31,32,32,33,33,34,34,35,35,36,36,37,37,38,38,39,39,40,40,41,41,42,42,43,43,44,44,45,45,46,46,47,47,48,48,49,49,50,50 };
    quantity = { 2,2,2,2,2,2,2,2,2,3 };
    check.checkBool(false, o.canDistribute(nums, quantity));
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
