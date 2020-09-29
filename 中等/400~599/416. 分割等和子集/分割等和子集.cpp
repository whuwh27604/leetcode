/* 分割等和子集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:

输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].
 

示例 2:

输入: [1, 2, 3, 5]

输出: false

解释: 数组不能分割成两个元素和相等的子集.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-equal-subset-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int i, j, size = nums.size(), sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if ((sum % 2) != 0) {
            return false;
        }
        int half = sum / 2;

        // dp纵坐标表示数的个数，每次新增一个数；横坐标表示前i+1个数能够组成的和，则dp[i][j+nums[i]]=dp[i-1][j]?true:false。纵坐标可以优化，只保存前一行数据即可。
        vector<bool> dp(half + 1, false);

        for (i = 0; i < size; i++) {
            int num = nums[i];
            if (num > half) {
                return false;  // 如果某个数超过了一半，可以直接失败了
            }

            int maxJ = half - num;
            for (j = maxJ; j > 0; j--) {  // 只能从大往小循环，如果从小往大j+num先把后面的值改了，再循环到后面的时候引起误判
                if (dp[j]) {
                    dp[j + num] = true;
                }
            }

            dp[num] = true;
            if (dp[half] == true) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2 };
    check.checkBool(false, o.canPartition(nums));

    nums = { 2,3 };
    check.checkBool(false, o.canPartition(nums));

    nums = { 2,4 };
    check.checkBool(false, o.canPartition(nums));

    nums = { 2,2 };
    check.checkBool(true, o.canPartition(nums));

    nums = { 1,5,11,5 };
    check.checkBool(true, o.canPartition(nums));

    nums = { 1,2,3,5 };
    check.checkBool(false, o.canPartition(nums));

    nums = { 12,2,2,2,2,2 };
    check.checkBool(false, o.canPartition(nums));

    nums = { 1,2,5 };
    check.checkBool(false, o.canPartition(nums));

    nums = { 2,2,3,5 };
    check.checkBool(false, o.canPartition(nums));

    nums = { 23,13,11,7,6,5,5 };
    check.checkBool(true, o.canPartition(nums));
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
