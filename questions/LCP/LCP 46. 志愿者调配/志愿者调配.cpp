/* 志愿者调配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
「力扣挑战赛」有 n 个比赛场馆（场馆编号从 0 开始），场馆之间的通道分布情况记录于二维数组 edges 中，edges[i]= [x, y] 表示第 i 条通道连接场馆 x 和场馆 y(即两个场馆相邻)。初始每个场馆中都有一定人数的志愿者（不同场馆人数可能不同），后续 m 天每天均会根据赛事热度进行志愿者人数调配。调配方案分为如下三种：

将编号为 idx 的场馆内的志愿者人数减半；
将编号为 idx 的场馆相邻的场馆的志愿者人数都加上编号为 idx 的场馆的志愿者人数；
将编号为 idx 的场馆相邻的场馆的志愿者人数都减去编号为 idx 的场馆的志愿者人数。
所有的调配信息记录于数组 plans 中，plans[i] = [num,idx] 表示第 i 天对编号 idx 的场馆执行了第 num 种调配方案。
在比赛结束后对调配方案进行复盘时，不慎将第 0 个场馆的最终志愿者人数丢失，只保留了初始所有场馆的志愿者总人数 totalNum ，以及记录了第 1 ~ n-1 个场馆的最终志愿者人数的一维数组 finalCnt。请你根据现有的信息求出初始每个场馆的志愿者人数，并按场馆编号顺序返回志愿者人数列表。

注意：

测试数据保证当某场馆进行第一种调配时，该场馆的志愿者人数一定为偶数；
测试数据保证当某场馆进行第三种调配时，该场馆的相邻场馆志愿者人数不为负数；
测试数据保证比赛开始时每个场馆的志愿者人数都不超过 10^9；
测试数据保证给定的场馆间的道路分布情况中不会出现自环、重边的情况。
示例 1：


输入：
finalCnt = [1,16], totalNum = 21, edges = [[0,1],[1,2]], plans = [[2,1],[1,0],[3,0]]

输出：[5,7,9]

解释：


示例 2 ：

输入：
finalCnt = [4,13,4,3,8], totalNum = 54, edges = [[0,3],[1,3],[4,3],[2,3],[2,5]], plans = [[1,1],[3,3],[2,5],[1,0]]

输出：[10,16,9,4,7,8]

提示：

2 <= n <= 5*10^4
1 <= edges.length <= min((n * (n - 1)) / 2, 5*10^4)
0 <= edges[i][0], edges[i][1] < n
1 <= plans.length <= 10
1 <= plans[i][0] <=3
0 <= plans[i][1] < n
finalCnt.length = n-1
0 <= finalCnt[i] < 10^9
0 <= totalNum < 5*10^13

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/05ZEDJ
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> volunteerDeployment(vector<int>& finalCnt, long long totalNum, vector<vector<int>>& edges, vector<vector<int>>& plans) {
        int n = finalCnt.size() + 1;
        vector<vector<int>> adjs(n);
        vector<vector<long long>> coefficients(n, vector<long long>(2, 0));
        vector<int> initialCnt(n);

        buildAdjs(edges, adjs);
        init(finalCnt, coefficients);
        reverseInfer(plans, adjs, coefficients);
        int x = calc(coefficients, totalNum);
        getInitialCnt(coefficients, n, x, initialCnt);

        return initialCnt;
    }

    void buildAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    void init(vector<int>& finalCnt, vector<vector<long long>>& coefficients) {
        int index = 0;
        coefficients[0][0] = 1;

        for (int count : finalCnt) {
            coefficients[++index][1] = count;
        }
    }

    void reverseInfer(vector<vector<int>>& plans, vector<vector<int>>& adjs, vector<vector<long long>>& coefficients) {
        for (int i = plans.size() - 1; i >= 0; --i) {
            int idx = plans[i][1];

            if (plans[i][0] == 1) {
                coefficients[idx][0] *= 2;
                coefficients[idx][1] *= 2;
            }
            else if (plans[i][0] == 2) {
                for (int adj : adjs[idx]) {
                    coefficients[adj][0] -= coefficients[idx][0];
                    coefficients[adj][1] -= coefficients[idx][1];
                }
            }
            else {
                for (int adj : adjs[idx]) {
                    coefficients[adj][0] += coefficients[idx][0];
                    coefficients[adj][1] += coefficients[idx][1];
                }
            }
        }
    }

    int calc(vector<vector<long long>>& coefficients, long long totalNum) {
        long long a = 0, b = 0;

        for (auto& coefficient : coefficients) {
            a += coefficient[0];
            b += coefficient[1];
        }

        return (int)((totalNum - b) / a);
    }

    void getInitialCnt(vector<vector<long long>>& coefficients, int n, int x, vector<int>& initialCnt) {
        for (int i = 0; i < n; ++i) {
            initialCnt[i] = (int)(coefficients[i][0] * x + coefficients[i][1]);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> finalCnt = { 1,16 };
    vector<vector<int>> edges = { {0,1},{1,2} };
    vector<vector<int>> plans = { {2,1},{1,0},{3,0} };
    vector<int> actual = o.volunteerDeployment(finalCnt, 21, edges, plans);
    vector<int> expected = { 5,7,9 };
    check.checkIntVector(expected, actual);

    finalCnt = { 4,13,4,3,8 };
    edges = { {0,3},{1,3},{4,3},{2,3},{2,5} };
    plans = { {1,1},{3,3},{2,5},{1,0} };
    actual = o.volunteerDeployment(finalCnt, 54, edges, plans);
    expected = { 10,16,9,4,7,8 };
    check.checkIntVector(expected, actual);

    finalCnt = { 4 };
    edges = { {0,1} };
    plans = { {1,1} };
    actual = o.volunteerDeployment(finalCnt, 54, edges, plans);
    expected = { 46,8 };
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
