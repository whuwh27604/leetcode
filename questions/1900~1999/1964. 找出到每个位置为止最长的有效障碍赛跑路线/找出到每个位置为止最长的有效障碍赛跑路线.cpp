/* 找出到每个位置为止最长的有效障碍赛跑路线.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你打算构建一些障碍赛跑路线。给你一个 下标从 0 开始 的整数数组 obstacles ，数组长度为 n ，其中 obstacles[i] 表示第 i 个障碍的高度。

对于每个介于 0 和 n - 1 之间（包含 0 和 n - 1）的下标  i ，在满足下述条件的前提下，请你找出 obstacles 能构成的最长障碍路线的长度：

你可以选择下标介于 0 到 i 之间（包含 0 和 i）的任意个障碍。
在这条路线中，必须包含第 i 个障碍。
你必须按障碍在 obstacles 中的 出现顺序 布置这些障碍。
除第一个障碍外，路线中每个障碍的高度都必须和前一个障碍 相同 或者 更高 。
返回长度为 n 的答案数组 ans ，其中 ans[i] 是上面所述的下标 i 对应的最长障碍赛跑路线的长度。

 

示例 1：

输入：obstacles = [1,2,3,2]
输出：[1,2,3,3]
解释：每个位置的最长有效障碍路线是：
- i = 0: [1], [1] 长度为 1
- i = 1: [1,2], [1,2] 长度为 2
- i = 2: [1,2,3], [1,2,3] 长度为 3
- i = 3: [1,2,3,2], [1,2,2] 长度为 3
示例 2：

输入：obstacles = [2,2,1]
输出：[1,2,1]
解释：每个位置的最长有效障碍路线是：
- i = 0: [2], [2] 长度为 1
- i = 1: [2,2], [2,2] 长度为 2
- i = 2: [2,2,1], [1] 长度为 1
示例 3：

输入：obstacles = [3,1,5,6,4,2]
输出：[1,1,2,3,2,2]
解释：每个位置的最长有效障碍路线是：
- i = 0: [3], [3] 长度为 1
- i = 1: [3,1], [1] 长度为 1
- i = 2: [3,1,5], [3,5] 长度为 2, [1,5] 也是有效的障碍赛跑路线
- i = 3: [3,1,5,6], [3,5,6] 长度为 3, [1,5,6] 也是有效的障碍赛跑路线
- i = 4: [3,1,5,6,4], [3,4] 长度为 2, [1,4] 也是有效的障碍赛跑路线
- i = 5: [3,1,5,6,4,2], [1,2] 长度为 2
 

提示：

n == obstacles.length
1 <= n <= 105
1 <= obstacles[i] <= 107

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-longest-valid-obstacle-course-at-each-position
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int i, size = obstacles.size(), len = 1;
        vector<int> longestObstacles(size);
        longestObstacles[0] = 1;
        vector<int> minValues(size + 1, 0);  // minValues[i]表示LIS长度为i时，最后一个数的最小值，显然minValues单调不降
        minValues[1] = obstacles[0];

        for (i = 1; i < size; ++i) {
            if (obstacles[i] >= minValues[len]) {  // 如果比当前LIS的最后一个数大，那么可以直接添加在后面，LIS长度加1
                minValues[++len] = obstacles[i];
                longestObstacles[i] = len;
            }
            else {  // 否则用obstacles[i]更新第一个大于obstacles[i]的minValues，即完成相同长度的LIS，最后一个数可以更小
                auto iter = upper_bound(minValues.begin(), minValues.begin() + len + 1, obstacles[i]);
                *iter = obstacles[i];
                longestObstacles[i] = distance(minValues.begin(), iter);
            }
        }

        return longestObstacles;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> obstacles = { 1,2,3,2 };
    vector<int> actual = o.longestObstacleCourseAtEachPosition(obstacles);
    vector<int> expected = { 1,2,3,3 };
    check.checkIntVector(expected, actual);

    obstacles = { 2,2,1 };
    actual = o.longestObstacleCourseAtEachPosition(obstacles);
    expected = { 1,2,1 };
    check.checkIntVector(expected, actual);

    obstacles = { 3,1,5,6,4,2 };
    actual = o.longestObstacleCourseAtEachPosition(obstacles);
    expected = { 1,1,2,3,2,2 };
    check.checkIntVector(expected, actual);

    obstacles = { 3 };
    actual = o.longestObstacleCourseAtEachPosition(obstacles);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    obstacles = { 1,2,3,4,5 };
    actual = o.longestObstacleCourseAtEachPosition(obstacles);
    expected = { 1,2,3,4,5 };
    check.checkIntVector(expected, actual);

    obstacles = { 5,4,3,2,1 };
    actual = o.longestObstacleCourseAtEachPosition(obstacles);
    expected = { 1,1,1,1,1 };
    check.checkIntVector(expected, actual);

    obstacles = { 3,1,5,6,4,2,3,1,5,6,4,2,3,1,5,6,4,2,3,1,5,6,4,2,3,1,5,6,4,2,3,1,5,6,4,2,3,1,5,6,4,2,3,1,5,6,4,2,3,1,5,6,4,2 };
    actual = o.longestObstacleCourseAtEachPosition(obstacles);
    expected = { 1,1,2,3,2,2,3,2,4,5,4,3,4,3,5,6,5,4,5,4,6,7,6,5,6,5,7,8,7,6,7,6,8,9,8,7,8,7,9,10,9,8,9,8,10,11,10,9,10,9,11,12,11,10 };
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
