/* 数组列表中的最大距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定 m 个数组，每个数组都已经按照升序排好序了。

现在你需要从两个不同的数组中选择两个整数（每个数组选一个）并且计算它们的距离。两个整数 a 和 b 之间的距离定义为它们差的绝对值 |a-b| 。

返回最大距离。

示例 1：

输入：[[1,2,3],[4,5],[1,2,3]]
输出：4
解释：
一种得到答案 4 的方法是从第一个数组或者第三个数组中选择 1，同时从第二个数组中选择 5 。
示例 2：

输入：arrays = [[1],[1]]
输出：0


提示：

m == arrays.length
2 <= m <= 105
1 <= arrays[i].length <= 500
-104 <= arrays[i][j] <= 104
arrays[i] 以 升序 排序。
所有数组中最多有 105 个整数。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int a = arrays[0][0], b = arrays[0].back(), maxDist = 0;

        for (int i = 1; i < (int)arrays.size(); ++i) {
            int x = arrays[i][0], y = arrays[i].back();
            maxDist = max(maxDist, abs(a - x));
            maxDist = max(maxDist, abs(a - y));
            maxDist = max(maxDist, abs(b - x));
            maxDist = max(maxDist, abs(b - y));
            a = min(a, x);
            b = max(b, y);
        }

        return maxDist;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> arrays = { {1,2,3},{4,5},{1,2,3} };
    check.checkInt(4, o.maxDistance(arrays));

    arrays = { {1},{1} };
    check.checkInt(0, o.maxDistance(arrays));

    arrays = { {1,2,100},{4,5},{1,2,100},{1,2,100} };
    check.checkInt(99, o.maxDistance(arrays));
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
