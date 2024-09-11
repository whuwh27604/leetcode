/* 范围内整数的最大得分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 start 和一个整数 d，代表 n 个区间 [start[i], start[i] + d]。

你需要选择 n 个整数，其中第 i 个整数必须属于第 i 个区间。所选整数的 得分 定义为所选整数两两之间的 最小 绝对差。

返回所选整数的 最大可能得分 。



示例 1：

输入： start = [6,0,3], d = 2

输出： 4

解释：

可以选择整数 8, 0 和 4 获得最大可能得分，得分为 min(|8 - 0|, |8 - 4|, |0 - 4|)，等于 4。

示例 2：

输入： start = [2,6,13,13], d = 5

输出： 5

解释：

可以选择整数 2, 7, 13 和 18 获得最大可能得分，得分为 min(|2 - 7|, |2 - 13|, |2 - 18|, |7 - 13|, |7 - 18|, |13 - 18|)，等于 5。



提示：

2 <= start.length <= 105
0 <= start[i] <= 109
0 <= d <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        int n = (int)start.size();
        long long low = 0, high = 3000000000, ans = 0;

        sort(start.begin(), start.end());

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (check(start, n, d, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }

    bool check(vector<int>& start, int n, int d, long long dist) {
        long long num = (long long)start[0];  // 因为所有区间是定长的，所以可以贪心选择最小的数开始，然后每次最小间隔dist

        for (int i = 1; i < n; ++i) {
            num = max(num + dist, (long long)start[i]);
            if (num > (long long)start[i] + d) {  // 超出了区间范围，无法选到当前num
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> start = { 6,0,3 };
    check.checkInt(4, o.maxPossibleScore(start, 2));

    start = { 2,6,13,13 };
    check.checkInt(5, o.maxPossibleScore(start, 5));

    start = { 0,1000000000,1000000000,1000000000 };
    check.checkInt(500000000, o.maxPossibleScore(start, 1000000000));
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
