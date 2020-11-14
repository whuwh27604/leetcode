/* 在圆内随机生成点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定圆的半径和圆心的 x、y 坐标，写一个在圆中产生均匀随机点的函数 randPoint 。

说明:

输入值和输出值都将是浮点数。
圆的半径和圆心的 x、y 坐标将作为参数传递给类的构造函数。
圆周上的点也认为是在圆中。
randPoint 返回一个包含随机点的x坐标和y坐标的大小为2的数组。
示例 1：

输入:
["Solution","randPoint","randPoint","randPoint"]
[[1,0,0],[],[],[]]
输出: [null,[-0.72939,-0.65505],[-0.78502,-0.28626],[-0.83119,-0.19803]]
示例 2：

输入:
["Solution","randPoint","randPoint","randPoint"]
[[10,5,-7.5],[],[],[]]
输出: [null,[11.52438,-8.33273],[2.46992,-16.21705],[11.13430,-12.42337]]
输入语法说明：

输入是两个列表：调用成员函数名和调用的参数。Solution 的构造函数有三个参数，圆的半径、圆心的 x 坐标、圆心的 y 坐标。randPoint 没有参数。输入参数是一个列表，即使参数为空，也会输入一个 [] 空列表。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-random-point-in-a-circle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <random>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double circleRadius, centerX, centerY;
    mt19937 generator{ random_device{}() };
    uniform_real_distribution<double> uni{ -1, 1.000001 };

    Solution(double radius, double x_center, double y_center) : circleRadius(radius), centerX(x_center), centerY(y_center) {}

    vector<double> randPoint() {
        double x, y;

        do {
            x = uni(generator) * circleRadius;
            y = uni(generator) * circleRadius;
        } while ((pow(x, 2) + pow(y, 2) > pow(circleRadius, 2)) || (x > circleRadius) || (y > circleRadius));

        return { centerX + x, centerY + y };
    }
};

int main()
{
    Solution o(1, 5, 5);
    CheckResult check;

    for (int i = 0; i < 50; i++) {
        cout << o.randPoint()[0] << "," << o.randPoint()[1] << endl;
    }
    cout << endl;
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
