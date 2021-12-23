/* 使字符串有序的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s （下标从 0 开始）。你需要对 s 执行以下操作直到它变为一个有序字符串：

找到 最大下标 i ，使得 1 <= i < s.length 且 s[i] < s[i - 1] 。
找到 最大下标 j ，使得 i <= j < s.length 且对于所有在闭区间 [i, j] 之间的 k 都有 s[k] < s[i - 1] 。
交换下标为 i - 1​​​​ 和 j​​​​ 处的两个字符。
将下标 i 开始的字符串后缀反转。
请你返回将字符串变成有序的最少操作次数。由于答案可能会很大，请返回它对 109 + 7 取余 的结果。

 

示例 1：

输入：s = "cba"
输出：5
解释：模拟过程如下所示：
操作 1：i=2，j=2。交换 s[1] 和 s[2] 得到 s="cab" ，然后反转下标从 2 开始的后缀字符串，得到 s="cab" 。
操作 2：i=1，j=2。交换 s[0] 和 s[2] 得到 s="bac" ，然后反转下标从 1 开始的后缀字符串，得到 s="bca" 。
操作 3：i=2，j=2。交换 s[1] 和 s[2] 得到 s="bac" ，然后反转下标从 2 开始的后缀字符串，得到 s="bac" 。
操作 4：i=1，j=1。交换 s[0] 和 s[1] 得到 s="abc" ，然后反转下标从 1 开始的后缀字符串，得到 s="acb" 。
操作 5：i=2，j=2。交换 s[1] 和 s[2] 得到 s="abc" ，然后反转下标从 2 开始的后缀字符串，得到 s="abc" 。
示例 2：

输入：s = "aabaa"
输出：2
解释：模拟过程如下所示：
操作 1：i=3，j=4。交换 s[2] 和 s[4] 得到 s="aaaab" ，然后反转下标从 3 开始的后缀字符串，得到 s="aaaba" 。
操作 2：i=4，j=4。交换 s[3] 和 s[4] 得到 s="aaaab" ，然后反转下标从 4 开始的后缀字符串，得到 s="aaaab" 。
示例 3：

输入：s = "cdbea"
输出：63
示例 4：

输入：s = "leetcodeleetcodeleetcode"
输出：982157772
 

提示：

1 <= s.length <= 3000
s​ 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-operations-to-make-string-sorted
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int makeStringSorted(string s) {
        // 按题意一次完整的操作，得到的是s的前一个排列，所以问题就变为了求小于s的排列个数
        int n = s.size(), opers = 0;
        vector<int> factorial(n);
        vector<int> inverse(n);
        vector<int> letters(26, 0);

        calcFactorials(n, factorial, inverse);
        count(s, letters);

        for (char c : s) {  // 第一个字符是c，那么第一个字符小于c的排列肯定都小于s，所以求剩下n个字符的全排列
            --n;

            for (int i = 0; 'a' + i < c; ++i) {
                if (letters[i] != 0) {
                    --letters[i];
                    opers = (opers + calcPermutation(letters, n, factorial, inverse)) % mod;
                    ++letters[i];
                }
            }

            --letters[c - 'a'];
        }

        return opers;
    }

    void count(string& s, vector<int>& letters) {
        for (char c : s) {
            ++letters[c - 'a'];
        }
    }

    int calcPermutation(vector<int>& letters, int n, vector<int>& factorial, vector<int>& inverse) {
        long long permutations = factorial[n];

        for (int num : letters) {
            if (num != 0) {
                permutations = permutations * inverse[num] % mod;
            }
        }

        return (int)permutations;  // n1个x、n2个y、n3个z...的排列方法数是(n1 + n2 + n3 + ...)! / (n1! * n2! * n3! * ...)
    }

    void calcFactorials(int n, vector<int>& factorial, vector<int>& inverse) {
        long long num = 1;
        factorial[0] = inverse[0] = 1;

        for (int i = 1; i < n; ++i) {
            num = (num * i) % mod;
            factorial[i] = (int)num;
            inverse[i] = fastPower(factorial[i], mod - 2);
        }
    }

    int fastPower(int x, int n) {
        long long ans = 1;
        int bit = 1;

        while (n != 0) {
            if ((n & bit) != 0) {
                ans = (ans * x) % mod;
            }

            n &= ~bit;
            bit <<= 1;
            x = ((long long)x * x) % mod;
        }

        return (int)ans;
    }

private:
    int mod = 1000000007;
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(5, o.makeStringSorted("cba"));
    check.checkInt(2, o.makeStringSorted("aabaa"));
    check.checkInt(63, o.makeStringSorted("cdbea"));
    check.checkInt(0, o.makeStringSorted("z"));
    check.checkInt(982157772, o.makeStringSorted("leetcodeleetcodeleetcode"));
    check.checkInt(821830556, o.makeStringSorted("leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode"));
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
