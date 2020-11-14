/* 连续差相同的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
返回所有长度为 N 且满足其每两个连续位上的数字之间的差的绝对值为 K 的非负整数。

请注意，除了数字 0 本身之外，答案中的每个数字都不能有前导零。例如，01 因为有一个前导零，所以是无效的；但 0 是有效的。

你可以按任何顺序返回答案。

 

示例 1：

输入：N = 3, K = 7
输出：[181,292,707,818,929]
解释：注意，070 不是一个有效的数字，因为它有前导零。
示例 2：

输入：N = 2, K = 1
输出：[10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

提示：

1 <= N <= 9
0 <= K <= 9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/numbers-with-same-consecutive-differences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int> bfs;
        for (int i = 1; i <= 9; ++i) {
            bfs.push(i);
        }

        for (int i = 1; i < n; ++i) {
            int size = bfs.size();

            for (int j = 0; j < size; ++j) {
                int num = bfs.front();
                bfs.pop();

                int digit = num % 10;
                if (digit >= k) {
                    bfs.push(num * 10 + digit - k);
                }

                if (k != 0 && digit + k <= 9) {
                    bfs.push(num * 10 + digit + k);
                }
            }
        }

        vector<int> nums;
        while (!bfs.empty()) {
            nums.push_back(bfs.front());
            bfs.pop();
        }

        if (n == 1) {
            nums.push_back(0);
        }

        return nums;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.numsSameConsecDiff(3, 7);
    vector<int> expected = { 181,292,707,818,929 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.numsSameConsecDiff(2, 1);
    expected = { 10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.numsSameConsecDiff(1, 2);
    expected = { 0,1,2,3,4,5,6,7,8,9 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.numsSameConsecDiff(3, 0);
    expected = { 111,222,333,444,555,666,777,888,999 };
    check.checkIntVectorRandomOrder(expected, actual);
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
