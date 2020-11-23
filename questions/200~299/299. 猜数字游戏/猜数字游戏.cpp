/* 猜数字游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你正在和你的朋友玩 猜数字（Bulls and Cows）游戏：你写下一个数字让你的朋友猜。每次他猜测后，你给他一个提示，告诉他有多少位数字和确切位置都猜对了（称为“Bulls”, 公牛），有多少位数字猜对了但是位置不对（称为“Cows”, 奶牛）。你的朋友将会根据提示继续猜，直到猜出秘密数字。

请写出一个根据秘密数字和朋友的猜测数返回提示的函数，用 A 表示公牛，用 B 表示奶牛。

请注意秘密数字和朋友的猜测数都可能含有重复数字。

示例 1:

输入: secret = "1807", guess = "7810"

输出: "1A3B"

解释: 1 公牛和 3 奶牛。公牛是 8，奶牛是 0, 1 和 7。
示例 2:

输入: secret = "1123", guess = "0111"

输出: "1A1B"

解释: 朋友猜测数中的第一个 1 是公牛，第二个或第三个 1 可被视为奶牛。
说明: 你可以假设秘密数字和朋友的猜测数都只包含数字，并且它们的长度永远相等。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bulls-and-cows
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int sTable[10] = { 0 };
        int gTable[10] = { 0 };
        int A = 0, B = 0;
        unsigned int i;

        for (i = 0; i < secret.size(); i++) {
            int sNum = (secret[i] - '0');
            int gNum = (guess[i] - '0');
            if (sNum == gNum) {
                A++;
            }
            else {
                sTable[sNum]++;
                gTable[gNum]++;
            }
        }

        for (i = 0; i < 10; i++) {
            if (sTable[i] < gTable[i]) {
                B += sTable[i];
            }
            else {
                B += gTable[i];
            }
        }

        return to_string(A) + "A" + to_string(B) + "B";
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string secret = "1807";
    string guess = "7810";
    string expected = "1A3B";
    check.checkString(expected, o.getHint(secret, guess));

    secret = "1123";
    guess = "0111";
    expected = "1A1B";
    check.checkString(expected, o.getHint(secret, guess));

    secret = "1";
    guess = "0";
    expected = "0A0B";
    check.checkString(expected, o.getHint(secret, guess));

    secret = "1";
    guess = "1";
    expected = "1A0B";
    check.checkString(expected, o.getHint(secret, guess));

    secret = "1123";
    guess = "1123";
    expected = "4A0B";
    check.checkString(expected, o.getHint(secret, guess));

    secret = "1123";
    guess = "3211";
    expected = "0A4B";
    check.checkString(expected, o.getHint(secret, guess));
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
