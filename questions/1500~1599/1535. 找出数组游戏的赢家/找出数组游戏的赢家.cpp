/* 找出数组游戏的赢家.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由 不同 整数组成的整数数组 arr 和一个整数 k 。

每回合游戏都在数组的前两个元素（即 arr[0] 和 arr[1] ）之间进行。比较 arr[0] 与 arr[1] 的大小，较大的整数将会取得这一回合的胜利并保留在位置 0 ，较小的整数移至数组的末尾。当一个整数赢得 k 个连续回合时，游戏结束，该整数就是比赛的 赢家 。

返回赢得比赛的整数。

题目数据 保证 游戏存在赢家。

 

示例 1：

输入：arr = [2,1,3,5,4,6,7], k = 2
输出：5
解释：一起看一下本场游戏每回合的情况：

因此将进行 4 回合比赛，其中 5 是赢家，因为它连胜 2 回合。
示例 2：

输入：arr = [3,2,1], k = 10
输出：3
解释：3 将会在前 10 个回合中连续获胜。
示例 3：

输入：arr = [1,9,8,2,3,7,6,4,5], k = 7
输出：9
示例 4：

输入：arr = [1,11,22,33,44,55,66,77,88,99], k = 1000000000
输出：99
 

提示：

2 <= arr.length <= 10^5
1 <= arr[i] <= 10^6
arr 所含的整数 各不相同 。
1 <= k <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-winner-of-an-array-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner = arr[0], times = -1;

        for (int num : arr) {
            if (num > winner) {
                winner = num;
                times = 1;
            }
            else {
                ++times;
            }

            if (times == k) {
                break;
            }
        }

        return winner;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 2,1,3,5,4,6,7 };
    check.checkInt(5, o.getWinner(arr, 2));
    check.checkInt(2, o.getWinner(arr, 1));

    arr = { 3,2,1 };
    check.checkInt(3, o.getWinner(arr, 10));
    check.checkInt(3, o.getWinner(arr, 1));

    arr = { 1,9,8,2,3,7,6,4,5 };
    check.checkInt(9, o.getWinner(arr, 7));
    check.checkInt(9, o.getWinner(arr, 1));

    arr = { 1,11,22,33,44,55,66,77,88,99 };
    check.checkInt(99, o.getWinner(arr, 1000000000));
    check.checkInt(11, o.getWinner(arr, 1));
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
