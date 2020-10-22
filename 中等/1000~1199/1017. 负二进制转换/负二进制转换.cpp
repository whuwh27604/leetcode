/* 负二进制转换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出数字 N，返回由若干 "0" 和 "1"组成的字符串，该字符串为 N 的负二进制（base -2）表示。

除非字符串就是 "0"，否则返回的字符串中不能含有前导零。

 

示例 1：

输入：2
输出："110"
解释：(-2) ^ 2 + (-2) ^ 1 = 2
示例 2：

输入：3
输出："111"
解释：(-2) ^ 2 + (-2) ^ 1 + (-2) ^ 0 = 3
示例 3：

输入：4
输出："100"
解释：(-2) ^ 2 = 4
 

提示：

0 <= N <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-to-base-2
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0) {
            return "0";
        }

        string binary = toBinary(N);

        for (unsigned int i = 0; i < binary.size(); ++i) {
            if ((i & 1) == 0) {
                if (binary[i] == '2') {
                    binary[i] = '0';
                    prevAddOne(binary, i);
                }
            }
            else {
                if (binary[i] == '1') {
                    prevAddOne(binary, i);
                }
                else if (binary[i] == '2') {
                    binary[i] = '0';
                    prevAddOne(binary, i);
                }
            }
        }

        reverse(binary.begin(), binary.end());

        return binary;
    }

    void prevAddOne(string& binary, unsigned int index) {
        if (index == binary.size() - 1) {
            binary += '1';
        }
        else {
            binary[index + 1] += 1;
        }
    }

    string toBinary(int n) {
        string binary;

        while (n != 0) {
            binary += ('0' + (n & 1));
            n >>= 1;
        }

        return binary;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("0", o.baseNeg2(0));
    check.checkString("1", o.baseNeg2(1));
    check.checkString("110", o.baseNeg2(2));
    check.checkString("111", o.baseNeg2(3));
    check.checkString("100", o.baseNeg2(4));
    check.checkString("11010", o.baseNeg2(6));
    check.checkString("10010", o.baseNeg2(14));
    check.checkString("1000010", o.baseNeg2(62));
    check.checkString("110101010", o.baseNeg2(86));
    check.checkString("1001100111011111101111000000011", o.baseNeg2(999999999));
    check.checkString("1001100111011111101111000000000", o.baseNeg2(1000000000));
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
