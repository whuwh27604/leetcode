/* 项目管理.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
公司共有 n 个项目和  m 个小组，每个项目要不无人接手，要不就由 m 个小组之一负责。

group[i] 表示第 i 个项目所属的小组，如果这个项目目前无人接手，那么 group[i] 就等于 -1。（项目和小组都是从零开始编号的）小组可能存在没有接手任何项目的情况。

请你帮忙按要求安排这些项目的进度，并返回排序后的项目列表：

同一小组的项目，排序后在列表中彼此相邻。
项目之间存在一定的依赖关系，我们用一个列表 beforeItems 来表示，其中 beforeItems[i] 表示在进行第 i 个项目前（位于第 i 个项目左侧）应该完成的所有项目。
如果存在多个解决方案，只需要返回其中任意一个即可。如果没有合适的解决方案，就请返回一个 空列表 。

 

示例 1：



输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
输出：[6,3,4,1,5,2,0,7]
示例 2：

输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
输出：[]
解释：与示例 1 大致相同，但是在排序后的列表中，4 必须放在 6 的前面。
 

提示：

1 <= m <= n <= 3 * 104
group.length == beforeItems.length == n
-1 <= group[i] <= m - 1
0 <= beforeItems[i].length <= n - 1
0 <= beforeItems[i][j] <= n - 1
i != beforeItems[i][j]
beforeItems[i] 不含重复元素

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-items-by-groups-respecting-dependencies
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int groupSize = adjustGroupId(m, group);

        vector<vector<int>> itemsInGroup(groupSize);
        vector<int> groupIndegrees(groupSize, 0);
        vector<unordered_set<int>> groupsAfterGroup(groupSize);
        vector<int> itemIndegrees(n, 0);
        vector<vector<int>> itemsAfterItem(n);
        preprocess(n, group, beforeItems, itemsInGroup, groupIndegrees, groupsAfterGroup, itemIndegrees, itemsAfterItem);

        queue<int> zeroIndegreeGourps;
        vector<int> sortedItems;

        for (int i = 0; i < groupSize; ++i) {  // group之间拓扑排序
            if (groupIndegrees[i] == 0) {
                zeroIndegreeGourps.push(i);
            }
        }

        while (!zeroIndegreeGourps.empty()) {
            int groupId = zeroIndegreeGourps.front();
            zeroIndegreeGourps.pop();

            if (sortItemsInGroup(groupId, group, itemsInGroup, itemIndegrees, itemsAfterItem, sortedItems) == -1) {
                return {};
            }

            for (int next : groupsAfterGroup[groupId]) {
                if (--groupIndegrees[next] == 0) {
                    zeroIndegreeGourps.push(next);
                }
            }
        }

        return sortedItems.size() == n ? sortedItems : vector<int>{};
    }

    int adjustGroupId(int m, vector<int>& groups) {
        for (int& group : groups) {
            if (group == -1) {
                group = m++;  // 分配一个新的groupId并不会改变item排序的结果，可以简化后序的拓扑排序编码
            }
        }

        return m;
    }

    void preprocess(int n, vector<int>& groups, vector<vector<int>>& beforeItems, vector<vector<int>>& itemsInGroup,
        vector<int>& groupIndegrees, vector<unordered_set<int>>& groupsAfterGroup, vector<int>& itemIndegrees, vector<vector<int>>& itemsAfterItem) {
        for (int i = 0; i < n; ++i) {
            itemsInGroup[groups[i]].push_back(i);
        }

        for (int i = 0; i < n; ++i) {
            itemIndegrees[i] += beforeItems[i].size();

            for (int item : beforeItems[i]) {
                itemsAfterItem[item].push_back(i);

                int group = groups[i], beforeGroup = groups[item];
                if (beforeGroup != group && groupsAfterGroup[beforeGroup].count(group) == 0) {  // 两个group之间多个item的依赖关系只计算一次group的入度
                    ++groupIndegrees[group];
                    groupsAfterGroup[beforeGroup].insert(group);
                }
            }
        }
    }

    int sortItemsInGroup(int group, vector<int>& groups, vector<vector<int>>& itemsInGroup, vector<int>& itemIndegrees, vector<vector<int>>& itemsAfterItem, vector<int>& sortedItems) {
        unsigned int size = sortedItems.size();
        queue<int> zeroIndegreeItems;

        for (int item : itemsInGroup[group]) {  // group内部item之间拓扑排序
            if (itemIndegrees[item] == 0) {
                zeroIndegreeItems.push(item);
            }
        }

        while (!zeroIndegreeItems.empty()) {
            int item = zeroIndegreeItems.front();
            zeroIndegreeItems.pop();

            sortedItems.push_back(item);

            for (int next : itemsAfterItem[item]) {
                --itemIndegrees[next];

                if (groups[next] == group && itemIndegrees[next] == 0) {  // 只放入本组内的item
                    zeroIndegreeItems.push(next);
                }
            }
        }

        return sortedItems.size() - size == itemsInGroup[group].size() ? 0 : -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> group = { 0,0,1 };
    vector<vector<int>> beforeItems = { {2},{},{1} };
    vector<int> actual = o.sortItems(3, 2, group, beforeItems);
    vector<int> expected = {};  // 组间有循环依赖，没有方法全部安排
    check.checkIntVector(expected, actual);

    group = { -1,-1,1,0,0,1,0,-1 };
    beforeItems = { {},{6},{5},{6},{3,6},{},{},{} };
    actual = o.sortItems(8, 2, group, beforeItems);
    expected = { 6,3,4,5,2,0,7,1 };
    check.checkIntVector(expected, actual);

    group = { -1,-1,1,0,0,1,0,-1 };
    beforeItems = { {},{6},{5},{6},{3},{},{4},{} };
    actual = o.sortItems(8, 2, group, beforeItems);
    expected = {};  // 组内有循环依赖，没有方法全部安排
    check.checkIntVector(expected, actual);

    group = { 2,0,-1,3,0 };
    beforeItems = { {2,1,3},{2,4},{},{},{} };
    actual = o.sortItems(5, 5, group, beforeItems);
    expected = { 3,2,4,1,0 };
    check.checkIntVector(expected, actual);
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
