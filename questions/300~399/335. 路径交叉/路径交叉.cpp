/* 路径交叉.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个含有 n 个正数的数组 x。从点 (0,0) 开始，先向北移动 x[0] 米，然后向西移动 x[1] 米，向南移动 x[2] 米，向东移动 x[3] 米，持续移动。也就是说，每次移动后你的方位会发生逆时针变化。

编写一个 O(1) 空间复杂度的一趟扫描算法，判断你所经过的路径是否相交。

 

示例 1:

┌───┐
│   │
└───┼──>
    │

输入: [2,1,1,2]
输出: true
示例 2:

┌──────┐
│      │
│
│
└────────────>

输入: [1,2,3,4]
输出: false
示例 3:

┌───┐
│   │
└───┼>

输入: [1,1,1,1]
输出: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/self-crossing
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        // 第一条线段只可能和第4、5、6中的一条相交，所以只需要保存前面6条线段即可
        vector<vector<int>> segments(6);
        int index = 0, x0 = 0, y0 = 0, direction = 0;
        int dx[4] = { 0,-1,0,1 }, dy[4] = { 1,0,-1,0 };

        for (int distance : x) {
            int x1 = x0 + distance * dx[direction], y1 = y0 + distance * dy[direction];
            segments[index % 6] = { min(x0, x1), min(y0, y1), max(x0, x1), max(y0, y1) };

            int index0 = index > 5 ? index - 5 : 0;
            if (isCrossing(segments[index0 % 6], segments[(index0 + 3) % 6])
                || isCrossing(segments[index0 % 6], segments[(index0 + 4) % 6])
                || isCrossing(segments[index0 % 6], segments[(index0 + 5) % 6])) {
                return true;
            }

            direction = (direction + 1) % 4;
            index += 1;
            x0 = x1;
            y0 = y1;
        }

        return false;
    }

    bool isCrossing(vector<int>& segment1, vector<int>& segment2) {
        if (segment1.empty() || segment2.empty()) {
            return false;
        }

        int x0 = segment1[0], y0 = segment1[1], x1 = segment1[2], y1 = segment1[3];
        int x2 = segment2[0], y2 = segment2[1], x3 = segment2[2], y3 = segment2[3];

        if (x0 == x1 && x0 == x2 && x0 == x3 && y3 >= y0 && y2 <= y1) {  // y方向在一条直线上
            return true;
        }

        if (y0 == y1 && y0 == y2 && y0 == y3 && x3 >= x0 && x2 <= x1) {  // x方向在一条直线上
            return true;
        }

        if (x0 == x1 && y0 <= y2 && y2 <= y1 && x2 <= x0 && x0 <= x3) {  // 十字方向
            return true;
        }

        if (y0 == y1 && x0 <= x2 && x2 <= x1 && y2 <= y0 && y0 <= y3) {  // 十字方向
            return true;
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> x = { 2,1,1,2 };
    check.checkBool(true, o.isSelfCrossing(x));
    
    x = { 1,2,3,4 };
    check.checkBool(false, o.isSelfCrossing(x));

    x = { 1,1,1,1 };
    check.checkBool(true, o.isSelfCrossing(x));
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
