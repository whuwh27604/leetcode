/* 数字的补数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个正整数，输出它的补数。补数是对该数的二进制表示取反。

 

示例 1:

输入: 5
输出: 2
解释: 5 的二进制表示为 101（没有前导零位），其补数为 010。所以你需要输出 2 。
示例 2:

输入: 1
输出: 0
解释: 1 的二进制表示为 1（没有前导零位），其补数为 0。所以你需要输出 0 。
 

注意:

给定的整数保证在 32 位带符号整数的范围内。
你可以假定二进制数不包含前导零位。
本题与 1009 https://leetcode-cn.com/problems/complement-of-base-10-integer/ 相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-complement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int xorNumber = 1;
        int tmp = (num >> 1);

        while (tmp != 0) {
            tmp >>= 1;
            xorNumber = ((xorNumber << 1) + 1);
        }

        return (num ^ xorNumber);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(2, o.findComplement(5));
    check.checkInt(0, o.findComplement(1));
    check.checkInt(1, o.findComplement(0));
    check.checkInt(85, o.findComplement(170));
    check.checkInt(0, o.findComplement(2147483647));
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
