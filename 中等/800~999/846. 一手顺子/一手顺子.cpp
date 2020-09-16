/* 一手顺子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
爱丽丝有一手（hand）由整数数组给定的牌。 

现在她想把牌重新排列成组，使得每个组的大小都是 W，且由 W 张连续的牌组成。

如果她可以完成分组就返回 true，否则返回 false。

 

示例 1：

输入：hand = [1,2,3,6,2,3,4,7,8], W = 3
输出：true
解释：爱丽丝的手牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。
示例 2：

输入：hand = [1,2,3,4,5], W = 4
输出：false
解释：爱丽丝的手牌无法被重新排列成几个大小为 4 的组。
 

提示：

1 <= hand.length <= 10000
0 <= hand[i] <= 10^9
1 <= W <= hand.length
 

注意：此题目与 1294 重复：https://leetcode-cn.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/hand-of-straights
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        unordered_map<int, int> cards;
        countCards(hand, cards);

        map<int, int> ordered_cards;
        sortCards(cards, ordered_cards);

        while (!ordered_cards.empty()) {
            auto iter = ordered_cards.begin();
            int card = iter->first;
            int num = iter->second;

            for (int i = 0; i < W; i++) {
                if (iter == ordered_cards.end()) {
                    return false;
                }

                if ((iter->first != card + i) || (iter->second < num)) {
                    return false;
                }

                iter->second -= num;
                if (iter->second == 0) {
                    iter = ordered_cards.erase(iter);
                }
                else {
                    ++iter;
                }
            }
        }

        return true;
    }

    void countCards(vector<int>& hand, unordered_map<int, int>& cards) {
        for (int card : hand) {
            auto iter = cards.find(card);
            if (iter == cards.end()) {
                cards[card] = 1;
            }
            else {
                iter->second++;
            }
        }
    }

    void sortCards(unordered_map<int, int>& cards, map<int, int>& ordered_cards) {
        for (auto iter = cards.begin(); iter != cards.end(); ++iter) {
            ordered_cards[iter->first] = iter->second;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> hand = { 1,2,3,6,2,3,4,7,8 };
    check.checkBool(true, o.isNStraightHand(hand, 3));

    hand = { 1,2,3,4,5 };
    check.checkBool(true, o.isNStraightHand(hand, 5));

    hand = { 1,2,3,4,5 };
    check.checkBool(false, o.isNStraightHand(hand, 4));

    hand = { 5 };
    check.checkBool(true, o.isNStraightHand(hand, 1));

    hand = { 5 };
    check.checkBool(false, o.isNStraightHand(hand, 2));

    hand = { 5,1 };
    check.checkBool(true, o.isNStraightHand(hand, 1));

    hand = { 5,1 };
    check.checkBool(false, o.isNStraightHand(hand, 2));
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
