/* 将区间分为最少组数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维整数数组 intervals ，其中 intervals[i] = [lefti, righti] 表示 闭 区间 [lefti, righti] 。

你需要将 intervals 划分为一个或者多个区间 组 ，每个区间 只 属于一个组，且同一个组中任意两个区间 不相交 。

请你返回 最少 需要划分成多少个组。

如果两个区间覆盖的范围有重叠（即至少有一个公共数字），那么我们称这两个区间是 相交 的。比方说区间 [1, 5] 和 [5, 8] 相交。

 

示例 1：

输入：intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
输出：3
解释：我们可以将区间划分为如下的区间组：
- 第 1 组：[1, 5] ，[6, 8] 。
- 第 2 组：[2, 3] ，[5, 10] 。
- 第 3 组：[1, 10] 。
可以证明无法将区间划分为少于 3 个组。
示例 2：

输入：intervals = [[1,3],[5,6],[8,10],[11,13]]
输出：1
解释：所有区间互不相交，所以我们可以把它们全部放在一个组内。
 

提示：

1 <= intervals.length <= 105
intervals[i].length == 2
1 <= lefti <= righti <= 106

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/divide-intervals-into-minimum-number-of-groups
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int groups = 1;
        priority_queue<int, vector<int>, greater<int>> rights;
        rights.push(intervals[0][1]);

        for (int i = 1; i < (int)intervals.size(); ++i) {
            if (intervals[i][0] <= rights.top()) {  // 和所有group都相交，只能新开一个group
                ++groups;
            }
            else {  // 贪心选择right最小的group，将intervals[i]加在它后面
                rights.pop();
            }

            rights.push(intervals[i][1]);
        }

        return groups;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> intervals = { {5,10},{6,8},{1,5},{2,3},{1,10} };
    check.checkInt(3,o.minGroups(intervals));

    intervals = { {1,3},{5,6},{8,10},{11,13} };
    check.checkInt(1, o.minGroups(intervals));

    intervals = { {441459,446342},{801308,840640},{871890,963447},{228525,336985},{807945,946787},{479815,507766},{693292,944029},{751962,821744} };
    check.checkInt(4, o.minGroups(intervals));
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
