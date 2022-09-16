/* 顺丰鄂州枢纽运转中心环线检测.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
【背景】
鄂州花湖机场是亚洲第一个、世界第四个专业货运枢纽机场。2016年4月获中国民用航空局正式批复，2017年12月20日枢纽工程正式开工，2022年3月19日由顺丰航空使用波音B757-200F型全货机执行试飞成功，系中国首次以全货机机型完成新机场的试飞工作。
顺丰鄂州枢纽转运中心占地约百万平方，实现了快件从卸载（卸车/卸机）到分拣再到装车/打板全自动化。自动化设备运输线总长超过数十公里。如何保障快件最高效到达装车或打板口是核心需要解决的问题。
转运中心内自动化设备通过运输线连接，构成一张立体的连通网络，快件达到分流路口需要决策行走支路，确保全程线路最优前提下，同时要避免大量快件涌向最短线路造成拥堵，还需要及时避开故障线路上的故障设备，直到故障得到修复。
自动化运输线简化图如下：
探客-有向图 (6).png
卸载口代表快件行走起始节点，装载口代表快件经过路线行走后最终目的节点，节点代表从卸载口到达装载口途径线路的分流或汇流点，卸载口和装载口也是一种特殊的节点。
边代表两个相邻节点间自动化设备运输线，线路代表从起始节点到达目的节点（装载口）途径所有的边。
在整连通网络上不应该存在环形线路，环形线路可能会导致快件在运输线上长时间运输，以至于错过飞机或车辆班次，导致延误。因此在建立线路数据模型时应避免出现环。

【问题】
请帮忙检测线路上是否存在环形通路。

示例 1：

输入：
"1->2,2->3,3->1"

输出：
true

示例 2：

输入：
"1->4,2->5,3->6,3->7,4->8,5->8,5->9,6->9,6->11,7->11,8->12,9->12,9->13,10->13,10->14,11->10,11->14"

输出：
false

示例 3：

输入：
"1->4,2->5,3->6,3->7,4->8,5->8,5->9,6->9,6->11,7->11,8->12,9->12,9->13,10->6,10->13,10->14,11->10,11->14"

输出：
true

解释:
存在环线:6->11,11->10,10->6

提示:

0 < 节点数 < 100
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool hasCycle(string graph) {
        unordered_map<int, vector<int>> adjs;
        unordered_map<int, int> indegrees;

        getAdjs(graph, adjs, indegrees);
        topSort(adjs, indegrees);

        return !adjs.empty();
    }

    void getAdjs(string& graph, unordered_map<int, vector<int>>& adjs, unordered_map<int, int>& indegrees) {
        int from = 0, to = 0;
        graph.push_back(',');

        for (char c : graph) {
            if (c >= '0' && c <= '9') {
                to = to * 10 + c - '0';
            }
            else if (c == '-') {
                from = to;
                to = 0;
            }
            else if (c == ',') {
                if (indegrees.count(from) == 0) {
                    indegrees[from] = 0;
                }

                ++indegrees[to];
                adjs[from].push_back(to);
                to = 0;
            }
        }
    }

    void topSort(unordered_map<int, vector<int>>& adjs, unordered_map<int, int>& indegrees) {
        queue<int> zeroDegrees;

        for (auto& degree : indegrees) {
            if (degree.second == 0) {
                zeroDegrees.push(degree.first);
            }
        }

        while (!zeroDegrees.empty()) {
            int node = zeroDegrees.front();
            zeroDegrees.pop();

            for (int next : adjs[node]) {
                if (--indegrees[next] == 0) {
                    zeroDegrees.push(next);
                }
            }

            adjs.erase(node);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.hasCycle("1->2,2->3,3->1"));
    check.checkBool(false, o.hasCycle("1->2"));
    check.checkBool(false, o.hasCycle("1->4,2->5,3->6,3->7,4->8,5->8,5->9,6->9,6->11,7->11,8->12,9->12,9->13,10->13,10->14,11->10,11->14"));
    check.checkBool(true, o.hasCycle("1->4,2->5,3->6,3->7,4->8,5->8,5->9,6->9,6->11,7->11,8->12,9->12,9->13,10->6,10->13,10->14,11->10,11->14"));
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
