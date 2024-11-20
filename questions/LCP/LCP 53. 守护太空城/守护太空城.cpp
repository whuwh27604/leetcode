/* 守护太空城.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
各位勇者请注意，力扣太空城发布陨石雨红色预警。

太空城中的一些舱室将要受到陨石雨的冲击，这些舱室按照编号 0 ~ N 的顺序依次排列。为了阻挡陨石损毁舱室，太空城可以使用能量展开防护屏障，具体消耗如下：

选择一个舱室开启屏障，能量消耗为 2
选择相邻两个舱室开启联合屏障，能量消耗为 3
对于已开启的 一个 屏障，多维持一时刻，能量消耗为 1
已知陨石雨的影响范围和到达时刻，time[i] 和 position[i] 分别表示该陨石的到达时刻和冲击位置。请返回太空舱能够守护所有舱室所需要的最少能量。

注意：

同一时间，一个舱室不能被多个屏障覆盖
陨石雨仅在到达时刻对冲击位置处的舱室有影响
示例 1：

输入：time = [1,2,1], position = [6,3,3]

输出：5

解释：时刻 1，分别开启编号 3、6 舱室的屏障，能量消耗 2*2 = 4。时刻 2，维持编号 3 舱室的屏障，能量消耗 1。因此，最少需要能量 5。


示例 2：

输入：time = [1,1,1,2,2,3,5], position = [1,2,3,1,2,1,3]

输出：9

解释：时刻 1，开启编号 1、2 舱室的联合屏障，能量消耗 3。时刻 1，开启编号 3 舱室的屏障，能量消耗 2 。时刻 2，维持编号 1、2 舱室的联合屏障，能量消耗 1。时刻 3，维持编号 1、2 舱室的联合屏障，能量消耗 1。时刻 5，重新开启编号 3 舱室的屏障，能量消耗 2。因此，最少需要能量 9。


提示：

1 <= time.length == position.length <= 500
1 <= time[i] <= 5
0 <= position[i] <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int defendSpaceCity(vector<int>& time, vector<int>& position) {
        int n = *max_element(position.begin(), position.end());
        int maxMask = (1 << *max_element(time.begin(), time.end())) - 1;

        vector<int> rainMask(n + 1, 0);
        getRainMask(time, position, rainMask);

        vector<int> jointCost(maxMask + 1, 0), singleCost(maxMask + 1, 0);
        preprocess(maxMask, jointCost, singleCost);

        return getMinCost(n, maxMask, rainMask, jointCost, singleCost);
    }

    void getRainMask(vector<int>& time, vector<int>& position, vector<int>& rainMask) {
        for (int i = 0; i < (int)time.size(); ++i) {
            rainMask[position[i]] |= (1 << (time[i] - 1));
        }
    }

    void preprocess(int maxMask, vector<int>& jointCost, vector<int>& singleCost) {
        jointCost[0] = singleCost[0] = 0;

        for (int mask = 1; mask <= maxMask; ++mask) {
            int lastBit = (mask & -mask);
            int subMask = mask ^ lastBit;
            bool consective = (((lastBit << 1) & mask) != 0);  // 连续的bit，可以延续时间，否则只能新开一个
            jointCost[mask] = jointCost[subMask] + (consective ? 1 : 3);
            singleCost[mask] = singleCost[subMask] + (consective ? 1 : 2);
        }
    }

    int getMinCost(int n, int maxMask, vector<int>& rainMask, vector<int>& jointCost, vector<int>& singleCost) {
        vector<int> dp(maxMask + 1);

        for (int mask = 0; mask <= maxMask; ++mask) {  // 枚举联合的时间点
            dp[mask] = jointCost[mask] + singleCost[(maxMask ^ mask) & rainMask[0]];
        }

        for (int i = 1; i <= n; ++i) {  // 枚举位置
            vector<int> tmp(maxMask + 1, INT_MAX / 2);

            for (int mask = 0; mask <= maxMask; ++mask) {  // 枚举联合的时间点
                int prev = mask ^ maxMask;  // 枚举前一个状态的联合mask，不能和当前mask有交集，这样当前位置才能够选择联合
                for (int sub = prev; sub != 0; sub = (sub - 1) & prev) {  // 枚举prev的所有子集
                    tmp[mask] = min(tmp[mask], jointCost[mask] + dp[sub] + singleCost[(prev ^ sub) & rainMask[i]]);
                }
                tmp[mask] = min(tmp[mask], jointCost[mask] + dp[0] + singleCost[prev & rainMask[i]]);  // sub = 0是合法的
            }

            dp = tmp;
        }

        return dp[0];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> time = { 1,2,1 };
    vector<int> position = { 6,3,3 };
    check.checkInt(5, o.defendSpaceCity(time, position));

    time = { 1,1,1,2,2,3,5 };
    position = { 1,2,3,1,2,1,3 };
    check.checkInt(9, o.defendSpaceCity(time, position));
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
