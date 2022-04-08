/* 服务中心的最佳位置.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一家快递公司希望在新城市建立新的服务中心。公司统计了该城市所有客户在二维地图上的坐标，并希望能够以此为依据为新的服务中心选址：使服务中心 到所有客户的欧几里得距离的总和最小 。

给你一个数组 positions ，其中 positions[i] = [xi, yi] 表示第 i 个客户在二维地图上的位置，返回到所有客户的 欧几里得距离的最小总和 。

换句话说，请你为服务中心选址，该位置的坐标 [xcentre, ycentre] 需要使下面的公式取到最小值：



与真实值误差在 10-5之内的答案将被视作正确答案。

 

示例 1：



输入：positions = [[0,1],[1,0],[1,2],[2,1]]
输出：4.00000
解释：如图所示，你可以选 [xcentre, ycentre] = [1, 1] 作为新中心的位置，这样一来到每个客户的距离就都是 1，所有距离之和为 4 ，这也是可以找到的最小值。
示例 2：



输入：positions = [[1,1],[3,3]]
输出：2.82843
解释：欧几里得距离可能的最小总和为 sqrt(2) + sqrt(2) = 2.82843
 

提示：

1 <= positions.length <= 50
positions[i].length == 2
0 <= xi, yi <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-position-for-a-service-centre
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        double xLeft = 0.0, xRight = 100.0, eps = 1e-7;

        while (xRight - xLeft > eps) {
            double xFirst = (xLeft + xLeft + xRight) / 3;  // 左 1/3 点
            double xSecond = (xLeft + xRight + xRight) / 3;  // 右 1/3 点

            if (checkOptimal(positions, xFirst) < checkOptimal(positions, xSecond)) {
                xRight = xSecond;
            }
            else {
                xLeft = xFirst;
            }
        }

        return checkOptimal(positions, xLeft);
    }

    double checkOptimal(vector<vector<int>>& positions, double centerX) {  // 固定 centerX，使用三分法找出最优的centerY
        double yLeft = 0.0, yRight = 100.0, eps = 1e-7;

        while (yRight - yLeft > eps) {
            double yFirst = (yLeft + yLeft + yRight) / 3;
            double ySecond = (yLeft + yRight + yRight) / 3;

            if (getDistanceSum(positions, centerX, yFirst) < getDistanceSum(positions, centerX, ySecond)) {
                yRight = ySecond;
            }
            else {
                yLeft = yFirst;
            }
        }

        return getDistanceSum(positions, centerX, yLeft);
    };

    double getDistanceSum(vector<vector<int>>& positions, double centerX, double centerY) {
        double distance = 0;

        for (auto& pos : positions) {
            distance += sqrt((pos[0] - centerX) * (pos[0] - centerX) + (pos[1] - centerY) * (pos[1] - centerY));
        }

        return distance;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> positions = {{0,1},{1,0},{1,2},{2,1}};
    check.checkDouble(4.0,o.getMinDistSum(positions));

    positions = {{1,1},{3,3}};
    check.checkDouble(2.828427,o.getMinDistSum(positions));

    positions = {{0,1},{3,2},{4,5},{7,6},{8,9},{11,1},{2,12}};
    check.checkDouble(32.940362, o.getMinDistSum(positions));
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
