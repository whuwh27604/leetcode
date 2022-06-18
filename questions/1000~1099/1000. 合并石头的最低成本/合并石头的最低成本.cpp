/*/ 合并石头的最低成本.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 N 堆石头排成一排，第 i 堆中有 stones[i] 块石头。

每次移动（move）需要将连续的 K 堆石头合并为一堆，而这个移动的成本为这 K 堆石头的总数。

找出把所有石头合并成一堆的最低成本。如果不可能，返回 -1 。

 

示例 1：

输入：stones = [3,2,4,1], K = 2
输出：20
解释：
从 [3, 2, 4, 1] 开始。
合并 [3, 2]，成本为 5，剩下 [5, 4, 1]。
合并 [4, 1]，成本为 5，剩下 [5, 5]。
合并 [5, 5]，成本为 10，剩下 [10]。
总成本 20，这是可能的最小值。
示例 2：

输入：stones = [3,2,4,1], K = 3
输出：-1
解释：任何合并操作后，都会剩下 2 堆，我们无法再进行合并。所以这项任务是不可能完成的。.
示例 3：

输入：stones = [3,5,1,2,6], K = 3
输出：25
解释：
从 [3, 5, 1, 2, 6] 开始。
合并 [5, 1, 2]，成本为 8，剩下 [3, 8, 6]。
合并 [3, 8, 6]，成本为 17，剩下 [17]。
总成本 25，这是可能的最小值。
 

提示：

1 <= stones.length <= 30
2 <= K <= 30
1 <= stones[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-cost-to-merge-stones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <numeric>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int size = stones.size(), step = k - 1, inf = 1000000000;

        if ((size - 1) % step != 0) {
            return -1;
        }

        vector<int> presums(size + 1, 0);
        vector<vector<vector<int>>> minCost(size, vector<vector<int>>(size, vector<int>(size + 1, inf)));

        for (int i = 0; i < size; ++i) {
            presums[i + 1] = presums[i] + stones[i];
        }

        for (int len = 1; len <= size; ++len) {  // 枚举区间长度
            for (int start = 0; start <= size - len; ++start) {  // 枚举区间起点
                int end = start + len - 1;
                minCost[start][end][len] = 0;  // n个石头分为n堆的cost为0

                for (int piles = len - 1; piles > 1; --piles) {  // 枚举划分的堆数，从len - 1到2
                    for (int split = start; end - split >= piles - 1; split += step) {  // 枚举第一堆的个数，只能是1 + x * step个
                        // 将[start, end]划分为[start, split]一堆，(split, end]区间(piles - 1)堆，一共piles堆
                        minCost[start][end][piles] = min(minCost[start][end][piles], minCost[start][split][1] + minCost[split + 1][end][piles - 1]);
                    }
                }

                if (len != 1) {
                    // 先将[start, end]划分为k堆，需要minCost[start][end][k]的开销，然后最后一步将这k堆合并为1堆，需要sum[start, end]的开销
                    minCost[start][end][1] = minCost[start][end][k] + presums[end + 1] - presums[start];
                }
            }
        }

        return minCost[0][size - 1][1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> stones = { 3,2,4,1 };
    check.checkInt(20, o.mergeStones(stones, 2));

    stones = { 3,2,4,1 };
    check.checkInt(-1, o.mergeStones(stones, 3));

    stones = { 3,5,1,2,6 };
    check.checkInt(25, o.mergeStones(stones, 3));

    stones = { 3,5,1,2,6,3,2,4,1,10,3,5,1,2,6,3,2,4,1,10,3,5,1,2,6,3,2,4,1,10 };
    check.checkInt(524, o.mergeStones(stones, 2));

    stones = { 3,5,1,2,6,3,2,4,1,10,3,5,1,2,6,3,2,4,1,10,3,5,1,2,6,3,2,4,1 };
    check.checkInt(152, o.mergeStones(stones, 15));

    stones = { 3,5,1,2,6,3,2,4,1,10,3,5,1,2,6,3,2,4,1,10,3,5,1,2,6,3,2,4,1 };
    check.checkInt(307, o.mergeStones(stones, 3));

    stones = { 3,5,1,2,6,3,2,4,1,10,3,5,1,2,6,3,2,4,1,10,3,5,1,2,6,3,2,4,1 };
    check.checkInt(216, o.mergeStones(stones, 5));

    stones = { 3,5,1,2,6,3,2,4,1,10,3,5,1,2,6,3,2,4,1,10,3,5,1,2,6,3,2,4,1 };
    check.checkInt(173, o.mergeStones(stones, 8));
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
