/* 计算应缴税款总额.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二维整数数组 brackets ，其中 brackets[i] = [upperi, percenti] ，表示第 i 个税级的上限是 upperi ，征收的税率为 percenti 。税级按上限 从低到高排序（在满足 0 < i < brackets.length 的前提下，upperi-1 < upperi）。

税款计算方式如下：

不超过 upper0 的收入按税率 percent0 缴纳
接着 upper1 - upper0 的部分按税率 percent1 缴纳
然后 upper2 - upper1 的部分按税率 percent2 缴纳
以此类推
给你一个整数 income 表示你的总收入。返回你需要缴纳的税款总额。与标准答案误差不超 10-5 的结果将被视作正确答案。

 

示例 1：

输入：brackets = [[3,50],[7,10],[12,25]], income = 10
输出：2.65000
解释：
前 $3 的税率为 50% 。需要支付税款 $3 * 50% = $1.50 。
接下来 $7 - $3 = $4 的税率为 10% 。需要支付税款 $4 * 10% = $0.40 。
最后 $10 - $7 = $3 的税率为 25% 。需要支付税款 $3 * 25% = $0.75 。
需要支付的税款总计 $1.50 + $0.40 + $0.75 = $2.65 。
示例 2：

输入：brackets = [[1,0],[4,25],[5,50]], income = 2
输出：0.25000
解释：
前 $1 的税率为 0% 。需要支付税款 $1 * 0% = $0 。
剩下 $1 的税率为 25% 。需要支付税款 $1 * 25% = $0.25 。
需要支付的税款总计 $0 + $0.25 = $0.25 。
示例 3：

输入：brackets = [[2,50]], income = 0
输出：0.00000
解释：
没有收入，无需纳税，需要支付的税款总计 $0 。
 

提示：

1 <= brackets.length <= 100
1 <= upperi <= 1000
0 <= percenti <= 100
0 <= income <= 1000
upperi 按递增顺序排列
upperi 中的所有值 互不相同
最后一个税级的上限大于等于 income

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/calculate-amount-paid-in-taxes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0;
        int upper = 0;

        for (auto& bracket : brackets) {
            if (income <= upper) {
                break;
            }

            tax += (((double)min(bracket[0], income) - upper) * bracket[1] / 100);
            upper = bracket[0];
        }

        return tax;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> brackets = { {3,50},{7,10},{12,25} };
    check.checkDouble(2.65, o.calculateTax(brackets, 10));

    brackets = { {2,50} };
    check.checkDouble(0, o.calculateTax(brackets, 0));

    brackets = { {1,0},{4,25},{5,50} };
    check.checkDouble(0.25, o.calculateTax(brackets, 2));
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
