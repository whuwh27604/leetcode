/* 餐厅过滤器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个餐馆信息数组 restaurants，其中  restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]。你必须使用以下三个过滤器来过滤这些餐馆信息。

其中素食者友好过滤器 veganFriendly 的值可以为 true 或者 false，如果为 true 就意味着你应该只包括 veganFriendlyi 为 true 的餐馆，为 false 则意味着可以包括任何餐馆。此外，我们还有最大价格 maxPrice 和最大距离 maxDistance 两个过滤器，它们分别考虑餐厅的价格因素和距离因素的最大值。

过滤后返回餐馆的 id，按照 rating 从高到低排序。如果 rating 相同，那么按 id 从高到低排序。简单起见， veganFriendlyi 和 veganFriendly 为 true 时取值为 1，为 false 时，取值为 0 。

 

示例 1：

输入：restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 1, maxPrice = 50, maxDistance = 10
输出：[3,1,5]
解释：
这些餐馆为：
餐馆 1 [id=1, rating=4, veganFriendly=1, price=40, distance=10]
餐馆 2 [id=2, rating=8, veganFriendly=0, price=50, distance=5]
餐馆 3 [id=3, rating=8, veganFriendly=1, price=30, distance=4]
餐馆 4 [id=4, rating=10, veganFriendly=0, price=10, distance=3]
餐馆 5 [id=5, rating=1, veganFriendly=1, price=15, distance=1]
在按照 veganFriendly = 1, maxPrice = 50 和 maxDistance = 10 进行过滤后，我们得到了餐馆 3, 餐馆 1 和 餐馆 5（按评分从高到低排序）。
示例 2：

输入：restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 50, maxDistance = 10
输出：[4,3,2,1,5]
解释：餐馆与示例 1 相同，但在 veganFriendly = 0 的过滤条件下，应该考虑所有餐馆。
示例 3：

输入：restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 30, maxDistance = 3
输出：[4,5]
 

提示：

1 <= restaurants.length <= 10^4
restaurants[i].length == 5
1 <= idi, ratingi, pricei, distancei <= 10^5
1 <= maxPrice, maxDistance <= 10^5
veganFriendlyi 和 veganFriendly 的值为 0 或 1 。
所有 idi 各不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool pairSort(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second == p2.second ? p1.first > p2.first : p1.second > p2.second;
}

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>> matchedRestaurants;
        getMatchedRestaurants(restaurants, veganFriendly, maxPrice, maxDistance, matchedRestaurants);

        sort(matchedRestaurants.begin(), matchedRestaurants.end(), pairSort);

        int i, size = matchedRestaurants.size();
        vector<int> ans(size);

        for (i = 0; i < size; ++i) {
            ans[i] = matchedRestaurants[i].first;
        }

        return ans;
    }

    void getMatchedRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance, vector<pair<int, int>>& matchedRestaurants) {
        for (vector<int>& restaurant : restaurants) {
            if (restaurant[3] > maxPrice || restaurant[4] > maxDistance) {
                continue;
            }

            if (veganFriendly == 0 || (veganFriendly == 1 && restaurant[2] == 1)) {
                matchedRestaurants.push_back({ restaurant[0],restaurant[1] });
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> restaurants = { {1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1} };
    vector<int> actual = o.filterRestaurants(restaurants, 1, 50, 10);
    vector<int> expected = { 3,1,5 };
    check.checkIntVector(expected, actual);

    restaurants = { {1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1} };
    actual = o.filterRestaurants(restaurants, 0, 50, 10);
    expected = { 4,3,2,1,5 };
    check.checkIntVector(expected, actual);

    restaurants = { {1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1} };
    actual = o.filterRestaurants(restaurants, 0, 30, 3);
    expected = { 4,5 };
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
