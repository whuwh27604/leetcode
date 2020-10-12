/* 最大宽度坡.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 A，坡是元组 (i, j)，其中  i < j 且 A[i] <= A[j]。这样的坡的宽度为 j - i。

找出 A 中的坡的最大宽度，如果不存在，返回 0 。

 

示例 1：

输入：[6,0,8,2,1,5]
输出：4
解释：
最大宽度的坡为 (i, j) = (1, 5): A[1] = 0 且 A[5] = 5.
示例 2：

输入：[9,8,1,0,1,9,4,0,4,1]
输出：7
解释：
最大宽度的坡为 (i, j) = (2, 9): A[2] = 1 且 A[9] = 1.
 

提示：

2 <= A.length <= 50000
0 <= A[i] <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-width-ramp
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int i, size = A.size(), prevIndex = 0, maxWidth = 0;
        stack<int> decreasingIndices;
        decreasingIndices.push(0);

        for (i = 1; i < size; ++i) {  // 构造单调递减栈，保存相应的index
            if (A[i] < A[decreasingIndices.top()]) {
                decreasingIndices.push(i);
            }
        }

        /* 以9,8,1,0,1,9,4,0,4,1为例，栈里面是[9,0],[8,1],[1,2],[0,3]
           考虑[1,9]，最大匹配到[1,2]，长度为7。此时可以将[0,3]、[1，2]pop出栈，因为在[1,2]和[1,9]之间大于0、1小于8的数都将匹配到[1,2]和[0,3]，而这个匹配长度肯定小于7。
           同理考虑[9,5]，最大匹配到[9，0]，长度为5。最后只需要找出这个匹配长度最大的就是答案。 */
        for (i = size - 1; i > maxWidth; --i) {
            while (!decreasingIndices.empty() && A[i] >= A[decreasingIndices.top()]) {
                prevIndex = decreasingIndices.top();
                decreasingIndices.pop();
            }

            maxWidth = max(maxWidth, i - prevIndex);
        }

        return maxWidth;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 6,0,8,2,1,5 };
    check.checkInt(4, o.maxWidthRamp(A));

    A = { 9,8,1,0,1,9,4,0,4,1 };
    check.checkInt(7, o.maxWidthRamp(A));

    A = { 3,28,15,1,4,12,6,19,8,15,3,9,6,4,13,12,6,12,10,1,2,1,4,1,4,0,0,1,1,0 };
    check.checkInt(25, o.maxWidthRamp(A));

    A = { 1,2 };
    check.checkInt(1, o.maxWidthRamp(A));

    A = { 2,1 };
    check.checkInt(0, o.maxWidthRamp(A));
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
