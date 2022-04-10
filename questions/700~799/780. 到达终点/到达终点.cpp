/* 到达终点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定四个整数 sx , sy ，tx 和 ty，如果通过一系列的转换可以从起点 (sx, sy) 到达终点 (tx, ty)，则返回 true，否则返回 false。

从点 (x, y) 可以转换到 (x, x+y)  或者 (x+y, y)。

 

示例 1:

输入: sx = 1, sy = 1, tx = 3, ty = 5
输出: true
解释:
可以通过以下一系列转换从起点转换到终点：
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)
示例 2:

输入: sx = 1, sy = 1, tx = 2, ty = 2
输出: false
示例 3:

输入: sx = 1, sy = 1, tx = 1, ty = 1
输出: true
 

提示:

1 <= sx, sy, tx, ty <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reaching-points
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx != tx || sy != ty) {
            if (sx == tx) {
                return ty > sy && (ty - sy) % tx == 0;
            }

            if (sy == ty) {
                return tx > sx && (tx - sx) % ty == 0;
            }

            if (tx >= ty) {
                tx %= ty;
            }
            else {
                ty %= tx;
            }

            if (tx < sx || ty < sy) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.reachingPoints(3, 5, 3, 8));
    check.checkBool(true, o.reachingPoints(1, 1, 3, 5));
    check.checkBool(true, o.reachingPoints(1, 1, 1, 1));
    check.checkBool(true, o.reachingPoints(10, 5, 15, 5));
    check.checkBool(true, o.reachingPoints(5, 2, 7, 16));
    check.checkBool(true, o.reachingPoints(2, 37, 166, 41));
    check.checkBool(false, o.reachingPoints(3, 5, 8, 3));
    check.checkBool(false, o.reachingPoints(1, 1, 2, 2));
    check.checkBool(false, o.reachingPoints(3, 7, 3, 4));
    check.checkBool(false, o.reachingPoints(10, 1, 11, 6));
    check.checkBool(false, o.reachingPoints(1, 6, 999999998, 6));
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
