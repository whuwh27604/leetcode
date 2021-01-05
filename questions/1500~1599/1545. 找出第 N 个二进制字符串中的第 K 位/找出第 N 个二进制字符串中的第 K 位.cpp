/* 找出第 N 个二进制字符串中的第 K 位.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个正整数 n 和 k，二进制字符串  Sn 的形成规则如下：

S1 = "0"
当 i > 1 时，Si = Si-1 + "1" + reverse(invert(Si-1))
其中 + 表示串联操作，reverse(x) 返回反转 x 后得到的字符串，而 invert(x) 则会翻转 x 中的每一位（0 变为 1，而 1 变为 0）

例如，符合上述描述的序列的前 4 个字符串依次是：

S1 = "0"
S2 = "011"
S3 = "0111001"
S4 = "011100110110001"
请你返回  Sn 的 第 k 位字符 ，题目数据保证 k 一定在 Sn 长度范围以内。

 

示例 1：

输入：n = 3, k = 1
输出："0"
解释：S3 为 "0111001"，其第 1 位为 "0" 。
示例 2：

输入：n = 4, k = 11
输出："1"
解释：S4 为 "011100110110001"，其第 11 位为 "1" 。
示例 3：

输入：n = 1, k = 1
输出："0"
示例 4：

输入：n = 2, k = 3
输出："1"
 

提示：

1 <= n <= 20
1 <= k <= 2n - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-kth-bit-in-nth-binary-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        vector<int> lens(n + 1);
        lens[1] = 1;
        bool needFlip = false;

        for (int i = 2; i <= n; ++i) {
            lens[i] = lens[i - 1] * 2 + 1;
        }

        for (int i = n; i > 1; --i) {
            int middle = lens[i] / 2 + 1;

            if (k == middle) {
                return needFlip ? '0' : '1';
            }

            if (k > middle) {
                k = 2 * middle - k;
                needFlip = !needFlip;
            }
        }

        return needFlip ? '1' : '0';
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkChar('0', o.findKthBit(1, 1));
    check.checkChar('1', o.findKthBit(2, 2));
    check.checkChar('1', o.findKthBit(2, 3));
    check.checkChar('1', o.findKthBit(3, 3));
    check.checkChar('1', o.findKthBit(3, 4));
    check.checkChar('0', o.findKthBit(3, 5));
    check.checkChar('1', o.findKthBit(3, 7));
    check.checkChar('1', o.findKthBit(4, 11));
    check.checkChar('0', o.findKthBit(4, 12));
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
