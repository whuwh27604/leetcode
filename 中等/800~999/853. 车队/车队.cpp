/* 车队.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
N  辆车沿着一条车道驶向位于 target 英里之外的共同目的地。

每辆车 i 以恒定的速度 speed[i] （英里/小时），从初始位置 position[i] （英里） 沿车道驶向目的地。

一辆车永远不会超过前面的另一辆车，但它可以追上去，并与前车以相同的速度紧接着行驶。

此时，我们会忽略这两辆车之间的距离，也就是说，它们被假定处于相同的位置。

车队 是一些由行驶在相同位置、具有相同速度的车组成的非空集合。注意，一辆车也可以是一个车队。

即便一辆车在目的地才赶上了一个车队，它们仍然会被视作是同一个车队。

 

会有多少车队到达目的地?

 

示例：

输入：target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
输出：3
解释：
从 10 和 8 开始的车会组成一个车队，它们在 12 处相遇。
从 0 处开始的车无法追上其它车，所以它自己就是一个车队。
从 5 和 3 开始的车会组成一个车队，它们在 6 处相遇。
请注意，在到达目的地之前没有其它车会遇到这些车队，所以答案是 3。

提示：

0 <= N <= 10 ^ 4
0 < target <= 10 ^ 6
0 < speed[i] <= 10 ^ 6
0 <= position[i] < target
所有车的初始位置各不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/car-fleet
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int i, N = speed.size(), count = 0;

        vector<pair<int, int>> cars;
        for (i = 0; i < N; ++i) {
            cars.push_back({ position[i], speed[i] });
        }

        sort(cars.begin(), cars.end());  // 按照车队的原始位置排序，注意最靠近目的地的排在后面了。如果有相同位置的车，速度快的认为更靠近目的地

        vector<double> arrivalTimes;
        for (pair<int, int>& car : cars) {
            arrivalTimes.push_back(((double)target - car.first) / car.second);  // 计算无障碍下每个车到达目的地的时间
        }

        double latestArrival = 0;
        for (i = N - 1; i >= 0; --i ) {  // 从离目的地最近的车开始往后遍历，小于等于到达时间的车，因为它跑得快，肯定会被中间的某个车合并掉
            if (arrivalTimes[i] > latestArrival) {  // 到达时间更大，这个车会形成一个新的车队，所以计数加一，并更新到达时间
                count++;
                latestArrival = arrivalTimes[i];
            }
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> position = { 10,8,0,5,3 };
    vector<int> speed = { 2,4,1,1,3 };
    check.checkInt(3, o.carFleet(12, position, speed));

    position = { 0,0 };
    speed = { 2,4 };
    check.checkInt(2, o.carFleet(12, position, speed));

    position = { 8,3,7,4,6,5 };
    speed = { 4,4,4,4,4,4 };
    check.checkInt(6, o.carFleet(10, position, speed));
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
