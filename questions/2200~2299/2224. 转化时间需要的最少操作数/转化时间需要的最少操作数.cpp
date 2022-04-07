// 转化时间需要的最少操作数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int convertTime(string current, string correct) {
        int cHour = (current[0] - '0') * 10 + (current[1] - '0'), cMinute = (current[3] - '0') * 10 + (current[4] - '0');
        int tHour = (correct[0] - '0') * 10 + (correct[1] - '0'), tMinute = (correct[3] - '0') * 10 + (correct[4] - '0');
        int opers = 0;

        if (tMinute >= cMinute) {
            opers = tHour - cHour;
        }
        else {
            opers = tHour - cHour - 1;
            tMinute += 60;
        }

        tMinute -= cMinute;
        opers += (tMinute / 15);
        tMinute %= 15;
        opers += (tMinute / 5);
        tMinute %= 5;

        return opers + tMinute;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.convertTime("02:30", "04:35"));
    check.checkInt(1, o.convertTime("11:00", "11:01"));
    check.checkInt(2, o.convertTime("11:59", "12:01"));
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
