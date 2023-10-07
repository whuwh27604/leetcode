/* 收集元素的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 nums 和一个整数 k 。

一次操作中，你可以将数组的最后一个元素删除，将该元素添加到一个集合中。

请你返回收集元素 1, 2, ..., k 需要的 最少操作次数 。



示例 1：

输入：nums = [3,1,5,4,2], k = 2
输出：4
解释：4 次操作后，集合中的元素依次添加了 2 ，4 ，5 和 1 。此时集合中包含元素 1 和 2 ，所以答案为 4 。
示例 2：

输入：nums = [3,1,5,4,2], k = 5
输出：5
解释：5 次操作后，集合中的元素依次添加了 2 ，4 ，5 ，1 和 3 。此时集合中包含元素 1 到 5 ，所以答案为 5 。
示例 3：

输入：nums = [3,2,5,3,1], k = 3
输出：4
解释：4 次操作后，集合中的元素依次添加了 1 ，3 ，5 和 2 。此时集合中包含元素 1 到 3  ，所以答案为 4 。


提示：

1 <= nums.length <= 50
1 <= nums[i] <= nums.length
1 <= k <= nums.length
输入保证你可以收集到元素 1, 2, ..., k 。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        int size = nums.size();
        vector<bool> exist(k + 1, false);

        for (int i = size - 1; i >= 0; --i) {
            int num = nums[i];
            if (num <= k && !exist[num]) {
                exist[num] = true;
                if (++count == k) {
                    return size - i;
                }
            }
        }

        return size;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,1,5,4,2 };
    check.checkInt(4, o.minOperations(nums, 2));

    nums = { 3,1,5,4,2 };
    check.checkInt(5, o.minOperations(nums, 5));

    nums = { 3,2,5,3,1 };
    check.checkInt(4, o.minOperations(nums, 3));
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
