/* K 次增加后的最大乘积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个非负整数数组 nums 和一个整数 k 。每次操作，你可以选择 nums 中 任一 元素并将它 增加 1 。

请你返回 至多 k 次操作后，能得到的 nums的 最大乘积 。由于答案可能很大，请你将答案对 109 + 7 取余后返回。

 

示例 1：

输入：nums = [0,4], k = 5
输出：20
解释：将第一个数增加 5 次。
得到 nums = [5, 4] ，乘积为 5 * 4 = 20 。
可以证明 20 是能得到的最大乘积，所以我们返回 20 。
存在其他增加 nums 的方法，也能得到最大乘积。
示例 2：

输入：nums = [6,3,3,2], k = 2
输出：216
解释：将第二个数增加 1 次，将第四个数增加 1 次。
得到 nums = [6, 4, 3, 3] ，乘积为 6 * 4 * 3 * 3 = 216 。
可以证明 216 是能得到的最大乘积，所以我们返回 216 。
存在其他增加 nums 的方法，也能得到最大乘积。
 

提示：

1 <= nums.length, k <= 105
0 <= nums[i] <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-after-k-increments
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  // 先排序，然后贪心的增加最小数

        int i = 0, j, size = nums.size();
        long long product = 1;

        while (k > 0) {
            for (++i; i < size && nums[i] == nums[i - 1]; ++i) {}  // 找到最小数的长度

            int inc = i == size ? k / size : min(k / i, nums[i] - nums[i - 1]);
            k -= i * inc;

            for (j = 0; j < i; ++j) {  // 将它们增加到次小数
                nums[j] += inc;
            }

            if (i == size || nums[i] != nums[i - 1]) {  // 最后不足部分
                for (--k; k >= 0; --k) {
                    nums[k] += 1;
                }
            }
        }

        for (int num : nums) {
            product = (product * num % 1000000007);
        }

        return (int)product;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 0,4 };
    check.checkInt(20, o.maximumProduct(nums, 5));

    nums = { 6,3,3,2 };
    check.checkInt(216, o.maximumProduct(nums, 2));

    nums = { 24,5,64,53,26,38 };
    check.checkInt(180820950, o.maximumProduct(nums, 54));

    nums = { 24,5,64,53,26,38 };
    check.checkInt(849915385, o.maximumProduct(nums, 18));

    nums = { 24,5,64,53,26,38 };
    check.checkInt(930346489, o.maximumProduct(nums, 19));

    nums = { 24,5,64,53,26,38 };
    check.checkInt(178342386, o.maximumProduct(nums, 22));

    nums = { 24,5,64,53,26,38 };
    check.checkInt(265476082, o.maximumProduct(nums, 23));

    nums = { 24,5,64,53,26,38 };
    check.checkInt(23040041, o.maximumProduct(nums, 100000));

    nums = { 0,0,1 };
    check.checkInt(0, o.maximumProduct(nums, 1));

    nums = { 0 };
    check.checkInt(100000, o.maximumProduct(nums, 100000));
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
