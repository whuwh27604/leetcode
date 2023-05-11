/* 有相同颜色的相邻元素数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、长度为 n 的数组 nums 。一开始，所有元素都是 未染色 （值为 0 ）的。

给你一个二维整数数组 queries ，其中 queries[i] = [indexi, colori] 。

对于每个操作，你需要将数组 nums 中下标为 indexi 的格子染色为 colori 。

请你返回一个长度与 queries 相等的数组 answer ，其中 answer[i]是前 i 个操作 之后 ，相邻元素颜色相同的数目。

更正式的，answer[i] 是执行完前 i 个操作后，0 <= j < n - 1 的下标 j 中，满足 nums[j] == nums[j + 1] 且 nums[j] != 0 的数目。



示例 1：

输入：n = 4, queries = [[0,2],[1,2],[3,1],[1,1],[2,1]]
输出：[0,1,1,0,2]
解释：一开始数组 nums = [0,0,0,0] ，0 表示数组中还没染色的元素。
- 第 1 个操作后，nums = [2,0,0,0] 。相邻元素颜色相同的数目为 0 。
- 第 2 个操作后，nums = [2,2,0,0] 。相邻元素颜色相同的数目为 1 。
- 第 3 个操作后，nums = [2,2,0,1] 。相邻元素颜色相同的数目为 1 。
- 第 4 个操作后，nums = [2,1,0,1] 。相邻元素颜色相同的数目为 0 。
- 第 5 个操作后，nums = [2,1,1,1] 。相邻元素颜色相同的数目为 2 。
示例 2：

输入：n = 1, queries = [[0,100000]]
输出：[0]
解释：一开始数组 nums = [0] ，0 表示数组中还没染色的元素。
- 第 1 个操作后，nums = [100000] 。相邻元素颜色相同的数目为 0 。


提示：

1 <= n <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= indexi <= n - 1
1 <=  colori <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int size = queries.size(), index = 0, count = 0;
        vector<int> colors(n, 0), ans(size);

        for (auto& query : queries) {
            int idx = query[0], color = query[1];

            if (colors[idx] != color) {
                if (idx != 0 && colors[idx] != 0 && colors[idx - 1] == colors[idx]) {
                    --count;
                }
                if (idx != n - 1 && colors[idx] != 0 && colors[idx] == colors[idx + 1]) {
                    --count;
                }
                if (idx != 0 && colors[idx - 1] == color) {
                    ++count;
                }
                if (idx != n - 1 && colors[idx + 1] == color) {
                    ++count;
                }

                colors[idx] = color;
            }

            ans[index++] = count;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> queries = { {0,2},{1,2},{3,1},{1,1},{2,1} };
    vector<int> actual = o.colorTheArray(4, queries);
    vector<int> expected = { 0,1,1,0,2 };
    check.checkIntVector(expected, actual);

    queries = { {0,100000} };
    actual = o.colorTheArray(1, queries);
    expected = { 0 };
    check.checkIntVector(expected, actual);
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
