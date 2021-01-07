/* 旋转字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个字符串, A 和 B。

A 的旋转操作就是将 A 最左边的字符移动到最右边。 例如, 若 A = 'abcde'，在移动一次之后结果就是'bcdea' 。如果在若干次旋转操作之后，A 能变成B，那么返回True。

示例 1:
输入: A = 'abcde', B = 'cdeab'
输出: true

示例 2:
输入: A = 'abcde', B = 'abced'
输出: false
注意：

A 和 B 长度不超过 100。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }

        A += A;
        return (A.find(B) != -1);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string A = "abcde";
    string B = "cdeab";
    check.checkBool(true, o.rotateString(A, B));

    A = "abcde";
    B = "abced";
    check.checkBool(false, o.rotateString(A, B));

    A = "abcde";
    B = "abcde";
    check.checkBool(true, o.rotateString(A, B));

    A = "abcde";
    B = "abcdE";
    check.checkBool(false, o.rotateString(A, B));

    A = "";
    B = "";
    check.checkBool(true, o.rotateString(A, B));

    A = "a";
    B = "";
    check.checkBool(false, o.rotateString(A, B));
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
