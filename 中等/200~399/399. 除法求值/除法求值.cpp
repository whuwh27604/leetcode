/* 除法求值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出方程式 A / B = k, 其中 A 和 B 均为用字符串表示的变量， k 是一个浮点型数字。根据已知方程式求解问题，并返回计算结果。如果结果不存在，则返回 -1.0。

示例 :
给定 a / b = 2.0, b / c = 3.0
问题: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
返回 [6.0, 0.5, -1.0, 1.0, -1.0 ]

输入为: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries(方程式，方程式结果，问题方程式)， 其中 equations.size() == values.size()，即方程式的长度与方程式结果长度相等（程式与结果一一对应），并且结果值均为正数。以上为方程式的描述。 返回vector<double>类型。

基于上述例子，输入如下：

equations(方程式) = [ ["a", "b"], ["b", "c"] ],
values(方程式结果) = [2.0, 3.0],
queries(问题方程式) = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
输入总是有效的。你可以假设除法运算中不会出现除数为0的情况，且不存在任何矛盾的结果。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/evaluate-division
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> valuedPaths;
        createPaths(equations, values, valuedPaths);

        vector<double> results;
        for (vector<string> path : queries) {
            double value;
            if (path[0] == path[1]) {
                value = (valuedPaths.find(path[0]) == valuedPaths.end()) ? -1.0 : 1.0;
                results.push_back(value);
                continue;
            }

            if (hasPath(path[0], path[1], valuedPaths, value)) {
                results.push_back(value);
            }
            else {
                results.push_back(-1.0);
            }
        }

        return results;
    }

    void createPaths(vector<vector<string>>& equations, vector<double>& values, unordered_map<string, vector<pair<string, double>>>& valuedPaths) {
        for (unsigned int i = 0; i < equations.size(); i++) {
            auto iter = valuedPaths.find(equations[i][0]);
            if (iter == valuedPaths.end()) {
                valuedPaths.insert({ equations[i][0], { {equations[i][1],values[i]} } });
            }
            else {
                iter->second.push_back({ equations[i][1],values[i] });
            }

            iter = valuedPaths.find(equations[i][1]);
            if (iter == valuedPaths.end()) {
                valuedPaths.insert({ equations[i][1], { {equations[i][0],1 / values[i]} } });
            }
            else {
                iter->second.push_back({ equations[i][0],1 / values[i] });
            }
        }
    }

    bool hasPath(string& from, string& to, unordered_map<string, vector<pair<string, double>>>& valuedPaths, double& value) {
        unordered_set<string> passedPoints;
        passedPoints.insert(from);
        list<pair<string, double>> bfs;
        bfs.push_back({ from, 1 });

        while (!bfs.empty()) {
            int size = bfs.size();
            for (int i = 0; i < size; i++) {
                string currentPoint = bfs.front().first;
                double currentValue = bfs.front().second;
                bfs.pop_front();

                auto iter = valuedPaths.find(currentPoint);
                if (iter == valuedPaths.end()) {
                    continue;
                }

                vector<pair<string, double>>& nextPoints = iter->second;
                for (unsigned int j = 0; j < nextPoints.size(); j++) {
                    string& nextPoint = nextPoints[j].first;
                    value = currentValue * nextPoints[j].second;

                    if (nextPoint == to) {
                        return true;
                    }

                    if (passedPoints.find(nextPoint) != passedPoints.end()) {
                        continue;  // 已经访问过该节点，跳过，避免环路
                    }

                    passedPoints.insert(nextPoint);
                    bfs.push_back({ nextPoint, value });
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<string>> equations = { {"a","b"},{"b","c"} };
    vector<double> values = { 2.0,3.0 };
    vector<vector<string>> queries = { {"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"} };
    vector<double> actual = o.calcEquation(equations, values, queries);
    vector<double> expected = { 6.0,0.5,-1.0,1.0,-1.0 };
    check.checkDoubleVector(expected, actual);

    equations = {  };
    values = {  };
    queries = {  };
    actual = o.calcEquation(equations, values, queries);
    expected = {  };
    check.checkDoubleVector(expected, actual);

    equations = { {"a","b"} };
    values = { 2 };
    queries = {  };
    actual = o.calcEquation(equations, values, queries);
    expected = {  };
    check.checkDoubleVector(expected, actual);

    equations = {  };
    values = {  };
    queries = { {"a","c"} };
    actual = o.calcEquation(equations, values, queries);
    expected = { -1.0 };
    check.checkDoubleVector(expected, actual);

    equations = { {"a","b"} };
    values = { 2 };
    queries = { {"a","b"},{"a","c"},{"b","a"},{"b","c"},{"a","a"},{"b","b"},{"c","c"} };
    actual = o.calcEquation(equations, values, queries);
    expected = { 2,-1,0.5,-1,1,1,-1 };
    check.checkDoubleVector(expected, actual);

    equations = { {"a","b"},{"b","c"},{"b","d"},{"d","c"},{"c","e"} };
    values = { 2,2,2,1,2 };
    queries = { {"a","a"},{"a","b"},{"a","c"},{"a","d"},{"a","e"},{"b","a"},{"b","b"},{"b","c"},{"b","d"},{"b","e"},{"e","a"},{"e","b"},{"e","c"},{"e","d"},{"e","e"} };
    actual = o.calcEquation(equations, values, queries);
    expected = { 1,2,4,4,8,0.5,1,2,2,4,0.125,0.25,0.5,0.5,1 };
    check.checkDoubleVector(expected, actual);
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
