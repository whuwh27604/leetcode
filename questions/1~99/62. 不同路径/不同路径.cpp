/* 不同路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？



例如，上图是一个7 x 3 的网格。有多少可能的路径？

 

示例 1:

输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
示例 2:

输入: m = 7, n = 3
输出: 28
 

提示：

1 <= m, n <= 100
题目数据保证答案小于等于 2 * 10 ^ 9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 一共(m-1)+(n-1)步，在其中选择(m-1)步往右走
        // C(x,y)=P(x,y)/y!=x!/(x-y)!y!=C(x,x-y)
        int i, x = m + n - 2, y = min(m - 1, n - 1), z = max(m - 1, n - 1);
        long long paths = 1;

        for (i = z + 1; i <= x; i++) {
            paths *= i;
        }

        for (i = 2; i <= y; i++) {
            paths /= i;
        }

        return (int)paths;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(3, o.uniquePaths(3, 2));
    check.checkInt(28, o.uniquePaths(3, 7));
    check.checkInt(1, o.uniquePaths(1, 1));
    check.checkInt(1, o.uniquePaths(1, 2));
    check.checkInt(1, o.uniquePaths(2, 1));
    check.checkInt(1, o.uniquePaths(1, 5));
    check.checkInt(1, o.uniquePaths(5, 1));
    check.checkInt(5, o.uniquePaths(5, 2));
    check.checkInt(15, o.uniquePaths(5, 3));
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
