/* 分组的最大数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 grades ，表示大学中一些学生的成绩。你打算将 所有 学生分为一些 有序 的非空分组，其中分组间的顺序满足以下全部条件：

第 i 个分组中的学生总成绩 小于 第 (i + 1) 个分组中的学生总成绩，对所有组均成立（除了最后一组）。
第 i 个分组中的学生总数 小于 第 (i + 1) 个分组中的学生总数，对所有组均成立（除了最后一组）。
返回可以形成的 最大 组数。

 

示例 1：

输入：grades = [10,6,12,7,3,5]
输出：3
解释：下面是形成 3 个分组的一种可行方法：
- 第 1 个分组的学生成绩为 grades = [12] ，总成绩：12 ，学生数：1
- 第 2 个分组的学生成绩为 grades = [6,7] ，总成绩：6 + 7 = 13 ，学生数：2
- 第 3 个分组的学生成绩为 grades = [10,3,5] ，总成绩：10 + 3 + 5 = 18 ，学生数：3
可以证明无法形成超过 3 个分组。
示例 2：

输入：grades = [8,8]
输出：1
解释：只能形成 1 个分组，因为如果要形成 2 个分组的话，会导致每个分组中的学生数目相等。
 

提示：

1 <= grades.length <= 105
1 <= grades[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-number-of-groups-entering-a-competition
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int size = grades.size(), group = (int)sqrt(2 * size);

        return (group + 1) * group / 2 > size ? group - 1 : group;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> grades = { 10,6,12,7,3,5 };
    check.checkInt(3, o.maximumGroups(grades));

    grades = { 8,8 };
    check.checkInt(1, o.maximumGroups(grades));
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
