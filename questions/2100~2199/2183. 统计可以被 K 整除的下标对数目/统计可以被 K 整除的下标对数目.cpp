/* 统计可以被 K 整除的下标对数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、长度为 n 的整数数组 nums 和一个整数 k ，返回满足下述条件的下标对 (i, j) 的数目：

0 <= i < j <= n - 1 且
nums[i] * nums[j] 能被 k 整除。
 

示例 1：

输入：nums = [1,2,3,4,5], k = 2
输出：7
解释：
共有 7 对下标的对应积可以被 2 整除：
(0, 1)、(0, 3)、(1, 2)、(1, 3)、(1, 4)、(2, 3) 和 (3, 4)
它们的积分别是 2、4、6、8、10、12 和 20 。
其他下标对，例如 (0, 2) 和 (2, 4) 的乘积分别是 3 和 15 ，都无法被 2 整除。
示例 2：

输入：nums = [1,2,3,4], k = 5
输出：0
解释：不存在对应积可以被 5 整除的下标对。
 

提示：

1 <= nums.length <= 105
1 <= nums[i], k <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-array-pairs-divisible-by-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

bool init = false;
const int maxNum = 100000;
vector<vector<int>> factors(maxNum + 1);

void decompose() {
    for (int factor = 1; factor <= maxNum; ++factor) {
        for (int num = factor; num <= maxNum; num += factor) {
            factors[num].push_back(factor);
        }
    }
}

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        if (!init) {
            init = true;
            decompose();
        }

        unordered_map<int, int> count;  // 记录包含factor的num的个数
        long long pairs = 0;

        for (int num : nums) {
            pairs += count[k / gcd(k, num)];  // 任何n = k / gcd(k, num)的倍数都可以被k整除，n的倍数都包含n这个factor

            for (int factor : factors[num]) {
                ++count[factor];
            }
        }

        return pairs;
    }

    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,4,5 };
    check.checkLongLong(7, o.countPairs(nums, 2));

    nums = { 1,2,3,4 };
    check.checkLongLong(0, o.countPairs(nums, 5));

    nums = { 5,5,5,5,5,5,5,5 };
    check.checkLongLong(28, o.countPairs(nums, 1));

    nums = { 1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,6,7,7,7,7,7,8,8,8,8,9,9,9 };
    check.checkLongLong(256, o.countPairs(nums, 4));
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
