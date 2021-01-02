/* 滑动窗口最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

 

示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
示例 2：

输入：nums = [1], k = 1
输出：[1]
示例 3：

输入：nums = [1,-1], k = 1
输出：[1,-1]
示例 4：

输入：nums = [9,11], k = 2
输出：[11]
示例 5：

输入：nums = [4,-2], k = 2
输出：[4]
 

提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-maximum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <deque>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> decreasingNums;
        int i, j = 0, size = nums.size();
        vector<int> maxInWindow(size - k + 1);

        for (i = 0; i < size; ++i) {
            while (!decreasingNums.empty() && nums[i] >= nums[decreasingNums.back()]) {
                decreasingNums.pop_back();
            }

            decreasingNums.push_back(i);

            while (i - decreasingNums.front() >= k) {
                decreasingNums.pop_front();
            }

            if (i >= k - 1) {
                maxInWindow[j++] = nums[decreasingNums.front()];
            }
        }

        return maxInWindow;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
    vector<int> actual = o.maxSlidingWindow(nums, 3);
    vector<int> expected = { 3,3,5,5,6,7 };
    check.checkIntVector(expected, actual);

    nums = { 1 };
    actual = o.maxSlidingWindow(nums, 1);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    nums = { 1,-1 };
    actual = o.maxSlidingWindow(nums, 1);
    expected = { 1,-1 };
    check.checkIntVector(expected, actual);

    nums = { 9,11 };
    actual = o.maxSlidingWindow(nums, 2);
    expected = { 11 };
    check.checkIntVector(expected, actual);

    nums = { 4,-2 };
    actual = o.maxSlidingWindow(nums, 2);
    expected = { 4 };
    check.checkIntVector(expected, actual);
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
