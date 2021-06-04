/* 两个盒子中球的颜色数相同的概率.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
桌面上有 2n 个颜色不完全相同的球，球上的颜色共有 k 种。给你一个大小为 k 的整数数组 balls ，其中 balls[i] 是颜色为 i 的球的数量。

所有的球都已经 随机打乱顺序 ，前 n 个球放入第一个盒子，后 n 个球放入另一个盒子（请认真阅读示例 2 的解释部分）。

注意：这两个盒子是不同的。例如，两个球颜色分别为 a 和 b，盒子分别为 [] 和 ()，那么 [a] (b) 和 [b] (a) 这两种分配方式是不同的（请认真阅读示例 1 的解释部分）。

请计算「两个盒子中球的颜色数相同」的情况的概率。

 

示例 1：

输入：balls = [1,1]
输出：1.00000
解释：球平均分配的方式只有两种：
- 颜色为 1 的球放入第一个盒子，颜色为 2 的球放入第二个盒子
- 颜色为 2 的球放入第一个盒子，颜色为 1 的球放入第二个盒子
这两种分配，两个盒子中球的颜色数都相同。所以概率为 2/2 = 1 。
示例 2：

输入：balls = [2,1,1]
输出：0.66667
解释：球的列表为 [1, 1, 2, 3]
随机打乱，得到 12 种等概率的不同打乱方案，每种方案概率为 1/12 ：
[1,1 / 2,3], [1,1 / 3,2], [1,2 / 1,3], [1,2 / 3,1], [1,3 / 1,2], [1,3 / 2,1], [2,1 / 1,3], [2,1 / 3,1], [2,3 / 1,1], [3,1 / 1,2], [3,1 / 2,1], [3,2 / 1,1]
然后，我们将前两个球放入第一个盒子，后两个球放入第二个盒子。
这 12 种可能的随机打乱方式中的 8 种满足「两个盒子中球的颜色数相同」。
概率 = 8/12 = 0.66667
示例 3：

输入：balls = [1,2,1,2]
输出：0.60000
解释：球的列表为 [1, 2, 2, 3, 4, 4]。要想显示所有 180 种随机打乱方案是很难的，但只检查「两个盒子中球的颜色数相同」的 108 种情况是比较容易的。
概率 = 108 / 180 = 0.6 。
示例 4：

输入：balls = [3,2,1]
输出：0.30000
解释：球的列表为 [1, 1, 1, 2, 2, 3]。要想显示所有 60 种随机打乱方案是很难的，但只检查「两个盒子中球的颜色数相同」的 18 种情况是比较容易的。
概率 = 18 / 60 = 0.3 。
示例 5：

输入：balls = [6,6,6,6,6,6]
输出：0.90327
 

提示：

1 <= balls.length <= 8
1 <= balls[i] <= 6
sum(balls) 是偶数
答案与真实值误差在 10^-5 以内，则被视为正确答案

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <numeric>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double getProbability(vector<int>& balls) {
        int colors = balls.size(), totalBalls = accumulate(balls.begin(), balls.end(), 0), ballNum = 0;

        vector<double> factorial(totalBalls + 1);
        calcFactorial(totalBalls, factorial);

        vector<vector<double>> dp(totalBalls + 1, vector<double>(2 * colors + 1, 0));  // dp[color][box1Balls][colorDiff]
        dp[0][colors] = 1;

        for (int color = 0; color < colors; ++color) {
            vector<vector<double>> tmp(totalBalls + 1, vector<double>(2 * colors + 1, 0));

            for (int ball = 0; ball <= balls[color]; ++ball) {
                int trans = (ball == 0 ? -1 : (ball == balls[color] ? 1 : 0));

                for (int box1Balls = 0; box1Balls <= totalBalls; ++box1Balls) {
                    for (int colorDiff = 0; colorDiff <= 2 * colors; ++colorDiff) {
                        if (dp[box1Balls][colorDiff] != 0) {
                            double ways = dp[box1Balls][colorDiff];
                            ways *= factorial[box1Balls + ball] / (factorial[box1Balls] * factorial[ball]);
                            ways *= factorial[ballNum - box1Balls + balls[color] - ball] / (factorial[ballNum - box1Balls] * factorial[balls[color] - ball]);
                            tmp[box1Balls + ball][colorDiff + trans] += ways;
                        }
                    }
                }
            }

            dp = tmp;
            ballNum += balls[color];
        }

        return dp[totalBalls / 2][colors] / getTotalWays(balls, factorial);
    }

    void calcFactorial(int n, vector<double>& factorial) {
        factorial[0] = 1;

        for (int i = 1; i <= n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
    }

    double getTotalWays(vector<int>& balls, vector<double>& factorial) {
        double totalWays = factorial.back();

        for (int ball : balls) {
            totalWays /= factorial[ball];
        }

        return totalWays;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> balls = { 1,1 };
    check.checkDouble(1, o.getProbability(balls));

    balls = { 2,1,1 };
    check.checkDouble(0.666667, o.getProbability(balls));

    balls = { 1,2,1,2 };
    check.checkDouble(0.6, o.getProbability(balls));

    balls = { 3,2,1 };
    check.checkDouble(0.3, o.getProbability(balls));

    balls = { 6,6,6,6,6,6 };
    check.checkDouble(0.903272, o.getProbability(balls));
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
