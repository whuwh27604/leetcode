/* 相对名次.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold Medal", "Silver Medal", "Bronze Medal"）。

(注：分数越高的选手，排名越靠前。)

示例 1:

输入: [5, 4, 3, 2, 1]
输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal" and "Bronze Medal").
余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
提示:

N 是一个正整数并且不会超过 10000。
所有运动员的成绩都不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/relative-ranks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int i, size = nums.size();
        vector<pair<int, int>> numIndices(size);
        vector<string> ranks(size);

        for (i = 0; i < size; ++i) {
            numIndices[i] = { nums[i],i };
        }

        sort(numIndices.begin(), numIndices.end());

        ranks[numIndices[size - 1].second] = "Gold Medal";

        if (size > 1) {
            ranks[numIndices[size - 2].second] = "Silver Medal";
        }

        if (size > 2) {
            ranks[numIndices[size - 3].second] = "Bronze Medal";
        }

        for (i = size - 4; i >= 0; --i) {
            ranks[numIndices[i].second] = to_string(size - i);
        }

        return ranks;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 5, 4, 3, 2, 1 };
    vector<string> actual = o.findRelativeRanks(nums);
    vector<string> expected = { "Gold Medal", "Silver Medal", "Bronze Medal", "4", "5" };
    check.checkStringVector(expected, actual);

    nums = { 1,2,3,4,5 };
    actual = o.findRelativeRanks(nums);
    expected = { "5", "4", "Bronze Medal", "Silver Medal", "Gold Medal" };
    check.checkStringVector(expected, actual);

    nums = { 1 };
    actual = o.findRelativeRanks(nums);
    expected = { "Gold Medal" };
    check.checkStringVector(expected, actual);

    nums = { 1,3 };
    actual = o.findRelativeRanks(nums);
    expected = { "Silver Medal", "Gold Medal" };
    check.checkStringVector(expected, actual);

    nums = { 1,3,2 };
    actual = o.findRelativeRanks(nums);
    expected = { "Bronze Medal", "Gold Medal", "Silver Medal" };
    check.checkStringVector(expected, actual);

    nums = { 2,4,6,8,10,9,7,5,3,1 };
    actual = o.findRelativeRanks(nums);
    expected = { "9", "7", "5", "Bronze Medal", "Gold Medal", "Silver Medal", "4", "6", "8", "10" };
    check.checkStringVector(expected, actual);
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
