/* 子数组异或查询.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个正整数数组 arr，现给你一个对应的查询数组 queries，其中 queries[i] = [Li, Ri]。

对于每个查询 i，请你计算从 Li 到 Ri 的 XOR 值（即 arr[Li] xor arr[Li+1] xor ... xor arr[Ri]）作为本次查询的结果。

并返回一个包含给定查询 queries 所有结果的数组。

 

示例 1：

输入：arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
输出：[2,7,14,8]
解释：
数组中元素的二进制表示形式是：
1 = 0001
3 = 0011
4 = 0100
8 = 1000
查询的 XOR 值为：
[0,1] = 1 xor 3 = 2
[1,2] = 3 xor 4 = 7
[0,3] = 1 xor 3 xor 4 xor 8 = 14
[3,3] = 8
示例 2：

输入：arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
输出：[8,0,4,4]
 

提示：

1 <= arr.length <= 3 * 10^4
1 <= arr[i] <= 10^9
1 <= queries.length <= 3 * 10^4
queries[i].length == 2
0 <= queries[i][0] <= queries[i][1] < arr.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xor-queries-of-a-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int i, size = arr.size();
        vector<int> preSum(size + 1), ans(queries.size());
        preSum[0] = 0;

        for (i = 0; i < size; ++i) {
            preSum[i + 1] = preSum[i] ^ arr[i];
        }

        i = 0;
        for (vector<int>& query : queries) {
            ans[i++] = preSum[query[1] + 1] ^ preSum[query[0]];
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 1,3,4,8 };
    vector<vector<int>> queries = { {0,1},{1,2},{0,3},{3,3} };
    vector<int> actual = o.xorQueries(arr, queries);
    vector<int> expected = { 2,7,14,8 };
    check.checkIntVector(expected, actual);

    arr = { 4,8,2,10 };
    queries = { {2,3},{1,3},{0,0},{0,3} };
    actual = o.xorQueries(arr, queries);
    expected = { 8,0,4,4 };
    check.checkIntVector(expected, actual);

    arr = { 4 };
    queries = { {0,0} };
    actual = o.xorQueries(arr, queries);
    expected = { 4 };
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
