/* 找到处理最多请求的服务器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有 k 个服务器，编号为 0 到 k-1 ，它们可以同时处理多个请求组。每个服务器有无穷的计算能力但是 不能同时处理超过一个请求 。请求分配到服务器的规则如下：

第 i （序号从 0 开始）个请求到达。
如果所有服务器都已被占据，那么该请求被舍弃（完全不处理）。
如果第 (i % k) 个服务器空闲，那么对应服务器会处理该请求。
否则，将请求安排给下一个空闲的服务器（服务器构成一个环，必要的话可能从第 0 个服务器开始继续找下一个空闲的服务器）。比方说，如果第 i 个服务器在忙，那么会查看第 (i+1) 个服务器，第 (i+2) 个服务器等等。
给你一个 严格递增 的正整数数组 arrival ，表示第 i 个任务的到达时间，和另一个数组 load ，其中 load[i] 表示第 i 个请求的工作量（也就是服务器完成它所需要的时间）。你的任务是找到 最繁忙的服务器 。最繁忙定义为一个服务器处理的请求数是所有服务器里最多的。

请你返回包含所有 最繁忙服务器 序号的列表，你可以以任意顺序返回这个列表。

 

示例 1：



输入：k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3]
输出：[1]
解释：
所有服务器一开始都是空闲的。
前 3 个请求分别由前 3 台服务器依次处理。
请求 3 进来的时候，服务器 0 被占据，所以它呗安排到下一台空闲的服务器，也就是服务器 1 。
请求 4 进来的时候，由于所有服务器都被占据，该请求被舍弃。
服务器 0 和 2 分别都处理了一个请求，服务器 1 处理了两个请求。所以服务器 1 是最忙的服务器。
示例 2：

输入：k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
输出：[0]
解释：
前 3 个请求分别被前 3 个服务器处理。
请求 3 进来，由于服务器 0 空闲，它被服务器 0 处理。
服务器 0 处理了两个请求，服务器 1 和 2 分别处理了一个请求。所以服务器 0 是最忙的服务器。
示例 3：

输入：k = 3, arrival = [1,2,3], load = [10,12,11]
输出：[0,1,2]
解释：每个服务器分别处理了一个请求，所以它们都是最忙的服务器。
示例 4：

输入：k = 3, arrival = [1,2,3,4,8,9,10], load = [5,2,10,3,1,2,2]
输出：[1]
示例 5：

输入：k = 1, arrival = [1], load = [1]
输出：[0]
 

提示：

1 <= k <= 105
1 <= arrival.length, load.length <= 105
arrival.length == load.length
1 <= arrival[i], load[i] <= 109
arrival 保证 严格递增 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-servers-that-handled-most-number-of-requests
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class RunningServer {
public:
    long long endTime;
    int id;

    RunningServer() : endTime(0), id(0) {}
    RunningServer(long long time_, int id_) : endTime(time_), id(id_) {}

    bool operator<(const RunningServer& s) const {
        return endTime == s.endTime ? id < s.id : endTime < s.endTime;
    }
};

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> idles;
        set<RunningServer> runnings;
        vector<int> assigned(k, 0);

        init(idles, k);
        processRequests(k, arrival, load, idles, runnings, assigned);

        return getBusiestServers(assigned, k);
    }

    void init(set<int>& idles, int k) {
        for (int i = 0; i < k; ++i) {
            idles.insert(i);
        }
    }

    void processRequests(int k, vector<int>& arrival, vector<int>& load, set<int>& idles, set<RunningServer>& runnings, vector<int>& assigned) {
        for (int i = 0; i < (int)load.size(); ++i) {
            while (!runnings.empty() && (*runnings.begin()).endTime < arrival[i]) {
                idles.insert((*runnings.begin()).id);
                runnings.erase(runnings.begin());
            }

            if (idles.empty()) {  // 所有服务器都已被占据，该请求被舍弃
                continue;
            }

            auto iter = idles.lower_bound(i % k);  // 往后找第一个空闲的
            if (iter == idles.end()) {
                iter = idles.begin();  // 后面没有，那就取前面第一个
            }

            ++assigned[*iter];
            runnings.insert(RunningServer((long long)arrival[i] + load[i] - 1, *iter));
            idles.erase(iter);
        }
    }

    vector<int> getBusiestServers(vector<int>& assigned, int k) {
        vector<int> busiests;
        int maxTimes = 0;

        for (int i = 0; i < k; ++i) {
            if (assigned[i] > maxTimes) {
                maxTimes = assigned[i];
                busiests = { i };
            }
            else if (assigned[i] == maxTimes) {
                busiests.push_back(i);
            }
        }

        return busiests;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arrival = { 1,2,3,4,5 };
    vector<int> load = { 5,2,3,3,3 };
    vector<int> actual = o.busiestServers(3, arrival, load);
    vector<int> expected = { 1 };
    check.checkIntVector(expected, actual);

    arrival = { 1,2,3,4 };
    load = { 1,2,1,2 };
    actual = o.busiestServers(3, arrival, load);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    arrival = { 1,2,3 };
    load = { 10,12,11 };
    actual = o.busiestServers(3, arrival, load);
    expected = { 0,1,2 };
    check.checkIntVector(expected, actual);

    arrival = { 1,2,3,4,8,9,10 };
    load = { 5,2,10,3,1,2,2 };
    actual = o.busiestServers(3, arrival, load);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    arrival = { 1 };
    load = { 1 };
    actual = o.busiestServers(1, arrival, load);
    expected = { 0 };
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
