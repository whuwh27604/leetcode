/* IPO.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
假设 力扣（LeetCode）即将开始其 IPO。为了以更高的价格将股票卖给风险投资公司，力扣 希望在 IPO 之前开展一些项目以增加其资本。 由于资源有限，它只能在 IPO 之前完成最多 k 个不同的项目。帮助 力扣 设计完成最多 k 个不同项目后得到最大总资本的方式。

给定若干个项目。对于每个项目 i，它都有一个纯利润 Pi，并且需要最小的资本 Ci 来启动相应的项目。最初，你有 W 资本。当你完成一个项目时，你将获得纯利润，且利润将被添加到你的总资本中。

总而言之，从给定项目中选择最多 k 个不同项目的列表，以最大化最终资本，并输出最终可获得的最多资本。

 

示例：

输入：k=2, W=0, Profits=[1,2,3], Capital=[0,1,1].
输出：4
解释：
由于你的初始资本为 0，你仅可以从 0 号项目开始。
在完成后，你将获得 1 的利润，你的总资本将变为 1。
此时你可以选择开始 1 号或 2 号项目。
由于你最多可以选择两个项目，所以你需要完成 2 号项目以获得最大的资本。
因此，输出最后最大化的资本，为 0 + 1 + 3 = 4。
 

提示：

假设所有输入数字都是非负整数。
表示利润和资本的数组的长度不超过 50000。
答案保证在 32 位有符号整数范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ipo
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

bool pairCompare(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first == p2.first ? p1.second > p2.second : p1.first < p2.first;  // capital小的排前面，capital相等时profit大的排前面
}

struct intComapare {
    bool operator() (const int p1, const int p2) const {
        return p1 > p2;  // profit大的排前面
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int i = 0, size = Capital.size(), totalCapital = W, projects = 0;
        vector<pair<int, int>> capProfits(size);
        multiset<int, intComapare> maxProfits;

        mergeCapitalProfits(Profits, Capital, capProfits);
        sort(capProfits.begin(), capProfits.end(), pairCompare);

        for (projects = 0; projects < k && i < size; ++projects) {  // 每一次，把小于currentCapital的项目扔进set排序，取profit最大的项目
            for (; i < size && capProfits[i].first <= totalCapital; ++i) {
                maxProfits.insert(capProfits[i].second);
                if ((int)maxProfits.size() > k) {
                    maxProfits.erase(--maxProfits.end());
                }
            }

            if (maxProfits.empty()) {  // 没有项目可取了，说明当前capital不足以启动下一个项目
                break;
            }

            totalCapital += *maxProfits.begin();  // 注意profit是纯利润，项目并不需要消耗capital
            maxProfits.erase(maxProfits.begin());
        }

        for (auto iter = maxProfits.begin(); iter != maxProfits.end() && projects < k; ++iter, ++projects) {
            totalCapital += (*iter);  // 所有项目都可以启动了，直接按照profit从高往低取满k个
        }

        return totalCapital;
    }

    void mergeCapitalProfits(vector<int>& Profits, vector<int>& Capital, vector<pair<int, int>>& capProfits) {
        for (unsigned int i = 0; i < Capital.size(); ++i) {
            capProfits[i] = { Capital[i], Profits[i] };
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> Profits = { 1,2,3 };
    vector<int> Capital = { 0,1,1 };
    check.checkInt(4, o.findMaximizedCapital(2, 0, Profits, Capital));

    Profits = { 1,2,3 };
    Capital = { 0,1,1 };
    check.checkInt(6, o.findMaximizedCapital(6, 0, Profits, Capital));

    Profits = { 1,2,3 };
    Capital = { 1,1,2 };
    check.checkInt(0, o.findMaximizedCapital(1, 0, Profits, Capital));

    Profits = { 1,2,3 };
    Capital = { 1,1,2 };
    check.checkInt(5, o.findMaximizedCapital(1, 2, Profits, Capital));

    Profits = { 3 };
    Capital = { 1 };
    check.checkInt(4, o.findMaximizedCapital(2, 1, Profits, Capital));

    Profits = { 1,2,3 };
    Capital = { 0,9,10 };
    check.checkInt(1, o.findMaximizedCapital(2, 0, Profits, Capital));
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
