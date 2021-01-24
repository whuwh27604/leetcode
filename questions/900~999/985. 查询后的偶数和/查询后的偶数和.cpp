/* 查询后的偶数和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出一个整数数组 A 和一个查询数组 queries。

对于第 i 次查询，有 val = queries[i][0], index = queries[i][1]，我们会把 val 加到 A[index] 上。然后，第 i 次查询的答案是 A 中偶数值的和。

（此处给定的 index = queries[i][1] 是从 0 开始的索引，每次查询都会永久修改数组 A。）

返回所有查询的答案。你的答案应当以数组 answer 给出，answer[i] 为第 i 次查询的答案。

 

示例：

输入：A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
输出：[8,6,2,4]
解释：
开始时，数组为 [1,2,3,4]。
将 1 加到 A[0] 上之后，数组为 [2,2,3,4]，偶数值之和为 2 + 2 + 4 = 8。
将 -3 加到 A[1] 上之后，数组为 [2,-1,3,4]，偶数值之和为 2 + 4 = 6。
将 -4 加到 A[0] 上之后，数组为 [-2,-1,3,4]，偶数值之和为 -2 + 4 = 2。
将 2 加到 A[3] 上之后，数组为 [-2,-1,3,6]，偶数值之和为 -2 + 6 = 4。
 

提示：

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
1 <= queries.length <= 10000
-10000 <= queries[i][0] <= 10000
0 <= queries[i][1] < A.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-even-numbers-after-queries
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> sumEven(queries.size());
        int sum = 0;

        for (int num : A) {
            if ((num & 1) == 0) {
                sum += num;
            }
        }

        for (unsigned int i = 0; i < queries.size(); ++i) {
            int index = queries[i][1];
            if ((A[index] & 1) == 0) {
                sum -= A[index];
            }

            A[index] += queries[i][0];
            if ((A[index] & 1) == 0) {
                sum += A[index];
            }

            sumEven[i] = sum;
        }

        return sumEven;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 1,2,3,4 };
    vector<vector<int>> queries = { {1,0},{-3,1},{-4,0},{2,3} };
    vector<int> actual = o.sumEvenAfterQueries(A, queries);
    vector<int> expected = { 8,6,2,4 };
    check.checkIntVector(expected, actual);

    A = { -5 };
    queries = { {1,0} };
    actual = o.sumEvenAfterQueries(A, queries);
    expected = { -4 };
    check.checkIntVector(expected, actual);

    A = { -5 };
    queries = { {0,0} };
    actual = o.sumEvenAfterQueries(A, queries);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    A = { -5 };
    queries = { {1,0},{2,0},{3,0},{4,0} };
    actual = o.sumEvenAfterQueries(A, queries);
    expected = { -4,-2,0,0 };
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
