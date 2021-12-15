/* 适合打劫银行的日子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你和一群强盗准备打劫银行。给你一个下标从 0 开始的整数数组 security ，其中 security[i] 是第 i 天执勤警卫的数量。日子从 0 开始编号。同时给你一个整数 time 。

如果第 i 天满足以下所有条件，我们称它为一个适合打劫银行的日子：

第 i 天前和后都分别至少有 time 天。
第 i 天前连续 time 天警卫数目都是非递增的。
第 i 天后连续 time 天警卫数目都是非递减的。
更正式的，第 i 天是一个合适打劫银行的日子当且仅当：security[i - time] >= security[i - time + 1] >= ... >= security[i] <= ... <= security[i + time - 1] <= security[i + time].

请你返回一个数组，包含 所有 适合打劫银行的日子（下标从 0 开始）。返回的日子可以 任意 顺序排列。

 

示例 1：

输入：security = [5,3,3,3,5,6,2], time = 2
输出：[2,3]
解释：
第 2 天，我们有 security[0] >= security[1] >= security[2] <= security[3] <= security[4] 。
第 3 天，我们有 security[1] >= security[2] >= security[3] <= security[4] <= security[5] 。
没有其他日子符合这个条件，所以日子 2 和 3 是适合打劫银行的日子。
示例 2：

输入：security = [1,1,1,1,1], time = 0
输出：[0,1,2,3,4]
解释：
因为 time 等于 0 ，所以每一天都是适合打劫银行的日子，所以返回每一天。
示例 3：

输入：security = [1,2,3,4,5,6], time = 2
输出：[]
解释：
没有任何一天的前 2 天警卫数目是非递增的。
所以没有适合打劫银行的日子，返回空数组。
示例 4：

输入：security = [1], time = 5
输出：[]
解释：
没有日子前面和后面有 5 天时间。
所以没有适合打劫银行的日子，返回空数组。
 

提示：

1 <= security.length <= 105
0 <= security[i], time <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-good-days-to-rob-the-bank
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int i, size = security.size();
        vector<int> decreasing(size, 0), inverseDecreasing(size, 0), goodDays;
        decreasing[0] = inverseDecreasing[size - 1] = 1;

        for (i = 1; i < size; ++i) {
            decreasing[i] = security[i] <= security[i - 1] ? decreasing[i - 1] + 1 : 1;
        }

        for (i = size - 2; i >= 0; --i) {
            inverseDecreasing[i] = security[i] <= security[i + 1] ? inverseDecreasing[i + 1] + 1 : 1;
        }

        for (i = time; i < size - time; ++i) {
            if (decreasing[i] > time && inverseDecreasing[i] > time) {
                goodDays.push_back(i);
            }
        }

        return goodDays;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> security = { 5,3,3,3,5,6,2 };
    vector<int> actual = o.goodDaysToRobBank(security, 2);
    vector<int> expected = { 2,3 };
    check.checkIntVector(expected, actual);

    security = { 1,1,1,1,1 };
    actual = o.goodDaysToRobBank(security, 0);
    expected = { 0,1,2,3,4 };
    check.checkIntVector(expected, actual);

    security = { 1,2,3,4,5,6 };
    actual = o.goodDaysToRobBank(security, 2);
    expected = {  };
    check.checkIntVector(expected, actual);

    security = { 1 };
    actual = o.goodDaysToRobBank(security, 5);
    expected = {  };
    check.checkIntVector(expected, actual);
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
