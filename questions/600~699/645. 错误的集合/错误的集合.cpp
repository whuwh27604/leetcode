/* 错误的集合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
集合 S 包含从1到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个整数并且有一个元素重复。

给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。

示例 1:

输入: nums = [1,2,2,4]
输出: [2,3]
注意:

给定数组的长度范围是 [2, 10000]。
给定的数组是无序的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/set-mismatch
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum = 0, size = nums.size();
        vector<int> ans;
        vector<bool> numbers(10001, false);

        for (int num : nums) {
            if (numbers[num]) {
                ans.push_back(num);
            }
            else {
                numbers[num] = true;
                sum += num;
            }
        }

        ans.push_back((1 + size) * size / 2 - sum);

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,2,4 };
    vector<int> actual = o.findErrorNums(nums);
    vector<int> expected = { 2,3 };
    check.checkIntVector(expected, actual);

    nums = { 1,3,3,4 };
    actual = o.findErrorNums(nums);
    expected = { 3,2 };
    check.checkIntVector(expected, actual);

    nums = { 4,3,2,4 };
    actual = o.findErrorNums(nums);
    expected = { 4,1 };
    check.checkIntVector(expected, actual);

    nums = { 3,2,1,1 };
    actual = o.findErrorNums(nums);
    expected = { 1,4 };
    check.checkIntVector(expected, actual);

    nums = { 1,1 };
    actual = o.findErrorNums(nums);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    nums = { 2,2 };
    actual = o.findErrorNums(nums);
    expected = { 2,1 };
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
