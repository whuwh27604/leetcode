/* 最小化数对的最大差值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 和一个整数 p 。请你从 nums 中找到 p 个下标对，每个下标对对应数值取差值，你需要使得这 p 个差值的 最大值 最小。同时，你需要确保每个下标在这 p 个下标对中最多出现一次。

对于一个下标对 i 和 j ，这一对的差值为 |nums[i] - nums[j]| ，其中 |x| 表示 x 的 绝对值 。

请你返回 p 个下标对对应数值 最大差值 的 最小值 。



示例 1：

输入：nums = [10,1,2,7,1,3], p = 2
输出：1
解释：第一个下标对选择 1 和 4 ，第二个下标对选择 2 和 5 。
最大差值为 max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1 。所以我们返回 1 。
示例 2：

输入：nums = [4,2,1,2], p = 1
输出：0
解释：选择下标 1 和 3 构成下标对。差值为 |2 - 2| = 0 ，这是最大差值的最小值。


提示：

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= p <= (nums.length)/2
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) {
            return 0;
        }

        int low = 0, high = 1000000000, ans = high;

        sort(nums.begin(), nums.end());

        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(nums, p, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    bool check(vector<int>& nums, int p, int diff) {
        int size = nums.size(), pairs = 0;

        for (int i = 1; i < size; ++i) {
            if (nums[i] - nums[i - 1] <= diff) {
                if (++pairs == p) {
                    return true;
                }

                ++i;
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 10,1,2,7,1,3 };
    check.checkInt(1, o.minimizeMax(nums, 2));

    nums = { 4,2,1,2 };
    check.checkInt(0, o.minimizeMax(nums, 1));

    nums = { 1,4,5,5,6,9 };
    check.checkInt(1, o.minimizeMax(nums, 2));
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
