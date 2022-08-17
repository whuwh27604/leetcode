/* 将数组排序的最少替换次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下表从 0 开始的整数数组 nums 。每次操作中，你可以将数组中任何一个元素替换为 任意两个 和为该元素的数字。

比方说，nums = [5,6,7] 。一次操作中，我们可以将 nums[1] 替换成 2 和 4 ，将 nums 转变成 [5,2,4,7] 。
请你执行上述操作，将数组变成元素按 非递减 顺序排列的数组，并返回所需的最少操作次数。

 

示例 1：

输入：nums = [3,9,3]
输出：2
解释：以下是将数组变成非递减顺序的步骤：
- [3,9,3] ，将9 变成 3 和 6 ，得到数组 [3,3,6,3]
- [3,3,6,3] ，将 6 变成 3 和 3 ，得到数组 [3,3,3,3,3]
总共需要 2 步将数组变成非递减有序，所以我们返回 2 。
示例 2：

输入：nums = [1,2,3,4,5]
输出：0
解释：数组已经是非递减顺序，所以我们返回 0 。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-replacements-to-sort-the-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long opers = 0;
        int i, size = nums.size(), current = nums.back();

        for (i = size - 2; i >= 0; --i) {
            int num = nums[i];
            if (num <= current) {
                current = num;
            }
            else {
                int replaceNums = num / current + (num % current == 0 ? 0 : 1);
                opers += ((long long)replaceNums - 1);
                current = num / replaceNums;
            }
        }

        return opers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,9,3 };
    check.checkLongLong(2, o.minimumReplacement(nums));

    nums = { 1,2,3,4,5 };
    check.checkLongLong(0, o.minimumReplacement(nums));

    nums = { 1,10,2,9,3,8,4,6,5 };
    check.checkLongLong(24, o.minimumReplacement(nums));
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
