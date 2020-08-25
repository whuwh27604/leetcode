﻿/* 灯泡开关 Ⅱ.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
现有一个房间，墙上挂有 n 只已经打开的灯泡和 4 个按钮。在进行了 m 次未知操作后，你需要返回这 n 只灯泡可能有多少种不同的状态。

假设这 n 只灯泡被编号为 [1, 2, 3 ..., n]，这 4 个按钮的功能如下：

将所有灯泡的状态反转（即开变为关，关变为开）
将编号为偶数的灯泡的状态反转
将编号为奇数的灯泡的状态反转
将编号为 3k+1 的灯泡的状态反转（k = 0, 1, 2, ...)
示例 1:

输入: n = 1, m = 1.
输出: 2
说明: 状态为: [开], [关]
示例 2:

输入: n = 2, m = 1.
输出: 3
说明: 状态为: [开, 关], [关, 开], [关, 关]
示例 3:

输入: n = 3, m = 1.
输出: 4
说明: 状态为: [关, 开, 关], [开, 关, 开], [关, 关, 关], [关, 开, 开].
注意： n 和 m 都属于 [0, 1000].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bulb-switcher-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int flipLights(int n, int m) {
        /* 分析操作可知，每6盏灯的状态是完全一样的，更进一步，前三盏灯和后三盏灯状态虽然不一样，但是关系是确定的。
           所以实际上最多只可能有2^3=8种状态。然后手动推演一下就知道各种情况下的状态数量 */
        n = min(n, 3);
        m = min(m, 3);

        int states[4][4] = { {1,1,1,1},{1,2,2,2},{1,3,4,4},{1,4,7,8} };
        return states[n][m];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(2, o.flipLights(1, 1));
    check.checkInt(3, o.flipLights(2, 1));
    check.checkInt(4, o.flipLights(3, 1));
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
