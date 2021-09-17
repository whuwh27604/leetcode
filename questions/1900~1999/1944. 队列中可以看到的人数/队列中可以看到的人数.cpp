/* 队列中可以看到的人数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 n 个人排成一个队列，从左到右 编号为 0 到 n - 1 。给你以一个整数数组 heights ，每个整数 互不相同，heights[i] 表示第 i 个人的高度。

一个人能 看到 他右边另一个人的条件是这两人之间的所有人都比他们两人 矮 。更正式的，第 i 个人能看到第 j 个人的条件是 i < j 且 min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]) 。

请你返回一个长度为 n 的数组 answer ，其中 answer[i] 是第 i 个人在他右侧队列中能 看到 的 人数 。

 

示例 1：



输入：heights = [10,6,8,5,11,9]
输出：[3,1,2,1,1,0]
解释：
第 0 个人能看到编号为 1 ，2 和 4 的人。
第 1 个人能看到编号为 2 的人。
第 2 个人能看到编号为 3 和 4 的人。
第 3 个人能看到编号为 4 的人。
第 4 个人能看到编号为 5 的人。
第 5 个人谁也看不到因为他右边没人。
示例 2：

输入：heights = [5,1,2,3,10]
输出：[4,1,1,1,0]
 

提示：

n == heights.length
1 <= n <= 105
1 <= heights[i] <= 105
heights 中所有数 互不相同 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-visible-people-in-a-queue
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int i, size = heights.size();
        stack<int> decreasing;
        vector<int> seePersons(size);

        for (i = size - 1; i >= 0; --i) {
            int count = 0;

            while (!decreasing.empty() && heights[i] > heights[decreasing.top()]) {
                decreasing.pop();
                ++count;
            }

            seePersons[i] = decreasing.empty() ? count : count + 1;
            decreasing.push(i);
        }

        return seePersons;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> heights = { 10,6,8,5,11,9 };
    vector<int> actual = o.canSeePersonsCount(heights);
    vector<int> expected = { 3,1,2,1,1,0 };
    check.checkIntVector(expected, actual);

    heights = { 5,1,2,3,10 };
    actual = o.canSeePersonsCount(heights);
    expected = { 4,1,1,1,0 };
    check.checkIntVector(expected, actual);

    heights = { 5 };
    actual = o.canSeePersonsCount(heights);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    heights = { 1,2,3,4,5 };
    actual = o.canSeePersonsCount(heights);
    expected = { 1,1,1,1,0 };
    check.checkIntVector(expected, actual);

    heights = { 5,4,3,2,1 };
    actual = o.canSeePersonsCount(heights);
    expected = { 1,1,1,1,0 };
    check.checkIntVector(expected, actual);

    heights = { 37,31,26,40,13,15,18,34,45,19,11,21,1,29,12,38,44,25,8,36,5,24,16,14,39,22,32,47,33,2,42,4,46,30,50,6,27,3,20,7,35,49,28,43,17,10,41,9,23,48 };
    actual = o.canSeePersonsCount(heights);
    expected = { 2,2,1,5,1,1,1,1,6,2,1,2,1,2,1,1,4,2,1,3,1,2,2,1,3,1,1,4,2,1,2,1,2,1,4,1,3,1,2,1,1,3,1,3,2,1,3,1,1,0 };
    check.checkIntVector(expected, actual);

    heights = { 49,40,13,26,38,5,32,50,31,19,21,36,17,6,33,47,1,10,25,12,27,14,28,3,7,44,8,39,18,37,4,34,24,20,42,43,9,48,35,29,23,22,2,30,45,16,41,11,46,15 };
    actual = o.canSeePersonsCount(heights);
    expected = { 2,4,1,1,3,1,1,4,3,1,1,3,2,1,1,7,1,1,2,1,2,1,3,1,1,5,1,3,1,3,1,2,2,1,1,2,1,3,3,2,2,2,1,1,3,1,2,1,1,0 };
    check.checkIntVector(expected, actual);

    heights = { 36,12,25,44,23,8,47,22,20,17,4,49,14,38,40,31,9,1,46,16,11,33,21,48,2,7,30,43,27,32,26,34,24,29,37,15,42,3,18,39,35,50,19,28,5,10,41,45,6,13 };
    actual = o.canSeePersonsCount(heights);
    expected = { 3,1,1,2,2,1,2,2,2,2,1,6,1,1,2,2,2,1,3,2,1,2,1,5,1,1,1,6,1,2,1,3,1,1,2,1,4,1,1,2,1,4,1,3,1,1,1,2,1,0 };
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
