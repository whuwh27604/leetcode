/* 学生分数的最小差值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 下标从 0 开始 的整数数组 nums ，其中 nums[i] 表示第 i 名学生的分数。另给你一个整数 k 。

从数组中选出任意 k 名学生的分数，使这 k 个分数间 最高分 和 最低分 的 差值 达到 最小化 。

返回可能的 最小差值 。

 

示例 1：

输入：nums = [90], k = 1
输出：0
解释：选出 1 名学生的分数，仅有 1 种方法：
- [90] 最高分和最低分之间的差值是 90 - 90 = 0
可能的最小差值是 0
示例 2：

输入：nums = [9,4,1,7], k = 2
输出：2
解释：选出 2 名学生的分数，有 6 种方法：
- [9,4,1,7] 最高分和最低分之间的差值是 9 - 4 = 5
- [9,4,1,7] 最高分和最低分之间的差值是 9 - 1 = 8
- [9,4,1,7] 最高分和最低分之间的差值是 9 - 7 = 2
- [9,4,1,7] 最高分和最低分之间的差值是 4 - 1 = 3
- [9,4,1,7] 最高分和最低分之间的差值是 7 - 4 = 3
- [9,4,1,7] 最高分和最低分之间的差值是 7 - 1 = 6
可能的最小差值是 2
 

提示：

1 <= k <= nums.length <= 1000
0 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int i, j, size = nums.size(), minDiff = INT_MAX;

        sort(nums.begin(), nums.end());

        for (i = 0, j = k - 1; j < size; ++i, ++j) {
            minDiff = min(minDiff, nums[j] - nums[i]);
        }

        return minDiff;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 90 };
    check.checkInt(0, o.minimumDifference(nums, 1));

    nums = { 9,4,1,7 };
    check.checkInt(2, o.minimumDifference(nums, 2));

    nums = { 9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7 };
    check.checkInt(2, o.minimumDifference(nums, 30));

    nums = { 9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7,9,4,1,7 };
    check.checkInt(8, o.minimumDifference(nums, 50));
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
