/* 旋转函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个长度为 n 的整数数组 A 。

假设 Bk 是数组 A 顺时针旋转 k 个位置后的数组，我们定义 A 的“旋转函数” F 为：

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1]。

计算F(0), F(1), ..., F(n-1)中的最大值。

注意:
可以认为 n 的值小于 105。

示例:

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

所以 F(0), F(1), F(2), F(3) 中的最大值是 F(3) = 26 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-function
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int i, size = A.size();
        long long prevFk = 0, currentFk, maxFk = LLONG_MIN, sum = 0;

        for (i = 0; i < size; i++) {
            sum += A[i];
            prevFk += (i * A[i]);
        }
        maxFk = prevFk;

        for (i = 1; i < size; i++) {
            currentFk = prevFk + sum - (long long)size * A[size - i];
            maxFk = max(maxFk, currentFk);
            prevFk = currentFk;
        }

        return (int)maxFk;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 4,3,2,6 };
    check.checkInt(26, o.maxRotateFunction(A));

    A = {  };
    check.checkInt(0, o.maxRotateFunction(A));
    
    A = { 5 };
    check.checkInt(0, o.maxRotateFunction(A));

    A = { 3,5 };
    check.checkInt(5, o.maxRotateFunction(A));

    A = { 5,3 };
    check.checkInt(5, o.maxRotateFunction(A));

    A = { 7,9,5 };
    check.checkInt(25, o.maxRotateFunction(A));

    A = { INT_MAX, INT_MAX };
    check.checkInt(INT_MAX, o.maxRotateFunction(A));
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
