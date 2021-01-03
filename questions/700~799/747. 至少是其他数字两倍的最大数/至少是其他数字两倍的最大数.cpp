/* 至少是其他数字两倍的最大数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个给定的数组nums中，总是存在一个最大元素 。

查找数组中的最大元素是否至少是数组中每个其他数字的两倍。

如果是，则返回最大元素的索引，否则返回-1。

示例 1:

输入: nums = [3, 6, 1, 0]
输出: 1
解释: 6是最大的整数, 对于数组中的其他整数,
6大于数组中其他元素的两倍。6的索引是1, 所以我们返回1.
 

示例 2:

输入: nums = [1, 2, 3, 4]
输出: -1
解释: 4没有超过3的两倍大, 所以我们返回 -1.
 

提示:

nums 的长度范围在[1, 50].
每个 nums[i] 的整数范围在 [0, 100].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-number-at-least-twice-of-others
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int firstMax = nums[0], secondMax = INT_MIN;
        int index = 0;
        for (unsigned int i = 1; i < nums.size(); i++) {
            int number = nums[i];
            if (number > firstMax) {
                secondMax = firstMax;
                firstMax = number;
                index = i;
            }
            else if (number > secondMax) {
                secondMax = number;
            }
        }

        if (firstMax >= (secondMax * 2)) {
            return index;
        }
        return -1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3, 6, 1, 0 };
    check.checkInt(1, o.dominantIndex(nums));

    nums = { 1, 2, 3, 4 };
    check.checkInt(-1, o.dominantIndex(nums));

    nums = { 1 };
    check.checkInt(0, o.dominantIndex(nums));

    nums = { 2, 4 };
    check.checkInt(1, o.dominantIndex(nums));

    nums = { 4, 2 };
    check.checkInt(0, o.dominantIndex(nums));

    nums = { 3, 4 };
    check.checkInt(-1, o.dominantIndex(nums));

    nums = { 1, 1, 4, 4 };
    check.checkInt(-1, o.dominantIndex(nums));

    nums = { 1, 1, 1, 4 };
    check.checkInt(3, o.dominantIndex(nums));
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
