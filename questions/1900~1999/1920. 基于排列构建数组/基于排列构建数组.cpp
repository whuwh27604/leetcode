/* 基于排列构建数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 从 0 开始的排列 nums（下标也从 0 开始）。请你构建一个 同样长度 的数组 ans ，其中，对于每个 i（0 <= i < nums.length），都满足 ans[i] = nums[nums[i]] 。返回构建好的数组 ans 。

从 0 开始的排列 nums 是一个由 0 到 nums.length - 1（0 和 nums.length - 1 也包含在内）的不同整数组成的数组。

 

示例 1：

输入：nums = [0,2,1,5,3,4]
输出：[0,1,2,4,5,3]
解释：数组 ans 构建如下：
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    = [0,1,2,4,5,3]
示例 2：

输入：nums = [5,0,1,2,3,4]
输出：[4,5,0,1,2,3]
解释：数组 ans 构建如下：
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
    = [4,5,0,1,2,3]
 

提示：

1 <= nums.length <= 1000
0 <= nums[i] < nums.length
nums 中的元素 互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/build-array-from-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int i, size = nums.size();
        vector<int> arr(size);

        for (i = 0; i < size; ++i) {
            arr[i] = nums[nums[i]];
        }

        return arr;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 0,2,1,5,3,4 };
    vector<int> actual = o.buildArray(nums);
    vector<int> expected = { 0,1,2,4,5,3 };
    check.checkIntVector(expected, actual);

    nums = { 5,0,1,2,3,4 };
    actual = o.buildArray(nums);
    expected = { 4,5,0,1,2,3 };
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
