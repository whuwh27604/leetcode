/* 镜面反射.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个特殊的正方形房间，每面墙上都有一面镜子。除西南角以外，每个角落都放有一个接受器，编号为 0， 1，以及 2。

正方形房间的墙壁长度为 p，一束激光从西南角射出，首先会与东墙相遇，入射点到接收器 0 的距离为 q 。

返回光线最先遇到的接收器的编号（保证光线最终会遇到一个接收器）。

 

示例：

输入： p = 2, q = 1
输出： 2
解释： 这条光线在第一次被反射回左边的墙时就遇到了接收器 2 。

 

提示：

1 <= p <= 1000
0 <= q <= p

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/mirror-reflection
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        if (q == 0) {
            return 0;
        }

        /* 1秒在东西方向走p，在南北方向走q，要想到达角上，就必须在某个时刻同时是p、q的倍数，所以就是求p、q的最小公倍数lcm
           然后lcm/q是经过的时间，奇数秒在东，偶数秒在西；lcm/p是南北方向往返的次数，奇数次在北，偶数次在南*/
        int lcm = p * q / gcd(p, q), ewest = lcm / q, snorth = lcm / p;

        return (ewest % 2 == 0) ? 2 : ((snorth % 2 == 0) ? 0 : 1);
    }

    int gcd(int x, int y) {
        return (y == 0) ? x : gcd(y, x % y);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(2, o.mirrorReflection(2, 1));
    check.checkInt(1, o.mirrorReflection(2, 2));
    check.checkInt(0, o.mirrorReflection(2, 0));
    check.checkInt(2, o.mirrorReflection(4, 1));
    check.checkInt(1, o.mirrorReflection(3, 1));
    check.checkInt(0, o.mirrorReflection(6, 4));
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
