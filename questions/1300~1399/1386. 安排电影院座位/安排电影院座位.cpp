/* 安排电影院座位.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

如上图所示，电影院的观影厅中有 n 行座位，行编号从 1 到 n ，且每一行内总共有 10 个座位，列编号从 1 到 10 。

给你数组 reservedSeats ，包含所有已经被预约了的座位。比如说，researvedSeats[i]=[3,8] ，它表示第 3 行第 8 个座位被预约了。

请你返回 最多能安排多少个 4 人家庭 。4 人家庭要占据 同一行内连续 的 4 个座位。隔着过道的座位（比方说 [3,3] 和 [3,4]）不是连续的座位，但是如果你可以将 4 人家庭拆成过道两边各坐 2 人，这样子是允许的。

 

示例 1：



输入：n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
输出：4
解释：上图所示是最优的安排方案，总共可以安排 4 个家庭。蓝色的叉表示被预约的座位，橙色的连续座位表示一个 4 人家庭。
示例 2：

输入：n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
输出：2
示例 3：

输入：n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
输出：4
 

提示：

1 <= n <= 10^9
1 <= reservedSeats.length <= min(10*n, 10^4)
reservedSeats[i].length == 2
1 <= reservedSeats[i][0] <= n
1 <= reservedSeats[i][1] <= 10
所有 reservedSeats[i] 都是互不相同的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cinema-seat-allocation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reserved;
        setReserved(reservedSeats, reserved);

        return 2 * (n - reserved.size()) + countFamilySeatsInReservedRow(reserved);
    }

    void setReserved(vector<vector<int>>& reservedSeats, unordered_map<int, int>& reserved) {
        for (auto& seat : reservedSeats) {
            reserved[seat[0]] |= (0b10000000000 >> seat[1]);
        }
    }

    int countFamilySeatsInReservedRow(unordered_map<int, int>& reserved) {
        int familySeats = 0;

        for (auto iter = reserved.begin(); iter != reserved.end(); ++iter) {
            int oneRowSeats = iter->second;

            if ((oneRowSeats & 0b111100000) == 0 && (oneRowSeats & 0b11110) == 0) {
                familySeats += 2;
            }
            else if ((oneRowSeats & 0b111100000) == 0 || (oneRowSeats & 0b11110) == 0 || (oneRowSeats & 0b1111000) == 0) {
                familySeats += 1;
            }
        }

        return familySeats;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> reservedSeats = { {1,2},{1,3},{1,8},{2,6},{3,1},{3,10} };
    check.checkInt(4, o.maxNumberOfFamilies(3, reservedSeats));

    reservedSeats = { {2,1},{1,8},{2,6} };
    check.checkInt(2, o.maxNumberOfFamilies(2, reservedSeats));

    reservedSeats = { {4,3},{1,4},{4,6},{1,7} };
    check.checkInt(4, o.maxNumberOfFamilies(4, reservedSeats));

    reservedSeats = {  };
    check.checkInt(2, o.maxNumberOfFamilies(1, reservedSeats));

    reservedSeats = { {1,3},{1,8} };
    check.checkInt(1, o.maxNumberOfFamilies(1, reservedSeats));

    reservedSeats = { {1,2},{1,5},{1,9} };
    check.checkInt(0, o.maxNumberOfFamilies(1, reservedSeats));
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
