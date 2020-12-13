/* 灯泡开关 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
房间中有 n 枚灯泡，编号从 1 到 n，自左向右排成一排。最初，所有的灯都是关着的。

在 k  时刻（ k 的取值范围是 0 到 n - 1），我们打开 light[k] 这个灯。

灯的颜色要想 变成蓝色 就必须同时满足下面两个条件：

灯处于打开状态。
排在它之前（左侧）的所有灯也都处于打开状态。
请返回能够让 所有开着的 灯都 变成蓝色 的时刻 数目 。

 

示例 1：



输入：light = [2,1,3,5,4]
输出：3
解释：所有开着的灯都变蓝的时刻分别是 1，2 和 4 。
示例 2：

输入：light = [3,2,4,1,5]
输出：2
解释：所有开着的灯都变蓝的时刻分别是 3 和 4（index-0）。
示例 3：

输入：light = [4,1,2,3]
输出：1
解释：所有开着的灯都变蓝的时刻是 3（index-0）。
第 4 个灯在时刻 3 变蓝。
示例 4：

输入：light = [2,1,4,3,6,5]
输出：3
示例 5：

输入：light = [1,2,3,4,5,6]
输出：6
 

提示：

n == light.length
1 <= n <= 5 * 10^4
light 是 [1, 2, ..., n] 的一个排列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bulb-switcher-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int i, size = light.size(), maxOnLight = 0, allBlueTimes = 0;

        for (i = 0; i < size; ++i) {
            maxOnLight = max(maxOnLight, light[i]);

            if (maxOnLight == i + 1) {  // 最大亮灯的编号等于亮灯的个数，所有灯就会变blue
                ++allBlueTimes;
            }
        }

        return allBlueTimes;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> light = { 2,1,3,5,4 };
    check.checkInt(3, o.numTimesAllBlue(light));

    light = { 3,2,4,1,5 };
    check.checkInt(2, o.numTimesAllBlue(light));

    light = { 4,1,2,3 };
    check.checkInt(1, o.numTimesAllBlue(light));

    light = { 2,1,4,3,6,5 };
    check.checkInt(3, o.numTimesAllBlue(light));

    light = { 1,2,3,4,5,6 };
    check.checkInt(6, o.numTimesAllBlue(light));

    light = { 1 };
    check.checkInt(1, o.numTimesAllBlue(light));

    light = { 9,8,1,2,3,7,6,5,4 };
    check.checkInt(1, o.numTimesAllBlue(light));
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
