/* 一个数组所有前缀的分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
定义一个数组 arr 的 转换数组 conver 为：

conver[i] = arr[i] + max(arr[0..i])，其中 max(arr[0..i]) 是满足 0 <= j <= i 的所有 arr[j] 中的最大值。
定义一个数组 arr 的 分数 为 arr 转换数组中所有元素的和。

给你一个下标从 0 开始长度为 n 的整数数组 nums ，请你返回一个长度为 n 的数组 ans ，其中 ans[i]是前缀 nums[0..i] 的分数。



示例 1：

输入：nums = [2,3,7,5,10]
输出：[4,10,24,36,56]
解释：
对于前缀 [2] ，转换数组为 [4] ，所以分数为 4 。
对于前缀 [2, 3] ，转换数组为 [4, 6] ，所以分数为 10 。
对于前缀 [2, 3, 7] ，转换数组为 [4, 6, 14] ，所以分数为 24 。
对于前缀 [2, 3, 7, 5] ，转换数组为 [4, 6, 14, 12] ，所以分数为 36 。
对于前缀 [2, 3, 7, 5, 10] ，转换数组为 [4, 6, 14, 12, 20] ，所以分数为 56 。
示例 2：

输入：nums = [1,1,2,4,8,16]
输出：[2,4,8,16,32,64]
解释：
对于前缀 [1] ，转换数组为 [2] ，所以分数为 2 。
对于前缀 [1, 1]，转换数组为 [2, 2] ，所以分数为 4 。
对于前缀 [1, 1, 2]，转换数组为 [2, 2, 4] ，所以分数为 8 。
对于前缀 [1, 1, 2, 4]，转换数组为 [2, 2, 4, 8] ，所以分数为 16 。
对于前缀 [1, 1, 2, 4, 8]，转换数组为 [2, 2, 4, 8, 16] ，所以分数为 32 。
对于前缀 [1, 1, 2, 4, 8, 16]，转换数组为 [2, 2, 4, 8, 16, 32] ，所以分数为 64 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int size = nums.size(), maxNum = 0;
        long long prev = 0;
        vector<long long> ans(size, 0);

        for (int i = 0; i < size; ++i) {
            maxNum = max(maxNum, nums[i]);
            ans[i] = prev + nums[i] + maxNum;
            prev = ans[i];
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,3,7,5,10 };
    vector<long long> actual = o.findPrefixScore(nums);
    vector<long long> expected = { 4,10,24,36,56 };
    check.checkLongLongVector(expected, actual);

    nums = { 1,1,2,4,8,16 };
    actual = o.findPrefixScore(nums);
    expected = { 2,4,8,16,32,64 };
    check.checkLongLongVector(expected, actual);
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
