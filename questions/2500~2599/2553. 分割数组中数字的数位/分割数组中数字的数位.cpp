/* 分割数组中数字的数位.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 nums ，请你返回一个数组 answer ，你需要将 nums 中每个整数进行数位分割后，按照 nums 中出现的 相同顺序 放入答案数组中。

对一个整数进行数位分割，指的是将整数各个数位按原本出现的顺序排列成数组。

比方说，整数 10921 ，分割它的各个数位得到 [1,0,9,2,1] 。


示例 1：

输入：nums = [13,25,83,77]
输出：[1,3,2,5,8,3,7,7]
解释：
- 分割 13 得到 [1,3] 。
- 分割 25 得到 [2,5] 。
- 分割 83 得到 [8,3] 。
- 分割 77 得到 [7,7] 。
answer = [1,3,2,5,8,3,7,7] 。answer 中的数字分割结果按照原数字在数组中的相同顺序排列。
示例 2：

输入：nums = [7,1,3,9]
输出：[7,1,3,9]
解释：nums 中每个整数的分割是它自己。
answer = [7,1,3,9] 。


提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for (int i = nums.size() - 1; i >= 0; --i) {
            int num = nums[i];
            while (num != 0) {
                ans.push_back(num % 10);
                num /= 10;
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 13,25,83,77 };
    vector<int> actual = o.separateDigits(nums);
    vector<int> expected = { 1,3,2,5,8,3,7,7 };
    check.checkIntVector(expected, actual);

    nums = { 7,1,3,9 };
    actual = o.separateDigits(nums);
    expected = { 7,1,3,9 };
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
