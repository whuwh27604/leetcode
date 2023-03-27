/* K 件物品的最大和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
袋子中装有一些物品，每个物品上都标记着数字 1 、0 或 -1 。

给你四个非负整数 numOnes 、numZeros 、numNegOnes 和 k 。

袋子最初包含：

numOnes 件标记为 1 的物品。
numZeroes 件标记为 0 的物品。
numNegOnes 件标记为 -1 的物品。
现计划从这些物品中恰好选出 k 件物品。返回所有可行方案中，物品上所标记数字之和的最大值。



示例 1：

输入：numOnes = 3, numZeros = 2, numNegOnes = 0, k = 2
输出：2
解释：袋子中的物品分别标记为 {1, 1, 1, 0, 0} 。取 2 件标记为 1 的物品，得到的数字之和为 2 。
可以证明 2 是所有可行方案中的最大值。
示例 2：

输入：numOnes = 3, numZeros = 2, numNegOnes = 0, k = 4
输出：3
解释：袋子中的物品分别标记为 {1, 1, 1, 0, 0} 。取 3 件标记为 1 的物品，1 件标记为 0 的物品，得到的数字之和为 3 。
可以证明 3 是所有可行方案中的最大值。


提示：

0 <= numOnes, numZeros, numNegOnes <= 50
0 <= k <= numOnes + numZeros + numNegOnes
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (numOnes >= k) {
            return k;
        }

        if (numOnes + numZeros >= k) {
            return numOnes;
        }

        return numOnes - (k - numOnes - numZeros);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.kItemsWithMaximumSum(3, 2, 0, 2));
    check.checkInt(3, o.kItemsWithMaximumSum(3, 2, 0, 4));
    check.checkInt(2, o.kItemsWithMaximumSum(3, 2, 3, 6));
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
