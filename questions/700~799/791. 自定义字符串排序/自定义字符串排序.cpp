/* 自定义字符串排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
字符串S和 T 只包含小写字符。在S中，所有字符只会出现一次。

S 已经根据某种规则进行了排序。我们要根据S中的字符顺序对T进行排序。更具体地说，如果S中x在y之前出现，那么返回的字符串中x也应出现在y之前。

返回任意一种符合条件的字符串T。

示例:
输入:
S = "cba"
T = "abcd"
输出: "cbad"
解释:
S中出现了字符 "a", "b", "c", 所以 "a", "b", "c" 的顺序应该是 "c", "b", "a".
由于 "d" 没有在S中出现, 它可以放在T的任意位置. "dcba", "cdba", "cbda" 都是合法的输出。
注意:

S的最大长度为26，其中没有重复的字符。
T的最大长度为200。
S和T只包含小写字符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/custom-sort-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        int letterNums['z' + 1] = { 0 };
        for (char c : T) {
            letterNums[c]++;
        }

        string sortedString;
        for (char c : S) {
            if (letterNums[c] != 0) {
                sortedString.insert(sortedString.end(), letterNums[c], c);
                letterNums[c] = 0;
            }
        }

        for (char i = 'a'; i <= 'z'; i++) {
            if (letterNums[i] != 0) {
                sortedString.insert(sortedString.end(), letterNums[i], i);
            }
        }

        return sortedString;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("cbad", o.customSortString("cba", "abcd"));
    check.checkString("", o.customSortString("", ""));
    check.checkString("a", o.customSortString("", "a"));
    check.checkString("", o.customSortString("a", ""));
    check.checkString("ccbbbaaaad", o.customSortString("cba", "abcdabcaba"));
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
