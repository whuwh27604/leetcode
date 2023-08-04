/* 长度递增组的最大数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、长度为 n 的数组 usageLimits 。

你的任务是使用从 0 到 n - 1 的数字创建若干组，并确保每个数字 i 在 所有组 中使用的次数总共不超过 usageLimits[i] 次。此外，还必须满足以下条件：

每个组必须由 不同 的数字组成，也就是说，单个组内不能存在重复的数字。
每个组（除了第一个）的长度必须 严格大于 前一个组。
在满足所有条件的情况下，以整数形式返回可以创建的最大组数。



示例 1：

输入：usageLimits = [1,2,5]
输出：3
解释：在这个示例中，我们可以使用 0 至多一次，使用 1 至多 2 次，使用 2 至多 5 次。
一种既能满足所有条件，又能创建最多组的方式是：
组 1 包含数字 [2] 。
组 2 包含数字 [1,2] 。
组 3 包含数字 [0,1,2] 。
可以证明能够创建的最大组数是 3 。
所以，输出是 3 。
示例 2：

输入：usageLimits = [2,1,2]
输出：2
解释：在这个示例中，我们可以使用 0 至多 2 次，使用 1 至多 1 次，使用 2 至多 2 次。
一种既能满足所有条件，又能创建最多组的方式是：
组 1 包含数字 [0] 。
组 2 包含数字 [1,2] 。
可以证明能够创建的最大组数是 2 。
所以，输出是 2 。
示例 3：

输入：usageLimits = [1,1]
输出：1
解释：在这个示例中，我们可以使用 0 和 1 至多 1 次。
一种既能满足所有条件，又能创建最多组的方式是：
组 1 包含数字 [0] 。
可以证明能够创建的最大组数是 1 。
所以，输出是 1 。


提示：

1 <= usageLimits.length <= 105
1 <= usageLimits[i] <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());

        /* 按照从小到大的顺序构造，记前面已经构造了groups个组，剩下left个数字：
        *  1、每组的数字个数必然是贪心的只增加一个，所以第groups组的数字个数也是groups
        *  2、当前数字的个数是limit，当limit + left < groups + 1时，显然无法构造出第groups + 1个组，因为数字个数不够
        *  3、当limit + left >= groups + 1时，是否一定可以构造出第groups + 1个组？答案是肯定的。方法是从前groups个组中挑出groups个不同的数，放在第groups + 1组中，然后将limit + left中的数填回原组中。
        *  4、能否构造出第groups + 2个组？答案是不能。每次新增一个数，最多只能多构成一个组。 */

        int groups = 0;
        long long left = 0;

        for (int limit : usageLimits) {
            left += limit;

            if (left > groups) {
                groups += 1;
                left -= groups;
            }
        }

        return groups;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> usageLimits = { 1,2,5 };
    check.checkInt(3, o.maxIncreasingGroups(usageLimits));

    usageLimits = { 2,1,2 };
    check.checkInt(2, o.maxIncreasingGroups(usageLimits));

    usageLimits = { 1,1 };
    check.checkInt(1, o.maxIncreasingGroups(usageLimits));

    usageLimits = { 1000000000,999999999,999999998 };
    check.checkInt(3, o.maxIncreasingGroups(usageLimits));
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
