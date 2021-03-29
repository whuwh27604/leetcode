/* 最短超级串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串数组 words，找到以 words 中每个字符串作为子字符串的最短字符串。如果有多个有效最短字符串满足题目条件，返回其中 任意一个 即可。

我们可以假设 words 中没有字符串是 words 中另一个字符串的子字符串。

 

示例 1：

输入：words = ["alex","loves","leetcode"]
输出："alexlovesleetcode"
解释："alex"，"loves"，"leetcode" 的所有排列都会被接受。
示例 2：

输入：words = ["catg","ctaagt","gcta","ttca","atgcatc"]
输出："gctaagttcatgcatc"
 

提示：

1 <= words.length <= 12
1 <= words[i].length <= 20
words[i] 由小写英文字母组成
words 中的所有字符串 互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-shortest-superstring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int size = words.size(), mask, fullMask = (1 << size) - 1;
        vector<vector<int>> overlaps(size, vector<int>(size));  // A、B串联为AB时，重合部分的长度
        getOverlaps(words, size, overlaps);

        vector<vector<int>> dp(fullMask + 1, vector<int>(size, INT_MAX));  // dp[mask][i]表示选择单词集合是mask、第一个单词是words[i]时的最短长度
        vector<vector<int>> dpPrev(fullMask + 1, vector<int>(size, 0));  // 记录下每一个状态是从哪里转移来的，用来重构出完整的字符串

        for (mask = 1; mask <= fullMask; ++mask) {  // 直接递增mask就可以了，因为计算某一个mask时，它所有的子集已经计算过了
            calcShortestSuperStr(mask, words, dp, dpPrev, overlaps);
        }

        int shortestIndex = getShortestIndex(dp, size);
        return buildSuperString(words, shortestIndex, fullMask, dpPrev, overlaps);
    }

    void getOverlaps(vector<string>& words, int size, vector<vector<int>>& overlaps) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                overlaps[i][j] = getOverlap(words[i], words[j]);
            }
        }
    }

    int getOverlap(string& word1, string& word2) {
        int i, size1 = word1.size(), size2 = word2.size(), overlap;

        for (overlap = min(size1, size2) - 1; overlap > 0; --overlap) {  // 不存在一个word是另一个word子串的情况，所以最大只能是size-1
            for (i = 0; i < overlap; ++i) {
                if (word1[size1 - overlap + i] != word2[i]) {
                    break;
                }
            }

            if (i == overlap) {
                break;
            }
        }

        return overlap;
    }

    void calcShortestSuperStr(int mask, vector<string>& words, vector<vector<int>>& dp, vector<vector<int>>& dpPrev, vector<vector<int>>& overlaps) {
        vector<int> indices;
        getIndices(mask, indices);  // 导出该mask包含的indices
        int i, j, size = indices.size();

        if (size == 1) {
            dp[mask][indices[0]] = words[indices[0]].size();
            return;
        }

        for (i = 0; i < size; ++i) {  // 遍历每一个选中的单词作为第一个单词
            int index1 = indices[i];
            int tmpMask = mask ^ (1 << index1);  // 剩下单词的集合

            for (j = 0; j < size; ++j) {  // 遍历剩下的单词，任选一个接到第一个单词后面，看哪个接出来的长度最短
                if (j == i) {
                    continue;
                }

                int index2 = indices[j];
                int len = (int)words[index1].size() + dp[tmpMask][index2] - overlaps[index1][index2];
                if (len < dp[mask][index1]) {
                    dp[mask][index1] = len;
                    dpPrev[mask][index1] = (tmpMask << 16) | index2;  // 记录下这个状态从哪里转移来的
                }
            }
        }
    }

    void getIndices(int mask, vector<int>& indices) {
        int index = 0;

        while (mask != 0) {
            if ((mask & 1) == 1) {
                indices.push_back(index);
            }

            ++index;
            mask >>= 1;
        }
    }

    int getShortestIndex(vector<vector<int>>& dp, int size) {
        int i, shortestLen = INT_MAX, shortestIndex = 0, mask = (1 << size) - 1;  // 全部单词都选上;

        for (i = 0; i < size; ++i) {  // 检查哪个单词放在第一个可以最短
            if (dp[mask][i] < shortestLen) {
                shortestLen = dp[mask][i];
                shortestIndex = i;
            }
        }

        return shortestIndex;
    }

    string buildSuperString(vector<string>& words, int index, int mask, vector<vector<int>>& dpPrev, vector<vector<int>>& overlaps) {
        string superString = words[index];
        int prevIndex = index, next = dpPrev[mask][index];

        while (next != 0) {
            mask = next >> 16;
            index = next & 0xffff;

            for (int i = overlaps[prevIndex][index]; i < (int)words[index].size(); ++i) {
                superString += words[index][i];
            }

            prevIndex = index;
            next = dpPrev[mask][index];
        }

        return superString;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "alex","loves","leetcode" };
    check.checkString("alexlovesleetcode", o.shortestSuperstring(words));

    words = { "catg","ctaagt","gcta","ttca","atgcatc" };
    check.checkString("gctaagttcatgcatc", o.shortestSuperstring(words));

    words = { "z" };
    check.checkString("z", o.shortestSuperstring(words));

    words = { "uhozqhxcqmkifljvcie","epuhozqhxcqmkifljvci","ugmqnepuhozqhxcqm","iexdudtvurjkrovrhmpa","rovrhmpaasblgaosw","qmkifljvciexdudtv","zsgtuowskyzphybeugm","uowskyzphybeugmq","qhxcqmkifljvciex" };
    check.checkString("zsgtuowskyzphybeugmqnepuhozqhxcqmkifljvciexdudtvurjkrovrhmpaasblgaosw", o.shortestSuperstring(words));
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
