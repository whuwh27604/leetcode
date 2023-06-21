/* 总行驶距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
卡车有两个油箱。给你两个整数，mainTank 表示主油箱中的燃料（以升为单位），additionalTank 表示副油箱中的燃料（以升为单位）。

该卡车每耗费 1 升燃料都可以行驶 10 km。每当主油箱使用了 5 升燃料时，如果副油箱至少有 1 升燃料，则会将 1 升燃料从副油箱转移到主油箱。

返回卡车可以行驶的最大距离。

注意：从副油箱向主油箱注入燃料不是连续行为。这一事件会在每消耗 5 升燃料时突然且立即发生。



示例 1：

输入：mainTank = 5, additionalTank = 10
输出：60
解释：
在用掉 5 升燃料后，主油箱中燃料还剩下 (5 - 5 + 1) = 1 升，行驶距离为 50km 。
在用掉剩下的 1 升燃料后，没有新的燃料注入到主油箱中，主油箱变为空。
总行驶距离为 60km 。
示例 2：

输入：mainTank = 1, additionalTank = 2
输出：10
解释：
在用掉 1 升燃料后，主油箱变为空。
总行驶距离为 10km 。


提示：

1 <= mainTank, additionalTank <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int tank = 0;

        while (mainTank >= 5) {
            tank += 5;
            mainTank -= 5;

            if (additionalTank != 0) {
                additionalTank -= 1;
                mainTank += 1;
            }
        }

        return (tank + mainTank) * 10;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(60, o.distanceTraveled(5, 10));
    check.checkInt(10, o.distanceTraveled(1, 2));
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
