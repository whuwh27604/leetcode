/* 统计不开心的朋友.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一份 n 位朋友的亲近程度列表，其中 n 总是 偶数 。

对每位朋友 i，preferences[i] 包含一份 按亲近程度从高到低排列 的朋友列表。换句话说，排在列表前面的朋友与 i 的亲近程度比排在列表后面的朋友更高。每个列表中的朋友均以 0 到 n-1 之间的整数表示。

所有的朋友被分成几对，配对情况以列表 pairs 给出，其中 pairs[i] = [xi, yi] 表示 xi 与 yi 配对，且 yi 与 xi 配对。

但是，这样的配对情况可能会是其中部分朋友感到不开心。在 x 与 y 配对且 u 与 v 配对的情况下，如果同时满足下述两个条件，x 就会不开心：

x 与 u 的亲近程度胜过 x 与 y，且
u 与 x 的亲近程度胜过 u 与 v
返回 不开心的朋友的数目 。

 

示例 1：

输入：n = 4, preferences = [[1, 2, 3], [3, 2, 0], [3, 1, 0], [1, 2, 0]], pairs = [[0, 1], [2, 3]]
输出：2
解释：
朋友 1 不开心，因为：
- 1 与 0 配对，但 1 与 3 的亲近程度比 1 与 0 高，且
- 3 与 1 的亲近程度比 3 与 2 高。
朋友 3 不开心，因为：
- 3 与 2 配对，但 3 与 1 的亲近程度比 3 与 2 高，且
- 1 与 3 的亲近程度比 1 与 0 高。
朋友 0 和 2 都是开心的。
示例 2：

输入：n = 2, preferences = [[1], [0]], pairs = [[1, 0]]
输出：0
解释：朋友 0 和 1 都开心。
示例 3：

输入：n = 4, preferences = [[1, 3, 2], [2, 3, 0], [1, 3, 0], [0, 2, 1]], pairs = [[1, 3], [0, 2]]
输出：4
 

提示：

2 <= n <= 500
n 是偶数
preferences.length == n
preferences[i].length == n - 1
0 <= preferences[i][j] <= n - 1
preferences[i] 不包含 i
preferences[i] 中的所有值都是独一无二的
pairs.length == n/2
pairs[i].length == 2
xi != yi
0 <= xi, yi <= n - 1
每位朋友都 恰好 被包含在一对中

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-unhappy-friends
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> preferenceIndices(n, vector<int>(n));
        getPreferenceIndices(n, preferences, preferenceIndices);

        vector<int> pairedFriends(n);
        getPairedFriends(pairs, pairedFriends);

        int unhappy = 0;

        for (auto& onePair : pairs) {
            if (isUnhappy(onePair[0], onePair[1], preferences, preferenceIndices, pairedFriends)) {
                ++unhappy;
            }

            if (isUnhappy(onePair[1], onePair[0], preferences, preferenceIndices, pairedFriends)) {
                ++unhappy;
            }
        }

        return unhappy;
    }

    void getPreferenceIndices(int n, vector<vector<int>>& preferences, vector<vector<int>>& preferenceIndices) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                preferenceIndices[i][preferences[i][j]] = j;
            }
        }
    }

    void getPairedFriends(vector<vector<int>>& pairs, vector<int>& pairedFriends) {
        for (auto& onePair : pairs) {
            pairedFriends[onePair[0]] = onePair[1];
            pairedFriends[onePair[1]] = onePair[0];
        }
    }

    bool isUnhappy(int x, int y, vector<vector<int>>& preferences, vector<vector<int>>& preferenceIndices, vector<int>& pairedFriends) {
        int i = 0, u = preferences[x][0], v;

        while (u != y) {
            v = pairedFriends[u];

            if (preferenceIndices[u][x] < preferenceIndices[u][v]) {
                return true;
            }

            u = preferences[x][++i];
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> preferences = { {1,2,3},{3,2,0},{3,1,0},{1,2,0} };
    vector<vector<int>> pairs = { {0,1},{2,3} };
    check.checkInt(2, o.unhappyFriends(4, preferences, pairs));

    preferences = { {1},{0} };
    pairs = { {1,0} };
    check.checkInt(0, o.unhappyFriends(2, preferences, pairs));

    preferences = { {1,3,2},{2,3,0},{1,3,0},{0,2,1} };
    pairs = { {1,3},{0,2} };
    check.checkInt(4, o.unhappyFriends(4, preferences, pairs));
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
