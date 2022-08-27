/* 十字路口的交通.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
前往「力扣挑战赛」场馆的道路上，有一个拥堵的十字路口，该十字路口由两条双向两车道的路交叉构成。由于信号灯故障，交警需要手动指挥拥堵车辆。假定路口没有新的来车且一辆车从一个车道驶入另一个车道所需的时间恰好为一秒钟，长度为 4 的一维字符串数组 directions 中按照 东、南、西、北 顺序记录了四个方向从最靠近路口到最远离路口的车辆计划开往的方向。其中：

"E" 表示向东行驶；
"S" 表示向南行驶；
"W" 表示向西行驶；
"N" 表示向北行驶。
交警每秒钟只能指挥各个车道距离路口最近的一辆车，且每次指挥需要满足如下规则：

同一秒钟内，一个方向的车道只允许驶出一辆车；
同一秒钟内，一个方向的车道只允许驶入一辆车；
同一秒钟内，车辆的行驶路线不可相交。
请返回最少需要几秒钟，该十字路口等候的车辆才能全部走完。

各个车道驶出的车辆可能的行驶路线如图所示：



注意：

测试数据保证不会出现掉头行驶指令，即某一方向的行驶车辆计划开往的方向不会是当前车辆所在的车道的方向;
表示堵塞车辆行驶方向的字符串仅用大写字母 "E"，"N"，"W"，"S" 表示。
示例 1：

输入：directions = ["W","N","ES","W"]

输出：2

解释：
第 1 秒：东西方向排在最前的车先行，剩余车辆状态 ["","N","S","W"]；
第 2 秒：南、西、北方向的车行驶，路口无等待车辆；
因此最少需要 2 秒，返回 2。

示例 2：

输入：directions = ["NS","WE","SE","EW"]

输出：3

解释：
第 1 秒：四个方向排在最前的车均可驶出；
第 2 秒：东南方向的车驶出，剩余车辆状态 ["","","E","W"]；
第 3 秒：西北方向的车驶出。

提示：

directions.length = 4
0 <= directions[i].length <= 20

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/Y1VbOX
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

bool fourLinesValids[88][88][88][88];

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        vector<char> dirs = { 'E','S','W','N','A' };
        vector<unordered_map<char, vector<int>>> linePoints = {  // 每条line通过的point编号
                    {{'S',{1,4,5,9}},{'W',{2,8,11}},{'N',{3}},{'A',{}}},
                    {{'W',{2,5,6,10}},{'N',{3,8,9}},{'E',{0}},{'A',{}}},
                    {{'N',{3,6,7,11}},{'E',{0,9,10}},{'S',{1}},{'A',{}}},
                    {{'E',{0,4,7,8}},{'S',{1,10,11}},{'W',{2}},{'A',{}}}
        };

        for (char d0 : dirs) {
            for (char d1 : dirs) {
                for (char d2 : dirs) {
                    for (char d3 : dirs) {  // 枚举所有lines
                        fourLinesValids[d0][d1][d2][d3] = true;
                        vector<char> fourDirs = { d0,d1,d2,d3 };
                        vector<bool> points(12, false);  // 4个方向的lines总共经过12个点

                        for (int i = 0; i < 4 && fourLinesValids[d0][d1][d2][d3]; ++i) {
                            for (int point : linePoints[i][fourDirs[i]]) {
                                if (points[point]) {  // 两条lines通过同一个point则非法
                                    fourLinesValids[d0][d1][d2][d3] = false;
                                    break;
                                }

                                points[point] = true;
                            }
                        }
                    }
                }
            }
        }
    }
}

class Solution {
public:
    int trafficCommand(vector<string>& directions) {
        int size0 = directions[0].size(), size1 = directions[1].size(), size2 = directions[2].size(), size3 = directions[3].size();
        int dp[21][21][21][21];

        init();

        for (int i0 = size0; i0 >= 0; --i0) {
            for (int i1 = size1; i1 >= 0; --i1) {
                for (int i2 = size2; i2 >= 0; --i2) {
                    for (int i3 = size3; i3 >= 0; --i3) {
                        if (i0 == size0 && i1 == size1 && i2 == size2 && i3 == size3) {  // 所有方向的车都走完了
                            dp[i0][i1][i2][i3] = 0;
                        }
                        else {
                            dp[i0][i1][i2][i3] = INT_MAX;

                            for (int mask = 1; mask < 16; ++mask) {  // 枚举所有可能的lines组合
                                char line0 = 'A', line1 = 'A', line2 = 'A', line3 = 'A';
                                int j0 = i0, j1 = i1, j2 = i2, j3 = i3;

                                if (((mask & 1) != 0 && i0 == size0) || ((mask & 2) != 0 && i1 == size1)
                                    || ((mask & 4) != 0 && i2 == size2) || ((mask & 8) != 0 && i3 == size3)) {
                                    continue;
                                }

                                if ((mask & 1) != 0) {
                                    line0 = directions[0][i0], ++j0;
                                }

                                if ((mask & 2) != 0) {
                                    line1 = directions[1][i1], ++j1;
                                }

                                if ((mask & 4) != 0) {
                                    line2 = directions[2][i2], ++j2;
                                }

                                if ((mask & 8) != 0) {
                                    line3 = directions[3][i3], ++j3;
                                }

                                if (fourLinesValids[line0][line1][line2][line3]) {  // 该组合是合法的，则放行该组合的车辆，看剩下的车还需要多少时间
                                    dp[i0][i1][i2][i3] = min(dp[i0][i1][i2][i3], 1 + dp[j0][j1][j2][j3]);
                                }
                            }
                        }
                    }
                }
            }
        }

        return dp[0][0][0][0];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> directions = { "W","N","ES","W" };
    check.checkInt(2, o.trafficCommand(directions));

    directions = { "NS","WE","SE","EW" };
    check.checkInt(3, o.trafficCommand(directions));

    directions = { "NWNS","WEENW","SSSS","WESS" };
    check.checkInt(7, o.trafficCommand(directions));

    directions = { "NSSW","NWNNW","EEESE","WSWWS" };
    check.checkInt(11, o.trafficCommand(directions));

    directions = { "WSSWNWWWNWNSNNN","NNWWWEENEWEWNE","NENSSNESESEENSNSSES","SSEWSSSEESSWWSESS" };
    check.checkInt(29, o.trafficCommand(directions));

    directions = { "SSSSSSSSSSSSSSSSSSSS","WWWWWWWWWWWWWWWWWWWW","SSSSSSSSSSSSSSSSSSSS","SSSSSSSSSSSSSSSSSSSS" };
    check.checkInt(60, o.trafficCommand(directions));
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
