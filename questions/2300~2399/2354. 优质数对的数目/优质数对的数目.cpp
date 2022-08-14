/* 优质数对的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的正整数数组 nums 和一个正整数 k 。

如果满足下述条件，则数对 (num1, num2) 是 优质数对 ：

num1 和 num2 都 在数组 nums 中存在。
num1 OR num2 和 num1 AND num2 的二进制表示中值为 1 的位数之和大于等于 k ，其中 OR 是按位 或 操作，而 AND 是按位 与 操作。
返回 不同 优质数对的数目。

如果 a != c 或者 b != d ，则认为 (a, b) 和 (c, d) 是不同的两个数对。例如，(1, 2) 和 (2, 1) 不同。

注意：如果 num1 在数组中至少出现 一次 ，则满足 num1 == num2 的数对 (num1, num2) 也可以是优质数对。

 

示例 1：

输入：nums = [1,2,3,1], k = 3
输出：5
解释：有如下几个优质数对：
- (3, 3)：(3 AND 3) 和 (3 OR 3) 的二进制表示都等于 (11) 。值为 1 的位数和等于 2 + 2 = 4 ，大于等于 k = 3 。
- (2, 3) 和 (3, 2)： (2 AND 3) 的二进制表示等于 (10) ，(2 OR 3) 的二进制表示等于 (11) 。值为 1 的位数和等于 1 + 2 = 3 。
- (1, 3) 和 (3, 1)： (1 AND 3) 的二进制表示等于 (01) ，(1 OR 3) 的二进制表示等于 (11) 。值为 1 的位数和等于 1 + 2 = 3 。
所以优质数对的数目是 5 。
示例 2：

输入：nums = [5,1,1], k = 10
输出：0
解释：该数组中不存在优质数对。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 60

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-excellent-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        vector<int> counts(33, 0);

        countAllOnes(nums, counts);

        return countPairs(counts, k);
    }

    void countAllOnes(vector<int>& nums, vector<int>& counts) {
        unordered_set<int> numbers;

        for (int num : nums) {
            if (numbers.count(num) == 0) {
                ++counts[countOnes(num)];
                numbers.insert(num);
            }
        }
    }

    int countOnes(int num) {
        int ones = 0;

        while (num != 0) {
            num &= (num - 1);
            ++ones;
        }

        return ones;
    }

    long long countPairs(vector<int>& counts, int k) {
        long long pairs = 0;

        for (int i = 1; i < 33; ++i) {
            for (int j = max(1, k - i); j < 33; ++j) {
                pairs += ((long long)counts[i] * counts[j]);
            }
        }

        return pairs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,1 };
    check.checkLongLong(5, o.countExcellentPairs(nums, 3));

    nums = { 5,1,1 };
    check.checkLongLong(0, o.countExcellentPairs(nums, 10));

    nums = { 1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10 };
    check.checkLongLong(44, o.countExcellentPairs(nums, 4));

    nums = { 1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10 };
    check.checkLongLong(100, o.countExcellentPairs(nums, 2));
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
