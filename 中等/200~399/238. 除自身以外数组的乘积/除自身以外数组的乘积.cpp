/* 除自身以外数组的乘积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

 

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
 

提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。

说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/product-of-array-except-self
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i, product = 1, size = nums.size();
        vector<int> products(size, 0);

        products[0] = 1;
        for (i = 1; i < size; i++) {
            products[i] = products[i - 1] * nums[i - 1];  // 对每个i，计算i左边的数的乘积
        }

        for (i = size - 2; i >= 0; i--) {
            product *= nums[i + 1];  // 再计算i右边的数的乘积
            products[i] *= product;  // 左右相乘得到结果
        }

        return products;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3,4 };
    vector<int> actual = o.productExceptSelf(nums);
    vector<int> expected = { 24,12,8,6 };
    check.checkIntVector(expected, actual);

    nums = { 3,4 };
    actual = o.productExceptSelf(nums);
    expected = { 4,3 };
    check.checkIntVector(expected, actual);

    nums = { 3,0 };
    actual = o.productExceptSelf(nums);
    expected = { 0,3 };
    check.checkIntVector(expected, actual);

    nums = { 3,4,0 };
    actual = o.productExceptSelf(nums);
    expected = { 0,0,12 };
    check.checkIntVector(expected, actual);

    nums = { 2,3,4,-2,-3,-4 };
    actual = o.productExceptSelf(nums);
    expected = { -288,-192,-144,288,192,144 };
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
