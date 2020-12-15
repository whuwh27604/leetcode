/* 将整数按权重排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们将整数 x 的 权重 定义为按照下述规则将 x 变成 1 所需要的步数：

如果 x 是偶数，那么 x = x / 2
如果 x 是奇数，那么 x = 3 * x + 1
比方说，x=3 的权重为 7 。因为 3 需要 7 步变成 1 （3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1）。

给你三个整数 lo， hi 和 k 。你的任务是将区间 [lo, hi] 之间的整数按照它们的权重 升序排序 ，如果大于等于 2 个整数有 相同 的权重，那么按照数字自身的数值 升序排序 。

请你返回区间 [lo, hi] 之间的整数按权重排序后的第 k 个数。

注意，题目保证对于任意整数 x （lo <= x <= hi） ，它变成 1 所需要的步数是一个 32 位有符号整数。

 

示例 1：

输入：lo = 12, hi = 15, k = 2
输出：13
解释：12 的权重为 9（12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1）
13 的权重为 9
14 的权重为 17
15 的权重为 17
区间内的数按权重排序以后的结果为 [12,13,14,15] 。对于 k = 2 ，答案是第二个整数也就是 13 。
注意，12 和 13 有相同的权重，所以我们按照它们本身升序排序。14 和 15 同理。
示例 2：

输入：lo = 1, hi = 1, k = 1
输出：1
示例 3：

输入：lo = 7, hi = 11, k = 4
输出：7
解释：区间内整数 [7, 8, 9, 10, 11] 对应的权重为 [16, 3, 19, 6, 14] 。
按权重排序后得到的结果为 [8, 10, 11, 7, 9] 。
排序后数组中第 4 个数字为 7 。
示例 4：

输入：lo = 10, hi = 20, k = 5
输出：13
示例 5：

输入：lo = 1, hi = 1000, k = 777
输出：570
 

提示：

1 <= lo <= hi <= 1000
1 <= k <= hi - lo + 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-integers-by-the-power-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

bool pairCompare(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
}

class Solution {
public:
    Solution() {
        powers[1] = 0;
    }

    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> powers;

        for (int num = lo; num <= hi; ++num) {
            powers.push_back({ getPower(num), num });
        }

        sort(powers.begin(), powers.end(), pairCompare);

        return powers[k - 1].second;
    }

    int getPower(int num) {
        if (powers.count(num) != 0) {
            return powers[num];
        }

        int power = 0;
        long long number = num;

        while (number != 1) {
            if ((number & 1) == 1) {
                number = number * 3 + 1;
            }
            else {
                number /= 2;
            }

            ++power;
        }

        powers[num] = power;
        return power;
    }

private:
    unordered_map<int, int> powers;
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.getKth(1, 2, 1));
    check.checkInt(13, o.getKth(12, 15, 2));
    check.checkInt(1, o.getKth(1, 1, 1));
    check.checkInt(7, o.getKth(7, 11, 4));
    check.checkInt(13, o.getKth(10, 20, 5));
    check.checkInt(570, o.getKth(1, 1000, 777));
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
