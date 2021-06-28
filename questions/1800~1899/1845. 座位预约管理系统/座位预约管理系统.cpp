/* 座位预约管理系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你设计一个管理 n 个座位预约的系统，座位编号从 1 到 n 。

请你实现 SeatManager 类：

SeatManager(int n) 初始化一个 SeatManager 对象，它管理从 1 到 n 编号的 n 个座位。所有座位初始都是可预约的。
int reserve() 返回可以预约座位的 最小编号 ，此座位变为不可预约。
void unreserve(int seatNumber) 将给定编号 seatNumber 对应的座位变成可以预约。
 

示例 1：

输入：
["SeatManager", "reserve", "reserve", "unreserve", "reserve", "reserve", "reserve", "reserve", "unreserve"]
[[5], [], [], [2], [], [], [], [], [5]]
输出：
[null, 1, 2, null, 2, 3, 4, 5, null]

解释：
SeatManager seatManager = new SeatManager(5); // 初始化 SeatManager ，有 5 个座位。
seatManager.reserve();    // 所有座位都可以预约，所以返回最小编号的座位，也就是 1 。
seatManager.reserve();    // 可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
seatManager.unreserve(2); // 将座位 2 变为可以预约，现在可预约的座位为 [2,3,4,5] 。
seatManager.reserve();    // 可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
seatManager.reserve();    // 可以预约的座位为 [3,4,5] ，返回最小编号的座位，也就是 3 。
seatManager.reserve();    // 可以预约的座位为 [4,5] ，返回最小编号的座位，也就是 4 。
seatManager.reserve();    // 唯一可以预约的是座位 5 ，所以返回 5 。
seatManager.unreserve(5); // 将座位 5 变为可以预约，现在可预约的座位为 [5] 。
 

提示：

1 <= n <= 105
1 <= seatNumber <= n
每一次对 reserve 的调用，题目保证至少存在一个可以预约的座位。
每一次对 unreserve 的调用，题目保证 seatNumber 在调用函数前都是被预约状态。
对 reserve 和 unreserve 的调用 总共 不超过 105 次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/seat-reservation-manager
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class SeatManager {
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            seats.push(i);
        }
    }

    int reserve() {
        int seat = seats.top();
        seats.pop();

        return seat;
    }

    void unreserve(int seatNumber) {
        seats.push(seatNumber);
    }

private:
    priority_queue<int, vector<int>, greater<int>> seats;
};

int main()
{
    CheckResult check;

    SeatManager o1(5);
    check.checkInt(1, o1.reserve());
    check.checkInt(2, o1.reserve());
    o1.unreserve(2);
    check.checkInt(2, o1.reserve());
    check.checkInt(3, o1.reserve());
    check.checkInt(4, o1.reserve());
    check.checkInt(5, o1.reserve());
    o1.unreserve(5);
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
