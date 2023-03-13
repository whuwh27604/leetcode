/* 重排数组以得到最大前缀分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。你可以将 nums 中的元素按 任意顺序 重排（包括给定顺序）。

令 prefix 为一个数组，它包含了 nums 重新排列后的前缀和。换句话说，prefix[i] 是 nums 重新排列后下标从 0 到 i 的元素之和。nums 的 分数 是 prefix 数组中正整数的个数。

返回可以得到的最大分数。



示例 1：

输入：nums = [2,-1,0,1,-3,3,-3]
输出：6
解释：数组重排为 nums = [2,3,1,-1,-3,0,-3] 。
prefix = [2,5,6,5,2,2,-1] ，分数为 6 。
可以证明 6 是能够得到的最大分数。
示例 2：

输入：nums = [-2,-3,0]
输出：0
解释：不管怎么重排数组得到的分数都是 0 。


提示：

1 <= nums.length <= 105
-106 <= nums[i] <= 106
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int size = nums.size(), i = size - 1;
        long long sum = 0;

        sort(nums.begin(), nums.end());

        for (; i >= 0; --i) {
            sum += nums[i];
            if (sum <= 0) {
                break;
            }
        }

        return size - 1 - i;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,-1,0,1,-3,3,-3 };
    check.checkInt(6, o.maxScore(nums));

    nums = { -2,-3,0 };
    check.checkInt(0, o.maxScore(nums));

    nums = { 1 };
    check.checkInt(1, o.maxScore(nums));
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
