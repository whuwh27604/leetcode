/* 理财产品.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
某公司计划推出一批投资项目。 product[i] = price 表示第 i 个理财项目的投资金额 price 。客户在按需投资时，需要遵循以下规则：

客户在首次对项目 product[i] 投资时，需要投入金额 price
对已完成首次投资的项目 product[i] 可继续追加投入，但追加投入的金额需小于上一次对该项目的投入(追加投入为大于 0 的整数)
为控制市场稳定，每人交易次数不得大于 limit。(首次投资和追加投入均记作 1 次交易)
若对所有理财项目中最多进行 limit 次交易，使得投入金额总和最大，请返回这个最大值的总和。

注意：

答案需要以 1e9 + 7 (1000000007) 为底取模，如：计算初始结果为：1000000008，请返回 1
示例 1：

输入：product = [4,5,3], limit = 8

输出：26

解释：满足条件的一种情况为：
第一个理财项目进行金额为 4，3，2 的交易；
第二个理财项目进行金额为 5，4，3 的交易；
第三个理财项目进行金额为 3，2 的交易；
得到最大投入金额总和为 5 + 4 * 2 + 3 * 3 + 2 * 2 = 26。

示例 2：

输入：product = [2,1,3], limit = 20

输出：10

解释：可交易总次数小于 limit，因此进行所有交易
第一个理财项目可交易 2 次，交易的金额分别为 2，1；
第二个理财项目可交易 1 次，交易的金额分别为 1；
第三个理财项目可交易 3 次，交易的金额分别为 3，2，1；
因此所得最大投入金额总和为 3 + 2 * 2 + 1 * 3 = 10。

提示：

1 <= product.length <= 10^5
1 <= product[i] <= 10^7
1 <= limit <= 10^9
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxInvestment(vector<int>& product, int limit) {
        int i, size = product.size(), mod = 1000000007;
        long long sum = 0, count = 0;

        sort(product.begin(), product.end());

        for (i = size - 1; i > 0; --i) {
            count = ((long long)size - i) * ((long long)product[i] - product[i - 1]);

            if (count > limit) {
                break;
            }

            sum = (sum + ((long long)product[i] + product[i - 1] + 1) * ((long long)product[i] - product[i - 1]) / 2 * ((long long)size - i)) % mod;
            limit -= (int)count;
        }

        int width = size - i, height = min(product[i], limit / width);
        int high = product[i], low = high - height + 1;
        sum = (sum + ((long long)high + low) * height / 2 * width) % mod;
        limit -= height * width;
        sum = (sum + ((long long)low - 1) * limit) % mod;

        return (int)sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> product = { 4,5,3 };
    check.checkInt(26, o.maxInvestment(product, 8));

    product = { 4,5,3 };
    check.checkInt(5, o.maxInvestment(product, 1));

    product = { 4,5,3 };
    check.checkInt(9, o.maxInvestment(product, 2));

    product = { 4,5,3 };
    check.checkInt(13, o.maxInvestment(product, 3));

    product = { 4,5,3 };
    check.checkInt(16, o.maxInvestment(product, 4));

    product = { 4,5,3 };
    check.checkInt(19, o.maxInvestment(product, 5));

    product = { 4,5,3 };
    check.checkInt(22, o.maxInvestment(product, 6));

    product = { 4,5,3 };
    check.checkInt(24, o.maxInvestment(product, 7));

    product = { 4,5,3 };
    check.checkInt(28, o.maxInvestment(product, 9));

    product = { 4,5,3 };
    check.checkInt(29, o.maxInvestment(product, 10));

    product = { 4,5,3 };
    check.checkInt(30, o.maxInvestment(product, 11));

    product = { 4,5,3 };
    check.checkInt(31, o.maxInvestment(product, 12));

    product = { 4,5,3 };
    check.checkInt(31, o.maxInvestment(product, 13));

    product = { 2,1,3 };
    check.checkInt(10, o.maxInvestment(product, 20));

    product = { 5,5,4,4,3,3 };
    check.checkInt(5, o.maxInvestment(product, 1));

    product = { 5,5,4,4,3,3 };
    check.checkInt(10, o.maxInvestment(product, 2));

    product = { 5,5,4,4,3,3 };
    check.checkInt(14, o.maxInvestment(product, 3));

    product = { 3 };
    check.checkInt(3, o.maxInvestment(product, 1));

    product = { 3 };
    check.checkInt(6, o.maxInvestment(product, 4));

    product = { 2,5 };
    check.checkInt(14, o.maxInvestment(product, 4));

    product = { 3,5 };
    check.checkInt(19, o.maxInvestment(product, 6));

    product = { 2,8,4,10,6 };
    check.checkInt(110, o.maxInvestment(product, 20));

    product = { 1000000000 };
    check.checkInt(21, o.maxInvestment(product, 1000000000));

    product = { 773160767 };
    check.checkInt(70267492, o.maxInvestment(product, 252264991));
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
