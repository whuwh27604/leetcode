/* 1比特与2比特字符.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有两种特殊字符。第一种字符可以用一比特0来表示。第二种字符可以用两比特(10 或 11)来表示。

现给一个由若干比特组成的字符串。问最后一个字符是否必定为一个一比特字符。给定的字符串总是由0结束。

示例 1:

输入:
bits = [1, 0, 0]
输出: True
解释:
唯一的编码方式是一个两比特字符和一个一比特字符。所以最后一个字符是一比特字符。
示例 2:

输入:
bits = [1, 1, 1, 0]
输出: False
解释:
唯一的编码方式是两比特字符和两比特字符。所以最后一个字符不是一比特字符。
注意:

1 <= len(bits) <= 1000.
bits[i] 总是0 或 1.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/1-bit-and-2-bit-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool complete = true;
        for (unsigned int i = 0; i < (bits.size() - 1); i++) {
            if (bits[i] == 1) {
                complete = (!complete);
            }
            else {
                complete = true;
            }
        }

        return complete;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> bits = { 1, 0, 0 };
    check.checkBool(true, o.isOneBitCharacter(bits));

    bits = { 1, 1, 1, 0 };
    check.checkBool(false, o.isOneBitCharacter(bits));

    bits = { 0 };
    check.checkBool(true, o.isOneBitCharacter(bits));

    bits = { 1, 0 };
    check.checkBool(false, o.isOneBitCharacter(bits));

    bits = { 0,1,0,1,1,0 };
    check.checkBool(true, o.isOneBitCharacter(bits));

    bits = { 0,1,1,1,0 };
    check.checkBool(false, o.isOneBitCharacter(bits));

    bits = { 1,0,0,1,1,0 };
    check.checkBool(true, o.isOneBitCharacter(bits));

    bits = { 1,0,1,1,0 };
    check.checkBool(true, o.isOneBitCharacter(bits));

    bits = { 1,1,0,1,0 };
    check.checkBool(false, o.isOneBitCharacter(bits));

    bits = { 1,1,1,0,0 };
    check.checkBool(true, o.isOneBitCharacter(bits));

    bits = { 1,0,1,1,1,0,1,1,1,0,1,1,1,0,0 };
    check.checkBool(true, o.isOneBitCharacter(bits));
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
