/* 高访问员工.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 、下标从 0 开始的二维字符串数组 access_times 。对于每个 i（0 <= i <= n - 1 ），access_times[i][0] 表示某位员工的姓名，access_times[i][1] 表示该员工的访问时间。access_times 中的所有条目都发生在同一天内。

访问时间用 四位 数字表示， 符合 24 小时制 ，例如 "0800" 或 "2250" 。

如果员工在 同一小时内 访问系统 三次或更多 ，则称其为 高访问 员工。

时间间隔正好相差一小时的时间 不 被视为同一小时内。例如，"0815" 和 "0915" 不属于同一小时内。

一天开始和结束时的访问时间不被计算为同一小时内。例如，"0005" 和 "2350" 不属于同一小时内。

以列表形式，按任意顺序，返回所有 高访问 员工的姓名。



示例 1：

输入：access_times = [["a","0549"],["b","0457"],["a","0532"],["a","0621"],["b","0540"]]
输出：["a"]
解释："a" 在时间段 [05:32, 06:31] 内有三条访问记录，时间分别为 05:32 、05:49 和 06:21 。
但是 "b" 的访问记录只有两条。
因此，答案是 ["a"] 。
示例 2：

输入：access_times = [["d","0002"],["c","0808"],["c","0829"],["e","0215"],["d","1508"],["d","1444"],["d","1410"],["c","0809"]]
输出：["c","d"]
解释："c" 在时间段 [08:08, 09:07] 内有三条访问记录，时间分别为 08:08 、08:09 和 08:29 。
"d" 在时间段 [14:10, 15:09] 内有三条访问记录，时间分别为 14:10 、14:44 和 15:08 。
然而，"e" 只有一条访问记录，因此不能包含在答案中，最终答案是 ["c","d"] 。
示例 3：

输入：access_times = [["cd","1025"],["ab","1025"],["cd","1046"],["cd","1055"],["ab","1124"],["ab","1120"]]
输出：["ab","cd"]
解释："ab"在时间段 [10:25, 11:24] 内有三条访问记录，时间分别为 10:25 、11:20 和 11:24 。
"cd" 在时间段 [10:25, 11:24] 内有三条访问记录，时间分别为 10:25 、10:46 和 10:55 。
因此，答案是 ["ab","cd"] 。


提示：

1 <= access_times.length <= 100
access_times[i].length == 2
1 <= access_times[i][0].length <= 10
access_times[i][0] 仅由小写英文字母组成。
access_times[i][1].length == 4
access_times[i][1] 采用24小时制表示时间。
access_times[i][1] 仅由数字 '0' 到 '9' 组成。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> employeeTimes;
        vector<string> ans;

        for (auto& times : access_times) {
            string& employee = times[0];
            string& time = times[1];
            employeeTimes[employee].push_back((time[0] * 10 + time[1]) * 60 + time[2] * 10 + time[3]);
        }

        for (auto& kv : employeeTimes) {
            auto& times = kv.second;
            sort(times.begin(), times.end());
            int size = times.size();

            for (int i = 0; i < size - 2; ++i) {
                if (times[i + 2] - times[i] < 60) {
                    ans.push_back(kv.first);
                    break;
                }
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<string>> access_times = {{"a","0549"},{"b","0457"},{"a","0532"},{"a","0621"},{"b","0540"}};
    vector<string> actual = o.findHighAccessEmployees(access_times);
    vector<string> expected = { "a" };
    check.checkStringVectorRandomOrder(expected,actual);

    access_times = {{"d","0002"},{"c","0808"},{"c","0829"},{"e","0215"},{"d","1508"},{"d","1444"},{"d","1410"},{"c","0809"}};
    actual = o.findHighAccessEmployees(access_times);
    expected = { "c","d" };
    check.checkStringVectorRandomOrder(expected,actual);

    access_times = {{"cd","1025"},{"ab","1025"},{"cd","1046"},{"cd","1055"},{"ab","1124"},{"ab","1120"}};
    actual = o.findHighAccessEmployees(access_times);
    expected = { "ab","cd" };
    check.checkStringVectorRandomOrder(expected, actual);
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
