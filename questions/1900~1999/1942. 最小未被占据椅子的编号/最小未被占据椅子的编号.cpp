/* 最小未被占据椅子的编号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 n 个朋友在举办一个派对，这些朋友从 0 到 n - 1 编号。派对里有 无数 张椅子，编号为 0 到 infinity 。当一个朋友到达派对时，他会占据 编号最小 且未被占据的椅子。

比方说，当一个朋友到达时，如果椅子 0 ，1 和 5 被占据了，那么他会占据 2 号椅子。
当一个朋友离开派对时，他的椅子会立刻变成未占据状态。如果同一时刻有另一个朋友到达，可以立即占据这张椅子。

给你一个下标从 0 开始的二维整数数组 times ，其中 times[i] = [arrivali, leavingi] 表示第 i 个朋友到达和离开的时刻，同时给你一个整数 targetFriend 。所有到达时间 互不相同 。

请你返回编号为 targetFriend 的朋友占据的 椅子编号 。

 

示例 1：

输入：times = [[1,4],[2,3],[4,6]], targetFriend = 1
输出：1
解释：
- 朋友 0 时刻 1 到达，占据椅子 0 。
- 朋友 1 时刻 2 到达，占据椅子 1 。
- 朋友 1 时刻 3 离开，椅子 1 变成未占据。
- 朋友 0 时刻 4 离开，椅子 0 变成未占据。
- 朋友 2 时刻 4 到达，占据椅子 0 。
朋友 1 占据椅子 1 ，所以返回 1 。
示例 2：

输入：times = [[3,10],[1,5],[2,6]], targetFriend = 0
输出：2
解释：
- 朋友 1 时刻 1 到达，占据椅子 0 。
- 朋友 2 时刻 2 到达，占据椅子 1 。
- 朋友 0 时刻 3 到达，占据椅子 2 。
- 朋友 1 时刻 5 离开，椅子 0 变成未占据。
- 朋友 2 时刻 6 离开，椅子 1 变成未占据。
- 朋友 0 时刻 10 离开，椅子 2 变成未占据。
朋友 0 占据椅子 2 ，所以返回 2 。
 

提示：

n == times.length
2 <= n <= 104
times[i].length == 2
1 <= arrivali < leavingi <= 105
0 <= targetFriend <= n - 1
每个 arrivali 时刻 互不相同 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-number-of-the-smallest-unoccupied-chair
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] < v2[0]; // 按照到达时间排序
}

struct pairCompare {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.first > p2.first;  // 按leaveTime从小到大排序
    }
};

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, pairCompare> leaveTimes;  // { leaveTime,seat }
        set<int> unoccupied;

        initUnoccupied(unoccupied, times.size());
        addIndices(times);
        sort(times.begin(), times.end(), vectorCompare);

        for (auto& time : times) {
            while (!leaveTimes.empty() && leaveTimes.top().first <= time[0]) {
                unoccupied.insert(leaveTimes.top().second);  // 所有已经离开的人，椅子释放出来
                leaveTimes.pop();
            }

            if (time[2] == targetFriend) {
                break;
            }

            leaveTimes.push({ time[1], *unoccupied.begin() });  // 最小的椅子分配给当前的人
            unoccupied.erase(unoccupied.begin());
        }

        return *unoccupied.begin();
    }

    void initUnoccupied(set<int>& unoccupied, int size) {
        for (int i = 0; i < size; ++i) {
            unoccupied.insert(i);
        }
    }

    void addIndices(vector<vector<int>>& times) {
        int index = 0;

        for (auto& time : times) {
            time.push_back(index++);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> times = { {1,4},{2,3},{4,6} };
    check.checkInt(1, o.smallestChair(times, 1));

    times = { {3,10},{1,5},{2,6} };
    check.checkInt(2, o.smallestChair(times, 0));

    times = { {1,10},{2,3},{3,4},{5,8},{6,10},{11,14},{12,13} };
    check.checkInt(0, o.smallestChair(times, 5));
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
