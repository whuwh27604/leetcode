/* 灯泡开关.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
初始时有 n 个灯泡关闭。 第 1 轮，你打开所有的灯泡。 第 2 轮，每两个灯泡你关闭一次。 第 3 轮，每三个灯泡切换一次开关（如果关闭则开启，如果开启则关闭）。第 i 轮，每 i 个灯泡切换一次开关。 对于第 n 轮，你只切换最后一个灯泡的开关。 找出 n 轮后有多少个亮着的灯泡。

示例:

输入: 3
输出: 1
解释:
初始时, 灯泡状态 [关闭, 关闭, 关闭].
第一轮后, 灯泡状态 [开启, 开启, 开启].
第二轮后, 灯泡状态 [开启, 关闭, 开启].
第三轮后, 灯泡状态 [开启, 关闭, 关闭].

你应该返回 1，因为只有一个灯泡还亮着。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bulb-switcher
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <math.h>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        // 一个数只在它的因子轮被操作，而因子总是成对出现，操作两次等于不操作。所以只有完全平方数最后会亮着。
        return (int)sqrt(n);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.bulbSwitch(0));
    check.checkInt(1, o.bulbSwitch(1));
    check.checkInt(1, o.bulbSwitch(2));
    check.checkInt(1, o.bulbSwitch(3));
    check.checkInt(2, o.bulbSwitch(4));
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
