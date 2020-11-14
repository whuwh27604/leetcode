/* 三数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int i, len = nums.size(), left, right, ret;
        for (i = 0; i < len - 2; (void)next(nums, i)) {
            left = i + 1;
            right = len - 1;
            if ((nums[i] + 2 * nums[left]) > 0) {
                break;
            }
            if ((nums[i] + 2 * nums[right]) < 0) {
                continue;
            }

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    ans.push_back({ nums[i], nums[left], nums[right] });
                    ret = next(nums, left);
                    ret += previous(nums, right);
                }
                else if (sum > 0) {
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

    vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    vector<vector<int>> actual = o.threeSum(nums);
    vector<vector<int>> expected = { {-1,-1,2},{-1,0,1} };
    check.checkIntDoubleVector(expected, actual);

    nums = { -1 };
    actual = o.threeSum(nums);
    expected = {  };
    check.checkIntDoubleVector(expected, actual);

    nums = { -1,1 };
    actual = o.threeSum(nums);
    expected = {  };
    check.checkIntDoubleVector(expected, actual);

    nums = { -1,-2,-3,-4,-5 };
    actual = o.threeSum(nums);
    expected = {  };
    check.checkIntDoubleVector(expected, actual);

    nums = { 1,2,3,4,5 };
    actual = o.threeSum(nums);
    expected = {  };
    check.checkIntDoubleVector(expected, actual);

    nums = { -1,1,0 };
    actual = o.threeSum(nums);
    expected = { {-1,0,1} };
    check.checkIntDoubleVector(expected, actual);

    nums = { 0,0,0,0,0 };
    actual = o.threeSum(nums);
    expected = { {0,0,0} };
    check.checkIntDoubleVector(expected, actual);

    nums = { 0,0,0,0,0,1 };
    actual = o.threeSum(nums);
    expected = { {0,0,0} };
    check.checkIntDoubleVector(expected, actual);

    nums = { 1,0,0,0,0,0 };
    actual = o.threeSum(nums);
    expected = { {0,0,0} };
    check.checkIntDoubleVector(expected, actual);

    nums = { -3,-3,-2,-2,-1,-1,0,1,1,2,2,3,3,14,15,16 };
    actual = o.threeSum(nums);
    expected = { {-3,0,3},{-3,1,2},{-2,-1,3},{-2,0,2},{-2,1,1},{-1,-1,2},{-1,0,1} };
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
