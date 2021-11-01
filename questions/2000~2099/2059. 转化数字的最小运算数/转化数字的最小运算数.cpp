/* 转化数字的最小运算数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums ，该数组由 互不相同 的数字组成。另给你两个整数 start 和 goal 。

整数 x 的值最开始设为 start ，你打算执行一些运算使 x 转化为 goal 。你可以对数字 x 重复执行下述运算：

如果 0 <= x <= 1000 ，那么，对于数组中的任一下标 i（0 <= i < nums.length），可以将 x 设为下述任一值：

x + nums[i]
x - nums[i]
x ^ nums[i]（按位异或 XOR）
注意，你可以按任意顺序使用每个 nums[i] 任意次。使 x 越过 0 <= x <= 1000 范围的运算同样可以生效，但该该运算执行后将不能执行其他运算。

返回将 x = start 转化为 goal 的最小操作数；如果无法完成转化，则返回 -1 。

 

示例 1：

输入：nums = [1,3], start = 6, goal = 4
输出：2
解释：
可以按 6 → 7 → 4 的转化路径进行，只需执行下述 2 次运算：
- 6 ^ 1 = 7
- 7 ^ 3 = 4
示例 2：

输入：nums = [2,4,12], start = 2, goal = 12
输出：2
解释：
可以按 2 → 14 → 12 的转化路径进行，只需执行下述 2 次运算：
- 2 + 12 = 14
- 14 - 2 = 12
示例 3：

输入：nums = [3,5,7], start = 0, goal = -4
输出：2
解释：
可以按 0 → 3 → -4 的转化路径进行，只需执行下述 2 次运算：
- 0 + 3 = 3
- 3 - 7 = -4
注意，最后一步运算使 x 超过范围 0 <= x <= 1000 ，但该运算仍然可以生效。
示例 4：

输入：nums = [2,8,16], start = 0, goal = 1
输出：-1
解释：
无法将 0 转化为 1
示例 5：

输入：nums = [1], start = 0, goal = 3
输出：3
解释：
可以按 0 → 1 → 2 → 3 的转化路径进行，只需执行下述 3 次运算：
- 0 + 1 = 1
- 1 + 1 = 2
- 2 + 1 = 3
 

提示：

1 <= nums.length <= 1000
-109 <= nums[i], goal <= 109
0 <= start <= 1000
start != goal
nums 中的所有整数互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-operations-to-convert-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int opers = 0;
        vector<bool> visited(1001, false);
        visited[start] = true;
        queue<int> nodes;
        nodes.push(start);

        while (!nodes.empty()) {
            int i, size = nodes.size();
            ++opers;

            for (i = 0; i < size; ++i) {
                int node = nodes.front();
                nodes.pop();

                for (int num : nums) {
                    int next = node + num;
                    if (next == goal) {
                        return opers;
                    }

                    if (next >= 0 && next <= 1000 && !visited[next]) {
                        visited[next] = true;
                        nodes.push(next);
                    }

                    next = node - num;
                    if (next == goal) {
                        return opers;
                    }

                    if (next >= 0 && next <= 1000 && !visited[next]) {
                        visited[next] = true;
                        nodes.push(next);
                    }

                    next = node ^ num;
                    if (next == goal) {
                        return opers;
                    }

                    if (next >= 0 && next <= 1000 && !visited[next]) {
                        visited[next] = true;
                        nodes.push(next);
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3 };
    check.checkInt(2, o.minimumOperations(nums, 6, 4));
    
    nums = { 2,4,12 };
    check.checkInt(2, o.minimumOperations(nums, 2, 12));

    nums = { 3,5,7 };
    check.checkInt(2, o.minimumOperations(nums, 0, -4));

    nums = { 2,8,16 };
    check.checkInt(-1, o.minimumOperations(nums, 0, 1));

    nums = { 1 };
    check.checkInt(3, o.minimumOperations(nums, 0, 3));

    nums = { -100001,100002 };
    check.checkInt(-1, o.minimumOperations(nums, 1, 2));
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
