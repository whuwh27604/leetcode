/* 分割圆的最少切割次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
圆内一个 有效切割 ，符合以下二者之一：

该切割是两个端点在圆上的线段，且该线段经过圆心。
该切割是一端在圆心另一端在圆上的线段。
一些有效和无效的切割如下图所示。



给你一个整数 n ，请你返回将圆切割成相等的 n 等分的 最少 切割次数。



示例 1：



输入：n = 4
输出：2
解释：
上图展示了切割圆 2 次，得到四等分。
示例 2：



输入：n = 3
输出：3
解释：
最少需要切割 3 次，将圆切成三等分。
少于 3 次切割无法将圆切成大小相等面积相同的 3 等分。
同时可以观察到，第一次切割无法将圆切割开。


提示：

1 <= n <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfCuts(int n) {
        return n == 1 ? 0 : (n % 2 == 1 ? n : n / 2);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(0, o.numberOfCuts(1));
    check.checkInt(1, o.numberOfCuts(2));
    check.checkInt(2, o.numberOfCuts(4));
    check.checkInt(3, o.numberOfCuts(3));
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
