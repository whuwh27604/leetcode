/* 回旋镖的数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。

找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。

示例:

输入:
[[0,0],[1,0],[2,0]]

输出:
2

解释:
两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-boomerangs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        // 遍历所有节点，以当前节点为顶点，计算到其它所有点的距离，如果距离相等则构成回旋镖。然后将一组相等的距离进行取2个的排列，得到回旋镖的个数。
        unordered_map<int, int> distanceCount;  // 用来保存每种距离出现的次数
        int Boomerangs = 0;
        for (unsigned int i = 0; i < points.size(); i++) {
            distanceCount.clear();
            for (unsigned int j = 0; j < points.size(); j++) {
                if (j == i) {
                    continue;
                }

                int distance = twoPointsDistance(points[i], points[j]);
                auto iter = distanceCount.find(distance);
                if (iter == distanceCount.end()) {
                    distanceCount[distance] = 1;
                }
                else {
                    iter->second += 1;
                }
            }

            Boomerangs += onePointBoomerangs(distanceCount);
        }

        return Boomerangs;
    }

    int onePointBoomerangs(unordered_map<int, int>& distanceCount) {
        int Boomerangs = 0;
        for (auto iter = distanceCount.begin(); iter != distanceCount.end(); iter++) {
            if (iter->second == 1) {
                continue;
            }

            Boomerangs += permutation(iter->second);
        }

        return Boomerangs;
    }

    int twoPointsDistance(vector<int>& point1, vector<int>& point2) {
        int x = (point1[0] - point2[0]), y = (point1[1] - point2[1]);
        return (x * x + y * y);
    }

    int permutation(int n) {
        // P(n,m)=n(n-1)(n-2)...(n-m+1)，这里m固定等于2
        return (n * (n - 1));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> points = { {0,0},{1,0},{2,0} };
    check.checkInt(2, o.numberOfBoomerangs(points));

    points = { {0,0} };
    check.checkInt(0, o.numberOfBoomerangs(points));

    points = { {0,0},{1,0} };
    check.checkInt(0, o.numberOfBoomerangs(points));

    points = { {0,0},{1,0},{-1,0},{0,1},{0,-1} };
    check.checkInt(20, o.numberOfBoomerangs(points));

    points = { {0,0} };
    for (int i = 0; i < 125; i++) {
        vector<int> tmp = {i,0};
        points.push_back(tmp);
        tmp = { 0,i };
        points.push_back(tmp);
        tmp = { -i,0 };
        points.push_back(tmp);
        tmp = { 0,-1 };
        points.push_back(tmp);
    }
    check.checkInt(20, o.numberOfBoomerangs(points));
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
