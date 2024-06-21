/* 气温变化趋势.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
力扣城计划在两地设立「力扣嘉年华」的分会场，气象小组正在分析两地区的气温变化趋势，对于第 i ~ (i+1) 天的气温变化趋势，将根据以下规则判断：

若第 i+1 天的气温 高于 第 i 天，为 上升 趋势
若第 i+1 天的气温 等于 第 i 天，为 平稳 趋势
若第 i+1 天的气温 低于 第 i 天，为 下降 趋势
已知 temperatureA[i] 和 temperatureB[i] 分别表示第 i 天两地区的气温。 组委会希望找到一段天数尽可能多，且两地气温变化趋势相同的时间举办嘉年华活动。请分析并返回两地气温变化趋势相同的最大连续天数。

即最大的 n，使得第 i~i+n 天之间，两地气温变化趋势相同

示例 1：

输入： temperatureA = [21,18,18,18,31] temperatureB = [34,32,16,16,17]

输出：2

解释：如下表所示， 第 2～4 天两地气温变化趋势相同，且持续时间最长，因此返回 4-2=2image.png

示例 2：

输入： temperatureA = [5,10,16,-6,15,11,3] temperatureB = [16,22,23,23,25,3,-16]

输出：3

提示：

2 <= temperatureA.length == temperatureB.length <= 1000
-20 <= temperatureA[i], temperatureB[i] <= 40
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int sameTrend = 0, maxSameTrend = 0;

        for (int i = 1; i < (int)temperatureA.size(); ++i) {
            int trendA = temperatureA[i] > temperatureA[i - 1] ? 1 : (temperatureA[i] == temperatureA[i - 1] ? 0 : -1);
            int trendB = temperatureB[i] > temperatureB[i - 1] ? 1 : (temperatureB[i] == temperatureB[i - 1] ? 0 : -1);

            if (trendA == trendB) {
                ++sameTrend;
            }
            else {
                maxSameTrend = max(maxSameTrend, sameTrend);
                sameTrend = 0;
            }
        }

        return max(maxSameTrend, sameTrend);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> temperatureA = { 21,18,18,18,31 };
    vector<int> temperatureB = { 34,32,16,16,17 };
    check.checkInt(2, o.temperatureTrend(temperatureA, temperatureB));

    temperatureA = { 5,10,16,-6,15,11,3 };
    temperatureB = { 16,22,23,23,25,3,-16 };
    check.checkInt(3, o.temperatureTrend(temperatureA, temperatureB));

    temperatureA = { 1,-15,3,14,-1,4,35,36 };
    temperatureB = { -15,32,20,9,33,4,-1,-5 };
    check.checkInt(0, o.temperatureTrend(temperatureA, temperatureB));

    temperatureA = { -14,7,-19,9,13,40,19,15,-18 };
    temperatureB = { 3,16,28,32,25,12,13,-6,4 };
    check.checkInt(1, o.temperatureTrend(temperatureA, temperatureB));
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
