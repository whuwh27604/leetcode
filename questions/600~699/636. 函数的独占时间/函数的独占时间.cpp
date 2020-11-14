/* 函数的独占时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出一个非抢占单线程CPU的 n 个函数运行日志，找到函数的独占时间。

每个函数都有一个唯一的 Id，从 0 到 n-1，函数可能会递归调用或者被其他函数调用。

日志是具有以下格式的字符串：function_id：start_or_end：timestamp。例如："0:start:0" 表示函数 0 从 0 时刻开始运行。"0:end:0" 表示函数 0 在 0 时刻结束。

函数的独占时间定义是在该方法中花费的时间，调用其他函数花费的时间不算该函数的独占时间。你需要根据函数的 Id 有序地返回每个函数的独占时间。

示例 1:

输入:
n = 2
logs =
["0:start:0",
 "1:start:2",
 "1:end:5",
 "0:end:6"]
输出:[3, 4]
说明：
函数 0 在时刻 0 开始，在执行了  2个时间单位结束于时刻 1。
现在函数 0 调用函数 1，函数 1 在时刻 2 开始，执行 4 个时间单位后结束于时刻 5。
函数 0 再次在时刻 6 开始执行，并在时刻 6 结束运行，从而执行了 1 个时间单位。
所以函数 0 总共的执行了 2 +1 =3 个时间单位，函数 1 总共执行了 4 个时间单位。
说明：

输入的日志会根据时间戳排序，而不是根据日志Id排序。
你的输出会根据函数Id排序，也就意味着你的输出数组中序号为 0 的元素相当于函数 0 的执行时间。
两个函数不会在同时开始或结束。
函数允许被递归调用，直到运行结束。
1 <= n <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/exclusive-time-of-functions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

const int TIME_START = 0;
const int TIME_END = 1;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> ids;  // 栈顶元素始终保持当前时间应该记在谁头上
        int id, type, timeStamp, prevTimeStamp = 0;
        vector<int> times(n, 0);

        for (string& log : logs) {
            parseLog(log, id, type, timeStamp);

            if (type == TIME_START) {
                if (!ids.empty()) {
                    times[ids.top()] += (timeStamp - prevTimeStamp);
                }

                ids.push(id);
            }
            else {
                times[ids.top()] += (timeStamp - prevTimeStamp);
                ids.pop();
            }

            prevTimeStamp = timeStamp;
        }

        return times;
    }

    void parseLog(string& log, int& id, int& type, int& timeStamp) {
        int index = 0, size = log.size();

        id = 0;
        while (log[index] != ':') {
            id = id * 10 + log[index++] - '0';
        }

        if (log[++index] == 's') {
            type = TIME_START;
            index += 6;
        }
        else {
            type = TIME_END;
            index += 4;
        }

        timeStamp = 0;
        while (index < size) {
            timeStamp = timeStamp * 10 + log[index++] - '0';
        }

        if (type == TIME_END) {
            timeStamp++;  // end_time=5时，其实是说第5秒还在运行，到第5秒末也就是第6秒初才结束，所以给它加1
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> logs = { "0:start:0","1:start:2","1:end:5","0:end:6" };
    vector<int> actual = o.exclusiveTime(2, logs);
    vector<int> expected = { 3,4 };
    check.checkIntVector(expected, actual);

    logs = { "0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7" };
    actual = o.exclusiveTime(1, logs);
    expected = { 8 };
    check.checkIntVector(expected, actual);

    logs = { "0:start:0","0:start:2","0:end:5","1:start:7","1:end:7","0:end:8" };
    actual = o.exclusiveTime(2, logs);
    expected = { 8,1 };
    check.checkIntVector(expected, actual);

    logs = { "0:start:0","1:start:1","2:start:2","3:start:3","3:end:5","2:end:6","1:end:7","1:start:8","2:start:9","3:start:10",
        "3:end:13","2:end:14","1:end:15","1:start:16","2:start:17","2:end:18","1:end:19","0:end:20" };
    actual = o.exclusiveTime(4, logs);
    expected = { 2,6,6,7 };
    check.checkIntVector(expected, actual);

    logs = { "0:start:0","0:end:0","1:start:1","1:end:2","2:start:3","2:end:5" };
    actual = o.exclusiveTime(3, logs);
    expected = { 1,2,3 };
    check.checkIntVector(expected, actual);
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
