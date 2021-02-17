/* 最大子矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个正整数、负整数和 0 组成的 N × M 矩阵，编写代码找出元素总和最大的子矩阵。

返回一个数组 [r1, c1, r2, c2]，其中 r1, c1 分别代表子矩阵左上角的行号和列号，r2, c2 分别代表右下角的行号和列号。若有多个满足条件的子矩阵，返回任意一个均可。

注意：本题相对书上原题稍作改动

示例：

输入：
[
   [-1,0],
   [0,-1]
]
输出：[0,1,0,1]
解释：输入中标粗的元素即为输出所表示的矩阵
 

说明：

1 <= matrix.length, matrix[0].length <= 200

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-submatrix-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), column = matrix[0].size(), submatrixSum = 0, maxSubmatrixSum = INT_MIN;
        vector<int> indices(4);

        for (int cStart = 0; cStart < column; ++cStart) {
            vector<int> rowSums(row, 0);

            for (int cEnd = cStart; cEnd < column; ++cEnd) {
                int rStart = 0;
                submatrixSum = 0;

                for (int rEnd = 0; rEnd < row; ++rEnd) {
                    rowSums[rEnd] += matrix[rEnd][cEnd];
                    submatrixSum += rowSums[rEnd];

                    if (submatrixSum > maxSubmatrixSum) {
                        maxSubmatrixSum = submatrixSum;
                        indices = { rStart,cStart,rEnd,cEnd };
                    }

                    if (submatrixSum < 0) {
                        submatrixSum = 0;
                        rStart = rEnd + 1;
                    }
                }
            }
        }

        return indices;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> matrix = { {-1,0},{0,-1} };
    vector<int> actual = o.getMaxMatrix(matrix);
    vector<int> expected = { 1,0,1,0 };
    check.checkIntVector(expected, actual);

    matrix = { {-3,-2},{-1,-5} };
    actual = o.getMaxMatrix(matrix);
    expected = { 1,0,1,0 };
    check.checkIntVector(expected, actual);

    matrix = { {3,2},{1,5} };
    actual = o.getMaxMatrix(matrix);
    expected = { 0,0,1,1 };
    check.checkIntVector(expected, actual);

    matrix = { {-5} };
    actual = o.getMaxMatrix(matrix);
    expected = { 0,0,0,0 };
    check.checkIntVector(expected, actual);

    matrix = { {5} };
    actual = o.getMaxMatrix(matrix);
    expected = { 0,0,0,0 };
    check.checkIntVector(expected, actual);

    matrix = { {9,-8,1,3,-2},{-3,7,6,-2,4},{6,-4,-4,8,-7} };
    actual = o.getMaxMatrix(matrix);
    expected = { 0,0,2,3 };
    check.checkIntVector(expected, actual);

    matrix = {{-5208,1041,-93779,-64152,17850,29055,-63731,-23568,41170,58457,-39616,55683,-51662,-75015,21726},{4535,-72412,86878,-60825,67088,48794,-23471,-22403,58200,-31153,-94668,-27274,-11003,33894,-66125},{-9538,-33861,54822,42636,48430,-56030,-33348,-30617,5219,56501,-95879,-73537,-18157,-72815,-40977},{15602,40115,-32475,99011,47251,84035,83793,-74389,-99042,65460,11671,-95294,68311,47893,71866},{69607,57288,55022,36610,-75113,31344,34319,-13381,-74800,-71904,-15625,-5398,-29689,-68805,-41994},{-32276,95017,-96452,-47311,13238,46324,95358,13247,-30930,5815,-36748,-25712,-83982,29391,-73922},{-29140,-70403,-3168,12219,-4473,-10013,-85502,87222,-44858,66506,-99821,-16992,-80758,59210,87145},{-9557,67725,-27359,-28647,46781,-67948,-28154,-3498,91489,-3887,-96422,6568,42380,73264,-55406},{40555,70153,-51490,-14237,9684,-54000,-8443,-32063,-96157,-70083,-7050,56221,93013,-1157,-45593},{-28686,-54296,628,11189,18227,-64455,-10528,-69244,94796,-39806,69194,45024,-14417,-51291,6387},{-28485,36898,97259,-83875,83650,-36715,80692,-55055,40025,-69379,-1548,-13045,23318,79349,-42774},{82645,17721,84052,-35036,-751,90269,-77187,51972,-90217,-5956,-34552,95560,40436,51650,72778},{-970,77788,10423,-1406,-90844,6732,-60197,59393,-82111,33737,-4731,-52679,-12011,69741,-91931}};
    actual = o.getMaxMatrix(matrix);
    expected = { 1,0,5,6 };
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
