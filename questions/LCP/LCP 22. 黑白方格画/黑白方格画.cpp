/* 黑白方格画.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小扣注意到秋日市集上有一个创作黑白方格画的摊位。摊主给每个顾客提供一个固定在墙上的白色画板，画板不能转动。画板上有 n * n 的网格。绘画规则为，小扣可以选择任意多行以及任意多列的格子涂成黑色，所选行数、列数均可为 0。

小扣希望最终的成品上需要有 k 个黑色格子，请返回小扣共有多少种涂色方案。

注意：两个方案中任意一个相同位置的格子颜色不同，就视为不同的方案。

示例 1：

输入：n = 2, k = 2

输出：4

解释：一共有四种不同的方案：
第一种方案：涂第一列；
第二种方案：涂第二列；
第三种方案：涂第一行；
第四种方案：涂第二行。

示例 2：

输入：n = 2, k = 1

输出：0

解释：不可行，因为第一次涂色至少会涂两个黑格。

示例 3：

输入：n = 2, k = 4

输出：1

解释：共有 2*2=4 个格子，仅有一种涂色方案。

限制：

1 <= n <= 6
0 <= k <= n * n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ccw6C7
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int paintingPlan(int n, int k) {
        if (k == n * n) {
            return 1;
        }

        int i, j, ways = 0;

        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if ((i + j) * n - i * j == k) {
                    ways += (combination(n, i) * combination(n, j));
                }
            }
        }

        return ways;
    }

    int combination(int x, int y) {  // C(x,y)=x!/y!(x-y)!
        int i, ans = 1;

        for (i = y + 1; i <= x; ++i) {
            ans *= i;
        }

        for (i = 2; i <= x - y; ++i) {
            ans /= i;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.paintingPlan(2, 2));
    check.checkInt(0, o.paintingPlan(2, 1));
    check.checkInt(1, o.paintingPlan(2, 4));
    check.checkInt(1, o.paintingPlan(1, 0));
    check.checkInt(1, o.paintingPlan(1, 1));
    check.checkInt(1, o.paintingPlan(6, 36));
    check.checkInt(0, o.paintingPlan(6, 15));
    check.checkInt(180, o.paintingPlan(6, 16));
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
