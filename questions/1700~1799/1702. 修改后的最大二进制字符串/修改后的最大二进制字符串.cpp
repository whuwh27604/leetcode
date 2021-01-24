/* 修改后的最大二进制字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制字符串 binary ，它仅有 0 或者 1 组成。你可以使用下面的操作任意次对它进行修改：

操作 1 ：如果二进制串包含子字符串 "00" ，你可以用 "10" 将其替换。
比方说， "00010" -> "10010"
操作 2 ：如果二进制串包含子字符串 "10" ，你可以用 "01" 将其替换。
比方说， "00010" -> "00001"
请你返回执行上述操作任意次以后能得到的 最大二进制字符串 。如果二进制字符串 x 对应的十进制数字大于二进制字符串 y 对应的十进制数字，那么我们称二进制字符串 x 大于二进制字符串 y 。

 

示例 1：

输入：binary = "000110"
输出："111011"
解释：一个可行的转换为：
"000110" -> "000101"
"000101" -> "100101"
"100101" -> "110101"
"110101" -> "110011"
"110011" -> "111011"
示例 2：

输入：binary = "01"
输出："01"
解释："01" 没办法进行任何转换。
 

提示：

1 <= binary.length <= 105
binary 仅包含 '0' 和 '1' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-binary-string-after-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        int i, size = binary.size(), ones = 0, zeros = 0;
        string ans(size, '1');  // 最终的结果必然是111...101...111，只需要找准0的位置。0后面的1的个数就是原始字符串中第一个0后面1的个数

        for (i = 0; i < size && binary[i] == '1'; ++i) {}

        for (; i < size; ++i) {
            if (binary[i] == '1') {
                ++ones;
            }
            else {
                ++zeros;
            }
        }

        if (zeros < 2) {  // 如果不足2个0，那么原始字符串就是最大的
            return binary;
        }

        ans[size - ones - 1] = '0';
        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("111011", o.maximumBinaryString("000110"));
    check.checkString("01", o.maximumBinaryString("01"));
    check.checkString("0", o.maximumBinaryString("0"));
    check.checkString("1", o.maximumBinaryString("1"));
    check.checkString("1110", o.maximumBinaryString("1100"));
    check.checkString("1111", o.maximumBinaryString("1111"));
    check.checkString("1110", o.maximumBinaryString("0000"));
    check.checkString("0111", o.maximumBinaryString("0111"));
    check.checkString("11111111110111111111", o.maximumBinaryString("01111001100000110010"));
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
