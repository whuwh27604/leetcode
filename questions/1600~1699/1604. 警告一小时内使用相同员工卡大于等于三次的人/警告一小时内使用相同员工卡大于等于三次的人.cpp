/* 警告一小时内使用相同员工卡大于等于三次的人.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
力扣公司的员工都使用员工卡来开办公室的门。每当一个员工使用一次他的员工卡，安保系统会记录下员工的名字和使用时间。如果一个员工在一小时时间内使用员工卡的次数大于等于三次，这个系统会自动发布一个 警告 。

给你字符串数组 keyName 和 keyTime ，其中 [keyName[i], keyTime[i]] 对应一个人的名字和他在 某一天 内使用员工卡的时间。

使用时间的格式是 24小时制 ，形如 "HH:MM" ，比方说 "23:51" 和 "09:49" 。

请你返回去重后的收到系统警告的员工名字，将它们按 字典序升序 排序后返回。

请注意 "10:00" - "11:00" 视为一个小时时间范围内，而 "23:51" - "00:10" 不被视为一小时内，因为系统记录的是某一天内的使用情况。

 

示例 1：

输入：keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"], keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
输出：["daniel"]
解释："daniel" 在一小时内使用了 3 次员工卡（"10:00"，"10:40"，"11:00"）。
示例 2：

输入：keyName = ["alice","alice","alice","bob","bob","bob","bob"], keyTime = ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
输出：["bob"]
解释："bob" 在一小时内使用了 3 次员工卡（"21:00"，"21:20"，"21:30"）。
示例 3：

输入：keyName = ["john","john","john"], keyTime = ["23:58","23:59","00:01"]
输出：[]
示例 4：

输入：keyName = ["leslie","leslie","leslie","clare","clare","clare","clare"], keyTime = ["13:00","13:20","14:00","18:00","18:51","19:30","19:49"]
输出：["clare","leslie"]
 

提示：

1 <= keyName.length, keyTime.length <= 105
keyName.length == keyTime.length
keyTime 格式为 "HH:MM" 。
保证 [keyName[i], keyTime[i]] 形成的二元对 互不相同 。
1 <= keyName[i].length <= 10
keyName[i] 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> nameTimes;
        vector<string> alerted;

        classifyTimesByName(keyName, keyTime, nameTimes);

        for (auto iter = nameTimes.begin(); iter != nameTimes.end(); ++iter) {
            if (checkIfAlert(iter->second)) {
                alerted.push_back(iter->first);
            }
        }

        sort(alerted.begin(), alerted.end());

        return alerted;
    }

    void classifyTimesByName(vector<string>& keyName, vector<string>& keyTime, unordered_map<string, vector<int>>& nameTimes) {
        int i, size = keyName.size();

        for (i = 0; i < size; ++i) {
            string& time = keyTime[i];
            nameTimes[keyName[i]].push_back((time[0] * 10 + time[1]) * 60 + (time[3] * 10 + time[4]));
        }
    }

    bool checkIfAlert(vector<int>& times) {
        sort(times.begin(), times.end());

        for (int i = 2; i < (int)times.size(); ++i) {
            if (times[i] - times[i - 2] <= 60) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> keyName = { "daniel","daniel","daniel","luis","luis","luis","luis" };
    vector<string> keyTime = { "10:00","10:40","11:00","09:00","11:00","13:00","15:00" };
    vector<string> actual = o.alertNames(keyName, keyTime);
    vector<string> expected = { "daniel" };
    check.checkStringVector(expected, actual);

    keyName = { "alice","alice","alice","bob","bob","bob","bob" };
    keyTime = { "12:01","12:00","18:00","21:00","21:20","21:30","23:00" };
    actual = o.alertNames(keyName, keyTime);
    expected = { "bob" };
    check.checkStringVector(expected, actual);

    keyName = { "john","john","john" };
    keyTime = { "23:58","23:59","00:01" };
    actual = o.alertNames(keyName, keyTime);
    expected = {  };
    check.checkStringVector(expected, actual);

    keyName = { "leslie","leslie","leslie","clare","clare","clare","clare" };
    keyTime = { "13:00","13:20","14:00","18:00","18:51","19:30","19:49" };
    actual = o.alertNames(keyName, keyTime);
    expected = { "clare","leslie" };
    check.checkStringVector(expected, actual);

    keyName = { "john","john","john" };
    keyTime = { "01:00","00:30","00:00" };
    actual = o.alertNames(keyName, keyTime);
    expected = { "john" };
    check.checkStringVector(expected, actual);

    keyName = { "john","john","john" };
    keyTime = { "00:00","00:30","01:00" };
    actual = o.alertNames(keyName, keyTime);
    expected = { "john" };
    check.checkStringVector(expected, actual);

    keyName = { "john","john","john" };
    keyTime = { "01:00","00:30","24:00" };
    actual = o.alertNames(keyName, keyTime);
    expected = {  };
    check.checkStringVector(expected, actual);

    keyName = { "john" };
    keyTime = { "01:00" };
    actual = o.alertNames(keyName, keyTime);
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
