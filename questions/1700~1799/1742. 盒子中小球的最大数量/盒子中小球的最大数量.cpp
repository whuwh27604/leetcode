/* 盒子中小球的最大数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你在一家生产小球的玩具厂工作，有 n 个小球，编号从 lowLimit 开始，到 highLimit 结束（包括 lowLimit 和 highLimit ，即 n == highLimit - lowLimit + 1）。另有无限数量的盒子，编号从 1 到 infinity 。

你的工作是将每个小球放入盒子中，其中盒子的编号应当等于小球编号上每位数字的和。例如，编号 321 的小球应当放入编号 3 + 2 + 1 = 6 的盒子，而编号 10 的小球应当放入编号 1 + 0 = 1 的盒子。

给你两个整数 lowLimit 和 highLimit ，返回放有最多小球的盒子中的小球数量。如果有多个盒子都满足放有最多小球，只需返回其中任一盒子的小球数量。

 

示例 1：

输入：lowLimit = 1, highLimit = 10
输出：2
解释：
盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
小球数量：2 1 1 1 1 1 1 1 1 0  0  ...
编号 1 的盒子放有最多小球，小球数量为 2 。
示例 2：

输入：lowLimit = 5, highLimit = 15
输出：2
解释：
盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
小球数量：1 1 1 1 2 2 1 1 1 0  0  ...
编号 5 和 6 的盒子放有最多小球，每个盒子中的小球数量都是 2 。
示例 3：

输入：lowLimit = 19, highLimit = 28
输出：2
解释：
盒子编号：1 2 3 4 5 6 7 8 9 10 11 12 ...
小球数量：0 1 1 1 1 1 1 1 1 2  0  0  ...
编号 10 的盒子放有最多小球，小球数量为 2 。
 

提示：

1 <= lowLimit <= highLimit <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-balls-in-a-box
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> boxes(46, 0);

        int box = getFirstBox(lowLimit);
        ++boxes[box];

        for (int i = lowLimit + 1; i <= highLimit; ++i) {
            int zeroCount = 0, ball = i;

            while (ball % 10 == 0) {
                ++zeroCount;
                ball /= 10;
            }

            box = box - 9 * zeroCount + 1;
            ++boxes[box];
        }

        return *max_element(boxes.begin(), boxes.end());
    }

    int getFirstBox(int lowLimit) {
        int sum = 0;

        while (lowLimit != 0) {
            sum += lowLimit % 10;
            lowLimit /= 10;
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.countBalls(1, 10));
    check.checkInt(2, o.countBalls(5, 15));
    check.checkInt(2, o.countBalls(19, 28));
    check.checkInt(6000, o.countBalls(1, 100000));
    check.checkInt(6000, o.countBalls(9, 99999));
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
