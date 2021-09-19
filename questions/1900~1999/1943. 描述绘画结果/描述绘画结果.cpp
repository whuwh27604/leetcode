/* 描述绘画结果.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个细长的画，用数轴表示。这幅画由若干有重叠的线段表示，每个线段有 独一无二 的颜色。给你二维整数数组 segments ，其中 segments[i] = [starti, endi, colori] 表示线段为 半开区间 [starti, endi) 且颜色为 colori 。

线段间重叠部分的颜色会被 混合 。如果有两种或者更多颜色混合时，它们会形成一种新的颜色，用一个 集合 表示这个混合颜色。

比方说，如果颜色 2 ，4 和 6 被混合，那么结果颜色为 {2,4,6} 。
为了简化题目，你不需要输出整个集合，只需要用集合中所有元素的 和 来表示颜色集合。

你想要用 最少数目 不重叠 半开区间 来 表示 这幅混合颜色的画。这些线段可以用二维数组 painting 表示，其中 painting[j] = [leftj, rightj, mixj] 表示一个 半开区间[leftj, rightj) 的颜色 和 为 mixj 。

比方说，这幅画由 segments = [[1,4,5],[1,7,7]] 组成，那么它可以表示为 painting = [[1,4,12],[4,7,7]] ，因为：
[1,4) 由颜色 {5,7} 组成（和为 12），分别来自第一个线段和第二个线段。
[4,7) 由颜色 {7} 组成，来自第二个线段。
请你返回二维数组 painting ，它表示最终绘画的结果（没有 被涂色的部分不出现在结果中）。你可以按 任意顺序 返回最终数组的结果。

半开区间 [a, b) 是数轴上点 a 和点 b 之间的部分，包含 点 a 且 不包含 点 b 。

 

示例 1：


输入：segments = [[1,4,5],[4,7,7],[1,7,9]]
输出：[[1,4,14],[4,7,16]]
解释：绘画借故偶可以表示为：
- [1,4) 颜色为 {5,9} （和为 14），分别来自第一和第二个线段。
- [4,7) 颜色为 {7,9} （和为 16），分别来自第二和第三个线段。
示例 2：


输入：segments = [[1,7,9],[6,8,15],[8,10,7]]
输出：[[1,6,9],[6,7,24],[7,8,15],[8,10,7]]
解释：绘画结果可以以表示为：
- [1,6) 颜色为 9 ，来自第一个线段。
- [6,7) 颜色为 {9,15} （和为 24），来自第一和第二个线段。
- [7,8) 颜色为 15 ，来自第二个线段。
- [8,10) 颜色为 7 ，来自第三个线段。
示例 3：


输入：segments = [[1,4,5],[1,4,7],[4,7,1],[4,7,11]]
输出：[[1,4,12],[4,7,12]]
解释：绘画结果可以表示为：
- [1,4) 颜色为 {5,7} （和为 12），分别来自第一和第二个线段。
- [4,7) 颜色为 {1,11} （和为 12），分别来自第三和第四个线段。
注意，只返回一个单独的线段 [1,7) 是不正确的，因为混合颜色的集合不相同。
 

提示：

1 <= segments.length <= 2 * 104
segments[i].length == 3
1 <= starti < endi <= 105
1 <= colori <= 109
每种颜色 colori 互不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/describe-the-painting
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int minStart = INT_MAX, maxEnd = 0;
        getStartEnd(segments, minStart, maxEnd);

        vector<vector<long long>> painting;
        vector<long long> colors(maxEnd + 1, 0);
        vector<bool> newSegment(maxEnd + 1, false);

        for (auto& segment : segments) {
            colors[segment[0]] += segment[2];
            colors[segment[1]] -= segment[2];
            newSegment[segment[0]] = true;
        }

        int start = minStart;

        for (int i = minStart + 1; i <= maxEnd; ++i) {
            colors[i] += colors[i - 1];

            if (colors[i] != colors[i - 1] || newSegment[i]) {
                if (colors[i - 1] != 0) {  // 没涂色的部分不体现在结果中
                    painting.push_back({ start,i,colors[i - 1] });
                }

                start = i;
            }
        }

        return painting;
    }

    void getStartEnd(vector<vector<int>>& segments, int& minStart, int& maxEnd) {
        for (auto& segment : segments) {
            minStart = min(minStart, segment[0]);
            maxEnd = max(maxEnd, segment[1]);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> segments = { {1,4,5},{1,4,7},{4,7,1},{4,7,11} };
    vector<vector<long long>> actual = o.splitPainting(segments);
    vector<vector<long long>> expected = { {1,4,12},{4,7,12} };
    check.checkLongLongVectorRandomOrderVector(expected, actual);

    segments = { {1,7,9},{6,8,15},{8,10,7} };
    actual = o.splitPainting(segments);
    expected = { {1,6,9},{6,7,24},{7,8,15},{8,10,7} };
    check.checkLongLongVectorRandomOrderVector(expected, actual);

    segments = { {1,4,5},{4,7,7},{1,7,9} };
    actual = o.splitPainting(segments);
    expected = { {1,4,14},{4,7,16} };
    check.checkLongLongVectorRandomOrderVector(expected, actual);

    segments = { {1,5,1},{10,16,7} };
    actual = o.splitPainting(segments);
    expected = { {1,5,1},{10,16,7} };
    check.checkLongLongVectorRandomOrderVector(expected, actual);

    segments = { {1,5,1} };
    actual = o.splitPainting(segments);
    expected = { {1,5,1} };
    check.checkLongLongVectorRandomOrderVector(expected, actual);

    segments = { {1,16,1000000000},{5,20,999999999},{8,30,888888888} };
    actual = o.splitPainting(segments);
    expected = { {1,5,1000000000},{5,8,1999999999},{8,16,2888888887},{16,20,1888888887},{20,30,888888888 } };
    check.checkLongLongVectorRandomOrderVector(expected, actual);
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
