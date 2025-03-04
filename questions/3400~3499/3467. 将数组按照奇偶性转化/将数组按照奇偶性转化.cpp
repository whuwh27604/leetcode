/* 将数组按照奇偶性转化.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums。请你按照以下顺序 依次 执行操作，转换 nums：

将每个偶数替换为 0。
将每个奇数替换为 1。
按 非递减 顺序排序修改后的数组。
执行完这些操作后，返回结果数组。



示例 1:

输入：nums = [4,3,2,1]

输出：[0,0,1,1]

解释：

将偶数（4 和 2）替换为 0，将奇数（3 和 1）替换为 1。现在，nums = [0, 1, 0, 1]。
按非递减顺序排序 nums，得到 nums = [0, 0, 1, 1]。
示例 2:

输入：nums = [1,5,1,4,2]

输出：[0,0,1,1,1]

解释：

将偶数（4 和 2）替换为 0，将奇数（1, 5 和 1）替换为 1。现在，nums = [1, 1, 1, 0, 0]。
按非递减顺序排序 nums，得到 nums = [0, 0, 1, 1, 1]。


提示：

1 <= nums.length <= 100
1 <= nums[i] <= 1000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int odd = 0, even = 0;

        for (int num : nums) {
            if ((num & 1) == 0) {
                ++even;
            }
            else {
                ++odd;
            }
        }

        vector<int> ans(even, 0);
        ans.insert(ans.end(), odd, 1);

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 4,3,2,1 };
    vector<int> actual = o.transformArray(nums);
    vector<int> expected = { 0,0,1,1 };
    check.checkIntVector(expected, actual);

    nums = { 1,5,1,4,2 };
    actual = o.transformArray(nums);
    expected = { 0,0,1,1,1 };
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
