/* 裁剪数字后查询第 K 小的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串数组 nums ，其中每个字符串 长度相等 且只包含数字。

再给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [ki, trimi] 。对于每个 queries[i] ，你需要：

将 nums 中每个数字 裁剪 到剩下 最右边 trimi 个数位。
在裁剪过后的数字中，找到 nums 中第 ki 小数字对应的 下标 。如果两个裁剪后数字一样大，那么下标 更小 的数字视为更小的数字。
将 nums 中每个数字恢复到原本字符串。
请你返回一个长度与 queries 相等的数组 answer，其中 answer[i]是第 i 次查询的结果。

提示：

裁剪到剩下 x 个数位的意思是不断删除最左边的数位，直到剩下 x 个数位。
nums 中的字符串可能会有前导 0 。
 

示例 1：

输入：nums = ["102","473","251","814"], queries = [[1,1],[2,3],[4,2],[1,2]]
输出：[2,2,1,0]
解释：
1. 裁剪到只剩 1 个数位后，nums = ["2","3","1","4"] 。最小的数字是 1 ，下标为 2 。
2. 裁剪到剩 3 个数位后，nums 没有变化。第 2 小的数字是 251 ，下标为 2 。
3. 裁剪到剩 2 个数位后，nums = ["02","73","51","14"] 。第 4 小的数字是 73 ，下标为 1 。
4. 裁剪到剩 2 个数位后，最小数字是 2 ，下标为 0 。
   注意，裁剪后数字 "02" 值为 2 。
示例 2：

输入：nums = ["24","37","96","04"], queries = [[2,1],[2,2]]
输出：[3,0]
解释：
1. 裁剪到剩 1 个数位，nums = ["4","7","6","4"] 。第 2 小的数字是 4 ，下标为 3 。
   有两个 4 ，下标为 0 的 4 视为小于下标为 3 的 4 。
2. 裁剪到剩 2 个数位，nums 不变。第二小的数字是 24 ，下标为 0 。
 

提示：

1 <= nums.length <= 100
1 <= nums[i].length <= 100
nums[i] 只包含数字。
所有 nums[i].length 的长度 相同 。
1 <= queries.length <= 100
queries[i].length == 2
1 <= ki <= nums.length
1 <= trimi <= nums[0].length

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/query-kth-smallest-trimmed-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool queryCompare(const vector<int>& q1, const vector<int>& q2) {
    return q1[1] < q2[1];  // 按照查询的trim排序
}

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int m = nums.size(), n = queries.size(), len = nums[0].size(), i = 0;
        vector<int> prev(m), ans(n);  // prev[k]、current[k]表示排在第k位的索引是多少

        addIndex(queries);
        sort(queries.begin(), queries.end(), queryCompare);
        init(m, prev);

        for (int trim = 1; trim <= len; ++trim) {  // 按照从后往前的顺序排序
            vector<int> current(m);
            sortLastTrim(m, nums, prev, current, len - trim);

            for (; i < n && queries[i][1] == trim; ++i) {  // 每排完一次，记录相应的query答案
                ans[queries[i][2]] = current[queries[i][0] - 1];
            }

            prev = current;
        }

        return ans;
    }

    void init(int m, vector<int>& seq) {
        for (int i = 0; i < m; ++i) {
            seq[i] = i;
        }
    }

    void addIndex(vector<vector<int>>& queries) {
        int index = 0;

        for (auto& query : queries) {
            query.push_back(index++);
        }
    }

    void sortLastTrim(int m, vector<string>& nums, vector<int>& prev, vector<int>& current, int trim) {  // 根据prev排序current
        vector<vector<int>> seqs(10);
        int index = 0;

        for (int i = 0; i < m; ++i) {  // 先按照nums[][trim]分类
            seqs[nums[prev[i]][trim] - '0'].push_back(prev[i]);
        }

        for (auto& seq : seqs) {  // 然后按照nums[][trim]从0到9的顺序导出idx，先导出的必然更小，nums[][trim]相同时遵循prev的顺序
            for (int idx : seq) {
                current[index++] = idx;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> nums = { "102","473","251","814" };
    vector<vector<int>> queries = { {1,1},{2,3},{4,2},{1,2} };
    vector<int> actual = o.smallestTrimmedNumbers(nums, queries);
    vector<int> expected = { 2,2,1,0 };
    check.checkIntVector(expected, actual);

    nums = { "24","37","96","04" };
    queries = { {2,1},{2,2} };
    actual = o.smallestTrimmedNumbers(nums, queries);
    expected = { 3,0 };
    check.checkIntVector(expected, actual);

    nums = { "22222222222222222222222222222222222222222222222225","22222222222222222222222222222222222222222222222221","22222222222222222222222222222222222222222222222223","22222222222222222222222222222222222222222222222228","22222222222222222222222222222222222222222222222226" };
    queries = { {1,40},{3,40},{2,40},{5,40},{4,40} };
    actual = o.smallestTrimmedNumbers(nums, queries);
    expected = { 1,0,2,3,4 };
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
