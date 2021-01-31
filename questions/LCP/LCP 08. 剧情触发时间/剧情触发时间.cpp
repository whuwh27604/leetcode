/* 剧情触发时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在战略游戏中，玩家往往需要发展自己的势力来触发各种新的剧情。一个势力的主要属性有三种，分别是文明等级（C），资源储备（R）以及人口数量（H）。在游戏开始时（第 0 天），三种属性的值均为 0。

随着游戏进程的进行，每一天玩家的三种属性都会对应增加，我们用一个二维数组 increase 来表示每天的增加情况。这个二维数组的每个元素是一个长度为 3 的一维数组，例如 [[1,2,1],[3,4,2]] 表示第一天三种属性分别增加 1,2,1 而第二天分别增加 3,4,2。

所有剧情的触发条件也用一个二维数组 requirements 表示。这个二维数组的每个元素是一个长度为 3 的一维数组，对于某个剧情的触发条件 c[i], r[i], h[i]，如果当前 C >= c[i] 且 R >= r[i] 且 H >= h[i] ，则剧情会被触发。

根据所给信息，请计算每个剧情的触发时间，并以一个数组返回。如果某个剧情不会被触发，则该剧情对应的触发时间为 -1 。

示例 1：

输入： increase = [[2,8,4],[2,5,0],[10,9,8]] requirements = [[2,11,3],[15,10,7],[9,17,12],[8,1,14]]

输出: [2,-1,3,-1]

解释：

初始时，C = 0，R = 0，H = 0

第 1 天，C = 2，R = 8，H = 4

第 2 天，C = 4，R = 13，H = 4，此时触发剧情 0

第 3 天，C = 14，R = 22，H = 12，此时触发剧情 2

剧情 1 和 3 无法触发。

示例 2：

输入： increase = [[0,4,5],[4,8,8],[8,6,1],[10,10,0]] requirements = [[12,11,16],[20,2,6],[9,2,6],[10,18,3],[8,14,9]]

输出: [-1,4,3,3,3]

示例 3：

输入： increase = [[1,1,1]] requirements = [[0,0,0]]

输出: [0]

限制：

1 <= increase.length <= 10000
1 <= requirements.length <= 100000
0 <= increase[i] <= 10
0 <= requirements[i] <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ju-qing-hong-fa-shi-jian
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        int i, size = requirements.size();
        vector<int> triggerTimes(size);
        vector<vector<int>> eachDayValues(increase.size() + 1, vector<int>(3));
        getValues(increase, eachDayValues);

        for (i = 0; i < size; ++i) {
            triggerTimes[i] = binarySearch(requirements[i], eachDayValues);
        }

        return triggerTimes;
    }

    void getValues(vector<vector<int>>& increase, vector<vector<int>>& eachDayValues) {
        eachDayValues[0] = { 0,0,0 };

        for (int i = 0; i < (int)increase.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                eachDayValues[i + 1][j] = eachDayValues[i][j] + increase[i][j];
            }
        }
    }

    int binarySearch(vector<int>& requirement, vector<vector<int>>& eachDayValues) {
        int left = 0, right = eachDayValues.size();

        while (left < right) {
            int middle = (left + right) / 2;

            if (eachDayValues[middle][0] < requirement[0] || eachDayValues[middle][1] < requirement[1] || eachDayValues[middle][2] < requirement[2]) {
                left = middle + 1;
            }
            else {
                right = middle;
            }
        }

        return left == eachDayValues.size() ? -1 : left;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> increase = { {2,8,4},{2,5,0},{10,9,8} };
    vector<vector<int>> requirements = { {2,11,3},{15,10,7},{9,17,12},{8,1,14} };
    vector<int> actual = o.getTriggerTime(increase, requirements);
    vector<int> expected = { 2,-1,3,-1 };
    check.checkIntVector(expected, actual);

    increase = { {0,4,5},{4,8,8},{8,6,1},{10,10,0} };
    requirements = { {12,11,16},{20,2,6},{9,2,6},{10,18,3},{8,14,9} };
    actual = o.getTriggerTime(increase, requirements);
    expected = { -1,4,3,3,3 };
    check.checkIntVector(expected, actual);

    increase = { {1,1,1} };
    requirements = { {0,0,0} };
    actual = o.getTriggerTime(increase, requirements);
    expected = { 0 };
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
