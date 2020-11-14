/* 子串能表示从 1 到 N 数字的二进制串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二进制字符串 S（一个仅由若干 '0' 和 '1' 构成的字符串）和一个正整数 N，如果对于从 1 到 N 的每个整数 X，其二进制表示都是 S 的子串，就返回 true，否则返回 false。

 

示例 1：

输入：S = "0110", N = 3
输出：true
示例 2：

输入：S = "0110", N = 4
输出：false
 

提示：

1 <= S.length <= 1000
1 <= N <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-string-with-substrings-representing-1-to-n
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool queryString(string S, int N) {
        if (N > 1000) {
            return false;
        }

        for (int i = N / 2 + 1; i <= N; ++i) {
            if (S.find(toBinary(i)) == S.npos) {
                return false;
            }
        }

        return true;
    }

    string toBinary(int n) {
        string binary;

        while (n != 0) {
            binary += ('0' + (n & 1));
            n >>= 1;
        }

        reverse(binary.begin(), binary.end());

        return binary;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.queryString("0110", 3));
    check.checkBool(false, o.queryString("0110", 4));
    check.checkBool(true, o.queryString("1", 1));
    check.checkBool(false, o.queryString("0", 1));
    check.checkBool(true, o.queryString("11101001000", 10));
    check.checkBool(false, o.queryString("0110100100110010110101011001101100111101", 20));
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
