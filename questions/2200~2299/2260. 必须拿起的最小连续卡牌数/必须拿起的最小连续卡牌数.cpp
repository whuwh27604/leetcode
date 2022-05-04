/* 必须拿起的最小连续卡牌数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 cards ，其中 cards[i] 表示第 i 张卡牌的 值 。如果两张卡牌的值相同，则认为这一对卡牌 匹配 。

返回你必须拿起的最小连续卡牌数，以使在拿起的卡牌中有一对匹配的卡牌。如果无法得到一对匹配的卡牌，返回 -1 。

 

示例 1：

输入：cards = [3,4,2,3,4,7]
输出：4
解释：拿起卡牌 [3,4,2,3] 将会包含一对值为 3 的匹配卡牌。注意，拿起 [4,2,3,4] 也是最优方案。
示例 2：

输入：cards = [1,0,5,3]
输出：-1
解释：无法找出含一对匹配卡牌的一组连续卡牌。
 

提示：

1 <= cards.length <= 105
0 <= cards[i] <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-consecutive-cards-to-pick-up
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> indices;
        int minPickup = INT_MAX;

        for (int i = 0; i < (int)cards.size(); ++i) {
            int card = cards[i];

            if (indices.count(card) != 0) {
                minPickup = min(minPickup, i - indices[card] + 1);
            }

            indices[card] = i;
        }

        return minPickup == INT_MAX ? -1 : minPickup;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> cards = { 3,4,2,3,4,7 };
    check.checkInt(4, o.minimumCardPickup(cards));

    cards = { 1,0,5,3 };
    check.checkInt(-1, o.minimumCardPickup(cards));

    cards = { 1 };
    check.checkInt(-1, o.minimumCardPickup(cards));

    cards = { 1,1 };
    check.checkInt(2, o.minimumCardPickup(cards));
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
