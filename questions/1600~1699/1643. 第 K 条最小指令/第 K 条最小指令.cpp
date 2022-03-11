/* 第 K 条最小指令.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Bob 站在单元格 (0, 0) ，想要前往目的地 destination ：(row, column) 。他只能向 右 或向 下 走。你可以为 Bob 提供导航 指令 来帮助他到达目的地 destination 。

指令 用字符串表示，其中每个字符：

'H' ，意味着水平向右移动
'V' ，意味着竖直向下移动
能够为 Bob 导航到目的地 destination 的指令可以有多种，例如，如果目的地 destination 是 (2, 3)，"HHHVV" 和 "HVHVH" 都是有效 指令 。

然而，Bob 很挑剔。因为他的幸运数字是 k，他想要遵循 按字典序排列后的第 k 条最小指令 的导航前往目的地 destination 。k  的编号 从 1 开始 。

给你一个整数数组 destination 和一个整数 k ，请你返回可以为 Bob 提供前往目的地 destination 导航的 按字典序排列后的第 k 条最小指令 。

 

示例 1：



输入：destination = [2,3], k = 1
输出："HHHVV"
解释：能前往 (2, 3) 的所有导航指令 按字典序排列后 如下所示：
["HHHVV", "HHVHV", "HHVVH", "HVHHV", "HVHVH", "HVVHH", "VHHHV", "VHHVH", "VHVHH", "VVHHH"].
示例 2：



输入：destination = [2,3], k = 2
输出："HHVHV"
示例 3：



输入：destination = [2,3], k = 3
输出："HHVVH"
 

提示：

destination.length == 2
1 <= row, column <= 15
1 <= k <= nCr(row + column, row)，其中 nCr(a, b) 表示组合数，即从 a 个物品中选 b 个物品的不同方案数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-instructions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int row = destination[0], column = destination[1];
        vector<vector<int>> combinations(row + column, vector<int>(column, 0));
        string path;

        getCombination(combinations);

        while (row != 0 && column != 0) {
            int ways = combinations[row + column - 1][column - 1];  // 假设第一个字符是H，那么剩下字符有ways种排序

            if (k > ways) {  // k比ways还大，说明第一个字符不能选H，只能选V，同时消耗掉了ways种排序
                path += 'V';
                row -= 1;
                k -= ways;
            }
            else {  // k比ways小，第一个字符选H，在剩下的字符中找第k个排序
                path += 'H';
                column -= 1;
            }
        }

        path += string(row, 'V');
        path += string(column, 'H');

        return path;
    }

    void getCombination(vector<vector<int>>& combinations) {
        // c(n, k) = c(n - 1, k - 1) + c(n - 1, k)
        int n, k, r = combinations.size(), c = combinations[0].size();
        combinations[0][0] = 1;

        for (n = 1; n < r; ++n) {
            combinations[n][0] = 1;

            for (k = 1; k < c && k <= n; ++k) {
                combinations[n][k] = combinations[n - 1][k - 1] + combinations[n - 1][k];
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> destination = { 2,3 };
    check.checkString("HHHVV", o.kthSmallestPath(destination, 1));

    destination = { 2,3 };
    check.checkString("HHVHV", o.kthSmallestPath(destination, 2));

    destination = { 2,3 };
    check.checkString("HHVVH", o.kthSmallestPath(destination, 3));

    destination = { 1,1 };
    check.checkString("HV", o.kthSmallestPath(destination, 1));

    destination = { 1,1 };
    check.checkString("VH", o.kthSmallestPath(destination, 2));

    destination = { 15,15 };
    check.checkString("HVVVVVVVVVVVVVVVHHHHHHHHHHHHHH", o.kthSmallestPath(destination, 77558760));

    destination = { 15,15 };
    check.checkString("VHHHHHHHHHHHHHHHVVVVVVVVVVVVVV", o.kthSmallestPath(destination, 77558761));

    destination = { 15,15 };
    check.checkString("HHHHHHHHVVHHVVVVHVVHHVVVHVVHVV", o.kthSmallestPath(destination, 99999));

    destination = { 15,15 };
    check.checkString("VVVVVVVVVVVVVVVHHHHHHHHHHHHHHH", o.kthSmallestPath(destination, 155117520));
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
