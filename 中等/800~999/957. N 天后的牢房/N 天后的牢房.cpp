/* N 天后的牢房.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
8 间牢房排成一排，每间牢房不是有人住就是空着。

每天，无论牢房是被占用或空置，都会根据以下规则进行更改：

如果一间牢房的两个相邻的房间都被占用或都是空的，那么该牢房就会被占用。
否则，它就会被空置。
（请注意，由于监狱中的牢房排成一行，所以行中的第一个和最后一个房间无法有两个相邻的房间。）

我们用以下方式描述监狱的当前状态：如果第 i 间牢房被占用，则 cell[i]==1，否则 cell[i]==0。

根据监狱的初始状态，在 N 天后返回监狱的状况（和上述 N 种变化）。

 

示例 1：

输入：cells = [0,1,0,1,1,0,0,1], N = 7
输出：[0,0,1,1,0,0,0,0]
解释：
下表概述了监狱每天的状况：
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

示例 2：

输入：cells = [1,0,0,1,0,0,1,0], N = 1000000000
输出：[0,0,1,1,1,1,1,0]
 

提示：

cells.length == 8
cells[i] 的值为 0 或 1 
1 <= N <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/prison-cells-after-n-days
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        // 1、一个状态的下一个状态是固定的；2、从第二天开始，首尾就只能是0，所以最多只有2^6=64个状态。综上，状态会快速成环。
        unordered_map<int, int> states = { {cells2State(cells),0} };  // 记录每个状态对应的天数
        vector<vector<int>> eachDayCells;
        eachDayCells.push_back(cells);
        int day, loopLen = INT_MAX, outLoopLen = 0;

        for (day = 0; day < N; ++day) {
            for (int i = 1; i < 7; ++i) {
                cells[i] = !(eachDayCells[day][i - 1] ^ eachDayCells[day][i + 1]);
            }
            cells[0] = 0;
            cells[7] = 0;

            int state = cells2State(cells);
            if (states.count(state) == 1) {
                outLoopLen = states[state];
                loopLen = day + 1 - states[state];
                break;
            }

            states[state] = day + 1;
            eachDayCells.push_back(cells);
        }

        return eachDayCells[(N - outLoopLen) % loopLen + outLoopLen];
    }

    int cells2State(vector<int>& cells) {
        return (cells[0] << 7) + (cells[1] << 6) + (cells[2] << 5) + (cells[3] << 4) + (cells[4] << 3) + (cells[5] << 2) + (cells[6] << 1) + cells[7];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> cells = { 0,1,0,1,1,0,0,1 };
    vector<int> actual = o.prisonAfterNDays(cells, 7);
    vector<int> expected = { 0,0,1,1,0,0,0,0 };
    check.checkIntVector(expected, actual);

    cells = { 0,1,0,1,1,0,0,1 };
    actual = o.prisonAfterNDays(cells, 14);
    expected = { 0,0,0,0,1,1,0,0 };
    check.checkIntVector(expected, actual);

    cells = { 0,1,0,1,1,0,0,1 };
    actual = o.prisonAfterNDays(cells, 28);
    expected = { 0,0,0,0,1,1,0,0 };
    check.checkIntVector(expected, actual);

    cells = { 0,1,0,1,1,0,0,1 };
    actual = o.prisonAfterNDays(cells, 1000000000);
    expected = { 0,0,1,0,1,1,0,0 };
    check.checkIntVector(expected, actual);

    cells = { 0,0,1,1,1,1,0,0 };
    actual = o.prisonAfterNDays(cells, 6);
    expected = { 0,1,1,1,1,1,1,0 };
    check.checkIntVector(expected, actual);

    cells = { 0,0,1,1,1,1,0,0 };
    actual = o.prisonAfterNDays(cells, 7);
    expected = { 0,0,1,1,1,1,0,0 };
    check.checkIntVector(expected, actual);

    cells = { 0,0,1,1,1,1,0,0 };
    actual = o.prisonAfterNDays(cells, 8);
    expected = { 0,0,0,1,1,0,0,0 };
    check.checkIntVector(expected, actual);

    cells = { 0,0,1,1,1,1,0,0 };
    actual = o.prisonAfterNDays(cells, 1000000000);
    expected = { 0,1,1,1,1,1,1,0 };
    check.checkIntVector(expected, actual);

    cells = { 1,1,1,1,1,1,1,1 };
    actual = o.prisonAfterNDays(cells, 13);
    expected = { 0,1,1,0,0,1,1,0 };
    check.checkIntVector(expected, actual);

    cells = { 1,1,1,1,1,1,1,1 };
    actual = o.prisonAfterNDays(cells, 14);
    expected = { 0,0,0,0,0,0,0,0 };
    check.checkIntVector(expected, actual);

    cells = { 1,1,1,1,1,1,1,1 };
    actual = o.prisonAfterNDays(cells, 15);
    expected = { 0,1,1,1,1,1,1,0 };
    check.checkIntVector(expected, actual);

    cells = { 1,1,1,1,1,1,1,1 };
    actual = o.prisonAfterNDays(cells, 999999999);
    expected = { 0,1,0,1,1,0,1,0 };
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
