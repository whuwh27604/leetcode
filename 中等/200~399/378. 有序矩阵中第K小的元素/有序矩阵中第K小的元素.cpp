/* 有序矩阵中第K小的元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。

 

示例：

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
 

提示：
你可以假设 k 的值永远是有效的，1 ≤ k ≤ n2 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), lessEqualMiddle = 0, middle = 0;
        long long left = matrix[0][0], right = matrix[n - 1][n - 1];

        while (left <= right) {
            middle = (int)((left + right) / 2);
            lessEqualMiddle = countLessEqualMiddle(matrix, n, middle);
            if (lessEqualMiddle == k) {
                break;
            }

            if (lessEqualMiddle < k) {
                left = middle + 1;
                continue;
            }

            // lessEqualMiddle > k的情况下，要尝试一下middle-1，否则middle-1这个数多次重复的情况下直接right = middle - 1会错过答案
            if (middle == left) {
                break;
            }

            lessEqualMiddle = countLessEqualMiddle(matrix, n, middle - 1);
            if (lessEqualMiddle < k) {
                return middle;  // lessEqualMiddle(middle-1)<k && lessEqualMiddle(middle)>k，说明middle就是答案
            }
            right = middle - 1;
        }

        return findTarget(matrix, n, middle);
    }

    int countLessEqualMiddle(vector<vector<int>>& matrix, int n, int middle) {
        int i = n - 1, j = 0, sum = 0;

        // 所有小于middle的数在数组的左上角，大于middle的数在数组的右下角
        while ((i >= 0) && (j < n)) {
            if (matrix[i][j] <= middle) {
                j++;
            }
            else {
                i--;
                sum += j;
            }
        }

        if (i >= 0) {
            sum += ((i + 1) * n);
        }

        return sum;
    }

    int findTarget(vector<vector<int>>& matrix, int n, int middle) {
        int i = n - 1, j = 0, target = INT_MIN;

        while ((i >= 0) && (j < n)) {
            if (matrix[i][j] <= middle) {
                target = (target > matrix[i][j] ? target : matrix[i][j]);
                j++;
            }
            else {
                i--;
            }
        }

        return target;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> matrix = { {5} };
    check.checkInt(5, o.kthSmallest(matrix, 1));

    matrix = { {1,5},{10,20} };
    check.checkInt(1, o.kthSmallest(matrix, 1));
    check.checkInt(5, o.kthSmallest(matrix, 2));
    check.checkInt(10, o.kthSmallest(matrix, 3));
    check.checkInt(20, o.kthSmallest(matrix, 4));

    matrix = { {-3,-2},{-3,-2} };
    check.checkInt(-3, o.kthSmallest(matrix, 1));
    check.checkInt(-3, o.kthSmallest(matrix, 2));
    check.checkInt(-2, o.kthSmallest(matrix, 3));
    check.checkInt(-2, o.kthSmallest(matrix, 4));

    matrix = { {1,5,9},{10,11,13},{12,13,15} };
    check.checkInt(1, o.kthSmallest(matrix, 1));
    check.checkInt(5, o.kthSmallest(matrix, 2));
    check.checkInt(9, o.kthSmallest(matrix, 3));
    check.checkInt(10, o.kthSmallest(matrix, 4));
    check.checkInt(11, o.kthSmallest(matrix, 5));
    check.checkInt(12, o.kthSmallest(matrix, 6));
    check.checkInt(13, o.kthSmallest(matrix, 7));
    check.checkInt(13, o.kthSmallest(matrix, 8));
    check.checkInt(15, o.kthSmallest(matrix, 9));

    matrix = { {INT_MIN,0,10},{-2,0,100},{-1,0,INT_MAX} };
    check.checkInt(INT_MIN, o.kthSmallest(matrix, 1));
    check.checkInt(-2, o.kthSmallest(matrix, 2));
    check.checkInt(-1, o.kthSmallest(matrix, 3));
    check.checkInt(0, o.kthSmallest(matrix, 4));
    check.checkInt(0, o.kthSmallest(matrix, 5));
    check.checkInt(0, o.kthSmallest(matrix, 6));
    check.checkInt(10, o.kthSmallest(matrix, 7));
    check.checkInt(100, o.kthSmallest(matrix, 8));
    check.checkInt(INT_MAX, o.kthSmallest(matrix, 9));

    matrix = { {INT_MIN,INT_MIN,5,7,9,11},{2,4,6,8,10,12},{3,5,7,9,11,13},{4,6,8,10,12,14},{5,7,9,11,13,15},{6,8,10,12,INT_MAX,INT_MAX} };
    check.checkInt(INT_MIN, o.kthSmallest(matrix, 1));
    check.checkInt(INT_MIN, o.kthSmallest(matrix, 2));
    check.checkInt(2, o.kthSmallest(matrix, 3));
    check.checkInt(3, o.kthSmallest(matrix, 4));
    check.checkInt(4, o.kthSmallest(matrix, 5));
    check.checkInt(4, o.kthSmallest(matrix, 6));
    check.checkInt(5, o.kthSmallest(matrix, 7));
    check.checkInt(5, o.kthSmallest(matrix, 8));
    check.checkInt(5, o.kthSmallest(matrix, 9));
    check.checkInt(6, o.kthSmallest(matrix, 10));
    check.checkInt(6, o.kthSmallest(matrix, 11));
    check.checkInt(6, o.kthSmallest(matrix, 12));
    check.checkInt(7, o.kthSmallest(matrix, 13));
    check.checkInt(7, o.kthSmallest(matrix, 14));
    check.checkInt(7, o.kthSmallest(matrix, 15));
    check.checkInt(8, o.kthSmallest(matrix, 16));
    check.checkInt(8, o.kthSmallest(matrix, 17));
    check.checkInt(8, o.kthSmallest(matrix, 18));
    check.checkInt(9, o.kthSmallest(matrix, 19));
    check.checkInt(9, o.kthSmallest(matrix, 20));
    check.checkInt(9, o.kthSmallest(matrix, 21));
    check.checkInt(10, o.kthSmallest(matrix, 22));
    check.checkInt(10, o.kthSmallest(matrix, 23));
    check.checkInt(10, o.kthSmallest(matrix, 24));
    check.checkInt(11, o.kthSmallest(matrix, 25));
    check.checkInt(11, o.kthSmallest(matrix, 26));
    check.checkInt(11, o.kthSmallest(matrix, 27));
    check.checkInt(12, o.kthSmallest(matrix, 28));
    check.checkInt(12, o.kthSmallest(matrix, 29));
    check.checkInt(12, o.kthSmallest(matrix, 30));
    check.checkInt(13, o.kthSmallest(matrix, 31));
    check.checkInt(13, o.kthSmallest(matrix, 32));
    check.checkInt(14, o.kthSmallest(matrix, 33));
    check.checkInt(15, o.kthSmallest(matrix, 34));
    check.checkInt(INT_MAX, o.kthSmallest(matrix, 35));
    check.checkInt(INT_MAX, o.kthSmallest(matrix, 36));
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
