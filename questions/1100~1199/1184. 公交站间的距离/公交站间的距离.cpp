/* 公交站间的距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
环形公交路线上有 n 个站，按次序从 0 到 n - 1 进行编号。我们已知每一对相邻公交站之间的距离，distance[i] 表示编号为 i 的车站和编号为 (i + 1) % n 的车站之间的距离。

环线上的公交车都可以按顺时针和逆时针的方向行驶。

返回乘客从出发点 start 到目的地 destination 之间的最短距离。

 

示例 1：



输入：distance = [1,2,3,4], start = 0, destination = 1
输出：1
解释：公交站 0 和 1 之间的距离是 1 或 9，最小值是 1。
 

示例 2：



输入：distance = [1,2,3,4], start = 0, destination = 2
输出：3
解释：公交站 0 和 2 之间的距离是 3 或 7，最小值是 3。
 

示例 3：



输入：distance = [1,2,3,4], start = 0, destination = 3
输出：4
解释：公交站 0 和 3 之间的距离是 6 或 4，最小值是 4。
 

提示：

1 <= n <= 10^4
distance.length == n
0 <= start, destination < n
0 <= distance[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distance-between-bus-stops
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int i, n = distance.size(), clockwiseDistance = 0, counterclockwiseDistance = 0;

        i = start;
        while (i != destination) {
            clockwiseDistance += distance[i++];
            if (i == n) {
                i = 0;
            }
        }

        i = destination;
        while (i != start) {
            counterclockwiseDistance += distance[i++];
            if (i == n) {
                i = 0;
            }
        }

        return min(clockwiseDistance, counterclockwiseDistance);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> distance = { 1,2,3,4 };
    check.checkInt(1, o.distanceBetweenBusStops(distance, 0, 1));
    check.checkInt(3, o.distanceBetweenBusStops(distance, 0, 2));
    check.checkInt(4, o.distanceBetweenBusStops(distance, 0, 3));
    check.checkInt(2, o.distanceBetweenBusStops(distance, 1, 2));
    check.checkInt(5, o.distanceBetweenBusStops(distance, 1, 3));

    distance = { 4 };
    check.checkInt(0, o.distanceBetweenBusStops(distance, 0, 0));
    
    distance = { 3,3 };
    check.checkInt(3, o.distanceBetweenBusStops(distance, 0, 1));
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
