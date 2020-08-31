/* 不同的二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

/* 分别以1~n为根节点，可以组成不同的二叉搜索树，所以dp[n]=sum(dp[n-1]*dp[0], dp[n-2]*dp[1] ... dp[1]dp[n-2], dp[0]dp[n-1]) */
class Solution {
public:
    int numTrees(int n) {
        int* dp = new int[n + 1]();
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            int start = i - 1, end = 0;
            for (; start > end; start--, end++) {
                dp[i] += (dp[start] * dp[end]);
            }

            dp[i] *= 2;
            if (start == end) {
                dp[i] += (dp[start] * dp[end]);
            }
        }

        int ans = dp[n];
        delete[] dp;

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(1, o.numTrees(0));
    check.checkInt(1, o.numTrees(1));
    check.checkInt(2, o.numTrees(2));
    check.checkInt(5, o.numTrees(3));
    check.checkInt(16796, o.numTrees(10));
    check.checkInt(1767263190, o.numTrees(19));
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
