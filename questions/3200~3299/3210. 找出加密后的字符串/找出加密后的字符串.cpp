/* 找出加密后的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个整数 k。请你使用以下算法加密字符串：

对于字符串 s 中的每个字符 c，用字符串中 c 后面的第 k 个字符替换 c（以循环方式）。
返回加密后的字符串。



示例 1：

输入： s = "dart", k = 3

输出： "tdar"

解释：

对于 i = 0，'d' 后面的第 3 个字符是 't'。
对于 i = 1，'a' 后面的第 3 个字符是 'd'。
对于 i = 2，'r' 后面的第 3 个字符是 'a'。
对于 i = 3，'t' 后面的第 3 个字符是 'r'。
示例 2：

输入： s = "aaa", k = 1

输出： "aaa"

解释：

由于所有字符都相同，加密后的字符串也将相同。



提示：

1 <= s.length <= 100
1 <= k <= 104
s 仅由小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string getEncryptedString(string s, int k) {
        int size = (int)s.size();
        k %= size;

        return string(s, k, size - k) + string(s, 0, k);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("tdar", o.getEncryptedString("dart", 3));
    check.checkString("aaa", o.getEncryptedString("aaa", 1));
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
