/* 两地调度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
公司计划面试 2N 人。第 i 人飞往 A 市的费用为 costs[i][0]，飞往 B 市的费用为 costs[i][1]。

返回将每个人都飞到某座城市的最低费用，要求每个城市都有 N 人抵达。

 

示例：

输入：[[10,20],[30,200],[400,50],[30,20]]
输出：110
解释：
第一个人去 A 市，费用为 10。
第二个人去 A 市，费用为 30。
第三个人去 B 市，费用为 50。
第四个人去 B 市，费用为 20。

最低总费用为 10 + 30 + 50 + 20 = 110，每个城市都有一半的人在面试。
 

提示：

1 <= costs.length <= 100
costs.length 为偶数
1 <= costs[i][0], costs[i][1] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-city-scheduling
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        multimap<int, int> costDiffIndex;
        int len = costs.size();

        for (int i = 0; i < len; i++) {
            int costDiff = (costs[i][1] - costs[i][0]);  // 按照去A比去B能节省的钱排序
            costDiffIndex.insert(pair<int, int>(costDiff, i));
        }

        int sumCosts = 0, count = 0;
        len /= 2;
        for (auto iter = costDiffIndex.begin(); iter != costDiffIndex.end(); iter++) {
            // 前一半节省的钱较少，去B；后一半节省的钱较多，去A
            if (count < len) {
                sumCosts += costs[iter->second][1];
                count++;
            }
            else {
                sumCosts += costs[iter->second][0];
            }
        }

        return sumCosts;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> costs = { {10,20}, {30,200}, {400,50}, {30,20} };
    check.checkInt(110, o.twoCitySchedCost(costs));

    costs = { {100,40}, {100,30}, {100,20}, {100,10} };
    check.checkInt(230, o.twoCitySchedCost(costs));

    costs = { {100,40}, {10,80} };
    check.checkInt(50, o.twoCitySchedCost(costs));

    costs = { {10,20}, {30,200}, {400,50}, {30,20}, {1,3}, {2,5} };
    check.checkInt(115, o.twoCitySchedCost(costs));
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
