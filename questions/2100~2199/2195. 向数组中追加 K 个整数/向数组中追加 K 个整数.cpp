/* 向数组中追加 K 个整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 k 。请你向 nums 中追加 k 个 未 出现在 nums 中的、互不相同 的 正 整数，并使结果数组的元素和 最小 。

返回追加到 nums 中的 k 个整数之和。

 

示例 1：

输入：nums = [1,4,25,10,25], k = 2
输出：5
解释：在该解法中，向数组中追加的两个互不相同且未出现的正整数是 2 和 3 。
nums 最终元素和为 1 + 4 + 25 + 10 + 25 + 2 + 3 = 70 ，这是所有情况中的最小值。
所以追加到数组中的两个整数之和是 2 + 3 = 5 ，所以返回 5 。
示例 2：

输入：nums = [5,6], k = 6
输出：25
解释：在该解法中，向数组中追加的两个互不相同且未出现的正整数是 1 、2 、3 、4 、7 和 8 。
nums 最终元素和为 5 + 6 + 1 + 2 + 3 + 4 + 7 + 8 = 36 ，这是所有情况中的最小值。
所以追加到数组中的两个整数之和是 1 + 2 + 3 + 4 + 7 + 8 = 25 ，所以返回 25 。
 

提示：

1 <= nums.length <= 105
1 <= nums[i], k <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/append-k-integers-with-minimal-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long sum = 0;

        nums.push_back(0);
        sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)nums.size() - 1 && k > 0; ++i) {
            int start = nums[i] + 1, end = nums[i + 1] - 1;

            if (start <= end) {
                end = min(end, start + k - 1);
                sum += ((long long)start + end) * ((long long)end + 1 - start) / 2;
                k -= (end + 1 - start);
            }
        }

        sum += (((long long)nums.back() + 1 + nums.back() + k) * k / 2);

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,4,25,10,25 };
    check.checkLongLong(5, o.minimalKSum(nums, 2));

    nums = { 5,6 };
    check.checkLongLong(25, o.minimalKSum(nums, 6));

    nums = { 1,5 };
    check.checkLongLong(5, o.minimalKSum(nums, 2));

    nums = { 1000000000 };
    check.checkLongLong(5000000050000000, o.minimalKSum(nums, 100000000));

    nums = { 1 };
    check.checkLongLong(5000000150000000, o.minimalKSum(nums, 100000000));
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
