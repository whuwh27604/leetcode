/* 最长连续序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

 

进阶：你可以设计并实现时间复杂度为 O(n) 的解决方案吗？

 

示例 1：

输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
示例 2：

输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
 

提示：

0 <= nums.length <= 104
-109 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        unordered_map<int, int> numsLen;
        int maxLen = 1;

        for (int num : nums) {
            numsLen[num] = 1;
        }

        for (auto iter = numsLen.begin(); iter != numsLen.end(); ++iter) {
            int num = iter->first - 1;
            auto it = numsLen.find(num);

            while (it != numsLen.end()) {
                iter->second += it->second;
                maxLen = max(maxLen, iter->second);
                num -= it->second;
                numsLen.erase(it);
                it = numsLen.find(num);
            }
        }

        return maxLen;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 100,4,200,1,3,2 };
    check.checkInt(4, o.longestConsecutive(nums));

    nums = { 0,3,7,2,5,8,4,6,0,1 };
    check.checkInt(9, o.longestConsecutive(nums));

    nums = {  };
    check.checkInt(0, o.longestConsecutive(nums));

    nums = { 0 };
    check.checkInt(1, o.longestConsecutive(nums));

    nums = { 0,0 };
    check.checkInt(1, o.longestConsecutive(nums));

    nums = { 0,1,1,2 };
    check.checkInt(3, o.longestConsecutive(nums));

    nums = { 16,1,15,2,14,3,13,4,12,5,11,6,10 };
    check.checkInt(7, o.longestConsecutive(nums));
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
