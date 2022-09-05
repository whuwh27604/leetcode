/* 严格回文的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果一个整数 n 在 b 进制下（b 为 2 到 n - 2 之间的所有整数）对应的字符串 全部 都是 回文的 ，那么我们称这个数 n 是 严格回文 的。

给你一个整数 n ，如果 n 是 严格回文 的，请返回 true ，否则返回 false 。

如果一个字符串从前往后读和从后往前读完全相同，那么这个字符串是 回文的 。

 

示例 1：

输入：n = 9
输出：false
解释：在 2 进制下：9 = 1001 ，是回文的。
在 3 进制下：9 = 100 ，不是回文的。
所以，9 不是严格回文数字，我们返回 false 。
注意在 4, 5, 6 和 7 进制下，n = 9 都不是回文的。
示例 2：

输入：n = 4
输出：false
解释：我们只考虑 2 进制：4 = 100 ，不是回文的。
所以我们返回 false 。
 

提示：

4 <= n <= 105

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/strictly-palindromic-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        return false;  // 不存在满足条件的数
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(false, o.isStrictlyPalindromic(9));
    check.checkBool(false, o.isStrictlyPalindromic(4));
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
