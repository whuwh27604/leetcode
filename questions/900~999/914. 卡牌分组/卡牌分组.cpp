/* 卡牌分组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一副牌，每张牌上都写着一个整数。

此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：

每组都有 X 张牌。
组内所有的牌上都写着相同的整数。
仅当你可选的 X >= 2 时返回 true。

 

示例 1：

输入：[1,2,3,4,4,3,2,1]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
示例 2：

输入：[1,1,1,2,2,2,3,3]
输出：false
解释：没有满足要求的分组。
示例 3：

输入：[1]
输出：false
解释：没有满足要求的分组。
示例 4：

输入：[1,1]
输出：true
解释：可行的分组是 [1,1]
示例 5：

输入：[1,1,2,2,2,2]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[2,2]

提示：

1 <= deck.length <= 10000
0 <= deck[i] < 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> numbersCount;

        for (unsigned int i = 0; i < deck.size(); i++) {
            auto iter = numbersCount.find(deck[i]);
            if (iter == numbersCount.end()) {
                numbersCount[deck[i]] = 1;
            }
            else {
                iter->second++;
            }
        }

        int X = deck.size();
        for (auto iter = numbersCount.begin(); iter != numbersCount.end(); iter++) {
            X = gcd(X, iter->second);
            if (X == 1) {
                return false;
            }
        }

        return true;
    }

    int gcd(int x, int y) {
        return (x == 0) ? y : gcd(y % x, x);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> deck = { 1,2,3,4,4,3,2,1 };
    check.checkBool(true, o.hasGroupsSizeX(deck));
    
    deck = { 1,1,1,2,2,2,3,3 };
    check.checkBool(false, o.hasGroupsSizeX(deck));

    deck = { 1 };
    check.checkBool(false, o.hasGroupsSizeX(deck));

    deck = { 1,2 };
    check.checkBool(false, o.hasGroupsSizeX(deck));

    deck = { 1,1 };
    check.checkBool(true, o.hasGroupsSizeX(deck));

    deck = { 1,1,2,2,2,2 };
    check.checkBool(true, o.hasGroupsSizeX(deck));
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
