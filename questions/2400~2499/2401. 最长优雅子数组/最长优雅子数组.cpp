/* 最长优雅子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由 正 整数组成的数组 nums 。

如果 nums 的子数组中位于 不同 位置的每对元素按位 与（AND）运算的结果等于 0 ，则称该子数组为 优雅 子数组。

返回 最长 的优雅子数组的长度。

子数组 是数组中的一个 连续 部分。

注意：长度为 1 的子数组始终视作优雅子数组。

 

示例 1：

输入：nums = [1,3,8,48,10]
输出：3
解释：最长的优雅子数组是 [3,8,48] 。子数组满足题目条件：
- 3 AND 8 = 0
- 3 AND 48 = 0
- 8 AND 48 = 0
可以证明不存在更长的优雅子数组，所以返回 3 。
示例 2：

输入：nums = [3,1,5,11,13]
输出：1
解释：最长的优雅子数组长度为 1 ，任何长度为 1 的子数组都满足题目条件。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-nice-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i, j = 0, size = nums.size(), maxNice = 1;
        vector<int> sums(32, 0);

        for (i = 0; i < size; ++i) {
            add(sums, nums[i]);

            while (!isNice(sums)) {
                sub(sums, nums[j++]);
            }

            maxNice = max(maxNice, i - j + 1);
        }

        return maxNice;
    }

    void add(vector<int>& sums, int num) {
        int index = 0;

        while (num != 0) {
            sums[index++] += (num & 1);
            num >>= 1;
        }
    }

    void sub(vector<int>& sums, int num) {
        int index = 0;

        while (num != 0) {
            sums[index++] -= (num & 1);
            num >>= 1;
        }
    }

    bool isNice(vector<int>& sums) {
        for (int i = 0; i < 32; ++i) {
            if (sums[i] > 1) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,8,48,10 };
    check.checkInt(3, o.longestNiceSubarray(nums));

    nums = { 3,1,5,11,13 };
    check.checkInt(1, o.longestNiceSubarray(nums));

    nums = { 1 };
    check.checkInt(1, o.longestNiceSubarray(nums));

    nums = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };
    check.checkInt(2, o.longestNiceSubarray(nums));

    nums = { 1,2,4,8,16,32,64,128,256,512,1024 };
    check.checkInt(11, o.longestNiceSubarray(nums));
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
