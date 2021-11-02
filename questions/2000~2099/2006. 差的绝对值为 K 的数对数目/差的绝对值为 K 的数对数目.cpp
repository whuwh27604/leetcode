/* 差的绝对值为 K 的数对数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 k ，请你返回数对 (i, j) 的数目，满足 i < j 且 |nums[i] - nums[j]| == k 。

|x| 的值定义为：

如果 x >= 0 ，那么值为 x 。
如果 x < 0 ，那么值为 -x 。
 

示例 1：

输入：nums = [1,2,2,1], k = 1
输出：4
解释：差的绝对值为 1 的数对为：
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
示例 2：

输入：nums = [1,3], k = 3
输出：0
解释：没有任何数对差的绝对值为 3 。
示例 3：

输入：nums = [3,2,1,5,4], k = 2
输出：3
解释：差的绝对值为 2 的数对为：
- [3,2,1,5,4]
- [3,2,1,5,4]
- [3,2,1,5,4]
 

提示：

1 <= nums.length <= 200
1 <= nums[i] <= 100
1 <= k <= 99

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-number-of-pairs-with-absolute-difference-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int i, pairs = 0;
        vector<int> count(101, 0);

        for (int num : nums) {
            ++count[num];
        }

        for (i = 1; i < 101; ++i) {
            if (i > k) {
                pairs += count[i] * count[i - k];
            }

            if (i + k < 101) {
                pairs += count[i] * count[i + k];
            }
        }

        return pairs / 2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,2,1 };
    check.checkInt(4, o.countKDifference(nums, 1));

    nums = { 1,3 };
    check.checkInt(0, o.countKDifference(nums, 3));

    nums = { 3,2,1,5,4 };
    check.checkInt(3, o.countKDifference(nums, 2));
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
