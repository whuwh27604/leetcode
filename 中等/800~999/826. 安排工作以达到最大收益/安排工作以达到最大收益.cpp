/* 安排工作以达到最大收益.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一些工作：difficulty[i] 表示第 i 个工作的难度，profit[i] 表示第 i 个工作的收益。

现在我们有一些工人。worker[i] 是第 i 个工人的能力，即该工人只能完成难度小于等于 worker[i] 的工作。

每一个工人都最多只能安排一个工作，但是一个工作可以完成多次。

举个例子，如果 3 个工人都尝试完成一份报酬为 1 的同样工作，那么总收益为 $3。如果一个工人不能完成任何工作，他的收益为 $0 。

我们能得到的最大收益是多少？

 

示例：

输入: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
输出: 100
解释: 工人被分配的工作难度是 [4,4,6,6] ，分别获得 [20,20,30,30] 的收益。
 

提示:

1 <= difficulty.length = profit.length <= 10000
1 <= worker.length <= 10000
difficulty[i], profit[i], worker[i]  的范围是 [1, 10^5]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/most-profit-assigning-work
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int i, j = 0, sizeDiff = difficulty.size(), sizeWorker = worker.size();
        int maxProfit = 0, totalProfit = 0;
        vector<pair<int, int>> dpPairs(sizeDiff, { 0,0 });

        for (i = 0; i < sizeDiff; ++i) {
            dpPairs[i] = { difficulty[i],profit[i] };
        }

        sort(dpPairs.begin(), dpPairs.end());
        sort(worker.begin(), worker.end());

        for (i = 0; i < sizeWorker; ++i) {
            while ((j < sizeDiff) && (dpPairs[j].first <= worker[i])) {
                maxProfit = max(maxProfit, dpPairs[j++].second);
            }

            totalProfit += maxProfit;
        }

        return totalProfit;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> difficulty = { 68,35,52,47,86 };
    vector<int> profit = { 67,17,1,81,3 };
    vector<int> worker = { 92,10,85,84,82 };
    check.checkInt(324, o.maxProfitAssignment(difficulty, profit, worker));

    difficulty = { 5,50,92,21,24,70,17,63,30,53 };
    profit = { 68,100,3,99,56,43,26,93,55,25 };
    worker = { 96,3,55,30,11,58,68,36,26,1 };
    check.checkInt(765, o.maxProfitAssignment(difficulty, profit, worker));

    difficulty = { 2,4,6,8,10 };
    profit = { 10,20,30,40,50 };
    worker = { 4,5,6,7 };
    check.checkInt(100, o.maxProfitAssignment(difficulty, profit, worker));

    difficulty = { 2 };
    profit = { 10 };
    worker = { 1,2,3 };
    check.checkInt(20, o.maxProfitAssignment(difficulty, profit, worker));
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
