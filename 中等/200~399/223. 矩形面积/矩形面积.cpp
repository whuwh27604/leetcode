/* 矩形面积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。

每个矩形由其左下顶点和右上顶点坐标表示，如图所示。



示例:

输入: -3, 0, 3, 4, 0, -1, 9, 2
输出: 45
说明: 假设矩形面积不会超出 int 的范围。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rectangle-area
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long x = C - A;
        long long y = D - B;
        long long area1 = x * y;
        x = G - E;
        y = H - F;
        long long area2 = x * y;
        long long overArea = 0;

        if ((max(A, E) < min(C, G)) && (max(B, F) < min(D, H))) {
            x = min(C, G) - max(A, E);
            y = min(D, H) - max(B, F);
            overArea = x * y;
        }

        return (int)(area1 + area2 - overArea);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(45, o.computeArea(-3, 0, 3, 4, 0, -1, 9, 2));
    check.checkInt(2, o.computeArea(0, 0, 1, 1, 1, 0, 2, 1));
    check.checkInt(9, o.computeArea(0, 0, 3, 3, 0, 0, 3, 3));
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
