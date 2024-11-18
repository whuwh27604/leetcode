/* 使数组元素等于零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 。

开始时，选择一个满足 nums[curr] == 0 的起始位置 curr ，并选择一个移动 方向 ：向左或者向右。

此后，你需要重复下面的过程：

如果 curr 超过范围 [0, n - 1] ，过程结束。
如果 nums[curr] == 0 ，沿当前方向继续移动：如果向右移，则 递增 curr ；如果向左移，则 递减 curr 。
如果 nums[curr] > 0:
将 nums[curr] 减 1 。
反转 移动方向（向左变向右，反之亦然）。
沿新方向移动一步。
如果在结束整个过程后，nums 中的所有元素都变为 0 ，则认为选出的初始位置和移动方向 有效 。

返回可能的有效选择方案数目。



示例 1：

输入：nums = [1,0,2,0,3]

输出：2

解释：

可能的有效选择方案如下：

选择 curr = 3 并向左移动。
[1,0,2,0,3] -> [1,0,2,0,3] -> [1,0,1,0,3] -> [1,0,1,0,3] -> [1,0,1,0,2] -> [1,0,1,0,2] -> [1,0,0,0,2] -> [1,0,0,0,2] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,0].
选择 curr = 3 并向右移动。
[1,0,2,0,3] -> [1,0,2,0,3] -> [1,0,2,0,2] -> [1,0,2,0,2] -> [1,0,1,0,2] -> [1,0,1,0,2] -> [1,0,1,0,1] -> [1,0,1,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [0,0,0,0,0].
示例 2：

输入：nums = [2,3,4,0,4,1,0]

输出：0

解释：

不存在有效的选择方案。



提示：

1 <= nums.length <= 100
0 <= nums[i] <= 100
至少存在一个元素 i 满足 nums[i] == 0 。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int size = (int)nums.size(), count = 0;
        vector<int> presum(size + 2, 0);

        for (int i = 0; i < size; ++i) {
            presum[i + 1] = presum[i] + nums[i];
        }

        presum[size + 1] = presum[size];

        for (int i = 0; i < size; ++i) {
            if (nums[i] == 0) {
                int left = presum[i], right = presum[size + 1] - presum[i + 1];
                if (left == right) {
                    count += 2;
                }
                else if (left == right + 1 || left + 1 == right) {
                    count += 1;
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,0,2,0,3 };
    check.checkInt(2, o.countValidSelections(nums));

    nums = { 2,3,4,0,4,1,0 };
    check.checkInt(0, o.countValidSelections(nums));

    nums = { 0 };
    check.checkInt(2, o.countValidSelections(nums));

    nums = { 0,0 };
    check.checkInt(4, o.countValidSelections(nums));

    nums = { 1,0 };
    check.checkInt(1, o.countValidSelections(nums));
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
