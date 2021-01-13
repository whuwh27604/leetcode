/* 亲密字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个由小写字母构成的字符串 A 和 B ，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回 true ；否则返回 false 。

 

示例 1：

输入： A = "ab", B = "ba"
输出： true
示例 2：

输入： A = "ab", B = "ab"
输出： false
示例 3:

输入： A = "aa", B = "aa"
输出： true
示例 4：

输入： A = "aaaaaaabc", B = "aaaaaaacb"
输出： true
示例 5：

输入： A = "", B = "aa"
输出： false
 

提示：

0 <= A.length <= 20000
0 <= B.length <= 20000
A 和 B 仅由小写字母构成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/buddy-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        // 有两种情况是亲密字符串：1、A==B，且至少一个字符出现2次；2、A、B只有两个地方不同，且A[i]==B[j] && [Aj]==B[i]
        vector<int> diff;
        int charTable[26] = { 0 };
        bool charMoreThanOnce = false;

        for (unsigned int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                if (diff.size() >= 3) {
                    return false;
                }
                diff.push_back(i);
                continue;
            }

            if (charMoreThanOnce) {
                continue;
            }

            charTable[A[i] - 'a']++;
            if (charTable[A[i] - 'a'] >= 2) {
                charMoreThanOnce = true;
            }
        }

        if (diff.size() == 0) {
            return charMoreThanOnce;
        }

        if (diff.size() == 1) {
            return false;
        }

        return ((A[diff[0]] == B[diff[1]]) && (A[diff[1]] == B[diff[0]]));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string A = "ab";
    string B = "ba";
    check.checkBool(true, o.buddyStrings(A, B));

    A = "a";
    B = "b";
    check.checkBool(false, o.buddyStrings(A, B));

    A = "ab";
    B = "ab";
    check.checkBool(false, o.buddyStrings(A, B));

    A = "aa";
    B = "aa";
    check.checkBool(true, o.buddyStrings(A, B));

    A = "bcaad";
    B = "bcaad";
    check.checkBool(true, o.buddyStrings(A, B));

    A = "aaaaaaabc";
    B = "aaaaaaacb";
    check.checkBool(true, o.buddyStrings(A, B));

    A = "aaaaaaacc";
    B = "aaaaaaacb";
    check.checkBool(false, o.buddyStrings(A, B));

    A = "";
    B = "aa";
    check.checkBool(false, o.buddyStrings(A, B));

    A = "";
    B = "";
    check.checkBool(false, o.buddyStrings(A, B));

    A = "abc";
    B = "def";
    check.checkBool(false, o.buddyStrings(A, B));
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
