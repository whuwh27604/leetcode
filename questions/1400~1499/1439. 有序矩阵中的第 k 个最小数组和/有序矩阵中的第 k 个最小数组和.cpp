/* 有序矩阵中的第 k 个最小数组和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m * n 的矩阵 mat，以及一个整数 k ，矩阵中的每一行都以非递减的顺序排列。

你可以从每一行中选出 1 个元素形成一个数组。返回所有可能数组中的第 k 个 最小 数组和。

 

示例 1：

输入：mat = [[1,3,11],[2,4,6]], k = 5
输出：7
解释：从每一行中选出一个元素，前 k 个和最小的数组分别是：
[1,2], [1,4], [3,2], [3,4], [1,6]。其中第 5 个的和是 7 。
示例 2：

输入：mat = [[1,3,11],[2,4,6]], k = 9
输出：17
示例 3：

输入：mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
输出：9
解释：从每一行中选出一个元素，前 k 个和最小的数组分别是：
[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]。其中第 7 个的和是 9 。
示例 4：

输入：mat = [[1,1,10],[2,2,9]], k = 7
输出：12
 

提示：

m == mat.length
n == mat.length[i]
1 <= m, n <= 40
1 <= k <= min(200, n ^ m)
1 <= mat[i][j] <= 5000
mat[i] 是一个非递减数组

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int i, row = mat.size(), column = mat[0].size();
        vector<int> sumIndices(row + 1, 0);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> nodes;
        unordered_set<string> visited;

        for (i = 0; i < row; ++i) {
            sumIndices[0] += mat[i][0];
        }

        nodes.push(sumIndices);

        for (k -= 1; k > 0; --k) {
            sumIndices = nodes.top();
            nodes.pop();

            for (i = 1; i <= row; ++i) {
                vector<int> next = sumIndices;

                if (++next[i] >= column) {
                    continue;
                }

                next[0] += (mat[i - 1][next[i]] - mat[i - 1][next[i] - 1]);
                string key = hash(next);

                if (visited.count(key) == 0) {
                    visited.insert(key);
                    nodes.push(next);
                }
            }
        }

        return nodes.top()[0];
    }

    string hash(vector<int>& nums) {
        string key;

        for (int num : nums) {
            key += to_string(num);
        }

        return key;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> mat = { {1,3,11},{2,4,6} };
    check.checkInt(3, o.kthSmallest(mat, 1));
    check.checkInt(5, o.kthSmallest(mat, 2));
    check.checkInt(5, o.kthSmallest(mat, 3));
    check.checkInt(7, o.kthSmallest(mat, 4));
    check.checkInt(7, o.kthSmallest(mat, 5));
    check.checkInt(9, o.kthSmallest(mat, 6));
    check.checkInt(13, o.kthSmallest(mat, 7));
    check.checkInt(15, o.kthSmallest(mat, 8));
    check.checkInt(17, o.kthSmallest(mat, 9));

    mat = { {1,3,11},{2,4,6} };
    check.checkInt(17, o.kthSmallest(mat, 9));

    mat = { {1,10,10},{1,4,5},{2,3,6} };
    check.checkInt(9, o.kthSmallest(mat, 7));

    mat = { {1,1,10},{2,2,9} };
    check.checkInt(12, o.kthSmallest(mat, 7));
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
