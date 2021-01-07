/* 你可以获得的最大硬币数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 3n 堆数目不一的硬币，你和你的朋友们打算按以下方式分硬币：

每一轮中，你将会选出 任意 3 堆硬币（不一定连续）。
Alice 将会取走硬币数量最多的那一堆。
你将会取走硬币数量第二多的那一堆。
Bob 将会取走最后一堆。
重复这个过程，直到没有更多硬币。
给你一个整数数组 piles ，其中 piles[i] 是第 i 堆中硬币的数目。

返回你可以获得的最大硬币数目。

 

示例 1：

输入：piles = [2,4,1,2,7,8]
输出：9
解释：选出 (2, 7, 8) ，Alice 取走 8 枚硬币的那堆，你取走 7 枚硬币的那堆，Bob 取走最后一堆。
选出 (1, 2, 4) , Alice 取走 4 枚硬币的那堆，你取走 2 枚硬币的那堆，Bob 取走最后一堆。
你可以获得的最大硬币数目：7 + 2 = 9.
考虑另外一种情况，如果选出的是 (1, 2, 8) 和 (2, 4, 7) ，你就只能得到 2 + 4 = 6 枚硬币，这不是最优解。
示例 2：

输入：piles = [2,4,5]
输出：4
示例 3：

输入：piles = [9,8,7,6,5,1,2,3,4]
输出：18
 

提示：

3 <= piles.length <= 10^5
piles.length % 3 == 0
1 <= piles[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-coins-you-can-get
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());

        int i, size = piles.size(), n = size / 3, coins = 0;

        for (i = size - 2; i >= n; i -= 2) {
            coins += piles[i];
        }

        return coins;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> piles = { 2,4,1,2,7,8 };
    check.checkInt(9, o.maxCoins(piles));

    piles = { 2,4,5 };
    check.checkInt(4, o.maxCoins(piles));

    piles = { 9,8,7,6,5,1,2,3,4 };
    check.checkInt(18, o.maxCoins(piles));

    piles = { 1,1,1 };
    check.checkInt(1, o.maxCoins(piles));
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
