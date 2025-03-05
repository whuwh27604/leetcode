/* 可行数组的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的数组 original 和一个长度为 n x 2 的二维数组 bounds，其中 bounds[i] = [ui, vi]。

你需要找到长度为 n 且满足以下条件的 可能的 数组 copy 的数量：

对于 1 <= i <= n - 1 ，都有 (copy[i] - copy[i - 1]) == (original[i] - original[i - 1]) 。
对于 0 <= i <= n - 1 ，都有 ui <= copy[i] <= vi 。
返回满足这些条件的数组数目。



示例 1

输入：original = [1,2,3,4], bounds = [[1,2],[2,3],[3,4],[4,5]]

输出：2

解释：

可能的数组为：

[1, 2, 3, 4]
[2, 3, 4, 5]
示例 2

输入：original = [1,2,3,4], bounds = [[1,10],[2,9],[3,8],[4,7]]

输出：4

解释：

可能的数组为：

[1, 2, 3, 4]
[2, 3, 4, 5]
[3, 4, 5, 6]
[4, 5, 6, 7]
示例 3

输入：original = [1,2,1,2], bounds = [[1,1],[2,3],[3,3],[2,3]]

输出：0

解释：

没有可行的数组。



提示：

2 <= n == original.length <= 105
1 <= original[i] <= 109
bounds.length == n
bounds[i].length == 2
1 <= bounds[i][0] <= bounds[i][1] <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = (int)original.size();
        int low = bounds[0][0], high = bounds[0][1], diff = 0;

        for (int i = 1; i < n; ++i) {
            diff += (original[i] - original[i - 1]);
            int L = bounds[i][0] - diff, H = bounds[i][1] - diff;

            if (L > high || H < low) {
                return 0;
            }

            low = max(low, L);
            high = min(high, H);
        }

        return high - low + 1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> original = { 1,2,3,4 };
    vector<vector<int>> bounds = { {1,2},{2,3},{3,4},{4,5} };
    check.checkInt(2, o.countArrays(original, bounds));

    original = { 1,2,3,4 };
    bounds = { {1,10},{2,9},{3,8},{4,7} };
    check.checkInt(4, o.countArrays(original, bounds));

    original = { 1,2,1,2 };
    bounds = { {1,1},{2,3},{3,3},{2,3} };
    check.checkInt(0, o.countArrays(original, bounds));

    original = { 3,25 };
    bounds = { {9,80},{16,35} };
    check.checkInt(5, o.countArrays(original, bounds));
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
