/* 找出最具竞争力的子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个正整数 k ，返回长度为 k 且最具 竞争力 的 nums 子序列。

数组的子序列是从数组中删除一些元素（可能不删除元素）得到的序列。

在子序列 a 和子序列 b 第一个不相同的位置上，如果 a 中的数字小于 b 中对应的数字，那么我们称子序列 a 比子序列 b（相同长度下）更具 竞争力 。 例如，[1,3,4] 比 [1,3,5] 更具竞争力，在第一个不相同的位置，也就是最后一个位置上， 4 小于 5 。

 

示例 1：

输入：nums = [3,5,2,6], k = 2
输出：[2,6]
解释：在所有可能的子序列集合 {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]} 中，[2,6] 最具竞争力。
示例 2：

输入：nums = [2,4,3,3,5,4,9,6], k = 4
输出：[2,3,3,4]
 

提示：

1 <= nums.length <= 105
0 <= nums[i] <= 109
1 <= k <= nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-most-competitive-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int i, size = nums.size();
        vector<int> mostCompetitiveNums;

        for (i = 0; i < size; ++i) {
            while (!mostCompetitiveNums.empty() && nums[i] < mostCompetitiveNums.back()
                && size - i > k - (int)mostCompetitiveNums.size()) {  // 要保证剩下的数还够凑齐k个
                mostCompetitiveNums.pop_back();
            }

            if ((int)mostCompetitiveNums.size() < k) {  // 如果已经够k个了，就不要再往里面放了。但是不能结束循环，因为后面可能还有更小的
                mostCompetitiveNums.push_back(nums[i]);
            }
        }

        return mostCompetitiveNums;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,5,2,6 };
    vector<int> actual = o.mostCompetitive(nums, 2);
    vector<int> expected = { 2,6 };
    check.checkIntVector(expected, actual);

    nums = { 3,5,2,6 };
    actual = o.mostCompetitive(nums, 2);
    expected = { 2,6 };
    check.checkIntVector(expected, actual);

    nums = { 2,4,3,3,5,4,9,6 };
    actual = o.mostCompetitive(nums, 4);
    expected = { 2,3,3,4 };
    check.checkIntVector(expected, actual);

    nums = { 2,4,3,3,5,4,9,6 };
    actual = o.mostCompetitive(nums, 5);
    expected = { 2,3,3,4,6 };
    check.checkIntVector(expected, actual);

    nums = { 2,4,3,3,5,4,9,6 };
    actual = o.mostCompetitive(nums, 6);
    expected = { 2,3,3,4,9,6 };
    check.checkIntVector(expected, actual);

    nums = { 2,4,3,3,5,4,9,6 };
    actual = o.mostCompetitive(nums, 8);
    expected = { 2,4,3,3,5,4,9,6 };
    check.checkIntVector(expected, actual);

    nums = { 6 };
    actual = o.mostCompetitive(nums, 1);
    expected = { 6 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,3,4,5 };
    actual = o.mostCompetitive(nums, 3);
    expected = { 1,2,3 };
    check.checkIntVector(expected, actual);

    nums = { 5,4,3,2,1 };
    actual = o.mostCompetitive(nums, 3);
    expected = { 3,2,1 };
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
