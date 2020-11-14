/* 全局倒置与局部倒置.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
数组 A 是 [0, 1, ..., N - 1] 的一种排列，N 是数组 A 的长度。全局倒置指的是 i,j 满足 0 <= i < j < N 并且 A[i] > A[j] ，局部倒置指的是 i 满足 0 <= i < N 并且 A[i] > A[i+1] 。

当数组 A 中全局倒置的数量等于局部倒置的数量时，返回 true 。

 

示例 1:

输入: A = [1,0,2]
输出: true
解释: 有 1 个全局倒置，和 1 个局部倒置。
示例 2:

输入: A = [1,2,0]
输出: false
解释: 有 2 个全局倒置，和 1 个局部倒置。
注意:

A 是 [0, 1, ..., A.length - 1] 的一种排列
A 的长度在 [1, 5000]之间
这个问题的时间限制已经减少了。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/global-and-local-inversions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        /* 局部倒置一定是全局倒置，全局倒置不一定是局部倒置。要使全局倒置都是局部倒置，只能Ai和Ai+1交换。
           假设Ai和Aj(j-i>1)交换，则存在Aj>Aj-1>Ai，此时Aj和Aj-1构成局部倒置，Aj和Ai构成了不是局部倒置的全局倒置 */
        for (int i = 0; i < (int)A.size(); i++) {
            if (abs(A[i] - i) > 1) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 0 };
    check.checkBool(true, o.isIdealPermutation(A));

    A = { 0,1 };
    check.checkBool(true, o.isIdealPermutation(A));

    A = { 1,0 };
    check.checkBool(true, o.isIdealPermutation(A));

    A = { 0,1,2 };
    check.checkBool(true, o.isIdealPermutation(A));

    A = { 0,2,1 };
    check.checkBool(true, o.isIdealPermutation(A));

    A = { 1,0,2 };
    check.checkBool(true, o.isIdealPermutation(A));

    A = { 1,2,0 };
    check.checkBool(false, o.isIdealPermutation(A));

    A = { 2,0,1 };
    check.checkBool(false, o.isIdealPermutation(A));

    A = { 2,1,0 };
    check.checkBool(false, o.isIdealPermutation(A));

    A = { 0,3,2,1 };
    check.checkBool(false, o.isIdealPermutation(A));
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
