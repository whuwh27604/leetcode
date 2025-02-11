/* K 次修改后的最大曼哈顿距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由字符 'N'、'S'、'E' 和 'W' 组成的字符串 s，其中 s[i] 表示在无限网格中的移动操作：

'N'：向北移动 1 个单位。
'S'：向南移动 1 个单位。
'E'：向东移动 1 个单位。
'W'：向西移动 1 个单位。
初始时，你位于原点 (0, 0)。你 最多 可以修改 k 个字符为任意四个方向之一。

请找出在 按顺序 执行所有移动操作过程中的 任意时刻 ，所能达到的离原点的 最大曼哈顿距离 。

曼哈顿距离 定义为两个坐标点 (xi, yi) 和 (xj, yj) 的横向距离绝对值与纵向距离绝对值之和，即 |xi - xj| + |yi - yj|。



示例 1：

输入：s = "NWSE", k = 1

输出：3

解释：

将 s[2] 从 'S' 改为 'N' ，字符串 s 变为 "NWNE" 。

移动操作	位置 (x, y)	曼哈顿距离	最大值
s[0] == 'N'	(0, 1)	0 + 1 = 1	1
s[1] == 'W'	(-1, 1)	1 + 1 = 2	2
s[2] == 'N'	(-1, 2)	1 + 2 = 3	3
s[3] == 'E'	(0, 2)	0 + 2 = 2	3
执行移动操作过程中，距离原点的最大曼哈顿距离是 3 。

示例 2：

输入：s = "NSWWEW", k = 3

输出：6

解释：

将 s[1] 从 'S' 改为 'N' ，将 s[4] 从 'E' 改为 'W' 。字符串 s 变为 "NNWWWW" 。

执行移动操作过程中，距离原点的最大曼哈顿距离是 6 。



提示：

1 <= s.length <= 105
0 <= k <= s.length
s 仅由 'N'、'S'、'E' 和 'W' 。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int maxDist = 0, step = 0, x = 0, y = 0;
        k *= 2;  // 每操作一次，距离增大2

        for (char c : s) {
            if (c == 'N') {
                ++y;
            }
            else if (c == 'S') {
                --y;
            }
            else if (c == 'E') {
                ++x;
            }
            else {
                --x;
            }

            int dist = min(abs(x) + abs(y) + k, ++step);  // step移动能走出的最大dist就是step
            maxDist = max(maxDist, dist);
        }

        return maxDist;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(3, o.maxDistance("NWSE", 1));
    check.checkInt(6, o.maxDistance("NSWWEW", 3));
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
