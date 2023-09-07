/* 在传球游戏中最大化函数值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 下标从 0 开始的整数数组 receiver 和一个整数 k 。

总共有 n 名玩家，玩家 编号 互不相同，且为 [0, n - 1] 中的整数。这些玩家玩一个传球游戏，receiver[i] 表示编号为 i 的玩家会传球给编号为 receiver[i] 的玩家。玩家可以传球给自己，也就是说 receiver[i] 可能等于 i 。

你需要从 n 名玩家中选择一名玩家作为游戏开始时唯一手中有球的玩家，球会被传 恰好 k 次。

如果选择编号为 x 的玩家作为开始玩家，定义函数 f(x) 表示从编号为 x 的玩家开始，k 次传球内所有接触过球玩家的编号之 和 ，如果有玩家多次触球，则 累加多次 。换句话说， f(x) = x + receiver[x] + receiver[receiver[x]] + ... + receiver(k)[x] 。

你的任务时选择开始玩家 x ，目的是 最大化 f(x) 。

请你返回函数的 最大值 。

注意：receiver 可能含有重复元素。



示例 1：

传递次数	传球者编号	接球者编号	x + 所有接球者编号
            2
1	2	1	3
2	1	0	3
3	0	2	5
4	2	1	6


输入：receiver = [2,0,1], k = 4
输出：6
解释：上表展示了从编号为 x = 2 开始的游戏过程。
从表中可知，f(2) 等于 6 。
6 是能得到最大的函数值。
所以输出为 6 。
示例 2：

传递次数	传球者编号	接球者编号	x + 所有接球者编号
            4
1	4	3	7
2	3	2	9
3	2	1	10


输入：receiver = [1,1,1,2,3], k = 3
输出：10
解释：上表展示了从编号为 x = 4 开始的游戏过程。
从表中可知，f(4) 等于 10 。
10 是能得到最大的函数值。
所以输出为 10 。


提示：

1 <= receiver.length == n <= 105
0 <= receiver[i] <= n - 1
1 <= k <= 1010
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int size = receiver.size(), maxPower = getMaxPower(k);
        long long maxValue = 0;
        vector<vector<int>> dest(maxPower, vector<int>(size));  // dest[p][i]表示从位置i出发，传球2 ^ p次，最终球到达的位置
        vector<vector<long long>> sum(maxPower, vector<long long>(size));  // sum[p][i]表示从位置i出发，传球2 ^ p次，经过路径的权值和，注意不包括终点的权值

        getDestSum(receiver, dest, sum);

        for (int start = 0; start < size; ++start) {  // 枚举起点
            maxValue = max(maxValue, getMaxValue(start, k, dest, sum));
        }

        return maxValue;
    }

    int getMaxPower(long long k) {
        int maxPower = 0;

        while (k != 1) {
            k /= 2;
            ++maxPower;
        }

        return maxPower + 1;
    }

    void getDestSum(vector<int>& receiver, vector<vector<int>>& dest, vector<vector<long long>>& sum) {
        int size = receiver.size(), maxPower = dest.size();

        for (int i = 0; i < size; ++i) {  // p = 0，2 ^ p = 1，传球1次
            dest[0][i] = receiver[i];
            sum[0][i] = i;
        }

        for (int p = 1; p < maxPower; ++p) {
            for (int i = 0; i < size; ++i) {
                dest[p][i] = dest[p - 1][dest[p - 1][i]];  // 从位置i传球2 ^ p次，等于从位置i传球2 ^ (p - 1)次到达位置j，再从位置j传球2 ^ (p - 1)次
                sum[p][i] = sum[p - 1][i] + sum[p - 1][dest[p - 1][i]];  // 从位置i传球2 ^ p次的路径和，等于从位置i传球2 ^ (p - 1)次到达位置j的路径和，再加上从位置j传球2 ^ (p - 1)次的路径和
            }
        }
    }

    long long getMaxValue(int start, long long k, vector<vector<int>>& dest, vector<vector<long long>>& sum) {
        long long value = 0;
        int index = start, p = 0;

        for (long long bit = 1; bit <= k; bit <<= 1, ++p) {
            if ((bit & k) != 0) {
                value += sum[p][index];
                index = dest[p][index];
            }
        }

        return value + index;  // 最后要加上终点的权值
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> receiver = { 2,0,1 };
    check.checkLongLong(6, o.getMaxFunctionValue(receiver, 4));

    receiver = { 1,1,1,2,3 };
    check.checkLongLong(10, o.getMaxFunctionValue(receiver, 3));

    receiver = { 0 };
    check.checkLongLong(0, o.getMaxFunctionValue(receiver, 1));
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
