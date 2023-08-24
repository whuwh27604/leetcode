/* 鸡蛋掉落.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你 k 枚相同的鸡蛋，并可以使用一栋从第 1 层到第 n 层共有 n 层楼的建筑。

已知存在楼层 f ，满足 0 <= f <= n ，任何从 高于 f 的楼层落下的鸡蛋都会碎，从 f 楼层或比它低的楼层落下的鸡蛋都不会破。

每次操作，你可以取一枚没有碎的鸡蛋并把它从任一楼层 x 扔下（满足 1 <= x <= n）。如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中 重复使用 这枚鸡蛋。

请你计算并返回要确定 f 确切的值 的 最小操作次数 是多少？


示例 1：

输入：k = 1, n = 2
输出：2
解释：
鸡蛋从 1 楼掉落。如果它碎了，肯定能得出 f = 0 。
否则，鸡蛋从 2 楼掉落。如果它碎了，肯定能得出 f = 1 。
如果它没碎，那么肯定能得出 f = 2 。
因此，在最坏的情况下我们需要移动 2 次以确定 f 是多少。
示例 2：

输入：k = 2, n = 6
输出：3
示例 3：

输入：k = 3, n = 14
输出：4


提示：

1 <= k <= 100
1 <= n <= 104
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        /* dp[t][k]表示t次操作，k个鸡蛋，最多可以探测的楼层数
           如果扔出一个鸡蛋没有碎，那么还可以往上探测dp[t - 1][k]层
           如果扔出一个鸡蛋碎了，那么可以探测下面的dp[t - 1][k - 1]层
           所以dp[t][k] = 1 + dp[t - 1][k - 1] + dp[t - 1][k] */
        int ans = 1;
        vector<int> dp(k + 1, 0);

        for (int i = 1; i <= k; ++i) {
            dp[i] = 1;  // 1次操作时，不管有多少个蛋，只能探测1层
        }

        for (int t = 2; t <= n; ++t) {  // 增大操作次数
            for (int i = k; i > 0; --i) {  // 滚动数组计算dp
                dp[i] += (1 + dp[i - 1]);
            }

            if (dp[k] >= n) {  // t次操作能够探测的楼层数已经大于n，返回结果
                ans = t;
                break;
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.superEggDrop(1, 1));
    check.checkInt(1, o.superEggDrop(10, 1));
    check.checkInt(2, o.superEggDrop(1, 2));
    check.checkInt(3, o.superEggDrop(2, 6));
    check.checkInt(3, o.superEggDrop(1, 3));
    check.checkInt(3, o.superEggDrop(2, 4));
    check.checkInt(4, o.superEggDrop(3, 14));
    check.checkInt(4, o.superEggDrop(2, 7));
    check.checkInt(5, o.superEggDrop(2, 14));
    check.checkInt(5, o.superEggDrop(3, 15));
    check.checkInt(5, o.superEggDrop(3, 25));
    check.checkInt(14, o.superEggDrop(100, 10000));
    check.checkInt(16, o.superEggDrop(2, 128));
    check.checkInt(141, o.superEggDrop(2, 10000));
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
