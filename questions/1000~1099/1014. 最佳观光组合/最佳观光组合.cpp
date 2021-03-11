/* 最佳观光组合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 values，其中 values[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的 距离 为 j - i。

一对景点（i < j）组成的观光组合的得分为 values[i] + values[j] + i - j ，也就是景点的评分之和 减去 它们两者之间的距离。

返回一对观光景点能取得的最高分。

 

示例 1：

输入：values = [8,1,5,2,6]
输出：11
解释：i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
示例 2：

输入：values = [1,2]
输出：2
 

提示：

2 <= values.length <= 5 * 104
1 <= values[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-sightseeing-pair
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int i, size = values.size(), maxIndexValue = 0, maxScore = 0;

        for (i = 0; i < size; ++i) {
            maxScore = max(maxScore, values[i] - i + maxIndexValue);
            maxIndexValue = max(maxIndexValue, values[i] + i);
        }

        return maxScore;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 8,1,5,2,6 };
    check.checkInt(11, o.maxScoreSightseeingPair(values));

    values = { 1,2 };
    check.checkInt(2, o.maxScoreSightseeingPair(values));
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
