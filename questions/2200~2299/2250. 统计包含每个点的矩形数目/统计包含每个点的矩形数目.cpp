// 统计包含每个点的矩形数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int i = rectangles.size() - 1, size = points.size(), maxHeight = getMaxHeight(rectangles);
        vector<int> heightCount(maxHeight + 1, 0), rectangleCount(size, 0);

        addIndex(points);
        sort(points.begin(), points.end());  // 按照x排序
        sort(rectangles.begin(), rectangles.end());  // 按照x排序

        for (int j = points.size() - 1; j >= 0; --j) {  // 按照x从大到小遍历points
            while (i >= 0 && rectangles[i][0] >= points[j][0]) {
                ++heightCount[rectangles[i--][1]];  // 将x比points[j]大的所有rectangles的y坐标计数
            }

            for (int height = points[j][1]; height <= maxHeight; ++height) {  // 统计这些rectangles里面，y坐标比points[j]大的rectangles的个数
                rectangleCount[points[j][2]] += heightCount[height];
            }
        }

        return rectangleCount;
    }

    int getMaxHeight(vector<vector<int>>& rectangles) {
        int maxHeight = 0;

        for (auto& rectangle : rectangles) {
            maxHeight = max(maxHeight, rectangle[1]);
        }

        return maxHeight;
    }

    void addIndex(vector<vector<int>>& points) {
        int index = 0;

        for (auto& point : points) {
            point.push_back(index++);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> rectangles = { {1,2},{2,3},{2,5} };
    vector<vector<int>> points = { {2,1},{1,4} };
    vector<int> actual = o.countRectangles(rectangles, points);
    vector<int> expected = { 2,1 };
    check.checkIntVector(expected, actual);

    rectangles = { {1,1},{2,2},{3,3} };
    points = { {1,3},{1,1} };
    actual = o.countRectangles(rectangles, points);
    expected = { 1,3 };
    check.checkIntVector(expected, actual);

    rectangles = { {49,26},{7,80},{79,10},{57,23},{23,20},{24,82},{47,62},{55,93},{84,62},{67,22} };
    points = { {65,31},{54,59},{57,46},{63,49},{87,93},{81,4},{23,50},{58,33},{100,39},{79,58},{89,25},{12,37},{83,68},{19,16},{22,44},{5,87},{33,82},{69,62},{67,29},{92,25},{51,98},{48,60},{62,87},{71,59},{99,81},{91,91},{26,83},{40,87},{28,42},{94,53},{80,24},{10,94},{16,1},{45,7},{50,39},{53,37},{76,50},{7,69},{1,81},{95,40},{48,73},{47,16},{38,5},{41,17},{24,37},{35,10},{25,92},{9,78},{66,97},{34,52},{28,45},{33,28},{55,48},{25,17},{14,24},{70,63},{6,47},{13,32},{64,36},{57,1},{37,62},{41,61},{56,77},{41,18},{69,43},{69,68},{24,11},{51,35},{5,86},{44,67},{98,21},{81,53},{78,69} };
    actual = o.countRectangles(rectangles, points);
    expected = { 1,2,1,1,0,1,4,1,0,1,0,4,0,8,4,1,1,1,1,0,0,2,0,1,0,0,1,1,3,0,1,0,9,7,2,2,1,3,2,0,1,6,7,6,4,7,1,2,0,3,3,3,2,6,5,0,5,4,1,4,3,3,0,6,1,0,7,2,1,1,0,1,0 };
    check.checkIntVector(expected, actual);
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
