/* 统计距离为 k 的点对.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 二维 整数数组 coordinates 和一个整数 k ，其中 coordinates[i] = [xi, yi] 是第 i 个点在二维平面里的坐标。

我们定义两个点 (x1, y1) 和 (x2, y2) 的 距离 为 (x1 XOR x2) + (y1 XOR y2) ，XOR 指的是按位异或运算。

请你返回满足 i < j 且点 i 和点 j之间距离为 k 的点对数目。



示例 1：

输入：coordinates = [[1,2],[4,2],[1,3],[5,2]], k = 5
输出：2
解释：以下点对距离为 k ：
- (0, 1)：(1 XOR 4) + (2 XOR 2) = 5 。
- (2, 3)：(1 XOR 5) + (3 XOR 2) = 5 。
示例 2：

输入：coordinates = [[1,3],[1,3],[1,3],[1,3],[1,3]], k = 0
输出：10
解释：任何两个点之间的距离都为 0 ，所以总共有 10 组点对。


提示：

2 <= coordinates.length <= 50000
0 <= xi, yi <= 106
0 <= k <= 100
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        unordered_map<long long, int> count;
        int pairs = 0;

        for (auto& coordinate : coordinates) {
            int x1 = coordinate[0], y1 = coordinate[1];

            for (int a = 0; a <= k; ++a) {
                int b = k - a;
                int x2 = a ^ x1, y2 = b ^ y1;
                long long key = (((long long)x2 << 32) | y2);
                if (count.count(key) != 0) {
                    pairs += count[key];
                }
            }

            ++count[((long long)coordinate[0] << 32) | coordinate[1]];
        }

        return pairs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> coordinates = { {1,2},{4,2},{1,3},{5,2} };
    check.checkInt(2, o.countPairs(coordinates, 5));

    coordinates = { {1,3},{1,3},{1,3},{1,3},{1,3} };
    check.checkInt(10, o.countPairs(coordinates, 0));
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
