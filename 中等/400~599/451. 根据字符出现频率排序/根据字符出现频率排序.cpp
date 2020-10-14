/* 根据字符出现频率排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串，请将字符串里的字符按照出现的频率降序排列。

示例 1:

输入:
"tree"

输出:
"eert"

解释:
'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
示例 2:

输入:
"cccaaa"

输出:
"cccaaa"

解释:
'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。
示例 3:

输入:
"Aabb"

输出:
"bbAa"

解释:
此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-characters-by-frequency
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int charCount[256] = {0};
        for (char c : s) {
            charCount[c + 128]++;
        }

        multimap<int, char> sortedChar;
        for (int i = -128; i < 128; i++) {
            if (charCount[i + 128] != 0) {
                sortedChar.insert({ charCount[i + 128], (char)i });
            }
        }

        string ans;
        for (auto rit = sortedChar.rbegin(); rit != sortedChar.rend(); rit++) {
            ans.insert(ans.end(), rit->first, rit->second);
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("eetr", o.frequencySort("tree"));
    check.checkString("cccaaa", o.frequencySort("cccaaa"));
    check.checkString("bbaA", o.frequencySort("Aabb"));
    check.checkString("", o.frequencySort(""));
    check.checkString("z", o.frequencySort("z"));
    check.checkString("fffeeeddccba", o.frequencySort("abccddeeefff"));
    check.checkString("ZZZZZZZZCCCCCCCBBBBBBAAAAAzzzzcccbba", o.frequencySort("abbccczzzzAAAAABBBBBBCCCCCCCZZZZZZZZ"));
    string s;
    s.insert(0, 1, 127);
    s.insert(0, 2, -128);
    check.checkString(s, o.frequencySort(s));
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
