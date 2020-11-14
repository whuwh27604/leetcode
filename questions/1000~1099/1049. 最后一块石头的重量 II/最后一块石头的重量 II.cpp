/* 最后一块石头的重量 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一堆石头，每块石头的重量都是正整数。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头最小的可能重量。如果没有石头剩下，就返回 0。

 

示例：

输入：[2,7,4,1,8,1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
 

提示：

1 <= stones.length <= 30
1 <= stones[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/last-stone-weight-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalWeight = getTotalWeight(stones);
        int capacity = totalWeight / 2;
        int i, j, size = stones.size();
        vector<vector<int>> dp(size, vector<int>(capacity + 1, 0));  // dp[i][j]表示当容量为j时，前i个石头能够取得的最大重量

        for (j = 1; j <= capacity; ++j) {
            dp[0][j] = (j >= stones[0] ? stones[0] : 0);
        }

        for (i = 1; i < size; ++i) {  // 面对第i个石头，可以选择取它，则容量变小；或者不取它，容量不变
            for (j = 1; j <= capacity; ++j) {
                dp[i][j] = ((j >= stones[i]) ? max(stones[i] + dp[i - 1][j - stones[i]], dp[i - 1][j]) : dp[i - 1][j]);
            }
        }

        return totalWeight - dp[size - 1][capacity] * 2;
    }

    int getTotalWeight(vector<int>& stones) {
        int weight = 0;

        for (int stone : stones) {
            weight += stone;
        }

        return weight;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> stones = { 2,7,4,1,8,1 };
    check.checkInt(1, o.lastStoneWeightII(stones));

    stones = { 321,900,972,910,478,730,814,543,887,824,831 };
    check.checkInt(8, o.lastStoneWeightII(stones));

    stones = { 1,2,4,8,16,32,64,12,25,51 };
    check.checkInt(1, o.lastStoneWeightII(stones));
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
