/* 用三种不同颜色为网格涂色.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数 m 和 n 。构造一个 m x n 的网格，其中每个单元格最开始是白色。请你用 红、绿、蓝 三种颜色为每个单元格涂色。所有单元格都需要被涂色。

涂色方案需要满足：不存在相邻两个单元格颜色相同的情况 。返回网格涂色的方法数。因为答案可能非常大， 返回 对 109 + 7 取余 的结果。

 

示例 1：


输入：m = 1, n = 1
输出：3
解释：如上图所示，存在三种可能的涂色方案。
示例 2：


输入：m = 1, n = 2
输出：6
解释：如上图所示，存在六种可能的涂色方案。
示例 3：

输入：m = 5, n = 5
输出：580986
 

提示：

1 <= m <= 5
1 <= n <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/painting-a-grid-with-three-different-colors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int colorTheGrid(int m, int n) {
        vector<string> table = getColumnTable(m);
        int size = table.size();
        vector<vector<long long>> dp(size, vector<long long>(n));
        int i, j, c, ways = 0, mod = 1000000007;

        for (i = 0; i < size; ++i) {
            dp[i][0] = 1;
        }

        for (c = 1; c < n; ++c) {
            for (i = 0; i < size; ++i) {
                for (j = 0; j < size; ++j) {
                    if (isMatch(table[i], table[j], m)) {
                        dp[i][c] = (dp[i][c] + dp[j][c - 1]) % mod;
                    }
                }
            }
        }

        for (i = 0; i < size; ++i) {
            ways = (ways + dp[i][n - 1]) % mod;
        }

        return ways;
    }

    vector<string> getColumnTable(int m) {
        vector<char> colors = { 'r','b','g' };
        vector<string> table = { "r", "b", "g" };

        for (int i = 1; i < m; ++i) {
            vector<string> tmp;

            for (string& s : table) {
                for (char c : colors) {
                    if (c != s.back()) {
                        tmp.push_back(s + c);
                    }
                }
            }

            table = tmp;
        }

        return table;
    }

    bool isMatch(string& a, string& b, int m) {
        for (int i = 0; i < m; ++i) {
            if (a[i] == b[i]) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.colorTheGrid(1, 1));
    check.checkInt(6, o.colorTheGrid(1, 2));
    check.checkInt(18, o.colorTheGrid(2, 2));
    check.checkInt(580986, o.colorTheGrid(5, 5));
    check.checkInt(408208448, o.colorTheGrid(5, 1000));
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
