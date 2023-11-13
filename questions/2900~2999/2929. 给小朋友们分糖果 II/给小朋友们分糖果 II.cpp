/* 给小朋友们分糖果 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个正整数 n 和 limit 。

请你将 n 颗糖果分给 3 位小朋友，确保没有任何小朋友得到超过 limit 颗糖果，请你返回满足此条件下的 总方案数 。



示例 1：

输入：n = 5, limit = 2
输出：3
解释：总共有 3 种方法分配 5 颗糖果，且每位小朋友的糖果数不超过 2 ：(1, 2, 2) ，(2, 1, 2) 和 (2, 2, 1) 。
示例 2：

输入：n = 3, limit = 3
输出：10
解释：总共有 10 种方法分配 3 颗糖果，且每位小朋友的糖果数不超过 3 ：(0, 0, 3) ，(0, 1, 2) ，(0, 2, 1) ，(0, 3, 0) ，(1, 0, 2) ，(1, 1, 1) ，(1, 2, 0) ，(2, 0, 1) ，(2, 1, 0) 和 (3, 0, 0) 。


提示：

1 <= n <= 106
1 <= limit <= 106
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long count = 0;

        for (int a = 0; a <= n && a <= limit; ++a) {
            int sum = n - a;  // b + c = sum，求b <= limit && c <= limit的方案数
            if (sum <= limit) {  // b可以取[0, sum]共sum + 1个方案
                count += ((long long)sum + 1);
            }
            else if (sum <= 2 * limit) {  // b可以取[sum - limit, limit]共2 * limit - sum + 1个方案
                count += (2 * (long long)limit - sum + 1);
            }  // sum > 2 * limit时无解
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkLongLong(3, o.distributeCandies(5, 2));
    check.checkLongLong(10, o.distributeCandies(3, 3));
    check.checkLongLong(3, o.distributeCandies(1, 1));
    check.checkLongLong(500001500001, o.distributeCandies(1000000, 1000000));
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
