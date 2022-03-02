/* 数组的最小偏移量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由 n 个正整数组成的数组 nums 。

你可以对数组的任意元素执行任意次数的两类操作：

如果元素是 偶数 ，除以 2
例如，如果数组是 [1,2,3,4] ，那么你可以对最后一个元素执行此操作，使其变成 [1,2,3,2]
如果元素是 奇数 ，乘上 2
例如，如果数组是 [1,2,3,4] ，那么你可以对第一个元素执行此操作，使其变成 [2,2,3,4]
数组的 偏移量 是数组中任意两个元素之间的 最大差值 。

返回数组在执行某些操作之后可以拥有的 最小偏移量 。

 

示例 1：

输入：nums = [1,2,3,4]
输出：1
解释：你可以将数组转换为 [1,2,3,2]，然后转换成 [2,2,3,2]，偏移量是 3 - 2 = 1
示例 2：

输入：nums = [4,1,5,20,3]
输出：3
解释：两次操作后，你可以将数组转换为 [4,2,5,5,3]，偏移量是 5 - 2 = 3
示例 3：

输入：nums = [2,10,8]
输出：3
 

提示：

n == nums.length
2 <= n <= 105
1 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimize-deviation-in-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> numbers;
        int minDeviation = INT_MAX;

        for (int num : nums) {
            if ((num & 1) == 1) {
                num *= 2;
            }

            numbers.insert(num);
        }

        auto iter = --numbers.end();

        while ((*iter & 1) == 0) {
            minDeviation = min(minDeviation, *iter - *numbers.begin());
            int num = *iter / 2;
            numbers.erase(iter);
            numbers.insert(num);
            iter = --numbers.end();
        }

        return min(minDeviation, *iter - *numbers.begin());
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,4 };
    check.checkInt(1, o.minimumDeviation(nums));

    nums = { 4,1,5,20,3 };
    check.checkInt(3, o.minimumDeviation(nums));

    nums = { 2,10,8 };
    check.checkInt(3, o.minimumDeviation(nums));

    nums = { 5,6 };
    check.checkInt(1, o.minimumDeviation(nums));
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
