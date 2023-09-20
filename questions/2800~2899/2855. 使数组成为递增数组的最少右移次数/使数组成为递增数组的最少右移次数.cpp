/* 使数组成为递增数组的最少右移次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 下标从 0 开始的数组 nums ，数组中的元素为 互不相同 的正整数。请你返回让 nums 成为递增数组的 最少右移 次数，如果无法得到递增数组，返回 -1 。

一次 右移 指的是同时对所有下标进行操作，将下标为 i 的元素移动到下标 (i + 1) % n 处。



示例 1：

输入：nums = [3,4,5,1,2]
输出：2
解释：
第一次右移后，nums = [2,3,4,5,1] 。
第二次右移后，nums = [1,2,3,4,5] 。
现在 nums 是递增数组了，所以答案为 2 。
示例 2：

输入：nums = [1,3,5]
输出：0
解释：nums 已经是递增数组了，所以答案为 0 。
示例 3：

输入：nums = [2,1,4]
输出：-1
解释：无法将数组变为递增数组。


提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100
nums 中的整数互不相同。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int size = nums.size(), index = -1;

        for (int i = 1; i < size; ++i) {
            if (nums[i] < nums[i - 1]) {
                if (index != -1) {
                    return -1;
                }
                index = i;
            }
        }

        if (index == -1) {
            return 0;
        }

        return nums[size - 1] < nums[0] ? size - index : -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,4,5,1,2 };
    check.checkInt(2, o.minimumRightShifts(nums));

    nums = { 1,3,5 };
    check.checkInt(0, o.minimumRightShifts(nums));

    nums = { 2,1,4 };
    check.checkInt(-1, o.minimumRightShifts(nums));
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
