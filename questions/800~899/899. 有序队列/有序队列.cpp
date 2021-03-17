/* 有序队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出了一个由小写字母组成的字符串 S。然后，我们可以进行任意次数的移动。

在每次移动中，我们选择前 K 个字母中的一个（从左侧开始），将其从原位置移除，并放置在字符串的末尾。

返回我们在任意次数的移动之后可以拥有的按字典顺序排列的最小字符串。

 

示例 1：

输入：S = "cba", K = 1
输出："acb"
解释：
在第一步中，我们将第一个字符（“c”）移动到最后，获得字符串 “bac”。
在第二步中，我们将第一个字符（“b”）移动到最后，获得最终结果 “acb”。
示例 2：

输入：S = "baaca", K = 3
输出："aaabc"
解释：
在第一步中，我们将第一个字符（“b”）移动到最后，获得字符串 “aacab”。
在第二步中，我们将第三个字符（“c”）移动到最后，获得最终结果 “aaabc”。
 

提示：

1 <= K <= S.length <= 1000
S 只由小写字母组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/orderly-queue
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string orderlyQueue(string S, int K) {
        return K == 1 ? orderlyQueueK1(S) : orderlyQueueK2(S);
    }

    string orderlyQueueK1(string& s) {
        char minChar = *min_element(s.begin(), s.end());
        string minString = "{";
        int i, size = s.size();

        for (i = 0; i < size; ++i) {  // k等于1时，比较所有以最小字符开头的子串，取字典序最小的
            if (s[i] == minChar) {
                minString = min(minString, string(s, i, size - i) + string(s, 0, i));
            }
        }

        return minString;
    }

    string orderlyQueueK2(string& s) {
        vector<int> count('z' + 1, 0);
        string minString;

        for (char c : s) {
            ++count[c];
        }

        for (char c = 'a'; c <= 'z'; ++c) {  // k大于1时，一定可以把任意字符交换到任意位置，所以只需要输出字典序最小的就可以了
            if (count[c] != 0) {
                minString += string(count[c], c);
            }
        }

        return minString;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("acb", o.orderlyQueue("cba", 1));
    check.checkString("acb", o.orderlyQueue("acb", 1));
    check.checkString("abacb", o.orderlyQueue("acbab", 1));
    check.checkString("aaabc", o.orderlyQueue("baaca", 3));
    check.checkString("z", o.orderlyQueue("z", 1));
    check.checkString("z", o.orderlyQueue("z", 2));
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
