/* 找出美丽数组的最小和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个正整数：n 和 target 。

如果数组 nums 满足下述条件，则称其为 美丽数组 。

nums.length == n.
nums 由两两互不相同的正整数组成。
在范围 [0, n-1] 内，不存在 两个 不同 下标 i 和 j ，使得 nums[i] + nums[j] == target 。
返回符合条件的美丽数组所可能具备的 最小 和。



示例 1：

输入：n = 2, target = 3
输出：4
解释：nums = [1,3] 是美丽数组。
- nums 的长度为 n = 2 。
- nums 由两两互不相同的正整数组成。
- 不存在两个不同下标 i 和 j ，使得 nums[i] + nums[j] == 3 。
可以证明 4 是符合条件的美丽数组所可能具备的最小和。
示例 2：

输入：n = 3, target = 3
输出：8
解释：
nums = [1,3,4] 是美丽数组。
- nums 的长度为 n = 3 。
- nums 由两两互不相同的正整数组成。
- 不存在两个不同下标 i 和 j ，使得 nums[i] + nums[j] == 3 。
可以证明 8 是符合条件的美丽数组所可能具备的最小和。
示例 3：

输入：n = 1, target = 1
输出：1
解释：nums = [1] 是美丽数组。


提示：

1 <= n <= 105
1 <= target <= 105
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        int m = min(target / 2, n);
        long long sum = (1 + (long long)m) * m / 2;
        n -= m;
        sum += ((long long)target + target + n - 1) * n / 2;

        return sum % 1000000007;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkLongLong(4, o.minimumPossibleSum(2, 3));
    check.checkLongLong(8, o.minimumPossibleSum(3, 3));
    check.checkLongLong(1, o.minimumPossibleSum(1, 1));
    check.checkLongLong(156198582, o.minimumPossibleSum(39636, 49035));
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
