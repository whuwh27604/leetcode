/* 缀点成线.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个 XY 坐标系中有一些点，我们用数组 coordinates 来分别记录它们的坐标，其中 coordinates[i] = [x, y] 表示横坐标为 x、纵坐标为 y 的点。

请你来判断，这些点是否在该坐标系中属于同一条直线上，是则返回 true，否则请返回 false。

 

示例 1：



输入：coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
输出：true
示例 2：



输入：coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
输出：false
 

提示：

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates 中不含重复的点

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-it-is-a-straight-line
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[1][0] - coordinates[0][0], y1 = coordinates[1][1] - coordinates[0][1];

        for (unsigned int i = 2; i < coordinates.size(); i++) {
            int x2 = coordinates[i][0] - coordinates[0][0];
            int y2 = coordinates[i][1] - coordinates[0][1];
            if ((x1 * y2) != (x2 * y1)) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> coordinates = { {1,2},{2,3},{3,4},{4,5},{5,6},{6,7} };
    check.checkBool(true, o.checkStraightLine(coordinates));

    coordinates = { {1,2},{-3,-2},{-4,-3},{4,5},{5,6},{-7,-6} };
    check.checkBool(true, o.checkStraightLine(coordinates));

    coordinates = { {1,1},{2,2},{3,4},{4,5},{5,6},{7,7} };
    check.checkBool(false, o.checkStraightLine(coordinates));

    coordinates = { {1,2},{2,10} };
    check.checkBool(true, o.checkStraightLine(coordinates));
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
