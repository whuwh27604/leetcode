/* 大礼包.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在LeetCode商店中， 有许多在售的物品。

然而，也有一些大礼包，每个大礼包以优惠的价格捆绑销售一组物品。

现给定每个物品的价格，每个大礼包包含物品的清单，以及待购物品清单。请输出确切完成待购清单的最低花费。

每个大礼包的由一个数组中的一组数据描述，最后一个数字代表大礼包的价格，其他数字分别表示内含的其他种类物品的数量。

任意大礼包可无限次购买。

示例 1:

输入: [2,5], [[3,0,5],[1,2,10]], [3,2]
输出: 14
解释:
有A和B两种物品，价格分别为¥2和¥5。
大礼包1，你可以以¥5的价格购买3A和0B。
大礼包2， 你可以以¥10的价格购买1A和2B。
你需要购买3个A和2个B， 所以你付了¥10购买了1A和2B（大礼包2），以及¥4购买2A。
示例 2:

输入: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
输出: 11
解释:
A，B，C的价格分别为¥2，¥3，¥4.
你可以用¥4购买1A和1B，也可以用¥9购买2A，2B和1C。
你需要买1A，2B和1C，所以你付了¥4买了1A和1B（大礼包1），以及¥3购买1B， ¥4购买1C。
你不可以购买超出待购清单的物品，尽管购买大礼包2更加便宜。
说明:

最多6种物品， 100种大礼包。
每种物品，你最多只需要购买6个。
你不可以购买超出待购清单的物品，即使更便宜。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shopping-offers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<int, int> needsPrice;
        return shopping(price, special, needs, needsPrice);
    }

    int shopping(vector<int>& price, vector<vector<int>>& specials, vector<int>& needs, unordered_map<int, int>& needsPrice) {
        int key = hashKey(needs);
        auto iter = needsPrice.find(key);
        if (iter != needsPrice.end()) {
            return iter->second;
        }

        int i, items = price.size();
        int totalPrice, lowestPrice = 0;

        for (i = 0; i < items; i++) {
            lowestPrice += price[i] * needs[i];  // 单买的价格
        }

        for (vector<int>& special : specials) {
            vector<int> needsLeft = needs;

            for (i = 0; i < items; i++) {
                if (special[i] > needs[i]) {
                    break;
                }

                needsLeft[i] -= special[i];
            }

            if (i == items) {  // 可以使用套餐
                totalPrice = special[i] + shopping(price, specials, needsLeft, needsPrice);  // 套餐价加上剩下货物的价格
                lowestPrice = min(lowestPrice, totalPrice);
            }
        }

        needsPrice[key] = lowestPrice;
        return lowestPrice;
    }

    int hashKey(vector<int>& needs) {
        int key = 0;

        for (int need : needs) {
            key = key * 10 + need;
        }

        return key;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> price = { 2,5 };
    vector<vector<int>> special = { {3,0,5},{1,2,10} };
    vector<int> needs = { 3,2 };
    check.checkInt(14, o.shoppingOffers(price, special, needs));

    price = { 2,3,4 };
    special = { {1,1,0,4},{2,2,1,9} };
    needs = { 1,2,1 };
    check.checkInt(11, o.shoppingOffers(price, special, needs));

    price = { 2,3,4 };
    special = { {1,1,0,4},{2,2,1,9} };
    needs = { 0,0,0 };
    check.checkInt(0, o.shoppingOffers(price, special, needs));

    price = { 0,0,0 };
    special = { {1,1,0,4},{2,2,1,9} };
    needs = { 1,1,1 };
    check.checkInt(0, o.shoppingOffers(price, special, needs));
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
