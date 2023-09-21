/* 让所有学生保持开心的分组方法数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、长度为 n 的整数数组 nums ，其中 n 是班级中学生的总数。班主任希望能够在让所有学生保持开心的情况下选出一组学生：

如果能够满足下述两个条件之一，则认为第 i 位学生将会保持开心：

这位学生被选中，并且被选中的学生人数 严格大于 nums[i] 。
这位学生没有被选中，并且被选中的学生人数 严格小于 nums[i] 。
返回能够满足让所有学生保持开心的分组方法的数目。



示例 1：

输入：nums = [1,1]
输出：2
解释：
有两种可行的方法：
班主任没有选中学生。
班主任选中所有学生形成一组。
如果班主任仅选中一个学生来完成分组，那么两个学生都无法保持开心。因此，仅存在两种可行的方法。
示例 2：

输入：nums = [6,0,3,3,6,7,2,7]
输出：3
解释：
存在三种可行的方法：
班主任选中下标为 1 的学生形成一组。
班主任选中下标为 1、2、3、6 的学生形成一组。
班主任选中所有学生形成一组。


提示：

1 <= nums.length <= 105
0 <= nums[i] < nums.length
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int size = nums.size(), i = 0, ways = nums[0] == 0 ? 0 : 1;

        while (i < size) {
            int j = i + 1;
            while (j < size && nums[j] == nums[i]) {
                ++j;
            }

            if ((nums[i] < j) && (j == size || nums[j] > j)) {
                ++ways;
            }

            i = j;
        }

        return ways;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,1 };
    check.checkInt(2, o.countWays(nums));

    nums = { 6,0,3,3,6,7,2,7 };
    check.checkInt(3, o.countWays(nums));

    nums = { 0 };
    check.checkInt(1, o.countWays(nums));
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
