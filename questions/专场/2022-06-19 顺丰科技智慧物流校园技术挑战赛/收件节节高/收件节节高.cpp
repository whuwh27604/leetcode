/* 收件节节高.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
背景
夏天就来了，天气越来越热了，顺丰小哥收派快递非常辛苦。为了鼓励小哥，我们设置了各种有奖竞赛活动。这其中就有一个叫收件节节高的竞赛，该竞赛比较的是小哥日收件数连续增长的天数，连续增长天数越大排名越高。

问题
小哥人数较多，请帮忙设计一个可以快速算出小哥日收件最大连续增长天数的算法。
输入: 一维数组nums[n]
输出: 连续递增天数长度

示例：

输入：[54,42,62,75,82,86,86]
输出：5
解释:
小哥A最近一周的收件数分别是：54,42,62,75,82,86,86，那么小哥A在这周的日收件最大连续增长天数是5
- 小哥A在这周第2天开始到第6天的日收件数都是在增长
- 第7天与第6天收件数一样，不算增长
提示：

0 <= nums.length < 200000
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findMaxCI(vector<int>& nums) {
        int days = 1, maxDays = 0;

        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                ++days;
            }
            else {
                maxDays = max(maxDays, days);
                days = 1;
            }
        }

        return max(maxDays, days);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 54,42,62,75,82,86,86 };
    check.checkInt(5, o.findMaxCI(nums));

    nums = { 54,42,62,75,82,86,87 };
    check.checkInt(6, o.findMaxCI(nums));

    nums = { 2,1 };
    check.checkInt(1, o.findMaxCI(nums));
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
