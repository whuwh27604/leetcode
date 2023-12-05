/* 需要添加的硬币的最小数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 coins，表示可用的硬币的面值，以及一个整数 target 。

如果存在某个 coins 的子序列总和为 x，那么整数 x 就是一个 可取得的金额 。

返回需要添加到数组中的 任意面值 硬币的 最小数量 ，使范围 [1, target] 内的每个整数都属于 可取得的金额 。

数组的 子序列 是通过删除原始数组的一些（可能不删除）元素而形成的新的 非空 数组，删除过程不会改变剩余元素的相对位置。



示例 1：

输入：coins = [1,4,10], target = 19
输出：2
解释：需要添加面值为 2 和 8 的硬币各一枚，得到硬币数组 [1,2,4,8,10] 。
可以证明从 1 到 19 的所有整数都可由数组中的硬币组合得到，且需要添加到数组中的硬币数目最小为 2 。
示例 2：

输入：coins = [1,4,10,5,7,19], target = 19
输出：1
解释：只需要添加一枚面值为 2 的硬币，得到硬币数组 [1,2,4,5,7,10,19] 。
可以证明从 1 到 19 的所有整数都可由数组中的硬币组合得到，且需要添加到数组中的硬币数目最小为 1 。
示例 3：

输入：coins = [1,1,1], target = 20
输出：3
解释：
需要添加面值为 4 、8 和 16 的硬币各一枚，得到硬币数组 [1,1,1,4,8,16] 。
可以证明从 1 到 20 的所有整数都可由数组中的硬币组合得到，且需要添加到数组中的硬币数目最小为 3 。


提示：

1 <= target <= 105
1 <= coins.length <= 105
1 <= coins[i] <= target
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int size = coins.size(), i = 0, wanted = 1, added = 0;

        sort(coins.begin(), coins.end());

        while (wanted <= target) {
            if (i < size && coins[i] <= wanted) {
                wanted += coins[i];  // [0, wanted)范围都是可得的，现在出现了coins[i]，并且coins[i] <= wanted，那么[0, wanted + coins[i])范围都可得
                ++i;
            }
            else {
                wanted *= 2;  // wanted不存在，必须添加这个硬币，添加后[0, 2 * wanted)都可得
                ++added;
            }
        }

        return added;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> coins = { 1,4,10 };
    check.checkInt(2, o.minimumAddedCoins(coins, 19));

    coins = { 1,4,10,5,7,19 };
    check.checkInt(1, o.minimumAddedCoins(coins, 19));

    coins = { 1,1,1 };
    check.checkInt(3, o.minimumAddedCoins(coins, 20));
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
