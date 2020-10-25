/* 数组异或操作.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数，n 和 start 。

数组 nums 定义为：nums[i] = start + 2*i（下标从 0 开始）且 n == nums.length 。

请返回 nums 中所有元素按位异或（XOR）后得到的结果。

 

示例 1：

输入：n = 5, start = 0
输出：8
解释：数组 nums 为 [0, 2, 4, 6, 8]，其中 (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8 。
     "^" 为按位异或 XOR 运算符。
示例 2：

输入：n = 4, start = 3
输出：8
解释：数组 nums 为 [3, 5, 7, 9]，其中 (3 ^ 5 ^ 7 ^ 9) = 8.
示例 3：

输入：n = 1, start = 7
输出：7
示例 4：

输入：n = 10, start = 5
输出：2
 

提示：

1 <= n <= 1000
0 <= start <= 1000
n == nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xor-operation-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int number = start, xored = 0;

        for (int i = 0; i < n; i++) {
            xored ^= number;
            number += 2;
        }

        return xored;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.xorOperation(1, 0));
    check.checkInt(5, o.xorOperation(1, 5));
    check.checkInt(2, o.xorOperation(2, 0));
    check.checkInt(2, o.xorOperation(2, 5));
    check.checkInt(8, o.xorOperation(5, 0));
    check.checkInt(8, o.xorOperation(4, 3));
    check.checkInt(7, o.xorOperation(1, 7));
    check.checkInt(2, o.xorOperation(10, 5));
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
