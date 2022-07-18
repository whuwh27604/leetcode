/* 使数组可以被整除的最少删除次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个正整数数组 nums 和 numsDivide 。你可以从 nums 中删除任意数目的元素。

请你返回使 nums 中 最小 元素可以整除 numsDivide 中所有元素的 最少 删除次数。如果无法得到这样的元素，返回 -1 。

如果 y % x == 0 ，那么我们说整数 x 整除 y 。

 

示例 1：

输入：nums = [2,3,2,4,3], numsDivide = [9,6,9,3,15]
输出：2
解释：
[2,3,2,4,3] 中最小元素是 2 ，它无法整除 numsDivide 中所有元素。
我们从 nums 中删除 2 个大小为 2 的元素，得到 nums = [3,4,3] 。
[3,4,3] 中最小元素为 3 ，它可以整除 numsDivide 中所有元素。
可以证明 2 是最少删除次数。
示例 2：

输入：nums = [4,3,6], numsDivide = [8,2,6,10]
输出：-1
解释：
我们想 nums 中的最小元素可以整除 numsDivide 中的所有元素。
没有任何办法可以达到这一目的。
 

提示：

1 <= nums.length, numsDivide.length <= 105
1 <= nums[i], numsDivide[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-deletions-to-make-array-divisible
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int GCD = getGCD(numsDivide);
        int minimum = getMin(nums, GCD);

        return minimum == INT_MAX ? -1 : getMinOperations(nums, minimum);
    }

    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }

    int getGCD(vector<int>& numsDivide) {
        int GCD = numsDivide[0];

        for (int i = 1; i < (int)numsDivide.size(); ++i) {
            GCD = gcd(GCD, numsDivide[i]);
        }

        return GCD;
    }

    int getMin(vector<int>& nums, int GCD) {
        int minimum = INT_MAX;

        for (int num : nums) {
            if (GCD % num == 0) {
                minimum = min(minimum, num);
            }
        }

        return minimum;
    }

    int getMinOperations(vector<int>& nums, int minimum) {
        int opers = 0;

        for (int num : nums) {
            if (num < minimum) {
                ++opers;
            }
        }

        return opers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,3,2,4,3 };
    vector<int> numsDivide = { 9,6,9,3,15 };
    check.checkInt(2, o.minOperations(nums, numsDivide));

    nums = { 4,3,6 };
    numsDivide = { 8,2,6,10 };
    check.checkInt(-1, o.minOperations(nums, numsDivide));
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
