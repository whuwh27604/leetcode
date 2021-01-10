/* 避免重复字母的最小删除成本.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个整数数组 cost ，其中 cost[i] 是从 s 中删除字符 i 的代价。

返回使字符串任意相邻两个字母不相同的最小删除成本。

请注意，删除一个字符后，删除其他字符的成本不会改变。

 

示例 1：

输入：s = "abaac", cost = [1,2,3,4,5]
输出：3
解释：删除字母 "a" 的成本为 3，然后得到 "abac"（字符串中相邻两个字母不相同）。
示例 2：

输入：s = "abc", cost = [1,2,3]
输出：0
解释：无需删除任何字母，因为字符串中不存在相邻两个字母相同的情况。
示例 3：

输入：s = "aabaa", cost = [1,2,3,4,1]
输出：2
解释：删除第一个和最后一个字母，得到字符串 ("aba") 。
 

提示：

s.length == cost.length
1 <= s.length, cost.length <= 10^5
1 <= cost[i] <= 10^4
s 中只含有小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-deletion-cost-to-avoid-repeating-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int i, size = s.size(), totalCost = 0, maxCost = cost[0], sum = cost[0];
        
        for (i = 1; i < size; ++i) {
            if (s[i] == s[i - 1]) {
                sum += cost[i];
                maxCost = max(maxCost, cost[i]);
            }
            else {
                totalCost += (sum - maxCost);
                sum = maxCost = cost[i];
            }
        }

        return totalCost + sum - maxCost;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> cost = { 1,2,3,4,5 };
    check.checkInt(3, o.minCost("abaac", cost));

    cost = { 1,2,3 };
    check.checkInt(0, o.minCost("abc", cost));

    cost = { 1,2,3,4,1 };
    check.checkInt(2, o.minCost("aabaa", cost));

    cost = { 1 };
    check.checkInt(0, o.minCost("a", cost));
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
