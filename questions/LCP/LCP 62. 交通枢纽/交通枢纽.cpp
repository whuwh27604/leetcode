/* 交通枢纽.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
为了缓解「力扣嘉年华」期间的人流压力，组委会在活动期间开设了一些交通专线。path[i] = [a, b] 表示有一条从地点 a通往地点 b 的 单向 交通专线。 若存在一个地点，满足以下要求，我们则称之为 交通枢纽：

所有地点（除自身外）均有一条 单向 专线 直接 通往该地点；
该地点不存在任何 通往其他地点 的单向专线。
请返回交通专线的 交通枢纽。若不存在，则返回 -1。

注意：

对于任意一个地点，至少被一条专线连通。
示例 1：

输入：path = [[0,1],[0,3],[1,3],[2,0],[2,3]]

输出：3

解释：如下图所示： 地点 0,1,2 各有一条通往地点 3 的交通专线， 且地点 3 不存在任何通往其他地点的交通专线。image.png

示例 2：

输入：path = [[0,3],[1,0],[1,3],[2,0],[3,0],[3,2]]

输出：-1

解释：如下图所示：不存在满足 交通枢纽 的地点。image.png

提示：

1 <= path.length <= 1000
0 <= path[i][0], path[i][1] <= 1000
path[i][0] 与 path[i][1] 不相等
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int transportationHub(vector<vector<int>>& path) {
        unordered_map<int, unordered_set<int>> in;
        unordered_set<int> all, out;

        for (auto& pa : path) {
            in[pa[1]].insert(pa[0]);
            out.insert(pa[0]);
            all.insert(pa[0]);
            all.insert(pa[1]);
        }

        for (auto& kv : in) {
            if (kv.second.size() == all.size() - 1 && out.count(kv.first) == 0) {
                return kv.first;
            }
        }

        return -1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> path = { {0,1},{0,3},{1,3},{2,0},{2,3} };
    check.checkInt(3, o.transportationHub(path));

    path = { {0,3},{1,0},{1,3},{2,0},{3,0},{3,2} };
    check.checkInt(-1, o.transportationHub(path));

    path = { {0,1},{0,3},{1,3},{2,0},{0,3} };
    check.checkInt(-1, o.transportationHub(path));

    path = { {0,1},{0,3},{2,0},{2,3},{2,3} };
    check.checkInt(-1, o.transportationHub(path));
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
