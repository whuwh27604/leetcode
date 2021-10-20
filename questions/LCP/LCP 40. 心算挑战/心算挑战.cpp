/* 心算挑战.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
「力扣挑战赛」心算项目的挑战比赛中，要求选手从 N 张卡牌中选出 cnt 张卡牌，若这 cnt 张卡牌数字总和为偶数，则选手成绩「有效」且得分为 cnt 张卡牌数字总和。
给定数组 cards 和 cnt，其中 cards[i] 表示第 i 张卡牌上的数字。 请帮参赛选手计算最大的有效得分。若不存在获取有效得分的卡牌方案，则返回 0。

示例 1：

输入：cards = [1,2,8,9], cnt = 3

输出：18

解释：选择数字为 1、8、9 的这三张卡牌，此时可获得最大的有效得分 1+8+9=18。

示例 2：

输入：cards = [3,3,1], cnt = 1

输出：0

解释：不存在获取有效得分的卡牌方案。

提示：

1 <= cnt <= cards.length <= 10^5
1 <= cards[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/uOAnQW
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        vector<int> odds, evens;

        for (int card : cards) {
            ((card & 1) == 1) ? odds.push_back(card) : evens.push_back(card);
        }

        sort(odds.begin(), odds.end());
        sort(evens.begin(), evens.end());
        int i = odds.size() - 1, j = evens.size() - 1, score = 0;

        if ((cnt & 1) == 1) {
            if (j >= 0) {
                score += evens[j--];
                --cnt;
            }
            else {
                return 0;
            }
        }

        while (cnt != 0) {
            int twoOddSum = 0, twoEvenSum = 0;

            if (i > 0) {
                twoOddSum = odds[i] + odds[i - 1];
            }

            if (j > 0) {
                twoEvenSum = evens[j] + evens[j - 1];
            }

            if (twoOddSum == 0 && twoEvenSum == 0) {
                return 0;
            }

            if (twoOddSum > twoEvenSum) {
                score += twoOddSum;
                i -= 2;
            }
            else {
                score += twoEvenSum;
                j -= 2;
            }

            cnt -= 2;
        }

        return score;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> cards = { 1,2,8,9 };
    check.checkInt(18, o.maxmiumScore(cards, 3));

    cards = { 3,3,1 };
    check.checkInt(0, o.maxmiumScore(cards, 1));

    cards = { 1 };
    check.checkInt(0, o.maxmiumScore(cards, 1));

    cards = { 2 };
    check.checkInt(2, o.maxmiumScore(cards, 1));

    cards = { 14,6,8,4,4,3,12,12,14,13,7,12,13,12,15,9,19,14,10,2,16,1,19,18,18,2,17,3,15,1,3,19,19,15,8,11,1,12,6,20,18,8,16,19,3,18,5,12,9,8,2,7,1,13,20,11,6,13,13,3,7,1,13,1,18,18,15,12,18,11,7,18,9,19,17,4,20,9,7,5,14,19 };
    check.checkInt(892, o.maxmiumScore(cards, 80));
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
