/* 猫和老鼠.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
两位玩家分别扮演猫和老鼠，在一张 无向 图上进行游戏，两人轮流行动。

图的形式是：graph[a] 是一个列表，由满足 ab 是图中的一条边的所有节点 b 组成。

老鼠从节点 1 开始，第一个出发；猫从节点 2 开始，第二个出发。在节点 0 处有一个洞。

在每个玩家的行动中，他们 必须 沿着图中与所在当前位置连通的一条边移动。例如，如果老鼠在节点 1 ，那么它必须移动到 graph[1] 中的任一节点。

此外，猫无法移动到洞中（节点 0）。

然后，游戏在出现以下三种情形之一时结束：

如果猫和老鼠出现在同一个节点，猫获胜。
如果老鼠到达洞中，老鼠获胜。
如果某一位置重复出现（即，玩家的位置和移动顺序都与上一次行动相同），游戏平局。
给你一张图 graph ，并假设两位玩家都都以最佳状态参与游戏：

如果老鼠获胜，则返回 1；
如果猫获胜，则返回 2；
如果平局，则返回 0 。

示例 1：


输入：graph = [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
输出：0
示例 2：


输入：graph = [[1,3],[0],[3],[0,2]]
输出：1


提示：

3 <= graph.length <= 50
1 <= graph[i].length < graph.length
0 <= graph[i][j] < graph.length
graph[i][j] != i
graph[i] 互不相同
猫和老鼠在游戏中总是可以移动
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class State {
public:
    int turn;  // 谁的轮次
    int mouse;  // 老鼠的位置
    int cat;  // 猫的位置，[turn, mouse, cat]定义一个唯一的状态

    State() : turn(0), mouse(0), cat(0) {}
    State(int t, int m, int c) : turn(t), mouse(m), cat(c) {}
};

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        const int DRAW = 0, WIN = 1, LOST = 2;
        const int MOUSE = 0, CAT = 1;
        int n = (int)graph.size();
        queue<State> states;
        vector<vector<vector<int>>> results(2, vector<vector<int>>(n, vector<int>(n, DRAW)));
        vector<vector<vector<int>>> degrees(2, vector<vector<int>>(n, vector<int>(n, 0)));

        for (int m = 0; m < n; ++m) {
            for (int c = 0; c < n; ++c) {
                degrees[MOUSE][m][c] = (int)graph[m].size();
                degrees[CAT][m][c] = (int)graph[c].size();
            }
        }

        for (int next : graph[0]) {
            for (int m = 0; m < n; ++m) {
                --degrees[CAT][m][next];  // cat不能到0
            }
        }

        for (int i = 1; i < n; ++i) {
            results[MOUSE][0][i] = WIN;  // mouse在位置0，win
            results[CAT][0][i] = WIN;
            states.push(State(MOUSE, 0, i));
            states.push(State(CAT, 0, i));

            results[MOUSE][i][i] = LOST;  // mouse、cat在同一位置，lost
            results[CAT][i][i] = LOST;
            states.push(State(MOUSE, i, i));
            states.push(State(CAT, i, i));
        }

        while (!states.empty()) {
            State state = states.front();
            states.pop();

            int turn = state.turn, mouse = state.mouse, cat = state.cat, result = results[turn][mouse][cat];
            int preTurn = turn ^ 1;

            for (int prePos : graph[preTurn == MOUSE ? mouse : cat]) {
                int preMouse = (turn == MOUSE ? mouse : prePos);
                int preCat = (turn == CAT ? cat : prePos);

                if (preCat != 0 && results[preTurn][preMouse][preCat] == DRAW) {  // 当前胜负状态未定
                    // 前一轮是mouse，当前是mouse win；或者前一轮是cat，当前是mouse lost。那么前一轮就应该选择该方案。
                    if ((result == WIN && preTurn == MOUSE) || (result == LOST && preTurn == CAT)) {
                        results[preTurn][preMouse][preCat] = result;
                        states.push(State(preTurn, preMouse, preCat));
                    }
                    else {  // 还不能确定上一个状态的结果，但可以将可尝试的度数减1
                        if (--degrees[preTurn][preMouse][preCat] == 0) {  // 可尝试的度数减到0了，那么结果就确定了
                            results[preTurn][preMouse][preCat] = (preTurn == MOUSE ? LOST : WIN);  // 对pre来说，尝试所有方案都没有取胜，那么肯定会输。平局的话degree不会减到0
                            states.push(State(preTurn, preMouse, preCat));
                        }
                    }
                }
            }
        }

        return results[MOUSE][1][2];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> graph = { {2,5},{3},{0,4,5},{1,4,5},{2,3},{0,2,3} };
    check.checkInt(0, o.catMouseGame(graph));

    graph = { {3,4},{3,5},{3,6},{0,1,2},{0,5,6},{1,4},{2,4} };
    check.checkInt(0, o.catMouseGame(graph));

    graph = { {2,9,14},{2,5,7},{0,1,3,8,9,11,14},{2,12},{5,11,18},{1,4,18},{9,17,19},{1,11,12,13,14,17,19},{2,16,17},{0,2,6,12,14,18},{14},{2,4,7},{3,7,9,13},{7,12,14},{0,2,7,9,10,13,17},{18},{8,19},{6,7,8,14,19},{4,5,9,15},{6,7,16,17} };
    check.checkInt(0, o.catMouseGame(graph));

    graph = { {1,3},{0},{3},{0,2} };
    check.checkInt(1, o.catMouseGame(graph));

    graph = { {2,3},{2},{0,1},{0,4},{3} };
    check.checkInt(2, o.catMouseGame(graph));

    graph = { {2,3,4},{2,4},{0,1,4},{0,4},{0,1,2,3} };
    check.checkInt(2, o.catMouseGame(graph));

    graph = { {4},{2,3,5},{1,5,3},{1,2},{0},{1,2} };
    check.checkInt(2, o.catMouseGame(graph));

    graph = { {2,6},{2,4,5,6},{0,1,3,5,6},{2},{1,5,6},{1,2,4},{0,1,2,4} };
    check.checkInt(2, o.catMouseGame(graph));

    graph = { {5,6},{3,4},{6},{1,4,5},{1,3,5},{0,3,4,6},{0,2,5} };
    check.checkInt(2, o.catMouseGame(graph));

    graph = { {2,3,4},{2,3},{0,1,3,4},{0,1,2,4},{0,2,3} };
    check.checkInt(2, o.catMouseGame(graph));

    graph = { {2,4,7,8},{2,3,4,5,7,8,9},{0,1,3,4,5,7,8,9},{1,2,5},{0,1,2,5,6,7,9},{1,2,3,4,6,7},{4,5,8,9},{0,1,2,4,5,9},{0,1,2,6,9},{1,2,4,6,7,8} };
    check.checkInt(2, o.catMouseGame(graph));

    graph = { {6},{4},{9},{5},{1,5},{3,4,6},{0,5,10},{8,9,10},{7},{2,7},{6,7} };
    check.checkInt(1, o.catMouseGame(graph));

    graph = { {5,7,9},{3,4,5,6},{3,4,5,8},{1,2,6,7},{1,2,5,7,9},{0,1,2,4,8},{1,3,7,8},{0,3,4,6,8},{2,5,6,7,9},{0,4,8} };
    check.checkInt(1, o.catMouseGame(graph));
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
