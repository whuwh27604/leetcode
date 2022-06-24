/* 设置交集大小至少为2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个整数区间 [a, b]  ( a < b ) 代表着从 a 到 b 的所有连续整数，包括 a 和 b。

给你一组整数区间intervals，请找到一个最小的集合 S，使得 S 里的元素与区间intervals中的每一个整数区间都至少有2个元素相交。

输出这个最小集合S的大小。

示例 1:

输入: intervals = [[1, 3], [1, 4], [2, 5], [3, 5]]
输出: 3
解释:
考虑集合 S = {2, 3, 4}. S与intervals中的四个区间都有至少2个相交的元素。
且这是S最小的情况，故我们输出3。
示例 2:

输入: intervals = [[1, 2], [2, 3], [2, 4], [4, 5]]
输出: 5
解释:
最小的集合S = {1, 2, 3, 4, 5}.
注意:

intervals 的长度范围为[1, 3000]。
intervals[i] 长度为 2，分别代表左、右边界。
intervals[i][j] 的值是 [0, 10^8]范围内的整数。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/set-intersection-size-at-least-two
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

// 按end升序排序，end相同则按start降序排序，这样可以确保前面的interval有两个点时，后面的interval一定也有两个点。
bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] == v2[1] ? v1[0] > v2[0] : v1[1] < v2[1];
}

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int setSize = 0, last1 = -1, last2 = -1;

        sort(intervals.begin(), intervals.end(), vectorCompare);

        for (auto& interval : intervals) {
            if (interval[0] <= last1) {
                continue;  // last1、last2都在这个区间，已经满足条件
            }
            else if (interval[0] > last1 && interval[0] <= last2) {
                last1 = last2;  // 只有last2在区间内，还差一个点，贪心的选择区间最右边的点
                last2 = interval[1];
                ++setSize;
            }
            else {  // 该区间还没有点，贪心选择最右边两个
                last1 = interval[1] - 1;
                last2 = interval[1];
                setSize += 2;
            }
        }

        return setSize;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> intervals = { {1,3},{1,4},{2,5},{3,5} };
    check.checkInt(3, o.intersectionSizeTwo(intervals));

    intervals = { {1,2},{2,3},{2,4},{4,5} };
    check.checkInt(5, o.intersectionSizeTwo(intervals));
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
