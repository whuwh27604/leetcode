/* 圆形赛道上经过次数最多的扇区.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n 和一个整数数组 rounds 。有一条圆形赛道由 n 个扇区组成，扇区编号从 1 到 n 。现将在这条赛道上举办一场马拉松比赛，该马拉松全程由 m 个阶段组成。其中，第 i 个阶段将会从扇区 rounds[i - 1] 开始，到扇区 rounds[i] 结束。举例来说，第 1 阶段从 rounds[0] 开始，到 rounds[1] 结束。

请你以数组形式返回经过次数最多的那几个扇区，按扇区编号 升序 排列。

注意，赛道按扇区编号升序逆时针形成一个圆（请参见第一个示例）。

 

示例 1：



输入：n = 4, rounds = [1,3,1,2]
输出：[1,2]
解释：本场马拉松比赛从扇区 1 开始。经过各个扇区的次序如下所示：
1 --> 2 --> 3（阶段 1 结束）--> 4 --> 1（阶段 2 结束）--> 2（阶段 3 结束，即本场马拉松结束）
其中，扇区 1 和 2 都经过了两次，它们是经过次数最多的两个扇区。扇区 3 和 4 都只经过了一次。
示例 2：

输入：n = 2, rounds = [2,1,2,1,2,1,2,1,2]
输出：[2]
示例 3：

输入：n = 7, rounds = [1,3,5,7]
输出：[1,2,3,4,5,6,7]
 

提示：

2 <= n <= 100
1 <= m <= 100
rounds.length == m + 1
1 <= rounds[i] <= n
rounds[i] != rounds[i + 1] ，其中 0 <= i < m

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/most-visited-sector-in-a-circular-track
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        // 结果只和始末的位置有关，和中间跑了多少圈没有关系
        int i, start = rounds[0], end = rounds.back();
        vector<int> ans;

        if (end >= start) {
            for (i = start; i <= end; ++i) {
                ans.push_back(i);
            }
        }
        else {
            for (i = 1; i <= end; ++i) {
                ans.push_back(i);
            }
            for (i = start; i <= n; ++i) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> rounds = { 1,3,1,2 };
    vector<int> actual = o.mostVisited(4, rounds);
    vector<int> expected = { 1,2 };
    check.checkIntVector(expected, actual);

    rounds = { 2,1,2,1,2,1,2,1,2 };
    actual = o.mostVisited(2, rounds);
    expected = { 2 };
    check.checkIntVector(expected, actual);

    rounds = { 1,3,5,7 };
    actual = o.mostVisited(7, rounds);
    expected = { 1,2,3,4,5,6,7 };
    check.checkIntVector(expected, actual);

    rounds = { 4,2 };
    actual = o.mostVisited(6, rounds);
    expected = { 1,2,4,5,6 };
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
