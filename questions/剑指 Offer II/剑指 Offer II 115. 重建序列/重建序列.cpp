/* 重建序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个长度为 n 的整数数组 nums ，其中 nums 是范围为 [1，n] 的整数的排列。还提供了一个 2D 整数数组 sequences ，其中 sequences[i] 是 nums 的子序列。
检查 nums 是否是唯一的最短 超序列 。最短 超序列 是 长度最短 的序列，并且所有序列 sequences[i] 都是它的子序列。对于给定的数组 sequences ，可能存在多个有效的 超序列 。

例如，对于 sequences = [[1,2],[1,3]] ，有两个最短的 超序列 ，[1,2,3] 和 [1,3,2] 。
而对于 sequences = [[1,2],[1,3],[1,2,3]] ，唯一可能的最短 超序列 是 [1,2,3] 。[1,2,3,4] 是可能的超序列，但不是最短的。
如果 nums 是序列的唯一最短 超序列 ，则返回 true ，否则返回 false 。
子序列 是一个可以通过从另一个序列中删除一些元素或不删除任何元素，而不改变其余元素的顺序的序列。

 

示例 1：

输入：nums = [1,2,3], sequences = [[1,2],[1,3]]
输出：false
解释：有两种可能的超序列：[1,2,3]和[1,3,2]。
序列 [1,2] 是[1,2,3]和[1,3,2]的子序列。
序列 [1,3] 是[1,2,3]和[1,3,2]的子序列。
因为 nums 不是唯一最短的超序列，所以返回false。
示例 2：

输入：nums = [1,2,3], sequences = [[1,2]]
输出：false
解释：最短可能的超序列为 [1,2]。
序列 [1,2] 是它的子序列：[1,2]。
因为 nums 不是最短的超序列，所以返回false。
示例 3：

输入：nums = [1,2,3], sequences = [[1,2],[1,3],[2,3]]
输出：true
解释：最短可能的超序列为[1,2,3]。
序列 [1,2] 是它的一个子序列：[1,2,3]。
序列 [1,3] 是它的一个子序列：[1,2,3]。
序列 [2,3] 是它的一个子序列：[1,2,3]。
因为 nums 是唯一最短的超序列，所以返回true。
 

提示：

n == nums.length
1 <= n <= 104
nums 是 [1, n] 范围内所有整数的排列
1 <= sequences.length <= 104
1 <= sequences[i].length <= 104
1 <= sum(sequences[i].length) <= 105
1 <= sequences[i][j] <= n
sequences 的所有数组都是 唯一 的
sequences[i] 是 nums 的一个子序列
 

注意：本题与主站 444 题相同：https://leetcode-cn.com/problems/sequence-reconstruction/

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/ur2n8P
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        unordered_map<int, unordered_set<int>> nextNums;

        for (auto& sequence : sequences) {
            for (int i = 1; i < (int)sequence.size(); ++i) {
                nextNums[sequence[i - 1]].insert(sequence[i]);
            }
        }

        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nextNums[nums[i - 1]].count(nums[i]) == 0) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3 };
    vector<vector<int>> sequences = { {1,2},{1,3} };
    check.checkBool(false, o.sequenceReconstruction(nums, sequences));

    nums = { 1,2,3 };
    sequences = { {1,2} };
    check.checkBool(false, o.sequenceReconstruction(nums, sequences));

    nums = { 1,2,3 };
    sequences = { {1,2},{1,3},{2,3} };
    check.checkBool(true, o.sequenceReconstruction(nums, sequences));

    nums = { 1 };
    sequences = { {1},{1},{1} };
    check.checkBool(true, o.sequenceReconstruction(nums, sequences));
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
