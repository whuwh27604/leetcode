/* 查询无效交易.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果出现下述两种情况，交易 可能无效：

交易金额超过 ¥1000
或者，它和另一个城市中同名的另一笔交易相隔不超过 60 分钟（包含 60 分钟整）
每个交易字符串 transactions[i] 由一些用逗号分隔的值组成，这些值分别表示交易的名称，时间（以分钟计），金额以及城市。

给你一份交易清单 transactions，返回可能无效的交易列表。你可以按任何顺序返回答案。

 

示例 1：

输入：transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
输出：["alice,20,800,mtv","alice,50,100,beijing"]
解释：第一笔交易是无效的，因为第二笔交易和它间隔不超过 60 分钟、名称相同且发生在不同的城市。同样，第二笔交易也是无效的。
示例 2：

输入：transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
输出：["alice,50,1200,mtv"]
示例 3：

输入：transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
输出：["bob,50,1200,mtv"]
 

提示：

transactions.length <= 1000
每笔交易 transactions[i] 按 "{name},{time},{amount},{city}" 的格式进行记录
每个交易名称 {name} 和城市 {city} 都由小写英文字母组成，长度在 1 到 10 之间
每个交易时间 {time} 由一些数字组成，表示一个 0 到 1000 之间的整数
每笔交易金额 {amount} 由一些数字组成，表示一个 0 到 2000 之间的整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/invalid-transactions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

struct TransInfo {
    int index;
    int amount;
    string city;
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, multimap<int, TransInfo>> personalTransactions;
        getPersonalTransactions(transactions, personalTransactions);

        vector<string> invalidTrans;
        for (auto iter = personalTransactions.begin(); iter != personalTransactions.end(); ++iter) {
            findInvalid(iter->second, transactions, invalidTrans);
        }

        return invalidTrans;
    }

    void findInvalid(multimap<int, TransInfo>& personalTransactions, vector<string>& transactions, vector<string>& invalidTrans) {
        unordered_map<string, int> cities;
        unordered_set<int> invalidIndices;
        auto itLeft = personalTransactions.begin(), itRight = personalTransactions.begin(), itNextInvalid = personalTransactions.begin();

        for (; itRight != personalTransactions.end(); ++itRight) {
            ++cities[itRight->second.city];

            for (; itRight->first - itLeft->first > 60; ++itLeft) {
                --cities[itLeft->second.city];
                if (cities[itLeft->second.city] == 0) {
                    cities.erase(itLeft->second.city);
                }
            }

            if (cities.size() != 1) {
                auto it = (itLeft->first > itNextInvalid->first) ? itLeft : itNextInvalid;
                itNextInvalid = itRight;
                ++itNextInvalid;

                for (; it != itNextInvalid; ++it) {
                    if (invalidIndices.count(it->second.index) == 0) {
                        invalidTrans.push_back(transactions[it->second.index]);
                        invalidIndices.insert(it->second.index);
                    }
                }
            }

            if (itRight->second.amount > 1000 && (invalidIndices.count(itRight->second.index) == 0)) {
                invalidTrans.push_back(transactions[itRight->second.index]);
                invalidIndices.insert(itRight->second.index);
            }
        }
    }

    void getPersonalTransactions(vector<string>& transactions, unordered_map<string, multimap<int, TransInfo>>& personalTransactions) {
        for (int i = 0; i < (int)transactions.size(); ++i) {
            string name, city;
            int time, amount;

            parse(transactions[i], name, time, amount, city);
            personalTransactions[name].insert({ time, {i, amount, city} });
        }
    }

    void parse(string& transaction, string& name, int& time, int& amount, string& city) {
        int start = 0, position = transaction.find(',');
        name.append(transaction, start, position);

        start = position + 1;
        position = transaction.find(',', start);
        string timeStr(transaction, start, position - start);
        time = stoi(timeStr);

        start = position + 1;
        position = transaction.find(',', start);
        string amountStr(transaction, start, position - start);
        amount = stoi(amountStr);

        start = position + 1;
        city.append(transaction, start, transaction.size() - start);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> transactions = { "alice,20,800,mtv","alice,50,100,beijing" };
    vector<string> actual = o.invalidTransactions(transactions);
    vector<string> expected = { "alice,20,800,mtv","alice,50,100,beijing" };
    check.checkStringVector(expected, actual);

    transactions = { "alice,20,800,mtv","alice,50,1200,mtv" };
    actual = o.invalidTransactions(transactions);
    expected = { "alice,50,1200,mtv" };
    check.checkStringVector(expected, actual);

    transactions = { "alice,20,800,mtv","alice,50,1000,mtv" };
    actual = o.invalidTransactions(transactions);
    expected = {  };
    check.checkStringVector(expected, actual);

    transactions = { "lee,953,12,toronto","lee,953,12,toronto" };
    actual = o.invalidTransactions(transactions);
    expected = {  };
    check.checkStringVector(expected, actual);

    transactions = { "lee,953,12,toronto","lee,953,12,mtv" };
    actual = o.invalidTransactions(transactions);
    expected = { "lee,953,12,toronto","lee,953,12,mtv" };
    check.checkStringVector(expected, actual);

    transactions = { "alice,20,800,mtv","bob,50,1200,mtv" };
    actual = o.invalidTransactions(transactions);
    expected = { "bob,50,1200,mtv" };
    check.checkStringVector(expected, actual);

    transactions = { "alice,20,800,mtv","alice,50,100,beijing","alice,60,100,mtv" };
    actual = o.invalidTransactions(transactions);
    expected = { "alice,20,800,mtv","alice,50,100,beijing","alice,60,100,mtv" };
    check.checkStringVector(expected, actual);

    transactions = { "bob,689,1910,barcelona","alex,696,122,bangkok","bob,832,1726,barcelona","bob,820,596,bangkok","chalicefy,217,669,barcelona","bob,175,221,amsterdam" };
    actual = o.invalidTransactions(transactions);
    expected = { "bob,689,1910,barcelona","bob,820,596,bangkok","bob,832,1726,barcelona" };
    check.checkStringVector(expected, actual);

    transactions = { "bob,627,1973,amsterdam","alex,387,885,bangkok","alex,355,1029,barcelona","alex,587,402,bangkok","chalicefy,973,830,barcelona","alex,932,86,bangkok","bob,188,989,amsterdam" };
    actual = o.invalidTransactions(transactions);
    expected = { "bob,627,1973,amsterdam","alex,355,1029,barcelona","alex,387,885,bangkok" };
    check.checkStringVector(expected, actual);

    transactions = { "maybe,850,824,budapest","maybe,549,988,moscow","maybe,716,1727,shenzhen","maybe,511,1002,toronto","maybe,838,585,amsterdam","maybe,502,530,barcelona","maybe,313,1394,madrid","maybe,406,659,shenzhen","maybe,162,406,mexico","maybe,358,774,istanbul","maybe,237,71,bangkok","maybe,129,1999,frankfurt" };
    actual = o.invalidTransactions(transactions);
    expected = { "maybe,850,824,budapest","maybe,549,988,moscow","maybe,716,1727,shenzhen","maybe,511,1002,toronto","maybe,838,585,amsterdam","maybe,502,530,barcelona","maybe,313,1394,madrid","maybe,406,659,shenzhen","maybe,162,406,mexico","maybe,358,774,istanbul","maybe,129,1999,frankfurt" };
    check.checkStringVectorRandomOrder(expected, actual);

    transactions = { "bob,899,1971,budapest","bob,381,1136,tokyo","bob,486,1751,barcelona","bob,536,217,toronto","bob,725,501,prague","bob,674,193,dubai","bob,456,6,luxembourg","bob,110,73,frankfurt","bob,487,260,bangkok","bob,880,628,hongkong","bob,262,120,hongkong","bob,257,803,mexico","bob,365,899,shanghai","bob,255,747,taipei","bob,744,401,guangzhou" };
    actual = o.invalidTransactions(transactions);
    expected = { "bob,899,1971,budapest","bob,381,1136,tokyo","bob,486,1751,barcelona","bob,536,217,toronto","bob,725,501,prague","bob,674,193,dubai","bob,456,6,luxembourg","bob,487,260,bangkok","bob,880,628,hongkong","bob,262,120,hongkong","bob,257,803,mexico","bob,365,899,shanghai","bob,255,747,taipei","bob,744,401,guangzhou" };
    check.checkStringVectorRandomOrder(expected, actual);

    transactions = { "alex,505,187,tokyo","alex,622,61,frankfurt","alex,28,1683,singapore","alex,957,466,munich","alex,496,1662,luxemburg","alex,481,35,frankfurt","alex,160,651,amsterdam","alex,290,770,tokyo","alex,929,591,taipei","alex,534,96,jakarta","alex,756,1473,hongkong","alex,54,1760,singapore","alex,759,31,barcelona","alex,353,1074,prague","alex,284,877,toronto","alex,168,1279,shenzhen","alex,348,1434,rome" };
    actual = o.invalidTransactions(transactions);
    expected = { "alex,505,187,tokyo","alex,28,1683,singapore","alex,957,466,munich","alex,496,1662,luxemburg","alex,481,35,frankfurt","alex,160,651,amsterdam","alex,290,770,tokyo","alex,929,591,taipei","alex,534,96,jakarta","alex,756,1473,hongkong","alex,54,1760,singapore","alex,759,31,barcelona","alex,353,1074,prague","alex,284,877,toronto","alex,168,1279,shenzhen","alex,348,1434,rome" };
    check.checkStringVectorRandomOrder(expected, actual);

    transactions = { "lee,953,1572,toronto","lee,191,1261,madrid","lee,353,1522,shanghai","lee,95,1916,madrid","lee,806,1597,chicago","lee,124,1012,tokyo","lee,493,1002,warsaw","lee,353,475,zurich","lee,973,1591,munich","lee,854,604,chicago","lee,354,140,warsaw","lee,827,521,prague","lee,115,531,rome","lee,532,712,hongkong","lee,766,616,newdelhi","lee,231,1150,zurich","lee,520,1825,montreal","lee,884,881,luxembourg" };
    actual = o.invalidTransactions(transactions);
    expected = { "lee,953,1572,toronto","lee,191,1261,madrid","lee,353,1522,shanghai","lee,95,1916,madrid","lee,806,1597,chicago","lee,124,1012,tokyo","lee,493,1002,warsaw","lee,353,475,zurich","lee,973,1591,munich","lee,854,604,chicago","lee,354,140,warsaw","lee,827,521,prague","lee,115,531,rome","lee,532,712,hongkong","lee,766,616,newdelhi","lee,231,1150,zurich","lee,520,1825,montreal","lee,884,881,luxembourg" };
    check.checkStringVectorRandomOrder(expected, actual);

    transactions = { "bob,899,1971,budapest","maybe,850,824,budapest","alex,505,187,tokyo","lee,953,1572,toronto","alex,622,61,frankfurt","lee,191,1261,madrid","iris,740,925,luxembourg","iris,681,401,moscow","chalicefy,298,731,madrid","maybe,549,988,moscow","alex,28,1683,singapore","chalicefy,894,550,rome","xnova,892,990,rome","lee,353,1522,shanghai","xnova,804,549,taipei","maybe,716,1727,shenzhen","chalicefy,770,1156,taipei","alex,957,466,munich","bob,381,1136,tokyo","alex,496,1662,luxembourg","xnova,849,354,munich","bob,486,1751,barcelona","xnova,350,14,moscow","iris,858,583,chicago","maybe,511,1002,toronto","maybe,838,585,amsterdam","bob,536,217,toronto","iris,24,1596,hongkong","chalicefy,894,1074,beijing","maybe,502,530,barcelona","lee,95,1916,madrid","maybe,313,1394,madrid","chalicefy,160,1591,hongkong","xnova,280,1023,tokyo","chalicefy,224,920,singapore","bob,725,501,prague","alex,481,35,frankfurt","xnova,336,423,guangzhou","xnova,535,382,istanbul","lee,806,1597,chicago","lee,124,1012,tokyo","iris,627,665,shenzhen","alex,160,651,amsterdam","bob,674,193,dubai","alex,290,770,tokyo","maybe,406,659,shenzhen","lee,493,1002,warsaw","alex,929,591,taipei","bob,456,6,luxembourg","iris,985,1959,newdelhi","xnova,816,1147,singapore","bob,110,73,frankfurt","chalicefy,80,85,warsaw","xnova,266,162,munich","xnova,295,1944,newdelhi","chalicefy,47,141,madrid","xnova,78,205,shanghai","bob,487,260,bangkok","bob,880,628,hongkong","maybe,162,406,mexico","xnova,390,1187,hongkong","chalicefy,810,289,zurich","alex,534,96,jakarta","chalicefy,768,1412,moscow","chalicefy,594,840,milan","xnova,844,1048,luxembourg","xnova,15,274,tokyo","alex,756,1473,hongkong","alex,54,1760,singapore","xnova,353,1644,zurich","lee,353,475,zurich","lee,973,1591,munich","bob,262,120,hongkong","alex,759,31,barcelona","bob,257,803,mexico","alex,353,1074,prague","lee,854,604,chicago","lee,354,140,warsaw","lee,827,521,prague","chalicefy,73,439,zurich","bob,365,899,shanghai","chalicefy,490,1473,beijing","lee,115,531,rome","maybe,358,774,istanbul","xnova,95,824,frankfurt","lee,532,712,hongkong","lee,766,616,newdelhi","lee,231,1150,zurich","maybe,237,71,bangkok","bob,255,747,taipei","lee,520,1825,montreal","bob,744,401,guangzhou","alex,284,877,toronto","maybe,129,1999,frankfurt","xnova,293,294,jakarta","chalicefy,283,901,beijing","lee,884,881,luxembourg","alex,168,1279,shenzhen","alex,348,1434,rome","iris,958,537,paris" };
    actual = o.invalidTransactions(transactions);
    expected = { "alex,160,651,amsterdam","alex,168,1279,shenzhen","alex,28,1683,singapore","alex,284,877,toronto","alex,290,770,tokyo","alex,348,1434,rome","alex,353,1074,prague","alex,481,35,frankfurt","alex,496,1662,luxembourg","alex,505,187,tokyo","alex,534,96,jakarta","alex,54,1760,singapore","alex,756,1473,hongkong","alex,759,31,barcelona","alex,929,591,taipei","alex,957,466,munich","bob,255,747,taipei","bob,257,803,mexico","bob,262,120,hongkong","bob,365,899,shanghai","bob,381,1136,tokyo","bob,456,6,luxembourg","bob,486,1751,barcelona","bob,487,260,bangkok","bob,536,217,toronto","bob,674,193,dubai","bob,725,501,prague","bob,744,401,guangzhou","bob,880,628,hongkong","bob,899,1971,budapest","chalicefy,160,1591,hongkong","chalicefy,224,920,singapore","chalicefy,283,901,beijing","chalicefy,298,731,madrid","chalicefy,47,141,madrid","chalicefy,490,1473,beijing","chalicefy,73,439,zurich","chalicefy,768,1412,moscow","chalicefy,770,1156,taipei","chalicefy,80,85,warsaw","chalicefy,810,289,zurich","chalicefy,894,1074,beijing","chalicefy,894,550,rome","iris,24,1596,hongkong","iris,627,665,shenzhen","iris,681,401,moscow","iris,740,925,luxembourg","iris,958,537,paris","iris,985,1959,newdelhi","lee,115,531,rome","lee,124,1012,tokyo","lee,191,1261,madrid","lee,231,1150,zurich","lee,353,1522,shanghai","lee,353,475,zurich","lee,354,140,warsaw","lee,493,1002,warsaw","lee,520,1825,montreal","lee,532,712,hongkong","lee,766,616,newdelhi","lee,806,1597,chicago","lee,827,521,prague","lee,854,604,chicago","lee,884,881,luxembourg","lee,95,1916,madrid","lee,953,1572,toronto","lee,973,1591,munich","maybe,129,1999,frankfurt","maybe,162,406,mexico","maybe,313,1394,madrid","maybe,358,774,istanbul","maybe,406,659,shenzhen","maybe,502,530,barcelona","maybe,511,1002,toronto","maybe,549,988,moscow","maybe,716,1727,shenzhen","maybe,838,585,amsterdam","maybe,850,824,budapest","xnova,266,162,munich","xnova,280,1023,tokyo","xnova,293,294,jakarta","xnova,295,1944,newdelhi","xnova,336,423,guangzhou","xnova,350,14,moscow","xnova,353,1644,zurich","xnova,390,1187,hongkong","xnova,78,205,shanghai","xnova,804,549,taipei","xnova,816,1147,singapore","xnova,844,1048,luxembourg","xnova,849,354,munich","xnova,892,990,rome","xnova,95,824,frankfurt" };
    check.checkStringVectorRandomOrder(expected, actual);
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
