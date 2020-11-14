/* 爱生气的书店老板.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
今天，书店老板有一家店打算试营业 customers.length 分钟。每分钟都有一些顾客（customers[i]）会进入书店，所有这些顾客都会在那一分钟结束后离开。

在某些时候，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。 当书店老板生气时，那一分钟的顾客就会不满意，不生气则他们是满意的。

书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续 X 分钟不生气，但却只能使用一次。

请你返回这一天营业下来，最多有多少客户能够感到满意的数量。
 

示例：

输入：customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
输出：16
解释：
书店老板在最后 3 分钟保持冷静。
感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.
 

提示：

1 <= X <= customers.length == grumpy.length <= 20000
0 <= customers[i] <= 1000
0 <= grumpy[i] <= 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/grumpy-bookstore-owner
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int i, size = customers.size();
        int dissatisfied = 0, satisfied = 0;

        for (i = 0; i < X; ++i) {
            if (grumpy[i] == 1) {
                dissatisfied += customers[i];
            }
            else {
                satisfied += customers[i];
            }
        }

        int maxDissatisfied = dissatisfied;

        for (; i < size; ++i) {
            if (grumpy[i - X] == 1) {
                dissatisfied -= customers[i - X];
            }

            if (grumpy[i] == 1) {
                dissatisfied += customers[i];
            }
            else {
                satisfied += customers[i];
            }

            maxDissatisfied = max(maxDissatisfied, dissatisfied);
        }

        return satisfied + maxDissatisfied;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> customers = { 1,0,1,2,1,1,7,5 };
    vector<int> grumpy = { 0,1,0,1,0,1,0,1 };
    check.checkInt(16, o.maxSatisfied(customers, grumpy, 3));

    customers = { 2,6,6,9 };
    grumpy = { 0,0,1,1 };
    check.checkInt(17, o.maxSatisfied(customers, grumpy, 1));

    customers = { 1,2,3,4 };
    grumpy = { 1,1,1,1 };
    check.checkInt(10, o.maxSatisfied(customers, grumpy, 4));

    customers = { 1,2,3,4 };
    grumpy = { 1,1,1,1 };
    check.checkInt(10, o.maxSatisfied(customers, grumpy, 4));

    customers = { 1,2,3,4 };
    grumpy = { 0,0,0,0 };
    check.checkInt(10, o.maxSatisfied(customers, grumpy, 1));

    customers = { 1,2,3,4 };
    grumpy = { 0,0,0,1 };
    check.checkInt(10, o.maxSatisfied(customers, grumpy, 1));
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
