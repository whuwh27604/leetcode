﻿/* 你完成的完整对局数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一款新的在线电子游戏在近期发布，在该电子游戏中，以 刻钟 为周期规划若干时长为 15 分钟 的游戏对局。这意味着，在 HH:00、HH:15、HH:30 和 HH:45 ，将会开始一个新的对局，其中 HH 用一个从 00 到 23 的整数表示。游戏中使用 24 小时制的时钟 ，所以一天中最早的时间是 00:00 ，最晚的时间是 23:59 。

给你两个字符串 startTime 和 finishTime ，均符合 "HH:MM" 格式，分别表示你 进入 和 退出 游戏的确切时间，请计算在整个游戏会话期间，你完成的 完整对局的对局数 。

例如，如果 startTime = "05:20" 且 finishTime = "05:59" ，这意味着你仅仅完成从 05:30 到 05:45 这一个完整对局。而你没有完成从 05:15 到 05:30 的完整对局，因为你是在对局开始后进入的游戏；同时，你也没有完成从 05:45 到 06:00 的完整对局，因为你是在对局结束前退出的游戏。
如果 finishTime 早于 startTime ，这表示你玩了个通宵（也就是从 startTime 到午夜，再从午夜到 finishTime）。

假设你是从 startTime 进入游戏，并在 finishTime 退出游戏，请计算并返回你完成的 完整对局的对局数 。

 

示例 1：

输入：startTime = "12:01", finishTime = "12:44"
输出：1
解释：你完成了从 12:15 到 12:30 的一个完整对局。
你没有完成从 12:00 到 12:15 的完整对局，因为你是在对局开始后的 12:01 进入的游戏。
你没有完成从 12:30 到 12:45 的完整对局，因为你是在对局结束前的 12:44 退出的游戏。
示例 2：

输入：startTime = "20:00", finishTime = "06:00"
输出：40
解释：你完成了从 20:00 到 00:00 的 16 个完整的对局，以及从 00:00 到 06:00 的 24 个完整的对局。
16 + 24 = 40
示例 3：

输入：startTime = "00:00", finishTime = "23:59"
输出：95
解释：除最后一个小时你只完成了 3 个完整对局外，其余每个小时均完成了 4 场完整对局。
 

提示：

startTime 和 finishTime 的格式为 HH:MM
00 <= HH <= 23
00 <= MM <= 59
startTime 和 finishTime 不相等

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-number-of-full-rounds-you-have-played
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int start = ((startTime[0] - '0') * 10 + (startTime[1] - '0')) * 60 + (startTime[3] - '0') * 10 + (startTime[4] - '0');
        int end = ((finishTime[0] - '0') * 10 + (finishTime[1] - '0')) * 60 + (finishTime[3] - '0') * 10 + (finishTime[4] - '0');

        if (end < start) {
            end += (24 * 60);
        }

        int remainder = start % 15;
        start += (remainder == 0 ? 0 : (15 - remainder));

        return (end - start) / 15;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.numberOfRounds("12:01", "12:44"));
    check.checkInt(40, o.numberOfRounds("20:00", "06:00"));
    check.checkInt(95, o.numberOfRounds("00:00", "23:59"));
    check.checkInt(95, o.numberOfRounds("00:01", "00:00"));
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
