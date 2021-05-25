/* 数组元素积的符号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
已知函数 signFunc(x) 将会根据 x 的正负返回特定值：

如果 x 是正数，返回 1 。
如果 x 是负数，返回 -1 。
如果 x 是等于 0 ，返回 0 。
给你一个整数数组 nums 。令 product 为数组 nums 中所有元素值的乘积。

返回 signFunc(product) 。

 

示例 1：

输入：nums = [-1,-2,-3,-4,3,2,1]
输出：1
解释：数组中所有值的乘积是 144 ，且 signFunc(144) = 1
示例 2：

输入：nums = [1,5,0,2,-3]
输出：0
解释：数组中所有值的乘积是 0 ，且 signFunc(0) = 0
示例 3：

输入：nums = [-1,1,-1,1,-1]
输出：-1
解释：数组中所有值的乘积是 -1 ，且 signFunc(-1) = -1
 

提示：

1 <= nums.length <= 1000
-100 <= nums[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sign-of-the-product-of-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;

        for (int num : nums) {
            if (num < 0) {
                sign *= -1;
            }
            else if (num == 0) {
                return 0;
            }
        }

        return sign;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { -1,-2,-3,-4,3,2,1 };
    check.checkInt(1, o.arraySign(nums));

    nums = { 1,5,0,2,-3 };
    check.checkInt(0, o.arraySign(nums));

    nums = { -1,1,-1,1,-1 };
    check.checkInt(-1, o.arraySign(nums));
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
