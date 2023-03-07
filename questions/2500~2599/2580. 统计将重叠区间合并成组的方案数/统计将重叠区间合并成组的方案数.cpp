/* 统计将重叠区间合并成组的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维整数数组 ranges ，其中 ranges[i] = [starti, endi] 表示 starti 到 endi 之间（包括二者）的所有整数都包含在第 i 个区间中。

你需要将 ranges 分成 两个 组（可以为空），满足：

每个区间只属于一个组。
两个有 交集 的区间必须在 同一个 组内。
如果两个区间有至少 一个 公共整数，那么这两个区间是 有交集 的。

比方说，区间 [1, 3] 和 [2, 5] 有交集，因为 2 和 3 在两个区间中都被包含。
请你返回将 ranges 划分成两个组的 总方案数 。由于答案可能很大，将它对 109 + 7 取余 后返回。



示例 1：

输入：ranges = [[6,10],[5,15]]
输出：2
解释：
两个区间有交集，所以它们必须在同一个组内。
所以有两种方案：
- 将两个区间都放在第 1 个组中。
- 将两个区间都放在第 2 个组中。
示例 2：

输入：ranges = [[1,3],[10,20],[2,5],[4,8]]
输出：4
解释：
区间 [1,3] 和 [2,5] 有交集，所以它们必须在同一个组中。
同理，区间 [2,5] 和 [4,8] 也有交集，所以它们也必须在同一个组中。
所以总共有 4 种分组方案：
- 所有区间都在第 1 组。
- 所有区间都在第 2 组。
- 区间 [1,3] ，[2,5] 和 [4,8] 在第 1 个组中，[10,20] 在第 2 个组中。
- 区间 [1,3] ，[2,5] 和 [4,8] 在第 2 个组中，[10,20] 在第 1 个组中。


提示：

1 <= ranges.length <= 105
ranges[i].length == 2
0 <= starti <= endi <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        int num = -1, ways = 1, mod = 1000000007;

        sort(ranges.begin(), ranges.end());

        for (auto& range : ranges) {
            if (range[0] > num) {
                ways = ways * 2 % mod;
            }

            num = max(num, range[1]);
        }

        return ways;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> ranges = {{1,1},{2,2},{3,3}};
    check.checkInt(8,o.countWays(ranges));

    ranges = {{6,10},{5,15}};
    check.checkInt(2,o.countWays(ranges));

    ranges = {{1,3},{10,20},{2,5},{4,8}};
    check.checkInt(4, o.countWays(ranges));
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
