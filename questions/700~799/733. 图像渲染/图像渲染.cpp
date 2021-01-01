/* 图像渲染.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。

给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。

为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为新的颜色值。

最后返回经过上色渲染后的图像。

示例 1:

输入:
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
输出: [[2,2,2],[2,2,0],[2,0,1]]
解析:
在图像的正中间，(坐标(sr,sc)=(1,1)),
在路径上所有符合条件的像素点的颜色都被更改成2。
注意，右下角的像素没有更改为2，
因为它不是在上下左右四个方向上与初始点相连的像素点。
注意:

image 和 image[0] 的长度在范围 [1, 50] 内。
给出的初始点将满足 0 <= sr < image.length 和 0 <= sc < image[0].length。
image[i][j] 和 newColor 表示的颜色值在范围 [0, 65535]内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flood-fill
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        changePoint(image, sr, sc, image[sr][sc], newColor);
        return image;
    }

    void changePoint(vector<vector<int>>& image, int sr, int sc, int originalColor, int newColor) {
        image[sr][sc] = newColor;
        changeUp(image, sr, sc, originalColor, newColor);
        changeDown(image, sr, sc, originalColor, newColor);
        changeLeft(image, sr, sc, originalColor, newColor);
        changeRight(image, sr, sc, originalColor, newColor);
    }

    void changeUp(vector<vector<int>>& image, int sr, int sc, int originalColor, int newColor) {
        if ((sr == 0) || (image[sr - 1][sc] != originalColor) || (image[sr - 1][sc] == newColor)) {
            return;
        }

        image[sr - 1][sc] = newColor;

        changeUp(image, sr - 1, sc, originalColor, newColor);
        changeDown(image, sr - 1, sc, originalColor, newColor);
        changeLeft(image, sr - 1, sc, originalColor, newColor);
        changeRight(image, sr - 1, sc, originalColor, newColor);
    }

    void changeDown(vector<vector<int>>& image, int sr, int sc, int originalColor, int newColor) {
        if ((sr == (image.size() - 1)) || (image[sr + 1][sc] != originalColor) || (image[sr + 1][sc] == newColor)) {
            return;
        }

        image[sr + 1][sc] = newColor;

        changeUp(image, sr + 1, sc, originalColor, newColor);
        changeDown(image, sr + 1, sc, originalColor, newColor);
        changeLeft(image, sr + 1, sc, originalColor, newColor);
        changeRight(image, sr + 1, sc, originalColor, newColor);
    }

    void changeLeft(vector<vector<int>>& image, int sr, int sc, int originalColor, int newColor) {
        if ((sc == 0) || (image[sr][sc - 1] != originalColor) || (image[sr][sc - 1] == newColor)) {
            return;
        }

        image[sr][sc - 1] = newColor;

        changeUp(image, sr, sc - 1, originalColor, newColor);
        changeDown(image, sr, sc - 1, originalColor, newColor);
        changeLeft(image, sr, sc - 1, originalColor, newColor);
        changeRight(image, sr, sc - 1, originalColor, newColor);
    }

    void changeRight(vector<vector<int>>& image, int sr, int sc, int originalColor, int newColor) {
        if ((sc == (image[0].size() - 1)) || (image[sr][sc + 1] != originalColor) || (image[sr][sc + 1] == newColor)) {
            return;
        }

        image[sr][sc + 1] = newColor;

        changeUp(image, sr, sc + 1, originalColor, newColor);
        changeDown(image, sr, sc + 1, originalColor, newColor);
        changeLeft(image, sr, sc + 1, originalColor, newColor);
        changeRight(image, sr, sc + 1, originalColor, newColor);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> image = { {1,1,1},{1,1,0},{1,0,1} };
    vector<vector<int>> actual = o.floodFill(image, 1, 1, 2);
    vector<vector<int>> expected = { {2,2,2},{2,2,0},{2,0,1} };
    check.checkIntDoubleVector(expected, actual);

    image = { {1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1} };
    actual = o.floodFill(image, 2, 2, 2);
    expected = { {2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2} };
    check.checkIntDoubleVector(expected, actual);

    image = { {1,0,1,0,1},{0,1,1,1,0},{1,1,1,1,1},{0,1,1,1,0},{1,0,1,0,1} };
    actual = o.floodFill(image, 2, 2, 2);
    expected = { {1,0,2,0,1},{0,2,2,2,0},{2,2,2,2,2},{0,2,2,2,0},{1,0,2,0,1} };
    check.checkIntDoubleVector(expected, actual);

    image = { {0,0,0},{0,1,0} };
    actual = o.floodFill(image, 1, 1, 2);
    expected = { {0,0,0},{0,2,0} };
    check.checkIntDoubleVector(expected, actual);

    vector<vector<int>> act;
    vector<vector<int>> exp;
    for (int j = 0; j < 50; j++) {
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < 50; i++) {
            a.push_back(1);
            b.push_back(2);
        }
        act.push_back(a);
        exp.push_back(b);
    }
    actual = o.floodFill(act, 24, 24, 2);
    check.checkIntDoubleVector(exp, actual);    
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
