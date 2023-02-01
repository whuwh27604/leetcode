/* 将珠子放入背包中.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有 k 个背包。给你一个下标从 0 开始的整数数组 weights ，其中 weights[i] 是第 i 个珠子的重量。同时给你整数 k 。

请你按照如下规则将所有的珠子放进 k 个背包。

没有背包是空的。
如果第 i 个珠子和第 j 个珠子在同一个背包里，那么下标在 i 到 j 之间的所有珠子都必须在这同一个背包中。
如果一个背包有下标从 i 到 j 的所有珠子，那么这个背包的价格是 weights[i] + weights[j] 。
一个珠子分配方案的 分数 是所有 k 个背包的价格之和。

请你返回所有分配方案中，最大分数 与 最小分数 的 差值 为多少。



示例 1：

输入：weights = [1,3,5,1], k = 2
输出：4
解释：
分配方案 [1],[3,5,1] 得到最小得分 (1+1) + (3+1) = 6 。
分配方案 [1,3],[5,1] 得到最大得分 (1+3) + (5+1) = 10 。
所以差值为 10 - 6 = 4 。
示例 2：

输入：weights = [1, 3], k = 2
输出：0
解释：唯一的分配方案为 [1],[3] 。
最大最小得分相等，所以返回 0 。


提示：

1 <= k <= weights.length <= 105
1 <= weights[i] <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long maxScore = 0, minScore = 0;
        int size = weights.size();
        vector<int> pairWeights(size - 1);

        for (int i = 0; i < size - 1; ++i) {
            pairWeights[i] = weights[i] + weights[i + 1];
        }

        sort(pairWeights.begin(), pairWeights.end());

        for (int i = 0; i < k - 1; ++i) {
            minScore += pairWeights[i];
            maxScore += pairWeights[size - 2 - i];
        }

        return maxScore - minScore;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> weights = { 1,3,5,1 };
    check.checkLongLong(4, o.putMarbles(weights, 2));

    weights = { 1,3 };
    check.checkLongLong(0, o.putMarbles(weights, 2));

    weights = { 5 };
    check.checkLongLong(0, o.putMarbles(weights, 1));

    weights = { 1,1,1,1,7,10,8,2,2,2 };
    check.checkLongLong(31, o.putMarbles(weights, 3));
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
