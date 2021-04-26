/* 统计元音字母序列的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n，请你帮忙统计一下我们可以按下述规则形成多少个长度为 n 的字符串：

字符串中的每个字符都应当是小写元音字母（'a', 'e', 'i', 'o', 'u'）
每个元音 'a' 后面都只能跟着 'e'
每个元音 'e' 后面只能跟着 'a' 或者是 'i'
每个元音 'i' 后面 不能 再跟着另一个 'i'
每个元音 'o' 后面只能跟着 'i' 或者是 'u'
每个元音 'u' 后面只能跟着 'a'
由于答案可能会很大，所以请你返回 模 10^9 + 7 之后的结果。

 

示例 1：

输入：n = 1
输出：5
解释：所有可能的字符串分别是："a", "e", "i" , "o" 和 "u"。
示例 2：

输入：n = 2
输出：10
解释：所有可能的字符串分别是："ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" 和 "ua"。
示例 3：

输入：n = 5
输出：68
 

提示：

1 <= n <= 2 * 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-vowels-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        long long a = 1, e = 1, i = 1, o = 1, u = 1, mod = 1000000007; 

        for (int k = 2; k <= n; ++k) {
            long long tmpA = (e + i + u) % mod;
            long long tmpE = (a + i) % mod;
            long long tmpI = (e + o) % mod;
            long long tmpO = i;
            long long tmpU = (i + o) % mod;
            a = tmpA;
            e = tmpE;
            i = tmpI;
            o = tmpO;
            u = tmpU;
        }

        return (int)((a + e + i + o + u) % mod);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(5, o.countVowelPermutation(1));
    check.checkInt(10, o.countVowelPermutation(2));
    check.checkInt(68, o.countVowelPermutation(5));
    check.checkInt(173981881, o.countVowelPermutation(100));
    check.checkInt(89945857, o.countVowelPermutation(1000));
    check.checkInt(759959057, o.countVowelPermutation(20000));
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
