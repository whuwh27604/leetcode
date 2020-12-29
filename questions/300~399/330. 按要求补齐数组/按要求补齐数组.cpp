/* 按要求补齐数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个已排序的正整数数组 nums，和一个正整数 n 。从 [1, n] 区间内选取任意个数字补充到 nums 中，使得 [1, n] 区间内的任何数字都可以用 nums 中某几个数字的和来表示。请输出满足上述要求的最少需要补充的数字个数。

示例 1:

输入: nums = [1,3], n = 6
输出: 1
解释:
根据 nums 里现有的组合 [1], [3], [1,3]，可以得出 1, 3, 4。
现在如果我们将 2 添加到 nums 中， 组合变为: [1], [2], [3], [1,3], [2,3], [1,2,3]。
其和可以表示数字 1, 2, 3, 4, 5, 6，能够覆盖 [1, 6] 区间里所有的数。
所以我们最少需要添加一个数字。
示例 2:

输入: nums = [1,5,10], n = 20
输出: 2
解释: 我们需要添加 [2, 4]。
示例 3:

输入: nums = [1,2,2], n = 5
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/patching-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        /* 1、如果[1,x)之间的数都可以表示而x不能，那么很明显x必须被添加
           2、x添加以后，[1,2x-1)之间的数都可以被表示
           3、如果(x,2x)之间存在一个数n，那么可以表示的数的上限将会扩展到2x-1+n，下一个必须添加的数是2x+n */
        int i = 0, size = nums.size(), patches = 0;
        long long x = 1;

        while (x <= n) {
            if (i < size && nums[i] <= x) {
                x += nums[i++];
            }
            else {
                x *= 2;
                ++patches;
            }
        }

        return patches;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3 };
    check.checkInt(1, o.minPatches(nums, 6));

    nums = { 1,5,10 };
    check.checkInt(2, o.minPatches(nums, 20));

    nums = { 1,2,2 };
    check.checkInt(0, o.minPatches(nums, 5));
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
