/* 采购方案.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小力将 N 个零件的报价存于数组 nums。小力预算为 target，假定小力仅购买两个零件，要求购买零件的花费不超过预算，请问他有多少种采购方案。

注意：答案需要以 1e9 + 7 (1000000007) 为底取模，如：计算初始结果为：1000000008，请返回 1

示例 1：

输入：nums = [2,5,3,5], target = 6

输出：1

解释：预算内仅能购买 nums[0] 与 nums[2]。

示例 2：

输入：nums = [2,2,1,9], target = 10

输出：4

解释：符合预算的采购方案如下：
nums[0] + nums[1] = 4
nums[0] + nums[2] = 3
nums[1] + nums[2] = 3
nums[2] + nums[3] = 10

提示：

2 <= nums.length <= 10^5
1 <= nums[i], target <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4xy4Wx
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        long long plans = 0;

        sort(nums.begin(), nums.end());

        while (left < right) {
            while (right > left && nums[left] + nums[right] > target) {
                --right;
            }

            plans += (right - left);
            ++left;
        }

        return (int)(plans % 1000000007);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,5,3,5 };
    check.checkInt(1, o.purchasePlans(nums, 6));

    nums = { 2,2,1,9 };
    check.checkInt(4, o.purchasePlans(nums, 10));

    nums = { 2,9 };
    check.checkInt(1, o.purchasePlans(nums, 11));

    nums = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
    check.checkInt(2016, o.purchasePlans(nums, 100));
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
