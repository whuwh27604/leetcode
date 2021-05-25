/* 准时到达的列车最小时速.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个浮点数 hour ，表示你到达办公室可用的总通勤时间。要到达办公室，你必须按给定次序乘坐 n 趟列车。另给你一个长度为 n 的整数数组 dist ，其中 dist[i] 表示第 i 趟列车的行驶距离（单位是千米）。

每趟列车均只能在整点发车，所以你可能需要在两趟列车之间等待一段时间。

例如，第 1 趟列车需要 1.5 小时，那你必须再等待 0.5 小时，搭乘在第 2 小时发车的第 2 趟列车。
返回能满足你准时到达办公室所要求全部列车的 最小正整数 时速（单位：千米每小时），如果无法准时到达，则返回 -1 。

生成的测试用例保证答案不超过 107 ，且 hour 的 小数点后最多存在两位数字 。

 

示例 1：

输入：dist = [1,3,2], hour = 6
输出：1
解释：速度为 1 时：
- 第 1 趟列车运行需要 1/1 = 1 小时。
- 由于是在整数时间到达，可以立即换乘在第 1 小时发车的列车。第 2 趟列车运行需要 3/1 = 3 小时。
- 由于是在整数时间到达，可以立即换乘在第 4 小时发车的列车。第 3 趟列车运行需要 2/1 = 2 小时。
- 你将会恰好在第 6 小时到达。
示例 2：

输入：dist = [1,3,2], hour = 2.7
输出：3
解释：速度为 3 时：
- 第 1 趟列车运行需要 1/3 = 0.33333 小时。
- 由于不是在整数时间到达，故需要等待至第 1 小时才能搭乘列车。第 2 趟列车运行需要 3/3 = 1 小时。
- 由于是在整数时间到达，可以立即换乘在第 2 小时发车的列车。第 3 趟列车运行需要 2/3 = 0.66667 小时。
- 你将会在第 2.66667 小时到达。
示例 3：

输入：dist = [1,3,2], hour = 1.9
输出：-1
解释：不可能准时到达，因为第 3 趟列车最早是在第 2 小时发车。
 

提示：

n == dist.length
1 <= n <= 105
1 <= dist[i] <= 105
1 <= hour <= 109
hours 中，小数点后最多存在两位数字

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-speed-to-arrive-on-time
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int i, size = dist.size(), left = 1, right = 0;
        long long sum = 0;

        if (hour <= (double)size - 1) {
            return -1;
        }

        for (i = 0; i < size - 1; ++i) {
            sum += dist[i];
            right = max(right, dist[i]);
        }

        sum += dist[i];
        right = max(right, (int)ceil((double)dist[i] / (hour + 1 - size)));
        int minSpeed = right;

        if (hour >= sum) {
            return 1;
        }

        while (left <= right) {
            int middle = (left + right) / 2;

            if (canArrived(dist, hour, middle)) {
                right = middle - 1;
                minSpeed = middle;
            }
            else {
                left = middle + 1;
            }
        }

        return minSpeed;
    }

    bool canArrived(vector<int>& dist, double hour, int speed) {
        int i, size = dist.size();
        double time = 0;

        for (i = 0; i < size - 1; ++i) {
            time += ceil((double)dist[i] / speed);
            if (time > hour) {
                return false;
            }
        }

        return time + (double)dist.back() / speed <= hour;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> dist = { 1,3,2 };
    check.checkInt(-1, o.minSpeedOnTime(dist, 2));

    dist = { 1,3,2 };
    check.checkInt(200, o.minSpeedOnTime(dist, 2.01));

    dist = { 1,3,2 };
    check.checkInt(3, o.minSpeedOnTime(dist, 3.01));

    dist = { 1,3,2 };
    check.checkInt(1, o.minSpeedOnTime(dist, 6));

    dist = { 1,1,100000 };
    check.checkInt(10000000, o.minSpeedOnTime(dist, 2.01));

    dist = { 5,3,4,6,2,2,7 };
    check.checkInt(4, o.minSpeedOnTime(dist, 10.92));
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
