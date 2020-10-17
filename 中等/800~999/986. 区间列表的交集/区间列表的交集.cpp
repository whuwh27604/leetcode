/* 区间列表的交集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个由一些 闭区间 组成的列表，每个区间列表都是成对不相交的，并且已经排序。

返回这两个区间列表的交集。

（形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <= b。两个闭区间的交集是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3]。）

 

示例：



输入：A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
输出：[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 

提示：

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/interval-list-intersections
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i = 0, j = 0, sizeA = A.size(), sizeB = B.size();
        vector<vector<int>> intersections;

        while (i < sizeA && j < sizeB) {  // 比较右端点的位置，小的那个跳到下一个区段。过程中如果有交集就加入到答案。
            int intersectionLeft = max(A[i][0], B[j][0]);

            if (A[i][1] < B[j][1]) {
                if (B[j][0] <= A[i][1]) {
                    intersections.push_back({ intersectionLeft,A[i][1] });
                }
                ++i;
            }
            else if (A[i][1] == B[j][1]) {
                intersections.push_back({ intersectionLeft,A[i][1] });
                ++i;
                ++j;
            }
            else {
                if (B[j][1] >= A[i][0]) {
                    intersections.push_back({ intersectionLeft,B[j][1] });
                }
                ++j;
            }
        }

        return intersections;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> A = { {0,2},{5,10},{13,23},{24,25} };
    vector<vector<int>> B = { {1,5},{8,12},{15,24},{25,26} };
    vector<vector<int>> actual = o.intervalIntersection(A, B);
    vector<vector<int>> expected = { {1,2},{5,5},{8,10},{15,23},{24,24},{25,25} };
    check.checkIntVectorVector(expected, actual);

    A = {  };
    B = {  };
    actual = o.intervalIntersection(A, B);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    A = {  };
    B = { {1,2} };
    actual = o.intervalIntersection(A, B);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    A = { {5,6} };
    B = { {1,2} };
    actual = o.intervalIntersection(A, B);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    A = { {0,1} };
    B = { {0,1} };
    actual = o.intervalIntersection(A, B);
    expected = { {0,1} };
    check.checkIntVectorVector(expected, actual);

    A = { {0,1} };
    B = { {1,2} };
    actual = o.intervalIntersection(A, B);
    expected = { {1,1} };
    check.checkIntVectorVector(expected, actual);

    A = { {3,10} };
    B = { {5,10} };
    actual = o.intervalIntersection(A, B);
    expected = { {5,10} };
    check.checkIntVectorVector(expected, actual);

    A = { {1,3},{5,7},{9,11} };
    B = { {3,5},{7,9},{11,13} };
    actual = o.intervalIntersection(A, B);
    expected = { {3,3},{5,5},{7,7},{9,9},{11,11} };
    check.checkIntVectorVector(expected, actual);

    A = { {3,5},{9,20} };
    B = { {4,5},{7,10},{11,12},{14,15},{16,20} };
    actual = o.intervalIntersection(A, B);
    expected = { {4,5},{9,10},{11,12},{14,15},{16,20} };
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
