/* 得到新鲜甜甜圈的最多组数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个甜甜圈商店，每批次都烤 batchSize 个甜甜圈。这个店铺有个规则，就是在烤一批新的甜甜圈时，之前 所有 甜甜圈都必须已经全部销售完毕。给你一个整数 batchSize 和一个整数数组 groups ，数组中的每个整数都代表一批前来购买甜甜圈的顾客，其中 groups[i] 表示这一批顾客的人数。每一位顾客都恰好只要一个甜甜圈。

当有一批顾客来到商店时，他们所有人都必须在下一批顾客来之前购买完甜甜圈。如果一批顾客中第一位顾客得到的甜甜圈不是上一组剩下的，那么这一组人都会很开心。

你可以随意安排每批顾客到来的顺序。请你返回在此前提下，最多 有多少组人会感到开心。

 

示例 1：

输入：batchSize = 3, groups = [1,2,3,4,5,6]
输出：4
解释：你可以将这些批次的顾客顺序安排为 [6,2,4,5,1,3] 。那么第 1，2，4，6 组都会感到开心。
示例 2：

输入：batchSize = 4, groups = [1,3,2,5,2,2,1,6]
输出：4
 

提示：

1 <= batchSize <= 9
1 <= groups.length <= 30
1 <= groups[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-groups-getting-fresh-donuts
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> remainderGroups(batchSize), remainders;
        unordered_map<int, int> memo;

        for (int group : groups) {
            ++remainderGroups[group % batchSize];
        }

        int happyGoups = remainderGroups[0];  // 能整除的group一定happy
        remainderGroups[0] = 0;

        happyGoups += getHappyTwoGoups(batchSize, remainderGroups);  // 两个组凑一块儿能happy的
        getLeft(batchSize, remainderGroups, remainders);  // 预处理后，最多还剩下4类groups，每类最多30个

        happyGoups += DFS(batchSize, 0, remainderGroups, remainders, memo);

        return happyGoups;
    }

    int getHappyTwoGoups(int batchSize, vector<int>& remainderGroups) {
        int i = 1, j = batchSize - 1, happyTwoGoups = 0;

        for (; i < j; ++i, --j) {
            int minimum = min(remainderGroups[i], remainderGroups[j]);
            happyTwoGoups += minimum;
            remainderGroups[i] -= minimum;
            remainderGroups[j] -= minimum;
        }

        if (i == j) {
            int half = remainderGroups[i] / 2;
            happyTwoGoups += half;
            remainderGroups[i] -= (half * 2);
        }

        return happyTwoGoups;
    }

    void getLeft(int batchSize, vector<int>& remainderGroups, vector<int>& remainders) {
        int i = 0;

        for (int j = 1; j < batchSize; ++j) {
            if (remainderGroups[j] != 0) {
                remainderGroups[i++] = remainderGroups[j];
                remainders.push_back(j);
            }
        }

        remainderGroups.resize(i);
    }

    int DFS(int batchSize, int left, vector<int>& remainderGroups, vector<int>& remainders, unordered_map<int, int>& memo) {
        int state = 0, maxGroups = 0, i, j, size = remainders.size();

        for (int groups : remainderGroups) {
            state = ((state << 5) | groups);
        }

        if (state == 0) {
            return memo[left] = 0;
        }

        state = ((state << 4) | left);
        if (memo.count(state) != 0) {
            return memo[state];
        }

        for (i = 0; i < size; ++i) {
            for (j = 1; j <= remainderGroups[i]; ++j) {
                int nextLeft = (j * remainders[i] + batchSize - left) % batchSize;
                if (nextLeft != 0) {
                    nextLeft = batchSize - nextLeft;
                }

                remainderGroups[i] -= j;
                int happyGroups = DFS(batchSize, nextLeft, remainderGroups, remainders, memo) + (left == 0 ? 1 : 0);
                remainderGroups[i] += j;

                maxGroups = max(maxGroups, happyGroups);
            }
        }

        return memo[state] = maxGroups;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> groups = { 1,2,3,4,5,6 };
    check.checkInt(4, o.maxHappyGroups(3, groups));

    groups = { 1,3,2,5,2,2,1,6 };
    check.checkInt(4, o.maxHappyGroups(4, groups));

    groups = { 369821235,311690424,74641571,179819879,171396603,274036220 };
    check.checkInt(4, o.maxHappyGroups(3, groups));
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
