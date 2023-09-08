/* 生成特殊数字的最少操作.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 num ，表示一个非负整数。

在一次操作中，您可以选择 num 的任意一位数字并将其删除。请注意，如果你删除 num 中的所有数字，则 num 变为 0。

返回最少需要多少次操作可以使 num 变成特殊数字。

如果整数 x 能被 25 整除，则该整数 x 被认为是特殊数字。





示例 1：

输入：num = "2245047"
输出：2
解释：删除数字 num[5] 和 num[6] ，得到数字 "22450" ，可以被 25 整除。
可以证明要使数字变成特殊数字，最少需要删除 2 位数字。
示例 2：

输入：num = "2908305"
输出：3
解释：删除 num[3]、num[4] 和 num[6] ，得到数字 "2900" ，可以被 25 整除。
可以证明要使数字变成特殊数字，最少需要删除 3 位数字。
示例 3：

输入：num = "10"
输出：1
解释：删除 num[0] ，得到数字 "0" ，可以被 25 整除。
可以证明要使数字变成特殊数字，最少需要删除 1 位数字。


提示

1 <= num.length <= 100
num 仅由数字 '0' 到 '9' 组成
num 不含任何前导零
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumOperations(string num) {
        // 被25整除的数，要么是0，要么末尾是00/25/50/75
        int size = num.size(), idx0 = size, idx5 = size;

        for (int i = size - 1; i >= 0; --i) {
            int digit = num[i] - '0';
            if (digit == 0) {
                if (idx0 != size) {  // 找到00
                    return size - i - 2;
                }
                idx0 = i;
            }
            else if (digit == 2) {
                if (idx5 != size) {  // 找到25
                    return size - i - 2;
                }
            }
            else if (digit == 5) {
                if (idx0 != size) {  // 找到50
                    return size - i - 2;
                }
                idx5 = i;
            }
            else if (digit == 7) {
                if (idx5 != size) {  // 找到75
                    return size - i - 2;
                }
            }
        }

        return idx0 == size ? size : size - 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.minimumOperations("2245047"));
    check.checkInt(3, o.minimumOperations("2908305"));
    check.checkInt(1, o.minimumOperations("10"));
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
