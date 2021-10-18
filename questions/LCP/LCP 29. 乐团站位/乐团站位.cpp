/* 乐团站位.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
某乐团的演出场地可视作 num * num 的二维矩阵 grid（左上角坐标为 [0,0])，每个位置站有一位成员。乐团共有 9 种乐器，乐器编号为 1~9，每位成员持有 1 个乐器。

为保证声乐混合效果，成员站位规则为：自 grid 左上角开始顺时针螺旋形向内循环以 1，2，...，9 循环重复排列。例如当 num = 5 时，站位如图所示



请返回位于场地坐标 [Xpos,Ypos] 的成员所持乐器编号。

示例 1：

输入：num = 3, Xpos = 0, Ypos = 2

输出：3

解释：


示例 2：

输入：num = 4, Xpos = 1, Ypos = 2

输出：5

解释：


提示：

1 <= num <= 10^9
0 <= Xpos, Ypos < num

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/SNJvJP
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
        long long circle = min({ xPos, num - 1 - xPos, yPos, num - 1 - yPos });
        long long seq = 4 * (num - circle) * circle;
        long long side = num - 2 * circle - 1, xVertex = circle, yVertex = circle;

        if (xPos == xVertex && yPos < yVertex + side) {
            seq += ((long long)yPos + 1 - yVertex);
        }
        else {
            seq += side;
            if (yPos == yVertex + side && xPos < xVertex + side) {
                seq += ((long long)xPos + 1 - xVertex);
            }
            else {
                seq += side;
                if (xPos == xVertex + side && yPos > yVertex) {
                    seq += (yVertex + side + 1 - yPos);
                }
                else {
                    seq += (side + xVertex + side + 1 - xPos);
                }
            }
        }

        seq %= 9;
        return (int)(seq == 0 ? 9 : seq);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.orchestraLayout(3, 0, 2));
    check.checkInt(1, o.orchestraLayout(1, 0, 0));
    check.checkInt(5, o.orchestraLayout(4, 1, 2));
    check.checkInt(7, o.orchestraLayout(5, 2, 2));
    check.checkInt(3, o.orchestraLayout(2511, 1504, 2235));
    check.checkInt(3, o.orchestraLayout(971131546, 966980466, 531910024));
    check.checkInt(1, o.orchestraLayout(1000000000, 555555555, 666666666));
    check.checkInt(5, o.orchestraLayout(999999999, 500000000, 500000000));
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
