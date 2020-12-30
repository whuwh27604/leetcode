/* 二分查找.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
 

提示：

你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, (nums.size() - 1));
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }

        int index = ((left + right) / 2);
        if (nums[index] == target) {
            return index;
        }

        if (nums[index] > target) {
            return binarySearch(nums, target, left, (index - 1));
        }

        return binarySearch(nums, target, (index + 1), right);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { -1,0,3,5,9,12 };
    check.checkInt(4, o.search(nums, 9));

    nums = { -1,0,3,5,9,12 };
    check.checkInt(-1, o.search(nums, 2));

    nums = { -1,0,3,5,9,12 };
    check.checkInt(-1, o.search(nums, -100));

    nums = { -1,0,3,5,9,12 };
    check.checkInt(-1, o.search(nums, 22));

    nums = { -1,0,3,5,9,12 };
    check.checkInt(0, o.search(nums, -1));

    nums = { -1,0,3,5,9,12 };
    check.checkInt(5, o.search(nums, 12));

    nums = { -1 };
    check.checkInt(0, o.search(nums, -1));

    nums = { -1 };
    check.checkInt(-1, o.search(nums, 2));
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
