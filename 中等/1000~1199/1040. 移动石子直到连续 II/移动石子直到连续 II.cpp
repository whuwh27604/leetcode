/* 移动石子直到连续 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个长度无限的数轴上，第 i 颗石子的位置为 stones[i]。如果一颗石子的位置最小/最大，那么该石子被称作端点石子。

每个回合，你可以将一颗端点石子拿起并移动到一个未占用的位置，使得该石子不再是一颗端点石子。

值得注意的是，如果石子像 stones = [1,2,5] 这样，你将无法移动位于位置 5 的端点石子，因为无论将它移动到任何位置（例如 0 或 3），该石子都仍然会是端点石子。

当你无法进行任何移动时，即，这些石子的位置连续时，游戏结束。

要使游戏结束，你可以执行的最小和最大移动次数分别是多少？ 以长度为 2 的数组形式返回答案：answer = [minimum_moves, maximum_moves] 。

 

示例 1：

输入：[7,4,9]
输出：[1,2]
解释：
我们可以移动一次，4 -> 8，游戏结束。
或者，我们可以移动两次 9 -> 5，4 -> 6，游戏结束。
示例 2：

输入：[6,5,4,3,10]
输出：[2,3]
解释：
我们可以移动 3 -> 8，接着是 10 -> 7，游戏结束。
或者，我们可以移动 3 -> 7, 4 -> 8, 5 -> 9，游戏结束。
注意，我们无法进行 10 -> 2 这样的移动来结束游戏，因为这是不合要求的移动。
示例 3：

输入：[100,101,104,102,103]
输出：[0,0]
 

提示：

3 <= stones.length <= 10^4
1 <= stones[i] <= 10^9
stones[i] 的值各不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/moving-stones-until-consecutive-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        return { getMinMoves(stones), getMaxMoves(stones) };
    }

    int getMinMoves(vector<int>& stones) {
        int i, size = stones.size(), leftmost = 0, maxStonesInWindow = 0;

        // 1236或者1456需要两次，1235或者1345只需要一次
        if ((stones[size - 2] == stones[0] + size - 2 && stones[size - 1] - stones[size - 2] > 2)
            || (stones[1] + size - 2 == stones[size - 1] && stones[1] - stones[0] > 2)) {
            return 2;
        }

        for (i = 1; i < size; ++i) {  // 其它情况，保持window为size大小，总有办法通过size-stonesInWindow次移动，把窗口外的石头移到窗口内，并且这就是最小移动次数
            while (stones[i] - stones[leftmost] >= size) {
                ++leftmost;
            }

            maxStonesInWindow = max(maxStonesInWindow, i - leftmost + 1);
        }

        return size - maxStonesInWindow;
    }

    int getMaxMoves(vector<int>& stones) {
        int size = stones.size(), first = stones[0], second = stones[1], last = stones[size - 1], secondLast = stones[size - 2];

        // 贪心，第一步选择移动距离旁边一个石头近的，这样损失的空位最小，然后每次移动一步向另外一边靠拢
        return (second - first < last - secondLast) ? (last - second - size + 2) : (secondLast - size - first + 2);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> stones = { 7,4,9 };
    vector<int> actual = o.numMovesStonesII(stones);
    vector<int> expected = { 1,2 };
    check.checkIntVector(expected, actual);

    stones = { 6,5,4,3,10 };
    actual = o.numMovesStonesII(stones);
    expected = { 2,3 };
    check.checkIntVector(expected, actual);

    stones = { 100,101,104,102,103 };
    actual = o.numMovesStonesII(stones);
    expected = { 0,0 };
    check.checkIntVector(expected, actual);

    stones = { 1,2,3,6 };
    actual = o.numMovesStonesII(stones);
    expected = { 2,2 };
    check.checkIntVector(expected, actual);

    stones = { 1,2,3,5 };
    actual = o.numMovesStonesII(stones);
    expected = { 1,1 };
    check.checkIntVector(expected, actual);

    stones = { 1,4,5,6 };
    actual = o.numMovesStonesII(stones);
    expected = { 2,2 };
    check.checkIntVector(expected, actual);

    stones = { 1,3,4,5 };
    actual = o.numMovesStonesII(stones);
    expected = { 1,1 };
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
