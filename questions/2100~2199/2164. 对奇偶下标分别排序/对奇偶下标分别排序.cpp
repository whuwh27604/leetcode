/* 对奇偶下标分别排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。根据下述规则重排 nums 中的值：

按 非递增 顺序排列 nums 奇数下标 上的所有值。
举个例子，如果排序前 nums = [4,1,2,3] ，对奇数下标的值排序后变为 [4,3,2,1] 。奇数下标 1 和 3 的值按照非递增顺序重排。
按 非递减 顺序排列 nums 偶数下标 上的所有值。
举个例子，如果排序前 nums = [4,1,2,3] ，对偶数下标的值排序后变为 [2,1,4,3] 。偶数下标 0 和 2 的值按照非递减顺序重排。
返回重排 nums 的值之后形成的数组。

 

示例 1：

输入：nums = [4,1,2,3]
输出：[2,3,4,1]
解释：
首先，按非递增顺序重排奇数下标（1 和 3）的值。
所以，nums 从 [4,1,2,3] 变为 [4,3,2,1] 。
然后，按非递减顺序重排偶数下标（0 和 2）的值。
所以，nums 从 [4,1,2,3] 变为 [2,3,4,1] 。
因此，重排之后形成的数组是 [2,3,4,1] 。
示例 2：

输入：nums = [2,1]
输出：[2,1]
解释：
由于只有一个奇数下标和一个偶数下标，所以不会发生重排。
形成的结果数组是 [2,1] ，和初始数组一样。
 

提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-even-and-odd-indices-independently
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int i, size = nums.size();
        vector<int> evens, odds, ans(size);

        for (i = 0; i < size; ++i) {
            if ((i & 1) == 0) {
                evens.push_back(nums[i]);
            }
            else {
                odds.push_back(nums[i]);
            }
        }

        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end());
        int j = 0, k = odds.size() - 1;

        for (i = 0; i < size; ++i) {
            if ((i & 1) == 0) {
                ans[i] = evens[j++];
            }
            else {
                ans[i] = odds[k--];
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4,1,2,3 };
    vector<int> actual = o.sortEvenOdd(nums);
    vector<int> expected = { 2,3,4,1 };
    check.checkIntVector(expected, actual);

    nums = { 2,1 };
    actual = o.sortEvenOdd(nums);
    expected = { 2,1 };
    check.checkIntVector(expected, actual);

    nums = { 2 };
    actual = o.sortEvenOdd(nums);
    expected = { 2 };
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
