/* 统计中位数为 K 的子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的数组 nums ，该数组由从 1 到 n 的 不同 整数组成。另给你一个正整数 k 。

统计并返回 num 中的 中位数 等于 k 的非空子数组的数目。

注意：

数组的中位数是按 递增 顺序排列后位于 中间 的那个元素，如果数组长度为偶数，则中位数是位于中间靠 左 的那个元素。
例如，[2,3,1,4] 的中位数是 2 ，[8,4,3,5,1] 的中位数是 4 。
子数组是数组中的一个连续部分。


示例 1：

输入：nums = [3,2,1,4,5], k = 4
输出：3
解释：中位数等于 4 的子数组有：[4]、[4,5] 和 [1,4,5] 。
示例 2：

输入：nums = [2,3,1], k = 3
输出：1
解释：[3] 是唯一一个中位数等于 3 的子数组。


提示：

n == nums.length
1 <= n <= 105
1 <= nums[i], k <= n
nums 中的整数互不相同
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int index = getIndex(nums, k);
        unordered_map<int, int> right;
        right[0] = 1;

        return countRight(nums, k, index, right) + countLeft(nums, k, index, right);
    }

    int getIndex(vector<int>& nums, int k) {
        int i = 0, size = nums.size();

        for (i = 0; i < size; ++i) {
            if (nums[i] == k) {
                break;
            }
        }

        return i;
    }

    int countRight(vector<int>& nums, int k, int index, unordered_map<int, int>& right) {
        int subarrays = 1, less = 0, greater = 0;

        for (int i = index + 1; i < (int)nums.size(); ++i) {
            nums[i] > k ? ++greater : ++less;
            if (greater == less || greater - less == 1) {
                ++subarrays;
            }
            ++right[greater - less];
        }

        return subarrays;
    }

    int countLeft(vector<int>& nums, int k, int index, unordered_map<int, int>& right) {
        int subarrays = 0, less = 0, greater = 0;

        for (int i = index - 1; i >= 0; --i) {
            nums[i] > k ? ++greater : ++less;
            subarrays += right[less - greater];
            subarrays += right[less - greater + 1];
        }

        return subarrays;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,2,1,4,5 };
    check.checkInt(3, o.countSubarrays(nums, 4));

    nums = { 2,3,1 };
    check.checkInt(1, o.countSubarrays(nums, 3));

    nums = { 1 };
    check.checkInt(1, o.countSubarrays(nums, 1));

    nums = { 2,5,1,4,3,6 };
    check.checkInt(3, o.countSubarrays(nums, 1));

    nums = { 5,19,11,15,13,16,4,6,2,7,10,8,18,20,1,3,17,9,12,14 };
    check.checkInt(13, o.countSubarrays(nums, 6));
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
