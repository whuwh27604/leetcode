/* 同时运行 N 台电脑的最长时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有 n 台电脑。给你整数 n 和一个下标从 0 开始的整数数组 batteries ，其中第 i 个电池可以让一台电脑 运行 batteries[i] 分钟。你想使用这些电池让 全部 n 台电脑 同时 运行。

一开始，你可以给每台电脑连接 至多一个电池 。然后在任意整数时刻，你都可以将一台电脑与它的电池断开连接，并连接另一个电池，你可以进行这个操作 任意次 。新连接的电池可以是一个全新的电池，也可以是别的电脑用过的电池。断开连接和连接新的电池不会花费任何时间。

注意，你不能给电池充电。

请你返回你可以让 n 台电脑同时运行的 最长 分钟数。

 

示例 1：



输入：n = 2, batteries = [3,3,3]
输出：4
解释：
一开始，将第一台电脑与电池 0 连接，第二台电脑与电池 1 连接。
2 分钟后，将第二台电脑与电池 1 断开连接，并连接电池 2 。注意，电池 0 还可以供电 1 分钟。
在第 3 分钟结尾，你需要将第一台电脑与电池 0 断开连接，然后连接电池 1 。
在第 4 分钟结尾，电池 1 也被耗尽，第一台电脑无法继续运行。
我们最多能同时让两台电脑同时运行 4 分钟，所以我们返回 4 。
示例 2：



输入：n = 2, batteries = [1,1,1,1]
输出：2
解释：
一开始，将第一台电脑与电池 0 连接，第二台电脑与电池 2 连接。
一分钟后，电池 0 和电池 2 同时耗尽，所以你需要将它们断开连接，并将电池 1 和第一台电脑连接，电池 3 和第二台电脑连接。
1 分钟后，电池 1 和电池 3 也耗尽了，所以两台电脑都无法继续运行。
我们最多能让两台电脑同时运行 2 分钟，所以我们返回 2 。
 

提示：

1 <= n <= batteries.length <= 105
1 <= batteries[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-running-time-of-n-computers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <numeric>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long maxTime = 0, low = 1, high = accumulate(batteries.begin(), batteries.end(), (long long)0);

        while (low <= high) {
            long long middle = (low + high) / 2;

            if (check(n, batteries, middle)) {
                maxTime = middle;
                low = middle + 1;
            }
            else {
                high = middle - 1;
            }
        }

        return maxTime;
    }

    bool check(int n, vector<int>& batteries, long long maxTime) {
        long long sum = 0, time = n * maxTime;

        for (int battery : batteries) {
            sum += min((long long)battery, maxTime);

            if (sum >= time) {
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

    vector<int> batteries = { 3,3,3 };
    check.checkLongLong(4, o.maxRunTime(2, batteries));

    batteries = { 1,1,1,1 };
    check.checkLongLong(2, o.maxRunTime(2, batteries));

    batteries = { 5 };
    check.checkLongLong(5, o.maxRunTime(1, batteries));
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
