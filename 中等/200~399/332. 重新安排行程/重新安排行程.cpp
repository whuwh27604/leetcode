/* 重新安排行程.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。

说明:

如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前
所有的机场都用三个大写字母表示（机场代码）。
假定所有机票至少存在一种合理的行程。
示例 1:

输入: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
输出: ["JFK", "MUC", "LHR", "SFO", "SJC"]
示例 2:

输入: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
输出: ["JFK","ATL","JFK","SFO","ATL","SFO"]
解释: 另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"]。但是它自然排序更大更靠后。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reconstruct-itinerary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <set>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> fromTos;  // 可以到同一目的地多次，所以要用multiset
        hashFromTos(tickets, fromTos);

        stack<string> reversedItinerary;
        string from = "JFK";
        DFS(from, fromTos, reversedItinerary);

        vector<string> itinerary;
        while (!reversedItinerary.empty()) {
            itinerary.push_back(reversedItinerary.top());
            reversedItinerary.pop();
        }

        return itinerary;
    }

    void hashFromTos(vector<vector<string>>& tickets, unordered_map<string, multiset<string>>& fromTos) {
        for (vector<string>& fromTo : tickets) {
            auto iter = fromTos.find(fromTo[0]);
            if (iter == fromTos.end()) {
                fromTos[fromTo[0]] = { fromTo[1] };
            }
            else {
                iter->second.insert(fromTo[1]);
            }
        }
    }

    void DFS(string& from, unordered_map<string, multiset<string>>& fromTos, stack<string>& reversedItinerary) {
        auto iter = fromTos.find(from);
        if (iter == fromTos.end()) {  // 如果该节点没有下一跳，说明是最后一个节点，直接入栈
            reversedItinerary.push(from);
            return;
        }

        while (!iter->second.empty()) {
            string to = *(iter->second.begin());  // 按顺序遍历所有的下一跳
            iter->second.erase(iter->second.begin());  // 遍历之前，删除当前节点到下一跳的路径，避免产生环路

            DFS(to, fromTos, reversedItinerary);
        }

        reversedItinerary.push(from);  // 遍历完所有的下一跳，该节点再无路可去，入栈
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<string>> tickets = { {"MUC", "LHR"},{"JFK", "MUC"},{"SFO", "SJC"},{"LHR", "SFO"} };
    vector<string> actual = o.findItinerary(tickets);
    vector<string> expected = { "JFK", "MUC", "LHR", "SFO", "SJC" };
    check.checkStringVector(expected, actual);

    tickets = { {"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"} };
    actual = o.findItinerary(tickets);
    expected = { "JFK","ATL","JFK","SFO","ATL","SFO" };
    check.checkStringVector(expected, actual);

    tickets = { {"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"} };
    actual = o.findItinerary(tickets);
    expected = { "JFK","NRT","JFK","KUL" };
    check.checkStringVector(expected, actual);

    tickets = { {"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"},{"JFK","NRT"},{"NRT","JFK"} };
    actual = o.findItinerary(tickets);
    expected = { "JFK","NRT","JFK","NRT","JFK","KUL" };
    check.checkStringVector(expected, actual);

    tickets = { {"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"} };
    actual = o.findItinerary(tickets);
    expected = { "JFK","ANU","EZE","AXA","TIA","ANU","JFK","TIA","ANU","TIA","JFK" };
    check.checkStringVector(expected, actual);

    tickets = { { "EZE", "TIA" }, { "EZE", "HBA" }, { "AXA", "TIA" }, { "JFK", "AXA" }, { "ANU", "JFK" }, { "ADL", "ANU" }, { "TIA", "AUA" }, { "ANU", "AUA" }, { "ADL", "EZE" }, { "ADL", "EZE" }, { "EZE", "ADL" }, { "AXA", "EZE" }, { "AUA", "AXA" }, { "JFK", "AXA" }, { "AXA", "AUA" }, { "AUA", "ADL" }, { "ANU", "EZE" }, { "TIA", "ADL" }, { "EZE", "ANU" }, { "AUA", "ANU" } };
    actual = o.findItinerary(tickets);
    expected = { "JFK","AXA","AUA","ADL","ANU","AUA","ANU","EZE","ADL","EZE","ANU","JFK","AXA","EZE","TIA","AUA","AXA","TIA","ADL","EZE","HBA" };
    check.checkStringVector(expected, actual);

    tickets = { {"AXA", "EZE"}, {"EZE", "AUA"}, {"ADL", "JFK"}, {"ADL", "TIA"}, {"AUA", "AXA"}, {"EZE", "TIA"}, {"EZE", "TIA"}, {"AXA", "EZE"}, {"EZE", "ADL"}, {"ANU", "EZE"}, {"TIA", "EZE"}, {"JFK", "ADL"}, {"AUA", "JFK"}, {"JFK", "EZE"}, {"EZE", "ANU"}, {"ADL", "AUA"}, {"ANU", "AXA"}, {"AXA", "ADL"}, {"AUA", "JFK"}, {"EZE", "ADL"}, {"ANU", "TIA"}, {"AUA", "JFK"}, {"TIA", "JFK"}, {"EZE", "AUA"}, {"AXA", "EZE"}, {"AUA", "ANU"}, {"ADL", "AXA"}, {"EZE", "ADL"}, {"AUA", "ANU"}, {"AXA", "EZE"}, {"TIA", "AUA"}, {"AXA", "EZE"}, {"AUA", "SYD"}, {"ADL", "JFK"}, {"EZE", "AUA"}, {"ADL", "ANU"}, {"AUA", "TIA"}, {"ADL", "EZE"}, {"TIA", "JFK"}, {"AXA", "ANU"}, {"JFK", "AXA"}, {"JFK", "ADL"}, {"ADL", "EZE"}, {"AXA", "TIA"}, {"JFK", "AUA"}, {"ADL", "EZE"}, {"JFK", "ADL"}, {"ADL", "AXA"}, {"TIA", "AUA"}, {"AXA", "JFK"}, {"ADL", "AUA"}, {"TIA", "JFK"}, {"JFK", "ADL"}, {"JFK", "ADL"}, {"ANU", "AXA"}, {"TIA", "AXA"}, {"EZE", "JFK"}, {"EZE", "AXA"}, {"ADL", "TIA"}, {"JFK", "AUA"}, {"TIA", "EZE"}, {"EZE", "ADL"}, {"JFK", "ANU"}, {"TIA", "AUA"}, {"EZE", "ADL"}, {"ADL", "JFK"}, {"ANU", "AXA"}, {"AUA", "AXA"}, {"ANU", "EZE"}, {"ADL", "AXA"}, {"ANU", "AXA"}, {"TIA", "ADL"}, {"JFK", "ADL"}, {"JFK", "TIA"}, {"AUA", "ADL"}, {"AUA", "TIA"}, {"TIA", "JFK"}, {"EZE", "JFK"}, {"AUA", "ADL"}, {"ADL", "AUA"}, {"EZE", "ANU"}, {"ADL", "ANU"}, {"AUA", "AXA"}, {"AXA", "TIA"}, {"AXA", "TIA"}, {"ADL", "AXA"}, {"EZE", "AXA"}, {"AXA", "JFK"}, {"JFK", "AUA"}, {"ANU", "ADL"}, {"AXA", "TIA"}, {"ANU", "AUA"}, {"JFK", "EZE"}, {"AXA", "ADL"}, {"TIA", "EZE"}, {"JFK", "AXA"}, {"AXA", "ADL"}, {"EZE", "AUA"}, {"AXA", "ANU"}, {"ADL", "EZE"}, {"AUA", "EZE"} };
    actual = o.findItinerary(tickets);
    expected = { "JFK","ADL","ANU","ADL","ANU","AUA","ADL","AUA","ADL","AUA","ANU","AXA","ADL","AUA","ANU","AXA","ADL","AXA","ADL","AXA","ANU","AXA","ANU","AXA","EZE","ADL","AXA","EZE","ADL","AXA","EZE","ADL","EZE","ADL","EZE","ADL","EZE","ANU","EZE","ANU","EZE","AUA","AXA","EZE","AUA","AXA","EZE","AUA","AXA","JFK","ADL","EZE","AUA","EZE","AXA","JFK","ADL","JFK","ADL","JFK","ADL","JFK","ADL","TIA","ADL","TIA","AUA","JFK","ANU","TIA","AUA","JFK","AUA","JFK","AUA","TIA","AUA","TIA","AXA","TIA","EZE","AXA","TIA","EZE","JFK","AXA","TIA","EZE","JFK","AXA","TIA","JFK","EZE","TIA","JFK","EZE","TIA","JFK","TIA","JFK","AUA","SYD" };
    check.checkStringVector(expected, actual);

    tickets = { {"JFK","KUL"} };
    actual = o.findItinerary(tickets);
    expected = { "JFK","KUL" };
    check.checkStringVector(expected, actual);
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
