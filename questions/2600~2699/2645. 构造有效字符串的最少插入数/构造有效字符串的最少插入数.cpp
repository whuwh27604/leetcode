/* 构造有效字符串的最少插入数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 word ，你可以向其中任何位置插入 "a"、"b" 或 "c" 任意次，返回使 word 有效 需要插入的最少字母数。

如果字符串可以由 "abc" 串联多次得到，则认为该字符串 有效 。



示例 1：

输入：word = "b"
输出：2
解释：在 "b" 之前插入 "a" ，在 "b" 之后插入 "c" 可以得到有效字符串 "abc" 。
示例 2：

输入：word = "aaa"
输出：6
解释：在每个 "a" 之后依次插入 "b" 和 "c" 可以得到有效字符串 "abcabcabc" 。
示例 3：

输入：word = "abc"
输出：0
解释：word 已经是有效字符串，不需要进行修改。


提示：

1 <= word.length <= 50
word 仅由字母 "a"、"b" 和 "c" 组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int addMinimum(string word) {
        char want = 'a';
        int size = word.size(), index = 0, add = 0;

        while (index < size) {
            if (word[index] == want) {
                ++index;
            }
            else {
                ++add;
            }

            ++want;
            if (want == 'd') {
                want = 'a';
            }
        }

        add += (want == 'a' ? 0 : (want == 'b' ? 2 : 1));

        return add;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.addMinimum("b"));
    check.checkInt(6, o.addMinimum("aaa"));
    check.checkInt(0, o.addMinimum("abc"));
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
