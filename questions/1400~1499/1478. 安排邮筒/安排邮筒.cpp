/* 安排邮筒.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个房屋数组houses 和一个整数 k ，其中 houses[i] 是第 i 栋房子在一条街上的位置，现需要在这条街上安排 k 个邮筒。

请你返回每栋房子与离它最近的邮筒之间的距离的 最小 总和。

答案保证在 32 位有符号整数范围以内。

 

示例 1：



输入：houses = [1,4,8,10,20], k = 3
输出：5
解释：将邮筒分别安放在位置 3， 9 和 20 处。
每个房子到最近邮筒的距离和为 |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 。
示例 2：



输入：houses = [2,3,5,12,18], k = 2
输出：9
解释：将邮筒分别安放在位置 3 和 14 处。
每个房子到最近邮筒距离和为 |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9 。
示例 3：

输入：houses = [7,4,6,1], k = 1
输出：8
示例 4：

输入：houses = [3,6,14,10], k = 4
输出：0
 

提示：

n == houses.length
1 <= n <= 100
1 <= houses[i] <= 10^4
1 <= k <= n
数组 houses 中的整数互不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/allocate-mailboxes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int houseNum = houses.size();
        vector<vector<int>> distances(houseNum, vector<int>(houseNum, 0));
        vector<vector<int>> dp(houseNum + 1, vector<int>(k + 1, 0));

        sort(houses.begin(), houses.end());
        getDistanceOneMailbox(houses, distances);

        for (int house = 2; house <= houseNum; ++house) {
            dp[house][1] = distances[0][house - 1];

            for (int mailbox = 2; mailbox <= k && mailbox < house; ++mailbox) {
                dp[house][mailbox] = INT_MAX;

                for (int last = 1; last <= house - mailbox + 1; ++last) {  // 遍历最后一个邮箱覆盖的房子个数
                    dp[house][mailbox] = min(dp[house][mailbox], dp[house - last][mailbox - 1] + distances[house - last][house - 1]);
                }
            }
        }

        return dp[houseNum][k];
    }

    void getDistanceOneMailbox(vector<int>& houses, vector<vector<int>>& distances) {
        int i, j, size = houses.size();

        for (i = 0; i < size - 1; ++i) {
            for (j = i + 1; j < size; ++j) {
                distances[i][j] = distances[i][j - 1] + houses[j] - houses[(i + j) / 2];
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> houses = { 1,4,8,10,20 };
    check.checkInt(5, o.minDistance(houses, 3));

    houses = { 2,3,5,12,18 };
    check.checkInt(9, o.minDistance(houses, 2));

    houses = { 7,4,6,1 };
    check.checkInt(8, o.minDistance(houses, 1));

    houses = { 3,6,14,10 };
    check.checkInt(0, o.minDistance(houses, 4));

    houses = { 5 };
    check.checkInt(0, o.minDistance(houses, 1));

    houses = { 5 };
    check.checkInt(0, o.minDistance(houses, 3));

    houses = { 1,3,5,7,9,2,4,6,8,10,110,18,16,14,12,19,17,15,13,11 };
    check.checkInt(10, o.minDistance(houses, 10));

    houses = { 1,13,25,37,49,52,64,76,88,910,810,718,616,514,412,319,217,115,153,181 };
    check.checkInt(223, o.minDistance(houses, 10));
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
