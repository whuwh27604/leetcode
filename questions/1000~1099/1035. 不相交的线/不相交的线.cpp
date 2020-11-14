/* 不相交的线.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们在两条独立的水平线上按给定的顺序写下 A 和 B 中的整数。

现在，我们可以绘制一些连接两个数字 A[i] 和 B[j] 的直线，只要 A[i] == B[j]，且我们绘制的直线不与任何其他连线（非水平线）相交。

以这种方法绘制线条，并返回我们可以绘制的最大连线数。

 

示例 1：



输入：A = [1,4,2], B = [1,2,4]
输出：2
解释：
我们可以画出两条不交叉的线，如上图所示。
我们无法画出第三条不相交的直线，因为从 A[1]=4 到 B[2]=4 的直线将与从 A[2]=2 到 B[1]=2 的直线相交。
示例 2：

输入：A = [2,5,1,2,5], B = [10,5,2,1,5,2]
输出：3
示例 3：

输入：A = [1,3,7,1,7,5], B = [1,9,2,5,1]
输出：2
 

提示：

1 <= A.length <= 500
1 <= B.length <= 500
1 <= A[i], B[i] <= 2000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/uncrossed-lines
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int i, j, sizeA = A.size(), sizeB = B.size();
        vector<vector<int>> dp(sizeA + 1, vector<int>(sizeB + 1, 0));  // dp[i][j]表示数组A[i,sizeA)和B[j,sizeB)能够绘制的最大连线数

        for (i = sizeA - 1; i >= 0; --i) {
            for (j = sizeB - 1; j >= 0; --j) {
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        return dp[0][0];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 1,4,2 };
    vector<int> B = { 1,2,4 };
    check.checkInt(2, o.maxUncrossedLines(A, B));

    A = { 2,5,1,2,5 };
    B = { 10,5,2,1,5,2 };
    check.checkInt(3, o.maxUncrossedLines(A, B));

    A = { 1,3,7,1,7,5 };
    B = { 1,9,2,5,1 };
    check.checkInt(2, o.maxUncrossedLines(A, B));

    A = { 2 };
    B = { 10 };
    check.checkInt(0, o.maxUncrossedLines(A, B));

    A = { 5 };
    B = { 5 };
    check.checkInt(1, o.maxUncrossedLines(A, B));
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
