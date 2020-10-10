/* 提莫攻击.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在《英雄联盟》的世界中，有一个叫 “提莫” 的英雄，他的攻击可以让敌方英雄艾希（编者注：寒冰射手）进入中毒状态。现在，给出提莫对艾希的攻击时间序列和提莫攻击的中毒持续时间，你需要输出艾希的中毒状态总时长。

你可以认为提莫在给定的时间点进行攻击，并立即使艾希处于中毒状态。

 

示例1:

输入: [1,4], 2
输出: 4
原因: 第 1 秒初，提莫开始对艾希进行攻击并使其立即中毒。中毒状态会维持 2 秒钟，直到第 2 秒末结束。
第 4 秒初，提莫再次攻击艾希，使得艾希获得另外 2 秒中毒时间。
所以最终输出 4 秒。
示例2:

输入: [1,2], 2
输出: 3
原因: 第 1 秒初，提莫开始对艾希进行攻击并使其立即中毒。中毒状态会维持 2 秒钟，直到第 2 秒末结束。
但是第 2 秒初，提莫再次攻击了已经处于中毒状态的艾希。
由于中毒状态不可叠加，提莫在第 2 秒初的这次攻击会在第 3 秒末结束。
所以最终输出 3 。
 

提示：

你可以假定时间序列数组的总长度不超过 10000。
你可以假定提莫攻击时间序列中的数字和提莫攻击的中毒持续时间都是非负整数，并且不超过 10,000,000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/teemo-attacking
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int totalDuration = 0, size = timeSeries.size();

        if (size == 0) {
            return 0;
        }

        for (int i = 1; i < size; i++) {
            int interval = timeSeries[i] - timeSeries[i - 1];
            if (interval > duration) {
                totalDuration += duration;
            }
            else {
                totalDuration += interval;
            }
        }

        return totalDuration + duration;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> timeSeries = {};
    check.checkInt(0, o.findPoisonedDuration(timeSeries, 5));

    timeSeries = { 0 };
    check.checkInt(5, o.findPoisonedDuration(timeSeries, 5));

    timeSeries = { 5 };
    check.checkInt(0, o.findPoisonedDuration(timeSeries, 0));

    timeSeries = { 1,4 };
    check.checkInt(4, o.findPoisonedDuration(timeSeries, 2));

    timeSeries = { 1,2 };
    check.checkInt(3, o.findPoisonedDuration(timeSeries, 2));

    timeSeries = { 1,2,3,4,5,6,7,8,9 };
    check.checkInt(10, o.findPoisonedDuration(timeSeries, 2));

    timeSeries = { 1,2,3,4,5,6,7,8,9 };
    check.checkInt(13, o.findPoisonedDuration(timeSeries, 5));

    timeSeries = { 1,2,3,6,8,9,10 };
    check.checkInt(10, o.findPoisonedDuration(timeSeries, 2));
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
