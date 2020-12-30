/* 寻找数组的中心索引.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。

我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。

如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。

示例 1:

输入:
nums = [1, 7, 3, 6, 5, 6]
输出: 3
解释:
索引3 (nums[3] = 6) 的左侧数之和(1 + 7 + 3 = 11)，与右侧数之和(5 + 6 = 11)相等。
同时, 3 也是第一个符合要求的中心索引。
示例 2:

输入:
nums = [1, 2, 3]
输出: -1
解释:
数组中不存在满足此条件的中心索引。
说明:

nums 的长度范围为 [0, 10000]。
任何一个 nums[i] 将会是一个范围在 [-1000, 1000]的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-pivot-index
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {  // 中心索引可以是0或者nums.size() - 1，即左侧或者右侧可以没有元素
        if (nums.empty()) {
            return -1;
        }

        int allSum = 0, leftSum = 0;
        for (unsigned int i = 0; i < nums.size(); i++) {
            allSum += nums[i];
        }

        if (nums[0] == allSum) {
            return 0;
        }

        for (unsigned int j = 0; j < (nums.size() - 1); j++) {
            leftSum += nums[j];
            if ((leftSum * 2 + nums[j + 1]) == allSum) {
                return (j + 1);
            }
        }

        return -1;
    }
};

int main()
{
    Solution o;
    CheckResult check; 
    
    vector<int> nums = { 1, 7, 3, 6, 5, 6 };
    check.checkInt(3, o.pivotIndex(nums));

    nums = { 1, 2, 3 };
    check.checkInt(-1, o.pivotIndex(nums));

    nums = {  };
    check.checkInt(-1, o.pivotIndex(nums));

    nums = { 3 };
    check.checkInt(0, o.pivotIndex(nums));

    nums = { 1, 2 };
    check.checkInt(-1, o.pivotIndex(nums));

    nums = { 0, 2 };
    check.checkInt(1, o.pivotIndex(nums));

    nums = { 3, 0 };
    check.checkInt(0, o.pivotIndex(nums));

    nums = { 0, 0 };
    check.checkInt(0, o.pivotIndex(nums));

    nums = { 0, 0, 0 };
    check.checkInt(0, o.pivotIndex(nums));

    nums = { 1, 2, 1 };
    check.checkInt(1, o.pivotIndex(nums));

    nums = { 5, 2, 2, -2, 2,3 };
    check.checkInt(1, o.pivotIndex(nums));

    nums = { 0, 2, -2 };
    check.checkInt(0, o.pivotIndex(nums));

    nums = { -1,-1,-1,0,1,1 };
    check.checkInt(0, o.pivotIndex(nums));

    nums = { -1,-1,-1,1,1 };
    check.checkInt(0, o.pivotIndex(nums));

    nums = { -1,-1,1,1,1 };
    check.checkInt(4, o.pivotIndex(nums));
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
