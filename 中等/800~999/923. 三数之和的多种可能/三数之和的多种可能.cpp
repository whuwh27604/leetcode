/* 三数之和的多种可能.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 A，以及一个整数 target 作为目标值，返回满足 i < j < k 且 A[i] + A[j] + A[k] == target 的元组 i, j, k 的数量。

由于结果会非常大，请返回 结果除以 10^9 + 7 的余数。

 

示例 1：

输入：A = [1,1,2,2,3,3,4,4,5,5], target = 8
输出：20
解释：
按值枚举（A[i]，A[j]，A[k]）：
(1, 2, 5) 出现 8 次；
(1, 3, 4) 出现 8 次；
(2, 2, 4) 出现 2 次；
(2, 3, 3) 出现 2 次。
示例 2：

输入：A = [1,1,2,2,2,2], target = 5
输出：12
解释：
A[i] = 1，A[j] = A[k] = 2 出现 12 次：
我们从 [1,1] 中选择一个 1，有 2 种情况，
从 [2,2,2,2] 中选出两个 2，有 6 种情况。
 

提示：

3 <= A.length <= 3000
0 <= A[i] <= 100
0 <= target <= 300

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-with-multiplicity
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        map<int, int> nums;
        countNums(A, nums);

        int ans = oneSum(nums, target);
        ans = (ans + twoSum(nums, target)) % mod;
        ans = (ans + threeSum(nums, target)) % mod;

        return ans;
    }

    int oneSum(map<int, int>& nums, int target) {
        int one = target / 3;

        if (one * 3 == target && nums.count(one) != 0) {
            return combination(nums[one], 3);
        }

        return 0;
    }

    int twoSum(map<int, int>& nums, int target) {
        int count = 0, second;

        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            second = target - iter->first;
            if (second % 2 == 1) {
                continue;
            }

            second /= 2;
            if (second <= iter->first) {
                break;
            }

            if (nums.count(second) != 0) {
                count = (count + iter->second * combination(nums[second], 2)) % mod;
            }
        }

        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            second = target - 2 * iter->first;
            if (second <= iter->first) {
                break;
            }

            if (nums.count(second) != 0) {
                count = (count + combination(iter->second, 2) * nums[second]) % mod;
            }
        }

        return count;
    }

    int threeSum(map<int, int>& nums, int target) {
        int count = 0;

        for (auto it1 = nums.begin(); it1 != nums.end(); ++it1) {
            auto it2 = it1;
            for (++it2; it2 != nums.end(); ++it2) {
                int third = target - it1->first - it2->first;
                if (third <= it2->first) {
                    break;
                }

                if (nums.count(third) != 0) {
                    count = (count + it1->second * it2->second * nums[third]) % mod;
                }
            }
        }

        return count;
    }

    int combination(int x, int y) {
        if (y == 0 || x < y) {
            return 0;
        }

        int m = max(y, x - y), n = min(y, x - y), i;
        long long product = 1;

        for (i = m + 1; i <= x; ++i) {
            product *= i;
        }

        for (i = 2; i <= n; ++i) {
            product /= i;
        }

        return (int)(product % mod);
    }

    void countNums(vector<int>& A, map<int, int>& nums) {
        for (int num : A) {
            if (nums.count(num) == 0) {
                nums[num] = 1;
            }
            else {
                ++nums[num];
            }
        }
    }

private:
    static const int mod = 1000000007;
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 1,1,2,2,3,3,4,4,5,5 };
    check.checkInt(20, o.threeSumMulti(A, 8));

    A = { 1,1,2,2,2,2 };
    check.checkInt(12, o.threeSumMulti(A, 5));
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
