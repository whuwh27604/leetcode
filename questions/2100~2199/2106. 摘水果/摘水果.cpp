/* 摘水果.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个无限的 x 坐标轴上，有许多水果分布在其中某些位置。给你一个二维整数数组 fruits ，其中 fruits[i] = [positioni, amounti] 表示共有 amounti 个水果放置在 positioni 上。fruits 已经按 positioni 升序排列 ，每个 positioni 互不相同 。

另给你两个整数 startPos 和 k 。最初，你位于 startPos 。从任何位置，你可以选择 向左或者向右 走。在 x 轴上每移动 一个单位 ，就记作 一步 。你总共可以走 最多 k 步。你每达到一个位置，都会摘掉全部的水果，水果也将从该位置消失（不会再生）。

返回你可以摘到水果的 最大总数 。

 

示例 1：


输入：fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
输出：9
解释：
最佳路线为：
- 向右移动到位置 6 ，摘到 3 个水果
- 向右移动到位置 8 ，摘到 6 个水果
移动 3 步，共摘到 3 + 6 = 9 个水果
示例 2：


输入：fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4
输出：14
解释：
可以移动最多 k = 4 步，所以无法到达位置 0 和位置 10 。
最佳路线为：
- 在初始位置 5 ，摘到 7 个水果
- 向左移动到位置 4 ，摘到 1 个水果
- 向右移动到位置 6 ，摘到 2 个水果
- 向右移动到位置 7 ，摘到 4 个水果
移动 1 + 3 = 4 步，共摘到 7 + 1 + 2 + 4 = 14 个水果
示例 3：


输入：fruits = [[0,3],[6,4],[8,5]], startPos = 3, k = 2
输出：0
解释：
最多可以移动 k = 2 步，无法到达任一有水果的地方
 

提示：

1 <= fruits.length <= 105
fruits[i].length == 2
0 <= startPos, positioni <= 2 * 105
对于任意 i > 0 ，positioni-1 < positioni 均成立（下标从 0 开始计数）
1 <= amounti <= 104
0 <= k <= 2 * 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-fruits-harvested-after-at-most-k-steps
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] < v2[0];
}

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int> tmp = { startPos };
        auto iter = lower_bound(fruits.begin(), fruits.end(), tmp, vectorCompare);
        int start = distance(fruits.begin(), iter);  // 找到离startPos最近的索引

        return max(doubleLeft(fruits, startPos, k, start - 1), doubleRight(fruits, startPos, k, start));
    }

    int doubleLeft(vector<vector<int>>& fruits, int startPos, int k, int start) {
        int size = fruits.size(), left = start, right = size - 1, total = 0, maxTotal = 0;

        for (int i = left + 1; i < size; ++i) {
            total += fruits[i][1];
        }

        for (; left >= 0 && startPos - fruits[left][0] <= k; --left) {
            total += fruits[left][1];

            // startPos到left，再折返到startPos，再到right。缩小right直到满足总和小于k
            while (right > start && 2 * (startPos - fruits[left][0]) + fruits[right][0] - startPos > k) {
                total -= fruits[right--][1];
            }

            maxTotal = max(maxTotal, total);
        }

        return maxTotal;
    }

    int doubleRight(vector<vector<int>>& fruits, int startPos, int k, int start) {
        int size = fruits.size(), left = 0, right = start, total = 0, maxTotal = 0;

        for (int i = 0; i < right; ++i) {
            total += fruits[i][1];
        }

        for (; right < size && fruits[right][0] - startPos <= k; ++right) {
            total += fruits[right][1];

            // startPos到right，再折返到startPos，再到left。增大left直到满足总和小于k
            while (left < start && startPos - fruits[left][0] + 2 * (fruits[right][0] - startPos) > k) {
                total -= fruits[left++][1];
            }

            maxTotal = max(maxTotal, total);
        }

        return maxTotal;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> fruits = { {2,8},{6,3},{8,6} };
    check.checkInt(9, o.maxTotalFruits(fruits, 5, 4));

    fruits = { {2,8},{6,3},{8,6} };
    check.checkInt(11, o.maxTotalFruits(fruits, 0, 7));

    fruits = { {2,8},{6,3},{8,6} };
    check.checkInt(17, o.maxTotalFruits(fruits, 9, 9));

    fruits = { {0,9},{4,1},{5,7},{6,2},{7,4},{10,9} };
    check.checkInt(14, o.maxTotalFruits(fruits, 5, 4));

    fruits = { {0,3},{6,4},{8,5} };
    check.checkInt(0, o.maxTotalFruits(fruits, 3, 2));

    fruits = { {200000,10000} };
    check.checkInt(0, o.maxTotalFruits(fruits, 0, 0));
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
