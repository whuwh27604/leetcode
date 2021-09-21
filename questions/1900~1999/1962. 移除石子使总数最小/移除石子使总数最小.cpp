/* 移除石子使总数最小.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 piles ，数组 下标从 0 开始 ，其中 piles[i] 表示第 i 堆石子中的石子数量。另给你一个整数 k ，请你执行下述操作 恰好 k 次：

选出任一石子堆 piles[i] ，并从中 移除 floor(piles[i] / 2) 颗石子。
注意：你可以对 同一堆 石子多次执行此操作。

返回执行 k 次操作后，剩下石子的 最小 总数。

floor(x) 为 小于 或 等于 x 的 最大 整数。（即，对 x 向下取整）。

 

示例 1：

输入：piles = [5,4,9], k = 2
输出：12
解释：可能的执行情景如下：
- 对第 2 堆石子执行移除操作，石子分布情况变成 [5,4,5] 。
- 对第 0 堆石子执行移除操作，石子分布情况变成 [3,4,5] 。
剩下石子的总数为 12 。
示例 2：

输入：piles = [4,3,6,7], k = 3
输出：12
解释：可能的执行情景如下：
- 对第 2 堆石子执行移除操作，石子分布情况变成 [4,3,3,7] 。
- 对第 3 堆石子执行移除操作，石子分布情况变成 [4,3,3,4] 。
- 对第 0 堆石子执行移除操作，石子分布情况变成 [2,3,3,4] 。
剩下石子的总数为 12 。
 

提示：

1 <= piles.length <= 105
1 <= piles[i] <= 104
1 <= k <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-stones-to-minimize-the-total
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> stones;
        int sum = 0;

        for (int pile : piles) {
            stones.push(pile);
        }

        for (int i = 0; i < k; ++i) {
            int stone = stones.top();
            stones.pop();
            stones.push((stone + 1) >> 1);
        }

        while (!stones.empty()) {
            sum += stones.top();
            stones.pop();
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> piles = { 5,4,9 };
    check.checkInt(12, o.minStoneSum(piles, 2));

    piles = { 4,3,6,7 };
    check.checkInt(12, o.minStoneSum(piles, 3));

    piles = { 7 };
    check.checkInt(1, o.minStoneSum(piles, 10));
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
