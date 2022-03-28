/* 美化数组的最少删除数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums ，如果满足下述条件，则认为数组 nums 是一个 美丽数组 ：

nums.length 为偶数
对所有满足 i % 2 == 0 的下标 i ，nums[i] != nums[i + 1] 均成立
注意，空数组同样认为是美丽数组。

你可以从 nums 中删除任意数量的元素。当你删除一个元素时，被删除元素右侧的所有元素将会向左移动一个单位以填补空缺，而左侧的元素将会保持 不变 。

返回使 nums 变为美丽数组所需删除的 最少 元素数目。

 

示例 1：

输入：nums = [1,1,2,3,5]
输出：1
解释：可以删除 nums[0] 或 nums[1] ，这样得到的 nums = [1,2,3,5] 是一个美丽数组。可以证明，要想使 nums 变为美丽数组，至少需要删除 1 个元素。
示例 2：

输入：nums = [1,1,2,2,3,3]
输出：2
解释：可以删除 nums[0] 和 nums[5] ，这样得到的 nums = [1,2,2,3] 是一个美丽数组。可以证明，要想使 nums 变为美丽数组，至少需要删除 2 个元素。
 

提示：

1 <= nums.length <= 105
0 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-deletions-to-make-array-beautiful
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int i = 0, j, size = nums.size(), del = 0;

        while (i < size) {            
            for (j = i + 1; j < size && nums[j] == nums[i]; ++j) {}
            del += (j - 1 - i);
            i = j + 1;
        }

        return i == size ? del : del + 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,1,2,3,5 };
    check.checkInt(1, o.minDeletion(nums));

    nums = { 1,1,2,2,3,3 };
    check.checkInt(2, o.minDeletion(nums));

    nums = { 1 };
    check.checkInt(1, o.minDeletion(nums));

    nums = { 1,2 };
    check.checkInt(0, o.minDeletion(nums));

    nums = { 1,1 };
    check.checkInt(2, o.minDeletion(nums));
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
