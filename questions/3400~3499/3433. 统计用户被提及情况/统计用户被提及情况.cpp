/* 统计用户被提及情况.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 numberOfUsers 表示用户总数，另有一个大小为 n x 3 的数组 events 。

每个 events[i] 都属于下述两种类型之一：

消息事件（Message Event）：["MESSAGE", "timestampi", "mentions_stringi"]
事件表示在 timestampi 时，一组用户被消息提及。
mentions_stringi 字符串包含下述标识符之一：
id<number>：其中 <number> 是一个区间 [0,numberOfUsers - 1] 内的整数。可以用单个空格分隔 多个 id ，并且 id 可能重复。此外，这种形式可以提及离线用户。
ALL：提及 所有 用户。
HERE：提及所有 在线 用户。
离线事件（Offline Event）：["OFFLINE", "timestampi", "idi"]
事件表示用户 idi 在 timestampi 时变为离线状态 60 个单位时间。用户会在 timestampi + 60 时自动再次上线。
返回数组 mentions ，其中 mentions[i] 表示  id 为  i 的用户在所有 MESSAGE 事件中被提及的次数。

最初所有用户都处于在线状态，并且如果某个用户离线或者重新上线，其对应的状态变更将会在所有相同时间发生的消息事件之前进行处理和同步。

注意 在单条消息中，同一个用户可能会被提及多次。每次提及都需要被 分别 统计。



示例 1：

输入：numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","71","HERE"]]

输出：[2,2]

解释：

最初，所有用户都在线。

时间戳 10 ，id1 和 id0 被提及，mentions = [1,1]

时间戳 11 ，id0 离线 。

时间戳 71 ，id0 再次 上线 并且 "HERE" 被提及，mentions = [2,2]

示例 2：

输入：numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","12","ALL"]]

输出：[2,2]

解释：

最初，所有用户都在线。

时间戳 10 ，id1 和 id0 被提及，mentions = [1,1]

时间戳 11 ，id0 离线 。

时间戳 12 ，"ALL" 被提及。这种方式将会包括所有离线用户，所以 id0 和 id1 都被提及，mentions = [2,2]

示例 3：

输入：numberOfUsers = 2, events = [["OFFLINE","10","0"],["MESSAGE","12","HERE"]]

输出：[0,1]

解释：

最初，所有用户都在线。

时间戳 10 ，id0 离线 。

时间戳 12 ，"HERE" 被提及。由于 id0 仍处于离线状态，其将不会被提及，mentions = [0,1]



提示：

1 <= numberOfUsers <= 100
1 <= events.length <= 100
events[i].length == 3
events[i][0] 的值为 MESSAGE 或 OFFLINE 。
1 <= int(events[i][1]) <= 105
在任意 "MESSAGE" 事件中，以 id<number> 形式提及的用户数目介于 1 和 100 之间。
0 <= <number> <= numberOfUsers - 1
题目保证 OFFLINE 引用的用户 id 在事件发生时处于 在线 状态。
*/

#include <iostream>
#include <algorithm>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

const int MESSAGE_TYPE_OFFLINE = 0;
const int MESSAGE_TYPE_MESS = 1;
const int ID_TYPE_ALL = 0;
const int ID_TYPE_HERE = 1;
const int ID_TYPE_MENTION = 2;

class Event {
public:
    int messageType;
    int time;
    int idType;
    vector<int> ids;

    Event() : messageType(MESSAGE_TYPE_OFFLINE), time(0), idType(ID_TYPE_ALL) {}

    bool operator<(const Event& e) const {
        return time == e.time ? messageType < e.messageType : time < e.time;  // time相等时优先处理offline消息
    }
};

class Offline {
public:
    int time;
    int id;

    Offline() : time(0), id(0) {}
    Offline(int t, int i) : time(t), id(i) {}

    bool operator<(const Offline& o) const {
        return time == o.time ? id < o.id : time < o.time;
    }
};

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<Event> evts;
        set<Offline> offs;
        vector<int> ans(numberOfUsers, 0);

        for (auto& evt : events) {
            evts.push_back(getEvent(evt));
        }

        sort(evts.begin(), evts.end());

        for (Event& evt : evts) {
            while (!offs.empty() && offs.begin()->time + 60 <= evt.time) {
                offs.erase(offs.begin());
            }

            if (evt.messageType == MESSAGE_TYPE_OFFLINE) {
                offs.insert(Offline(evt.time, evt.ids[0]));
            }
            else {
                if (evt.idType == ID_TYPE_MENTION) {
                    for (int id : evt.ids) {
                        ++ans[id];
                    }
                }
                else {
                    for (int id = 0; id < numberOfUsers; ++id) {
                        ++ans[id];
                    }

                    if (evt.idType == ID_TYPE_HERE) {
                        for (const Offline& off : offs) {
                            --ans[off.id];
                        }
                    }
                }
            }
        }

        return ans;
    }

    Event getEvent(vector<string>& event) {
        Event evt;

        if (event[0][0] == 'M') {
            evt.messageType = MESSAGE_TYPE_MESS;
            if (event[2][0] == 'A') {
                evt.idType = ID_TYPE_ALL;
            }
            else if (event[2][0] == 'H') {
                evt.idType = ID_TYPE_HERE;
            }
            else {
                evt.idType = ID_TYPE_MENTION;
                getIds(event[2], evt.ids);
            }
        }
        else {
            evt.ids.push_back(stoi(event[2]));
        }

        evt.time = stoi(event[1]);

        return evt;
    }

    void getIds(string& s, vector<int>& ids) {
        int size = (int)s.size(), start = 2, end = 3;

        while (start < size) {
            while (end < size && s[end] != ' ') {
                ++end;
            }

            ids.push_back(stoi(string(s, start, end - start)));
            start = end + 3;
            end = start + 1;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<string>> events = { {"MESSAGE","10","id1 id0"},{"OFFLINE","11","0"},{"MESSAGE","71","HERE"} };
    vector<int> actual = o.countMentions(2, events);
    vector<int> expected = { 2,2 };
    check.checkIntVector(expected, actual);

    events = { {"MESSAGE","10","id1 id0"},{"OFFLINE","11","0"},{"MESSAGE","12","ALL"} };
    actual = o.countMentions(2, events);
    expected = { 2,2 };
    check.checkIntVector(expected, actual);

    events = { {"OFFLINE","10","0"},{"MESSAGE","12","HERE"} };
    actual = o.countMentions(2, events);
    expected = { 0,1 };
    check.checkIntVector(expected, actual);

    events = { {"MESSAGE","1","id0 id1"},{"MESSAGE","5","id2"},{"MESSAGE","6","ALL"},{"OFFLINE","5","2"} };
    actual = o.countMentions(3, events);
    expected = { 2,2,2 };
    check.checkIntVector(expected, actual);

    events = { {"MESSAGE","2","HERE"},{"OFFLINE","2","1"},{"OFFLINE","1","0"},{"MESSAGE","61","HERE"} };
    actual = o.countMentions(3, events);
    expected = { 1,0,2 };
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
