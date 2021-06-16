/* 所有子字符串美丽值之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个字符串的 美丽值 定义为：出现频率最高字符与出现频率最低字符的出现次数之差。

比方说，"abaacc" 的美丽值为 3 - 1 = 2 。
给你一个字符串 s ，请你返回它所有子字符串的 美丽值 之和。

 

示例 1：

输入：s = "aabcb"
输出：5
解释：美丽值不为零的字符串包括 ["aab","aabc","aabcb","abcb","bcb"] ，每一个字符串的美丽值都为 1 。
示例 2：

输入：s = "aabcbaa"
输出：17
 

提示：

1 <= s.length <= 500
s 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-beauty-of-all-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int i, j, k, size = s.size(), sum = 0, base = size * 26;
        int* counts = new int[size * size * 26]();
        counts[s[0] - 'a'] = 1;

        for (i = 1; i < size; ++i) {
            for (j = 0; j <= i; ++j) {
                for (k = 0; k < 26; ++k) {
                    counts[j * base + i * 26 + k] = counts[j * base + (i - 1) * 26 + k];
                }
                ++counts[j * base + i * 26 + s[i] - 'a'];

                int minFreq = INT_MAX, maxFreq = 0;

                for (k = 0; k < 26; ++k) {
                    int count = counts[j * base + i * 26 + k];
                    if (count != 0) {
                        minFreq = min(minFreq, count);
                        maxFreq = max(maxFreq, count);
                    }
                }

                sum += (maxFreq - minFreq);
            }
        }

        delete[] counts;
        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(5, o.beautySum("aabcb"));
    check.checkInt(17, o.beautySum("aabcbaa"));
    check.checkInt(0, o.beautySum("z"));
    check.checkInt(143567, o.beautySum("eryeyreyroyerskdhkhfkhkfhhhhhhhhhhhhhhhhheryeyreyroyerskdhkhfkhkfhhhhhhhhhhhhhhhhheryeyreyroyerskdhkhfkhkfhhhhhhhhhhhhhhhhh"));
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
