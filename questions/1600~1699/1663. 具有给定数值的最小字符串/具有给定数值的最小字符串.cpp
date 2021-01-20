/* 具有给定数值的最小字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小写字符 的 数值 是它在字母表中的位置（从 1 开始），因此 a 的数值为 1 ，b 的数值为 2 ，c 的数值为 3 ，以此类推。

字符串由若干小写字符组成，字符串的数值 为各字符的数值之和。例如，字符串 "abe" 的数值等于 1 + 2 + 5 = 8 。

给你两个整数 n 和 k 。返回 长度 等于 n 且 数值 等于 k 的 字典序最小 的字符串。

注意，如果字符串 x 在字典排序中位于 y 之前，就认为 x 字典序比 y 小，有以下两种情况：

x 是 y 的一个前缀；
如果 i 是 x[i] != y[i] 的第一个位置，且 x[i] 在字母表中的位置比 y[i] 靠前。
 

示例 1：

输入：n = 3, k = 27
输出："aay"
解释：字符串的数值为 1 + 1 + 25 = 27，它是数值满足要求且长度等于 3 字典序最小的字符串。
示例 2：

输入：n = 5, k = 73
输出："aaszz"
 

提示：

1 <= n <= 105
n <= k <= 26 * n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-string-with-a-given-numeric-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string smallest(n, 0);
        int i = 0;

        while ((n - 1 - i) * 26 >= k - 1) {  // 如果还能放a，就继续放
            smallest[i++] = 'a';
            k -= 1;
        }

        smallest[i] = 'a' + k - (n - 1 - i) * 26 - 1;  // 不能再放a了，看看最小能放什么

        for (i += 1; i < n; ++i) {  // 剩下的都是z
            smallest[i] = 'z';
        }

        return smallest;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("aay", o.getSmallestString(3, 27));
    check.checkString("aaszz", o.getSmallestString(5, 73));
    check.checkString("a", o.getSmallestString(1, 1));
    check.checkString("z", o.getSmallestString(1, 26));
    check.checkString("zz", o.getSmallestString(2, 52));
    check.checkString("aaaaaapzzz", o.getSmallestString(10, 100));
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
