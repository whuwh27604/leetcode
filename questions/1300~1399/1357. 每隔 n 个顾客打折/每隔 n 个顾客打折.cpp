/* 每隔 n 个顾客打折.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
超市里正在举行打折活动，每隔 n 个顾客会得到 discount 的折扣。

超市里有一些商品，第 i 种商品为 products[i] 且每件单品的价格为 prices[i] 。

结账系统会统计顾客的数目，每隔 n 个顾客结账时，该顾客的账单都会打折，折扣为 discount （也就是如果原本账单为 x ，那么实际金额会变成 x - (discount * x) / 100 ），然后系统会重新开始计数。

顾客会购买一些商品， product[i] 是顾客购买的第 i 种商品， amount[i] 是对应的购买该种商品的数目。

请你实现 Cashier 类：

Cashier(int n, int discount, int[] products, int[] prices) 初始化实例对象，参数分别为打折频率 n ，折扣大小 discount ，超市里的商品列表 products 和它们的价格 prices 。
double getBill(int[] product, int[] amount) 返回账单的实际金额（如果有打折，请返回打折后的结果）。返回结果与标准答案误差在 10^-5 以内都视为正确结果。
 

示例 1：

输入
["Cashier","getBill","getBill","getBill","getBill","getBill","getBill","getBill"]
[[3,50,[1,2,3,4,5,6,7],[100,200,300,400,300,200,100]],[[1,2],[1,2]],[[3,7],[10,10]],[[1,2,3,4,5,6,7],[1,1,1,1,1,1,1]],[[4],[10]],[[7,3],[10,10]],[[7,5,3,1,6,4,2],[10,10,10,9,9,9,7]],[[2,3,5],[5,3,2]]]
输出
[null,500.0,4000.0,800.0,4000.0,4000.0,7350.0,2500.0]
解释
Cashier cashier = new Cashier(3,50,[1,2,3,4,5,6,7],[100,200,300,400,300,200,100]);
cashier.getBill([1,2],[1,2]);                        // 返回 500.0, 账单金额为 = 1 * 100 + 2 * 200 = 500.
cashier.getBill([3,7],[10,10]);                      // 返回 4000.0
cashier.getBill([1,2,3,4,5,6,7],[1,1,1,1,1,1,1]);    // 返回 800.0 ，账单原本为 1600.0 ，但由于该顾客是第三位顾客，他将得到 50% 的折扣，所以实际金额为 1600 - 1600 * (50 / 100) = 800 。
cashier.getBill([4],[10]);                           // 返回 4000.0
cashier.getBill([7,3],[10,10]);                      // 返回 4000.0
cashier.getBill([7,5,3,1,6,4,2],[10,10,10,9,9,9,7]); // 返回 7350.0 ，账单原本为 14700.0 ，但由于系统计数再次达到三，该顾客将得到 50% 的折扣，实际金额为 7350.0 。
cashier.getBill([2,3,5],[5,3,2]);                    // 返回 2500.0
 

提示：

1 <= n <= 10^4
0 <= discount <= 100
1 <= products.length <= 200
1 <= products[i] <= 200
products 列表中 不会 有重复的元素。
prices.length == products.length
1 <= prices[i] <= 1000
1 <= product.length <= products.length
product[i] 在 products 出现过。
amount.length == product.length
1 <= amount[i] <= 1000
最多有 1000 次对 getBill 函数的调用。
返回结果与标准答案误差在 10^-5 以内都视为正确结果。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/apply-discount-every-n-orders
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        interval = n;
        custom = 0;
        rate = 1 - (double)discount / 100;

        for (unsigned int i = 0; i < products.size(); ++i) {
            productPrices[products[i]] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
        double bill = 0;

        for (unsigned int i = 0; i < product.size(); ++i) {
            bill += ((double)productPrices[product[i]] * amount[i]);
        }

        if (++custom % interval == 0) {
            bill *= rate;
        }

        return bill;
    }

private:
    int interval;
    int custom;
    double rate;
    unordered_map<int, int> productPrices;
};

int main()
{
    CheckResult check;

    vector<int> products = { 1,2,3,4,5,6,7 };
    vector<int> prices = { 100,200,300,400,300,200,100 };
    Cashier o1(3,50, products, prices);
    vector<int> product = { 1,2 };
    vector<int> amount = { 1,2 };
    check.checkDouble(500, o1.getBill(product, amount));
    product = { 3,7 };
    amount = { 10,10 };
    check.checkDouble(4000, o1.getBill(product, amount));
    product = { 1,2,3,4,5,6,7 };
    amount = { 1,1,1,1,1,1,1 };
    check.checkDouble(800, o1.getBill(product, amount));
    product = { 4 };
    amount = { 10 };
    check.checkDouble(4000, o1.getBill(product, amount));
    product = { 7,3 };
    amount = { 10,10 };
    check.checkDouble(4000, o1.getBill(product, amount));
    product = { 7,5,3,1,6,4,2 };
    amount = { 10,10,10,9,9,9,7 };
    check.checkDouble(7350, o1.getBill(product, amount));
    product = { 2,3,5 };
    amount = { 5,3,2 };
    check.checkDouble(2500, o1.getBill(product, amount));

    products = { 1,2,3,4,5,6,7 };
    prices = { 101,201,301,401,301,201,101 };
    Cashier o2(3, 50, products, prices);
    product = { 1,2 };
    amount = { 1,2 };
    check.checkDouble(503, o2.getBill(product, amount));
    product = { 3,7 };
    amount = { 10,10 };
    check.checkDouble(4020, o2.getBill(product, amount));
    product = { 1,2,3,4,5,6,7 };
    amount = { 1,1,1,1,1,1,1 };
    check.checkDouble(803.5, o2.getBill(product, amount));
    product = { 4 };
    amount = { 10 };
    check.checkDouble(4010, o2.getBill(product, amount));
    product = { 7,3 };
    amount = { 10,10 };
    check.checkDouble(4020, o2.getBill(product, amount));
    product = { 7,5,3,1,6,4,2 };
    amount = { 10,10,10,9,9,9,7 };
    check.checkDouble(7382, o2.getBill(product, amount));
    product = { 2,3,5 };
    amount = { 5,3,2 };
    check.checkDouble(2510, o2.getBill(product, amount));
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
