/* 寻找重复数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

示例 1:

输入: [1,3,4,2,2]
输出: 2
示例 2:

输入: [3,1,3,4,2]
输出: 3
说明：

不能更改原数组（假设数组是只读的）。
只能使用额外的 O(1) 的空间。
时间复杂度小于 O(n2) 。
数组中只有一个重复的数字，但它可能不止重复出现一次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-duplicate-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0], slow = fast;

        do {
            fast = nums[fast];
            fast = nums[fast];
            slow = nums[slow];
        } while (fast != slow);

        slow = nums[0];
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }

        return fast;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,4,2,2 };
    check.checkInt(2, o.findDuplicate(nums));

    nums = { 3,1,3,4,2 };
    check.checkInt(3, o.findDuplicate(nums));

    nums = { 1,1 };
    check.checkInt(1, o.findDuplicate(nums));

    nums = { 2,1,2 };
    check.checkInt(2, o.findDuplicate(nums));

    nums = { 1,1,2 };
    check.checkInt(1, o.findDuplicate(nums));

    nums = { 2,5,9,6,9,3,8,9,7,1 };
    check.checkInt(9, o.findDuplicate(nums));

    nums = { 4,1,3,2,4 };
    check.checkInt(4, o.findDuplicate(nums));

    nums = { 1,11,2,19,3,18,4,17,5,16,6,15,7,14,8,13,9,12,10,11 };
    check.checkInt(11, o.findDuplicate(nums));
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
