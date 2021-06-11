/* 使整数变为 0 的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n，你需要重复执行多次下述操作将其转换为 0 ：

翻转 n 的二进制表示中最右侧位（第 0 位）。
如果第 (i-1) 位为 1 且从第 (i-2) 位到第 0 位都为 0，则翻转 n 的二进制表示中的第 i 位。
返回将 n 转换为 0 的最小操作次数。

 

示例 1：

输入：n = 0
输出：0
示例 2：

输入：n = 3
输出：2
解释：3 的二进制表示为 "11"
"11" -> "01" ，执行的是第 2 种操作，因为第 0 位为 1 。
"01" -> "00" ，执行的是第 1 种操作。
示例 3：

输入：n = 6
输出：4
解释：6 的二进制表示为 "110".
"110" -> "010" ，执行的是第 2 种操作，因为第 1 位为 1 ，第 0 到 0 位为 0 。
"010" -> "011" ，执行的是第 1 种操作。
"011" -> "001" ，执行的是第 2 种操作，因为第 0 位为 1 。
"001" -> "000" ，执行的是第 1 种操作。
示例 4：

输入：n = 9
输出：14
示例 5：

输入：n = 333
输出：393
 

提示：

0 <= n <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-one-bit-operations-to-make-integers-zero
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        /* 本题等价于已知Grey(n)，求Binary(n)。有以下结论：
           1、Gi = Bi ^ B(i+1)，Bi = Gi ^ B(i+1)
           2、已知Binary(n)，则Grey(n) = n ^ (n >> 1)
           3、已知Grey(n)，则Binary(n) = G^(G>>1)^(G>>2)^...^(G>>leftmost) */
        int num = 0;

        while (n != 0) {
            num ^= n;
            n >>= 1;
        }

        return num;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(0, o.minimumOneBitOperations(0));
    check.checkInt(2, o.minimumOneBitOperations(3));
    check.checkInt(4, o.minimumOneBitOperations(6));
    check.checkInt(14, o.minimumOneBitOperations(9));
    check.checkInt(393, o.minimumOneBitOperations(333));
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
