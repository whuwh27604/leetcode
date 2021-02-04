/* 编辑距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
 

提示：

0 <= word1.length, word2.length <= 500
word1 和 word2 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/edit-distance
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
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));  // dp[i+1][j+1]表示word1[0,i],word2[0,j]的最小操作次数
        
        for (i = 1; i <= size1; ++i) {
            dp[i][0] = i;
        }

        for (j = 1; j <= size2; ++j) {
            dp[0][j] = j;
        }

        for (i = 0; i < size1; ++i) {
            for (j = 0; j < size2; ++j) {
                int insertOperations = dp[i + 1][j] + 1;
                int deleteOperations = dp[i][j + 1] + 1;
                int replaceOperations = dp[i][j] + (word1[i] == word2[j] ? 0 : 1);
                dp[i + 1][j + 1] = min({ insertOperations,deleteOperations,replaceOperations });
            }
        }

        return dp[size1][size2];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.minDistance("horse", "ros"));
    check.checkInt(5, o.minDistance("intention", "execution"));
    check.checkInt(0, o.minDistance("", ""));
    check.checkInt(9, o.minDistance("intention", ""));
    check.checkInt(4, o.minDistance("", "exec"));
    check.checkInt(4, o.minDistance("abcdefg", "bdf"));
    check.checkInt(27, o.minDistance("pneumonoultramicroscopicsilicovolcanoconiosis", "ultramicroscopically"));
    check.checkInt(28, o.minDistance("pneumonoultramicroscopicsilicovolcanoconiosis", "ultramicroscopical"));
    check.checkInt(29, o.minDistance("pneumonoultramicroscopicsilicovolcanoconiosis", "ultramicroscopic"));
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
