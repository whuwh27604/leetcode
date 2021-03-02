/* 学生出勤记录 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个正整数 n，返回长度为 n 的所有可被视为可奖励的出勤记录的数量。 答案可能非常大，你只需返回结果mod 109 + 7的值。

学生出勤记录是只包含以下三个字符的字符串：

'A' : Absent，缺勤
'L' : Late，迟到
'P' : Present，到场
如果记录不包含多于一个'A'（缺勤）或超过两个连续的'L'（迟到），则该记录被视为可奖励的。

示例 1:

输入: n = 2
输出: 8
解释：
有8个长度为2的记录将被视为可奖励：
"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
只有"AA"不会被视为可奖励，因为缺勤次数超过一次。
注意：n 的值不会超过100000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/student-attendance-record-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        /*              A,A    A,P    A,L    A,LL    noA,P    noA,L    noA,LL
           A,A(a)                                      e        f        g
           A,P(b)        a      b      c      d
           A,L(c)        a      b      
           A,LL(d)                     c
           noA,P(e)                                    e        f        g
           noA,L(f)                                    e
           noA,LL(g)                                            f
        */
        long long a = 1, b = 0, c = 0, d = 0, e = 1, f = 1, g = 0, mod = 1000000007;

        for (int i = 1; i < n; ++i) {
            long long a1 = (e + f + g) % mod;
            long long b1 = (a + b + c + d) % mod;
            long long c1 = (a + b) % mod;
            long long d1 = c;
            long long e1 = (e + f + g) % mod;
            long long f1 = e;
            long long g1 = f;
            a = a1;
            b = b1;
            c = c1;
            d = d1;
            e = e1;
            f = f1;
            g = g1;
        }

        return (int)((a + b + c + d + e + f + g) % mod);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.checkRecord(1));
    check.checkInt(8, o.checkRecord(2));
    check.checkInt(19, o.checkRecord(3));
    check.checkInt(43, o.checkRecord(4));
    check.checkInt(94, o.checkRecord(5));
    check.checkInt(3536, o.checkRecord(10));
    check.checkInt(985598218, o.checkRecord(100));
    check.checkInt(749184020, o.checkRecord(100000));
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
