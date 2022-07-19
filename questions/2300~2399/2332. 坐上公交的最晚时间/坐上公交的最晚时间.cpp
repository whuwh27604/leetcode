/* 坐上公交的最晚时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始长度为 n 的整数数组 buses ，其中 buses[i] 表示第 i 辆公交车的出发时间。同时给你一个下标从 0 开始长度为 m 的整数数组 passengers ，其中 passengers[j] 表示第 j 位乘客的到达时间。所有公交车出发的时间互不相同，所有乘客到达的时间也互不相同。

给你一个整数 capacity ，表示每辆公交车 最多 能容纳的乘客数目。

每位乘客都会搭乘下一辆有座位的公交车。如果你在 y 时刻到达，公交在 x 时刻出发，满足 y <= x  且公交没有满，那么你可以搭乘这一辆公交。最早 到达的乘客优先上车。

返回你可以搭乘公交车的最晚到达公交站时间。你 不能 跟别的乘客同时刻到达。

注意：数组 buses 和 passengers 不一定是有序的。

 

示例 1：

输入：buses = [10,20], passengers = [2,17,18,19], capacity = 2
输出：16
解释：
第 1 辆公交车载着第 1 位乘客。
第 2 辆公交车载着你和第 2 位乘客。
注意你不能跟其他乘客同一时间到达，所以你必须在第二位乘客之前到达。
示例 2：

输入：buses = [20,30,10], passengers = [19,13,26,4,25,11,21], capacity = 2
输出：20
解释：
第 1 辆公交车载着第 4 位乘客。
第 2 辆公交车载着第 6 位和第 2 位乘客。
第 3 辆公交车载着第 1 位乘客和你。
 

提示：

n == buses.length
m == passengers.length
1 <= n, m, capacity <= 105
2 <= buses[i], passengers[i] <= 109
buses 中的元素 互不相同 。
passengers 中的元素 互不相同 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/the-latest-time-to-catch-a-bus
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        int last = 0;
        bool full = isLastBusFull(buses, passengers, capacity, last);

        if (full || passengers[last] == buses.back()) {
            return getPrev(passengers, last);  // 最后一辆bus坐满了，或者没坐满但是最后一个人占用了最后的时间，需要往前找一个人替换掉
        }

        return buses.back();  // 最后的时间空着，直接在该bus的发车时间到达即可
    }

    bool isLastBusFull(vector<int>& buses, vector<int>& passengers, int capacity, int& last) {
        int j = 0, size = passengers.size();
        bool full = false;

        for (int i = 0; i < (int)buses.size(); ++i) {
            int count = 0;
            full = false;

            for (; j < size && passengers[j] <= buses[i]; ++j) {
                last = j;

                if (++count == capacity) {
                    full = true;
                    ++j;
                    break;
                }
            }
        }

        return full;
    }

    int getPrev(vector<int>& passengers, int last) {
        for (int i = last; i > 0; --i) {
            if (passengers[i - 1] != passengers[i] - 1) {
                return passengers[i] - 1;
            }
        }

        return passengers[0] - 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> buses = { 10,20 };
    vector<int> passengers = { 2,17,18,19 };
    check.checkInt(16, o.latestTimeCatchTheBus(buses, passengers, 2));

    buses = { 20,30,10 };
    passengers = { 19,13,26,4,25,11,21 };
    check.checkInt(20, o.latestTimeCatchTheBus(buses, passengers, 2));

    buses = { 2 };
    passengers = { 2 };
    check.checkInt(1, o.latestTimeCatchTheBus(buses, passengers, 2));

    buses = { 5 };
    passengers = { 19,13,26,4,25,11,21 };
    check.checkInt(3, o.latestTimeCatchTheBus(buses, passengers, 1));
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
