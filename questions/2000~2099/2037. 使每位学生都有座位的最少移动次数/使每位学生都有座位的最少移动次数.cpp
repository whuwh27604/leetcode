/* 使每位学生都有座位的最少移动次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个房间里有 n 个座位和 n 名学生，房间用一个数轴表示。给你一个长度为 n 的数组 seats ，其中 seats[i] 是第 i 个座位的位置。同时给你一个长度为 n 的数组 students ，其中 students[j] 是第 j 位学生的位置。

你可以执行以下操作任意次：

增加或者减少第 i 位学生的位置，每次变化量为 1 （也就是将第 i 位学生从位置 x 移动到 x + 1 或者 x - 1）
请你返回使所有学生都有座位坐的 最少移动次数 ，并确保没有两位学生的座位相同。

请注意，初始时有可能有多个座位或者多位学生在 同一 位置。

 

示例 1：

输入：seats = [3,1,5], students = [2,7,4]
输出：4
解释：学生移动方式如下：
- 第一位学生从位置 2 移动到位置 1 ，移动 1 次。
- 第二位学生从位置 7 移动到位置 5 ，移动 2 次。
- 第三位学生从位置 4 移动到位置 3 ，移动 1 次。
总共 1 + 2 + 1 = 4 次移动。
示例 2：

输入：seats = [4,1,5,9], students = [1,3,2,6]
输出：7
解释：学生移动方式如下：
- 第一位学生不移动。
- 第二位学生从位置 3 移动到位置 4 ，移动 1 次。
- 第三位学生从位置 2 移动到位置 5 ，移动 3 次。
- 第四位学生从位置 6 移动到位置 9 ，移动 3 次。
总共 0 + 1 + 3 + 3 = 7 次移动。
示例 3：

输入：seats = [2,2,6,6], students = [1,3,2,6]
输出：4
解释：学生移动方式如下：
- 第一位学生从位置 1 移动到位置 2 ，移动 1 次。
- 第二位学生从位置 3 移动到位置 6 ，移动 3 次。
- 第三位学生不移动。
- 第四位学生不移动。
总共 1 + 3 + 0 + 0 = 4 次移动。
 

提示：

n == seats.length == students.length
1 <= n <= 100
1 <= seats[i], students[j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-moves-to-seat-everyone
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        /* 可以证明排序后，第i人去第i位总的移动次数最少 */
        int i, size = seats.size(), moves = 0;

        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        for (i = 0; i < size; ++i) {
            moves += abs(seats[i] - students[i]);
        }

        return moves;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> seats = { 3,1,5 };
    vector<int> students = { 2,7,4 };
    check.checkInt(4, o.minMovesToSeat(seats, students));

    seats = { 4,1,5,9 };
    students = { 1,3,2,6 };
    check.checkInt(7, o.minMovesToSeat(seats, students));

    seats = { 2,2,6,6 };
    students = { 1,3,2,6 };
    check.checkInt(4, o.minMovesToSeat(seats, students));
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
