/* 可获得的最大点数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
几张卡牌 排成一行，每张卡牌都有一个对应的点数。点数由整数数组 cardPoints 给出。

每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌。

你的点数就是你拿到手中的所有卡牌的点数之和。

给你一个整数数组 cardPoints 和整数 k，请你返回可以获得的最大点数。

 

示例 1：

输入：cardPoints = [1,2,3,4,5,6,1], k = 3
输出：12
解释：第一次行动，不管拿哪张牌，你的点数总是 1 。但是，先拿最右边的卡牌将会最大化你的可获得点数。最优策略是拿右边的三张牌，最终点数为 1 + 6 + 5 = 12 。
示例 2：

输入：cardPoints = [2,2,2], k = 2
输出：4
解释：无论你拿起哪两张卡牌，可获得的点数总是 4 。
示例 3：

输入：cardPoints = [9,7,7,9,7,7,9], k = 7
输出：55
解释：你必须拿起所有卡牌，可以获得的点数为所有卡牌的点数之和。
示例 4：

输入：cardPoints = [1,1000,1], k = 1
输出：1
解释：你无法拿到中间那张卡牌，所以可以获得的最大点数为 1 。
示例 5：

输入：cardPoints = [1,79,80,1,1,1,200,1], k = 3
输出：202
 

提示：

1 <= cardPoints.length <= 10^5
1 <= cardPoints[i] <= 10^4
1 <= k <= cardPoints.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i, j, size = cardPoints.size(), sum = 0;
        
        for (i = size - k; i < size; ++i) {
            sum += cardPoints[i];
        }

        int maxSum = sum;

        for (i = 0, j = size - k; i < k; ++i, ++j) {
            sum = sum + cardPoints[i] - cardPoints[j];
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> cardPoints = { 1,2,3,4,5,6,1 };
    check.checkInt(12, o.maxScore(cardPoints, 3));
    
    cardPoints = { 2,2,2 };
    check.checkInt(4, o.maxScore(cardPoints, 2));

    cardPoints = { 9,7,7,9,7,7,9 };
    check.checkInt(55, o.maxScore(cardPoints, 7));

    cardPoints = { 1,1000,1 };
    check.checkInt(1, o.maxScore(cardPoints, 1));

    cardPoints = { 1,79,80,1,1,1,200,1 };
    check.checkInt(202, o.maxScore(cardPoints, 3));
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
