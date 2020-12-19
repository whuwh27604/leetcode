/* 长度为 n 的开心字符串中字典序第 k 小的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个 「开心字符串」定义为：

仅包含小写字母 ['a', 'b', 'c'].
对所有在 1 到 s.length - 1 之间的 i ，满足 s[i] != s[i + 1] （字符串的下标从 1 开始）。
比方说，字符串 "abc"，"ac"，"b" 和 "abcbabcbcb" 都是开心字符串，但是 "aa"，"baa" 和 "ababbc" 都不是开心字符串。

给你两个整数 n 和 k ，你需要将长度为 n 的所有开心字符串按字典序排序。

请你返回排序后的第 k 个开心字符串，如果长度为 n 的开心字符串少于 k 个，那么请你返回 空字符串 。

 

示例 1：

输入：n = 1, k = 3
输出："c"
解释：列表 ["a", "b", "c"] 包含了所有长度为 1 的开心字符串。按照字典序排序后第三个字符串为 "c" 。
示例 2：

输入：n = 1, k = 4
输出：""
解释：长度为 1 的开心字符串只有 3 个。
示例 3：

输入：n = 3, k = 9
输出："cab"
解释：长度为 3 的开心字符串总共有 12 个 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"] 。第 9 个字符串为 "cab"
示例 4：

输入：n = 2, k = 7
输出：""
示例 5：

输入：n = 10, k = 100
输出："abacbabacb"
 

提示：

1 <= n <= 10
1 <= k <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        string happyStr;
        vector<char> firstLayer = { 'a','b','c' };
        unordered_map<char, vector<char>> next = { {'a', {'b', 'c'}},{'b', {'a', 'c'}},{'c', {'a', 'b'}} };

        int count = (int)pow(2, n - 1);
        if (k > count * 3) {
            return "";
        }

        k -= 1;
        char current = firstLayer[k / count];
        happyStr += current;
        k %= count;
        int left = 0, right = count - 1;

        for (int layer = 1; layer < n; ++layer) {
            int middle = (left + right) / 2;
            int leftOrRight = (k > middle) ? 1 : 0;
            current = next[current][leftOrRight];
            happyStr += current;

            if (leftOrRight == 0) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }

        return happyStr;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("cab", o.getHappyString(3, 9));
    check.checkString("a", o.getHappyString(1, 1));
    check.checkString("c", o.getHappyString(1, 3));
    check.checkString("", o.getHappyString(1, 4));
    check.checkString("", o.getHappyString(2, 7));
    check.checkString("ababa", o.getHappyString(5, 1));
    check.checkString("abacbabacb", o.getHappyString(10, 100));
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
