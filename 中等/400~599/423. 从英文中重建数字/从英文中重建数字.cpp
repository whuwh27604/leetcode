/* 从英文中重建数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非空字符串，其中包含字母顺序打乱的英文单词表示的数字0-9。按升序输出原始的数字。

注意:

输入只包含小写英文字母。
输入保证合法并可以转换为原始的数字，这意味着像 "abc" 或 "zerone" 的输入是不允许的。
输入字符串的长度小于 50,000。
示例 1:

输入: "owoztneoer"

输出: "012" (zeroonetwo)
示例 2:

输入: "fviefuro"

输出: "45" (fourfive)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reconstruct-original-digits-from-english
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        // 按照0(z)、2(w)、4(u)、6(x)、8(g)、1(o)、3(t)、5(f)、7(s)、9(i)的顺序依次拼接出数字
        int charCount[26] = { 0 };
        int numberCount[10] = { 0 };
        char numbers[10] = { '0','1','2','3','4','5','6','7','8','9' };
        string keys = "zwuxgotfsi";
        unordered_map<char, int> key2Number = { {'z',0},{'w',2},{'u',4},{'x',6},{'g',8},{'o',1},{'t',3},{'f',5},{'s',7},{'i',9}, };
        unordered_map<char, string> key2String = { {'z',"zero"},{'w',"two"},{'u',"four"},{'x',"six"},{'g',"eight"},
            {'o',"one"}, {'t',"three"}, {'f',"five"}, {'s',"seven"}, {'i',"nine"} };

        for (char c : s) {
            charCount[c - 'a']++;
        }

        for (char c : keys) {
            int keyCount = charCount[c - 'a'];
            if (keyCount == 0) {
                continue;
            }

            numberCount[key2Number[c]] = keyCount;

            for (char ch : key2String[c]) {
                charCount[ch - 'a'] -= keyCount;
            }
        }

        string original;
        for (int i = 0; i < 10; i++) {
            if (numberCount[i] != 0) {
                original.append(numberCount[i], numbers[i]);
            }
        }

        return original;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("012", o.originalDigits("owoztneoer"));
    check.checkString("45", o.originalDigits("fviefuro"));
    check.checkString("011222333344444555556666777889", o.originalDigits("nineeighteightsevensevensevensixsixsixsixfivefivefivefivefivefourfourfourfourfourthreethreethreethreetwotwotwooneonezero"));
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
