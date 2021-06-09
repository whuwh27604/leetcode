/* 袋子里最少数目的球.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，其中 nums[i] 表示第 i 个袋子里球的数目。同时给你一个整数 maxOperations 。

你可以进行如下操作至多 maxOperations 次：

选择任意一个袋子，并将袋子里的球分到 2 个新的袋子中，每个袋子里都有 正整数 个球。
比方说，一个袋子里有 5 个球，你可以把它们分到两个新袋子里，分别有 1 个和 4 个球，或者分别有 2 个和 3 个球。
你的开销是单个袋子里球数目的 最大值 ，你想要 最小化 开销。

请你返回进行上述操作后的最小开销。

 

示例 1：

输入：nums = [9], maxOperations = 2
输出：3
解释：
- 将装有 9 个球的袋子分成装有 6 个和 3 个球的袋子。[9] -> [6,3] 。
- 将装有 6 个球的袋子分成装有 3 个和 3 个球的袋子。[6,3] -> [3,3,3] 。
装有最多球的袋子里装有 3 个球，所以开销为 3 并返回 3 。
示例 2：

输入：nums = [2,4,8,2], maxOperations = 4
输出：2
解释：
- 将装有 8 个球的袋子分成装有 4 个和 4 个球的袋子。[2,4,8,2] -> [2,4,4,4,2] 。
- 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,4,4,4,2] -> [2,2,2,4,4,2] 。
- 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,4,4,2] -> [2,2,2,2,2,4,2] 。
- 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2] 。
装有最多球的袋子里装有 2 个球，所以开销为 2 并返回 2 。
示例 3：

输入：nums = [7,17], maxOperations = 2
输出：7
 

提示：

1 <= nums.length <= 105
1 <= maxOperations, nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-limit-of-balls-in-a-bag
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        long long left = 1, right = getSum(nums), minPenalty = right;

        while (left <= right) {
            long long middle = (left + right) / 2;

            if (canFinish(nums, maxOperations, middle)) {
                minPenalty = middle;
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        return (int)minPenalty;
    }

    bool canFinish(vector<int>& nums, int maxOperations, long long penalty) {
        long long operations = 0;

        for (int num : nums) {
            operations += ((long long)num - 1) / penalty;

            if (operations > maxOperations) {
                return false;
            }
        }

        return true;
    }

    long long getSum(vector<int>& nums) {
        long long sum = 0;

        for (int num : nums) {
            sum += num;
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 9 };
    check.checkInt(3, o.minimumSize(nums, 2));

    nums = { 2,4,8,2 };
    check.checkInt(2, o.minimumSize(nums, 4));

    nums = { 7,17 };
    check.checkInt(7, o.minimumSize(nums, 2));

    nums = { 1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10 };
    check.checkInt(9, o.minimumSize(nums, 2));

    nums = { 1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10 };
    check.checkInt(8, o.minimumSize(nums, 5));

    nums = { 1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10 };
    check.checkInt(5, o.minimumSize(nums, 10));
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
