/* 存在重复元素 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在整数数组 nums 中，是否存在两个下标 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值小于等于 t ，且满足 i 和 j 的差的绝对值也小于等于 ķ 。

如果存在则返回 true，不存在返回 false。

 

示例 1:

输入: nums = [1,2,3,1], k = 3, t = 0
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1, t = 2
输出: true
示例 3:

输入: nums = [1,5,9,1,5,9], k = 2, t = 3
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contains-duplicate-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> kNums;
        int i, size = nums.size();

        for (i = 0; i < size; i++) {
            if (((int)kNums.size() - 1) == k) {
                kNums.erase(nums[i - k - 1]);
            }

            long long number = nums[i];
            auto iter = kNums.insert(number);
            auto leftIter = iter;
            if ((leftIter != kNums.begin()) && (abs(number - *(--leftIter)) <= t)) {
                return true;
            }

            if (((++iter) != kNums.end()) && (abs(number - *iter) <= t)) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = {};
    check.checkBool(false, o.containsNearbyAlmostDuplicate(nums, INT_MAX, INT_MAX));

    nums = { 1 };
    check.checkBool(false, o.containsNearbyAlmostDuplicate(nums, INT_MAX, INT_MAX));

    nums = { 1,2 };
    check.checkBool(true, o.containsNearbyAlmostDuplicate(nums, INT_MAX, INT_MAX));

    nums = { 1,2 };
    check.checkBool(true, o.containsNearbyAlmostDuplicate(nums, 1, 1));

    nums = { 1,2 };
    check.checkBool(false, o.containsNearbyAlmostDuplicate(nums, 0, 1));

    nums = { 1,2 };
    check.checkBool(false, o.containsNearbyAlmostDuplicate(nums, 1, 0));

    nums = { 1,2,3,1 };
    check.checkBool(true, o.containsNearbyAlmostDuplicate(nums, 3, 0));

    nums = { 1,2,3,1 };
    check.checkBool(false, o.containsNearbyAlmostDuplicate(nums, 2, 0));

    nums = { 1,0,1,1 };
    check.checkBool(true, o.containsNearbyAlmostDuplicate(nums, 1, 2));

    nums = { 1,0,1,1 };
    check.checkBool(true, o.containsNearbyAlmostDuplicate(nums, 1, 0));

    nums = { 1,5,9,1,5,9 };
    check.checkBool(false, o.containsNearbyAlmostDuplicate(nums, 2, 3));

    nums = { 1,5,9,1,5,9 };
    check.checkBool(true, o.containsNearbyAlmostDuplicate(nums, 1, 4));

    nums = { -1,INT_MAX };
    check.checkBool(false, o.containsNearbyAlmostDuplicate(nums, 1, INT_MAX));
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
