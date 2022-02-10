/* 分组得分最高的所有下标.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二进制数组 nums ，数组长度为 n 。nums 可以按下标 i（ 0 <= i <= n ）拆分成两个数组（可能为空）：numsleft 和 numsright 。

numsleft 包含 nums 中从下标 0 到 i - 1 的所有元素（包括 0 和 i - 1 ），而 numsright 包含 nums 中从下标 i 到 n - 1 的所有元素（包括 i 和 n - 1 ）。
如果 i == 0 ，numsleft 为 空 ，而 numsright 将包含 nums 中的所有元素。
如果 i == n ，numsleft 将包含 nums 中的所有元素，而 numsright 为 空 。
下标 i 的 分组得分 为 numsleft 中 0 的个数和 numsright 中 1 的个数之 和 。

返回 分组得分 最高 的 所有不同下标 。你可以按 任意顺序 返回答案。

 

示例 1：

输入：nums = [0,0,1,0]
输出：[2,4]
解释：按下标分组
- 0 ：numsleft 为 [] 。numsright 为 [0,0,1,0] 。得分为 0 + 1 = 1 。
- 1 ：numsleft 为 [0] 。numsright 为 [0,1,0] 。得分为 1 + 1 = 2 。
- 2 ：numsleft 为 [0,0] 。numsright 为 [1,0] 。得分为 2 + 1 = 3 。
- 3 ：numsleft 为 [0,0,1] 。numsright 为 [0] 。得分为 2 + 0 = 2 。
- 4 ：numsleft 为 [0,0,1,0] 。numsright 为 [] 。得分为 3 + 0 = 3 。
下标 2 和 4 都可以得到最高的分组得分 3 。
注意，答案 [4,2] 也被视为正确答案。
示例 2：

输入：nums = [0,0,0]
输出：[3]
解释：按下标分组
- 0 ：numsleft 为 [] 。numsright 为 [0,0,0] 。得分为 0 + 0 = 0 。
- 1 ：numsleft 为 [0] 。numsright 为 [0,0] 。得分为 1 + 0 = 1 。
- 2 ：numsleft 为 [0,0] 。numsright 为 [0] 。得分为 2 + 0 = 2 。
- 3 ：numsleft 为 [0,0,0] 。numsright 为 [] 。得分为 3 + 0 = 3 。
只有下标 3 可以得到最高的分组得分 3 。
示例 3：

输入：nums = [1,1]
输出：[0]
解释：按下标分组
- 0 ：numsleft 为 [] 。numsright 为 [1,1] 。得分为 0 + 2 = 2 。
- 1 ：numsleft 为 [1] 。numsright 为 [1] 。得分为 0 + 1 = 1 。
- 2 ：numsleft 为 [1,1] 。numsright 为 [] 。得分为 0 + 0 = 0 。
只有下标 0 可以得到最高的分组得分 2 。
 

提示：

n == nums.length
1 <= n <= 105
nums[i] 为 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-divisions-with-the-highest-score-of-a-binary-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int i, size = nums.size(), totalOnes = 0, ones = 0;

        for (i = 0; i < size; ++i) {
            totalOnes += nums[i];
        }

        int maxScore = totalOnes;
        vector<int> indices = { 0 };

        for (i = 1; i <= size; ++i) {
            ones += nums[i - 1];
            int score = (i - ones) + (totalOnes - ones);

            if (score == maxScore) {
                indices.push_back(i);
            }
            else if (score > maxScore) {
                maxScore = score;
                indices = { i };
            }
        }

        return indices;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 0,0,1,0 };
    vector<int> actual = o.maxScoreIndices(nums);
    vector<int> expected = { 2,4 };
    check.checkIntVector(expected, actual);

    nums = { 0,0,0 };
    actual = o.maxScoreIndices(nums);
    expected = { 3 };
    check.checkIntVector(expected, actual);

    nums = { 1,1 };
    actual = o.maxScoreIndices(nums);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    nums = { 0 };
    actual = o.maxScoreIndices(nums);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    nums = { 1 };
    actual = o.maxScoreIndices(nums);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,0,0,0,1,0,1,1,0,1,1,0,1,1,1,0,0,1,0,0,1,0,0,0,1,1,1,1,0,0,0,1,0,1,1,0,1,1,0,1,1,1,0,0,1,0,0,1,0,0,0,1,1,1,1,0,0,0,1,0,1,1,0,1,1,0,1,1,1,0,0,1,0,0,1,0,0,0,1,1 };
    actual = o.maxScoreIndices(nums);
    expected = { 5,7,25 };
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
