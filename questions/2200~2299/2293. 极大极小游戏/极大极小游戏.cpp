/* 极大极小游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums ，其长度是 2 的幂。

对 nums 执行下述算法：

设 n 等于 nums 的长度，如果 n == 1 ，终止 算法过程。否则，创建 一个新的整数数组 newNums ，新数组长度为 n / 2 ，下标从 0 开始。
对于满足 0 <= i < n / 2 的每个 偶数 下标 i ，将 newNums[i] 赋值 为 min(nums[2 * i], nums[2 * i + 1]) 。
对于满足 0 <= i < n / 2 的每个 奇数 下标 i ，将 newNums[i] 赋值 为 max(nums[2 * i], nums[2 * i + 1]) 。
用 newNums 替换 nums 。
从步骤 1 开始 重复 整个过程。
执行算法后，返回 nums 中剩下的那个数字。

 

示例 1：



输入：nums = [1,3,5,2,4,8,2,2]
输出：1
解释：重复执行算法会得到下述数组。
第一轮：nums = [1,5,4,2]
第二轮：nums = [1,4]
第三轮：nums = [1]
1 是最后剩下的那个数字，返回 1 。
示例 2：

输入：nums = [3]
输出：3
解释：3 就是最后剩下的数字，返回 3 。
 

提示：

1 <= nums.length <= 1024
1 <= nums[i] <= 109
nums.length 是 2 的幂

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/min-max-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int i, size = nums.size(), half = size / 2;
        vector<int> newNums(half);

        if (size == 1) {
            return nums[0];
        }

        for (i = 0; i < half; ++i) {
            if ((i & 1) == 0) {
                newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
            }
            else {
                newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
            }
        }

        return minMaxGame(newNums);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,5,2,4,8,2,2 };
    check.checkInt(1, o.minMaxGame(nums));

    nums = { 3 };
    check.checkInt(3, o.minMaxGame(nums));
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
