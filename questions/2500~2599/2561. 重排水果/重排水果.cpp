/* 重排水果.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有两个果篮，每个果篮中有 n 个水果。给你两个下标从 0 开始的整数数组 basket1 和 basket2 ，用以表示两个果篮中每个水果的成本。

你希望两个果篮相等。为此，可以根据需要多次执行下述操作：

选中两个下标 i 和 j ，并交换 basket1 中的第 i 个水果和 basket2 中的第 j 个水果。
交换的成本是 min(basket1i,basket2j) 。
根据果篮中水果的成本进行排序，如果排序后结果完全相同，则认为两个果篮相等。

返回使两个果篮相等的最小交换成本，如果无法使两个果篮相等，则返回 -1 。



示例 1：

输入：basket1 = [4,2,2,2], basket2 = [1,4,1,2]
输出：1
解释：交换 basket1 中下标为 1 的水果和 basket2 中下标为 0 的水果，交换的成本为 1 。此时，basket1 = [4,1,2,2] 且 basket2 = [2,4,1,2] 。重排两个数组，发现二者相等。
示例 2：

输入：basket1 = [2,3,4,1], basket2 = [3,2,5,1]
输出：-1
解释：可以证明无法使两个果篮相等。


提示：

basket1.length == bakste2.length
1 <= basket1.length <= 105
1 <= basket1i,basket2i <= 109
*/

#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int least = INT_MAX, diffs = 0;
        unordered_map<int, int> costCnt1, costCnt2;
        map<int, int> diffCosts;

        count(basket1, costCnt1, least);
        count(basket2, costCnt2, least);

        if (!check(costCnt1, costCnt2, diffCosts, diffs) || !check(costCnt2, costCnt1, diffCosts, diffs)) {
            return -1;
        }

        return getCost(diffCosts, diffs, least);
    }

    void count(vector<int>& basket, unordered_map<int, int>& costCnt, int& least) {
        for (int cost : basket) {
            ++costCnt[cost];
            least = min(least, cost);
        }
    }

    bool check(unordered_map<int, int>& costCnt1, unordered_map<int, int>& costCnt2, map<int, int>& diffCosts, int& diffs) {
        for (auto& kv : costCnt1) {
            if (kv.second > costCnt2[kv.first]) {
                int diff = kv.second - costCnt2[kv.first];
                if ((diff & 1) == 1) {
                    return false;
                }
                diff /= 2;
                diffCosts[kv.first] += diff;
                diffs += diff;
            }
        }

        return true;
    }

    long long getCost(map<int, int>& diffCosts, int diffs, int least) {
        long long cost = 0;
        diffs /= 2;  // 设需要交换的两个是a、b，那么cost=min(a,b)，所以只需要cost较小的一半
        least *= 2;  // 可以直接交换a、b，也可以a交换least，再b交换least；每一次比较cost和2*least，取较小的一个

        for (auto iter = diffCosts.begin(); diffs != 0; ++iter) {
            if (iter->second > diffs) {
                cost += (long long)min(iter->first, least) * diffs;
                diffs = 0;
            }
            else {
                cost += (long long)min(iter->first, least) * iter->second;
                diffs -= iter->second;
            }
        }

        return cost;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> basket1 = { 4,2,2,2 };
    vector<int> basket2 = { 1,4,1,2 };
    check.checkLongLong(1, o.minCost(basket1, basket2));

    basket1 = { 2,3,4,1 };
    basket2 = { 3,2,5,1 };
    check.checkLongLong(-1, o.minCost(basket1, basket2));

    basket1 = { 1,10,10 };
    basket2 = { 1,20,20 };
    check.checkLongLong(2, o.minCost(basket1, basket2));

    basket1 = { 84,80,43,8,80,88,43,14,100,88 };
    basket2 = { 32,32,42,68,68,100,42,84,14,8 };
    check.checkLongLong(48, o.minCost(basket1, basket2));

    basket1 = { 1 };
    basket2 = { 1 };
    check.checkLongLong(0, o.minCost(basket1, basket2));

    basket1 = { 1 };
    basket2 = { 2 };
    check.checkLongLong(-1, o.minCost(basket1, basket2));
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
