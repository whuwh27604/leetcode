/* 删掉一个元素以后全为 1 的最长子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制数组 nums ，你需要从中删掉一个元素。

请你在删掉元素的结果数组中，返回最长的且只包含 1 的非空子数组的长度。

如果不存在这样的子数组，请返回 0 。

 

提示 1：

输入：nums = [1,1,0,1]
输出：3
解释：删掉位置 2 的数后，[1,1,1] 包含 3 个 1 。
示例 2：

输入：nums = [0,1,1,1,0,1,1,0,1]
输出：5
解释：删掉位置 4 的数字后，[0,1,1,1,1,1,0,1] 的最长全 1 子数组为 [1,1,1,1,1] 。
示例 3：

输入：nums = [1,1,1]
输出：2
解释：你必须要删除一个元素。
示例 4：

输入：nums = [1,1,0,0,1,1,1,0,1]
输出：4
示例 5：

输入：nums = [0,0,0]
输出：0
 

提示：

1 <= nums.length <= 10^5
nums[i] 要么是 0 要么是 1 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-subarray-of-1s-after-deleting-one-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev = 0, current = 0, maxLen = 0;

        for (int num : nums) {
            if (num == 1) {
                ++current;
            }
            else {
                maxLen = max(maxLen, prev + current);
                prev = current;
                current = 0;
            }
        }

        return current == nums.size() ? current - 1 : max(maxLen, prev + current);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,1,0,1 };
    check.checkInt(3, o.longestSubarray(nums));

    nums = { 0,1,1,1,0,1,1,0,1 };
    check.checkInt(5, o.longestSubarray(nums));

    nums = { 1,1,0,0,1,1,1,0,1 };
    check.checkInt(4, o.longestSubarray(nums));

    nums = { 0,0,0 };
    check.checkInt(0, o.longestSubarray(nums));

    nums = { 1,1,1 };
    check.checkInt(2, o.longestSubarray(nums));
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
