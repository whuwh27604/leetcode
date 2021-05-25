/* 做菜顺序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个厨师收集了他 n 道菜的满意程度 satisfaction ，这个厨师做出每道菜的时间都是 1 单位时间。

一道菜的 「喜爱时间」系数定义为烹饪这道菜以及之前每道菜所花费的时间乘以这道菜的满意程度，也就是 time[i]*satisfaction[i] 。

请你返回做完所有菜 「喜爱时间」总和的最大值为多少。

你可以按 任意 顺序安排做菜的顺序，你也可以选择放弃做某些菜来获得更大的总和。

 

示例 1：

输入：satisfaction = [-1,-8,0,5,-9]
输出：14
解释：去掉第二道和最后一道菜，最大的喜爱时间系数和为 (-1*1 + 0*2 + 5*3 = 14) 。每道菜都需要花费 1 单位时间完成。
示例 2：

输入：satisfaction = [4,3,2]
输出：20
解释：按照原来顺序相反的时间做菜 (2*1 + 3*2 + 4*3 = 20)
示例 3：

输入：satisfaction = [-1,-4,-5]
输出：0
解释：大家都不喜欢这些菜，所以不做任何菜可以获得最大的喜爱时间系数。
示例 4：

输入：satisfaction = [-2,5,-1,0,3,-3]
输出：35
 

提示：

n == satisfaction.length
1 <= n <= 500
-10^3 <= satisfaction[i] <= 10^3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reducing-dishes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        /* 1、对1*A1+2*A2+...+n*An来说，{A1,A2...An}升序排列能够取到最大值
           2、排序后按顺序累加An、An-1...只要sum>=0，那么就应该做这个菜 */
        int i, size = satisfaction.size(), maxSat = 0, sum = 0;

        sort(satisfaction.begin(), satisfaction.end(), greater<int>());

        for (i = 0; i < size && sum + satisfaction[i] >= 0; ++i) {
            sum += satisfaction[i];
            maxSat += sum;
        }

        return maxSat;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> satisfaction = { -1,-8,0,5,-9 };
    check.checkInt(14, o.maxSatisfaction(satisfaction));

    satisfaction = { 4,3,2 };
    check.checkInt(20, o.maxSatisfaction(satisfaction));

    satisfaction = { -1,-4,-5 };
    check.checkInt(0, o.maxSatisfaction(satisfaction));

    satisfaction = { -2,5,-1,0,3,-3 };
    check.checkInt(35, o.maxSatisfaction(satisfaction));

    satisfaction = { -2 };
    check.checkInt(0, o.maxSatisfaction(satisfaction));

    satisfaction = { 5 };
    check.checkInt(5, o.maxSatisfaction(satisfaction));
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
