/* 字符串转换后的长度 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个整数 t，表示要执行的 转换 次数。每次 转换 需要根据以下规则替换字符串 s 中的每个字符：

如果字符是 'z'，则将其替换为字符串 "ab"。
否则，将其替换为字母表中的下一个字符。例如，'a' 替换为 'b'，'b' 替换为 'c'，依此类推。
返回 恰好 执行 t 次转换后得到的字符串的 长度。

由于答案可能非常大，返回其对 109 + 7 取余的结果。



示例 1：

输入： s = "abcyy", t = 2

输出： 7

解释：

第一次转换 (t = 1)
'a' 变为 'b'
'b' 变为 'c'
'c' 变为 'd'
'y' 变为 'z'
'y' 变为 'z'
第一次转换后的字符串为："bcdzz"
第二次转换 (t = 2)
'b' 变为 'c'
'c' 变为 'd'
'd' 变为 'e'
'z' 变为 "ab"
'z' 变为 "ab"
第二次转换后的字符串为："cdeabab"
最终字符串长度：字符串为 "cdeabab"，长度为 7 个字符。
示例 2：

输入： s = "azbk", t = 1

输出： 5

解释：

第一次转换 (t = 1)
'a' 变为 'b'
'z' 变为 "ab"
'b' 变为 'c'
'k' 变为 'l'
第一次转换后的字符串为："babcl"
最终字符串长度：字符串为 "babcl"，长度为 5 个字符。


提示：

1 <= s.length <= 105
s 仅由小写英文字母组成。
1 <= t <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

int maxT = 100000;
int mod = 1000000007;
vector<vector<int>> lens(26, vector<int>(maxT + 1, 1));

void getLens() {
    for (int t = 1; t <= maxT; ++t) {
        for (int i = 0; i < 26; ++i) {
            int trans = 26 - i;
            if (trans <= t) {
                lens[i][t] = (lens[0][t - trans] + lens[1][t - trans]) % mod;
            }
        }
    }
}

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;        
        getLens();
    }
}

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        init();

        int len = 0;

        for (char c : s) {
            len = (len + lens[c - 'a'][t]) % mod;
        }

        return len;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(7, o.lengthAfterTransformations("abcyy", 2));
    check.checkInt(5, o.lengthAfterTransformations("azbk", 1));
    check.checkInt(704103930, o.lengthAfterTransformations("abcdefghijklmnopqrstuvwxyz", maxT));
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
