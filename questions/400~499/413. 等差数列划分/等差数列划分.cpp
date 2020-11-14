/* 等差数列划分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果一个数列至少有三个元素，并且任意两个相邻元素之差相同，则称该数列为等差数列。

例如，以下数列为等差数列:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
以下数列不是等差数列。

1, 1, 2, 5, 7
 

数组 A 包含 N 个数，且索引从0开始。数组 A 的一个子数组划分为数组 (P, Q)，P 与 Q 是整数且满足 0<=P<Q<N 。

如果满足以下条件，则称子数组(P, Q)为等差数组：

元素 A[P], A[p + 1], ..., A[Q - 1], A[Q] 是等差的。并且 P + 1 < Q 。

函数要返回数组 A 中所有为等差数组的子数组个数。

 

示例:

A = [1, 2, 3, 4]

返回: 3, A 中有三个子等差数组: [1, 2, 3], [2, 3, 4] 以及自身 [1, 2, 3, 4]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/arithmetic-slices
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int i, size = A.size();
        long long consectiveNumber = 2, arithmeticSlicesNumber = 0;

        for (i = 2; i < size; i++) {
            if (((long long)A[i] - A[i - 1]) == ((long long)A[i - 1] - A[i - 2])) {
                consectiveNumber++;
            }
            else if (consectiveNumber > 2) {  // n个数分别连续3,4...n个一组，可以有n-2,n-3...1种组合，共(n-2)+(n-3)+...+1=(n-2)*(n-1)/2种
                arithmeticSlicesNumber += ((consectiveNumber - 2) * (consectiveNumber - 1) / 2);
                consectiveNumber = 2;
            }
        }

        if (consectiveNumber > 2) {
            arithmeticSlicesNumber += ((consectiveNumber - 2) * (consectiveNumber - 1) / 2);
        }

        return (int)arithmeticSlicesNumber;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 1,2,3,4 };
    check.checkInt(3, o.numberOfArithmeticSlices(A));
    
    A = {  };
    check.checkInt(0, o.numberOfArithmeticSlices(A));

    A = { 1 };
    check.checkInt(0, o.numberOfArithmeticSlices(A));

    A = { 1,2 };
    check.checkInt(0, o.numberOfArithmeticSlices(A));

    A = { 1,2,3 };
    check.checkInt(1, o.numberOfArithmeticSlices(A));

    A = { 1,2,1 };
    check.checkInt(0, o.numberOfArithmeticSlices(A));

    A = { 1,1,1,1 };
    check.checkInt(3, o.numberOfArithmeticSlices(A));

    A = { 2,1,1,1 };
    check.checkInt(1, o.numberOfArithmeticSlices(A));

    A = { 1,1,1,2 };
    check.checkInt(1, o.numberOfArithmeticSlices(A));

    A = { 1,1,1,2,2,3,3,3,4,5,5,5 };
    check.checkInt(4, o.numberOfArithmeticSlices(A));

    A = { 0,0,1,1,1,1,2,2,2,3,3,3,3,3,4 };
    check.checkInt(10, o.numberOfArithmeticSlices(A));

    A = { INT_MAX, 1, INT_MIN };
    check.checkInt(0, o.numberOfArithmeticSlices(A));

    A = { INT_MAX, 0, INT_MIN + 1 };
    check.checkInt(1, o.numberOfArithmeticSlices(A));
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
