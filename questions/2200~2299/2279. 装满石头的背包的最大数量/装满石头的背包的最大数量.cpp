/* 装满石头的背包的最大数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
现有编号从 0 到 n - 1 的 n 个背包。给你两个下标从 0 开始的整数数组 capacity 和 rocks 。第 i 个背包最大可以装 capacity[i] 块石头，当前已经装了 rocks[i] 块石头。另给你一个整数 additionalRocks ，表示你可以放置的额外石头数量，石头可以往 任意 背包中放置。

请你将额外的石头放入一些背包中，并返回放置后装满石头的背包的 最大 数量。

 

示例 1：

输入：capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
输出：3
解释：
1 块石头放入背包 0 ，1 块石头放入背包 1 。
每个背包中的石头总数是 [2,3,4,4] 。
背包 0 、背包 1 和 背包 2 都装满石头。
总计 3 个背包装满石头，所以返回 3 。
可以证明不存在超过 3 个背包装满石头的情况。
注意，可能存在其他放置石头的方案同样能够得到 3 这个结果。
示例 2：

输入：capacity = [10,2,2], rocks = [2,2,0], additionalRocks = 100
输出：3
解释：
8 块石头放入背包 0 ，2 块石头放入背包 2 。
每个背包中的石头总数是 [10,2,2] 。
背包 0 、背包 1 和背包 2 都装满石头。
总计 3 个背包装满石头，所以返回 3 。
可以证明不存在超过 3 个背包装满石头的情况。
注意，不必用完所有的额外石头。
 

提示：

n == capacity.length == rocks.length
1 <= n <= 5 * 104
1 <= capacity[i] <= 109
0 <= rocks[i] <= capacity[i]
1 <= additionalRocks <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-bags-with-full-capacity-of-rocks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int i, n = rocks.size();
        vector<int> lefts(n);

        for (i = 0; i < n; ++i) {
            lefts[i] = capacity[i] - rocks[i];
        }

        sort(lefts.begin(), lefts.end());

        for (i = 0; i < n && lefts[i] <= additionalRocks; ++i) {
            additionalRocks -= lefts[i];
        }

        return i;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> capacity = { 2,3,4,5 };
    vector<int> rocks = { 1,2,4,4 };
    check.checkInt(3, o.maximumBags(capacity, rocks, 2));

    capacity = { 10,2,2 };
    rocks = { 2,2,0 };
    check.checkInt(3, o.maximumBags(capacity, rocks, 100));

    capacity = { 10 };
    rocks = { 2 };
    check.checkInt(0, o.maximumBags(capacity, rocks, 1));
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
