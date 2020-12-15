/* 重塑矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在MATLAB中，有一个非常有用的函数 reshape，它可以将一个矩阵重塑为另一个大小不同的新矩阵，但保留其原始数据。

给出一个由二维数组表示的矩阵，以及两个正整数r和c，分别表示想要的重构的矩阵的行数和列数。

重构后的矩阵需要将原始矩阵的所有元素以相同的行遍历顺序填充。

如果具有给定参数的reshape操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。

示例 1:

输入:
nums =
[[1,2],
 [3,4]]
r = 1, c = 4
输出:
[[1,2,3,4]]
解释:
行遍历nums的结果是 [1,2,3,4]。新的矩阵是 1 * 4 矩阵, 用之前的元素值一行一行填充新矩阵。
示例 2:

输入:
nums =
[[1,2],
 [3,4]]
r = 2, c = 4
输出:
[[1,2],
 [3,4]]
解释:
没有办法将 2 * 2 矩阵转化为 2 * 4 矩阵。 所以输出原矩阵。
注意：

给定矩阵的宽和高范围在 [1, 100]。
给定的 r 和 c 都是正数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reshape-the-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size();
        int column = nums[0].size();
        int area = (row * column);

        if (((area % r) != 0) || ((area / r) != c)) {
            return nums;
        }

        vector<vector<int>> newShape(r, vector<int>(c, 0));
        int count = 0, newShapeI = 0, newShapeJ = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                newShape[newShapeI][newShapeJ++] = nums[i][j];
                count++;
                if ((count % c) == 0) {
                    newShapeI++;
                    newShapeJ = 0;
                }
            }
        }

        return newShape;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> nums = { {1,2},{3,4} };
    vector<vector<int>> actual = o.matrixReshape(nums, 1, 4);
    vector<vector<int>> expected = { {1,2,3,4} };
    check.checkIntDoubleVector(expected, actual);

    nums = { {1,2},{3,4} };
    actual = o.matrixReshape(nums, 2, 4);
    expected = nums;
    check.checkIntDoubleVector(expected, actual);

    nums = { {1} };
    actual = o.matrixReshape(nums, 1, 1);
    expected = nums;
    check.checkIntDoubleVector(expected, actual);

    nums = { {1} };
    actual = o.matrixReshape(nums, 2, 2);
    expected = nums;
    check.checkIntDoubleVector(expected, actual);

    nums = { {1,2,3,4} };
    actual = o.matrixReshape(nums, 4, 1);
    expected = { {1},{2},{3},{4} };
    check.checkIntDoubleVector(expected, actual);
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
