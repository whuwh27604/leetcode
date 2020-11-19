/* 多边形三角剖分的最低得分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定 N，想象一个凸 N 边多边形，其顶点按顺时针顺序依次标记为 A[0], A[i], ..., A[N-1]。

假设您将多边形剖分为 N-2 个三角形。对于每个三角形，该三角形的值是顶点标记的乘积，三角剖分的分数是进行三角剖分后所有 N-2 个三角形的值之和。

返回多边形进行三角剖分后可以得到的最低分。
 

示例 1：

输入：[1,2,3]
输出：6
解释：多边形已经三角化，唯一三角形的分数为 6。
示例 2：



输入：[3,7,4,5]
输出：144
解释：有两种三角剖分，可能得分分别为：3*7*5 + 4*5*7 = 245，或 3*4*5 + 3*4*7 = 144。最低分数为 144。
示例 3：

输入：[1,3,1,4,1,5]
输出：13
解释：最低分数三角剖分的得分情况为 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13。
 

提示：

3 <= A.length <= 50
1 <= A[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-score-triangulation-of-polygon
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        /* 固定住A[n-1]A[0]这条边，另外一个顶点A[i]遍历A[1]...A[n-2]，每次多边形被剖分为三部分，三角形A[n-1]A[0]A[i]，三角形左边的多边形A[0]A[1]...A[i]，
           三角形右边的多边形A[i]A[i+1]...A[n-2]A[n-1]。令dp[start][end]表示从start到end的多边形能够得到的最低分，则A[i]每一次剖分能够得到的分数为：
           A[n-1]A[0]A[i]+dp[0][i]+dp[i][n-1]，取最小的得分就是答案。
           固定的边并不需要遍历A[0]A[1]...A[n-2]A[n-1]，因为在每一种剖分方案中，一定存在一个三角形有一条边是A[n-1]A[0]*/
        int size = A.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));

        for (int len = 3; len <= size; ++len) {
            for (int start = 0; start + len <= size; ++start) {
                int end = start + len - 1;
                dp[start][end] = INT_MAX;
                for (int i = start + 1; i < end; ++i) {
                    dp[start][end] = min(dp[start][end], A[start] * A[end] * A[i] + dp[start][i] + dp[i][end]);
                }
            }
        }

        return dp[0][size - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 1,2,3 };
    check.checkInt(6, o.minScoreTriangulation(A));

    A = { 3,7,4,5 };
    check.checkInt(144, o.minScoreTriangulation(A));

    A = { 1,3,1,4,1,5 };
    check.checkInt(13, o.minScoreTriangulation(A));
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
