/* 使数组唯一的最小增量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定整数数组 A，每次 move 操作将会选择任意 A[i]，并将其递增 1。

返回使 A 中的每个值都是唯一的最少操作次数。

示例 1:

输入：[1,2,2]
输出：1
解释：经过一次 move 操作，数组将变为 [1, 2, 3]。
示例 2:

输入：[3,2,1,2,1,7]
输出：6
解释：经过 6 次 move 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
可以看出 5 次或 5 次以下的 move 操作是不能让数组的每个值唯一的。
提示：

0 <= A.length <= 40000
0 <= A[i] < 40000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int* numsCount = new int[40001]();
        int i, unique = 0, increment = 0;

        for (int num : A) {
            ++numsCount[num];
        }

        for (i = 0; i < 40001; ++i) {
            if (numsCount[i] == 0) {
                continue;
            }

            if (i > unique) {
                increment += ((numsCount[i] - 1) * numsCount[i] / 2);
                unique = i + numsCount[i];
            }
            else {
                increment += (((unique - i) + (unique + numsCount[i] - 1 - i)) * numsCount[i] / 2);
                unique += numsCount[i];
            }
        }

        delete[] numsCount;

        return increment;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 1,2,2 };
    check.checkInt(1, o.minIncrementForUnique(A));

    A = { 3,2,1,2,1,7 };
    check.checkInt(6, o.minIncrementForUnique(A));

    A = {  };
    check.checkInt(0, o.minIncrementForUnique(A));

    A = { 7 };
    check.checkInt(0, o.minIncrementForUnique(A));

    A = { 7,7 };
    check.checkInt(1, o.minIncrementForUnique(A));

    A = { 0,0,0 };
    check.checkInt(3, o.minIncrementForUnique(A));

    A = { 0,0,0,1,1,1,1,2,2,2,2,2 };
    check.checkInt(52, o.minIncrementForUnique(A));

    A = { 0,0,0,1,1,1,1,2,2,2,2,2,11 };
    check.checkInt(53, o.minIncrementForUnique(A));

    A = { 0,0,0,1,1,1,1,2,2,2,2,2,12 };
    check.checkInt(52, o.minIncrementForUnique(A));

    A = { 4,3,2,1 };
    check.checkInt(0, o.minIncrementForUnique(A));

    A = { 40000,40000,40000 };
    check.checkInt(3, o.minIncrementForUnique(A));

    A = { 0,0,0,0,40000,40000,40000 };
    check.checkInt(9, o.minIncrementForUnique(A));
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
