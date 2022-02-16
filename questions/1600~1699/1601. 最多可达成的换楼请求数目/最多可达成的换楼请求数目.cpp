﻿/* 最多可达成的换楼请求数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们有 n 栋楼，编号从 0 到 n - 1 。每栋楼有若干员工。由于现在是换楼的季节，部分员工想要换一栋楼居住。

给你一个数组 requests ，其中 requests[i] = [fromi, toi] ，表示一个员工请求从编号为 fromi 的楼搬到编号为 toi 的楼。

一开始 所有楼都是满的，所以从请求列表中选出的若干个请求是可行的需要满足 每栋楼员工净变化为 0 。意思是每栋楼 离开 的员工数目 等于 该楼 搬入 的员工数数目。比方说 n = 3 且两个员工要离开楼 0 ，一个员工要离开楼 1 ，一个员工要离开楼 2 ，如果该请求列表可行，应该要有两个员工搬入楼 0 ，一个员工搬入楼 1 ，一个员工搬入楼 2 。

请你从原请求列表中选出若干个请求，使得它们是一个可行的请求列表，并返回所有可行列表中最大请求数目。

 

示例 1：



输入：n = 5, requests = [[0,1],[1,0],[0,1],[1,2],[2,0],[3,4]]
输出：5
解释：请求列表如下：
从楼 0 离开的员工为 x 和 y ，且他们都想要搬到楼 1 。
从楼 1 离开的员工为 a 和 b ，且他们分别想要搬到楼 2 和 0 。
从楼 2 离开的员工为 z ，且他想要搬到楼 0 。
从楼 3 离开的员工为 c ，且他想要搬到楼 4 。
没有员工从楼 4 离开。
我们可以让 x 和 b 交换他们的楼，以满足他们的请求。
我们可以让 y，a 和 z 三人在三栋楼间交换位置，满足他们的要求。
所以最多可以满足 5 个请求。
示例 2：



输入：n = 3, requests = [[0,0],[1,2],[2,1]]
输出：3
解释：请求列表如下：
从楼 0 离开的员工为 x ，且他想要回到原来的楼 0 。
从楼 1 离开的员工为 y ，且他想要搬到楼 2 。
从楼 2 离开的员工为 z ，且他想要搬到楼 1 。
我们可以满足所有的请求。
示例 3：

输入：n = 4, requests = [[0,3],[3,1],[1,2],[2,0]]
输出：4
 

提示：

1 <= n <= 20
1 <= requests.length <= 16
requests[i].length == 2
0 <= fromi, toi < n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-achievable-transfer-requests
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int mask, size = requests.size(), maxMask = (1 << size), maxReqs = 0;

        for (mask = 1; mask < maxMask; ++mask) {
            int reqs = 0;

            if (check(n, requests, mask, reqs)) {
                maxReqs = max(maxReqs, reqs);
            }
        }

        return maxReqs;
    }

    bool check(int n, vector<vector<int>>& requests, int mask, int& reqs) {
        int i, bit, size = requests.size();
        vector<int> employees(n, 0);

        for (i = 0, bit = 1; i < size; ++i, bit <<= 1) {
            if ((bit & mask) != 0) {
                --employees[requests[i][0]];
                ++employees[requests[i][1]];
                ++reqs;
            }
        }

        for (i = 0; i < n; ++i) {
            if (employees[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> requests = { {0,1},{1,0},{0,1},{1,2},{2,0},{3,4} };
    check.checkInt(5, o.maximumRequests(5, requests));

    requests = { {0,0},{1,2},{2,1} };
    check.checkInt(3, o.maximumRequests(3, requests));

    requests = { {0,3},{3,1},{1,2},{2,0} };
    check.checkInt(4, o.maximumRequests(4, requests));

    requests = { {1,2},{0,0},{0,2},{0,1},{0,0},{0,2},{1,0},{0,1},{2,0} };
    check.checkInt(7, o.maximumRequests(3, requests));

    requests = { {0,0} };
    check.checkInt(1, o.maximumRequests(1, requests));

    requests = { {0,0},{0,0},{0,0} };
    check.checkInt(3, o.maximumRequests(1, requests));
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
