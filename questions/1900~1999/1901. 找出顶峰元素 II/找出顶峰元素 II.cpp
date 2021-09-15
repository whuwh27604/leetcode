/* 找出顶峰元素 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个 2D 网格中的 顶峰元素 是指那些 严格大于 其相邻格子(上、下、左、右)的元素。

给你一个 从 0 开始编号 的 m x n 矩阵 mat ，其中任意两个相邻格子的值都 不相同 。找出 任意一个 顶峰元素 mat[i][j] 并 返回其位置 [i,j] 。

你可以假设整个矩阵周边环绕着一圈值为 -1 的格子。

要求必须写出时间复杂度为 O(m log(n)) 或 O(n log(m)) 的算法

 

 

示例 1:



输入: mat = [[1,4],[3,2]]
输出: [0,1]
解释: 3和4都是顶峰元素，所以[1,0]和[0,1]都是可接受的答案。
示例 2:



输入: mat = [[10,20,15],[21,30,14],[7,16,32]]
输出: [1,1]
解释: 30和32都是顶峰元素，所以[1,1]和[2,2]都是可接受的答案。
 

提示：

m == mat.length
n == mat[i].length
1 <= m, n <= 500
1 <= mat[i][j] <= 105
任意两个相邻元素均不相等.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-a-peak-element-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size(), column = mat[0].size(), low = 0, high = row - 1, middle = 0, cIndex = 0;

        while (low <= high) {
            middle = (low + high) / 2;

            int upMax = -1;
            if (middle != 0) {
                upMax = getRowMax(mat, middle - 1, cIndex);
            }

            int downMax = -1;
            if (middle != row - 1) {
                downMax = getRowMax(mat, middle + 1, cIndex);
            }

            int rowMax = getRowMax(mat, middle, cIndex);
            if (rowMax >= upMax && rowMax >= downMax) {
                break;
            }
            else if (upMax > rowMax) {
                high = middle - 1;
            }
            else {
                low = middle + 1;
            }
        }

        return { middle, cIndex };
    }

    int getRowMax(vector<vector<int>>& mat, int r, int& c) {
        int rowMax = 0;

        for (int j = 0; j < (int)mat[0].size(); ++j) {
            if (mat[r][j] > rowMax) {
                rowMax = mat[r][j];
                c = j;
            }
        }

        return rowMax;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> mat = { {1,4},{3,2} };
    vector<int> actual = o.findPeakGrid(mat);
    vector<int> expected = { 0,1 };
    check.checkIntVector(expected, actual);
    
    mat = { {10,20,15},{21,30,14},{7,16,32} };
    actual = o.findPeakGrid(mat);
    expected = { 2,2 };
    check.checkIntVector(expected, actual);

    mat = { {10} };
    actual = o.findPeakGrid(mat);
    expected = { 0,0 };
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
