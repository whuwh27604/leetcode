/* 按位与为零的三元组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 A，找出索引为 (i, j, k) 的三元组，使得：

0 <= i < A.length
0 <= j < A.length
0 <= k < A.length
A[i] & A[j] & A[k] == 0，其中 & 表示按位与（AND）操作符。
 

示例：

输入：[2,1,3]
输出：12
解释：我们可以选出如下 i, j, k 三元组：
(i=0, j=0, k=1) : 2 & 2 & 1
(i=0, j=1, k=0) : 2 & 1 & 2
(i=0, j=1, k=1) : 2 & 1 & 1
(i=0, j=1, k=2) : 2 & 1 & 3
(i=0, j=2, k=1) : 2 & 3 & 1
(i=1, j=0, k=0) : 1 & 2 & 2
(i=1, j=0, k=1) : 1 & 2 & 1
(i=1, j=0, k=2) : 1 & 2 & 3
(i=1, j=1, k=0) : 1 & 1 & 2
(i=1, j=2, k=0) : 1 & 3 & 2
(i=2, j=0, k=1) : 3 & 2 & 1
(i=2, j=1, k=0) : 3 & 1 & 2
 

提示：

1 <= A.length <= 1000
0 <= A[i] < 2^16

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/triples-with-bitwise-and-equal-to-zero
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& A) {
        /* 先统计两两相与的结果出现的数量，然后枚举第三个数，匹配与的结果为0的数。
           关键点：由于两数相与的结果只会变小，而A[i]<2^16，所以这不是一个n的三次方算法，而是n*2^16
           同时还有更巧妙的方法将枚举第三个数的复杂度降到nlog(maxA) */
        int maxNum = *max_element(A.begin(), A.end());
        int mask = getMask(maxNum);

        vector<int> twoAndCount(mask + 1, 0);
        countTwoAnd(A, twoAndCount);

        return countThreeAnd(A, twoAndCount, mask);
    }

    int getMask(int num) {
        int mask = 1;

        while (mask < num) {
            mask = (mask << 1) | 1;
        }

        return mask;
    }

    void countTwoAnd(vector<int>& A, vector<int>& twoAndCount) {
        for (int a : A) {
            for (int b : A) {
                ++twoAndCount[a & b];
            }
        }
    }

    int countThreeAnd(vector<int>& A, vector<int>& twoAndCount, int mask) {
        int triplets = twoAndCount[0] * A.size();  // 两个数相与已经是0，任意一个数加进来还是0

        for (int a : A) {
            int mostBits = a ^ mask;  // 为使结果为0，最多可以有1的位置

            for (int b = mostBits; b != 0; b = (b - 1) & mostBits) {  // (b - 1) & mostBits能够遍历mostBits里面去掉任意1的所有情况
                triplets += twoAndCount[b];
            }
        }

        return triplets;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 2,1,3 };
    check.checkInt(12, o.countTriplets(A));

    A = { 1,2,3,4,5,6,7,8,9,10 };
    check.checkInt(684, o.countTriplets(A));

    A = { 0,1,2,3,4,5,6,7,8,9,10 };
    check.checkInt(1015, o.countTriplets(A));

    A = { 0,0,1,2,3,4,5,6,7,8,9,10,0,0,0 };
    check.checkInt(3059, o.countTriplets(A));

    A = { 32767,0,1,32766,32765,2,3,32764,32763,4,5 };
    check.checkInt(805, o.countTriplets(A));

    A = { 0 };
    check.checkInt(1, o.countTriplets(A));

    A = { 1 };
    check.checkInt(0, o.countTriplets(A));

    A = { 0,5 };
    check.checkInt(7, o.countTriplets(A));

    A = { 2,5 };
    check.checkInt(6, o.countTriplets(A));
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
