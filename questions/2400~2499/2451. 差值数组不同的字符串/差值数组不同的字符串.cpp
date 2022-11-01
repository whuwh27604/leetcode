/* 差值数组不同的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串数组 words ，每一个字符串长度都相同，令所有字符串的长度都为 n 。

每个字符串 words[i] 可以被转化为一个长度为 n - 1 的 差值整数数组 difference[i] ，其中对于 0 <= j <= n - 2 有 difference[i][j] = words[i][j+1] - words[i][j] 。注意两个字母的差值定义为它们在字母表中 位置 之差，也就是说 'a' 的位置是 0 ，'b' 的位置是 1 ，'z' 的位置是 25 。

比方说，字符串 "acb" 的差值整数数组是 [2 - 0, 1 - 2] = [2, -1] 。
words 中所有字符串 除了一个字符串以外 ，其他字符串的差值整数数组都相同。你需要找到那个不同的字符串。

请你返回 words中 差值整数数组 不同的字符串。

 

示例 1：

输入：words = ["adc","wzy","abc"]
输出："abc"
解释：
- "adc" 的差值整数数组是 [3 - 0, 2 - 3] = [3, -1] 。
- "wzy" 的差值整数数组是 [25 - 22, 24 - 25]= [3, -1] 。
- "abc" 的差值整数数组是 [1 - 0, 2 - 1] = [1, 1] 。
不同的数组是 [1, 1]，所以返回对应的字符串，"abc"。
示例 2：

输入：words = ["aaa","bob","ccc","ddd"]
输出："bob"
解释：除了 "bob" 的差值整数数组是 [13, -13] 以外，其他字符串的差值整数数组都是 [0, 0] 。
 

提示：

3 <= words.length <= 100
n == words[i].length
2 <= n <= 20
words[i] 只含有小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/odd-string-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string oddString(vector<string>& words) {
        int i, j, size = words.size(), n = words[0].size();

        for (j = 1; j < n; ++j) {
            int diff0 = words[0][j] - words[0][j - 1], diff1 = words[1][j] - words[1][j - 1];
            if (diff0 != diff1) {
                return words[2][j] - words[2][j - 1] == diff0 ? words[1] : words[0];
            }
            else {
                for (i = 2; i < size; ++i) {
                    if (words[i][j] - words[i][j - 1] != diff0) {
                        return words[i];
                    }
                }
            }
        }

        return words[0];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "adc","wzy","abc" };
    check.checkString("abc", o.oddString(words));

    words = { "aaa","bob","ccc","ddd" };
    check.checkString("bob", o.oddString(words));
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
