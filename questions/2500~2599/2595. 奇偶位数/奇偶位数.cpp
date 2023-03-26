/* 奇偶位数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 正 整数 n 。

用 even 表示在 n 的二进制形式（下标从 0 开始）中值为 1 的偶数下标的个数。

用 odd 表示在 n 的二进制形式（下标从 0 开始）中值为 1 的奇数下标的个数。

返回整数数组 answer ，其中 answer = [even, odd] 。



示例 1：

输入：n = 17
输出：[2,0]
解释：17 的二进制形式是 10001 。
下标 0 和 下标 4 对应的值为 1 。
共有 2 个偶数下标，0 个奇数下标。
示例 2：

输入：n = 2
输出：[0,1]
解释：2 的二进制形式是 10 。
下标 1 对应的值为 1 。
共有 0 个偶数下标，1 个奇数下标。


提示：

1 <= n <= 1000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0, eo = 0;

        while (n != 0) {
            if (eo == 0) {
                even += (n & 1);
            }
            else {
                odd += (n & 1);
            }

            eo ^= 1;
            n >>= 1;
        }

        return { even, odd };
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.evenOddBit(17);
    vector<int> expected = { 2,0 };
    check.checkIntVector(expected, actual);

    actual = o.evenOddBit(2);
    expected = { 0,1 };
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
