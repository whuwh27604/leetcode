/* 统计完全子数组的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由 正 整数组成的数组 nums 。

如果数组中的某个子数组满足下述条件，则称之为 完全子数组 ：

子数组中 不同 元素的数目等于整个数组不同元素的数目。
返回数组中 完全子数组 的数目。

子数组 是数组中的一个连续非空序列。



示例 1：

输入：nums = [1,3,1,2,2]
输出：4
解释：完全子数组有：[1,3,1,2]、[1,3,1,2,2]、[3,1,2] 和 [3,1,2,2] 。
示例 2：

输入：nums = [5,5,5,5]
输出：10
解释：数组仅由整数 5 组成，所以任意子数组都满足完全子数组的条件。子数组的总数为 10 。


提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 2000
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int count = 0, size = nums.size(), left = 0, right = 0;
        int elements = getElements(nums);
        unordered_map<int, int> numsCount;

        for (left = 0; left < size; ++left) {
            while (right < size && (int)numsCount.size() < elements) {
                ++numsCount[nums[right++]];
            }

            if (numsCount.size() == elements) {
                count += (size - right + 1);
            }

            if (--numsCount[nums[left]] == 0) {
                numsCount.erase(nums[left]);
            }
        }

        return count;
    }

    int getElements(vector<int>& nums) {
        unordered_map<int, int> numsCount;

        for (int num : nums) {
            ++numsCount[num];
        }

        return numsCount.size();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,1,2,2 };
    check.checkInt(4, o.countCompleteSubarrays(nums));

    nums = { 5,5,5,5 };
    check.checkInt(10, o.countCompleteSubarrays(nums));
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
