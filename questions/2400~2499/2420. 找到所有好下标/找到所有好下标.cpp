/* 找到所有好下标.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 n 下标从 0 开始的整数数组 nums 和一个正整数 k 。

对于 k <= i < n - k 之间的一个下标 i ，如果它满足以下条件，我们就称它为一个 好 下标：

下标 i 之前 的 k 个元素是 非递增的 。
下标 i 之后 的 k 个元素是 非递减的 。
按 升序 返回所有好下标。

 

示例 1：

输入：nums = [2,1,1,1,3,4,1], k = 2
输出：[2,3]
解释：数组中有两个好下标：
- 下标 2 。子数组 [2,1] 是非递增的，子数组 [1,3] 是非递减的。
- 下标 3 。子数组 [1,1] 是非递增的，子数组 [3,4] 是非递减的。
注意，下标 4 不是好下标，因为 [4,1] 不是非递减的。
示例 2：

输入：nums = [2,1,1,2], k = 2
输出：[]
解释：数组中没有好下标。
 

提示：

n == nums.length
3 <= n <= 105
1 <= nums[i] <= 106
1 <= k <= n / 2

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-all-good-indices
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nonIncreasingLen(n), nonDecreasingLen(n);

        getNonIncreasingLen(n, nums, nonIncreasingLen);
        getNonDecreasingLen(n, nums, nonDecreasingLen);

        return getGoods(n, k, nonIncreasingLen, nonDecreasingLen);
    }

    void getNonIncreasingLen(int n, vector<int>& nums, vector<int>& nonIncreasingLen) {
        nonIncreasingLen[n - 1] = 1;

        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] >= nums[i + 1]) {
                nonIncreasingLen[i] = nonIncreasingLen[i + 1] + 1;
            }
            else {
                nonIncreasingLen[i] = 1;
            }
        }
    }

    void getNonDecreasingLen(int n, vector<int>& nums, vector<int>& nonDecreasingLen) {
        nonDecreasingLen[0] = 1;

        for (int i = 1; i < n; ++i) {
            if (nums[i] >= nums[i - 1]) {
                nonDecreasingLen[i] = nonDecreasingLen[i - 1] + 1;
            }
            else {
                nonDecreasingLen[i] = 1;
            }
        }
    }

    vector<int> getGoods(int n, int k, vector<int>& nonIncreasingLen, vector<int>& nonDecreasingLen) {
        vector<int> goods;

        for (int i = k; i < n - k; ++i) {
            if (nonIncreasingLen[i - k] >= k && nonDecreasingLen[i + k] >= k) {
                goods.push_back(i);
            }
        }

        return goods;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,1,1,1,3,4,1 };
    vector<int> actual = o.goodIndices(nums, 2);
    vector<int> expected = { 2,3 };
    check.checkIntVector(expected, actual);

    nums = { 2,1,1,2 };
    actual = o.goodIndices(nums, 2);
    expected = {  };
    check.checkIntVector(expected, actual);
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
