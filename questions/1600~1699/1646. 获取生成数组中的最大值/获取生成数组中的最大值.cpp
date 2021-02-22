/* 获取生成数组中的最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n 。按下述规则生成一个长度为 n + 1 的数组 nums ：

nums[0] = 0
nums[1] = 1
当 2 <= 2 * i <= n 时，nums[2 * i] = nums[i]
当 2 <= 2 * i + 1 <= n 时，nums[2 * i + 1] = nums[i] + nums[i + 1]
返回生成数组 nums 中的 最大 值。

 

示例 1：

输入：n = 7
输出：3
解释：根据规则：
  nums[0] = 0
  nums[1] = 1
  nums[(1 * 2) = 2] = nums[1] = 1
  nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
  nums[(2 * 2) = 4] = nums[2] = 1
  nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
  nums[(3 * 2) = 6] = nums[3] = 2
  nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
因此，nums = [0,1,1,2,1,3,2,3]，最大值 3
示例 2：

输入：n = 2
输出：1
解释：根据规则，nums[0]、nums[1] 和 nums[2] 之中的最大值是 1
示例 3：

输入：n = 3
输出：2
解释：根据规则，nums[0]、nums[1]、nums[2] 和 nums[3] 之中的最大值是 2
 

提示：

0 <= n <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/get-maximum-in-generated-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n < 2) {
            return n;
        }

        int i, maxNum = 0;
        vector<int> nums(n + 1);

        nums[0] = 0;
        nums[1] = 1;

        for (i = 2; i <= n; ++i) {
            if ((i & 1) == 0) {
                nums[i] = nums[i >> 1];
            }
            else {
                nums[i] = nums[i >> 1] + nums[(i + 1) >> 1];
            }

            maxNum = max(maxNum, nums[i]);
        }

        return maxNum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.getMaximumGenerated(7));
    check.checkInt(1, o.getMaximumGenerated(2));
    check.checkInt(2, o.getMaximumGenerated(3));
    check.checkInt(1, o.getMaximumGenerated(1));
    check.checkInt(0, o.getMaximumGenerated(0));
    check.checkInt(13, o.getMaximumGenerated(50));
    check.checkInt(18, o.getMaximumGenerated(80));
    check.checkInt(21, o.getMaximumGenerated(99));
    check.checkInt(21, o.getMaximumGenerated(100));
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
