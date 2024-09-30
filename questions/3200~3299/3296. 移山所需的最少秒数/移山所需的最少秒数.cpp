/* 移山所需的最少秒数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 mountainHeight 表示山的高度。

同时给你一个整数数组 workerTimes，表示工人们的工作时间（单位：秒）。

工人们需要 同时 进行工作以 降低 山的高度。对于工人 i :

山的高度降低 x，需要花费 workerTimes[i] + workerTimes[i] * 2 + ... + workerTimes[i] * x 秒。例如：
山的高度降低 1，需要 workerTimes[i] 秒。
山的高度降低 2，需要 workerTimes[i] + workerTimes[i] * 2 秒，依此类推。
返回一个整数，表示工人们使山的高度降低到 0 所需的 最少 秒数。



示例 1：

输入： mountainHeight = 4, workerTimes = [2,1,1]

输出： 3

解释：

将山的高度降低到 0 的一种方式是：

工人 0 将高度降低 1，花费 workerTimes[0] = 2 秒。
工人 1 将高度降低 2，花费 workerTimes[1] + workerTimes[1] * 2 = 3 秒。
工人 2 将高度降低 1，花费 workerTimes[2] = 1 秒。
因为工人同时工作，所需的最少时间为 max(2, 3, 1) = 3 秒。

示例 2：

输入： mountainHeight = 10, workerTimes = [3,2,2,4]

输出： 12

解释：

工人 0 将高度降低 2，花费 workerTimes[0] + workerTimes[0] * 2 = 9 秒。
工人 1 将高度降低 3，花费 workerTimes[1] + workerTimes[1] * 2 + workerTimes[1] * 3 = 12 秒。
工人 2 将高度降低 3，花费 workerTimes[2] + workerTimes[2] * 2 + workerTimes[2] * 3 = 12 秒。
工人 3 将高度降低 2，花费 workerTimes[3] + workerTimes[3] * 2 = 12 秒。
所需的最少时间为 max(9, 12, 12, 12) = 12 秒。

示例 3：

输入： mountainHeight = 5, workerTimes = [1]

输出： 15

解释：

这个示例中只有一个工人，所以答案是 workerTimes[0] + workerTimes[0] * 2 + workerTimes[0] * 3 + workerTimes[0] * 4 + workerTimes[0] * 5 = 15 秒。



提示：

1 <= mountainHeight <= 105
1 <= workerTimes.length <= 104
1 <= workerTimes[i] <= 106
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int h = (mountainHeight - 1) / (int)workerTimes.size() + 1;
        long long low = 0, high = (long long)*max_element(workerTimes.begin(), workerTimes.end()) * h * (h + 1) / 2, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;
            int height = cutHeight(mid, workerTimes);

            if (height >= mountainHeight) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int cutHeight(long long totalTime, vector<int>& workerTimes) {
        int height = 0;

        for (int time : workerTimes) {
            height += (int)((sqrt(totalTime / time * 8 + 1) - 1) / 2);
        }

        return height;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> workerTimes = { 2,1,1 };
    check.checkLongLong(3, o.minNumberOfSeconds(4, workerTimes));

    workerTimes = { 3,2,2,4 };
    check.checkLongLong(12, o.minNumberOfSeconds(10, workerTimes));

    workerTimes = { 1 };
    check.checkLongLong(15, o.minNumberOfSeconds(5, workerTimes));
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
