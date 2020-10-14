/* 用最少数量的箭引爆气球.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。开始坐标总是小于结束坐标。平面内最多存在104个气球。

一支弓箭可以沿着x轴从不同点完全垂直地射出。在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

Example:

输入:
[[10,16], [2,8], [1,6], [7,12]]

输出:
2

解释:
对于该样例，我们可以在x = 6（射爆[2,8],[1,6]两个气球）和 x = 11（射爆另外两个气球）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int> v1, const vector<int> v2) {
    return v1[1] < v2[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        // 按照结束点贪心选择，就是最后正确的答案。记住这个结论吧，暂未想到简单有效的证明方法。
        sort(points.begin(), points.end(), vectorCompare);  // 可能是vector的排序比较慢

        int count = 1, currentEnd = points[0][1];  // 选中第一个结束点

        for (unsigned int i = 1; i < points.size(); i++) {
            if (points[i][0] > currentEnd) {
                count++;
                currentEnd = points[i][1];  // 不重叠，需要新增一支箭
            }
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> points = { {10,16},{2,8},{1,6},{7,12} };
    check.checkInt(2, o.findMinArrowShots(points));

    points = {  };
    check.checkInt(0, o.findMinArrowShots(points));

    points = { {1,2} };
    check.checkInt(1, o.findMinArrowShots(points));

    points = { {1,2},{2,3} };
    check.checkInt(1, o.findMinArrowShots(points));

    points = { {1,2},{1,2},{1,2} };
    check.checkInt(1, o.findMinArrowShots(points));

    points = { {1,2},{2,3},{3,4},{1,3} };
    check.checkInt(2, o.findMinArrowShots(points));

    points = { {1,100},{11,22},{1,11},{2,12} };
    check.checkInt(1, o.findMinArrowShots(points));

    points = { {1,10},{2,4},{7,9},{3,5},{6,8},{4,7} };
    check.checkInt(2, o.findMinArrowShots(points));

    points = { {1,2},{2,3},{3,4},{4,5},{5,6} };
    check.checkInt(3, o.findMinArrowShots(points));

    points = { {-2147483648,2147483647} };
    check.checkInt(1, o.findMinArrowShots(points));

    points = { {0,9},{1,8},{7,8},{1,6},{9,16},{7,13},{7,10},{6,11},{6,9},{9,13} };
    check.checkInt(3, o.findMinArrowShots(points));

    points = { {2,3},{7,15},{5,12},{4,5},{8,13},{9,16},{5,8},{8,16},{3,4},{8,17} };
    check.checkInt(3, o.findMinArrowShots(points));
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
