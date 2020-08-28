/* 乘积小于K的子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个正整数数组 nums。

找出该数组内乘积小于 k 的连续的子数组的个数。

示例 1:

输入: nums = [10,5,2,6], k = 100
输出: 8
解释: 8个乘积小于100的子数组分别为: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于100的子数组。
说明:

0 < nums.length <= 50000
0 < nums[i] < 1000
0 <= k < 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-product-less-than-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1, head = 0, tail, count = 0;
        
        for (tail = 0; tail < (int)nums.size(); tail++) {
            product *= nums[tail];
            
            while ((product >= k) && (head <= tail)) {
                product /= nums[head++];
            }

            count += (tail - head + 1);
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 10,5,2,6 };
    check.checkInt(8, o.numSubarrayProductLessThanK(nums, 100));
    check.checkInt(0, o.numSubarrayProductLessThanK(nums, 0));
    check.checkInt(9, o.numSubarrayProductLessThanK(nums, 600));
    check.checkInt(10, o.numSubarrayProductLessThanK(nums, 601));

    nums = { 10 };
    check.checkInt(0, o.numSubarrayProductLessThanK(nums, 0));
    check.checkInt(0, o.numSubarrayProductLessThanK(nums, 10));
    check.checkInt(1, o.numSubarrayProductLessThanK(nums, 11));

    nums = { 2,3 };
    check.checkInt(0, o.numSubarrayProductLessThanK(nums, 0));
    check.checkInt(0, o.numSubarrayProductLessThanK(nums, 2));
    check.checkInt(1, o.numSubarrayProductLessThanK(nums, 3));
    check.checkInt(2, o.numSubarrayProductLessThanK(nums, 4));
    check.checkInt(2, o.numSubarrayProductLessThanK(nums, 6));
    check.checkInt(3, o.numSubarrayProductLessThanK(nums, 7));

    nums = { 1,1,1,1,1 };
    check.checkInt(15, o.numSubarrayProductLessThanK(nums, 2));
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
