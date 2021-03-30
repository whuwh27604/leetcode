/* 字符串中不同整数的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 word ，该字符串由数字和小写英文字母组成。

请你用空格替换每个不是数字的字符。例如，"a123bc34d8ef34" 将会变成 " 123  34 8  34" 。注意，剩下的这些整数为（相邻彼此至少有一个空格隔开）："123"、"34"、"8" 和 "34" 。

返回对 word 完成替换后形成的 不同 整数的数目。

只有当两个整数的 不含前导零 的十进制表示不同， 才认为这两个整数也不同。

 

示例 1：

输入：word = "a123bc34d8ef34"
输出：3
解释：不同的整数有 "123"、"34" 和 "8" 。注意，"34" 只计数一次。
示例 2：

输入：word = "leet1234code234"
输出：2
示例 3：

输入：word = "a1b01c001"
输出：1
解释："1"、"01" 和 "001" 视为同一个整数的十进制表示，因为在比较十进制值时会忽略前导零的存在。
 

提示：

1 <= word.length <= 1000
word 由数字和小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-different-integers-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> nums;
        int i, j, size = word.size();

        for (i = 0; i < size; ++i) {
            char c = word[i];
            if ((c >= 'a' && c <= 'z')) {
                continue;
            }

            if (c == '0' && i + 1 < size && word[i + 1] >= '0' && word[i + 1] <= '9') {
                continue;
            }

            for (j = i + 1; j < size && (word[j] >= '0' && word[j] <= '9'); ++j) {}
            nums.insert(string(word, i, j - i));
            i = j;
        }

        return nums.size();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.numDifferentIntegers("a123bc34d8ef34"));
    check.checkInt(2, o.numDifferentIntegers("leet1234code234"));
    check.checkInt(1, o.numDifferentIntegers("a1b01c001"));
    check.checkInt(0, o.numDifferentIntegers("a"));
    check.checkInt(1, o.numDifferentIntegers("0"));
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
