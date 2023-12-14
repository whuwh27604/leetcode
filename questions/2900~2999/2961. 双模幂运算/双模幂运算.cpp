/* 双模幂运算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二维数组 variables ，其中 variables[i] = [ai, bi, ci, mi]，以及一个整数 target 。

如果满足以下公式，则下标 i 是 好下标：

0 <= i < variables.length
((aibi % 10)ci) % mi == target
返回一个由 好下标 组成的数组，顺序不限 。



示例 1：

输入：variables = [[2,3,3,10],[3,3,3,1],[6,1,1,4]], target = 2
输出：[0,2]
解释：对于 variables 数组中的每个下标 i ：
1) 对于下标 0 ，variables[0] = [2,3,3,10] ，(23 % 10)3 % 10 = 2 。
2) 对于下标 1 ，variables[1] = [3,3,3,1] ，(33 % 10)3 % 1 = 0 。
3) 对于下标 2 ，variables[2] = [6,1,1,4] ，(61 % 10)1 % 4 = 2 。
因此，返回 [0,2] 作为答案。
示例 2：

输入：variables = [[39,3,1000,1000]], target = 17
输出：[]
解释：对于 variables 数组中的每个下标 i ：
1) 对于下标 0 ，variables[0] = [39,3,1000,1000] ，(393 % 10)1000 % 1000 = 1 。
因此，返回 [] 作为答案。


提示：

1 <= variables.length <= 100
variables[i] == [ai, bi, ci, mi]
1 <= ai, bi, ci, mi <= 103
0 <= target <= 103
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        int size = variables.size();
        vector<int> ans;

        for (int i = 0; i < size; ++i) {
            if (fastPower(fastPower(variables[i][0], variables[i][1], 10), variables[i][2], variables[i][3]) == target) {
                ans.push_back(i);
            }
        }

        return ans;
    }

    long long fastPower(long long x, int n, long long mod) {
        long long ans = 1;

        while (n > 0) {
            if ((n & 1) == 1) {
                ans = ans * x % mod;
            }

            x = x * x % mod;
            n >>= 1;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> variables = { {2,3,3,10},{3,3,3,1},{6,1,1,4} };
    vector<int> actual = o.getGoodIndices(variables, 2);
    vector<int> expected = { 0,2 };
    check.checkIntVectorRandomOrder(expected, actual);

    variables = { {39,3,1000,1000} };
    actual = o.getGoodIndices(variables, 17);
    expected = {  };
    check.checkIntVectorRandomOrder(expected, actual);
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
