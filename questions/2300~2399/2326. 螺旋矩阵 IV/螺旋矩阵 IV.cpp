/* 螺旋矩阵 IV.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数：m 和 n ，表示矩阵的维数。

另给你一个整数链表的头节点 head 。

请你生成一个大小为 m x n 的螺旋矩阵，矩阵包含链表中的所有整数。链表中的整数从矩阵 左上角 开始、顺时针 按 螺旋 顺序填充。如果还存在剩余的空格，则用 -1 填充。

返回生成的矩阵。

 

示例 1：


输入：m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
输出：[[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
解释：上图展示了链表中的整数在矩阵中是如何排布的。
注意，矩阵中剩下的空格用 -1 填充。
示例 2：


输入：m = 1, n = 4, head = [0,1,2]
输出：[[0,1,2,-1]]
解释：上图展示了链表中的整数在矩阵中是如何从左到右排布的。
注意，矩阵中剩下的空格用 -1 填充。
 

提示：

1 <= m, n <= 105
1 <= m * n <= 105
链表中节点数目在范围 [1, m * n] 内
0 <= Node.val <= 1000

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/spiral-matrix-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n));
        ListNode* node = head;

        for (int circle = 0; m > 2 * circle && n > 2 * circle; ++circle) {
            int rStart = circle, cStart = circle, rEnd = m - 1 - circle, cEnd = n - 1 - circle, r, c;

            for (r = rStart, c = cStart; c <= cEnd; ++c) {
                if (node == NULL) {
                    matrix[r][c] = -1;
                }
                else {
                    matrix[r][c] = node->val;
                    node = node->next;
                }
            }

            for (r = rStart + 1, c = cEnd; r < rEnd; ++r) {
                if (node == NULL) {
                    matrix[r][c] = -1;
                }
                else {
                    matrix[r][c] = node->val;
                    node = node->next;
                }
            }

            if (rStart != rEnd) {
                for (r = rEnd, c = cEnd; c >= cStart; --c) {
                    if (node == NULL) {
                        matrix[r][c] = -1;
                    }
                    else {
                        matrix[r][c] = node->val;
                        node = node->next;
                    }
                }
            }

            if (cStart != cEnd) {
                for (r = rEnd - 1, c = cStart; r > rStart; --r) {
                    if (node == NULL) {
                        matrix[r][c] = -1;
                    }
                    else {
                        matrix[r][c] = node->val;
                        node = node->next;
                    }
                }
            }
        }

        return matrix;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 3,0,2,6,8,1,7,9,4,2,5,5,0 };
    vector<vector<int>> actual = o.spiralMatrix(3, 5, createList(values));
    vector<vector<int>> expected = { {3,0,2,6,8},{5,0,-1,-1,1},{5,2,4,9,7} };
    check.checkIntVectorVector(expected, actual);

    values = { 0,1,2 };
    actual = o.spiralMatrix(1, 4, createList(values));
    expected = { {0,1,2,-1} };
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
