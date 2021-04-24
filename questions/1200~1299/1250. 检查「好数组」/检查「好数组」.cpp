/* 检查「好数组」.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 nums，你需要从中任选一些子集，然后将子集中每一个数乘以一个 任意整数，并求出他们的和。

假如该和结果为 1，那么原数组就是一个「好数组」，则返回 True；否则请返回 False。

 

示例 1：

输入：nums = [12,5,7,23]
输出：true
解释：挑选数字 5 和 7。
5*3 + 7*(-2) = 1
示例 2：

输入：nums = [29,6,10]
输出：true
解释：挑选数字 29, 6 和 10。
29*1 + 6*(-3) + 10*(-1) = 1
示例 3：

输入：nums = [3,6]
输出：false
 

提示：

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-it-is-a-good-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        // ax+by=z 有整数解当且仅当z是x,y的最大公约数的倍数。此题z等于1，所以最大公约数只能是1。
        int divisor = nums[0];

        for (int num : nums) {
            divisor = gcd(num, divisor);
            if (divisor == 1) {
                return true;
            }
        }

        return false;
    }

    int gcd(int x, int y) {
        return (y == 0) ? x : gcd(y, x % y);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1 };
    check.checkBool(true, o.isGoodArray(nums));

    nums = { 2 };
    check.checkBool(false, o.isGoodArray(nums));

    nums = { 12,5,7,23 };
    check.checkBool(true, o.isGoodArray(nums));

    nums = { 29,6,10 };
    check.checkBool(true, o.isGoodArray(nums));

    nums = { 3,6 };
    check.checkBool(false, o.isGoodArray(nums));
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
