/* 与数组中元素的最大异或值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由非负整数组成的数组 nums 。另有一个查询数组 queries ，其中 queries[i] = [xi, mi] 。

第 i 个查询的答案是 xi 和任何 nums 数组中不超过 mi 的元素按位异或（XOR）得到的最大值。换句话说，答案是 max(nums[j] XOR xi) ，其中所有 j 均满足 nums[j] <= mi 。如果 nums 中的所有元素都大于 mi，最终答案就是 -1 。

返回一个整数数组 answer 作为查询的答案，其中 answer.length == queries.length 且 answer[i] 是第 i 个查询的答案。

 

示例 1：

输入：nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
输出：[3,3,7]
解释：
1) 0 和 1 是仅有的两个不超过 1 的整数。0 XOR 3 = 3 而 1 XOR 3 = 2 。二者中的更大值是 3 。
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
示例 2：

输入：nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
输出：[15,-1,5]
 

提示：

1 <= nums.length, queries.length <= 105
queries[i].length == 2
0 <= nums[j], xi, mi <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] == v2[1] ? v1[0] < v2[0] : v1[1] < v2[1];
}

class TrieNode {
public:
    TrieNode() {
        left = NULL;
        right = NULL;
    }

    TrieNode* left;
    TrieNode* right;
};

class Trie {
public:
    Trie() {
        root = new TrieNode;
    }

    void insert(int num) {
        TrieNode* current = root;
        int bit = 0x20000000;

        for (int i = 0; i < 30; ++i, bit >>= 1) {
            if ((num & bit) == 0) {
                if (current->left == NULL) {
                    current->left = new TrieNode;
                }
                current = current->left;
            }
            else {
                if (current->right == NULL) {
                    current->right = new TrieNode;
                }
                current = current->right;
            }
        }
    }

    int getMaxXor(int num) {
        TrieNode* another = root;
        int maxXor = 0, bit = 0x20000000;

        for (int i = 0; i < 30; ++i, bit >>= 1) {
            maxXor <<= 1;
            if ((num & bit) == 0) {
                if (another->right != NULL) {
                    maxXor += 1;
                    another = another->right;
                }
                else {
                    another = another->left;
                }
            }
            else {
                if (another->left != NULL) {
                    maxXor += 1;
                    another = another->left;
                }
                else {
                    another = another->right;
                }
            }
        }

        return maxXor;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int i = 0;
        vector<int> ans(queries.size());
        Trie trie;

        addIndex(queries);
        sort(nums.begin(), nums.end());
        sort(queries.begin(), queries.end(), vectorCompare);

        for (auto& query : queries) {
            int x = query[0], m = query[1], index = query[2];

            if (m < nums[0]) {
                ans[index] = -1;
            }
            else {
                while (i < (int)nums.size() && nums[i] <= m) {
                    trie.insert(nums[i++]);
                }

                ans[index] = trie.getMaxXor(x);
            }
        }

        return ans;
    }

    void addIndex(vector<vector<int>>& queries) {
        int index = 0;

        for (auto& query : queries) {
            query.push_back(index++);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 0,1,2,3,4 };
    vector<vector<int>> queries = { {3,1},{1,3},{5,6} };
    vector<int> actual = o.maximizeXor(nums, queries);
    vector<int> expected = { 3,3,7 };
    check.checkIntVector(expected, actual);

    nums = { 5,2,4,6,6,3 };
    queries = { {12,4},{8,1},{6,3} };
    actual = o.maximizeXor(nums, queries);
    expected = { 15,-1,5 };
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
