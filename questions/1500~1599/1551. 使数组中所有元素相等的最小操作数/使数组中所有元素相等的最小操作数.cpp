/* 使数组中所有元素相等的最小操作数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
存在一个长度为 n 的数组 arr ，其中 arr[i] = (2 * i) + 1 （ 0 <= i < n ）。

一次操作中，你可以选出两个下标，记作 x 和 y （ 0 <= x, y < n ）并使 arr[x] 减去 1 、arr[y] 加上 1 （即 arr[x] -=1 且 arr[y] += 1 ）。最终的目标是使数组中的所有元素都 相等 。题目测试用例将会 保证 ：在执行若干步操作后，数组中的所有元素最终可以全部相等。

给你一个整数 n，即数组的长度。请你返回使数组 arr 中所有元素相等所需的 最小操作数 。

 

示例 1：

输入：n = 3
输出：2
解释：arr = [1, 3, 5]
第一次操作选出 x = 2 和 y = 0，使数组变为 [2, 3, 4]
第二次操作继续选出 x = 2 和 y = 0，数组将会变成 [3, 3, 3]
示例 2：

输入：n = 6
输出：9
 

提示：

1 <= n <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-operations-to-make-array-equal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(int n) {
        // 很容易推导出，n为奇数时，结果为(n+1)*(n-1)/2/2；n为偶数时，结果为n*n/2/2。整数运算的结果都是n*n/4
        return n * n / 4;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.minOperations(3));
    check.checkInt(0, o.minOperations(1));
    check.checkInt(1, o.minOperations(2));
    check.checkInt(4, o.minOperations(4));
    check.checkInt(6, o.minOperations(5));
    check.checkInt(9, o.minOperations(6));
    check.checkInt(12, o.minOperations(7));
    check.checkInt(2500, o.minOperations(100));
    check.checkInt(25000000, o.minOperations(10000));
    check.checkInt(24995000, o.minOperations(9999));
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
