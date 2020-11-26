/* 猜数字大小.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们正在玩一个猜数字游戏。 游戏规则如下：
我从 1 到 n 选择一个数字。 你需要猜我选择了哪个数字。
每次你猜错了，我会告诉你这个数字是大了还是小了。
你调用一个预先定义好的接口 guess(int num)，它会返回 3 个可能的结果（-1，1 或 0）：

-1 : 我的数字比较小
 1 : 我的数字比较大
 0 : 恭喜！你猜对了！
示例 :

输入: n = 10, pick = 6
输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/guess-number-higher-or-lower
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
int choseNum;
int guess(int num) {
    if (num == choseNum) {
        return 0;
    }

    if (num > choseNum) {
        return -1;
    }

    return 1;
}

class Solution {
public:
    int guessNumber(int n) {
        return halfGuess(1, n);
    }

    int halfGuess(long long left, long long right) {
        long long middle = ((left + right) / 2);
        int answer = guess((int)middle);
        if (answer == 0) {
            return (int)middle;
        }

        if (answer == 1) {
            return halfGuess((middle + 1), right);
        }

        return halfGuess(left, (middle - 1));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    choseNum = 6;
    check.checkInt(choseNum, o.guessNumber(10));

    choseNum = 1;
    check.checkInt(choseNum, o.guessNumber(10));

    choseNum = 10;
    check.checkInt(choseNum, o.guessNumber(10));

    choseNum = 1702766719;
    check.checkInt(choseNum, o.guessNumber(2126753390));
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
