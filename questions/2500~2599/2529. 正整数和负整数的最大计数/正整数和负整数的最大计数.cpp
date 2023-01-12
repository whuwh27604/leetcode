/* 正整数和负整数的最大计数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个按 非递减顺序 排列的数组 nums ，返回正整数数目和负整数数目中的最大值。

换句话讲，如果 nums 中正整数的数目是 pos ，而负整数的数目是 neg ，返回 pos 和 neg二者中的最大值。
注意：0 既不是正整数也不是负整数。



示例 1：

输入：nums = [-2,-1,-1,1,2,3]
输出：3
解释：共有 3 个正整数和 3 个负整数。计数得到的最大值是 3 。
示例 2：

输入：nums = [-3,-2,-1,0,0,1,2]
输出：3
解释：共有 2 个正整数和 3 个负整数。计数得到的最大值是 3 。
示例 3：

输入：nums = [5,20,66,1314]
输出：4
解释：共有 4 个正整数和 0 个负整数。计数得到的最大值是 4 。


提示：

1 <= nums.length <= 2000
-2000 <= nums[i] <= 2000
nums 按 非递减顺序 排列。


进阶：你可以设计并实现时间复杂度为 O(log(n)) 的算法解决此问题吗？
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = (int)nums.size() - distance(nums.begin(), upper_bound(nums.begin(), nums.end(), 0));
        int neg = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), 0));

        return max(pos, neg);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { -2,-1,-1,1,2,3 };
    check.checkInt(3, o.maximumCount(nums));

    nums = { -3,-2,-1,0,0,1,2 };
    check.checkInt(3, o.maximumCount(nums));

    nums = { 5,20,66,1314 };
    check.checkInt(4, o.maximumCount(nums));

    nums = { -5,-4 };
    check.checkInt(2, o.maximumCount(nums));
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
