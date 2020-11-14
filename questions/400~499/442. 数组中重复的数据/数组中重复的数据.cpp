/* 数组中重复的数据.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。

找到所有出现两次的元素。

你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？

示例：

输入:
[4,3,2,7,8,2,3,1]

输出:
[2,3]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-duplicates-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicateNums;

        for (int num : nums) {
            num = abs(num);
            int index = num - 1;
            if (nums[index] < 0) {
                duplicateNums.push_back(num);
            }
            else {
                nums[index] = -nums[index];
            }
        }

        return duplicateNums;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 4,3,2,7,8,2,3,1 };
    vector<int> actual = o.findDuplicates(nums);
    vector<int> expected = { 2,3 };
    check.checkIntVector(expected, actual);

    nums = { 4,3,2,4 };
    actual = o.findDuplicates(nums);
    expected = { 4 };
    check.checkIntVector(expected, actual);

    nums = { 1 };
    actual = o.findDuplicates(nums);
    expected = {  };
    check.checkIntVector(expected, actual);

    nums = { 1,2 };
    actual = o.findDuplicates(nums);
    expected = {  };
    check.checkIntVector(expected, actual);

    nums = { 1,1 };
    actual = o.findDuplicates(nums);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    nums = { 2,2 };
    actual = o.findDuplicates(nums);
    expected = { 2 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,3,1 };
    actual = o.findDuplicates(nums);
    expected = { 1 };
    check.checkIntVector(expected, actual);
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
