/* 找出第 K 小的数对距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
数对 (a,b) 由整数 a 和 b 组成，其数对距离定义为 a 和 b 的绝对差值。

给你一个整数数组 nums 和一个整数 k ，数对由 nums[i] 和 nums[j] 组成且满足 0 <= i < j < nums.length 。返回 所有数对距离中 第 k 小的数对距离。

 

示例 1：

输入：nums = [1,3,1], k = 1
输出：0
解释：数对和对应的距离如下：
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
距离第 1 小的数对是 (1,1) ，距离为 0 。
示例 2：

输入：nums = [1,1,1], k = 2
输出：0
示例 3：

输入：nums = [1,6,1], k = 3
输出：5
 

提示：

n == nums.length
2 <= n <= 104
0 <= nums[i] <= 106
1 <= k <= n * (n - 1) / 2

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-k-th-smallest-pair-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int low = 0, high = nums.back() - nums[0], ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            int pairs = count(nums, mid);

            if (pairs >= k) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int count(vector<int>& nums, int distance) {
        int pairs = 0, left, right = 0, size = nums.size();

        for (left = 0; left < size - 1; ++left) {
            for (; right < size && nums[right] - nums[left] <= distance; ++right) {}

            pairs += (right - left - 1);
        }

        return pairs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,1 };
    check.checkInt(0, o.smallestDistancePair(nums, 1));

    nums = { 1,3,1 };
    check.checkInt(2, o.smallestDistancePair(nums, 2));
    
    nums = { 1,3,1 };
    check.checkInt(2, o.smallestDistancePair(nums, 3));

    nums = { 1,1,1 };
    check.checkInt(0, o.smallestDistancePair(nums, 2));

    nums = { 1,6,1 };
    check.checkInt(5, o.smallestDistancePair(nums, 3));

    nums = { 8,3 };
    check.checkInt(5, o.smallestDistancePair(nums, 1));

    nums = getIntVector("./testcase1.txt");
    check.checkInt(1, o.smallestDistancePair(nums, 25000000));
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
