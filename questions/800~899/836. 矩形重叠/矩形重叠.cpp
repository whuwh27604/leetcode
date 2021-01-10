/* 矩形重叠.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标。

如果相交的面积为正，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。

给出两个矩形，判断它们是否重叠并返回结果。

 

示例 1：

输入：rec1 = [0,0,2,2], rec2 = [1,1,3,3]
输出：true
示例 2：

输入：rec1 = [0,0,1,1], rec2 = [1,0,2,1]
输出：false
 

提示：

两个矩形 rec1 和 rec2 都以含有四个整数的列表的形式给出。
矩形中的所有坐标都处于 -10^9 和 10^9 之间。
x 轴默认指向右，y 轴默认指向上。
你可以仅考虑矩形是正放的情况。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rectangle-overlap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int p1x1 = rec1[0], p1y1 = rec1[1], p1x2 = rec1[2], p1y2 = rec1[3];
        int p2x1 = rec2[0], p2y1 = rec2[1], p2x2 = rec2[2], p2y2 = rec2[3];

        return !((p2x1 >= p1x2) || (p2x2 <= p1x1) || (p2y1 >= p1y2) || (p2y2 <= p1y1));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> rec1 = { 0,0,2,2 };
    vector<int> rec2 = { 1,1,3,3 };
    check.checkBool(true, o.isRectangleOverlap(rec1, rec2));

    rec1 = { 0,0,1,1 };
    rec2 = { 1,0,2,1 };
    check.checkBool(false, o.isRectangleOverlap(rec1, rec2));
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
