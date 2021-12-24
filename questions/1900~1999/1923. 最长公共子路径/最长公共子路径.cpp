/* 最长公共子路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个国家由 n 个编号为 0 到 n - 1 的城市组成。在这个国家里，每两个 城市之间都有一条道路连接。

总共有 m 个编号为 0 到 m - 1 的朋友想在这个国家旅游。他们每一个人的路径都会包含一些城市。每条路径都由一个整数数组表示，每个整数数组表示一个朋友按顺序访问过的城市序列。同一个城市在一条路径中可能 重复 出现，但同一个城市在一条路径中不会连续出现。

给你一个整数 n 和二维数组 paths ，其中 paths[i] 是一个整数数组，表示第 i 个朋友走过的路径，请你返回 每一个 朋友都走过的 最长公共子路径 的长度，如果不存在公共子路径，请你返回 0 。

一个 子路径 指的是一条路径中连续的城市序列。

 

示例 1：

输入：n = 5, paths = [[0,1,2,3,4],
                     [2,3,4],
                     [4,0,1,2,3]]
输出：2
解释：最长公共子路径为 [2,3] 。
示例 2：

输入：n = 3, paths = [[0],[1],[2]]
输出：0
解释：三条路径没有公共子路径。
示例 3：

输入：n = 5, paths = [[0,1,2,3,4],
                     [4,3,2,1,0]]
输出：1
解释：最长公共子路径为 [0]，[1]，[2]，[3] 和 [4] 。它们长度都为 1 。
 

提示：

1 <= n <= 105
m == paths.length
2 <= m <= 105
sum(paths[i].length) <= 105
0 <= paths[i][j] < n
paths[i] 中同一个城市不会连续重复出现。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-subpath
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int low = 1, high = getMinPath(paths), maxCommonSubpath = 0;

        while (low <= high) {
            int middle = (low + high) / 2;

            if (check(paths, middle)) {
                maxCommonSubpath = middle;
                low = middle + 1;
            }
            else {
                high = middle - 1;
            }
        }

        return maxCommonSubpath;
    }

    bool check(vector<vector<int>>& paths, int len) {
        int i, m = paths.size(), base1 = 31, base2 = 47, mod1 = 1000000007, mod2 = 1010100007;
        unordered_map<long long, int> allKeys;

        for (auto& path : paths) {
            unordered_set<long long> keys;
            long long key1 = path[0], key2 = path[0], power1 = 1, power2 = 1;

            for (i = 1; i < len; ++i) {  // 计算path[0, len)的hashkey
                key1 = (key1 * base1 + path[i]) % mod1;
                key2 = (key2 * base2 + path[i]) % mod2;
                power1 = power1 * base1 % mod1;
                power2 = power2 * base2 % mod2;
            }

            long long keyPair = ((key1 << 32) | key2);
            keys.insert(keyPair);

            for (i = 1; i + len <= (int)path.size(); ++i) {  // 滚动计算path[i, i + len)的hashkey，先减去最高位，再左移一位，再加上最末位
                long long highest = (long long)path[i - 1] * power1 % mod1;
                key1 = ((key1 + (key1 < highest ? mod1 : 0) - highest) * base1 + (long long)path[i + len - 1]) % mod1;
                highest = (long long)path[i - 1] * power2 % mod2;
                key2 = ((key2 + (key2 < highest ? mod2 : 0) - highest) * base2 + (long long)path[i + len - 1]) % mod2;
                keyPair = ((key1 << 32) | key2);
                keys.insert(keyPair);
            }

            for (auto key : keys) {
                if (++allKeys[key] == m) {
                    return true;
                }
            }
        }

        return false;
    }

    int getMinPath(vector<vector<int>>& paths) {
        int minPath = INT_MAX;

        for (auto& path : paths) {
            minPath = min(minPath, (int)path.size());
        }

        return minPath;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> paths = { {0,1,2,3,4},{2,3,4},{4,0,1,2,3} };
    check.checkInt(2, o.longestCommonSubpath(5, paths));

    paths = { {0},{1},{2} };
    check.checkInt(0, o.longestCommonSubpath(3, paths));

    paths = { {0,1,2,3,4},{4,3,2,1,0} };
    check.checkInt(1, o.longestCommonSubpath(5, paths));

    paths = { {1,7,0,6,9,0,7,4,3,9,1,5,0,8,0,6,3,6,0,8,3,7,8,3,5,3,7,4,0,6,8,1,4},{1,7,0,6,9,0,7,4,3,9,1,5,0,8,0,6,3,6,0,8,3,7,8,3,5,3,7,4,0,6,8,1,5},{8,1,7,0,6,9,0,7,4,3,9,1,5,0,8,0,6,3,6,0,8,3,7,8,3,5,3,7,4,0,6,8,1} };
    check.checkInt(32, o.longestCommonSubpath(10, paths));
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
