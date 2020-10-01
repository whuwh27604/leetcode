/* 秋叶收藏集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小扣出去秋游，途中收集了一些红叶和黄叶，他利用这些叶子初步整理了一份秋叶收藏集 leaves， 字符串 leaves 仅包含小写字符 r 和 y， 其中字符 r 表示一片红叶，字符 y 表示一片黄叶。
出于美观整齐的考虑，小扣想要将收藏集中树叶的排列调整成「红、黄、红」三部分。每部分树叶数量可以不相等，但均需大于等于 1。每次调整操作，小扣可以将一片红叶替换成黄叶或者将一片黄叶替换成红叶。请问小扣最少需要多少次调整操作才能将秋叶收藏集调整完毕。

示例 1：

输入：leaves = "rrryyyrryyyrr"

输出：2

解释：调整两次，将中间的两片红叶替换成黄叶，得到 "rrryyyyyyyyrr"

示例 2：

输入：leaves = "ryr"

输出：0

解释：已符合要求，不需要额外操作

提示：

3 <= leaves.length <= 10^5
leaves 中只包含字符 'r' 和字符 'y'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/UlBDOe
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumOperations(string leaves) {
        /* 令dp[i][j]表示将区间[0,i]调整为模式j需要的最少次数，j∈{0,1,2}，j[0]=rrr...r，j[1]=rrr...yyy，j[2]=rrr...yyy...rrr
           dp[i][0]=dp[i-1][0]+isYellow(i)，在dp[i-1][0]基础上，leaves[i]是黄色则加1，是红色则不用加
           dp[i][1]=min(dp[i-1][0],dp[i-1][1])+isRed(i)，可以把[0,i-1]调整为j[0]模式，也可以调整为j[1]模式，取其中小的，然后将leaves[i]调整为黄色
           dp[i][2]=min(dp[i-1][1],dp[i-1][2])+isYellow(i)，可以把[0,i-1]调整为j[1]模式，也可以调整为j[2]模式，取其中小的，然后将leaves[i]调整为红色 */
        int dp0 = (leaves[0] == 'y' ? 1 : 0) + (leaves[1] == 'y' ? 1 : 0);
        int dp1 = (leaves[0] == 'y' ? 1 : 0) + (leaves[1] == 'r' ? 1 : 0);
        int dp2 = INT_MAX;

        for (int i = 2; i < (int)leaves.size(); ++i) {
            dp2 = min(dp1, dp2) + (leaves[i] == 'y' ? 1 : 0);
            dp1 = min(dp0, dp1) + (leaves[i] == 'r' ? 1 : 0);
            dp0 += (leaves[i] == 'y' ? 1 : 0);
        }

        return dp2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.minimumOperations("rrryyyrryyyrr"));
    check.checkInt(0, o.minimumOperations("ryr"));
    check.checkInt(3, o.minimumOperations("yry"));
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
