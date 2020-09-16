/* 划分数组为连续数字的集合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个正整数 k，请你判断是否可以把这个数组划分成一些由 k 个连续数字组成的集合。
如果可以，请返回 True；否则，返回 False。

 

示例 1：

输入：nums = [1,2,3,3,4,4,5,6], k = 4
输出：true
解释：数组可以分成 [1,2,3,4] 和 [3,4,5,6]。
示例 2：

输入：nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
输出：true
解释：数组可以分成 [1,2,3] , [2,3,4] , [3,4,5] 和 [9,10,11]。
示例 3：

输入：nums = [3,3,2,2,1,1], k = 3
输出：true
示例 4：

输入：nums = [1,2,3,4], k = 3
输出：false
解释：数组不能分成几个大小为 3 的子数组。
 

提示：

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= k <= nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divide-array-in-sets-of-k-consecutive-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> numsCount;
        countNums(nums, numsCount);

        map<int, int> ordered_nums;
        sortNums(numsCount, ordered_nums);

        auto iter = ordered_nums.begin();
        while (iter != ordered_nums.end()) {
            if (iter->second == 0) {
                ++iter;
                continue;
            }

            int num = iter->first;
            int count = iter->second;
            auto it = iter;

            for (int i = 0; i < k; i++) {
                if ((it == ordered_nums.end()) || (it->first != num + i) || (it->second < count)) {
                    return false;
                }

                it->second -= count;
                ++it;
            }
        }

        return true;
    }

    void countNums(vector<int>& nums, unordered_map<int, int>& numsCount) {
        for (int num : nums) {
            auto iter = numsCount.find(num);
            if (iter == numsCount.end()) {
                numsCount[num] = 1;
            }
            else {
                ++iter->second;
            }
        }
    }

    void sortNums(unordered_map<int, int>& numsCount, map<int, int>& ordered_nums) {
        for (auto iter = numsCount.begin(); iter != numsCount.end(); ++iter) {
            ordered_nums[iter->first] = iter->second;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3,3,4,4,5,6 };
    check.checkBool(true, o.isPossibleDivide(nums, 4));

    nums = { 3,2,1,2,3,4,3,4,5,9,10,11 };
    check.checkBool(true, o.isPossibleDivide(nums, 3));

    nums = { 3,3,2,2,1,1 };
    check.checkBool(true, o.isPossibleDivide(nums, 3));

    nums = { 1,2,3,4 };
    check.checkBool(false, o.isPossibleDivide(nums, 3));

    nums = { 1,2,3,6,2,3,4,7,8 };
    check.checkBool(true, o.isPossibleDivide(nums, 3));

    nums = { 1,2,3,4,5 };
    check.checkBool(true, o.isPossibleDivide(nums, 5));

    nums = { 1,2,3,4,5 };
    check.checkBool(false, o.isPossibleDivide(nums, 4));

    nums = { 5 };
    check.checkBool(true, o.isPossibleDivide(nums, 1));

    nums = { 5 };
    check.checkBool(false, o.isPossibleDivide(nums, 2));

    nums = { 5,1 };
    check.checkBool(true, o.isPossibleDivide(nums, 1));

    nums = { 5,1 };
    check.checkBool(false, o.isPossibleDivide(nums, 2));
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
