/* 子字符串异或查询.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 二进制字符串 s 和一个整数数组 queries ，其中 queries[i] = [firsti, secondi] 。

对于第 i 个查询，找到 s 的 最短子字符串 ，它对应的 十进制值 val 与 firsti 按位异或 得到 secondi ，换言之，val ^ firsti == secondi 。

第 i 个查询的答案是子字符串 [lefti, righti] 的两个端点（下标从 0 开始），如果不存在这样的子字符串，则答案为 [-1, -1] 。如果有多个答案，请你选择 lefti 最小的一个。

请你返回一个数组 ans ，其中 ans[i] = [lefti, righti] 是第 i 个查询的答案。

子字符串 是一个字符串中一段连续非空的字符序列。



示例 1：

输入：s = "101101", queries = [[0,5],[1,2]]
输出：[[0,2],[2,3]]
解释：第一个查询，端点为 [0,2] 的子字符串为 "101" ，对应十进制数字 5 ，且 5 ^ 0 = 5 ，所以第一个查询的答案为 [0,2]。第二个查询中，端点为 [2,3] 的子字符串为 "11" ，对应十进制数字 3 ，且 3 ^ 1 = 2 。所以第二个查询的答案为 [2,3] 。
示例 2：

输入：s = "0101", queries = [[12,8]]
输出：[[-1,-1]]
解释：这个例子中，没有符合查询的答案，所以返回 [-1,-1] 。
示例 3：

输入：s = "1", queries = [[4,5]]
输出：[[0,0]]
解释：这个例子中，端点为 [0,0] 的子字符串对应的十进制值为 1 ，且 1 ^ 4 = 5 。所以答案为 [0,0] 。


提示：

1 <= s.length <= 104
s[i] 要么是 '0' ，要么是 '1' 。
1 <= queries.length <= 105
0 <= firsti, secondi <= 109
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> numIndices;
        vector<vector<int>> ans(queries.size());
        int size = s.size(), index = 0;

        for (int i = 0; i < size; ++i) {
            if (s[i] == '0') {
                if (numIndices.count(0) == 0) {
                    numIndices[0] = { i,i };
                }
            }
            else {
                int num = 0;
                for (int j = 0; j < 31 && i + j < size; ++j) {
                    num = num * 2 + (s[i + j] == '0' ? 0 : 1);
                    if (numIndices.count(num) == 0) {
                        numIndices[num] = { i,i + j };
                    }
                }
            }
        }

        for (auto& query : queries) {
            int num = query[0] ^ query[1];
            if (numIndices.count(num) == 0) {
                ans[index++] = { -1,-1 };
            }
            else {
                ans[index++] = numIndices[num];
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> queries = { {0,5},{1,2} };
    vector<vector<int>> actual = o.substringXorQueries("101101", queries);
    vector<vector<int>> expected = { {0,2},{2,3} };
    check.checkIntVectorVector(expected, actual);

    queries = { {12,8} };
    actual = o.substringXorQueries("0101", queries);
    expected = { {-1,-1} };
    check.checkIntVectorVector(expected, actual);

    queries = { {0,0} };
    actual = o.substringXorQueries("0", queries);
    expected = { {0,0} };
    check.checkIntVectorVector(expected, actual);

    queries = { {12,8} };
    actual = o.substringXorQueries("111111111111111111111111111111111111111111111111111111111111111111111111111111111", queries);
    expected = { {-1,-1} };
    check.checkIntVectorVector(expected, actual);
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
