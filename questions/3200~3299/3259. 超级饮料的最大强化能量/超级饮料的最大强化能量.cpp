/* 超级饮料的最大强化能量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
来自未来的体育科学家给你两个整数数组 energyDrinkA 和 energyDrinkB，数组长度都等于 n。这两个数组分别代表 A、B 两种不同能量饮料每小时所能提供的强化能量。

你需要每小时饮用一种能量饮料来 最大化 你的总强化能量。然而，如果从一种能量饮料切换到另一种，你需要等待一小时来梳理身体的能量体系（在那个小时里你将不会获得任何强化能量）。

返回在接下来的 n 小时内你能获得的 最大 总强化能量。

注意 你可以选择从饮用任意一种能量饮料开始。



示例 1：

输入：energyDrinkA = [1,3,1], energyDrinkB = [3,1,1]

输出：5

解释：

要想获得 5 点强化能量，需要选择只饮用能量饮料 A（或者只饮用 B）。

示例 2：

输入：energyDrinkA = [4,1,1], energyDrinkB = [1,1,3]

输出：7

解释：

第一个小时饮用能量饮料 A。
切换到能量饮料 B ，在第二个小时无法获得强化能量。
第三个小时饮用能量饮料 B ，并获得强化能量。


提示：

n == energyDrinkA.length == energyDrinkB.length
3 <= n <= 105
1 <= energyDrinkA[i], energyDrinkB[i] <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = (int)energyDrinkA.size();
        long long A = energyDrinkA[0], B = energyDrinkB[0], Z = 0;

        for (int i = 1; i < n; ++i) {
            long long a = max(A, Z) + energyDrinkA[i];
            long long b = max(B, Z) + energyDrinkB[i];
            long long z = max(A, B);
            A = a, B = b, Z = z;
        }

        return max(A, B);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> energyDrinkA = { 1,3,1 };
    vector<int> energyDrinkB = { 3,1,1 };
    check.checkLongLong(5, o.maxEnergyBoost(energyDrinkA, energyDrinkB));

    energyDrinkA = { 4,1,1 };
    energyDrinkB = { 1,1,3 };
    check.checkLongLong(7, o.maxEnergyBoost(energyDrinkA, energyDrinkB));
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
