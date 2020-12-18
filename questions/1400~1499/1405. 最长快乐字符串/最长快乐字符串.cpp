/* 最长快乐字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果字符串中不含有任何 'aaa'，'bbb' 或 'ccc' 这样的字符串作为子串，那么该字符串就是一个「快乐字符串」。

给你三个整数 a，b ，c，请你返回 任意一个 满足下列全部条件的字符串 s：

s 是一个尽可能长的快乐字符串。
s 中 最多 有a 个字母 'a'、b 个字母 'b'、c 个字母 'c' 。
s 中只含有 'a'、'b' 、'c' 三种字母。
如果不存在这样的字符串 s ，请返回一个空字符串 ""。

 

示例 1：

输入：a = 1, b = 1, c = 7
输出："ccaccbcc"
解释："ccbccacc" 也是一种正确答案。
示例 2：

输入：a = 2, b = 2, c = 1
输出："aabbc"
示例 3：

输入：a = 7, b = 1, c = 0
输出："aabaa"
解释：这是该测试用例的唯一正确答案。
 

提示：

0 <= a, b, c <= 100
a + b + c > 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-happy-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string diverse;
        vector<pair<int, char>> letters = { {a,'a'},{b,'b'},{c,'c'} };
        sort(letters.begin(), letters.end());

        while (letters[1].first != 0) {
            int num = (letters[2].first > 1) ? 2 : 1;
            letters[2].first -= num;
            diverse.append(num, letters[2].second);

            num = letters[1].first > max(letters[2].first, 1) ? 2 : 1;
            letters[1].first -= num;
            diverse.append(num, letters[1].second);

            sort(letters.begin(), letters.end());
        }

        diverse.append(min(letters[2].first, 2), letters[2].second);

        return diverse;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("ccbccacc", o.longestDiverseString(1, 1, 7));
    check.checkString("bbaac", o.longestDiverseString(2, 2, 1));
    check.checkString("aabaa", o.longestDiverseString(7, 1, 0));
    check.checkString("b", o.longestDiverseString(0, 1, 0));
    check.checkString("ccbbaacba", o.longestDiverseString(3, 3, 3));
    check.checkString("ccbccbccbbccbbccbbc", o.longestDiverseString(0, 8, 11));
    check.checkString("bbc", o.longestDiverseString(0, 2, 1));
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
