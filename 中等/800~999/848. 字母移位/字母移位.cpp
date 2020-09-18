/* 字母移位.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个由小写字母组成的字符串 S，和一个整数数组 shifts。

我们将字母表中的下一个字母称为原字母的 移位（由于字母表是环绕的， 'z' 将会变成 'a'）。

例如·，shift('a') = 'b'， shift('t') = 'u',， 以及 shift('z') = 'a'。

对于每个 shifts[i] = x ， 我们会将 S 中的前 i+1 个字母移位 x 次。

返回将所有这些移位都应用到 S 后最终得到的字符串。

示例：

输入：S = "abc", shifts = [3,5,9]
输出："rpl"
解释：
我们以 "abc" 开始。
将 S 中的第 1 个字母移位 3 次后，我们得到 "dbc"。
再将 S 中的前 2 个字母移位 5 次后，我们得到 "igc"。
最后将 S 中的这 3 个字母移位 9 次后，我们得到答案 "rpl"。
提示：

1 <= S.length = shifts.length <= 20000
0 <= shifts[i] <= 10 ^ 9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shifting-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int i, size = S.size(), sum = 0;
        string shifted(size, 0);

        for (i = size - 1; i >= 0; --i) {
            sum = (sum + shifts[i]) % 26;
            shifted[i] = ('z' - S[i] >= sum) ? S[i] + sum : sum - ('z' - S[i] + 1) + 'a';
        }

        return shifted;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> shifts = { 3,5,9 };
    check.checkString("rpl", o.shiftingLetters("abc", shifts));

    shifts = { 1,2 };
    check.checkString("ca", o.shiftingLetters("zy", shifts));

    shifts = { 26 };
    check.checkString("g", o.shiftingLetters("g", shifts));
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
