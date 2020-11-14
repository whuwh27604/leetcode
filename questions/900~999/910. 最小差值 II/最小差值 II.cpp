/* 最小差值 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 A，对于每个整数 A[i]，我们可以选择 x = -K 或是 x = K，并将 x 加到 A[i] 中。

在此过程之后，我们得到一些数组 B。

返回 B 的最大值和 B 的最小值之间可能存在的最小差值。

 

示例 1：

输入：A = [1], K = 0
输出：0
解释：B = [1]
示例 2：

输入：A = [0,10], K = 2
输出：6
解释：B = [2,8]
示例 3：

输入：A = [1,3,6], K = 3
输出：3
解释：B = [4,6,3]
 

提示：

1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-range-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());

        int i, size = A.size();
        int minimum = A[0], maximum = A.back(), smallestRange = maximum - minimum;

        for (i = 0; i < size - 1; ++i) {
            int high = max(A[i] + K, maximum - K);
            int low = min(minimum + K, A[i + 1] - K);
            smallestRange = min(smallestRange, high - low);
        }

        return smallestRange;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 1 };
    check.checkInt(0, o.smallestRangeII(A, 0));

    A = { 0,10 };
    check.checkInt(6, o.smallestRangeII(A, 2));

    A = { 1,3,6 };
    check.checkInt(3, o.smallestRangeII(A, 3));
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
