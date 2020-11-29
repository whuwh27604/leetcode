/* 压缩字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一组字符，使用原地算法将其压缩。

压缩后的长度必须始终小于或等于原数组长度。

数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。

在完成原地修改输入数组后，返回数组的新长度。

 

进阶：
你能否仅使用O(1) 空间解决问题？

 

示例 1：

输入：
["a","a","b","b","c","c","c"]

输出：
返回6，输入数组的前6个字符应该是：["a","2","b","2","c","3"]

说明：
"aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。
示例 2：

输入：
["a"]

输出：
返回1，输入数组的前1个字符应该是：["a"]

说明：
没有任何字符串被替代。
示例 3：

输入：
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

输出：
返回4，输入数组的前4个字符应该是：["a","b","1","2"]。

说明：
由于字符"a"不重复，所以不会被压缩。"bbbbbbbbbbbb"被“b12”替代。
注意每个数字在数组中都有它自己的位置。
注意：

所有字符都有一个ASCII值在[35, 126]区间内。
1 <= len(chars) <= 1000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-compression
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int writeIndex = 0;
        char prevChar = 0;
        int count = 1;

        for (unsigned int readIndex = 0; readIndex < chars.size(); readIndex++) {
            char currentChar = chars[readIndex];
            if (currentChar == prevChar) {
                count++;
                continue;
            }

            if (count != 1) {
                writeCount(chars, writeIndex, count);
            }

            chars[writeIndex++] = currentChar;
            count = 1;
            prevChar = currentChar;
        }

        if (count != 1) {
            writeCount(chars, writeIndex, count);
        }

        return writeIndex;
    }

    void writeCount(vector<char>& chars, int& writeIndex, int count) {
        string countStr = to_string(count);
        for (unsigned int i = 0; i < countStr.size(); i++) {
            chars[writeIndex++] = countStr[i];
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<char> chars = { 'a','a','b','b','c','c','c' };
    check.checkInt(6, o.compress(chars));

    chars = { 'a' };
    check.checkInt(1, o.compress(chars));

    chars = { 'a','b','b','b','b','b','b','b','b','b','b','b','b' };
    check.checkInt(4, o.compress(chars));

    chars = { '.','.','.' };
    check.checkInt(2, o.compress(chars));

    chars = { ',','.','.','.' };
    check.checkInt(3, o.compress(chars));

    chars = { '.','.','.',',' };
    check.checkInt(3, o.compress(chars));

    chars = { ',',',',',','.','.','.' };
    check.checkInt(4, o.compress(chars));

    chars = { 'a','b','a','b','a','b' };
    check.checkInt(6, o.compress(chars));
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
