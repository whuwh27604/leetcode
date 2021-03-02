/* 最接近目标价格的甜点成本.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你打算做甜点，现在需要购买配料。目前共有 n 种冰激凌基料和 m 种配料可供选购。而制作甜点需要遵循以下几条规则：

必须选择 一种 冰激凌基料。
可以添加 一种或多种 配料，也可以不添加任何配料。
每种类型的配料 最多两份 。
给你以下三个输入：

baseCosts ，一个长度为 n 的整数数组，其中每个 baseCosts[i] 表示第 i 种冰激凌基料的价格。
toppingCosts，一个长度为 m 的整数数组，其中每个 toppingCosts[i] 表示 一份 第 i 种冰激凌配料的价格。
target ，一个整数，表示你制作甜点的目标价格。
你希望自己做的甜点总成本尽可能接近目标价格 target 。

返回最接近 target 的甜点成本。如果有多种方案，返回 成本相对较低 的一种。

 

示例 1：

输入：baseCosts = [1,7], toppingCosts = [3,4], target = 10
输出：10
解释：考虑下面的方案组合（所有下标均从 0 开始）：
- 选择 1 号基料：成本 7
- 选择 1 份 0 号配料：成本 1 x 3 = 3
- 选择 0 份 1 号配料：成本 0 x 4 = 0
总成本：7 + 3 + 0 = 10 。
示例 2：

输入：baseCosts = [2,3], toppingCosts = [4,5,100], target = 18
输出：17
解释：考虑下面的方案组合（所有下标均从 0 开始）：
- 选择 1 号基料：成本 3
- 选择 1 份 0 号配料：成本 1 x 4 = 4
- 选择 2 份 1 号配料：成本 2 x 5 = 10
- 选择 0 份 2 号配料：成本 0 x 100 = 0
总成本：3 + 4 + 10 + 0 = 17 。不存在总成本为 18 的甜点制作方案。
示例 3：

输入：baseCosts = [3,10], toppingCosts = [2,5], target = 9
输出：8
解释：可以制作总成本为 8 和 10 的甜点。返回 8 ，因为这是成本更低的方案。
示例 4：

输入：baseCosts = [10], toppingCosts = [1], target = 1
输出：10
解释：注意，你可以选择不添加任何配料，但你必须选择一种基料。
 

提示：

n == baseCosts.length
m == toppingCosts.length
1 <= n, m <= 10
1 <= baseCosts[i], toppingCosts[i] <= 104
1 <= target <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/closest-dessert-cost
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int i, j, n = baseCosts.size(), m = toppingCosts.size(), diff, closestDiff = INT_MAX, closest = 0;
        int x = (int)pow(2, m * 2);
        vector<int> topping = toppingCosts;
        topping.insert(topping.end(), toppingCosts.begin(), toppingCosts.end());

        for (i = 0; i < n; ++i) {
            for (j = 0; j < x; ++j) {
                int cost = baseCosts[i];
                int k = j, index = 0;

                while (k != 0) {
                    if ((k & 1) == 1) {
                        cost += topping[index];
                    }
                    k >>= 1;
                    ++index;
                }

                diff = abs(cost - target);
                if (diff < closestDiff) {
                    closestDiff = diff;
                    closest = cost;
                }
                else if (diff == closestDiff) {
                    closest = min(closest, cost);
                }
            }
        }

        return closest;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> baseCosts = { 1,7 };
    vector<int> toppingCosts = { 3,4 };
    check.checkInt(10, o.closestCost(baseCosts, toppingCosts, 10));

    baseCosts = { 2,3 };
    toppingCosts = { 4,5,100 };
    check.checkInt(17, o.closestCost(baseCosts, toppingCosts, 18));

    baseCosts = { 3,10 };
    toppingCosts = { 2,5 };
    check.checkInt(8, o.closestCost(baseCosts, toppingCosts, 9));

    baseCosts = { 10 };
    toppingCosts = { 1 };
    check.checkInt(10, o.closestCost(baseCosts, toppingCosts, 1));

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
