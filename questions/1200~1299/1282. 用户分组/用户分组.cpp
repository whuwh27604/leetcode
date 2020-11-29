/* 用户分组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 n 位用户参加活动，他们的 ID 从 0 到 n - 1，每位用户都 恰好 属于某一用户组。给你一个长度为 n 的数组 groupSizes，其中包含每位用户所处的用户组的大小，请你返回用户分组情况（存在的用户组以及每个组中用户的 ID）。

你可以任何顺序返回解决方案，ID 的顺序也不受限制。此外，题目给出的数据保证至少存在一种解决方案。

 

示例 1：

输入：groupSizes = [3,3,3,3,3,1,3]
输出：[[5],[0,1,2],[3,4,6]]
解释：
其他可能的解决方案有 [[2,1,6],[5],[0,4,3]] 和 [[5],[0,6,2],[4,3,1]]。
示例 2：

输入：groupSizes = [2,1,3,3,3,2]
输出：[[1],[0,5],[2,3,4]]
 

提示：

groupSizes.length == n
1 <= n <= 500
1 <= groupSizes[i] <= n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-the-people-given-the-group-size-they-belong-to
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> groups, tmp(501);

        for (int i = 0; i < (int)groupSizes.size(); ++i) {
            int groupSize = groupSizes[i];
            tmp[groupSize].push_back(i);

            if (tmp[groupSize].size() == groupSize) {
                groups.push_back(tmp[groupSize]);
                tmp[groupSize].clear();
            }
        }

        return groups;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> groupSizes = { 3,3,3,3,3,1,3 };
    vector<vector<int>> actual = o.groupThePeople(groupSizes);
    vector<vector<int>> expected = { {0,1,2},{5},{3,4,6} };
    check.checkIntVectorVector(expected, actual);

    groupSizes = { 2,1,3,3,3,2 };
    actual = o.groupThePeople(groupSizes);
    expected = { {1},{2,3,4},{0,5} };
    check.checkIntVectorVector(expected, actual);

    groupSizes = { 1 };
    actual = o.groupThePeople(groupSizes);
    expected = { {0} };
    check.checkIntVectorVector(expected, actual);
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
