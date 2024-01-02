/* 移除栅栏得到的正方形田地的最大面积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个大型的 (m - 1) x (n - 1) 矩形田地，其两个对角分别是 (1, 1) 和 (m, n) ，田地内部有一些水平栅栏和垂直栅栏，分别由数组 hFences 和 vFences 给出。

水平栅栏为坐标 (hFences[i], 1) 到 (hFences[i], n)，垂直栅栏为坐标 (1, vFences[i]) 到 (m, vFences[i]) 。

返回通过 移除 一些栅栏（可能不移除）所能形成的最大面积的 正方形 田地的面积，或者如果无法形成正方形田地则返回 -1。

由于答案可能很大，所以请返回结果对 109 + 7 取余 后的值。

注意：田地外围两个水平栅栏（坐标 (1, 1) 到 (1, n) 和坐标 (m, 1) 到 (m, n) ）以及两个垂直栅栏（坐标 (1, 1) 到 (m, 1) 和坐标 (1, n) 到 (m, n) ）所包围。这些栅栏 不能 被移除。



示例 1：



输入：m = 4, n = 3, hFences = [2,3], vFences = [2]
输出：4
解释：移除位于 2 的水平栅栏和位于 2 的垂直栅栏将得到一个面积为 4 的正方形田地。
示例 2：



输入：m = 6, n = 7, hFences = [2], vFences = [4]
输出：-1
解释：可以证明无法通过移除栅栏形成正方形田地。


提示：

3 <= m, n <= 109
1 <= hFences.length, vFences.length <= 600
1 < hFences[i] < m
1 < vFences[i] < n
hFences 和 vFences 中的元素是唯一的。
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int> hSides, vSides;
        int maxSide = 0;

        hFences.push_back(1);
        hFences.push_back(m);
        getSides(m, hFences, vSides);
        vFences.push_back(1);
        vFences.push_back(n);
        getSides(n, vFences, hSides);

        for (int side : vSides) {
            if (hSides.count(side) != 0) {
                maxSide = max(maxSide, side);
            }
        }

        return maxSide == 0 ? -1 : (int)((long long)maxSide * maxSide % 1000000007);
    }

    void getSides(int n, vector<int>& fences, unordered_set<int>& sides) {
        for (int i = 1; i < (int)fences.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                sides.insert(abs(fences[i] - fences[j]));
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> hFences = { 2,3 };
    vector<int> vFences = { 2 };
    check.checkInt(4, o.maximizeSquareArea(4, 3, hFences, vFences));

    hFences = { 2 };
    vFences = { 4 };
    check.checkInt(-1, o.maximizeSquareArea(6, 7, hFences, vFences));
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
