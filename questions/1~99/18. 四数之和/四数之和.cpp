/* 四数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int i, j, len = nums.size(), left, right, ret;
        vector<vector<int>> ans;

        for (i = 0; i < len - 3; next(nums, i)) {
            if (((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3]) > target) {
                break;
            }
            if (((long long)nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1]) < target) {
                continue;
            }

            for (j = i + 1; j < len - 2; next(nums, j)) {
                if (((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2]) > target) {
                    break;
                }
                if (((long long)nums[i] + nums[j] + nums[len - 2] + nums[len - 1]) < target) {
                    continue;
                }

                left = j + 1;
                right = len - 1;
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        ans.push_back({ nums[i],nums[j],nums[left],nums[right] });
                        ret = next(nums, left);
                        ret += previous(nums, right);
                    }
                    else if (sum > target) {
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
        }

        return ans;
    }

    int next(vector<int>& nums, int& index) {
        int n = nums[index], len = nums.size();
        while ((index < len) && (nums[index] == n)) {
            index++;
        }

        return (index == len) ? -1 : 0;
    }

    int previous(vector<int>& nums, int& index) {
        int n = nums[index], len = nums.size();
        while ((index >= 0) && (nums[index] == n)) {
            index--;
        }

        return (index == -1) ? -1 : 0;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,0,-1,0,-2,2 };
    vector<vector<int>> actual = o.fourSum(nums, 0);
    vector<vector<int>> expected = { {-2,-1,1,2},{-2,0,0,2},{-1,0,0,1} };
    check.checkIntDoubleVector(expected, actual);

    nums = { 1,1,1,0,0,-1,-1,-1 };
    actual = o.fourSum(nums, 4);
    expected = {  };
    check.checkIntDoubleVector(expected, actual);

    nums = { 1,1,1,0,0,-1,-1,-1 };
    actual = o.fourSum(nums, 2);
    expected = { {-1,1,1,1},{0,0,1,1} };
    check.checkIntDoubleVector(expected, actual);

    nums = { 1,1,1,0,0,-1,-1,-1 };
    actual = o.fourSum(nums, 0);
    expected = { {-1,-1,1,1},{-1,0,0,1} };
    check.checkIntDoubleVector(expected, actual);

    nums = {  };
    actual = o.fourSum(nums, 0);
    expected = {  };
    check.checkIntDoubleVector(expected, actual);

    nums = { -1 };
    actual = o.fourSum(nums, 0);
    expected = {  };
    check.checkIntDoubleVector(expected, actual);

    nums = { 1,-1 };
    actual = o.fourSum(nums, 0);
    expected = {  };
    check.checkIntDoubleVector(expected, actual);

    nums = { 1,0,-1 };
    actual = o.fourSum(nums, 0);
    expected = {  };
    check.checkIntDoubleVector(expected, actual);

    nums = { 1000000000,1000000000,1000000000,1000000000 };
    actual = o.fourSum(nums, 0);
    expected = {  };
    check.checkIntDoubleVector(expected, actual);
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
