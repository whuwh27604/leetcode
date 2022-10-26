/* 判断两个事件是否存在冲突.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串数组 event1 和 event2 ，表示发生在同一天的两个闭区间时间段事件，其中：

event1 = [startTime1, endTime1] 且
event2 = [startTime2, endTime2]
事件的时间为有效的 24 小时制且按 HH:MM 格式给出。

当两个事件存在某个非空的交集时（即，某些时刻是两个事件都包含的），则认为出现 冲突 。

如果两个事件之间存在冲突，返回 true ；否则，返回 false 。

 

示例 1：

输入：event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
输出：true
解释：两个事件在 2:00 出现交集。
示例 2：

输入：event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
输出：true
解释：两个事件的交集从 01:20 开始，到 02:00 结束。
示例 3：

输入：event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
输出：false
解释：两个事件不存在交集。
 

提示：

evnet1.length == event2.length == 2.
event1[i].length == event2[i].length == 5
startTime1 <= endTime1
startTime2 <= endTime2
所有事件的时间都按照 HH:MM 格式给出

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/determine-if-two-events-have-conflict
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int num1 = toNum(event1[0]), num2 = toNum(event1[1]), num3 = toNum(event2[0]), num4 = toNum(event2[1]);

        return !(num3 > num2 || num4 < num1);
    }

    int toNum(string& time) {
        return ((time[0] - '0') * 10 + (time[1] - '0')) * 60 + (time[3] - '0') * 10 + (time[4] - '0');
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> event1 = { "01:15","02:00" };
    vector<string> event2 = { "02:00","03:00" };
    check.checkBool(true, o.haveConflict(event1, event2));

    event1 = { "01:00","02:00" };
    event2 = { "01:20","03:00" };
    check.checkBool(true, o.haveConflict(event1, event2));

    event1 = { "15:19","17:56" };
    event2 = { "14:11","20:02" };
    check.checkBool(true, o.haveConflict(event1, event2));

    event1 = { "10:00","11:00" };
    event2 = { "14:00","15:00" };
    check.checkBool(false, o.haveConflict(event1, event2));
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
