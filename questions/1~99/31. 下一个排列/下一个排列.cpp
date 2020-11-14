/* 下一个排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j, size = nums.size();

        if (size == 0) {
            return;
        }

        for (i = size - 2; i >= 0 && nums[i] >= nums[i + 1]; --i) {}

        if (i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (j = size - 1; nums[j] <= nums[i]; --j) {}

        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3 };
    o.nextPermutation(nums);
    vector<int> expected = { 1,3,2 };
    check.checkIntVector(expected, nums);

    nums = { 1,2,2,3 };
    o.nextPermutation(nums);
    expected = { 1,2,3,2 };
    check.checkIntVector(expected, nums);

    nums = { 1,2,3,3 };
    o.nextPermutation(nums);
    expected = { 1,3,2,3 };
    check.checkIntVector(expected, nums);

    nums = { 3,2,1 };
    o.nextPermutation(nums);
    expected = { 1,2,3 };
    check.checkIntVector(expected, nums);

    nums = { 1,1,5 };
    o.nextPermutation(nums);
    expected = { 1,5,1 };
    check.checkIntVector(expected, nums);

    nums = {  };
    o.nextPermutation(nums);
    expected = {  };
    check.checkIntVector(expected, nums);

    nums = { 1,5 };
    o.nextPermutation(nums);
    expected = { 5,1 };
    check.checkIntVector(expected, nums);

    nums = { 5,1 };
    o.nextPermutation(nums);
    expected = { 1,5 };
    check.checkIntVector(expected, nums);

    nums = { 0,5,4,3,2,1 };
    o.nextPermutation(nums);
    expected = { 1,0,2,3,4,5 };
    check.checkIntVector(expected, nums);

    nums = { 0,0,5,4,3,2,1,1 };
    o.nextPermutation(nums);
    expected = { 0,1,0,1,2,3,4,5 };
    check.checkIntVector(expected, nums);

    nums = { 2,3,1 };
    o.nextPermutation(nums);
    expected = { 3,1,2 };
    check.checkIntVector(expected, nums);
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
