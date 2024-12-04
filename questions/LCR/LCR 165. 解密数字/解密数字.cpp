/* 解密数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
现有一串神秘的密文 ciphertext，经调查，密文的特点和规则如下：

密文由非负整数组成
数字 0-25 分别对应字母 a-z
请根据上述规则将密文 ciphertext 解密为字母，并返回共有多少种解密结果。





示例 1:

输入: ciphertext = 216612
输出: 6
解释: 216612 解密后有 6 种不同的形式，分别是 "cbggbc"，"vggbc"，"vggm"，"cbggm"，"cqgbc" 和 "cqgm"


提示：

0 <= ciphertext < 231
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int crackNumber(int ciphertext) {
        string s = to_string(ciphertext);
        int size = (int)s.size();
        vector<int> count(size + 1, 1);

        for (int i = 1; i < size; ++i) {
            count[i + 1] = count[i];
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '6')) {
                count[i + 1] += count[i - 1];
            }
        }

        return count.back();
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(6, o.crackNumber(216612));
    check.checkInt(1, o.crackNumber(0));
    check.checkInt(3, o.crackNumber(1234567890));
    check.checkInt(18, o.crackNumber(1230123012));
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
