/* 高度互不相同的最大塔高和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 maximumHeight ，其中 maximumHeight[i] 表示第 i 座塔可以达到的 最大 高度。

你的任务是给每一座塔分别设置一个高度，使得：

第 i 座塔的高度是一个正整数，且不超过 maximumHeight[i] 。
所有塔的高度互不相同。
请你返回设置完所有塔的高度后，可以达到的 最大 总高度。如果没有合法的设置，返回 -1 。



示例 1：

输入：maximumHeight = [2,3,4,3]

输出：10

解释：

我们可以将塔的高度设置为：[1, 2, 4, 3] 。

示例 2：

输入：maximumHeight = [15,10]

输出：25

解释：

我们可以将塔的高度设置为：[15, 10] 。

示例 3：

输入：maximumHeight = [2,2,1]

输出：-1

解释：

无法设置塔的高度为正整数且高度互不相同。



提示：

1 <= maximumHeight.length <= 105
1 <= maximumHeight[i] <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        long long sum = 0;
        int possible = INT_MAX;

        sort(maximumHeight.begin(), maximumHeight.end());

        for (int i = (int)maximumHeight.size() - 1; i >= 0; --i) {
            if (possible == 0) {
                return -1;
            }

            int height = min(maximumHeight[i], possible);
            sum += height;
            possible = height - 1;
        }

        return sum;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> maximumHeight = { 2,3,4,3 };
    check.checkLongLong(10, o.maximumTotalSum(maximumHeight));

    maximumHeight = { 15,10 };
    check.checkLongLong(25, o.maximumTotalSum(maximumHeight));

    maximumHeight = { 2,2,1 };
    check.checkLongLong(-1, o.maximumTotalSum(maximumHeight));
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
