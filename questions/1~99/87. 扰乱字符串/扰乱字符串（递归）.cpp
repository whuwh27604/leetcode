/* 扰乱字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。

下图是字符串 s1 = "great" 的一种可能的表示形式。

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。

例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
我们将 "rgeat” 称作 "great" 的一个扰乱字符串。

同样地，如果我们继续交换节点 "eat" 和 "at" 的子节点，将会产生另一个新的扰乱字符串 "rgtae" 。

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
我们将 "rgtae” 称作 "great" 的一个扰乱字符串。

给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。

示例 1:

输入: s1 = "great", s2 = "rgeat"
输出: true
示例 2:

输入: s1 = "abcde", s2 = "caebd"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/scramble-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int i, size = s1.size();
        if (size == 1) {
            return s1 == s2;
        }

        vector<int> count1(26, 0), count2(26, 0);

        for (i = 0; i < size - 1; ++i) {
            ++count1[s1[i] - 'a'];
            ++count2[s2[i] - 'a'];

            if (count1 == count2 && isScramble(string(s1, 0, i + 1), string(s2, 0, i + 1))
                && isScramble(string(s1, i + 1, size - i - 1), string(s2, i + 1, size - i - 1))) {
                return true;
            }
        }

        for (i = 0; i < 26; ++i) {
            count1[i] = count2[i] = 0;
        }

        for (i = 0; i < size - 1; ++i) {
            ++count1[s1[i] - 'a'];
            ++count2[s2[size - 1 - i] - 'a'];

            if (count1 == count2 && isScramble(string(s1, 0, i + 1), string(s2, size - 1 - i, i + 1))
                && isScramble(string(s1, i + 1, size - i - 1), string(s2, 0, size - i - 1))) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.isScramble("abb", "bab"));
    check.checkBool(true, o.isScramble("great", "rgeat"));
    check.checkBool(false, o.isScramble("abcde", "caebd"));
    check.checkBool(true, o.isScramble("sasa", "ssaa"));
    check.checkBool(true, o.isScramble("asasa", "ssaaa"));
    check.checkBool(true, o.isScramble("sasasa", "sssaaa"));
    check.checkBool(true, o.isScramble("abcdefghijklmnopqrstuvwxyzxyzz", "zzyxzyxwvutsrqponmlkjihgfedcba"));
    check.checkBool(false, o.isScramble("abcdefghijklmnopqrstuvwxyzxyzz", "zzyxzyxwvutsrqppnmlkjihgfedcba"));
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
