/* 检查数组是否是好的.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，如果它是数组 base[n] 的一个排列，我们称它是个 好 数组。

base[n] = [1, 2, ..., n - 1, n, n] （换句话说，它是一个长度为 n + 1 且包含 1 到 n - 1 恰好各一次，包含 n  两次的一个数组）。比方说，base[1] = [1, 1] ，base[3] = [1, 2, 3, 3] 。

如果数组是一个好数组，请你返回 true ，否则返回 false 。

注意：数组的排列是这些数字按任意顺序排布后重新得到的数组。



示例 1：

输入：nums = [2, 1, 3]
输出：false
解释：因为数组的最大元素是 3 ，唯一可以构成这个数组的 base[n] 对应的 n = 3 。但是 base[3] 有 4 个元素，但数组 nums 只有 3 个元素，所以无法得到 base[3] = [1, 2, 3, 3] 的排列，所以答案为 false 。
示例 2：

输入：nums = [1, 3, 3, 2]
输出：true
解释：因为数组的最大元素是 3 ，唯一可以构成这个数组的 base[n] 对应的 n = 3 ，可以看出数组是 base[3] = [1, 2, 3, 3] 的一个排列（交换 nums 中第二个和第四个元素）。所以答案为 true 。
示例 3：

输入：nums = [1, 1]
输出：true
解释：因为数组的最大元素是 1 ，唯一可以构成这个数组的 base[n] 对应的 n = 1，可以看出数组是 base[1] = [1, 1] 的一个排列。所以答案为 true 。
示例 4：

输入：nums = [3, 4, 4, 1, 2, 1]
输出：false
解释：因为数组的最大元素是 4 ，唯一可以构成这个数组的 base[n] 对应的 n = 4 。但是 base[n] 有 5 个元素而 nums 有 6 个元素。所以答案为 false 。


提示：

1 <= nums.length <= 100
1 <= num[i] <= 200
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int size = nums.size(), n = size - 1;
        vector<int> count(size, 0);

        for (int num : nums) {
            if (num > n) {
                return false;
            }

            ++count[num];
        }

        for (int i = 1; i < n; ++i) {
            if (count[i] != 1) {
                return false;
            }
        }

        return count[n] == 2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,1,3 };
    check.checkBool(false, o.isGood(nums));

    nums = { 3,4,4,1,2,1 };
    check.checkBool(false, o.isGood(nums));

    nums = { 1,3,3,2 };
    check.checkBool(true, o.isGood(nums));

    nums = { 1,1 };
    check.checkBool(true, o.isGood(nums));
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
