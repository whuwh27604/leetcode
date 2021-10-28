/* 找出数组的最大公约数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，返回数组中最大数和最小数的 最大公约数 。

两个数的 最大公约数 是能够被两个数整除的最大正整数。

 

示例 1：

输入：nums = [2,5,6,9,10]
输出：2
解释：
nums 中最小的数是 2
nums 中最大的数是 10
2 和 10 的最大公约数是 2
示例 2：

输入：nums = [7,5,6,8,3]
输出：1
解释：
nums 中最小的数是 3
nums 中最大的数是 8
3 和 8 的最大公约数是 1
示例 3：

输入：nums = [3,3]
输出：3
解释：
nums 中最小的数是 3
nums 中最大的数是 3
3 和 3 的最大公约数是 3
 

提示：

2 <= nums.length <= 1000
1 <= nums[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-greatest-common-divisor-of-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(*max_element(nums.begin(), nums.end()), *min_element(nums.begin(), nums.end()));
    }

    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,5,6,9,10 };
    check.checkInt(2, o.findGCD(nums));

    nums = { 7,5,6,8,3 };
    check.checkInt(1, o.findGCD(nums));

    nums = { 3,3 };
    check.checkInt(3, o.findGCD(nums));
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
