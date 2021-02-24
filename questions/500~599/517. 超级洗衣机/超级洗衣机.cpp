/* 超级洗衣机.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
假设有 n 台超级洗衣机放在同一排上。开始的时候，每台洗衣机内可能有一定量的衣服，也可能是空的。

在每一步操作中，你可以选择任意 m （1 ≤ m ≤ n） 台洗衣机，与此同时将每台洗衣机的一件衣服送到相邻的一台洗衣机。

给定一个非负整数数组代表从左至右每台洗衣机中的衣物数量，请给出能让所有洗衣机中剩下的衣物的数量相等的最少的操作步数。如果不能使每台洗衣机中衣物的数量相等，则返回 -1。

 

示例 1：

输入: [1,0,5]

输出: 3

解释:
第一步:    1     0 <-- 5    =>    1     1     4
第二步:    1 <-- 1 <-- 4    =>    2     1     3
第三步:    2     1 <-- 3    =>    2     2     2
示例 2：

输入: [0,3,0]

输出: 2

解释:
第一步:    0 <-- 3     0    =>    1     2     0
第二步:    1     2 --> 0    =>    1     1     1
示例 3:

输入: [0,2,0]

输出: -1

解释:
不可能让所有三个洗衣机同时剩下相同数量的衣物。
 

提示：

n 的范围是 [1, 10000]。
在每台超级洗衣机中，衣物数量的范围是 [0, 1e5]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/super-washing-machines
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int i, size = machines.size(), sum = getSum(machines), average = sum / size;
        if (average * size != sum) {
            return -1;
        }

        int left = machines[0], wantedLeft = average, right, wantedRight = average * (size - 2);
        int minMoves = max(abs(machines[0] - average), abs(machines[size - 1] - average));

        for (i = 1; i < size - 1; ++i) {
            int num = machines[i];
            right = sum - num - left;

            if (num >= average) {
                int moves = num - average;
                if (left > wantedLeft) {
                    moves += (left - wantedLeft);
                }
                if (right > wantedRight) {
                    moves += (right - wantedRight);
                }
                minMoves = max(minMoves, moves);

            }

            left += num;
            wantedLeft += average;
            wantedRight -= average;
        }

        return minMoves;
    }

    int getSum(vector<int>& machines) {
        int sum = 0;

        for (int num : machines) {
            sum += num;
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> machines = { 1,0,5 };
    check.checkInt(3, o.findMinMoves(machines));

    machines = { 0,3,0 };
    check.checkInt(2, o.findMinMoves(machines));

    machines = { 0,2,1,2,0 };
    check.checkInt(1, o.findMinMoves(machines));

    machines = { 0,2,0 };
    check.checkInt(-1, o.findMinMoves(machines));

    machines = { 5,5,1,1 };
    check.checkInt(4, o.findMinMoves(machines));

    machines = { 5,1,4,1,6,1 };
    check.checkInt(3, o.findMinMoves(machines));

    machines = { 9,1,8,8,9 };
    check.checkInt(4, o.findMinMoves(machines));

    machines = { 0,0,11,5 };
    check.checkInt(8, o.findMinMoves(machines));

    machines = { 4,0,0,4 };
    check.checkInt(2, o.findMinMoves(machines));

    machines = { 1 };
    check.checkInt(0, o.findMinMoves(machines));

    machines = { 2,2 };
    check.checkInt(0, o.findMinMoves(machines));

    machines = { 2,4 };
    check.checkInt(1, o.findMinMoves(machines));
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
