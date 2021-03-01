/* 最富有客户的资产总量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的整数网格 accounts ，其中 accounts[i][j] 是第 i​​​​​​​​​​​​ 位客户在第 j 家银行托管的资产数量。返回最富有客户所拥有的 资产总量 。

客户的 资产总量 就是他们在各家银行托管的资产数量之和。最富有客户就是 资产总量 最大的客户。

 

示例 1：

输入：accounts = [[1,2,3],[3,2,1]]
输出：6
解释：
第 1 位客户的资产总量 = 1 + 2 + 3 = 6
第 2 位客户的资产总量 = 3 + 2 + 1 = 6
两位客户都是最富有的，资产总量都是 6 ，所以返回 6 。
示例 2：

输入：accounts = [[1,5],[7,3],[3,5]]
输出：10
解释：
第 1 位客户的资产总量 = 6
第 2 位客户的资产总量 = 10
第 3 位客户的资产总量 = 8
第 2 位客户是最富有的，资产总量是 10
示例 3：

输入：accounts = [[2,8,7],[7,1,3],[1,9,5]]
输出：17
 

提示：

m == accounts.length
n == accounts[i].length
1 <= m, n <= 50
1 <= accounts[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/richest-customer-wealth
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxAmount = 0;

        for (auto& account : accounts) {
            int sum = 0;

            for (int amount : account) {
                sum += amount;
            }

            maxAmount = max(maxAmount, sum);
        }

        return maxAmount;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> accounts = { {1,2,3},{3,2,1} };
    check.checkInt(6, o.maximumWealth(accounts));

    accounts = { {1,5},{7,3},{3,5} };
    check.checkInt(10, o.maximumWealth(accounts));

    accounts = { {2,8,7},{7,1,3},{1,9,5} };
    check.checkInt(17, o.maximumWealth(accounts));

    accounts = { {8} };
    check.checkInt(8, o.maximumWealth(accounts));
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
