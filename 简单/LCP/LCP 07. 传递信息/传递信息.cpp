/* 传递信息.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小朋友 A 在和 ta 的小伙伴们玩传信息游戏，游戏规则如下：

有 n 名玩家，所有玩家编号分别为 0 ～ n-1，其中小朋友 A 的编号为 0
每个玩家都有固定的若干个可传信息的其他玩家（也可能没有）。传信息的关系是单向的（比如 A 可以向 B 传信息，但 B 不能向 A 传信息）。
每轮信息必须需要传递给另一个人，且信息可重复经过同一个人
给定总玩家数 n，以及按 [玩家编号,对应可传递玩家编号] 关系组成的二维数组 relation。返回信息从小 A (编号 0 ) 经过 k 轮传递到编号为 n-1 的小伙伴处的方案数；若不能到达，返回 0。

示例 1：

输入：n = 5, relation = [[0,2],[2,1],[3,4],[2,3],[1,4],[2,0],[0,4]], k = 3

输出：3

解释：信息从小 A 编号 0 处开始，经 3 轮传递，到达编号 4。共有 3 种方案，分别是 0->2->0->4， 0->2->1->4， 0->2->3->4。

示例 2：

输入：n = 3, relation = [[0,2],[2,1]], k = 2

输出：0

解释：信息不能从小 A 处经过 2 轮传递到编号 2

限制：

2 <= n <= 10
1 <= k <= 5
1 <= relation.length <= 90, 且 relation[i].length == 2
0 <= relation[i][0],relation[i][1] < n 且 relation[i][0] != relation[i][1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/chuan-di-xin-xi
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        unordered_map<int, unordered_set<int>> multiRelation;

        for (unsigned int i = 0; i < relation.size(); i++) {
            multiRelation[relation[i][0]].insert(relation[i][1]);
        }

        list<int> destinations;
        destinations.push_back(0);

        while (k-- != 0) {
            int count = destinations.size();
            while (count-- != 0) {
                int from = destinations.front();
                auto iter = multiRelation.find(from);
                if (iter != multiRelation.end()) {
                    unordered_set<int>& to = iter->second;
                    for (auto iter2 = to.begin(); iter2 != to.end(); iter2++) {
                        destinations.push_back(*iter2);
                    }
                }

                destinations.pop_front();
            }
        }

        int paths = 0;
        n -= 1;
        for (auto iter = destinations.begin(); iter != destinations.end(); iter++) {
            if (*iter == n) {
                paths++;
            }
        }

        return paths;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> relation = { {0,2},{2,1},{3,4},{2,3},{1,4},{2,0},{0,4} };
    check.checkInt(3, o.numWays(5, relation, 3));

    relation = { {0,2},{2,1} };
    check.checkInt(0, o.numWays(3, relation, 2));

    relation = { {0,1} };
    check.checkInt(1, o.numWays(2, relation, 1));

    relation = { {0,1} };
    check.checkInt(0, o.numWays(3, relation, 1));

    relation = { {0,1} };
    check.checkInt(0, o.numWays(2, relation, 2));

    relation = { {0,2},{0,1},{1,3},{2,3},{3,4} };
    check.checkInt(2, o.numWays(5, relation, 3));

    relation = { {0,2},{0,1},{1,3},{2,3},{3,4},{0,2},{0,1},{1,3},{2,3},{3,4} };
    check.checkInt(2, o.numWays(5, relation, 3));

    relation = { {0,1},{0,2},{0,3},{1,4},{2,4},{3,4},{1,5},{2,5},{3,5},{4,6},{5,6} };
    check.checkInt(6, o.numWays(7, relation, 3));
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
