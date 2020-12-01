/* 删除被覆盖区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。

只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。

在完成所有删除操作后，请你返回列表中剩余区间的数目。

 

示例：

输入：intervals = [[1,4],[3,6],[2,8]]
输出：2
解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。
 

提示：​​​​​​

1 <= intervals.length <= 1000
0 <= intervals[i][0] < intervals[i][1] <= 10^5
对于所有的 i != j：intervals[i] != intervals[j]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-covered-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool sortVector(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0];
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sortVector);

        int intervalsLeft = 0, rightmost = 0;

        for (vector<int>& interval : intervals) {
            if (interval[1] > rightmost) {
                rightmost = interval[1];
                ++intervalsLeft;
            }
        }

        return intervalsLeft;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> intervals = { {1,4},{3,6},{2,8} };
    check.checkInt(2, o.removeCoveredIntervals(intervals));

    intervals = { {1,2} };
    check.checkInt(1, o.removeCoveredIntervals(intervals));

    intervals = { {1,5},{2,7},{3,10} };
    check.checkInt(3, o.removeCoveredIntervals(intervals));
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
