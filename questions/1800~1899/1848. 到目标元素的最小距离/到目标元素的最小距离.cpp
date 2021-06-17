/* 到目标元素的最小距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums （下标 从 0 开始 计数）以及两个整数 target 和 start ，请你找出一个下标 i ，满足 nums[i] == target 且 abs(i - start) 最小化 。注意：abs(x) 表示 x 的绝对值。

返回 abs(i - start) 。

题目数据保证 target 存在于 nums 中。

 

示例 1：

输入：nums = [1,2,3,4,5], target = 5, start = 3
输出：1
解释：nums[4] = 5 是唯一一个等于 target 的值，所以答案是 abs(4 - 3) = 1 。
示例 2：

输入：nums = [1], target = 1, start = 0
输出：0
解释：nums[0] = 1 是唯一一个等于 target 的值，所以答案是 abs(0 - 0) = 0 。
示例 3：

输入：nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0
输出：0
解释：nums 中的每个值都是 1 ，但 nums[0] 使 abs(i - start) 的结果得以最小化，所以答案是 abs(0 - 0) = 0 。
 

提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 104
0 <= start < nums.length
target 存在于 nums 中

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-distance-to-the-target-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int distance = 0, size = nums.size();

        for (distance = 0; distance < size; ++distance) {
            if ((start - distance >= 0 && nums[start - distance] == target) || (start + distance < size && nums[start + distance] == target)) {
                break;
            }
        }

        return distance;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,4,5 };
    check.checkInt(1, o.getMinDistance(nums, 5, 3));
    check.checkInt(4, o.getMinDistance(nums, 5, 0));

    nums = { 1 };
    check.checkInt(0, o.getMinDistance(nums, 1, 0));

    nums = { 1,1,1,1,1,1,1,1,1,1 };
    check.checkInt(0, o.getMinDistance(nums, 1, 0));
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
