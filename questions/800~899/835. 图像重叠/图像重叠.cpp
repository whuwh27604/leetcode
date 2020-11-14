/* 图像重叠.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出两个图像 A 和 B ，A 和 B 为大小相同的二维正方形矩阵。（并且为二进制矩阵，只包含0和1）。

我们转换其中一个图像，向左，右，上，或下滑动任何数量的单位，并把它放在另一个图像的上面。之后，该转换的重叠是指两个图像都具有 1 的位置的数目。

（请注意，转换不包括向任何方向旋转。）

最大可能的重叠是什么？

示例 1:

输入：A = [[1,1,0],
          [0,1,0],
          [0,1,0]]
     B = [[0,0,0],
          [0,1,1],
          [0,0,1]]
输出：3
解释: 将 A 向右移动一个单位，然后向下移动一个单位。
注意: 

1 <= A.length = A[0].length = B.length = B[0].length <= 30
0 <= A[i][j], B[i][j] <= 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/image-overlap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int i, j, size = img1.size(), maxOverlap = 0;

        for (i = 0; i < size; ++i) {
            for (j = 0; j < size; ++j) {
                maxOverlap = max(maxOverlap, overlap(img1, img2, i, j));
            }
        }

        return maxOverlap;
    }

    int overlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int dr, int dc) {
        int i, j, size = img1.size(), count1 = 0, count2 = 0, count3 = 0, count4 = 0;

        for (i = dr; i < size; ++i) {
            for (j = dc; j < size; ++j) {
                if ((img1[i - dr][j - dc] == 1) && (img2[i][j] == 1)) {
                    count1++;
                }
                if ((img1[i][j] == 1) && (img2[i - dr][j - dc] == 1)) {
                    count2++;
                }
            }
        }

        for (i = 0; i < size - dr; ++i) {
            for (j = dc; j < size; ++j) {
                if ((img1[i + dr][j - dc] == 1) && (img2[i][j] == 1)) {
                    count3++;
                }
                if ((img1[i][j] == 1) && (img2[i + dr][j - dc] == 1)) {
                    count4++;
                }
            }
        }

        return max(max(count1, count2), max(count3, count4));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> img1 = { {1,1,0},{0,1,0},{0,1,0} };
    vector<vector<int>> img2 = { {0,0,0},{0,1,1},{0,0,1} };
    check.checkInt(3, o.largestOverlap(img1, img2));

    img1 = { {0,0,0},{1,1,0},{0,0,0} };
    img2 = { {0,1,1},{0,0,0},{0,0,0} };
    check.checkInt(2, o.largestOverlap(img1, img2));

    img1 = { {1} };
    img2 = { {0} };
    check.checkInt(0, o.largestOverlap(img1, img2));

    img1 = { {1} };
    img2 = { {1} };
    check.checkInt(1, o.largestOverlap(img1, img2));

    img1 = { {1,1},{0,0} };
    img2 = { {0,0},{1,1} };
    check.checkInt(2, o.largestOverlap(img1, img2));

    img1 = { {0,0},{1,1} };
    img2 = { {1,1},{0,0} };
    check.checkInt(2, o.largestOverlap(img1, img2));

    img1 = { {0,1},{0,0} };
    img2 = { {0,0},{1,0} };
    check.checkInt(1, o.largestOverlap(img1, img2));

    img1 = { {0,0,0,0,1},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0} };
    img2 = { {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{1,0,0,0,0} };
    check.checkInt(1, o.largestOverlap(img1, img2));

    img1 = { {1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0} };
    img2 = { {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,1} };
    check.checkInt(1, o.largestOverlap(img1, img2));
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
