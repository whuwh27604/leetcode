/* 参加会议的最多员工数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个公司准备组织一场会议，邀请名单上有 n 位员工。公司准备了一张 圆形 的桌子，可以坐下 任意数目 的员工。

员工编号为 0 到 n - 1 。每位员工都有一位 喜欢 的员工，每位员工 当且仅当 他被安排在喜欢员工的旁边，他才会参加会议。每位员工喜欢的员工 不会 是他自己。

给你一个下标从 0 开始的整数数组 favorite ，其中 favorite[i] 表示第 i 位员工喜欢的员工。请你返回参加会议的 最多员工数目 。

 

示例 1：



输入：favorite = [2,2,1,2]
输出：3
解释：
上图展示了公司邀请员工 0，1 和 2 参加会议以及他们在圆桌上的座位。
没办法邀请所有员工参与会议，因为员工 2 没办法同时坐在 0，1 和 3 员工的旁边。
注意，公司也可以邀请员工 1，2 和 3 参加会议。
所以最多参加会议的员工数目为 3 。
示例 2：

输入：favorite = [1,2,0]
输出：3
解释：
每个员工都至少是另一个员工喜欢的员工。所以公司邀请他们所有人参加会议的前提是所有人都参加了会议。
座位安排同图 1 所示：
- 员工 0 坐在员工 2 和 1 之间。
- 员工 1 坐在员工 0 和 2 之间。
- 员工 2 坐在员工 1 和 0 之间。
参与会议的最多员工数目为 3 。
示例 3：



输入：favorite = [3,0,1,4,1]
输出：4
解释：
上图展示了公司可以邀请员工 0，1，3 和 4 参加会议以及他们在圆桌上的座位。
员工 2 无法参加，因为他喜欢的员工 0 旁边的座位已经被占领了。
所以公司只能不邀请员工 2 。
参加会议的最多员工数目为 4 。
 

提示：

n == favorite.length
2 <= n <= 105
0 <= favorite[i] <= n - 1
favorite[i] != i

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-employees-to-be-invited-to-a-meeting
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int size = favorite.size();
        vector<int> inDegrees(size, 0);
        vector<int> maxDepth(size, 0);

        getInDegrees(favorite, inDegrees);
        topSort(favorite, inDegrees, maxDepth);

        return getMaxInvitations(favorite, inDegrees, maxDepth);
    }

    void getInDegrees(vector<int>& favorite, vector<int>& InDegrees) {
        for (int node : favorite) {
            ++InDegrees[node];
        }
    }

    void topSort(vector<int>& favorite, vector<int>& InDegrees, vector<int>& maxDepth) {
        queue<int> nodes;

        for (int i = 0; i < (int)InDegrees.size(); ++i) {
            if (InDegrees[i] == 0) {
                nodes.push(i);
            }
        }

        while (!nodes.empty()) {  // 拓扑排序，这里只处理了链上面的节点
            int node = nodes.front();
            nodes.pop();

            int next = favorite[node];
            if (--InDegrees[next] == 0) {
                nodes.push(next);
            }

            ++maxDepth[node];
            maxDepth[next] = max(maxDepth[next], maxDepth[node]);  // 链可能有多个分支，取深度最大的一个
        }
    }

    int getMaxInvitations(vector<int>& favorite, vector<int>& InDegrees, vector<int>& maxDepth) {
        int maxRingSize = 0, sumChainSize = 0, size = favorite.size();

        for (int node = 0; node < size; ++node) {
            if (InDegrees[node] == 0) {
                continue;  // 在拓扑排序后，所有链上的点入度为0，所有环上的点入度不为0
            }

            int ringSize = 1;

            for (int next = favorite[node]; next != node; next = favorite[next]) {
                ++ringSize;
                InDegrees[next] = 0;  // 避免外层循环再次访问这个环上的点
            }

            if (ringSize == 2) {  // 当环等于2时，除了环上2个人，还可以分别安排他们相连的最长的链。并且多个环带链可以同时安排。
                sumChainSize += (maxDepth[node] + maxDepth[favorite[node]] + 2);
            }
            else {  // 当环大于2时，只能安排环上的人，所以取最大的一个环
                maxRingSize = max(maxRingSize, ringSize);
            }
        }

        return max(maxRingSize, sumChainSize);  // 可以选择安排最大的一个环，或者安排所有大小为2的环带链。
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> favorite = { 2,2,1,2 };
    check.checkInt(3, o.maximumInvitations(favorite));

    favorite = { 1,2,0 };
    check.checkInt(3, o.maximumInvitations(favorite));

    favorite = { 3,0,1,4,1 };
    check.checkInt(4, o.maximumInvitations(favorite));

    favorite = { 3,2,4,0,1 };
    check.checkInt(3, o.maximumInvitations(favorite));

    favorite = { 1,2,3,4,0,6,5,5,9,8,8 };
    check.checkInt(6, o.maximumInvitations(favorite));
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
