/* 通知所有员工所需的时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
公司里有 n 名员工，每个员工的 ID 都是独一无二的，编号从 0 到 n - 1。公司的总负责人通过 headID 进行标识。

在 manager 数组中，每个员工都有一个直属负责人，其中 manager[i] 是第 i 名员工的直属负责人。对于总负责人，manager[headID] = -1。题目保证从属关系可以用树结构显示。

公司总负责人想要向公司所有员工通告一条紧急消息。他将会首先通知他的直属下属们，然后由这些下属通知他们的下属，直到所有的员工都得知这条紧急消息。

第 i 名员工需要 informTime[i] 分钟来通知它的所有直属下属（也就是说在 informTime[i] 分钟后，他的所有直属下属都可以开始传播这一消息）。

返回通知所有员工这一紧急消息所需要的 分钟数 。

 

示例 1：

输入：n = 1, headID = 0, manager = [-1], informTime = [0]
输出：0
解释：公司总负责人是该公司的唯一一名员工。
示例 2：



输入：n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
输出：1
解释：id = 2 的员工是公司的总负责人，也是其他所有员工的直属负责人，他需要 1 分钟来通知所有员工。
上图显示了公司员工的树结构。
示例 3：



输入：n = 7, headID = 6, manager = [1,2,3,4,5,6,-1], informTime = [0,6,5,4,3,2,1]
输出：21
解释：总负责人 id = 6。他将在 1 分钟内通知 id = 5 的员工。
id = 5 的员工将在 2 分钟内通知 id = 4 的员工。
id = 4 的员工将在 3 分钟内通知 id = 3 的员工。
id = 3 的员工将在 4 分钟内通知 id = 2 的员工。
id = 2 的员工将在 5 分钟内通知 id = 1 的员工。
id = 1 的员工将在 6 分钟内通知 id = 0 的员工。
所需时间 = 1 + 2 + 3 + 4 + 5 + 6 = 21 。
示例 4：

输入：n = 15, headID = 0, manager = [-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6], informTime = [1,1,1,1,1,1,1,0,0,0,0,0,0,0,0]
输出：3
解释：第一分钟总负责人通知员工 1 和 2 。
第二分钟他们将会通知员工 3, 4, 5 和 6 。
第三分钟他们将会通知剩下的员工。
示例 5：

输入：n = 4, headID = 2, manager = [3,3,-1,2], informTime = [0,0,162,914]
输出：1076
 

提示：

1 <= n <= 10^5
0 <= headID < n
manager.length == n
0 <= manager[i] < n
manager[headID] == -1
informTime.length == n
0 <= informTime[i] <= 1000
如果员工 i 没有下属，informTime[i] == 0 。
题目 保证 所有员工都可以收到通知。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/time-needed-to-inform-all-employees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> subordinates(n, vector<int>{});
        getSubordinates(n, manager, subordinates);

        queue<pair<int, int>> bfs;
        bfs.push({ headID, 0 });

        int maxMinutes = 0;

        while (!bfs.empty()) {
            int directManager = bfs.front().first;
            int minutes = bfs.front().second;
            bfs.pop();

            maxMinutes = max(maxMinutes, minutes);
            minutes += informTime[directManager];

            for (int subordinate : subordinates[directManager]) {
                bfs.push({ subordinate, minutes });
            }
        }

        return maxMinutes;
    }

    void getSubordinates(int n, vector<int>& manager, vector<vector<int>>& subordinates) {
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                subordinates[manager[i]].push_back(i);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> manager = { -1 };
    vector<int> informTime = { 0 };
    check.checkInt(0, o.numOfMinutes(1, 0, manager, informTime));

    manager = { 2,2,-1,2,2,2 };
    informTime = { 0,0,1,0,0,0 };
    check.checkInt(1, o.numOfMinutes(6, 2, manager, informTime));

    manager = { 1,2,3,4,5,6,-1 };
    informTime = { 0,6,5,4,3,2,1 };
    check.checkInt(21, o.numOfMinutes(7, 6, manager, informTime));

    manager = { -1,0,0,1,1,2,2,3,3,4,4,5,5,6,6 };
    informTime = { 1,1,1,1,1,1,1,0,0,0,0,0,0,0,0 };
    check.checkInt(3, o.numOfMinutes(15, 0, manager, informTime));

    manager = { 3,3,-1,2 };
    informTime = { 0,0,162,914 };
    check.checkInt(1076, o.numOfMinutes(4, 2, manager, informTime));
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
