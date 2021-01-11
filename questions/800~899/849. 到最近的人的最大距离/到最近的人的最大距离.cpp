/* 到最近的人的最大距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一排座位（ seats）中，1 代表有人坐在座位上，0 代表座位上是空的。

至少有一个空座位，且至少有一人坐在座位上。

亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。

返回他到离他最近的人的最大距离。

示例 1：

输入：[1,0,0,0,1,0,1]
输出：2
解释：
如果亚历克斯坐在第二个空位（seats[2]）上，他到离他最近的人的距离为 2 。
如果亚历克斯坐在其它任何一个空位上，他到离他最近的人的距离为 1 。
因此，他到离他最近的人的最大距离是 2 。
示例 2：

输入：[1,0,0,0]
输出：3
解释：
如果亚历克斯坐在最后一个座位上，他离最近的人有 3 个座位远。
这是可能的最大距离，所以答案是 3 。
提示：

1 <= seats.length <= 20000
seats 中只含有 0 和 1，至少有一个 0，且至少有一个 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximize-distance-to-closest-person
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int consecutiveZeros = 0, maxConsecutiveZeros = 0, leftmostConsecutiveZeros = 0, rightmostConsecutiveZeros = 0;
        bool isLeftmost = true;

        for (unsigned int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                maxConsecutiveZeros = max(maxConsecutiveZeros, consecutiveZeros);
                consecutiveZeros = 0;
                rightmostConsecutiveZeros = 0;
                isLeftmost = false;
                continue;
            }

            consecutiveZeros++;
            rightmostConsecutiveZeros++;
            if (isLeftmost) {
                leftmostConsecutiveZeros++;
            }
        }

        int maxDistance = ((maxConsecutiveZeros + 1) / 2);
        maxDistance = max(maxDistance, leftmostConsecutiveZeros);
        return max(maxDistance, rightmostConsecutiveZeros);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> seats = { 1,0,0,0,1,0,1 };
    check.checkInt(2, o.maxDistToClosest(seats));

    seats = { 1,0,0,0 };
    check.checkInt(3, o.maxDistToClosest(seats));

    seats = { 1,0 };
    check.checkInt(1, o.maxDistToClosest(seats));

    seats = { 0,1 };
    check.checkInt(1, o.maxDistToClosest(seats));

    seats = { 1,0,0,0,0,0 };
    check.checkInt(5, o.maxDistToClosest(seats));

    seats = { 0,0,0,0,0,1 };
    check.checkInt(5, o.maxDistToClosest(seats));

    seats = { 1,0,1 };
    check.checkInt(1, o.maxDistToClosest(seats));

    seats = { 1,0,0,1 };
    check.checkInt(1, o.maxDistToClosest(seats));

    seats = { 1,0,0,0,1 };
    check.checkInt(2, o.maxDistToClosest(seats));

    seats = { 1,0,0,0,0,1 };
    check.checkInt(2, o.maxDistToClosest(seats));

    seats = { 1,0,0,0,0,0,1 };
    check.checkInt(3, o.maxDistToClosest(seats));

    seats = { 0,0,0,0,1,0,0,0,0,0,1 };
    check.checkInt(4, o.maxDistToClosest(seats));

    seats = { 1,0,0,0,0,0,1,0,0,0,0 };
    check.checkInt(4, o.maxDistToClosest(seats));

    seats = { 0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0 };
    check.checkInt(5, o.maxDistToClosest(seats));
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
