/* 兼具大小写的最好英文字母.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由英文字母组成的字符串 s ，请你找出并返回 s 中的 最好 英文字母。返回的字母必须为大写形式。如果不存在满足条件的字母，则返回一个空字符串。

最好 英文字母的大写和小写形式必须 都 在 s 中出现。

英文字母 b 比另一个英文字母 a 更好 的前提是：英文字母表中，b 在 a 之 后 出现。

 

示例 1：

输入：s = "lEeTcOdE"
输出："E"
解释：
字母 'E' 是唯一一个大写和小写形式都出现的字母。
示例 2：

输入：s = "arRAzFif"
输出："R"
解释：
字母 'R' 是大写和小写形式都出现的最好英文字母。
注意 'A' 和 'F' 的大写和小写形式也都出现了，但是 'R' 比 'F' 和 'A' 更好。
示例 3：

输入：s = "AbCdEfGhIjK"
输出：""
解释：
不存在大写和小写形式都出现的字母。
 

提示：

1 <= s.length <= 1000
s 由小写和大写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/greatest-english-letter-in-upper-and-lower-case
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        vector<int> exist(26, 0);

        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                exist[c - 'a'] |= 1;
            }
            else {
                exist[c - 'A'] |= 2;
            }
        }

        for (int i = 25; i >= 0; --i) {
            if (exist[i] == 3) {
                return string(1, 'A' + i);
            }
        }

        return "";
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("E", o.greatestLetter("lEeTcOdE"));
    check.checkString("R", o.greatestLetter("arRAzFif"));
    check.checkString("", o.greatestLetter("AbCdEfGhIjK"));
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
