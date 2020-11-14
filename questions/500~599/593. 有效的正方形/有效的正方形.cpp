/* 有效的正方形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定二维空间中四点的坐标，返回四点是否可以构造一个正方形。

一个点的坐标（x，y）由一个有两个整数的整数数组表示。

示例:

输入: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
输出: True
 

注意:

所有输入整数都在 [-10000，10000] 范围内。
一个有效的正方形有四个等长的正长和四个等角（90度角）。
输入点没有顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        multimap<int, vector<int>> distancePoints;
        distancePoints.insert({ twoPointsDistance(p1, p2), p2 });
        distancePoints.insert({ twoPointsDistance(p1, p3), p3 });
        distancePoints.insert({ twoPointsDistance(p1, p4), p4 });

        auto iter = distancePoints.begin();
        int leftDistance = iter->first;
        vector<int>& p1Lef = iter->second;
        iter++;
        int rightDistance = iter->first;
        vector<int>& p1Right = iter->second;
        iter++;
        int counterDistance = iter->first;
        vector<int>& p1Counter = iter->second;

        if ((leftDistance == 0) || (leftDistance != rightDistance) || (leftDistance + rightDistance != counterDistance)) {
            return false;
        }

        return ((twoPointsDistance(p1Counter, p1Lef) == leftDistance) && (twoPointsDistance(p1Counter, p1Right) == leftDistance)
            && (twoPointsDistance(p1Lef, p1Right) == counterDistance));
    }

    int twoPointsDistance(vector<int>& p, vector<int>& q) {
        return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> p1 = { 0,0 };
    vector<int> p2 = { 1,1 };
    vector<int> p3 = { 1,0 };
    vector<int> p4 = { 0,1 };
    check.checkBool(true, o.validSquare(p1, p2, p3, p4));

    p1 = { 1,0 };
    p2 = { 1,1 };
    p3 = { 0,0 };
    p4 = { 0,1 };
    check.checkBool(true, o.validSquare(p1, p2, p3, p4));

    p1 = { 1,0 };
    p2 = { 2,2 };
    p3 = { 0,0 };
    p4 = { 0,1 };
    check.checkBool(false, o.validSquare(p1, p2, p3, p4));

    p1 = { 0,0 };
    p2 = { 2,2 };
    p3 = { 1,0 };
    p4 = { 0,1 };
    check.checkBool(false, o.validSquare(p1, p2, p3, p4));

    p1 = { 0,0 };
    p2 = { 0,0 };
    p3 = { 0,0 };
    p4 = { 0,0 };
    check.checkBool(false, o.validSquare(p1, p2, p3, p4));

    p1 = { 1,0 };
    p2 = { -1,0 };
    p3 = { 0,1 };
    p4 = { 0,-1 };
    check.checkBool(true, o.validSquare(p1, p2, p3, p4));
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
