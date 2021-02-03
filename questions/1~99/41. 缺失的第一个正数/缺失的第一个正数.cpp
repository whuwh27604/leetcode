/* 缺失的第一个正数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

 

进阶：你可以实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案吗？

 

示例 1：

输入：nums = [1,2,0]
输出：3
示例 2：

输入：nums = [3,4,-1,1]
输出：2
示例 3：

输入：nums = [7,8,9,11,12]
输出：1
 

提示：

0 <= nums.length <= 300
-231 <= nums[i] <= 231 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-missing-positive
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i, size = nums.size();

        for (i = 0; i < size; ++i) {
            if (nums[i] < 1 || nums[i] > size) {  // 区间[1,size]以外的数对结果没有任何影响
                nums[i] = 0;
            }
        }

        for (i = 0; i < size; ++i) {
            int index = nums[i] % 1000;
            if (index != 0) {
                nums[index - 1] += 1000;  // 标记已经存在的数
            }
        }

        for (i = 0; i < size; ++i) {
            if (nums[i] < 1000) {
                return i + 1;  // 查找不存在的最小正整数
            }
        }

        return size + 1;  // [1,size]都存在
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,0 };
    check.checkInt(3, o.firstMissingPositive(nums));

    nums = { 3,4,-1,1 };
    check.checkInt(2, o.firstMissingPositive(nums));

    nums = { 7,8,9,11,12 };
    check.checkInt(1, o.firstMissingPositive(nums));

    nums = { 1,1,3,3,4 };
    check.checkInt(2, o.firstMissingPositive(nums));
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
