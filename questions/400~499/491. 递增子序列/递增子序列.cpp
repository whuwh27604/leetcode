/* 递增子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。

示例:

输入: [4, 6, 7, 7]
输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
说明:

给定数组的长度不会超过15。
数组中的整数范围是 [-100,100]。
给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/increasing-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> increasingSubseqs;
        unordered_set<int> selected;

        for (int i = 0; i < (int)nums.size(); i++) {
            if (selected.find(nums[i]) == selected.end()) {  // 不选重复的数，因为在它第一次出现时，就遍历了所有可能
                BFS(nums, i, increasingSubseqs);
                selected.insert(nums[i]);
            }
        }

        return increasingSubseqs;
    }

    void BFS(vector<int>& nums, int index, vector<vector<int>>& increasingSubseqs) {
        queue<vector<int>> subSeqs;
        subSeqs.push({ nums[index],index });

        while (!subSeqs.empty()) {
            int size = subSeqs.size();
            for (int i = 0; i < size; i++) {
                vector<int> prevSubseq = subSeqs.front();
                subSeqs.pop();
                int lastIndex = prevSubseq.back();
                prevSubseq.pop_back();
                int last = prevSubseq.back();

                if (prevSubseq.size() > 1) {
                    increasingSubseqs.push_back(prevSubseq);
                }

                unordered_set<int> selected;
                while (++lastIndex < (int)nums.size()) {
                    int current = nums[lastIndex];
                    if (current < last) {  // 大于等于last的数添加到最后构成一个新的递增序列
                        continue;
                    }

                    if (selected.find(current) != selected.end()) {  // 这一轮已经选过这个数，不再重复选择
                        continue;
                    }

                    vector<int> subseq = prevSubseq;
                    subseq.push_back(current);
                    subseq.push_back(lastIndex);  // 保存一下最后这个数的index，下一轮好知道从哪里开始找
                    subSeqs.push(subseq);
                    selected.insert(current);
                }
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 4,6,7,7 };
    vector<vector<int>> actual = o.findSubsequences(nums);
    vector<vector<int>> expected = { {4,6},{4,7},{4,6,7},{4,7,7},{4,6,7,7},{6,7},{6,7,7},{7,7} };
    check.checkIntVectorVector(expected, actual);

    nums = {  };
    actual = o.findSubsequences(nums);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    nums = { 1 };
    actual = o.findSubsequences(nums);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    nums = { 2,2 };
    actual = o.findSubsequences(nums);
    expected = { {2,2} };
    check.checkIntVectorVector(expected, actual);

    nums = { 2,2,2 };
    actual = o.findSubsequences(nums);
    expected = { {2,2},{2,2,2} };
    check.checkIntVectorVector(expected, actual);

    nums = { 1,2,3,4 };
    actual = o.findSubsequences(nums);
    expected = { {1,2},{1,3},{1,4},{1,2,3},{1,2,4},{1,3,4},{1,2,3,4},{2,3},{2,4},{2,3,4},{3,4} };
    check.checkIntVectorVector(expected, actual);

    nums = { 4,3,2,1 };
    actual = o.findSubsequences(nums);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    nums = { 1,1,2,2,3,3 };
    actual = o.findSubsequences(nums);
    expected = { {1,1},{1,2},{1,3},{1,1,2},{1,1,3},{1,2,2},{1,2,3},{1,3,3},{1,1,2,2},{1,1,2,3},{1,1,3,3},{1,2,2,3},{1,2,3,3},
        {1,1,2,2,3},{1,1,2,3,3},{1,2,2,3,3},{1,1,2,2,3,3},{2,2},{2,3},{2,2,3},{2,3,3},{2,2,3,3},{3,3} };
    check.checkIntVectorVector(expected, actual);

    nums = { 1,1,8,1,1,1,1,1 };
    actual = o.findSubsequences(nums);
    expected = { {1,1},{1,8},{1,1,8},{1,1,1},{1,1,1,1},{1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1,1} };
    check.checkIntVectorVector(expected, actual);
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
