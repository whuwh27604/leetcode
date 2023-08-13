/* 子序列最大优雅度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的二维整数数组 items 和一个整数 k 。

items[i] = [profiti, categoryi]，其中 profiti 和 categoryi 分别表示第 i 个项目的利润和类别。

现定义 items 的 子序列 的 优雅度 可以用 total_profit + distinct_categories2 计算，其中 total_profit 是子序列中所有项目的利润总和，distinct_categories 是所选子序列所含的所有类别中不同类别的数量。

你的任务是从 items 所有长度为 k 的子序列中，找出 最大优雅度 。

用整数形式表示并返回 items 中所有长度恰好为 k 的子序列的最大优雅度。

注意：数组的子序列是经由原数组删除一些元素（可能不删除）而产生的新数组，且删除不改变其余元素相对顺序。



示例 1：

输入：items = [[3,2],[5,1],[10,1]], k = 2
输出：17
解释：
在这个例子中，我们需要选出长度为 2 的子序列。
其中一种方案是 items[0] = [3,2] 和 items[2] = [10,1] 。
子序列的总利润为 3 + 10 = 13 ，子序列包含 2 种不同类别 [2,1] 。
因此，优雅度为 13 + 22 = 17 ，可以证明 17 是可以获得的最大优雅度。
示例 2：

输入：items = [[3,1],[3,1],[2,2],[5,3]], k = 3
输出：19
解释：
在这个例子中，我们需要选出长度为 3 的子序列。
其中一种方案是 items[0] = [3,1] ，items[2] = [2,2] 和 items[3] = [5,3] 。
子序列的总利润为 3 + 2 + 5 = 10 ，子序列包含 3 种不同类别 [1, 2, 3] 。
因此，优雅度为 10 + 32 = 19 ，可以证明 19 是可以获得的最大优雅度。
示例 3：

输入：items = [[1,1],[2,1],[3,1]], k = 3
输出：7
解释：
在这个例子中，我们需要选出长度为 3 的子序列。
我们需要选中所有项目。
子序列的总利润为 1 + 2 + 3 = 6，子序列包含 1 种不同类别 [1] 。
因此，最大优雅度为 6 + 12 = 7 。


提示：

1 <= items.length == n <= 105
items[i].length == 2
items[i][0] == profiti
items[i][1] == categoryi
1 <= profiti <= 109
1 <= categoryi <= n
1 <= k <= n
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n = items.size(), left = n - k - 1, right = n - k;
        long long elegance = 0;
        unordered_map<int, int> cateCount;

        sort(items.begin(), items.end());

        for (int i = right; i < n; ++i) {  // 先选右边profit最大的k个
            elegance += items[i][0];
            ++cateCount[items[i][1]];
        }

        long long cates = cateCount.size();
        elegance += (cates * cates);
        long long maxElegance = elegance;

        for (; left >= 0; --left) {  // 尝试将左边的item替换右边的，profit会变小，但category会变大
            int profit1 = items[left][0], category1 = items[left][1];
            if (cateCount.count(category1) != 0) {  // 如果category1在右边已经出现过，那么替换它不会导致category变大
                continue;
            }

            while (right < n && cateCount[items[right][1]] == 1) {  // 在右边找category有重复且profit最小的一个
                ++right;
            }

            if (right < n) {  // 找到了，用left替换right
                int profit2 = items[right][0], category2 = items[right][1];
                --cateCount[category2];
                ++cateCount[category1];
                elegance -= profit2;
                elegance += profit1;
                elegance -= (cates * cates);
                ++cates;
                elegance += (cates * cates);
                maxElegance = max(maxElegance, elegance);  // 此时elegance可能变大也可能变小，只是候选答案。但最终答案一定在这个过程中出现。
                ++right;
            }
        }

        return maxElegance;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> items = { {3,2},{5,1},{10,1} };
    check.checkLongLong(17, o.findMaximumElegance(items, 2));

    items = { {3,1},{3,1},{2,2},{5,3} };
    check.checkLongLong(19, o.findMaximumElegance(items, 3));

    items = { {1,1},{2,1},{3,1} };
    check.checkLongLong(7, o.findMaximumElegance(items, 3));

    items = { {1,5},{4,5},{9,8},{6,8},{4,7},{4,2},{4,3},{10,8} };
    check.checkLongLong(38, o.findMaximumElegance(items, 4));
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
