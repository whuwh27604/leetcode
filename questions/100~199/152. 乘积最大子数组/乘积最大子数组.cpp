/* 乘积最大子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

 

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /* 令dpMax[i]、dpMin[i]分别表示以nums[i]为结尾的子数组能够得到的最大值最小值，dpMax[i+1]只能出现在以下三种情况：
           1、nums[i+1]>0, dpMax[i]=0, dpMax[i+1]=nums[i+1]
           2、nums[i+1]>0, dpMax[i]>0, dpMax[i+1]=nums[i+1]*dpMax[i]
           3、nums[i+1]<0, dpMin[i]<0, dpMax[i+1]=nums[i+1]*dpMin[i]
           dpMin[i+1]只能出现在以下三种情况：
           1、nums[i+1]<0, dpMin[i]=0, dpMin[i+1]=nums[i+1]
           2、nums[i+1]<0, dpMax[i]>0, dpMin[i+1]=nums[i+1]*dpMax[i]
           3、nums[i+1]>0, dpMin[i]<0, dpMin[i+1]=nums[i+1]*dpMin[i] */
        int i, size = nums.size(), productMin = nums[0], productMax = nums[0], maximumProduct = nums[0];

        for (i = 1; i < size; ++i) {
            int lastMin = productMin, lastMax = productMax;
            productMax = max({ nums[i], nums[i] * lastMin, nums[i] * lastMax });
            productMin = min({ nums[i], nums[i] * lastMin, nums[i] * lastMax });
            maximumProduct = max(maximumProduct, productMax);
        }

        return maximumProduct;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 5,6,-3,4,-3 };
    check.checkInt(1080, o.maxProduct(nums));

    nums = { 1,-2,4,-3,5,-3 };
    check.checkInt(180, o.maxProduct(nums));

    nums = { 2,3,-2,4 };
    check.checkInt(6, o.maxProduct(nums));

    nums = { -2,0,-1 };
    check.checkInt(0, o.maxProduct(nums));

    nums = { 0,2 };
    check.checkInt(2, o.maxProduct(nums));

    nums = { -4,-3,-2 };
    check.checkInt(12, o.maxProduct(nums));

    nums = { -2,3,-4 };
    check.checkInt(24, o.maxProduct(nums));
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
