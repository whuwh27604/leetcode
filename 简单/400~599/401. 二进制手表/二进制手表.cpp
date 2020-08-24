/* 二进制手表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
二进制手表顶部有 4 个 LED 代表小时（0-11），底部的 6 个 LED 代表分钟（0-59）。

每个 LED 代表一个 0 或 1，最低位在右侧。



例如，上面的二进制手表读取 “3:25”。

给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。

案例:

输入: n = 1
返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
 

注意事项:

输出的顺序没有要求。
小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-watch
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> allTimes;
        if (num >= 9) {
            return allTimes;
        }

        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                if (ledLightCount(hour, minute) == num) {
                    allTimes.push_back(time2String(hour, minute));
                }
            }
        }

        return allTimes;
    }

    int ledLightCount(int hour, int minute) {
        int hourLightNums[12] = { 0,1,1,2,1,2,2,3,1,2,2,3 };
        int minuteLightNums[60] = { 0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5 };
        return (hourLightNums[hour] + minuteLightNums[minute]);
    }

    string time2String(int hour, int minute) {
        char format[6] = { 0 };
        snprintf(format, 6, "%d:%02d", hour, minute);
        string time(format);
        return time;
    }
};

int main()
{
    Solution o;
    CheckResult check;
    
    vector<string> actual = o.readBinaryWatch(1);
    vector<string> expected = { "0:01", "0:02", "0:04", "0:08", "0:16", "0:32", "1:00", "2:00", "4:00", "8:00" };
    check.checkStringVector(expected, actual);

    actual = o.readBinaryWatch(0);
    expected = { "0:00" };
    check.checkStringVector(expected, actual);

    actual = o.readBinaryWatch(9);
    expected = {  };
    check.checkStringVector(expected, actual);
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
