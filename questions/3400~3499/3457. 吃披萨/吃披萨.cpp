/* 吃披萨.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 pizzas，其中 pizzas[i] 表示第 i 个披萨的重量。每天你会吃 恰好 4 个披萨。由于你的新陈代谢能力惊人，当你吃重量为 W、X、Y 和 Z 的披萨（其中 W <= X <= Y <= Z）时，你只会增加 1 个披萨的重量！体重增加规则如下：

在 奇数天（按 1 开始计数）你会增加 Z 的重量。
在 偶数天，你会增加 Y 的重量。
请你设计吃掉 所有 披萨的最优方案，并计算你可以增加的 最大 总重量。

注意：保证 n 是 4 的倍数，并且每个披萨只吃一次。



示例 1：

输入： pizzas = [1,2,3,4,5,6,7,8]

输出： 14

解释：

第 1 天，你吃掉下标为 [1, 2, 4, 7] = [2, 3, 5, 8] 的披萨。你增加的重量为 8。
第 2 天，你吃掉下标为 [0, 3, 5, 6] = [1, 4, 6, 7] 的披萨。你增加的重量为 6。
吃掉所有披萨后，你增加的总重量为 8 + 6 = 14。

示例 2：

输入： pizzas = [2,1,1,1,1,1,1,1]

输出： 3

解释：

第 1 天，你吃掉下标为 [4, 5, 6, 0] = [1, 1, 1, 2] 的披萨。你增加的重量为 2。
第 2 天，你吃掉下标为 [1, 2, 3, 7] = [1, 1, 1, 1] 的披萨。你增加的重量为 1。
吃掉所有披萨后，你增加的总重量为 2 + 1 = 3。



提示：

4 <= n == pizzas.length <= 2 * 105
1 <= pizzas[i] <= 105
n 是 4 的倍数。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        long long weight = 0;
        int n = (int)pizzas.size(), odd = (n / 4 + 1) / 2, even = n / 4 / 2, idx = n - 1;

        sort(pizzas.begin(), pizzas.end());

        for (int i = 0; i < odd; ++i) {  // 最大的odd个在奇数轮的时候选
            weight += pizzas[idx--];
        }

        --idx;
        for (int i = 0; i < even; ++i) {  // 然后偶数轮每次选次大的
            weight += pizzas[idx];
            idx -= 2;
        }

        return weight;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> pizzas = { 1,2,3,4,5,6,7,8 };
    check.checkLongLong(14, o.maxWeight(pizzas));

    pizzas = { 2,1,1,1,1,1,1,1 };
    check.checkLongLong(3, o.maxWeight(pizzas));

    pizzas = { 3,4,2,4,2,4,2,2,4,5,3,2,1,2,1,1 };
    check.checkLongLong(16, o.maxWeight(pizzas));
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
