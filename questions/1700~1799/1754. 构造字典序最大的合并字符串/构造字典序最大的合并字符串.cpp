/* 构造字典序最大的合并字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 word1 和 word2 。你需要按下述方式构造一个新字符串 merge ：如果 word1 或 word2 非空，选择 下面选项之一 继续操作：

如果 word1 非空，将 word1 中的第一个字符附加到 merge 的末尾，并将其从 word1 中移除。
例如，word1 = "abc" 且 merge = "dv" ，在执行此选项操作之后，word1 = "bc" ，同时 merge = "dva" 。
如果 word2 非空，将 word2 中的第一个字符附加到 merge 的末尾，并将其从 word2 中移除。
例如，word2 = "abc" 且 merge = "" ，在执行此选项操作之后，word2 = "bc" ，同时 merge = "a" 。
返回你可以构造的字典序 最大 的合并字符串 merge 。

长度相同的两个字符串 a 和 b 比较字典序大小，如果在 a 和 b 出现不同的第一个位置，a 中字符在字母表中的出现顺序位于 b 中相应字符之后，就认为字符串 a 按字典序比字符串 b 更大。例如，"abcd" 按字典序比 "abcc" 更大，因为两个字符串出现不同的第一个位置是第四个字符，而 d 在字母表中的出现顺序位于 c 之后。

 

示例 1：

输入：word1 = "cabaa", word2 = "bcaaa"
输出："cbcabaaaaa"
解释：构造字典序最大的合并字符串，可行的一种方法如下所示：
- 从 word1 中取第一个字符：merge = "c"，word1 = "abaa"，word2 = "bcaaa"
- 从 word2 中取第一个字符：merge = "cb"，word1 = "abaa"，word2 = "caaa"
- 从 word2 中取第一个字符：merge = "cbc"，word1 = "abaa"，word2 = "aaa"
- 从 word1 中取第一个字符：merge = "cbca"，word1 = "baa"，word2 = "aaa"
- 从 word1 中取第一个字符：merge = "cbcab"，word1 = "aa"，word2 = "aaa"
- 将 word1 和 word2 中剩下的 5 个 a 附加到 merge 的末尾。
示例 2：

输入：word1 = "abcabc", word2 = "abdcaba"
输出："abdcabcabcaba"
 

提示：

1 <= word1.length, word2.length <= 3000
word1 和 word2 仅由小写英文组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-merge-of-two-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i = 0, j = 0, size1 = word1.size(), size2 = word2.size();
        string largest;

        while (i < size1 && j < size2) {
            if (word1[i] > word2[j]) {
                largest += word1[i++];
            }
            else if (word1[i] < word2[j]) {
                largest += word2[j++];
            }
            else {
                if (word1.compare(i, string::npos, word2, j, string::npos) > 0) {
                    largest += word1[i++];
                }
                else {
                    largest += word2[j++];
                }
            }
        }

        largest += string(word1, i, size1 - i);
        largest += string(word2, j, size2 - j);

        return largest;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("cbcabaaaaa", o.largestMerge("cabaa", "bcaaa"));
    check.checkString("abdcabcabcaba", o.largestMerge("abcabc", "abdcaba"));
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
