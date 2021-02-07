/* 非递减数列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中所有的 i (1 <= i < n)，总满足 array[i] <= array[i + 1]。

 

示例 1:

输入: nums = [4,2,3]
输出: true
解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
示例 2:

输入: nums = [4,2,1]
输出: false
解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
 

说明：

1 <= n <= 10 ^ 4
- 10 ^ 5 <= nums[i] <= 10 ^ 5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/non-decreasing-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i, size = nums.size(), count = 0;

        for (i = 1; i < size; ++i) {
            if (nums[i] < nums[i - 1]) {
                if (++count == 2) {
                    return false;
                }

                if (i == 1 || nums[i] >= nums[i - 2]) {
                    continue;
                }
                else {
                    nums[i] = nums[i - 1];
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 4,2,3 };
    check.checkBool(true, o.checkPossibility(nums));

    nums = { 4,2,1 };
    check.checkBool(false, o.checkPossibility(nums));

    nums = { 4 };
    check.checkBool(true, o.checkPossibility(nums));

    nums = { 4,1 };
    check.checkBool(true, o.checkPossibility(nums));

    nums = { 4,5 };
    check.checkBool(true, o.checkPossibility(nums));

    nums = { 4,5,1 };
    check.checkBool(true, o.checkPossibility(nums));

    nums = { 4,1,2 };
    check.checkBool(true, o.checkPossibility(nums));

    nums = { 4,4,1 };
    check.checkBool(true, o.checkPossibility(nums));

    nums = { 4,1,1 };
    check.checkBool(true, o.checkPossibility(nums));

    nums = { 4,4,0,4,5 };
    check.checkBool(true, o.checkPossibility(nums));

    nums = { 0,4,0,1,2 };
    check.checkBool(true, o.checkPossibility(nums));

    nums = { 1,4,0,1,2 };
    check.checkBool(false, o.checkPossibility(nums));

    nums = { 4,1,2,3 };
    check.checkBool(true, o.checkPossibility(nums));

    nums = { 1,2,3,2 };
    check.checkBool(true, o.checkPossibility(nums));

    nums = { 4,4,1,2,3 };
    check.checkBool(false, o.checkPossibility(nums));

    nums = { 2,2,1,3,4 };
    check.checkBool(true, o.checkPossibility(nums));

    nums = { 2,2,1,1,3,4 };
    check.checkBool(false, o.checkPossibility(nums));
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
