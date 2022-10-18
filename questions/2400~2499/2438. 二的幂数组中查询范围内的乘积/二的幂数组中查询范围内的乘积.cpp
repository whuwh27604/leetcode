/* 二的幂数组中查询范围内的乘积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 n ，你需要找到一个下标从 0 开始的数组 powers ，它包含 最少 数目的 2 的幂，且它们的和为 n 。powers 数组是 非递减 顺序的。根据前面描述，构造 powers 数组的方法是唯一的。

同时给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [lefti, righti] ，其中 queries[i] 表示请你求出满足 lefti <= j <= righti 的所有 powers[j] 的乘积。

请你返回一个数组 answers ，长度与 queries 的长度相同，其中 answers[i]是第 i 个查询的答案。由于查询的结果可能非常大，请你将每个 answers[i] 都对 109 + 7 取余 。

 

示例 1：

输入：n = 15, queries = [[0,1],[2,2],[0,3]]
输出：[2,4,64]
解释：
对于 n = 15 ，得到 powers = [1,2,4,8] 。没法得到元素数目更少的数组。
第 1 个查询的答案：powers[0] * powers[1] = 1 * 2 = 2 。
第 2 个查询的答案：powers[2] = 4 。
第 3 个查询的答案：powers[0] * powers[1] * powers[2] * powers[3] = 1 * 2 * 4 * 8 = 64 。
每个答案对 109 + 7 得到的结果都相同，所以返回 [2,4,64] 。
示例 2：

输入：n = 2, queries = [[0,0]]
输出：[2]
解释：
对于 n = 2, powers = [2] 。
唯一一个查询的答案是 powers[0] = 2 。答案对 109 + 7 取余后结果相同，所以返回 [2] 。
 

提示：

1 <= n <= 109
1 <= queries.length <= 105
0 <= starti <= endi < powers.length

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/range-product-queries-of-powers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int index = 0, size = queries.size();
        vector<int> ans(size, 1);
        vector<int> powers;
        getPowers(n, powers);

        for (auto& query : queries) {
            for (int i = query[0]; i <= query[1]; ++i) {
                ans[index] = (int)((long long)ans[index] * powers[i] % 1000000007);
            }

            ++index;
        }

        return ans;
    }

    void getPowers(int n, vector<int>& powers) {
        int power = 1;

        while (n != 0) {
            if ((n & 1) == 1) {
                powers.push_back(power);
            }

            n >>= 1;
            power <<= 1;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> queries = { {0,1},{2,2},{0,3} };
    vector<int> actual = o.productQueries(15, queries);
    vector<int> expected = { 2,4,64 };
    check.checkIntVector(expected, actual);

    queries = { {0,0} };
    actual = o.productQueries(2, queries);
    expected = { 2 };
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
