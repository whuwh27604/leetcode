/* 完成所有任务需要的最少轮数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 tasks ，其中 tasks[i] 表示任务的难度级别。在每一轮中，你可以完成 2 个或者 3 个 相同难度级别 的任务。

返回完成所有任务需要的 最少 轮数，如果无法完成所有任务，返回 -1 。

 

示例 1：

输入：tasks = [2,2,3,3,2,4,4,4,4,4]
输出：4
解释：要想完成所有任务，一个可能的计划是：
- 第一轮，完成难度级别为 2 的 3 个任务。
- 第二轮，完成难度级别为 3 的 2 个任务。
- 第三轮，完成难度级别为 4 的 3 个任务。
- 第四轮，完成难度级别为 4 的 2 个任务。
可以证明，无法在少于 4 轮的情况下完成所有任务，所以答案为 4 。
示例 2：

输入：tasks = [2,3,3]
输出：-1
解释：难度级别为 2 的任务只有 1 个，但每一轮执行中，只能选择完成 2 个或者 3 个相同难度级别的任务。因此，无法完成所有任务，答案为 -1 。
 

提示：

1 <= tasks.length <= 105
1 <= tasks[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-rounds-to-complete-all-tasks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> taskCount;
        int rounds = 0;

        for (int task : tasks) {
            ++taskCount[task];
        }

        for (auto& count : taskCount) {
            if (count.second == 1) {
                return -1;
            }

            if (count.second % 3 == 0) {  // 2x+3y=3z; x=0,y=z
                rounds += (count.second / 3);
            }
            else {  // 2x+3y=3z+1; x=2,y=z-1  2x+3y=3z+2; x=1,y=z
                rounds += (count.second / 3 + 1);
            }
        }

        return rounds;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> tasks = { 2,2,3,3,2,4,4,4,4,4 };
    check.checkInt(4, o.minimumRounds(tasks));

    tasks = { 2,3,3 };
    check.checkInt(-1, o.minimumRounds(tasks));
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
