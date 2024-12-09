/* 转换数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums，它表示一个循环数组。请你遵循以下规则创建一个大小 相同 的新数组 result ：

对于每个下标 i（其中 0 <= i < nums.length），独立执行以下操作：
如果 nums[i] > 0：从下标 i 开始，向 右 移动 nums[i] 步，在循环数组中落脚的下标对应的值赋给 result[i]。
如果 nums[i] < 0：从下标 i 开始，向 左 移动 abs(nums[i]) 步，在循环数组中落脚的下标对应的值赋给 result[i]。
如果 nums[i] == 0：将 nums[i] 的值赋给 result[i]。
返回新数组 result。

注意：由于 nums 是循环数组，向右移动超过最后一个元素时将回到开头，向左移动超过第一个元素时将回到末尾。



示例 1：

输入： nums = [3,-2,1,1]

输出： [1,1,1,3]

解释：

对于 nums[0] 等于 3，向右移动 3 步到 nums[3]，因此 result[0] 为 1。
对于 nums[1] 等于 -2，向左移动 2 步到 nums[3]，因此 result[1] 为 1。
对于 nums[2] 等于 1，向右移动 1 步到 nums[3]，因此 result[2] 为 1。
对于 nums[3] 等于 1，向右移动 1 步到 nums[0]，因此 result[3] 为 3。
示例 2：

输入： nums = [-1,4,-1]

输出： [-1,-1,4]

解释：

对于 nums[0] 等于 -1，向左移动 1 步到 nums[2]，因此 result[0] 为 -1。
对于 nums[1] 等于 4，向右移动 4 步到 nums[2]，因此 result[1] 为 -1。
对于 nums[2] 等于 -1，向左移动 1 步到 nums[1]，因此 result[2] 为 4。


提示：

1 <= nums.length <= 100
-100 <= nums[i] <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int size = (int)nums.size();
        vector<int> result(size);

        for (int i = 0; i < size; ++i) {
            int n = nums[i];
            result[i] = n > 0 ? nums[(i + n) % size] : nums[(i + size - (-n) % size) % size];
        }

        return result;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3,-2,1,1 };
    vector<int> actual = o.constructTransformedArray(nums);
    vector<int> expected = { 1,1,1,3 };
    check.checkIntVector(expected, actual);

    nums = { -1,4,-1 };
    actual = o.constructTransformedArray(nums);
    expected = { -1,-1,4 };
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
