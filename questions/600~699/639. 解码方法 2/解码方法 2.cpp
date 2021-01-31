/* 解码方法 2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一条包含字母 A-Z 的消息通过以下的方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
除了上述的条件以外，现在加密字符串可以包含字符 '*'了，字符'*'可以被当做1到9当中的任意一个数字。

给定一条包含数字和字符'*'的加密信息，请确定解码方法的总数。

同时，由于结果值可能会相当的大，所以你应当对109 + 7取模。（翻译者标注：此处取模主要是为了防止溢出）

示例 1 :

输入: "*"
输出: 9
解释: 加密的信息可以被解密为: "A", "B", "C", "D", "E", "F", "G", "H", "I".
示例 2 :

输入: "1*"
输出: 9 + 9 = 18（翻译者标注：这里1*可以分解为1,* 或者当做1*来处理，所以结果是9+9=18）
说明 :

输入的字符串长度范围是 [1, 105]。
输入的字符串只会包含字符 '*' 和 数字'0' - '9'。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-ways-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<vector<int>> factorPrevTwo = {  // 当前字符和前一个字符联合起来解释的可能性，最后一行一列表示是字符*
            {0,0,0,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,1,1,1,1,1,9},  // 注意*只能转义为1~9，不能转义为0，所以"1*"不能转义为10
            {1,1,1,1,1,1,1,0,0,0,6},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {2,2,2,2,2,2,2,1,1,1,15} };
        vector<int> factorPrev = { 0,1,1,1,1,1,1,1,1,1,9 };  // 不管前一个字符是什么，当前字符单独解释时，结果只和自身是什么字符有关

        int i, size = s.size(), mod = 1000000007;
        vector<long long> dp(size + 1);
        dp[0] = 1;
        dp[1] = (s[0] == '*' ? 9 : s[0] == '0' ? 0 : 1);

        for (i = 1; i < size; ++i) {
            int prev = s[i - 1] == '*' ? 10 : s[i - 1] - '0', current = s[i] == '*' ? 10 : s[i] - '0';
            dp[i + 1] = (factorPrevTwo[prev][current] * dp[i - 1] + factorPrev[current] * dp[i]) % mod;
        }

        return (int)dp[size];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(9, o.numDecodings("*"));
    check.checkInt(18, o.numDecodings("1*"));
    check.checkInt(700198546, o.numDecodings("****************************"));
    check.checkInt(2, o.numDecodings("12"));
    check.checkInt(3, o.numDecodings("226"));
    check.checkInt(0, o.numDecodings("0226"));
    check.checkInt(0, o.numDecodings("000226"));
    check.checkInt(1, o.numDecodings("1"));
    check.checkInt(1, o.numDecodings("2"));
    check.checkInt(1, o.numDecodings("10"));
    check.checkInt(1, o.numDecodings("8"));
    check.checkInt(1, o.numDecodings("20"));
    check.checkInt(2, o.numDecodings("26"));
    check.checkInt(1, o.numDecodings("27"));
    check.checkInt(1, o.numDecodings("99"));
    check.checkInt(0, o.numDecodings("100"));
    check.checkInt(0, o.numDecodings("0"));
    check.checkInt(0, o.numDecodings("000"));
    check.checkInt(1, o.numDecodings("101"));
    check.checkInt(1, o.numDecodings("2101"));
    check.checkInt(1597, o.numDecodings("1111111111111111"));
    check.checkInt(1536, o.numDecodings("11437877141634163196491614691641649146"));
    check.checkInt(768, o.numDecodings("12437877242634263296492624692642649246"));
    check.checkInt(679053282, o.numDecodings("***11437877141634**16319649161469164*****1649146********"));
    check.checkInt(899814395, o.numDecodings("*12437***87724263***42632964******92624692642649246***************"));
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
