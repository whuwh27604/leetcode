/* 给定数字能组成的最大时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个由 4 位数字组成的数组，返回可以设置的符合 24 小时制的最大时间。

最小的 24 小时制时间是 00:00，而最大的是 23:59。从 00:00 （午夜）开始算起，过得越久，时间越大。

以长度为 5 的字符串返回答案。如果不能确定有效时间，则返回空字符串。

 

示例 1：

输入：[1,2,3,4]
输出："23:41"
示例 2：

输入：[5,5,5,5]
输出：""
 

提示：

A.length == 4
0 <= A[i] <= 9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-time-for-given-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int time[4], maxTime[4] = { -1,-1,-1,-1 };

        for (int a = 0; a < 4; a++) {
            for (int b = 0; b < 4; b++) {
                if (b == a) {
                    continue;
                }

                for (int c = 0; c < 4; c++) {
                    if ((c == a) || (c == b)) {
                        continue;
                    }

                    for (int d = 0; d < 4; d++) {
                        if ((d == a) || (d == b) || (d == c)) {
                            continue;
                        }

                        time[0] = A[a];
                        time[1] = A[b];
                        time[2] = A[c];
                        time[3] = A[d];
                        if (isTimeValid(time)) {
                            getMaxTime(time, maxTime);
                        }
                    }
                }
            }
        }

        if (maxTime[0] == -1) {
            return "";
        }
        return to_string(maxTime[0]) + to_string(maxTime[1]) + ":" + to_string(maxTime[2]) + to_string(maxTime[3]);
    }

    bool isTimeValid(int* time) {
        int hour = (time[0] * 10 + time[1]);
        int minute = (time[2] * 10 + time[3]);
        return ((hour < 24) && (minute < 60));
    }

    void getMaxTime(int* time, int* maxTime) {
        int time1 = (time[0] * 10 + time[1]) * 60 + time[2] * 10 + time[3];
        int time2 = (maxTime[0] * 10 + maxTime[1]) * 60 + maxTime[2] * 10 + maxTime[3];
        if (time1 > time2) {
            maxTime[0] = time[0];
            maxTime[1] = time[1];
            maxTime[2] = time[2];
            maxTime[3] = time[3];
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 1,2,3,4 };
    string expected = "23:41";
    check.checkString(expected, o.largestTimeFromDigits(A));

    A = { 5,5,5,5 };
    expected = "";
    check.checkString(expected, o.largestTimeFromDigits(A));

    A = { 9,5,3,2 };
    expected = "23:59";
    check.checkString(expected, o.largestTimeFromDigits(A));

    A = { 0,0,0,0 };
    expected = "00:00";
    check.checkString(expected, o.largestTimeFromDigits(A));

    A = { 0,0,0,1 };
    expected = "10:00";
    check.checkString(expected, o.largestTimeFromDigits(A));
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
