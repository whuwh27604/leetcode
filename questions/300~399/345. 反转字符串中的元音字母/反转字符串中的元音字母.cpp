/* 反转字符串中的元音字母.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1:

输入: "hello"
输出: "holle"
示例 2:

输入: "leetcode"
输出: "leotcede"
说明:
元音字母不包含字母"y"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-vowels-of-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int size = s.size(), left = 0, right = size - 1;
        if (size == 0) {
            return s;
        }

        while (left < right) {
            while (left < size && s[left] != 'a' && s[left] != 'e' && s[left] != 'i' && s[left] != 'o' && s[left] != 'u' 
                && s[left] != 'A' && s[left] != 'E' && s[left] != 'I' && s[left] != 'O' && s[left] != 'U') {
                ++left;
            }

            while (right >= 0 && s[right] != 'a' && s[right] != 'e' && s[right] != 'i' && s[right] != 'o' && s[right] != 'u' 
                && s[right] != 'A' && s[right] != 'E' && s[right] != 'I' && s[right] != 'O' && s[right] != 'U') {
                --right;
            }

            if (left < right) {
                swap(s[left++], s[right--]);
            }
        }

        return s;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string s = "hello";
    string expected = "holle";
    check.checkString(expected, o.reverseVowels(s));

    s = "leetcode";
    expected = "leotcede";
    check.checkString(expected, o.reverseVowels(s));

    s = "n";
    expected = "n";
    check.checkString(expected, o.reverseVowels(s));

    s = "on";
    expected = "on";
    check.checkString(expected, o.reverseVowels(s));

    s = "aA";
    expected = "Aa";
    check.checkString(expected, o.reverseVowels(s));

    s = "one";
    expected = "eno";
    check.checkString(expected, o.reverseVowels(s));

    s = "aeno";
    expected = "oena";
    check.checkString(expected, o.reverseVowels(s));

    s = "aenuo";
    expected = "ounea";
    check.checkString(expected, o.reverseVowels(s));

    s = "annnnnnnnoaue";
    expected = "ennnnnnnnuaoa";
    check.checkString(expected, o.reverseVowels(s));

    s = "";
    expected = "";
    check.checkString(expected, o.reverseVowels(s));
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
