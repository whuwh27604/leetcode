/* 最短公共超序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出两个字符串 str1 和 str2，返回同时以 str1 和 str2 作为子序列的最短字符串。如果答案不止一个，则可以返回满足条件的任意一个答案。

（如果从字符串 T 中删除一些字符（也可能不删除，并且选出的这些字符可以位于 T 中的 任意位置），可以得到字符串 S，那么 S 就是 T 的子序列）

 

示例：

输入：str1 = "abac", str2 = "cab"
输出："cabac"
解释：
str1 = "abac" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 的第一个 "c"得到 "abac"。
str2 = "cab" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 末尾的 "ac" 得到 "cab"。
最终我们给出的答案是满足上述属性的最短字符串。
 

提示：

1 <= str1.length, str2.length <= 1000
str1 和 str2 都由小写英文字母组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-common-supersequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int i, j, size1 = str1.size(), size2 = str2.size(), inf = 100000;
        if (size1 < size2) {
            return shortestCommonSupersequence(str2, str1);
        }

        string ans;
        vector<vector<int>> trans(size1 + 1, vector<int>(size2 + 1, -1));  // 默认选择插入str2首字符
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, inf));
        
        init(dp, size1, size2);

        for (j = size2 - 1; j >= 0; --j) {
            int first = size1;

            for (i = size1 - 1; i >= 0; --i) {
                if (str1[i] == str2[j]) {
                    first = i;  // 记录str1第一次出现str2的首字符的位置
                }

                /* 两种选择：1、不匹配首字符，那么需要在str1前面插入str2的首字符
                   2、匹配首字符（如果可以匹配，不能匹配就只能选择方案1），然后剩下的字符串继续计算SCS */
                int len1 = dp[i][j + 1] + 1, len2 = first < size1 ? (first + 1 - i) + dp[first + 1][j + 1] : inf;

                if (len1 < len2) {  // 两种方案选小的，同时记录下dp转移的方式
                    dp[i][j] = len1;
                    trans[i][j] = -1;
                }
                else {
                    dp[i][j] = len2;
                    trans[i][j] = first;
                }
            }
        }

        return getSCS(str1, str2, trans);
    }

    void init(vector<vector<int>>& dp, int size1, int size2) {
        dp[size1][size2] = 0;  // 两边都不需要任何字符，SCS等于0

        for (int i = size1 - 1; i >= 0; --i) {
            dp[i][size2] = size1 - i;  // 当一边的str不需要任何字符时，SCS就是另外一个的长度
        }

        for (int j = size2 - 1; j >= 0; --j) {
            dp[size1][j] = size2 - j;  // 当一边的str不需要任何字符时，SCS就是另外一个的长度
        }
    }

    string getSCS(string& str1, string& str2, vector<vector<int>>& trans) {
        int i = 0, j, size1 = str1.size(), size2 = str2.size();
        string SCS;

        for (j = 0; j < size2; ++j) {
            if (trans[i][j] == -1) {  // 插入str2的首字符
                SCS.push_back(str2[j]);
            }
            else {  // 匹配str2的首字符，str1从当前字符一直拷贝到第一次出现str2首字符的位置
                SCS += string(str1, i, trans[i][j] - i + 1);
                i = trans[i][j] + 1;
            }
        }

        SCS += string(str1, i, size1 - i);  // str1如果还没有匹配完，把剩余的字符加上

        return SCS;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("cabac", o.shortestCommonSupersequence("abac", "cab"));
    check.checkString("cabac", o.shortestCommonSupersequence("cab", "abac"));
    check.checkString("a", o.shortestCommonSupersequence("a", "a"));
    check.checkString("ba", o.shortestCommonSupersequence("a", "b"));
    check.checkString("bbbaaababbb", o.shortestCommonSupersequence("bbbaaaba", "bbababbb"));
    check.checkString("ewreryuiyfhmfdxhkfhcvfroihhhhhhhhhhhhhhhhz", o.shortestCommonSupersequence("ewryufhmfdhhhhhhhhhhhhhhhhhhz", "ereruiyfdxhkfhcvfroi"));
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
