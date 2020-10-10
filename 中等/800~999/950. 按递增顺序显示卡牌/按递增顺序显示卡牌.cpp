/* 按递增顺序显示卡牌.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
牌组中的每张卡牌都对应有一个唯一的整数。你可以按你想要的顺序对这套卡片进行排序。

最初，这些卡牌在牌组里是正面朝下的（即，未显示状态）。

现在，重复执行以下步骤，直到显示所有卡牌为止：

从牌组顶部抽一张牌，显示它，然后将其从牌组中移出。
如果牌组中仍有牌，则将下一张处于牌组顶部的牌放在牌组的底部。
如果仍有未显示的牌，那么返回步骤 1。否则，停止行动。
返回能以递增顺序显示卡牌的牌组顺序。

答案中的第一张牌被认为处于牌堆顶部。

 

示例：

输入：[17,13,11,2,3,5,7]
输出：[2,13,3,11,5,17,7]
解释：
我们得到的牌组顺序为 [17,13,11,2,3,5,7]（这个顺序不重要），然后将其重新排序。
重新排序后，牌组以 [2,13,3,11,5,17,7] 开始，其中 2 位于牌组的顶部。
我们显示 2，然后将 13 移到底部。牌组现在是 [3,11,5,17,7,13]。
我们显示 3，并将 11 移到底部。牌组现在是 [5,17,7,13,11]。
我们显示 5，然后将 17 移到底部。牌组现在是 [7,13,11,17]。
我们显示 7，并将 13 移到底部。牌组现在是 [11,17,13]。
我们显示 11，然后将 17 移到底部。牌组现在是 [13,17]。
我们展示 13，然后将 17 移到底部。牌组现在是 [17]。
我们显示 17。
由于所有卡片都是按递增顺序排列显示的，所以答案是正确的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reveal-cards-in-increasing-order
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <list>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        int i, size = deck.size();
        list<int> nums;

        for (i = size - 1; i > 0; --i) {
            nums.push_back(deck[i]);
            nums.push_back(nums.front());
            nums.pop_front();
        }

        nums.push_back(deck[0]);
        i = 0;

        for (auto iter = nums.rbegin(); iter != nums.rend(); ++iter) {
            deck[i++] = *iter;
        }

        return deck;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> deck = { 17,13,11,2,3,5,7 };
    vector<int> actual = o.deckRevealedIncreasing(deck);
    vector<int> expected = { 2,13,3,11,5,17,7 };
    check.checkIntVector(expected, actual);

    deck = { 1 };
    actual = o.deckRevealedIncreasing(deck);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    deck = { 2,1 };
    actual = o.deckRevealedIncreasing(deck);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    deck = { 3,2,1 };
    actual = o.deckRevealedIncreasing(deck);
    expected = { 1,3,2 };
    check.checkIntVector(expected, actual);

    deck = { 9,8,7,6,5,4,3,2,1 };
    actual = o.deckRevealedIncreasing(deck);
    expected = { 1,9,2,6,3,8,4,7,5 };
    check.checkIntVector(expected, actual);

    deck = { 10,9,8,7,6,5,4,3,2,1 };
    actual = o.deckRevealedIncreasing(deck);
    expected = { 1,6,2,10,3,7,4,9,5,8 };
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
