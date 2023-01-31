/* 最大化城市的最小供电站数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始长度为 n 的整数数组 stations ，其中 stations[i] 表示第 i 座城市的供电站数目。

每个供电站可以在一定 范围 内给所有城市提供电力。换句话说，如果给定的范围是 r ，在城市 i 处的供电站可以给所有满足 |i - j| <= r 且 0 <= i, j <= n - 1 的城市 j 供电。

|x| 表示 x 的 绝对值 。比方说，|7 - 5| = 2 ，|3 - 10| = 7 。
一座城市的 电量 是所有能给它供电的供电站数目。

政府批准了可以额外建造 k 座供电站，你需要决定这些供电站分别应该建在哪里，这些供电站与已经存在的供电站有相同的供电范围。

给你两个整数 r 和 k ，如果以最优策略建造额外的发电站，返回所有城市中，最小供电站数目的最大值是多少。

这 k 座供电站可以建在多个城市。



示例 1：

输入：stations = [1,2,4,5,0], r = 1, k = 2
输出：5
解释：
最优方案之一是把 2 座供电站都建在城市 1 。
每座城市的供电站数目分别为 [1,4,4,5,0] 。
- 城市 0 的供电站数目为 1 + 4 = 5 。
- 城市 1 的供电站数目为 1 + 4 + 4 = 9 。
- 城市 2 的供电站数目为 4 + 4 + 5 = 13 。
- 城市 3 的供电站数目为 5 + 4 = 9 。
- 城市 4 的供电站数目为 5 + 0 = 5 。
供电站数目最少是 5 。
无法得到更优解，所以我们返回 5 。
示例 2：

输入：stations = [4,4,4,4], r = 0, k = 3
输出：4
解释：
无论如何安排，总有一座城市的供电站数目是 4 ，所以最优解是 4 。


提示：

n == stations.length
1 <= n <= 105
0 <= stations[i] <= 105
0 <= r <= n - 1
0 <= k <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        long long low = 0, high = LLONG_MAX, maxMinPower = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (check(stations, r, k, mid)) {
                maxMinPower = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return maxMinPower;
    }

    bool check(vector<int>& stations, int r, int k, long long minPower) {
        int size = stations.size();
        long long power = 0, addPower = 0, totalAdd = 0;
        vector<long long> diffs(size, 0);

        for (int i = 0; i < r; ++i) {
            power += stations[i];
        }

        for (int i = 0; i < size; ++i) {
            addPower += diffs[i];  // 先利用差分数组计算当前位置实际新增的power

            if (i > r) {  // 计算当前位置的power，移出左边界
                power -= stations[i - r - 1];
            }
            if (i + r < size) {  // 移入右边界
                power += stations[i + r];
            }

            if (power + addPower < minPower) {  // 比设定的minPower小，需要在尽可能靠右的位置新增station
                long long add = minPower - power - addPower;  // 新增add个station，贪心的放在i + r位置，可以覆盖[i, i + 2 * r]区域
                addPower += add;  // 从当前位置开始，需要加上新增station提供的power
                if (i + 2 * r + 1 < size) {
                    diffs[i + 2 * r + 1] -= add;  // 从i + 2 * r + 1位置开始，需要减去新增station提供的power
                }

                totalAdd += add;
                if (totalAdd > k) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> stations = { 1,2,4,5,0 };
    check.checkLongLong(5, o.maxPower(stations, 1, 2));

    stations = { 4,4,4,4 };
    check.checkLongLong(4, o.maxPower(stations, 0, 3));

    stations = { 13,12,8,14,7 };
    check.checkLongLong(52, o.maxPower(stations, 2, 23));
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
