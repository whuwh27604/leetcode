/* 你能构造出连续值的最大数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 coins ，它代表你拥有的 n 个硬币。第 i 个硬币的值为 coins[i] 。如果你从这些硬币中选出一部分硬币，它们的和为 x ，那么称，你可以 构造 出 x 。

请返回从 0 开始（包括 0 ），你最多能 构造 出多少个连续整数。

你可能有多个相同值的硬币。

 

示例 1：

输入：coins = [1,3]
输出：2
解释：你可以得到以下这些值：
- 0：什么都不取 []
- 1：取 [1]
从 0 开始，你可以构造出 2 个连续整数。
示例 2：

输入：coins = [1,1,1,4]
输出：8
解释：你可以得到以下这些值：
- 0：什么都不取 []
- 1：取 [1]
- 2：取 [1,1]
- 3：取 [1,1,1]
- 4：取 [4]
- 5：取 [4,1]
- 6：取 [4,1,1]
- 7：取 [4,1,1,1]
从 0 开始，你可以构造出 8 个连续整数。
示例 3：

输入：nums = [1,4,10,3,1]
输出：20
 

提示：

coins.length == n
1 <= n <= 4 * 104
1 <= coins[i] <= 4 * 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-consecutive-values-you-can-make
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());

        int end = 0;

        for (int coin : coins) {
            if (coin > end + 1) {
                break;
            }

            end += coin;
        }

        return end + 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> coins = { 1,3 };
    check.checkInt(2, o.getMaximumConsecutive(coins));

    coins = { 1,1,1,4 };
    check.checkInt(8, o.getMaximumConsecutive(coins));

    coins = { 1,4,10,3,1 };
    check.checkInt(20, o.getMaximumConsecutive(coins));

    coins = { 3 };
    check.checkInt(1, o.getMaximumConsecutive(coins));
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
