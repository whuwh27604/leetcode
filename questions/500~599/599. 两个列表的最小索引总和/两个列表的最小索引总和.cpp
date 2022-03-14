/* 两个列表的最小索引总和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。

你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。

示例 1:

输入:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
输出: ["Shogun"]
解释: 他们唯一共同喜爱的餐厅是“Shogun”。
示例 2:

输入:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
输出: ["Shogun"]
解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
提示:

两个列表的长度范围都在 [1, 1000]内。
两个列表中的字符串的长度将在[1，30]的范围内。
下标从0开始，到列表的长度减1。
两个列表都没有重复的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-index-sum-of-two-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        if (list1.size() > list2.size()) {
            return findRestaurant(list2, list1);
        }

        unordered_map<string, int> nameIndices;
        int i, size1 = list1.size(), size2 = list2.size(), minIndexSum = INT_MAX;
        vector<string> restaurants;

        for (i = 0; i < size2; ++i) {
            nameIndices[list2[i]] = i;
        }

        for (i = 0; i < size1; ++i) {
            if (nameIndices.count(list1[i]) == 0) {
                continue;
            }

            int indexSum = (nameIndices[list1[i]] + i);

            if (indexSum < minIndexSum) {
                minIndexSum = indexSum;
                restaurants = { list1[i] };
            }
            else if (indexSum == minIndexSum) {
                restaurants.push_back(list1[i]);
            }
        }

        return restaurants;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> list1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
    vector<string> list2 = { "Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun" };
    vector<string> actual = o.findRestaurant(list1, list2);
    vector<string> expected = { "Shogun" };
    check.checkStringVector(expected, actual);

    list1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
    list2 = { "KFC", "Shogun", "Burger King" };
    actual = o.findRestaurant(list1, list2);
    expected = { "Shogun" };
    check.checkStringVector(expected, actual);

    list1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
    list2 = { "KFC", "Burger King", "Tapioca Express", "Shogun" };
    actual = o.findRestaurant(list1, list2);
    expected = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
    check.checkStringVector(expected, actual);

    list1 = { "Shogun" };
    list2 = { "Shogun" };
    actual = o.findRestaurant(list1, list2);
    expected = { "Shogun" };
    check.checkStringVector(expected, actual);
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
