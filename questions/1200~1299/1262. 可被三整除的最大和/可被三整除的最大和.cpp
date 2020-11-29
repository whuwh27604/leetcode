/* 可被三整除的最大和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums，请你找出并返回能被三整除的元素最大和。

 

示例 1：

输入：nums = [3,6,5,1,8]
输出：18
解释：选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。
示例 2：

输入：nums = [4]
输出：0
解释：4 不能被 3 整除，所以无法选出数字，返回 0。
示例 3：

输入：nums = [1,2,3,4,4]
输出：12
解释：选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。
 

提示：

1 <= nums.length <= 4 * 10^4
1 <= nums[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/greatest-sum-divisible-by-three
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int invalid = 100000, minR1 = invalid, secondMinR1 = invalid, minR2 = invalid, secondMinR2 = invalid;
        int sum = getSum(nums, minR1, secondMinR1, minR2, secondMinR2);

        if (sum % 3 == 0) {
            return sum;
        }

        if (sum % 3 == 1) {
            return sum - min(minR1, minR2 + secondMinR2);
        }

        return sum - min(minR2, minR1 + secondMinR1);
    }

    int getSum(vector<int>& nums, int& minR1, int& secondMinR1, int& minR2, int& secondMinR2) {
        int sum = 0;

        for (int num : nums) {
            sum += num;

            if (num % 3 == 1) {
                if (num < minR1) {
                    secondMinR1 = minR1;
                    minR1 = num;
                }
                else if (num < secondMinR1) {
                    secondMinR1 = num;
                }
            }

            if (num % 3 == 2) {
                if (num < minR2) {
                    secondMinR2 = minR2;
                    minR2 = num;
                }
                else if (num < secondMinR2) {
                    secondMinR2 = num;
                }
            }
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,6,5,1,8 };
    check.checkInt(18, o.maxSumDivThree(nums));

    nums = { 4 };
    check.checkInt(0, o.maxSumDivThree(nums));

    nums = { 5 };
    check.checkInt(0, o.maxSumDivThree(nums));

    nums = { 6 };
    check.checkInt(6, o.maxSumDivThree(nums));

    nums = { 1,2,3,4,4 };
    check.checkInt(12, o.maxSumDivThree(nums));

    nums = { 3,3,3,4 };
    check.checkInt(9, o.maxSumDivThree(nums));

    nums = { 3,3,3,7,2,2,2 };
    check.checkInt(18, o.maxSumDivThree(nums));

    nums = { 3,3,3,5,1,1,1 };
    check.checkInt(15, o.maxSumDivThree(nums));

    nums = { 3,3,3,5,4,4,4 };
    check.checkInt(21, o.maxSumDivThree(nums));
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
