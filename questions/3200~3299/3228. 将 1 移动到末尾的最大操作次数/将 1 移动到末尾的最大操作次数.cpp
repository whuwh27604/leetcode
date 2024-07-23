/* 将 1 移动到末尾的最大操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个
二进制字符串
 s。

你可以对这个字符串执行 任意次 下述操作：

选择字符串中的任一下标 i（ i + 1 < s.length ），该下标满足 s[i] == '1' 且 s[i + 1] == '0'。
将字符 s[i] 向 右移 直到它到达字符串的末端或另一个 '1'。例如，对于 s = "010010"，如果我们选择 i = 1，结果字符串将会是 s = "000110"。
返回你能执行的 最大 操作次数。



示例 1：

输入： s = "1001101"

输出： 4

解释：

可以执行以下操作：

选择下标 i = 0。结果字符串为 s = "0011101"。
选择下标 i = 4。结果字符串为 s = "0011011"。
选择下标 i = 3。结果字符串为 s = "0010111"。
选择下标 i = 2。结果字符串为 s = "0001111"。
示例 2：

输入： s = "00111"

输出： 0



提示：

1 <= s.length <= 105
s[i] 为 '0' 或 '1'。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        bool zero = false;
        int oper = 0, total = 0;

        for (int i = (int)s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                zero = true;
            }
            else {
                if (zero) {
                    ++oper;
                    zero = false;
                }
                total += oper;
            }
        }

        return total;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(4, o.maxOperations("1001101"));
    check.checkInt(0, o.maxOperations("00111"));
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
