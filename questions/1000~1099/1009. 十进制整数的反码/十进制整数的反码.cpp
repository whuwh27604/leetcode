/* 十进制整数的反码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
每个非负整数 N 都有其二进制表示。例如， 5 可以被表示为二进制 "101"，11 可以用二进制 "1011" 表示，依此类推。注意，除 N = 0 外，任何二进制表示中都不含前导零。

二进制的反码表示是将每个 1 改为 0 且每个 0 变为 1。例如，二进制数 "101" 的二进制反码为 "010"。

给你一个十进制数 N，请你返回其二进制表示的反码所对应的十进制整数。

 

示例 1：

输入：5
输出：2
解释：5 的二进制表示为 "101"，其二进制反码为 "010"，也就是十进制中的 2 。
示例 2：

输入：7
输出：0
解释：7 的二进制表示为 "111"，其二进制反码为 "000"，也就是十进制中的 0 。
示例 3：

输入：10
输出：5
解释：10 的二进制表示为 "1010"，其二进制反码为 "0101"，也就是十进制中的 5 。
 

提示：

0 <= N < 10^9
本题与 476：https://leetcode-cn.com/problems/number-complement/ 相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/complement-of-base-10-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int bitwiseComplement(int N) {
        int xorNumber = 1;
        int tmp = (N >> 1);

        while (tmp != 0) {
            tmp >>= 1;
            xorNumber = ((xorNumber << 1) + 1);
        }

        return (N ^ xorNumber);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(2, o.bitwiseComplement(5));
    check.checkInt(0, o.bitwiseComplement(7));
    check.checkInt(5, o.bitwiseComplement(10));
    check.checkInt(0, o.bitwiseComplement(1));
    check.checkInt(1, o.bitwiseComplement(0));
    check.checkInt(85, o.bitwiseComplement(170));
    check.checkInt(0, o.bitwiseComplement(2147483647));
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
