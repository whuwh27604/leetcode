/* 移动石子直到连续.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
三枚石子放置在数轴上，位置分别为 a，b，c。

每一回合，我们假设这三枚石子当前分别位于位置 x, y, z 且 x < y < z。从位置 x 或者是位置 z 拿起一枚石子，并将该石子移动到某一整数位置 k 处，其中 x < k < z 且 k != y。

当你无法进行任何移动时，即，这些石子的位置连续时，游戏结束。

要使游戏结束，你可以执行的最小和最大移动次数分别是多少？ 以长度为 2 的数组形式返回答案：answer = [minimum_moves, maximum_moves]

 

示例 1：

输入：a = 1, b = 2, c = 5
输出：[1, 2]
解释：将石子从 5 移动到 4 再移动到 3，或者我们可以直接将石子移动到 3。
示例 2：

输入：a = 4, b = 3, c = 2
输出：[0, 0]
解释：我们无法进行任何移动。
 

提示：

1 <= a <= 100
1 <= b <= 100
1 <= c <= 100
a != b, b != c, c != a

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/moving-stones-until-consecutive
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int stones[3] = { a, b, c };
        sort(stones, (stones + 3));

        int minMoves, maxMoves = (stones[2] - stones[0] - 2);

        if (((stones[0] + 1) == stones[1]) && ((stones[1] + 1) == stones[2])) {
            minMoves = 0;
        }
        else if (((stones[0] + 1) == stones[1]) || ((stones[1] + 1) == stones[2])) {
            minMoves = 1;
        }
        else if (((stones[0] + 2) == stones[1]) || ((stones[1] + 2) == stones[2])) {
            minMoves = 1;
        }
        else {
            minMoves = 2;
        }

        return { minMoves, maxMoves };
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> expected = { 1,2 };
    vector<int> actual = o.numMovesStones(1, 2, 5);
    check.checkIntVector(expected, actual);

    expected = { 0,0 };
    actual = o.numMovesStones(4, 3, 2);
    check.checkIntVector(expected, actual);

    expected = { 1,3 };
    actual = o.numMovesStones(5, 6, 1);
    check.checkIntVector(expected, actual);

    expected = { 1,1 };
    actual = o.numMovesStones(3, 5, 6);
    check.checkIntVector(expected, actual);

    expected = { 1,1 };
    actual = o.numMovesStones(5, 6, 8);
    check.checkIntVector(expected, actual);

    expected = { 1,2 };
    actual = o.numMovesStones(9, 6, 5);
    check.checkIntVector(expected, actual);

    expected = { 1,2 };
    actual = o.numMovesStones(5, 3, 7);
    check.checkIntVector(expected, actual);

    expected = { 2,6 };
    actual = o.numMovesStones(9, 5, 1);
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
