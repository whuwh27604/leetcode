/* 换酒问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小区便利店正在促销，用 numExchange 个空酒瓶可以兑换一瓶新酒。你购入了 numBottles 瓶酒。

如果喝掉了酒瓶中的酒，那么酒瓶就会变成空的。

请你计算 最多 能喝到多少瓶酒。

 

示例 1：



输入：numBottles = 9, numExchange = 3
输出：13
解释：你可以用 3 个空酒瓶兑换 1 瓶酒。
所以最多能喝到 9 + 3 + 1 = 13 瓶酒。
示例 2：



输入：numBottles = 15, numExchange = 4
输出：19
解释：你可以用 4 个空酒瓶兑换 1 瓶酒。
所以最多能喝到 15 + 3 + 1 = 19 瓶酒。
示例 3：

输入：numBottles = 5, numExchange = 5
输出：6
示例 4：

输入：numBottles = 2, numExchange = 3
输出：2
 

提示：

1 <= numBottles <= 100
2 <= numExchange <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/water-bottles
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int quotient, remainder, totalBottles = numBottles;

        while (numBottles >= numExchange) {
            quotient = numBottles / numExchange;
            remainder = numBottles % numExchange;
            totalBottles += quotient;
            numBottles = quotient + remainder;
        }

        return totalBottles;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(13, o.numWaterBottles(9, 3));
    check.checkInt(19, o.numWaterBottles(15, 4));
    check.checkInt(6, o.numWaterBottles(5, 5));
    check.checkInt(2, o.numWaterBottles(2, 3));
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
