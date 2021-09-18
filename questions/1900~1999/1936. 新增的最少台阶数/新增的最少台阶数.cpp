/* 新增的最少台阶数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 严格递增 的整数数组 rungs ，用于表示梯子上每一台阶的 高度 。当前你正站在高度为 0 的地板上，并打算爬到最后一个台阶。

另给你一个整数 dist 。每次移动中，你可以到达下一个距离你当前位置（地板或台阶）不超过 dist 高度的台阶。当然，你也可以在任何正 整数 高度处插入尚不存在的新台阶。

返回爬到最后一阶时必须添加到梯子上的 最少 台阶数。

 

示例 1：

输入：rungs = [1,3,5,10], dist = 2
输出：2
解释：
现在无法到达最后一阶。
在高度为 7 和 8 的位置增设新的台阶，以爬上梯子。
梯子在高度为 [1,3,5,7,8,10] 的位置上有台阶。
示例 2：

输入：rungs = [3,6,8,10], dist = 3
输出：0
解释：
这个梯子无需增设新台阶也可以爬上去。
示例 3：

输入：rungs = [3,4,6,7], dist = 2
输出：1
解释：
现在无法从地板到达梯子的第一阶。
在高度为 1 的位置增设新的台阶，以爬上梯子。
梯子在高度为 [1,3,4,6,7] 的位置上有台阶。
示例 4：

输入：rungs = [5], dist = 10
输出：0
解释：这个梯子无需增设新台阶也可以爬上去。
 

提示：

1 <= rungs.length <= 105
1 <= rungs[i] <= 109
1 <= dist <= 109
rungs 严格递增

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-minimum-number-of-rungs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int current = 0, add = 0;

        for (int rung : rungs) {
            if (current + dist < rung) {
                add += (rung - current - 1) / dist;
            }

            current = rung;
        }

        return add;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> rungs = { 1,3,5,10 };
    check.checkInt(2, o.addRungs(rungs, 2));

    rungs = { 3,6,8,10 };
    check.checkInt(0, o.addRungs(rungs, 3));

    rungs = { 3,4,6,7 };
    check.checkInt(1, o.addRungs(rungs, 2));

    rungs = { 5 };
    check.checkInt(0, o.addRungs(rungs, 10));
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
