/* 三个数的最大乘积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

示例 1:

输入: [1,2,3]
输出: 6
示例 2:

输入: [1,2,3,4]
输出: 24
注意:

给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。
输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-three-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        /* 不管正负，答案一定在(min,min,max)和(max,max,max)这两种情况中 */
        int firstMax = INT_MIN, secondMax = INT_MIN, thirdMax = INT_MIN;
        int firstMin = INT_MAX, secondMin = INT_MAX;
        for (unsigned int i = 0; i < nums.size(); i++) {
            adjustMax(nums[i], firstMax, secondMax, thirdMax);
            adjustMin(nums[i], firstMin, secondMin);
        }

        return max((firstMax * secondMax * thirdMax), (firstMin * secondMin * firstMax));
    }

    void adjustMax(int number, int& firstMax, int& secondMax, int& thirdMax) {
        if (number >= firstMax) {
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = number;
        }
        else if (number >= secondMax) {
            thirdMax = secondMax;
            secondMax = number;
        }
        else if (number > thirdMax) {
            thirdMax = number;
        }
    }

    void adjustMin(int number, int& firstMin, int& secondMin) {
        if (number <= firstMin) {
            secondMin = firstMin;
            firstMin = number;
        }
        else if (number < secondMin) {
            secondMin = number;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3 };
    check.checkInt(6, o.maximumProduct(nums));

    nums = { 1,2,3,4 };
    check.checkInt(24, o.maximumProduct(nums));

    nums = { -2,3,4 };
    check.checkInt(-24, o.maximumProduct(nums));

    nums = { -1,2,3,4 };
    check.checkInt(24, o.maximumProduct(nums));

    nums = { -1,-2,3,4 };
    check.checkInt(8, o.maximumProduct(nums));

    nums = { -5,-6,-1,-2,3,4,5 };
    check.checkInt(150, o.maximumProduct(nums));

    nums = { -1,-2,-3,4,5,6,7 };
    check.checkInt(210, o.maximumProduct(nums));

    nums = { -1,-2,-3,-4,-5 };
    check.checkInt(-6, o.maximumProduct(nums));
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
