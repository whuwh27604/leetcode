/* 得到 K 个黑块的最少涂色次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 下标从 0 开始的字符串 blocks ，blocks[i] 要么是 'W' 要么是 'B' ，表示第 i 块的颜色。字符 'W' 和 'B' 分别表示白色和黑色。

给你一个整数 k ，表示想要 连续 黑色块的数目。

每一次操作中，你可以选择一个白色块将它 涂成 黑色块。

请你返回至少出现 一次 连续 k 个黑色块的 最少 操作次数。

 

示例 1：

输入：blocks = "WBBWWBBWBW", k = 7
输出：3
解释：
一种得到 7 个连续黑色块的方法是把第 0 ，3 和 4 个块涂成黑色。
得到 blocks = "BBBBBBBWBW" 。
可以证明无法用少于 3 次操作得到 7 个连续的黑块。
所以我们返回 3 。
示例 2：

输入：blocks = "WBWBBBW", k = 2
输出：0
解释：
不需要任何操作，因为已经有 2 个连续的黑块。
所以我们返回 0 。
 

提示：

n == blocks.length
1 <= n <= 100
blocks[i] 要么是 'W' ，要么是 'B' 。
1 <= k <= n

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int size = blocks.size(), left = 0, right, whites = 0;

        for (right = 0; right < k; ++right) {
            whites += (blocks[right] == 'W' ? 1 : 0);
        }

        int minOpers = whites;

        for (; right < size; ++right) {
            whites += (blocks[right] == 'W' ? 1 : 0);
            whites -= (blocks[left++] == 'W' ? 1 : 0);
            minOpers = min(minOpers, whites);
        }

        return minOpers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.minimumRecolors("WBBWWBBWBW", 7));
    check.checkInt(0, o.minimumRecolors("WBWBBBW", 2));
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
