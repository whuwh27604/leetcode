/* 早餐组合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小扣在秋日市集选择了一家早餐摊位，一维整型数组 staple 中记录了每种主食的价格，一维整型数组 drinks 中记录了每种饮料的价格。小扣的计划选择一份主食和一款饮料，且花费不超过 x 元。请返回小扣共有多少种购买方案。

注意：答案需要以 1e9 + 7 (1000000007) 为底取模，如：计算初始结果为：1000000008，请返回 1

示例 1：

输入：staple = [10,20,5], drinks = [5,5,2], x = 15

输出：6

解释：小扣有 6 种购买方案，所选主食与所选饮料在数组中对应的下标分别是：
第 1 种方案：staple[0] + drinks[0] = 10 + 5 = 15；
第 2 种方案：staple[0] + drinks[1] = 10 + 5 = 15；
第 3 种方案：staple[0] + drinks[2] = 10 + 2 = 12；
第 4 种方案：staple[2] + drinks[0] = 5 + 5 = 10；
第 5 种方案：staple[2] + drinks[1] = 5 + 5 = 10；
第 6 种方案：staple[2] + drinks[2] = 5 + 2 = 7。

示例 2：

输入：staple = [2,1,1], drinks = [8,9,5,1], x = 9

输出：8

解释：小扣有 8 种购买方案，所选主食与所选饮料在数组中对应的下标分别是：
第 1 种方案：staple[0] + drinks[2] = 2 + 5 = 7；
第 2 种方案：staple[0] + drinks[3] = 2 + 1 = 3；
第 3 种方案：staple[1] + drinks[0] = 1 + 8 = 9；
第 4 种方案：staple[1] + drinks[2] = 1 + 5 = 6；
第 5 种方案：staple[1] + drinks[3] = 1 + 1 = 2；
第 6 种方案：staple[2] + drinks[0] = 1 + 8 = 9；
第 7 种方案：staple[2] + drinks[2] = 1 + 5 = 6；
第 8 种方案：staple[2] + drinks[3] = 1 + 1 = 2；

提示：

1 <= staple.length <= 10^5
1 <= drinks.length <= 10^5
1 <= staple[i],drinks[i] <= 10^5
1 <= x <= 2*10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/2vYnGI
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        int size1 = staple.size(), size2 = drinks.size(), i, j = size2 - 1, mod = 1000000007;
        long long ways = 0;

        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());

        for (i = 0, j = size2 - 1; i < size1; ++i) {
            int drink = x - staple[i];

            while (drinks[j] > drink) {
                if (--j < 0) {
                    return (int)(ways % mod);
                }
            }

            ways += ((long long)j + 1);
        }

        return (int)(ways % mod);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> staple = { 10,20,5 };
    vector<int> drinks = { 5,5,2 };
    check.checkInt(6, o.breakfastNumber(staple, drinks, 15));

    staple = { 2,1,1 };
    drinks = { 8,9,5,1 };
    check.checkInt(8, o.breakfastNumber(staple, drinks, 9));

    staple = { 2,1,1 };
    drinks = { 8,9,5,1 };
    check.checkInt(12, o.breakfastNumber(staple, drinks, 100));

    staple = { 2,1,1 };
    drinks = { 8,9,5,1 };
    check.checkInt(0, o.breakfastNumber(staple, drinks, 1));

    staple = { 1,1,1,1,1 };
    drinks = { 2,2,2,2,2,2 };
    check.checkInt(30, o.breakfastNumber(staple, drinks, 3));
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
