/* 全 0 子数组的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，返回全部为 0 的 子数组 数目。

子数组 是一个数组中一段连续非空元素组成的序列。

 

示例 1：

输入：nums = [1,3,0,0,2,0,0,4]
输出：6
解释：
子数组 [0] 出现了 4 次。
子数组 [0,0] 出现了 2 次。
不存在长度大于 2 的全 0 子数组，所以我们返回 6 。
示例 2：

输入：nums = [0,0,0,2,0,0]
输出：9
解释：
子数组 [0] 出现了 5 次。
子数组 [0,0] 出现了 3 次。
子数组 [0,0,0] 出现了 1 次。
不存在长度大于 3 的全 0 子数组，所以我们返回 9 。
示例 3：

输入：nums = [2,10,2019]
输出：0
解释：没有全 0 子数组，所以我们返回 0 。
 

提示：

1 <= nums.length <= 105
-109 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-zero-filled-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long zeros = 0, subarrs = 0;

        for (int num : nums) {
            if (num == 0) {
                ++zeros;
            }
            else {
                subarrs += (1 + zeros) * zeros / 2;
                zeros = 0;
            }
        }

        return subarrs + (1 + zeros) * zeros / 2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,0,0,2,0,0,4 };
    check.checkLongLong(6, o.zeroFilledSubarray(nums));

    nums = { 0,0,0,2,0,0 };
    check.checkLongLong(9, o.zeroFilledSubarray(nums));

    nums = { 2,10,2019 };
    check.checkLongLong(0, o.zeroFilledSubarray(nums));

    nums = { 0 };
    check.checkLongLong(1, o.zeroFilledSubarray(nums));
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
