/* K 连续位的最小翻转次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在仅包含 0 和 1 的数组 A 中，一次 K 位翻转包括选择一个长度为 K 的（连续）子数组，同时将子数组中的每个 0 更改为 1，而每个 1 更改为 0。

返回所需的 K 位翻转的最小次数，以便数组没有值为 0 的元素。如果不可能，返回 -1。

 

示例 1：

输入：A = [0,1,0], K = 1
输出：2
解释：先翻转 A[0]，然后翻转 A[2]。
示例 2：

输入：A = [1,1,0], K = 2
输出：-1
解释：无论我们怎样翻转大小为 2 的子数组，我们都不能使数组变为 [1,1,1]。
示例 3：

输入：A = [0,0,0,1,0,1,1,0], K = 3
输出：3
解释：
翻转 A[0],A[1],A[2]: A变成 [1,1,1,1,0,1,1,0]
翻转 A[4],A[5],A[6]: A变成 [1,1,1,1,1,0,0,0]
翻转 A[5],A[6],A[7]: A变成 [1,1,1,1,1,1,1,1]
 

提示：

1 <= A.length <= 30000
1 <= K <= A.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        A.push_back(1);  // 加一个1不影响结果，处理边界条件
        int i, size = A.size(), flips = 0, totalFlips = 0;
        queue<int> decIndices;

        for (i = 0; i < size; ++i) {
            if (!decIndices.empty() && i == decIndices.front()) {
                decIndices.pop();
                --flips;  // 一次翻转影响的k个数已经结束，flips减1
            }

            if ((flips & 1) == 1) {  // 翻转了奇数次，需要真的执行翻转动作
                A[i] ^= 1;
            }

            if (A[i] == 0) {  // 如果当前数是0，那么需要翻转它
                ++totalFlips;
                ++flips;
                decIndices.push(i + K);  // 记录下这次翻转结束的位置
            }
        }

        return decIndices.empty() ? totalFlips : -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 0,1,0 };
    check.checkInt(2, o.minKBitFlips(A, 1));

    A = { 1,1,0 };
    check.checkInt(-1, o.minKBitFlips(A, 2));

    A = { 0,1,1 };
    check.checkInt(-1, o.minKBitFlips(A, 2));

    A = { 0,0,0,1,0,1,1,0 };
    check.checkInt(3, o.minKBitFlips(A, 3));

    A = { 0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,1 };
    check.checkInt(7, o.minKBitFlips(A, 3));

    A = { 0 };
    check.checkInt(1, o.minKBitFlips(A, 1));

    A = { 1 };
    check.checkInt(0, o.minKBitFlips(A, 1));
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
