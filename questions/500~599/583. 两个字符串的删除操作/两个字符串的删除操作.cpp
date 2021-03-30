/* 两个字符串的删除操作.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

 

示例：

输入: "sea", "eat"
输出: 2
解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
 

提示：

给定单词的长度不超过500。
给定单词中的字符只含有小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-operation-for-two-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int i, j, size1 = word1.size(), size2 = word2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));  // dp[i][j]表示word1[0,i-1]和word2[0,j-1]变成一样需要的步骤

        for (i = 1; i <= size1; ++i) {  // word2一个字符也没有，需要把word1删光
            dp[i][0] = i;
        }

        for (j = 1; j <= size2; ++j) {  // word1一个字符也没有，需要把word2删光
            dp[0][j] = j;
        }

        for (i = 0; i < size1; ++i) {
            for (j = 0; j < size2; ++j) {
                if (word1[i] == word2[j]) {  // 最后一个字符相同，肯定要选择匹配它们，然后看匹配剩下的字符需要多少步骤
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else {  // 最后一个字符不同，可以选择删除word1最后一个字符，或者word2最后一个字符，看哪个需要的步骤更少
                    dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i + 1][j]) + 1;
                }
            }
        }

        return dp[size1][size2];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.minDistance("sea", "eat"));
    check.checkInt(0, o.minDistance("", ""));
    check.checkInt(1, o.minDistance("", "z"));
    check.checkInt(1, o.minDistance("a", ""));
    check.checkInt(2, o.minDistance("aaa", "aaaaa"));
    check.checkInt(25, o.minDistance("aljasfjladfjal", "lasjdflkajlfajfajlfjalkfjalfjlajfla"));
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
