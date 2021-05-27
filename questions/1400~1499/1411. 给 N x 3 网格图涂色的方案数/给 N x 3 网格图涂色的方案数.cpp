/* 给 N x 3 网格图涂色的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有一个 n x 3 的网格图 grid ，你需要用 红，黄，绿 三种颜色之一给每一个格子上色，且确保相邻格子颜色不同（也就是有相同水平边或者垂直边的格子颜色不同）。

给你网格图的行数 n 。

请你返回给 grid 涂色的方案数。由于答案可能会非常大，请你返回答案对 10^9 + 7 取余的结果。

 

示例 1：

输入：n = 1
输出：12
解释：总共有 12 种可行的方法：

示例 2：

输入：n = 2
输出：54
示例 3：

输入：n = 3
输出：246
示例 4：

输入：n = 7
输出：106494
示例 5：

输入：n = 5000
输出：30228214
 

提示：

n == grid.length
grid[i].length == 3
1 <= n <= 5000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-ways-to-paint-n-3-grid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        long long aba = 6, abc = 6, mod = 1000000007;

        for (int i = 1; i < n; ++i) {
            long long tmp = aba;
            aba = (abc * 2 + aba * 3) % mod;
            abc = (abc * 2 + tmp * 2) % mod;
        }

        return (int)((aba + abc) % mod);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(12, o.numOfWays(1));
    check.checkInt(54, o.numOfWays(2));
    check.checkInt(246, o.numOfWays(3));
    check.checkInt(106494, o.numOfWays(7));
    check.checkInt(30228214, o.numOfWays(5000));
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
