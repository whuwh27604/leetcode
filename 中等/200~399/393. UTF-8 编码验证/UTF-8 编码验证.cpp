/* UTF-8 编码验证.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
UTF-8 中的一个字符可能的长度为 1 到 4 字节，遵循以下的规则：

对于 1 字节的字符，字节的第一位设为0，后面7位为这个符号的unicode码。
对于 n 字节的字符 (n > 1)，第一个字节的前 n 位都设为1，第 n+1 位设为0，后面字节的前两位一律设为10。剩下的没有提及的二进制位，全部为这个符号的unicode码。
这是 UTF-8 编码的工作方式：

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
给定一个表示数据的整数数组，返回它是否为有效的 utf-8 编码。

注意:
输入是整数数组。只有每个整数的最低 8 个有效位用来存储数据。这意味着每个整数只表示 1 字节的数据。

示例 1:

data = [197, 130, 1], 表示 8 位的序列: 11000101 10000010 00000001.

返回 true 。
这是有效的 utf-8 编码，为一个2字节字符，跟着一个1字节字符。
示例 2:

data = [235, 140, 4], 表示 8 位的序列: 11101011 10001100 00000100.

返回 false 。
前 3 位都是 1 ，第 4 位为 0 表示它是一个3字节字符。
下一个字节是开头为 10 的延续字节，这是正确的。
但第二个延续字节不以 10 开头，所以是不符合规则的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/utf-8-validation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0, size = data.size();
        int first, second, third, fourth, tmp1, tmp2;

        while (i < size) {
            first = data[i];
            if ((first & 0x00000080) == 0) {
                i += 1;
            }
            else if (((first & 0x000000c0) == 0x000000c0) && ((first & 0x00000020) == 0)) {
                if (i + 1 >= size) {
                    return false;
                }

                second = data[i + 1];
                if (((second & 0x00000080) != 0x00000080) || ((second & 0x00000040) != 0)) {
                    return false;
                }

                i += 2;
            }
            else if (((first & 0x000000e0) == 0x000000e0) && ((first & 0x00000010) == 0)) {
                if (i + 2 >= size) {
                    return false;
                }

                second = data[i + 1];
                third = data[i + 2];
                tmp1 = second & third;
                tmp2 = second | third;
                if (((tmp1 & 0x00000080) != 0x00000080) || ((tmp2 & 0x00000040) != 0)) {
                    return false;
                }

                i += 3;
            }
            else if (((first & 0x000000f0) == 0x000000f0) && ((first & 0x00000008) == 0)) {
                if (i + 3 >= size) {
                    return false;
                }

                second = data[i + 1];
                third = data[i + 2];
                fourth = data[i + 3];
                tmp1 = second & third & fourth;
                tmp2 = second | third | fourth;
                if (((tmp1 & 0x00000080) != 0x00000080) || ((tmp2 & 0x00000040) != 0)) {
                    return false;
                }

                i += 4;
            }
            else {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> data = { 197,130,1 };
    check.checkBool(true, o.validUtf8(data));

    data = { 192,128,192,128 };
    check.checkBool(true, o.validUtf8(data));

    data = { 192 };
    check.checkBool(false, o.validUtf8(data));

    data = { 192,1 };
    check.checkBool(false, o.validUtf8(data));

    data = { 192,192 };
    check.checkBool(false, o.validUtf8(data));

    data = { 228,189,160,229,165,189,13,10 };
    check.checkBool(true, o.validUtf8(data));

    data = { 235,140,4 };
    check.checkBool(false, o.validUtf8(data));

    data = { 235,140 };
    check.checkBool(false, o.validUtf8(data));

    data = { 240,162,138,147,17 };
    check.checkBool(true, o.validUtf8(data));

    data = { 240,162,138,192,17 };
    check.checkBool(false, o.validUtf8(data));

    data = { 240,162,138,1,17 };
    check.checkBool(false, o.validUtf8(data));

    data = { 240,162,138,147,145 };
    check.checkBool(false, o.validUtf8(data));

    data = { 240,162,138 };
    check.checkBool(false, o.validUtf8(data));

    data = { 248,130,130,130 };
    check.checkBool(false, o.validUtf8(data));

    data = { 250,145,145,145,145 };
    check.checkBool(false, o.validUtf8(data));

    data = { 255 };
    check.checkBool(false, o.validUtf8(data));

    data = { 194,155,231,184,185,246,176,131,161,222,174,227,162,134,241,154,168,185,218,178,229,187,139,246,178,187,139,204,146,225,148,179,245,139,172,134,193,156,233,131,154,240,166,188,190,216,150,230,145,144,240,167,140,163,221,190,238,168,139,241,154,159,164,199,170,224,173,140,244,182,143,134,206,181,227,172,141,241,146,159,170,202,134,230,142,163,244,172,140,191 };
    check.checkBool(true, o.validUtf8(data));
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
