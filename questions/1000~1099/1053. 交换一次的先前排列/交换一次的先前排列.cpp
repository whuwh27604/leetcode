/* 交换一次的先前排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数的数组 A（其中的元素不一定完全不同），请你返回可在 一次交换（交换两数字 A[i] 和 A[j] 的位置）后得到的、按字典序排列小于 A 的最大可能排列。

如果无法这么操作，就请返回原数组。

 

示例 1：

输入：[3,2,1]
输出：[3,1,2]
解释：
交换 2 和 1
 

示例 2：

输入：[1,1,5]
输出：[1,1,5]
解释：
这已经是最小排列
 

示例 3：

输入：[1,9,4,6,7]
输出：[1,7,4,6,9]
解释：
交换 9 和 7
 

示例 4：

输入：[3,1,1,3]
输出：[1,3,1,3]
解释：
交换 1 和 3
 

提示：

1 <= A.length <= 10000
1 <= A[i] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/previous-permutation-with-one-swap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        /* 1、假设交换的是P、Q，因为要变小，所以一定有P>Q
           2、需要是小的里面最大的，所以要交换最后的P、Q，比如987321，需要交换2、1而不是9、8
           3、如果P有重复，选择最后一个P，比如332变为323；如果Q有重复，选择第一个Q，比如322变为232
           综上，利用单调栈从后往前找第一个升序 */
        int p, q = -1, size = A.size();
        stack<int> decreasing;
        decreasing.push(size - 1);

        for (p = size - 2; p >= 0; --p) {
            if (A[p] < A[decreasing.top()]) {
                decreasing.push(p);
            }
            else if (A[p] == A[decreasing.top()]) {
                do {
                    decreasing.pop();
                } while (!decreasing.empty() && A[p] == A[decreasing.top()]);

                decreasing.push(p);
            }
            else {
                do {
                    q = decreasing.top();
                    decreasing.pop();
                } while (!decreasing.empty() && A[p] > A[decreasing.top()]);

                break;
            }
        }

        if (q != -1) {
            swap(A[p], A[q]);
        }

        return A;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 1,0 };
    vector<int> actual = o.prevPermOpt1(A);
    vector<int> expected = { 0,1 };
    check.checkIntVector(expected, actual);

    A = { 3,2,1 };
    actual = o.prevPermOpt1(A);
    expected = { 3,1,2 };
    check.checkIntVector(expected, actual);

    A = { 1,1,5 };
    actual = o.prevPermOpt1(A);
    expected = { 1,1,5 };
    check.checkIntVector(expected, actual);

    A = { 1,9,4,6,7 };
    actual = o.prevPermOpt1(A);
    expected = { 1,7,4,6,9 };
    check.checkIntVector(expected, actual);

    A = { 3,1,1,3 };
    actual = o.prevPermOpt1(A);
    expected = { 1,3,1,3 };
    check.checkIntVector(expected, actual);

    A = { 9,8,7,3,2,1 };
    actual = o.prevPermOpt1(A);
    expected = { 9,8,7,3,1,2 };
    check.checkIntVector(expected, actual);

    A = { 3 };
    actual = o.prevPermOpt1(A);
    expected = { 3 };
    check.checkIntVector(expected, actual);

    A = { 3,3,2 };
    actual = o.prevPermOpt1(A);
    expected = { 3,2,3 };
    check.checkIntVector(expected, actual);

    A = { 3,2,2 };
    actual = o.prevPermOpt1(A);
    expected = { 2,3,2 };
    check.checkIntVector(expected, actual);

    A = { 3,1,1,3 };
    actual = o.prevPermOpt1(A);
    expected = { 1,3,1,3 };
    check.checkIntVector(expected, actual);
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
