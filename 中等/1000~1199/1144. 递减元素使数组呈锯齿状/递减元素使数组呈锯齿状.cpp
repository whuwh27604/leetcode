/* 递减元素使数组呈锯齿状.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums，每次 操作 会从中选择一个元素并 将该元素的值减少 1。

如果符合下列情况之一，则数组 A 就是 锯齿数组：

每个偶数索引对应的元素都大于相邻的元素，即 A[0] > A[1] < A[2] > A[3] < A[4] > ...
或者，每个奇数索引对应的元素都大于相邻的元素，即 A[0] < A[1] > A[2] < A[3] > A[4] < ...
返回将数组 nums 转换为锯齿数组所需的最小操作次数。

 

示例 1：

输入：nums = [1,2,3]
输出：2
解释：我们可以把 2 递减到 0，或把 3 递减到 1。
示例 2：

输入：nums = [9,6,1,6,2]
输出：4
 

提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decrease-elements-to-make-array-zigzag
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int size = nums.size();

        if (size == 1) {
            return 0;
        }

        return (size & 1) == 1 ? min(oddIncreasingMoves(nums), oddDecreasingMoves(nums)) : min(evenIncreasingMoves(nums), evenDecreasingMoves(nums));
    }

    int oddIncreasingMoves(vector<int>& nums) {
        int i, size = nums.size(), moves = 0;

        for (i = 2; i < size - 2; i += 2) {
            int tmp = min(nums[i - 1], nums[i + 1]);
            moves += (nums[i] < tmp ? 0 : nums[i] - tmp + 1);
        }

        moves += (nums[0] < nums[1] ? 0 : nums[0] - nums[1] + 1);  // nums={a,a}时这个逻辑不对，不过不影响最终的结果，因为oddDecreasingMoves等于1更小一些
        moves += (nums[i] < nums[i - 1] ? 0 : nums[i] - nums[i - 1] + 1);

        return moves;
    }

    int oddDecreasingMoves(vector<int>& nums) {
        int i, size = nums.size(), moves = 0;

        for (i = 1; i < size; i += 2) {
            int tmp = min(nums[i - 1], nums[i + 1]);
            moves += (nums[i] < tmp ? 0 : nums[i] - tmp + 1);
        }

        return moves;
    }

    int evenIncreasingMoves(vector<int>& nums) {
        int i, size = nums.size(), moves = 0;

        moves += ((nums[0] < nums[1]) ? 0 : nums[0] - nums[1] + 1);

        for (i = 2; i < size; i += 2) {
            int tmp = min(nums[i - 1], nums[i + 1]);
            moves += (nums[i] < tmp ? 0 : nums[i] - tmp + 1);
        }

        return moves;
    }

    int evenDecreasingMoves(vector<int>& nums) {
        int i, size = nums.size(), moves = 0;

        for (i = 1; i < size - 2; i += 2) {
            int tmp = min(nums[i - 1], nums[i + 1]);
            moves += (nums[i] < tmp ? 0 : nums[i] - tmp + 1);
        }

        moves += (nums[i] < nums[i - 1] ? 0 : nums[i] - nums[i - 1] + 1);

        return moves;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3 };
    check.checkInt(2, o.movesToMakeZigzag(nums));

    nums = { 9,6,1,6,2 };
    check.checkInt(4, o.movesToMakeZigzag(nums));

    nums = { 9,9 };
    check.checkInt(1, o.movesToMakeZigzag(nums));

    nums = { 10,4,4,10,10,6,2,3 };
    check.checkInt(13, o.movesToMakeZigzag(nums));
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
