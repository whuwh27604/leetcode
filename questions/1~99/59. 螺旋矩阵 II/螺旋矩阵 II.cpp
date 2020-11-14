/* 螺旋矩阵 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i, j, rowStart = 0, rowEnd = n - 1, columnStart = 0, columnEnd = n - 1, num = 1;
        vector<vector<int>> spiralNums(n, vector<int>(n));

        while ((rowEnd >= rowStart) && (columnEnd >= columnStart)) {
            for (j = columnStart; j <= columnEnd; j++) {
                spiralNums[rowStart][j] = num++;
            }

            for (i = rowStart + 1; i <= rowEnd; i++) {
                spiralNums[i][columnEnd] = num++;
            }

            for (j = columnEnd - 1; j >= columnStart; j--) {
                spiralNums[rowEnd][j] = num++;
            }

            for (i = rowEnd - 1; i > rowStart; i--) {
                spiralNums[i][columnStart] = num++;
            }

            rowStart++;
            rowEnd--;
            columnStart++;
            columnEnd--;
        }

        return spiralNums;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> actual = o.generateMatrix(1);
    vector<vector<int>> expected = { {1} };
    check.checkIntVectorVector(expected, actual);
    
    actual = o.generateMatrix(2);
    expected = { {1,2},{4,3} };
    check.checkIntVectorVector(expected, actual);

    actual = o.generateMatrix(3);
    expected = { {1,2,3},{8,9,4},{7,6,5} };
    check.checkIntVectorVector(expected, actual);

    actual = o.generateMatrix(4);
    expected = { {1,2,3,4},{12,13,14,5},{11,16,15,6},{10,9,8,7} };
    check.checkIntVectorVector(expected, actual);

    actual = o.generateMatrix(5);
    expected = { {1,2,3,4,5},{16,17,18,19,6},{15,24,25,20,7},{14,23,22,21,8},{13,12,11,10,9} };
    check.checkIntVectorVector(expected, actual);
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
