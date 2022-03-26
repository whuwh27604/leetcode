/* 射箭比赛中的最大得分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Alice 和 Bob 是一场射箭比赛中的对手。比赛规则如下：

Alice 先射 numArrows 支箭，然后 Bob 也射 numArrows 支箭。
分数按下述规则计算：
箭靶有若干整数计分区域，范围从 0 到 11 （含 0 和 11）。
箭靶上每个区域都对应一个得分 k（范围是 0 到 11），Alice 和 Bob 分别在得分 k 区域射中 ak 和 bk 支箭。如果 ak >= bk ，那么 Alice 得 k 分。如果 ak < bk ，则 Bob 得 k 分
如果 ak == bk == 0 ，那么无人得到 k 分。
例如，Alice 和 Bob 都向计分为 11 的区域射 2 支箭，那么 Alice 得 11 分。如果 Alice 向计分为 11 的区域射 0 支箭，但 Bob 向同一个区域射 2 支箭，那么 Bob 得 11 分。

给你整数 numArrows 和一个长度为 12 的整数数组 aliceArrows ，该数组表示 Alice 射中 0 到 11 每个计分区域的箭数量。现在，Bob 想要尽可能 最大化 他所能获得的总分。

返回数组 bobArrows ，该数组表示 Bob 射中 0 到 11 每个 计分区域的箭数量。且 bobArrows 的总和应当等于 numArrows 。

如果存在多种方法都可以使 Bob 获得最大总分，返回其中 任意一种 即可。

 

示例 1：



输入：numArrows = 9, aliceArrows = [1,1,0,1,0,0,2,1,0,1,2,0]
输出：[0,0,0,0,1,1,0,0,1,2,3,1]
解释：上表显示了比赛得分情况。
Bob 获得总分 4 + 5 + 8 + 9 + 10 + 11 = 47 。
可以证明 Bob 无法获得比 47 更高的分数。
示例 2：



输入：numArrows = 3, aliceArrows = [0,0,1,0,0,0,0,0,0,0,0,2]
输出：[0,0,0,0,0,0,0,0,1,1,1,0]
解释：上表显示了比赛得分情况。
Bob 获得总分 8 + 9 + 10 = 27 。
可以证明 Bob 无法获得比 27 更高的分数。
 

提示：

1 <= numArrows <= 105
aliceArrows.length == bobArrows.length == 12
0 <= aliceArrows[i], bobArrows[i] <= numArrows
sum(aliceArrows[i]) == numArrows

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-points-in-an-archery-competition
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<vector<int>> memo(12, vector<int>(numArrows + 1, -1)), bobChoices(12, vector<int>(numArrows + 1, 0));

        (void)getMaxPoints(numArrows, 0, aliceArrows, memo, bobChoices);

        return getBobArrows(bobChoices, aliceArrows, numArrows);
    }

    int getMaxPoints(int numArrows, int point, vector<int>& aliceArrows, vector<vector<int>>& maxPoints, vector<vector<int>>& bobChoices) {
        if (point == 12) {
            return 0;
        }

        int& ans = maxPoints[point][numArrows];
        if (ans != -1) {
            return ans;
        }

        ans = getMaxPoints(numArrows, point + 1, aliceArrows, maxPoints, bobChoices);

        if (numArrows > aliceArrows[point]) {
            int maxPoint = point + getMaxPoints(numArrows - aliceArrows[point] - 1, point + 1, aliceArrows, maxPoints, bobChoices);

            if (maxPoint > ans) {
                ans = maxPoint;
                bobChoices[point][numArrows] = 1;
            }
        }

        return ans;
    }

    vector<int> getBobArrows(vector<vector<int>>& bobChoices, vector<int>& aliceArrows, int numArrows) {
        vector<int> bobArrows(12, 0);

        for (int point = 0; point < 12; ++point) {
            if (bobChoices[point][numArrows] == 1) {
                bobArrows[point] = aliceArrows[point] + 1;
                numArrows -= bobArrows[point];
            }
        }

        bobArrows[0] = numArrows;

        return bobArrows;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> aliceArrows = { 1,1,0,1,0,0,2,1,0,1,2,0 };
    vector<int> actual = o.maximumBobPoints(9, aliceArrows);
    vector<int> expected = { 0,0,0,0,1,1,0,0,1,2,3,1 };
    check.checkIntVector(expected, actual);

    aliceArrows = { 0,0,1,0,0,0,0,0,0,0,0,2 };
    actual = o.maximumBobPoints(3, aliceArrows);
    expected = { 0,0,0,0,0,0,0,0,1,1,1,0 };
    check.checkIntVector(expected, actual);

    aliceArrows = { 3,2,28,1,7,1,16,7,3,13,3,5 };
    actual = o.maximumBobPoints(89, aliceArrows);
    expected = { 21,3,0,2,8,2,17,8,4,14,4,6 };
    check.checkIntVector(expected, actual);
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
