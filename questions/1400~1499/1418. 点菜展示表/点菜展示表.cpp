/* 点菜展示表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 orders，表示客户在餐厅中完成的订单，确切地说， orders[i]=[customerNamei,tableNumberi,foodItemi] ，其中 customerNamei 是客户的姓名，tableNumberi 是客户所在餐桌的桌号，而 foodItemi 是客户点的餐品名称。

请你返回该餐厅的 点菜展示表 。在这张表中，表中第一行为标题，其第一列为餐桌桌号 “Table” ，后面每一列都是按字母顺序排列的餐品名称。接下来每一行中的项则表示每张餐桌订购的相应餐品数量，第一列应当填对应的桌号，后面依次填写下单的餐品数量。

注意：客户姓名不是点菜展示表的一部分。此外，表中的数据行应该按餐桌桌号升序排列。

 

示例 1：

输入：orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]
输出：[["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]]
解释：
点菜展示表如下所示：
Table,Beef Burrito,Ceviche,Fried Chicken,Water
3    ,0           ,2      ,1            ,0
5    ,0           ,1      ,0            ,1
10   ,1           ,0      ,0            ,0
对于餐桌 3：David 点了 "Ceviche" 和 "Fried Chicken"，而 Rous 点了 "Ceviche"
而餐桌 5：Carla 点了 "Water" 和 "Ceviche"
餐桌 10：Corina 点了 "Beef Burrito"
示例 2：

输入：orders = [["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],["Amadeus","12","Fried Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]
输出：[["Table","Canadian Waffles","Fried Chicken"],["1","2","0"],["12","0","3"]]
解释：
对于餐桌 1：Adam 和 Brianna 都点了 "Canadian Waffles"
而餐桌 12：James, Ratesh 和 Amadeus 都点了 "Fried Chicken"
示例 3：

输入：orders = [["Laura","2","Bean Burrito"],["Jhon","2","Beef Burrito"],["Melissa","2","Soda"]]
输出：[["Table","Bean Burrito","Beef Burrito","Soda"],["2","1","1","1"]]
 

提示：

1 <= orders.length <= 5 * 10^4
orders[i].length == 3
1 <= customerNamei.length, foodItemi.length <= 20
customerNamei 和 foodItemi 由大小写英文字母及空格字符 ' ' 组成。
tableNumberi 是 1 到 500 范围内的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/display-table-of-food-orders-in-a-restaurant
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> foods;
        set<int> tables;
        unordered_map<int, unordered_map<string, int>> foodsCount;
        vector<vector<string>> displayTab = { {"Table"} };

        countFoods(orders, tables, foods, foodsCount);
        displayTableHead(foods, displayTab);
        displayTableFoods(tables, foods, foodsCount, displayTab);

        return displayTab;
    }

    void countFoods(vector<vector<string>>& orders, set<int>& tables, set<string>& foods, unordered_map<int, unordered_map<string, int>>& foodsCount) {
        for (auto& order : orders) {
            int table = stoi(order[1]);
            tables.insert(table);
            foods.insert(order[2]);
            ++foodsCount[table][order[2]];
        }
    }

    void displayTableHead(set<string>& foods, vector<vector<string>>& displayTab) {
        for (auto iter = foods.begin(); iter != foods.end(); ++iter) {
            displayTab[0].push_back(*iter);
        }
    }

    void displayTableFoods(set<int>& tables, set<string>& foods, unordered_map<int, unordered_map<string, int>>& foodsCount, vector<vector<string>>& displayTab) {
        for (auto itTable = tables.begin(); itTable != tables.end(); ++itTable) {
            displayTab.push_back({ to_string(*itTable) });

            for (auto itFood = foods.begin(); itFood != foods.end(); ++itFood) {
                if (foodsCount[*itTable].count(*itFood) == 0) {
                    displayTab.back().push_back("0");
                }
                else {
                    displayTab.back().push_back(to_string(foodsCount[*itTable][*itFood]));
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<string>> orders = { {"David","3","Ceviche"},{"Corina","10","Beef Burrito"},{"David","3","Fried Chicken"},{"Carla","5","Water"},{"Carla","5","Ceviche"},{"Rous","3","Ceviche"} };
    vector<vector<string>> actual = o.displayTable(orders);
    vector<vector<string>> expected = { {"Table","Beef Burrito","Ceviche","Fried Chicken","Water"},{"3","0","2","1","0"},{"5","0","1","0","1"},{"10","1","0","0","0"} };
    check.checkStringVectorVector(expected,actual);

    orders = { {"James","12","Fried Chicken"},{"Ratesh","12","Fried Chicken"},{"Amadeus","12","Fried Chicken"},{"Adam","1","Canadian Waffles"},{"Brianna","1","Canadian Waffles"} };
    actual = o.displayTable(orders);
    expected = { {"Table","Canadian Waffles","Fried Chicken"},{"1","2","0"},{"12","0","3"} };
    check.checkStringVectorVector(expected,actual);

    orders = { {"Laura","2","Bean Burrito"},{"Jhon","2","Beef Burrito"},{"Melissa","2","Soda"} };
    actual = o.displayTable(orders);
    expected = { {"Table","Bean Burrito","Beef Burrito","Soda"},{"2","1","1","1"} };
    check.checkStringVectorVector(expected,actual);
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
