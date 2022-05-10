/* 统计打字方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Alice 在给 Bob 用手机打字。数字到字母的 对应 如下图所示。



为了 打出 一个字母，Alice 需要 按 对应字母 i 次，i 是该字母在这个按键上所处的位置。

比方说，为了按出字母 's' ，Alice 需要按 '7' 四次。类似的， Alice 需要按 '5' 两次得到字母  'k' 。
注意，数字 '0' 和 '1' 不映射到任何字母，所以 Alice 不 使用它们。
但是，由于传输的错误，Bob 没有收到 Alice 打字的字母信息，反而收到了 按键的字符串信息 。

比方说，Alice 发出的信息为 "bob" ，Bob 将收到字符串 "2266622" 。
给你一个字符串 pressedKeys ，表示 Bob 收到的字符串，请你返回 Alice 总共可能发出多少种文字信息 。

由于答案可能很大，将它对 109 + 7 取余 后返回。

 

示例 1：

输入：pressedKeys = "22233"
输出：8
解释：
Alice 可能发出的文字信息包括：
"aaadd", "abdd", "badd", "cdd", "aaae", "abe", "bae" 和 "ce" 。
由于总共有 8 种可能的信息，所以我们返回 8 。
示例 2：

输入：pressedKeys = "222222222222222222222222222222222222"
输出：82876089
解释：
总共有 2082876103 种 Alice 可能发出的文字信息。
由于我们需要将答案对 109 + 7 取余，所以我们返回 2082876103 % (109 + 7) = 82876089 。
 

提示：

1 <= pressedKeys.length <= 105
pressedKeys 只包含数字 '2' 到 '9' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-number-of-texts
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

vector<long long> texts1(100001), texts2(100001);
int mod = 1000000007;

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;

        texts1[1] = 1, texts1[2] = 2, texts1[3] = 4;
        texts2[1] = 1, texts2[2] = 2, texts2[3] = 4, texts2[4] = 8;

        for (int i = 4; i <= 100000; ++i) {
            texts1[i] = (texts1[i - 1] + texts1[i - 2] + texts1[i - 3]) % mod;
        }

        for (int i = 5; i <= 100000; ++i) {
            texts2[i] = (texts2[i - 1] + texts2[i - 2] + texts2[i - 3] + texts2[i - 4]) % mod;
        }
    }
}

class Solution {
public:
    int countTexts(string pressedKeys) {
        long long texts = 1;
        int consecutive = 1;
        char prev = 0;

        init();
        pressedKeys.push_back('0');

        for (char c : pressedKeys) {
            if (c == prev) {
                ++consecutive;
            }
            else {
                texts = (texts * (prev == '7' || prev == '9' ? texts2[consecutive] : texts1[consecutive]) % mod);
                consecutive = 1;
            }

            prev = c;
        }

        return (int)texts;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(8, o.countTexts("22233"));
    check.checkInt(82876089, o.countTexts("222222222222222222222222222222222222"));
    check.checkInt(8, o.countTexts("7777"));
    check.checkInt(15, o.countTexts("77777"));
    check.checkInt(484622224, o.countTexts("22333444455555666666777777788888888999999999"));
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
