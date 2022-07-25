/* 最好的扑克手牌.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 ranks 和一个字符数组 suit 。你有 5 张扑克牌，第 i 张牌大小为 ranks[i] ，花色为 suits[i] 。

下述是从好到坏你可能持有的 手牌类型 ：

"Flush"：同花，五张相同花色的扑克牌。
"Three of a Kind"：三条，有 3 张大小相同的扑克牌。
"Pair"：对子，两张大小一样的扑克牌。
"High Card"：高牌，五张大小互不相同的扑克牌。
请你返回一个字符串，表示给定的 5 张牌中，你能组成的 最好手牌类型 。

注意：返回的字符串 大小写 需与题目描述相同。

 

示例 1：

输入：ranks = [13,2,3,1,9], suits = ["a","a","a","a","a"]
输出："Flush"
解释：5 张扑克牌的花色相同，所以返回 "Flush" 。
示例 2：

输入：ranks = [4,4,2,4,4], suits = ["d","a","a","b","c"]
输出："Three of a Kind"
解释：第一、二和四张牌组成三张相同大小的扑克牌，所以得到 "Three of a Kind" 。
注意我们也可以得到 "Pair" ，但是 "Three of a Kind" 是更好的手牌类型。
有其他的 3 张牌也可以组成 "Three of a Kind" 手牌类型。
示例 3：

输入：ranks = [10,10,2,12,9], suits = ["a","b","c","a","d"]
输出："Pair"
解释：第一和第二张牌大小相同，所以得到 "Pair" 。
我们无法得到 "Flush" 或者 "Three of a Kind" 。
 

提示：

ranks.length == suits.length == 5
1 <= ranks[i] <= 13
'a' <= suits[i] <= 'd'
任意两张扑克牌不会同时有相同的大小和花色。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/best-poker-hand
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if (suits[0] == suits[1] && suits[0] == suits[2] && suits[0] == suits[3] && suits[0] == suits[4]) {
            return "Flush";
        }

        vector<int> counts(14, 0);

        for (int rank : ranks) {
            ++counts[rank];
        }

        for (int count : counts) {
            if (count >= 3) {
                return "Three of a Kind";
            }
        }

        for (int count : counts) {
            if (count == 2) {
                return "Pair";
            }
        }

        return "High Card";
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> ranks = { 13,2,3,1,9 };
    vector<char> suits = { 'a','a','a','a','a' };
    check.checkString("Flush", o.bestHand(ranks, suits));

    ranks = { 4,4,2,4,4 };
    suits = { 'd','a','a','b','c' };
    check.checkString("Three of a Kind", o.bestHand(ranks, suits));

    ranks = { 10,10,2,12,9 };
    suits = { 'a','b','c','a','d' };
    check.checkString("Pair", o.bestHand(ranks, suits));
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
