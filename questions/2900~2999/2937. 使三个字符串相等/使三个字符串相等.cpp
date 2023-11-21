/* 使三个字符串相等.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你三个字符串 s1、s2 和 s3。 你可以根据需要对这三个字符串执行以下操作 任意次数 。

在每次操作中，你可以选择其中一个长度至少为 2 的字符串 并删除其 最右位置上 的字符。

如果存在某种方法能够使这三个字符串相等，请返回使它们相等所需的 最小 操作次数；否则，返回 -1。



示例 1：

输入：s1 = "abc"，s2 = "abb"，s3 = "ab"
输出：2
解释：对 s1 和 s2 进行一次操作后，可以得到三个相等的字符串。
可以证明，不可能用少于两次操作使它们相等。
示例 2：

输入：s1 = "dac"，s2 = "bac"，s3 = "cac"
输出：-1
解释：因为 s1 和 s2 的最左位置上的字母不相等，所以无论进行多少次操作，它们都不可能相等。因此答案是 -1 。


提示：

1 <= s1.length, s2.length, s3.length <= 100
s1、s2 和 s3 仅由小写英文字母组成。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
        int size = min({ size1, size2, size3 }), index = 0;

        while (index < size && s1[index] == s2[index] && s1[index] == s3[index]) {
            ++index;
        }

        return index == 0 ? -1 : size1 + size2 + size3 - 3 * index;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.findMinimumOperations("abc", "abb", "ab"));
    check.checkInt(-1, o.findMinimumOperations("dac", "bac", "cac"));
    check.checkInt(6, o.findMinimumOperations("adb", "adc", "aad"));
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
