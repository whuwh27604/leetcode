/* 两数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<long long, int> existNums;
        int i, size = nums.size();

        for (i = 0; i < size; ++i) {
            long long one = nums[i], other = (long long)target - one;
            if (existNums.count(other) != 0) {
                return { existNums[other], i };
            }

            existNums[one] = i;
        }

        return {};
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,7,11,15 };
    vector<int> actual = o.twoSum(nums, 9);
    vector<int> expected = { 0,1 };
    check.checkIntVector(expected, actual);

    nums = { 2,7,4,11,4,15 };
    actual = o.twoSum(nums, 8);
    expected = { 2,4 };
    check.checkIntVector(expected, actual);

    nums = { 2,7,4,0,11,4,20 };
    actual = o.twoSum(nums, 20);
    expected = { 3,6 };
    check.checkIntVector(expected, actual);

    nums = { 2,-1,4,11,INT_MAX,15 };
    actual = o.twoSum(nums, 2147483646);
    expected = { 1,4 };
    check.checkIntVector(expected, actual);

    nums = { INT_MIN,INT_MAX };
    actual = o.twoSum(nums, -1);
    expected = { 0,1 };
    check.checkIntVector(expected, actual);

    nums = { INT_MIN,1 };
    actual = o.twoSum(nums, -2147483647);
    expected = { 0,1 };
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
