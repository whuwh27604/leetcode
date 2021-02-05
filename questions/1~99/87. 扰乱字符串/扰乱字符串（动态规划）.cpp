/* 扰乱字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。

下图是字符串 s1 = "great" 的一种可能的表示形式。

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。

例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
我们将 "rgeat” 称作 "great" 的一个扰乱字符串。

同样地，如果我们继续交换节点 "eat" 和 "at" 的子节点，将会产生另一个新的扰乱字符串 "rgtae" 。

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
我们将 "rgtae” 称作 "great" 的一个扰乱字符串。

给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。

示例 1:

输入: s1 = "great", s2 = "rgeat"
输出: true
示例 2:

输入: s1 = "abcde", s2 = "caebd"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/scramble-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int i, j, size = s1.size();
        /* 将区间s[u,v]映射到索引u*size+v，那么dp[x][y]就表示区间s1[x]=s1[u1,v1]和区间s2[y]=s2[u2,v2]是否满足条件 */
        vector<vector<bool>> dp(size * size, vector<bool>(size * size));

        for (i = 0; i < size; ++i) {
            for (j = 0; j < size; ++j) {
                dp[i * size + i][j * size + j] = (s1[i] == s2[j]);
            }
        }

        for (int sectionLen = 2; sectionLen <= size; ++sectionLen) {
            for (i = 0; i <= size - sectionLen; ++i) {
                for (j = 0; j <= size - sectionLen; ++j) {
                    int x = i * size + i + sectionLen - 1, y = j * size + j + sectionLen - 1;

                    for (int splitLen = 1; splitLen < sectionLen; ++splitLen) {
                        // s1、s2都从前往后划分，区间[i,i+sectionLen-1]划分为[i,i+splitLen-1]和[i+splitLen,i+sectionLen-1]
                        int u11 = i, v11 = i + splitLen - 1, u12 = i + splitLen, v12 = i + sectionLen - 1;
                        int u21 = j, v21 = j + splitLen - 1, u22 = j + splitLen, v22 = j + sectionLen - 1;
                        dp[x][y] = dp[u11 * size + v11][u21 * size + v21] && dp[u12 * size + v12][u22 * size + v22];
                        if (dp[x][y]) {
                            break;
                        }

                        // s1从前往后划分，s2从后往前划分为[j,j+sectionLen-splitLen-1]和[j+sectionLen-splitLen,j+sectionLen-1]
                        v21 = j + sectionLen - splitLen - 1, u22 = j + sectionLen - splitLen;
                        dp[x][y] = dp[u11 * size + v11][u22 * size + v22] && dp[u12 * size + v12][u21 * size + v21];
                        if (dp[x][y]) {
                            break;
                        }
                    }
                }
            }
        }

        return dp[size - 1][size - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.isScramble("abb", "bab"));
    check.checkBool(true, o.isScramble("great", "rgeat"));
    check.checkBool(false, o.isScramble("abcde", "caebd"));
    check.checkBool(true, o.isScramble("sasa", "ssaa"));
    check.checkBool(true, o.isScramble("asasa", "ssaaa"));
    check.checkBool(true, o.isScramble("sasasa", "sssaaa"));
    check.checkBool(true, o.isScramble("abcdefghijklmnopqrstuvwxyzxyzz", "zzyxzyxwvutsrqponmlkjihgfedcba"));
    check.checkBool(false, o.isScramble("abcdefghijklmnopqrstuvwxyzxyzz", "zzyxzyxwvutsrqppnmlkjihgfedcba"));
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
