/* 人口最多的年份.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维整数数组 logs ，其中每个 logs[i] = [birthi, deathi] 表示第 i 个人的出生和死亡年份。

年份 x 的 人口 定义为这一年期间活着的人的数目。第 i 个人被计入年份 x 的人口需要满足：x 在闭区间 [birthi, deathi - 1] 内。注意，人不应当计入他们死亡当年的人口中。

返回 人口最多 且 最早 的年份。

 

示例 1：

输入：logs = [[1993,1999],[2000,2010]]
输出：1993
解释：人口最多为 1 ，而 1993 是人口为 1 的最早年份。
示例 2：

输入：logs = [[1950,1961],[1960,1971],[1970,1981]]
输出：1960
解释：
人口最多为 2 ，分别出现在 1960 和 1970 。
其中最早年份是 1960 。
 

提示：

1 <= logs.length <= 100
1950 <= birthi < deathi <= 2050

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-population-year
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> population(2051, 0);
        int minYear = INT_MAX, maxYear = 0, maxPopulation = 0, sum = 0, maxPopulationYear = 0;

        for (auto& log : logs) {
            population[log[0]] += 1;
            population[log[1]] -= 1;
            minYear = min(minYear, log[0]);
            maxYear = max(maxYear, log[1]);
        }

        for (int year = minYear; year <= maxYear; ++year) {
            sum += population[year];

            if (sum > maxPopulation) {
                maxPopulation = sum;
                maxPopulationYear = year;
            }
        }

        return maxPopulationYear;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> logs = { {1993,1999},{2000,2010} };
    check.checkInt(1993, o.maximumPopulation(logs));

    logs = { {1950,1961},{1960,1971},{1970,1981} };
    check.checkInt(1960, o.maximumPopulation(logs));

    logs = { {2008,2026},{2004,2008},{2034,2035},{1999,2050},{2049,2050},{2011,2035},{1966,2033},{2044,2049} };
    check.checkInt(2011, o.maximumPopulation(logs));

    logs = { {2008,2009} };
    check.checkInt(2008, o.maximumPopulation(logs));
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
