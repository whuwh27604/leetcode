/* 不同字符的最小子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
返回字符串 text 中按字典序排列最小的子序列，该子序列包含 text 中所有不同字符一次。

 

示例 1：

输入："cdadabcc"
输出："adbc"
示例 2：

输入："abcd"
输出："abcd"
示例 3：

输入："ecbacba"
输出："eacb"
示例 4：

输入："leetcode"
输出："letcod"
 

提示：

1 <= text.length <= 1000
text 由小写英文字母组成
 

注意：本题目与 316 https://leetcode-cn.com/problems/remove-duplicate-letters/ 相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> lettersCount;
        countLetters(s, lettersCount);

        stack<char> letters;
        letters.push(1);
        removeRedundant(s, lettersCount, letters);

        return getSubsequence(letters);
    }

    void countLetters(string& s, unordered_map<char, int>& lettersCount) {
        for (char c : s) {
            ++lettersCount[c];
        }
    }

    void removeRedundant(string& s, unordered_map<char, int>& lettersCount, stack<char>& letters) {
        unordered_set<char> lettersInStack;

        for (char c : s) {
            --lettersCount[c];  // 标记后序还有没有该字符

            if (lettersInStack.count(c) != 0) {
                continue;  // 栈里面已经有该字符，说明第一个c后面的字符肯定比c大，否则就会把前面一个c踢出栈。所以后来的c抛弃，保留前面的。
            }

            while (c < letters.top() && lettersCount[letters.top()] != 0) {
                lettersInStack.erase(letters.top());
                letters.pop();  // 栈顶字符比当前字符大，并且后序还有它，那么栈顶这个可以抛弃掉了
            }

            letters.push(c);
            lettersInStack.insert(c);
        }
    }

    string getSubsequence(stack<char>& letters) {
        string subsequence;

        while (letters.top() != 1) {
            subsequence += letters.top();
            letters.pop();
        }

        reverse(subsequence.begin(), subsequence.end());
        return subsequence;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("adbc", o.smallestSubsequence("cdadabcc"));
    check.checkString("abcd", o.smallestSubsequence("abcd"));
    check.checkString("eacb", o.smallestSubsequence("ecbacba"));
    check.checkString("letcod", o.smallestSubsequence("leetcode"));
    check.checkString("a", o.smallestSubsequence("a"));
    check.checkString("a", o.smallestSubsequence("aa"));
    check.checkString("aceisdgorl", o.smallestSubsequence("aliceisgoodgoodgoodgirl"));
    check.checkString("acdgoirlhes", o.smallestSubsequence("aliceisgoodgoodgoodgirlsheisa"));
    check.checkString("acdgirlheostun", o.smallestSubsequence("aliceisgoodgoodgoodgirlsheisagoodstudent"));
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
