/* 数位和相等数对的最大和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的数组 nums ，数组中的元素都是 正 整数。请你选出两个下标 i 和 j（i != j），且 nums[i] 的数位和 与  nums[j] 的数位和相等。

请你找出所有满足条件的下标 i 和 j ，找出并返回 nums[i] + nums[j] 可以得到的 最大值 。

 

示例 1：

输入：nums = [18,43,36,13,7]
输出：54
解释：满足条件的数对 (i, j) 为：
- (0, 2) ，两个数字的数位和都是 9 ，相加得到 18 + 36 = 54 。
- (1, 4) ，两个数字的数位和都是 7 ，相加得到 43 + 7 = 50 。
所以可以获得的最大和是 54 。
示例 2：

输入：nums = [10,12,19,14]
输出：-1
解释：不存在满足条件的数对，返回 -1 。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<pair<int, int>> maxTwos(100, { -1,-1 });
        int maxSum = -1;

        for (int num : nums) {
            int sum = getDigitSum(num);
            save(maxTwos[sum], num);
        }

        for (auto& maxTwo : maxTwos) {
            if (maxTwo.first != -1 && maxTwo.second != -1) {
                maxSum = max(maxSum, maxTwo.first + maxTwo.second);
            }
        }

        return maxSum;
    }

    int getDigitSum(int num) {
        int sum = 0;

        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    void save(pair<int, int>& maxTwo, int num) {
        if (num >= maxTwo.first) {
            maxTwo.second = maxTwo.first;
            maxTwo.first = num;
        }
        else if (num > maxTwo.second) {
            maxTwo.second = num;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 18,43,36,13,7 };
    check.checkInt(54, o.maximumSum(nums));

    nums = { 10,12,19,14 };
    check.checkInt(-1, o.maximumSum(nums));
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
