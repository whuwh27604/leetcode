/* 可被 5 整除的二进制前缀.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定由若干 0 和 1 组成的数组 A。我们定义 N_i：从 A[0] 到 A[i] 的第 i 个子数组被解释为一个二进制数（从最高有效

位到最低有效位）。

返回布尔值列表 answer，只有当 N_i 可以被 5 整除时，答案 answer[i] 为 true，否则为 false。

 

示例 1：

输入：[0,1,1]
输出：[true,false,false]
解释：
输入数字为 0, 01, 011；也就是十进制中的 0, 1, 3 。只有第一个数可以被 5 整除，因此 answer[0] 为真。
示例 2：

输入：[1,1,1]
输出：[false,false,false]
示例 3：

输入：[0,1,1,1,1,1]
输出：[true,false,false,false,true,false]
示例 4：

输入：[1,1,1,0,1]
输出：[false,false,false,false,false]
 

提示：

1 <= A.length <= 30000
A[i] 为 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-prefix-divisible-by-5
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans(A.size());
        int remainder = 0, index = 0;

        for (int num : A) {
            remainder = ((remainder * 2 + num) % 5);
            ans[index++] = (remainder == 0);
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 0,1,1 };
    vector<bool> actual = o.prefixesDivBy5(A);
    vector<bool> expected = { true,false,false };
    check.checkBoolVector(expected, actual);

    A = { 1,1,1 };
    actual = o.prefixesDivBy5(A);
    expected = { false,false,false };
    check.checkBoolVector(expected, actual);

    A = { 0,1,1,1,1,1 };
    actual = o.prefixesDivBy5(A);
    expected = { true,false,false,false,true,false };
    check.checkBoolVector(expected, actual);

    A = { 1,1,1,0,1 };
    actual = o.prefixesDivBy5(A);
    expected = { false,false,false,false,false };
    check.checkBoolVector(expected, actual);
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
