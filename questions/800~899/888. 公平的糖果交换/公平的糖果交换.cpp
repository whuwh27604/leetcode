/* 公平的糖果交换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 块糖的大小，B[j] 是鲍勃拥有的第 j 块糖的大小。

因为他们是朋友，所以他们想交换一个糖果棒，这样交换后，他们都有相同的糖果总量。（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）

返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1] 是 Bob 必须交换的糖果棒的大小。

如果有多个答案，你可以返回其中任何一个。保证答案存在。

 

示例 1：

输入：A = [1,1], B = [2,2]
输出：[1,2]
示例 2：

输入：A = [1,2], B = [2,3]
输出：[1,2]
示例 3：

输入：A = [2], B = [1,3]
输出：[2,3]
示例 4：

输入：A = [1,2,5], B = [2,4]
输出：[5,4]
 

提示：

1 <= A.length <= 10000
1 <= B.length <= 10000
1 <= A[i] <= 100000
1 <= B[i] <= 100000
保证爱丽丝与鲍勃的糖果总量不同。
答案肯定存在。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fair-candy-swap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = 0, sumB = 0;
        unsigned int i;
        unordered_set<int> numsA, numsB;

        for (i = 0; i < A.size(); i++) {
            sumA += A[i];
            numsA.insert(A[i]);
        }

        for (i = 0; i < B.size(); i++) {
            sumB += B[i];
            numsB.insert(B[i]);
        }

        int diff = ((sumA + sumB) / 2 - sumA);
        for (auto iterA = numsA.begin(); iterA != numsA.end(); iterA++) {
            auto iterB = numsB.find(*iterA + diff);
            if (iterB != numsB.end()) {
                return { *iterA, *iterB };
            }
        }

        return {};
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 1,1 };
    vector<int> B = { 2,2 };
    vector<int> actual = o.fairCandySwap(A, B);
    vector<int> expected = { 1,2 };
    check.checkIntVector(expected, actual);

    A = { 1,2 };
    B = { 2,3 };
    actual = o.fairCandySwap(A, B);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    A = { 2 };
    B = { 1,3 };
    actual = o.fairCandySwap(A, B);
    expected = { 2,3 };
    check.checkIntVector(expected, actual);

    A = { 1,2,5 };
    B = { 2,4 };
    actual = o.fairCandySwap(A, B);
    expected = { 5,4 };
    check.checkIntVector(expected, actual);

    A = { 2 };
    B = { 2 };
    actual = o.fairCandySwap(A, B);
    expected = { 2,2 };
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
