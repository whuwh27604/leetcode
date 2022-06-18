/* 播放列表的数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你的音乐播放器里有 N 首不同的歌，在旅途中，你的旅伴想要听 L 首歌（不一定不同，即，允许歌曲重复）。请你为她按如下规则创建一个播放列表：

每首歌至少播放一次。
一首歌只有在其他 K 首歌播放完之后才能再次播放。
返回可以满足要求的播放列表的数量。由于答案可能非常大，请返回它模 10^9 + 7 的结果。

 

示例 1：

输入：N = 3, L = 3, K = 1
输出：6
解释：有 6 种可能的播放列表。[1, 2, 3]，[1, 3, 2]，[2, 1, 3]，[2, 3, 1]，[3, 1, 2]，[3, 2, 1].
示例 2：

输入：N = 2, L = 3, K = 0
输出：6
解释：有 6 种可能的播放列表。[1, 1, 2]，[1, 2, 1]，[2, 1, 1]，[2, 2, 1]，[2, 1, 2]，[1, 2, 2]
示例 3：

输入：N = 2, L = 3, K = 1
输出：2
解释：有 2 种可能的播放列表。[1, 2, 1]，[2, 1, 2]
 

提示：

0 <= K < N <= L <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-music-playlists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        int mod = 1000000007;
        vector<vector<long long>> dp(goal + 1, vector<long long>(n + 1, 0));  // dp[i][j]表示列表长度为i，不同歌曲数量为j的方法数
        dp[0][0] = 1;

        for (int i = 1; i <= goal; ++i) {
            for (int j = 1; j <= n && j <= i; ++j) {
                dp[i][j] = dp[i - 1][j - 1] * ((long long)n - j + 1) % mod;  // 最后一首歌选前面没有出现过的，那么有(n - j + 1)种选择

                if (j > k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j] * ((long long)j - k)) % mod;  // 最后一首歌选前面已经出现过的，那么有(j - k)种选择
                }
            }
        }

        return (int)dp[goal][n];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(6, o.numMusicPlaylists(3, 3, 1));
    check.checkInt(6, o.numMusicPlaylists(2, 3, 0));
    check.checkInt(2, o.numMusicPlaylists(2, 3, 1));
    check.checkInt(10800, o.numMusicPlaylists(5, 8, 2));
    check.checkInt(393678983, o.numMusicPlaylists(50, 100, 25));
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
