/* 环形数组循环.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个含有正整数和负整数的环形数组 nums。 如果某个索引中的数 k 为正数，则向前移动 k 个索引。相反，如果是负数 (-k)，则向后移动 k 个索引。因为数组是环形的，所以可以假设最后一个元素的下一个元素是第一个元素，而第一个元素的前一个元素是最后一个元素。

确定 nums 中是否存在循环（或周期）。循环必须在相同的索引处开始和结束并且循环长度 > 1。此外，一个循环中的所有运动都必须沿着同一方向进行。换句话说，一个循环中不能同时包括向前的运动和向后的运动。
 

示例 1：

输入：[2,-1,1,2,2]
输出：true
解释：存在循环，按索引 0 -> 2 -> 3 -> 0 。循环长度为 3 。
示例 2：

输入：[-1,2]
输出：false
解释：按索引 1 -> 1 -> 1 ... 的运动无法构成循环，因为循环的长度为 1 。根据定义，循环的长度必须大于 1 。
示例 3:

输入：[-2,1,-1,-2,-2]
输出：false
解释：按索引 1 -> 2 -> 1 -> ... 的运动无法构成循环，因为按索引 1 -> 2 的运动是向前的运动，而按索引 2 -> 1 的运动是向后的运动。一个循环中的所有运动都必须沿着同一方向进行。
 

提示：

-1000 ≤ nums[i] ≤ 1000
nums[i] ≠ 0
0 ≤ nums.length ≤ 5000
 

进阶：

你能写出时间时间复杂度为 O(n) 和额外空间复杂度为 O(1) 的算法吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/circular-array-loop
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int index = 0, size = nums.size();
        if (size < 2) {
            return false;
        }

        while (hasNext(nums, index)) {
            int originalIndex = index;
            int slowIndex = index;
            int fastIndex = getNextIndex(index, nums[index], size);
            if (slowIndex == fastIndex) {  // 一个数自循环不算
                nums[index] = 0;
                continue;
            }

            while (slowIndex != fastIndex) {
                if (nums[fastIndex] == 0) {  // 走到了前面已经验证过不是循环的路上
                    break;
                }
                if ((nums[fastIndex] ^ nums[originalIndex]) < 0) {  // 两个数方向相反，说明不是循环
                    break;
                }

                int tmp = getNextIndex(fastIndex, nums[fastIndex], size);
                if (tmp == fastIndex) {  // 任何时候一个数自循环都不算
                    nums[fastIndex] = 0;
                    break;
                }
                fastIndex = tmp;
                slowIndex = getNextIndex(slowIndex, nums[slowIndex], size);

                if (nums[fastIndex] == 0) {
                    break;
                }
                if ((nums[fastIndex] ^ nums[originalIndex]) < 0) {
                    break;
                }

                tmp = getNextIndex(fastIndex, nums[fastIndex], size);
                if (tmp == fastIndex) {  // 任何时候一个数自循环都不算
                    nums[fastIndex] = 0;
                    break;
                }
                fastIndex = tmp;
            }

            if (slowIndex == fastIndex) {  // 快慢指针相等说明找到一个循环
                return true;
            }

            while (originalIndex != fastIndex) {  // 把已经验证的路径上所有点置非循环
                int tmp = originalIndex;
                originalIndex = getNextIndex(originalIndex, nums[originalIndex], size);
                nums[tmp] = 0;
            }

            index = fastIndex;
        }

        return false;
    }

    bool hasNext(vector<int>& nums, int& index) {
        int originalIndex = index;

        while (nums[index] == 0) {
            index++;
            if (index == nums.size()) {
                index = 0;
            }
            if (index == originalIndex) {
                return false;
            }
        }

        return true;
    }

    int getNextIndex(int current, int num, int size) {
        num %= size;
        if (num > 0) {
            return (current + num) % size;
        }

        current += num;
        return (current < 0) ? current + size : current;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2,-1,1,2,2 };
    check.checkBool(true, o.circularArrayLoop(nums));

    nums = { 2,-1,1,-2,-2 };
    check.checkBool(false, o.circularArrayLoop(nums));

    nums = { -1,2 };
    check.checkBool(false, o.circularArrayLoop(nums));

    nums = { -2,1,-1,-2,-2 };
    check.checkBool(false, o.circularArrayLoop(nums));

    nums = {  };
    check.checkBool(false, o.circularArrayLoop(nums));

    nums = { 1 };
    check.checkBool(false, o.circularArrayLoop(nums));

    nums = { 3,3 };
    check.checkBool(true, o.circularArrayLoop(nums));

    nums = { -3,-3 };
    check.checkBool(true, o.circularArrayLoop(nums));

    nums = { 2,4 };
    check.checkBool(false, o.circularArrayLoop(nums));

    nums = { 3,2,1 };
    check.checkBool(false, o.circularArrayLoop(nums));

    nums = { 3,1,2 };
    check.checkBool(true, o.circularArrayLoop(nums));

    nums = { -1,-2,-3,-4,-5 };
    check.checkBool(false, o.circularArrayLoop(nums));
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
