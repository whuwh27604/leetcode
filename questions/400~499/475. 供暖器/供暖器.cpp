/* 供暖器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。

现在，给出位于一条水平线上的房屋和供暖器的位置，找到可以覆盖所有房屋的最小加热半径。

所以，你的输入将会是房屋和供暖器的位置。你将输出供暖器的最小加热半径。

说明:

给出的房屋和供暖器的数目是非负数且不会超过 25000。
给出的房屋和供暖器的位置均是非负数且不会超过10^9。
只要房屋位于供暖器的半径内(包括在边缘上)，它就可以得到供暖。
所有供暖器都遵循你的半径标准，加热的半径也一样。
示例 1:

输入: [1,2,3],[2]
输出: 1
解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
示例 2:

输入: [1,2,3,4],[1,4]
输出: 1
解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/heaters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int i, left = 0, right = 0, heatersLen = heaters.size(), minRadius = 0;

        for (i = 0; i < (int)houses.size(); i++) {
            int house = houses[i];
            lastLeft(heaters, left, heatersLen, house);
            firstRight(heaters, right, heatersLen, house);
            int radius = min(abs(heaters[left] - house), abs(heaters[right] - house));
            minRadius = max(minRadius, radius);
        }

        return minRadius;
    }

    void lastLeft(vector<int>& heaters, int& left, int heatersLen, int house) {
        while (((left + 1) < heatersLen) && (heaters[left + 1] <= house)) {
            left++;
        }
    }

    void firstRight(vector<int>& heaters, int& right, int heatersLen, int house) {
        while (((right + 1) < heatersLen) && (heaters[right] < house)) {
            right++;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> houses = { 1,2,3 };
    vector<int> heaters = { 2 };
    check.checkInt(1, o.findRadius(houses, heaters));

    houses = { 1,2,3,4 };
    heaters = { 1,4 };
    check.checkInt(1, o.findRadius(houses, heaters));

    houses = {  };
    heaters = {  };
    check.checkInt(0, o.findRadius(houses, heaters));

    houses = {  };
    heaters = { 1 };
    check.checkInt(0, o.findRadius(houses, heaters));

    houses = { 0 };
    heaters = { 2 };
    check.checkInt(2, o.findRadius(houses, heaters));

    houses = { 0,5 };
    heaters = { 2 };
    check.checkInt(3, o.findRadius(houses, heaters));

    houses = { 0,5 };
    heaters = { 2,3,4 };
    check.checkInt(2, o.findRadius(houses, heaters));

    houses = { 0,5,10 };
    heaters = { 2,3,4,6 };
    check.checkInt(4, o.findRadius(houses, heaters));

    houses = { 0,5,10 };
    heaters = { 2,3,4,6,11 };
    check.checkInt(2, o.findRadius(houses, heaters));

    houses = { 0,5,10 };
    heaters = { 2,3,4,5,6,11 };
    check.checkInt(2, o.findRadius(houses, heaters));

    houses = { 5 };
    heaters = { 1,11 };
    check.checkInt(4, o.findRadius(houses, heaters));

    houses = { 5,6 };
    heaters = { 1,12 };
    check.checkInt(5, o.findRadius(houses, heaters));
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
