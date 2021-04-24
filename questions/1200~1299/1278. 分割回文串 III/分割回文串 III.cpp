/* 分割回文串 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由小写字母组成的字符串 s，和一个整数 k。

请你按下面的要求分割字符串：

首先，你可以将 s 中的部分字符修改为其他的小写英文字母。
接着，你需要把 s 分割成 k 个非空且不相交的子串，并且每个子串都是回文串。
请返回以这种方式分割字符串所需修改的最少字符数。

 

示例 1：

输入：s = "abc", k = 2
输出：1
解释：你可以把字符串分割成 "ab" 和 "c"，并修改 "ab" 中的 1 个字符，将它变成回文串。
示例 2：

输入：s = "aabbc", k = 3
输出：0
解释：你可以把字符串分割成 "aa"、"bb" 和 "c"，它们都是回文串。
示例 3：

输入：s = "leetcode", k = 8
输出：0
 

提示：

1 <= k <= s.length <= 100
s 中只含有小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int palindromePartition(string s, int k) {
        int index, partitions, lastStart, size = s.size();
        vector<vector<int>> dp(size, vector<int>(k + 1, INT_MAX));
        dp[0][1] = 0;  // dp[index][partitions]表示区间s[0,index]分割为partitions个子串需要修改的最小次数

        vector<vector<int>> costs(size, vector<int>(size));
        getCosts(s, costs);  // 预处理任意区间变为回文串需要的修改次数

        for (index = 1; index < size; ++index) {
            dp[index][1] = costs[0][index];  // 区间s[0,index]分割为1个子串需要修改的最小次数

            for (partitions = 2; partitions <= k; ++partitions) {  // 依次计算分割为2到k个子串的最小次数
                for (lastStart = index; lastStart >= partitions - 1; --lastStart) {  // 遍历最后一个子串可能的起始位置
                    dp[index][partitions] = min(dp[index][partitions], dp[lastStart - 1][partitions - 1] + costs[lastStart][index]);  // 最后一个子串的开销加上前面部分分割为partitions-1个子串的开销
                }
            }
        }

        return dp[size - 1][k];
    }

    void getCosts(string& s, vector<vector<int>>& costs) {
        int i, j, size = s.size();

        for (i = 0; i < size; ++i) {
            for (j = i; j < size; ++j) {
                int left = i, right = j, cost = 0;

                while (left < right) {
                    if (s[left++] != s[right--]) {
                        ++cost;
                    }
                }

                costs[i][j] = cost;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(0, o.palindromePartition("z", 1));
    check.checkInt(1, o.palindromePartition("abc", 2));
    check.checkInt(0, o.palindromePartition("aabbc", 3));
    check.checkInt(0, o.palindromePartition("leetcode", 8));
    check.checkInt(17, o.palindromePartition("dfafakhfahdfakldhfaklhfakhdfkahfaklhfakhfaklhfalkhfalkhfalkhfakhfahflka", 8));
    check.checkInt(30, o.palindromePartition("ewyriuaksfhkfhnzxnafklhffalsfsfhaerouydfhznykweknfdnafhasfhhklhdflkahlkhzfnzxnhklaeyriklhdfklhakfzxn", 10));
    check.checkInt(43, o.palindromePartition("ewyriuaksfhkfhnzxnafklhffalsfsfhaerouydfhznykweknfdnafhasfhhklhdflkahlkhzfnzxnhklaeyriklhdfklhakfzxn", 1));
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
