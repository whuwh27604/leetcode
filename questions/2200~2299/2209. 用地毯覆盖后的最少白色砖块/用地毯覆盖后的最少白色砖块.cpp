/* 用地毯覆盖后的最少白色砖块.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的 二进制 字符串 floor ，它表示地板上砖块的颜色。

floor[i] = '0' 表示地板上第 i 块砖块的颜色是 黑色 。
floor[i] = '1' 表示地板上第 i 块砖块的颜色是 白色 。
同时给你 numCarpets 和 carpetLen 。你有 numCarpets 条 黑色 的地毯，每一条 黑色 的地毯长度都为 carpetLen 块砖块。请你使用这些地毯去覆盖砖块，使得未被覆盖的剩余 白色 砖块的数目 最小 。地毯相互之间可以覆盖。

请你返回没被覆盖的白色砖块的 最少 数目。

 

示例 1：



输入：floor = "10110101", numCarpets = 2, carpetLen = 2
输出：2
解释：
上图展示了剩余 2 块白色砖块的方案。
没有其他方案可以使未被覆盖的白色砖块少于 2 块。
示例 2：



输入：floor = "11111", numCarpets = 2, carpetLen = 3
输出：0
解释：
上图展示了所有白色砖块都被覆盖的一种方案。
注意，地毯相互之间可以覆盖。
 

提示：

1 <= carpetLen <= floor.length <= 1000
floor[i] 要么是 '0' ，要么是 '1' 。
1 <= numCarpets <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-white-tiles-after-covering-with-carpets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int i, size = floor.size();
        vector<int> whites(size + carpetLen, 0);
        vector<vector<int>> dp(size + carpetLen, vector<int>(numCarpets + 1, 0));  // dp[i][carpets]表示floor[i, size)用carpets个最多可以覆盖几个白色

        for (i = size - 1; i >= 0; --i) {
            whites[i] = whites[i + 1] + (floor[i] - '0');

            for (int carpets = 1; carpets <= numCarpets; ++carpets) {
                dp[i][carpets] = dp[i + 1][carpets];

                if (floor[i] == '1') {
                    dp[i][carpets] = max(dp[i][carpets], whites[i] - whites[i + carpetLen] + dp[i + carpetLen][carpets - 1]);
                }
            }
        }

        return whites[0] - dp[0][numCarpets];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.minimumWhiteTiles("10110101", 2, 2));
    check.checkInt(0, o.minimumWhiteTiles("11111", 2, 3));
    check.checkInt(0, o.minimumWhiteTiles("0101111", 2, 3));
    check.checkInt(0, o.minimumWhiteTiles("1111010", 2, 3));
    check.checkInt(0, o.minimumWhiteTiles("10011011001", 2, 5));
    check.checkInt(0, o.minimumWhiteTiles("1", 2, 3));
    check.checkInt(0, o.minimumWhiteTiles("0", 2, 3));
    check.checkInt(41, o.minimumWhiteTiles("101101011011010110110101101101011011010110110101101101011011010110110101", 2, 2));
    check.checkInt(25, o.minimumWhiteTiles("101101011011010110110101101101011011010110110101101101011011010110110101", 2, 15));
    check.checkInt(5, o.minimumWhiteTiles("101101011011010110110101101101011011010110110101101101011011010110110101", 10, 6));
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
