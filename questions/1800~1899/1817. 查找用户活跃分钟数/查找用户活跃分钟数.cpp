/* 查找用户活跃分钟数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你用户在 LeetCode 的操作日志，和一个整数 k 。日志用一个二维整数数组 logs 表示，其中每个 logs[i] = [IDi, timei] 表示 ID 为 IDi 的用户在 timei 分钟时执行了某个操作。

多个用户 可以同时执行操作，单个用户可以在同一分钟内执行 多个操作 。

指定用户的 用户活跃分钟数（user active minutes，UAM） 定义为用户对 LeetCode 执行操作的 唯一分钟数 。 即使一分钟内执行多个操作，也只能按一分钟计数。

请你统计用户活跃分钟数的分布情况，统计结果是一个长度为 k 且 下标从 1 开始计数 的数组 answer ，对于每个 j（1 <= j <= k），answer[j] 表示 用户活跃分钟数 等于 j 的用户数。

返回上面描述的答案数组 answer 。

 

示例 1：

输入：logs = [[0,5],[1,2],[0,2],[0,5],[1,3]], k = 5
输出：[0,2,0,0,0]
解释：
ID=0 的用户执行操作的分钟分别是：5 、2 和 5 。因此，该用户的用户活跃分钟数为 2（分钟 5 只计数一次）
ID=1 的用户执行操作的分钟分别是：2 和 3 。因此，该用户的用户活跃分钟数为 2
2 个用户的用户活跃分钟数都是 2 ，answer[2] 为 2 ，其余 answer[j] 的值都是 0
示例 2：

输入：logs = [[1,1],[2,2],[2,3]], k = 4
输出：[1,1,0,0]
解释：
ID=1 的用户仅在分钟 1 执行单个操作。因此，该用户的用户活跃分钟数为 1
ID=2 的用户执行操作的分钟分别是：2 和 3 。因此，该用户的用户活跃分钟数为 2
1 个用户的用户活跃分钟数是 1 ，1 个用户的用户活跃分钟数是 2
因此，answer[1] = 1 ，answer[2] = 1 ，其余的值都是 0
 

提示：

1 <= logs.length <= 104
0 <= IDi <= 109
1 <= timei <= 105
k 的取值范围是 [用户的最大用户活跃分钟数, 105]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/finding-the-users-active-minutes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> idTimeSet;
        vector<int> ans(k, 0);

        for (auto& log : logs) {
            idTimeSet[log[0]].insert(log[1]);
        }

        for (auto iter = idTimeSet.begin(); iter != idTimeSet.end(); ++iter) {
            ++ans[iter->second.size() - 1];
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> logs = { {0,5},{1,2},{0,2},{0,5},{1,3} };
    vector<int> actual = o.findingUsersActiveMinutes(logs, 5);
    vector<int> expected = { 0,2,0,0,0 };
    check.checkIntVector(expected, actual);

    logs = { {1,1},{2,2},{2,3} };
    actual = o.findingUsersActiveMinutes(logs, 4);
    expected = { 1,1,0,0 };
    check.checkIntVector(expected, actual);

    logs = { {0,100000} };
    actual = o.findingUsersActiveMinutes(logs, 1);
    expected = { 1 };
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
