/* 生成乘积数组的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维整数数组 queries ，其中 queries[i] = [ni, ki] 。第 i 个查询 queries[i] 要求构造长度为 ni 、每个元素都是正整数的数组，且满足所有元素的乘积为 ki ，请你找出有多少种可行的方案。由于答案可能会很大，方案数需要对 109 + 7 取余 。

请你返回一个整数数组 answer，满足 answer.length == queries.length ，其中 answer[i]是第 i 个查询的结果。

 

示例 1：

输入：queries = [[2,6],[5,1],[73,660]]
输出：[4,1,50734910]
解释：每个查询之间彼此独立。
[2,6]：总共有 4 种方案得到长度为 2 且乘积为 6 的数组：[1,6]，[2,3]，[3,2]，[6,1]。
[5,1]：总共有 1 种方案得到长度为 5 且乘积为 1 的数组：[1,1,1,1,1]。
[73,660]：总共有 1050734917 种方案得到长度为 73 且乘积为 660 的数组。1050734917 对 109 + 7 取余得到 50734910 。
示例 2 ：

输入：queries = [[1,1],[2,2],[3,3],[4,4],[5,5]]
输出：[1,2,3,10,5]
 

提示：

1 <= queries.length <= 104
1 <= ni, ki <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-ways-to-make-array-with-product
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        /* 对k做质因数分解，设K = P1^X1 * P2^X2 * ... * Pm^Xm，
           那么题目等价于把X1个P1球、X2个P2球、...、Xm个Pm球放入N个槽位，槽位可以为空（意味着用1填充），有多少种方法？
           根据组合数学隔板法，X个球放入N个槽位，如果槽位不可为空，那么方法数为C(X - 1, N - 1)；
           如果槽位可以为空，那么方法数为C(X + N - 1, N - 1)，即先添加N个球，每个槽位放1个，然后剩下X个球随意放。
           最后X被分解为X1 + X2 + ... + Xm，每一个Xi类型的球互不影响，可以随意放入，所以最终的方法数是：
           C(X1 + N - 1, N - 1) * C(X2 + N - 1, N - 1) * ... * C(Xm + N - 1, N - 1) */
        vector<int> ways(queries.size());
        int index = 0;

        for (auto& query : queries) {
            long long way = 1;

            if (query[1] != 1) {
                for (auto& iter : primeFactors[query[1]]) {
                    way = (long long)factorial[iter.second + query[0] - 1] * inverse[query[0] - 1] % mod * inverse[iter.second] % mod * way % mod;
                }
            }

            ways[index++] = (int)way;
        }

        return ways;
    }

    Solution() {
        if (!init) {
            init = true;
            decomposePrimeFactors();
            calcFactorials();
        }
    }

    void decomposePrimeFactors() {  // 埃拉托色尼筛选法分解10000以内的质数
        int i, size = 10001;
        primeFactors.resize(size);
        primeFactors[1][1] = 1;

        for (i = 2; i < size; ++i) {
            if (primeFactors[i].empty()) {  // i是一个质数，将它所有的倍数分解为i * times
                primeFactors[i][i] = 1;  // i自己只能分解为i * 1

                for (int times = 2; i * times <= 10000; ++times) {
                    if (primeFactors[i * times].empty()) {  // 如果已经被更小的质数分解过了，则不用重复分解
                        primeFactors[i * times][i] = times;
                    }
                }
            }
            else {
                int decomposed = primeFactors[i].begin()->second;
                primeFactors[i].begin()->second = 1;

                for (auto& iter : primeFactors[decomposed]) {  // 将已经分解过的这个数的最终结果加入进来
                    primeFactors[i][iter.first] += iter.second;
                }
            }
        }
    }

    void calcFactorials() {
        int size = 10015;  // 因为k <= 10000，X最大只能是13（2^13 < 10000 < 2^14），所以算到10015够用了
        factorial.resize(size);
        inverse.resize(size);
        factorial[0] = inverse[0] = 1;
        long long num = 1;

        for (int i = 1; i < size; ++i) {
            num = (num * i) % mod;
            factorial[i] = (int)num;
            inverse[i] = fastPower(factorial[i], mod - 2);
        }
    }

    int fastPower(int x, int n) {
        long long ans = 1;
        int bit = 1;

        while (n != 0) {
            if ((n & bit) != 0) {
                ans = (ans * x) % mod;
            }

            n &= ~bit;
            bit <<= 1;
            x = ((long long)x * x) % mod;
        }

        return (int)ans;
    }

private:
    static vector<unordered_map<int, int>> primeFactors;
    static vector<int> factorial;
    static vector<int> inverse;
    static const int mod = 1000000007;
    static bool init;
};

vector<unordered_map<int, int>> Solution::primeFactors;
vector<int> Solution::factorial;
vector<int> Solution::inverse;
bool Solution::init = false;

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> queries = { {2,6},{5,1},{73,660} };
    vector<int> actual = o.waysToFillArray(queries);
    vector<int> expected = { 4,1,50734910 };
    check.checkIntVector(expected, actual);

    queries = { {1,1},{2,2},{3,3},{4,4},{5,5} };
    actual = o.waysToFillArray(queries);
    expected = { 1,2,3,10,5 };
    check.checkIntVector(expected, actual);

    queries = { {10000,10000},{9999,9999},{9998,9998},{9997,9997},{9996,9996},{9995,9995},{9994,9994},{9993,9993},{9992,9992},{9991,9991},{9990,9990} };
    actual = o.waysToFillArray(queries);
    expected = { 418224726,115005500,99960004,99940009,886831192,99900025,201072798,99860049,552527582,99820081,158152760 };
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
