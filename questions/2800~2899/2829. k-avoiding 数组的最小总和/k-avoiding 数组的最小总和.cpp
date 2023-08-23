/* k-avoiding 数组的最小总和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数 n 和 k 。

对于一个由 不同 正整数组成的数组，如果其中不存在任何求和等于 k 的不同元素对，则称其为 k-avoiding 数组。

返回长度为 n 的 k-avoiding 数组的可能的最小总和。



示例 1：

输入：n = 5, k = 4
输出：18
解释：设若 k-avoiding 数组为 [1,2,4,5,6] ，其元素总和为 18 。
可以证明不存在总和小于 18 的 k-avoiding 数组。
示例 2：

输入：n = 2, k = 6
输出：3
解释：可以构造数组 [1,2] ，其元素总和为 3 。
可以证明不存在总和小于 3 的 k-avoiding 数组。


提示：

1 <= n, k <= 50
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumSum(int n, int k) {
        int m = min(k / 2, n);
        int sum = (1 + m) * m / 2;
        n -= m;
        sum += (k + k + n - 1) * n / 2;

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(18, o.minimumSum(5, 4));
    check.checkInt(3, o.minimumSum(2, 6));
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
