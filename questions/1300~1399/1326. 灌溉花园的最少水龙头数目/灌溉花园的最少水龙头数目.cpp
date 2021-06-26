/* 灌溉花园的最少水龙头数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在 x 轴上有一个一维的花园。花园长度为 n，从点 0 开始，到点 n 结束。

花园里总共有 n + 1 个水龙头，分别位于 [0, 1, ..., n] 。

给你一个整数 n 和一个长度为 n + 1 的整数数组 ranges ，其中 ranges[i] （下标从 0 开始）表示：如果打开点 i 处的水龙头，可以灌溉的区域为 [i -  ranges[i], i + ranges[i]] 。

请你返回可以灌溉整个花园的 最少水龙头数目 。如果花园始终存在无法灌溉到的地方，请你返回 -1 。

 

示例 1：



输入：n = 5, ranges = [3,4,1,1,0,0]
输出：1
解释：
点 0 处的水龙头可以灌溉区间 [-3,3]
点 1 处的水龙头可以灌溉区间 [-3,5]
点 2 处的水龙头可以灌溉区间 [1,3]
点 3 处的水龙头可以灌溉区间 [2,4]
点 4 处的水龙头可以灌溉区间 [4,4]
点 5 处的水龙头可以灌溉区间 [5,5]
只需要打开点 1 处的水龙头即可灌溉整个花园 [0,5] 。
示例 2：

输入：n = 3, ranges = [0,0,0,0]
输出：-1
解释：即使打开所有水龙头，你也无法灌溉整个花园。
示例 3：

输入：n = 7, ranges = [1,2,1,0,2,1,0,1]
输出：3
示例 4：

输入：n = 8, ranges = [4,0,0,0,0,0,0,0,4]
输出：2
示例 5：

输入：n = 8, ranges = [4,0,0,0,4,0,0,0,4]
输出：1
 

提示：

1 <= n <= 10^4
ranges.length == n + 1
0 <= ranges[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-taps-to-open-to-water-a-garden
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int i, rightmost = 0, breakpoint = 0, taps = 0;
        vector<int> rightmosts(n + 1, 0);  // rightmosts[i]表示能够覆盖到位置i的水龙头最右边能够覆盖的位置

        for (i = 0; i <= n; ++i) {
            int left = max(0, i - ranges[i]), right = min(n, i + ranges[i]);
            rightmosts[left] = max(rightmosts[left], right);
        }

        for (i = 0; i < n; ++i) {  // 位置n一定是靠其它水龙头覆盖的，所以不要遍历这个位置
            rightmost = max(rightmost, rightmosts[i]);

            if (i == breakpoint) {
                if (rightmost <= i) {
                    return -1;
                }

                breakpoint = rightmost;
                taps += 1;
            }
        }

        return taps;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> ranges = { 3,4,1,1,0,0 };
    check.checkInt(1, o.minTaps(5, ranges));

    ranges = { 0,0,0,0 };
    check.checkInt(-1, o.minTaps(3, ranges));

    ranges = { 1,2,1,0,2,1,0,1 };
    check.checkInt(3, o.minTaps(7, ranges));

    ranges = { 4,0,0,0,0,0,0,0,4 };
    check.checkInt(2, o.minTaps(8, ranges));

    ranges = { 4,0,0,0,4,0,0,0,4 };
    check.checkInt(1, o.minTaps(8, ranges));

    ranges = { 1,0,4,0,4,1,4,3,1,1,1,2,1,4,0,3,0,3,0,3,0,5,3,0,0,1,2,1,2,4,3,0,1,0,5,2 };
    check.checkInt(6, o.minTaps(35, ranges));

    ranges = { 0,0,0,0 };
    check.checkInt(-1, o.minTaps(3, ranges));

    ranges = { 2,1,0,1 };
    check.checkInt(2, o.minTaps(3, ranges));
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
