/* 下一个更大元素 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

示例 1:

输入: [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数；
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
注意: 输入数组的长度不会超过 10000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        int i, size = nums.size(), maximum = nums[0];
        vector<int> nextGreaterNums(size, 0);
        stack<pair<int, int>> noGreaterNums;
        noGreaterNums.push({ nums[0], 0 });

        for (i = 1; i < size; i++) {
            int num = nums[i];
            maximum = maximum > num ? maximum : num;

            while (!noGreaterNums.empty() && (num > noGreaterNums.top().first)) {
                nextGreaterNums[noGreaterNums.top().second] = num;
                noGreaterNums.pop();
            }

            noGreaterNums.push({ num, i });
        }

        i = 0;
        while (noGreaterNums.top().first != maximum) {
            int num = nums[i++];
            while (num > noGreaterNums.top().first) {
                nextGreaterNums[noGreaterNums.top().second] = num;
                noGreaterNums.pop();
            }
        }

        while (!noGreaterNums.empty()) {
            nextGreaterNums[noGreaterNums.top().second] = -1;
            noGreaterNums.pop();
        }

        return nextGreaterNums;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,1 };
    vector<int> actual = o.nextGreaterElements(nums);
    vector<int> expected = { 2,-1,2 };
    check.checkIntVector(expected, actual);

    nums = {  };
    actual = o.nextGreaterElements(nums);
    expected = {  };
    check.checkIntVector(expected, actual);

    nums = { 0 };
    actual = o.nextGreaterElements(nums);
    expected = { -1 };
    check.checkIntVector(expected, actual);

    nums = { 1,2 };
    actual = o.nextGreaterElements(nums);
    expected = { 2,-1 };
    check.checkIntVector(expected, actual);

    nums = { 2,1 };
    actual = o.nextGreaterElements(nums);
    expected = { -1,2 };
    check.checkIntVector(expected, actual);

    nums = { 1,1 };
    actual = o.nextGreaterElements(nums);
    expected = { -1,-1 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,3,4,5 };
    actual = o.nextGreaterElements(nums);
    expected = { 2,3,4,5,-1 };
    check.checkIntVector(expected, actual);

    nums = { 5,4,3,2,1 };
    actual = o.nextGreaterElements(nums);
    expected = { -1,5,5,5,5 };
    check.checkIntVector(expected, actual);

    nums = { 5,4,3,5,2,1 };
    actual = o.nextGreaterElements(nums);
    expected = { -1,5,5,-1,5,5 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,1,1 };
    actual = o.nextGreaterElements(nums);
    expected = { -1,-1,-1,-1 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,2,2 };
    actual = o.nextGreaterElements(nums);
    expected = { 2,-1,-1,-1 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,3,4,5,5,4,3,2,1,INT_MIN,INT_MAX,0,0,INT_MAX,INT_MIN,1,1,5,5,2,2,4,4,3,3 };
    actual = o.nextGreaterElements(nums);
    expected = { 2,3,4,5,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,-1,INT_MAX,INT_MAX,-1,1,5,5,INT_MAX,INT_MAX,4,4,5,5,4,4 };
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
