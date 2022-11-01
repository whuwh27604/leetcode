/* 可被三整除的偶数的平均值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由正整数组成的整数数组 nums ，返回其中可被 3 整除的所有偶数的平均值。

注意：n 个元素的平均值等于 n 个元素 求和 再除以 n ，结果 向下取整 到最接近的整数。

 

示例 1：

输入：nums = [1,3,6,10,12,15]
输出：9
解释：6 和 12 是可以被 3 整除的偶数。(6 + 12) / 2 = 9 。
示例 2：

输入：nums = [1,2,4,7,10]
输出：0
解释：不存在满足题目要求的整数，所以返回 0 。
 

提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/average-value-of-even-numbers-that-are-divisible-by-three
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int count = 0, sum = 0;

        for (int num : nums) {
            if (num % 6 == 0) {
                ++count;
                sum += num;
            }
        }

        return count == 0 ? 0 : sum / count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,6,10,12,15 };
    check.checkInt(9, o.averageValue(nums));

    nums = { 1,2,4,7,10 };
    check.checkInt(0, o.averageValue(nums));
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
