/* 统计特殊四元组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 下标从 0 开始 的整数数组 nums ，返回满足下述条件的 不同 四元组 (a, b, c, d) 的 数目 ：

nums[a] + nums[b] + nums[c] == nums[d] ，且
a < b < c < d
 

示例 1：

输入：nums = [1,2,3,6]
输出：1
解释：满足要求的唯一一个四元组是 (0, 1, 2, 3) 因为 1 + 2 + 3 == 6 。
示例 2：

输入：nums = [3,3,6,4,5]
输出：0
解释：[3,3,6,4,5] 中不存在满足要求的四元组。
示例 3：

输入：nums = [1,1,1,3,5]
输出：4
解释：满足要求的 4 个四元组如下：
- (0, 1, 2, 3): 1 + 1 + 1 == 3
- (0, 1, 3, 4): 1 + 1 + 3 == 5
- (0, 2, 3, 4): 1 + 1 + 3 == 5
- (1, 2, 3, 4): 1 + 1 + 3 == 5
 

提示：

4 <= nums.length <= 50
1 <= nums[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-special-quadruplets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int i, j, size = nums.size(), count = 0;
        vector<vector<pair<int, int>>> twoSums(201);

        for (i = 0; i < size - 1; ++i) {
            for (j = i + 1; j < size; ++j) {
                twoSums[nums[i] + nums[j]].push_back({ i, j });
            }
        }

        for (i = 0; i < size - 1; ++i) {
            for (j = i + 1; j < size; ++j) {
                if (nums[j] > nums[i]) {
                    for (auto& twoNums : twoSums[nums[j] - nums[i]]) {
                        if (twoNums.first < j && twoNums.second < j && twoNums.first != i && twoNums.second != i) {
                            ++count;
                        }
                    }
                }
            }
        }

        return count / 3;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,6 };
    check.checkInt(1, o.countQuadruplets(nums));

    nums = { 3,3,6,4,5 };
    check.checkInt(0, o.countQuadruplets(nums));

    nums = { 1,1,1,3,5 };
    check.checkInt(4, o.countQuadruplets(nums));

    nums = { 1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10 };
    check.checkInt(3965, o.countQuadruplets(nums));
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
