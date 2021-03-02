/* 车队 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一条单车道上有 n 辆车，它们朝着同样的方向行驶。给你一个长度为 n 的数组 cars ，其中 cars[i] = [positioni, speedi] ，它表示：

positioni 是第 i 辆车和道路起点之间的距离（单位：米）。题目保证 positioni < positioni+1 。
speedi 是第 i 辆车的初始速度（单位：米/秒）。
简单起见，所有车子可以视为在数轴上移动的点。当两辆车占据同一个位置时，我们称它们相遇了。一旦两辆车相遇，它们会合并成一个车队，这个车队里的车有着同样的位置和相同的速度，速度为这个车队里 最慢 一辆车的速度。

请你返回一个数组 answer ，其中 answer[i] 是第 i 辆车与下一辆车相遇的时间（单位：秒），如果这辆车不会与下一辆车相遇，则 answer[i] 为 -1 。答案精度误差需在 10-5 以内。

 

示例 1：

输入：cars = [[1,2],[2,1],[4,3],[7,2]]
输出：[1.00000,-1.00000,3.00000,-1.00000]
解释：经过恰好 1 秒以后，第一辆车会与第二辆车相遇，并形成一个 1 m/s 的车队。经过恰好 3 秒以后，第三辆车会与第四辆车相遇，并形成一个 2 m/s 的车队。
示例 2：

输入：cars = [[3,4],[5,4],[6,3],[9,1]]
输出：[2.00000,1.00000,1.50000,-1.00000]
 

提示：

1 <= cars.length <= 105
1 <= positioni, speedi <= 106
positioni < positioni+1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/car-fleet-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int i, j, size = cars.size();
        vector<double> collisionTimes(size, -1);
        stack<int> increasing;  // 单调递增栈

        // 关键点：如果car[i].speed <= car[j].speed，那么i不可能追上j。如果j右边有一个比i慢的k，那么j会先追上k，而j追上k的后果就是j消失了。
        for (i = size - 1; i >= 0; --i) {
            while (!increasing.empty() && cars[i][1] <= cars[increasing.top()][1]) {
                increasing.pop();  // 速度小于栈顶的车，肯定追不上，直接pop它，因为它对car[i]没有任何影响，要么会消失，要么在i前面越来越远
            }

            if (!increasing.empty()) {  // 栈顶的车肯定可以追上，看看在什么位置追上它，没有栈顶则说明它追不上任何人
                j = increasing.top();
                while (collisionTimes[j] != -1
                    && cars[i][0] + cars[i][1] * collisionTimes[j] < cars[j][0] + cars[j][1] * collisionTimes[j]) {
                    increasing.pop();  // 这个车在它消失之前，还没有追上，不用管它
                    j = increasing.top();  // 一定有车可以追上，栈不会为空
                }

                collisionTimes[i] = ((double)cars[j][0] - cars[i][0]) / ((double)cars[i][1] - cars[j][1]);  // 计算追上的时间
            }

            increasing.push(i);
        }

        return collisionTimes;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> cars = { {1,2},{2,1},{4,3},{7,2} };
    vector<double> actual = o.getCollisionTimes(cars);
    vector<double> expected = { 1.00000,-1.00000,3.00000,-1.00000 };
    check.checkDoubleVector(expected, actual);

    cars = { {3,4},{5,4},{6,3},{9,1} };
    actual = o.getCollisionTimes(cars);
    expected = { 2.00000,1.00000,1.50000,-1.00000 };
    check.checkDoubleVector(expected, actual);

    cars = { {3,4} };
    actual = o.getCollisionTimes(cars);
    expected = { -1.00000 };
    check.checkDoubleVector(expected, actual);
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
