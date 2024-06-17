/* 构成整天的下标对数目 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 hours，表示以 小时 为单位的时间，返回一个整数，表示满足 i < j 且 hours[i] + hours[j] 构成 整天 的下标对 i, j 的数目。

整天 定义为时间持续时间是 24 小时的 整数倍 。

例如，1 天是 24 小时，2 天是 48 小时，3 天是 72 小时，以此类推。



示例 1：

输入： hours = [12,12,30,24,24]

输出： 2

解释：

构成整天的下标对分别是 (0, 1) 和 (3, 4)。

示例 2：

输入： hours = [72,48,24,3]

输出： 3

解释：

构成整天的下标对分别是 (0, 1)、(0, 2) 和 (1, 2)。



提示：

1 <= hours.length <= 5 * 105
1 <= hours[i] <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<int> count(24, 0);
        long long pairs = 0;

        for (int hour : hours) {
            int r1 = hour % 24, r2 = (r1 == 0 ? 0 : 24 - r1);
            pairs += count[r2];
            ++count[r1];
        }

        return pairs;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> hours = { 12,12,30,24,24 };
    check.checkLongLong(2, o.countCompleteDayPairs(hours));

    hours = { 72,48,24,3 };
    check.checkLongLong(3, o.countCompleteDayPairs(hours));
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
