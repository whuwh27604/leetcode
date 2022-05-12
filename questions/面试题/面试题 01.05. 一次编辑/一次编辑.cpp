/* 一次编辑.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。

 

示例 1:

输入:
first = "pale"
second = "ple"
输出: True
 

示例 2:

输入:
first = "pales"
second = "pal"
输出: False

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/one-away-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int size1 = first.size(), size2 = second.size();

        if (size1 == size2) {
            return isReplacable(first, second);
        }

        if (size1 + 1 == size2) {
            return isInsertable(first, second);
        }

        if (size1 - 1 == size2) {
            return isInsertable(second, first);
        }

        return false;
    }

    bool isReplacable(string& first, string& second) {
        bool mismatch = false;

        for (int i = 0; i < (int)first.size(); ++i) {
            if (first[i] != second[i]) {
                if (mismatch) {
                    return false;
                }

                mismatch = true;
            }
        }

        return true;
    }

    bool isInsertable(string& first, string& second) {
        int i, size = first.size();

        for (i = 0; i < size; ++i) {
            if (first[i] != second[i]) {
                break;
            }
        }

        for (; i < size; ++i) {
            if (first[i] != second[i + 1]) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.oneEditAway("pale", "ple"));
    check.checkBool(true, o.oneEditAway("ple", "pale"));
    check.checkBool(true, o.oneEditAway("ple", "ple"));
    check.checkBool(true, o.oneEditAway("ple", "plo"));
    check.checkBool(true, o.oneEditAway("a", "z"));
    check.checkBool(false, o.oneEditAway("pales", "pal"));
    check.checkBool(false, o.oneEditAway("ple", "poo"));
    check.checkBool(false, o.oneEditAway("ple", "polo"));
    check.checkBool(false, o.oneEditAway("polo", "ple"));
    check.checkBool(false, o.oneEditAway("ab", "bc"));
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
