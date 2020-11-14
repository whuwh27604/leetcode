/* 最接近的三数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

 

示例：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 

提示：

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int i, len = nums.size(), left, right;
        int diff, minDiff = INT_MAX, sum, ans = 0, ret;
        for (i = 0; i < len - 2; (void)next(nums, i)) {
            left = i + 1;
            right = len - 1;
            sum = nums[i] + nums[left] + nums[left + 1];
            if (sum >= target) {
                diff = sum - target;
                return (diff <= minDiff) ? sum : ans;
            }
            sum = nums[i] + nums[right - 1] + nums[right];
            if (sum < target) {
                diff = target - sum;
                if (diff < minDiff) {
                    minDiff = diff;
                    ans = sum;
                }
                continue;
            }

            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum == target) {
                    return target;
                }

                diff = abs(sum - target);
                if (diff < minDiff) {
                    minDiff = diff;
                    ans = sum;
                }

                if (sum > target) {
                    ret = previous(nums, right);
                }
                else {
                    ret = next(nums, left);
                }
                if (ret != 0) {
                    break;
                }
            }
        }

        return ans;
    }

    int next(vector<int>& nums, int& index) {
        int num = nums[index], len = nums.size();

        while (nums[index] == num) {
            index++;
            if (index >= len) {
                return -1;
            }
        }

        return 0;
    }

    int previous(vector<int>& nums, int& index) {
        int num = nums[index];

        while (nums[index] == num) {
            index--;
            if (index < 0) {
                return -1;
            }
        }

        return 0;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { -1,2,1,-4 };
    check.checkInt(2, o.threeSumClosest(nums, 1));
    
    nums = { 1,2,3 };
    check.checkInt(6, o.threeSumClosest(nums, 10));

    nums = { 1,2,3 };
    check.checkInt(6, o.threeSumClosest(nums, -10));

    nums = { -1,-2,-3,-4,-5 };
    check.checkInt(-6, o.threeSumClosest(nums, 0));

    nums = { 1,2,3,4,5 };
    check.checkInt(6, o.threeSumClosest(nums, 0));

    nums = { 1,3,2,2,2 };
    check.checkInt(6, o.threeSumClosest(nums, 6));

    nums = { 1,1,3,3,3,3 };
    check.checkInt(9, o.threeSumClosest(nums, 8));

    nums = { 0,1,3,3,3,3 };
    check.checkInt(9, o.threeSumClosest(nums, 8));

    nums = { 2,2,2,2,5,6,7 };
    check.checkInt(6, o.threeSumClosest(nums, 7));
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
