/* 数组的最大公因数排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，你可以在 nums 上执行下述操作 任意次 ：

如果 gcd(nums[i], nums[j]) > 1 ，交换 nums[i] 和 nums[j] 的位置。其中 gcd(nums[i], nums[j]) 是 nums[i] 和 nums[j] 的最大公因数。
如果能使用上述交换方式将 nums 按 非递减顺序 排列，返回 true ；否则，返回 false 。

 

示例 1：

输入：nums = [7,21,3]
输出：true
解释：可以执行下述操作完成对 [7,21,3] 的排序：
- 交换 7 和 21 因为 gcd(7,21) = 7 。nums = [21,7,3]
- 交换 21 和 3 因为 gcd(21,3) = 3 。nums = [3,7,21]
示例 2：

输入：nums = [5,2,6,2]
输出：false
解释：无法完成排序，因为 5 不能与其他元素交换。
示例 3：

输入：nums = [10,5,9,3,15]
输出：true
解释：
可以执行下述操作完成对 [10,5,9,3,15] 的排序：
- 交换 10 和 15 因为 gcd(10,15) = 5 。nums = [15,5,9,3,10]
- 交换 15 和 3 因为 gcd(15,3) = 3 。nums = [3,5,9,15,10]
- 交换 10 和 15 因为 gcd(10,15) = 5 。nums = [3,5,9,10,15]
 

提示：

1 <= nums.length <= 3 * 104
2 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gcd-sort-of-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class DSU {
public:
    DSU(int size) {
        parents.resize(size);

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    void merge(int x, int y) {
        parents[find(x)] = find(y);
    }

private:
    vector<int> parents;
};

class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end()) + 1;
        DSU dsu(n);
        vector<int> backup = nums;

        eratosthenes(n, nums, dsu);
        sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] != backup[i] && dsu.find(nums[i]) != dsu.find(backup[i])) {
                return false;
            }
        }

        return true;
    }

    void eratosthenes(int n, vector<int>& nums, DSU& dsu) {
        vector<bool> numExist(n, false), primes(n, true);

        for (int num : nums) {
            numExist[num] = true;
        }

        for (int i = 2; (i * i) < n; ++i) {  // 如果n=i*i，则n不是质数，所以只需要循环到(i * i) < n就可以了
            if (primes[i]) {
                for (int j = i; i * j < n; ++j) {  // i的小于i的倍数都已经排除过了，现在只需要排除更大的i的倍数
                    primes[i * j] = 0;

                    if (numExist[i * j]) {
                        dsu.merge(i, i * j);
                        dsu.merge(i, j);
                        numExist[j] = true;
                    }
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 7,21,3 };
    check.checkBool(true, o.gcdSort(nums));

    nums = { 6,2,3 };
    check.checkBool(true, o.gcdSort(nums));

    nums = { 5,2,6,2 };
    check.checkBool(false, o.gcdSort(nums));

    nums = { 10,5,9,3,15 };
    check.checkBool(true, o.gcdSort(nums));

    nums = { 5,4,5 };
    check.checkBool(false, o.gcdSort(nums));

    nums = { 9,4,5,6,2 };
    check.checkBool(true, o.gcdSort(nums));

    nums = { 100000 };
    check.checkBool(true, o.gcdSort(nums));
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
