/* 判断一个点是否可以到达.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个无穷大的网格图。一开始你在 (1, 1) ，你需要通过有限步移动到达点 (targetX, targetY) 。

每一步 ，你可以从点 (x, y) 移动到以下点之一：

(x, y - x)
(x - y, y)
(2 * x, y)
(x, 2 * y)
给你两个整数 targetX 和 targetY ，分别表示你最后需要到达点的 X 和 Y 坐标。如果你可以从 (1, 1) 出发到达这个点，请你返回true ，否则返回 false 。



示例 1：

输入：targetX = 6, targetY = 9
输出：false
解释：没法从 (1,1) 出发到达 (6,9) ，所以返回 false 。
示例 2：

输入：targetX = 4, targetY = 7
输出：true
解释：你可以按照以下路径到达：(1,1) -> (1,2) -> (1,4) -> (1,8) -> (1,7) -> (2,7) -> (4,7) 。


提示：

1 <= targetX, targetY <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int common = gcd(targetX, targetY);

        return (common & (common - 1)) == 0;  // gcd是2的幂则可达，否则不可达
    }

    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.isReachable(4, 7));
    check.checkBool(false, o.isReachable(6, 9));
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
