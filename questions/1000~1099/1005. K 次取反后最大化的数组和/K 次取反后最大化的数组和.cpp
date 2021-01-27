/* K 次取反后最大化的数组和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个个索引 i 并将 A[i] 替换为 -A[i]，然后总共重复这个过程 K 次。（我们可以多次选择同一个索引 i。）

以这种方式修改数组后，返回数组可能的最大和。

 

示例 1：

输入：A = [4,2,3], K = 1
输出：5
解释：选择索引 (1,) ，然后 A 变为 [4,-2,3]。
示例 2：

输入：A = [3,-1,0,2], K = 3
输出：6
解释：选择索引 (1, 2, 2) ，然后 A 变为 [3,1,0,2]。
示例 3：

输入：A = [2,-3,-1,5,-4], K = 2
输出：13
解释：选择索引 (1, 4) ，然后 A 变为 [2,3,-1,5,4]。
 

提示：

1 <= A.length <= 10000
1 <= K <= 10000
-100 <= A[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());

        int i, len = A.size(), sum = 0, negativeCount = 0, maxNegativeIndex = -1, minPositive = INT_MAX;
        for (i = 0; i < len; i++) {
            sum += A[i];

            if (A[i] < 0) {
                negativeCount++;
                maxNegativeIndex = i;
            }
        }

        if (maxNegativeIndex < (len - 1)) {
            minPositive = A[maxNegativeIndex + 1];
        }

        i = 0;
        while ((negativeCount > 0) && (K > 0)) {
            A[i] = (0 - A[i]);
            sum += (2 * A[i]);
            minPositive = min(minPositive, A[i]);
            i++;
            negativeCount--;
            K--;
        }

        if ((K % 2) != 0) {
            sum -= (2 * minPositive);
        }

        return sum;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 4,2,3 };
    check.checkInt(5, o.largestSumAfterKNegations(A, 1));

    A = { 3,-1,0,2 };
    check.checkInt(6, o.largestSumAfterKNegations(A, 3));

    A = { 2,-3,-1,5,-4 };
    check.checkInt(13, o.largestSumAfterKNegations(A, 2));

    A = { -4 };
    check.checkInt(4, o.largestSumAfterKNegations(A, 1));

    A = { -4 };
    check.checkInt(-4, o.largestSumAfterKNegations(A, 2));

    A = { 4 };
    check.checkInt(-4, o.largestSumAfterKNegations(A, 3));

    A = { -4,-3,-2 };
    check.checkInt(-1, o.largestSumAfterKNegations(A, 1));

    A = { -4,-3,-2 };
    check.checkInt(5, o.largestSumAfterKNegations(A, 2));

    A = { -4,-3,-2 };
    check.checkInt(9, o.largestSumAfterKNegations(A, 3));

    A = { -4,-3,-2 };
    check.checkInt(5, o.largestSumAfterKNegations(A, 4));

    A = { -4,-3,-2 };
    check.checkInt(9, o.largestSumAfterKNegations(A, 5));

    A = { -4,-3,-2,0 };
    check.checkInt(-1, o.largestSumAfterKNegations(A, 1));

    A = { -4,-3,-2,0 };
    check.checkInt(5, o.largestSumAfterKNegations(A, 2));

    A = { -4,-3,-2,0 };
    check.checkInt(9, o.largestSumAfterKNegations(A, 3));

    A = { -4,-3,-2,0 };
    check.checkInt(9, o.largestSumAfterKNegations(A, 4));

    A = { -4,-3,-2,0 };
    check.checkInt(9, o.largestSumAfterKNegations(A, 5));

    A = { -4,-3,-2,0 };
    check.checkInt(9, o.largestSumAfterKNegations(A, 6));

    A = { -4,-3,-2,0,1,2 };
    check.checkInt(2, o.largestSumAfterKNegations(A, 1));

    A = { -4,-3,-2,0,1,2 };
    check.checkInt(8, o.largestSumAfterKNegations(A, 2));

    A = { -4,-3,-2,0,1,2 };
    check.checkInt(12, o.largestSumAfterKNegations(A, 3));

    A = { -4,-3,-2,0,1,2 };
    check.checkInt(12, o.largestSumAfterKNegations(A, 4));

    A = { -4,-3,-2,0,1,2 };
    check.checkInt(12, o.largestSumAfterKNegations(A, 5));

    A = { -4,-3,-2,1,2 };
    check.checkInt(2, o.largestSumAfterKNegations(A, 1));

    A = { -4,-3,-2,1,2 };
    check.checkInt(8, o.largestSumAfterKNegations(A, 2));

    A = { -4,-3,-2,1,2 };
    check.checkInt(12, o.largestSumAfterKNegations(A, 3));

    A = { -4,-3,-2,1,2 };
    check.checkInt(10, o.largestSumAfterKNegations(A, 4));

    A = { -4,-3,-2,1,2 };
    check.checkInt(12, o.largestSumAfterKNegations(A, 5));

    A = { -4,-3,-2,1,2 };
    check.checkInt(10, o.largestSumAfterKNegations(A, 6));

    A = { 0,1,2 };
    check.checkInt(3, o.largestSumAfterKNegations(A, 1));

    A = { 0,1,2 };
    check.checkInt(3, o.largestSumAfterKNegations(A, 2));

    A = { 1,2 };
    check.checkInt(1, o.largestSumAfterKNegations(A, 1));

    A = { 1,2 };
    check.checkInt(3, o.largestSumAfterKNegations(A, 2));

    A = { 1,2 };
    check.checkInt(1, o.largestSumAfterKNegations(A, 3));
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
