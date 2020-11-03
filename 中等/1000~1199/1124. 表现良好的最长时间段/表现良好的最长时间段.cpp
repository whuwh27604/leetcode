/* 表现良好的最长时间段.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。

我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。

所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。

请你返回「表现良好时间段」的最大长度。

 

示例 1：

输入：hours = [9,9,6,0,6,6,9]
输出：3
解释：最长的表现良好时间段是 [9,9,6]。
 

提示：

1 <= hours.length <= 10000
0 <= hours[i] <= 16

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-well-performing-interval
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int i, size = hours.size(), preSum = 0, maxWPI = 0;
        unordered_map<int, int> preSumIndex;

        for (i = 0; i < size; ++i) {
            preSum += (hours[i] > 8) ? 1 : -1;
            if (preSum > 0) {  // 如果前缀和大于0，说明从第一天到当前天tiring days一定大于non-tiring days，并且当前i是最长的，所以i+1就是答案
                maxWPI = i + 1;
                continue;
            }

            if (preSumIndex.count(preSum) == 0) {
                preSumIndex[preSum] = i;  // 第一次出现某个前缀和，记录它的index
            }

            /* 前面有preSum-1出现，现在是preSum，说明两者之间tiring days大于non-tiring days
               1、由于preSum-1和preSum只相差1，这是满足tiring days大于non-tiring days最极限的条件了
               2、由于index记录的是第一次出现的值，所以两者的index差是最大的，所以这两个条件得到的是一个局部最长WPI */
            if (preSumIndex.count(preSum - 1) != 0) {
                int WPI = i - preSumIndex[preSum - 1];
                maxWPI = max(maxWPI, WPI);
            }
        }

        return maxWPI;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> hours = { 9,9,6,0,6,6,9 };
    check.checkInt(3, o.longestWPI(hours));

    hours = { 9 };
    check.checkInt(1, o.longestWPI(hours));

    hours = { 9,9,9,9,9 };
    check.checkInt(5, o.longestWPI(hours));

    hours = { 8 };
    check.checkInt(0, o.longestWPI(hours));

    hours = { 9,9,6,0 };
    check.checkInt(3, o.longestWPI(hours));

    hours = { 9,9,6,0,9 };
    check.checkInt(5, o.longestWPI(hours));
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
