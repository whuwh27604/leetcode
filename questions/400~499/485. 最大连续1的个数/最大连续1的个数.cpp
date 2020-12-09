/* 最大连续1的个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二进制数组， 计算其中最大连续1的个数。

示例 1:

输入: [1,1,0,1,1,1]
输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
注意：

输入的数组只包含 0 和1。
输入数组的长度是正整数，且不超过 10,000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-consecutive-ones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int consecutiveOnes = 0, maxConsecutiveOnes = 0;

        for (unsigned int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                consecutiveOnes++;
            }
            else {
                maxConsecutiveOnes = max(maxConsecutiveOnes, consecutiveOnes);
                consecutiveOnes = 0;
            }
        }

        return max(maxConsecutiveOnes, consecutiveOnes);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,1,0,1,1,1 };
    check.checkInt(3, o.findMaxConsecutiveOnes(nums));

    nums = { 0 };
    check.checkInt(0, o.findMaxConsecutiveOnes(nums));

    nums = { 1 };
    check.checkInt(1, o.findMaxConsecutiveOnes(nums));

    nums = { 0,1,1,1 };
    check.checkInt(3, o.findMaxConsecutiveOnes(nums));

    nums = { 1,1,1,0 };
    check.checkInt(3, o.findMaxConsecutiveOnes(nums));

    nums = { 1,1,1,0,1,1 };
    check.checkInt(3, o.findMaxConsecutiveOnes(nums));

    nums = { 0,1,0,1,0,1,0,1,1 };
    check.checkInt(2, o.findMaxConsecutiveOnes(nums));

    nums = { 0,1,0,1,0,1,0,1,1,0,0,0 };
    check.checkInt(2, o.findMaxConsecutiveOnes(nums));
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
