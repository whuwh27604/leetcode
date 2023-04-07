/* 老鼠和奶酪.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有两只老鼠和 n 块不同类型的奶酪，每块奶酪都只能被其中一只老鼠吃掉。

下标为 i 处的奶酪被吃掉的得分为：

如果第一只老鼠吃掉，则得分为 reward1[i] 。
如果第二只老鼠吃掉，则得分为 reward2[i] 。
给你一个正整数数组 reward1 ，一个正整数数组 reward2 ，和一个非负整数 k 。

请你返回第一只老鼠恰好吃掉 k 块奶酪的情况下，最大 得分为多少。



示例 1：

输入：reward1 = [1,1,3,4], reward2 = [4,4,1,1], k = 2
输出：15
解释：这个例子中，第一只老鼠吃掉第 2 和 3 块奶酪（下标从 0 开始），第二只老鼠吃掉第 0 和 1 块奶酪。
总得分为 4 + 4 + 3 + 4 = 15 。
15 是最高得分。
示例 2：

输入：reward1 = [1,1], reward2 = [1,1], k = 2
输出：2
解释：这个例子中，第一只老鼠吃掉第 0 和 1 块奶酪（下标从 0 开始），第二只老鼠不吃任何奶酪。
总得分为 1 + 1 = 2 。
2 是最高得分。


提示：

1 <= n == reward1.length == reward2.length <= 105
1 <= reward1[i], reward2[i] <= 1000
0 <= k <= n
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int size = reward1.size(), score = 0;
        vector<pair<int, int>> rewards(size);

        for (int i = 0; i < size; ++i) {
            rewards[i] = { reward1[i] - reward2[i],i };
        }

        sort(rewards.begin(), rewards.end());

        for (int i = 0; i < k; ++i) {
            score += reward1[rewards[size - 1 - i].second];
        }

        for (int i = k; i < size; ++i) {
            score += reward2[rewards[size - 1 - i].second];
        }

        return score;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> reward1 = { 1,1,3,4 };
    vector<int> reward2 = { 4,4,1,1 };
    check.checkInt(15, o.miceAndCheese(reward1, reward2, 2));

    reward1 = { 1,1 };
    reward2 = { 1,1 };
    check.checkInt(2, o.miceAndCheese(reward1, reward2, 2));

    reward1 = { 1,4,4,6,4 };
    reward2 = { 6,5,3,6,1 };
    check.checkInt(24, o.miceAndCheese(reward1, reward2, 1));

    reward1 = { 11,14,4,8,7,6,2,7,10,1,2,7,8,4,9,5,13,9,13,9,4,8,10,10,3,1 };
    reward2 = { 5,8,4,4,8,6,3,11,5,15,7,2,13,12,8,2,7,3,14,9,5,9,4,6,7,2 };
    check.checkInt(209, o.miceAndCheese(reward1, reward2, 5));
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
