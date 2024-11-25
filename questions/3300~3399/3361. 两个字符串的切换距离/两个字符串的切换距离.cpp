/* 两个字符串的切换距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个长度相同的字符串 s 和 t ，以及两个整数数组 nextCost 和 previousCost 。

一次操作中，你可以选择 s 中的一个下标 i ，执行以下操作 之一 ：

将 s[i] 切换为字母表中的下一个字母，如果 s[i] == 'z' ，切换后得到 'a' 。操作的代价为 nextCost[j] ，其中 j 表示 s[i] 在字母表中的下标。
将 s[i] 切换为字母表中的上一个字母，如果 s[i] == 'a' ，切换后得到 'z' 。操作的代价为 previousCost[j] ，其中 j 是 s[i] 在字母表中的下标。
切换距离 指的是将字符串 s 变为字符串 t 的 最少 操作代价总和。

请你返回从 s 到 t 的 切换距离 。



示例 1：

输入：s = "abab", t = "baba", nextCost = [100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0], previousCost = [1,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

输出：2

解释：

选择下标 i = 0 并将 s[0] 向前切换 25 次，总代价为 1 。
选择下标 i = 1 并将 s[1] 向后切换 25 次，总代价为 0 。
选择下标 i = 2 并将 s[2] 向前切换 25 次，总代价为 1 。
选择下标 i = 3 并将 s[3] 向后切换 25 次，总代价为 0 。
示例 2：

输入：s = "leet", t = "code", nextCost = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], previousCost = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]

输出：31

解释：

选择下标 i = 0 并将 s[0] 向前切换 9 次，总代价为 9 。
选择下标 i = 1 并将 s[1] 向后切换 10 次，总代价为 10 。
选择下标 i = 2 并将 s[2] 向前切换 1 次，总代价为 1 。
选择下标 i = 3 并将 s[3] 向后切换 11 次，总代价为 11 。


提示：

1 <= s.length == t.length <= 105
s 和 t 都只包含小写英文字母。
nextCost.length == previousCost.length == 26
0 <= nextCost[i], previousCost[i] <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        vector<vector<long long>> minDist(26, vector<long long>(26, 0));

        getMinDist(nextCost, previousCost, minDist);

        return getDist(s, t, minDist);
    }

    void getMinDist(vector<int>& nextCost, vector<int>& previousCost, vector<vector<long long>>& minDist) {
        vector<long long> nextPresum(27, 0), prevPresum(27, 0);

        for (int i = 0; i < 26; ++i) {
            nextPresum[i + 1] = nextPresum[i] + nextCost[i];
        }

        for (int i = 0; i < 26; ++i) {
            prevPresum[i + 1] = prevPresum[i] + previousCost[i];
        }

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (i < j) {
                    minDist[i][j] = min(nextPresum[j] - nextPresum[i], prevPresum[i + 1] + prevPresum[26] - prevPresum[j + 1]);
                }
                else if (i > j) {
                    minDist[i][j] = min(nextPresum[26] - nextPresum[i] + nextPresum[j], prevPresum[i + 1] - prevPresum[j + 1]);
                }
            }
        }
    }

    long long getDist(string& s, string& t, vector<vector<long long>>& minDist) {
        int size = (int)s.size();
        long long dist = 0;

        for (int i = 0; i < size; ++i) {
            dist += minDist[s[i] - 'a'][t[i] - 'a'];
        }

        return dist;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nextCost = { 100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    vector<int> previousCost = { 1,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    check.checkLongLong(2, o.shiftDistance("abab", "baba", nextCost, previousCost));

    nextCost = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
    previousCost = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
    check.checkLongLong(31, o.shiftDistance("leet", "code", nextCost, previousCost));
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
