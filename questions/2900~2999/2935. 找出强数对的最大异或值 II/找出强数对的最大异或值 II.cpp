/* 找出强数对的最大异或值 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。如果一对整数 x 和 y 满足以下条件，则称其为 强数对 ：

|x - y| <= min(x, y)
你需要从 nums 中选出两个整数，且满足：这两个整数可以形成一个强数对，并且它们的按位异或（XOR）值是在该数组所有强数对中的 最大值 。

返回数组 nums 所有可能的强数对中的 最大 异或值。

注意，你可以选择同一个整数两次来形成一个强数对。



示例 1：

输入：nums = [1,2,3,4,5]
输出：7
解释：数组 nums 中有 11 个强数对：(1, 1), (1, 2), (2, 2), (2, 3), (2, 4), (3, 3), (3, 4), (3, 5), (4, 4), (4, 5) 和 (5, 5) 。
这些强数对中的最大异或值是 3 XOR 4 = 7 。
示例 2：

输入：nums = [10,100]
输出：0
解释：数组 nums 中有 2 个强数对：(10, 10) 和 (100, 100) 。
这些强数对中的最大异或值是 10 XOR 10 = 0 ，数对 (100, 100) 的异或值也是 100 XOR 100 = 0 。
示例 3：

输入：nums = [500,520,2500,3000]
输出：1020
解释：数组 nums 中有 6 个强数对：(500, 500), (500, 520), (520, 520), (2500, 2500), (2500, 3000) 和 (3000, 3000) 。
这些强数对中的最大异或值是 500 XOR 520 = 1020 ；另一个异或值非零的数对是 (5, 6) ，其异或值是 2500 XOR 3000 = 636 。


提示：

1 <= nums.length <= 5 * 104
1 <= nums[i] <= 220 - 1
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    TrieNode* left;
    TrieNode* right;
    int count;

    TrieNode() : left(NULL), right(NULL), count(0) {};
};

class Trie {
public:
    TrieNode* root;
    int maxBit = (1 << 19);

    Trie() {
        root = new TrieNode;
    }

    void insert(int num) {
        TrieNode* node = root;

        for (int bit = maxBit; bit != 0; bit >>= 1) {
            if ((num & bit) == 0) {  // bit0插入left，bit1插入right，计数加1
                if (node->left == NULL) {
                    node->left = new TrieNode;
                }
                node = node->left;
                ++node->count;
            }
            else {
                if (node->right == NULL) {
                    node->right = new TrieNode;
                }
                node = node->right;
                ++node->count;
            }
        }
    }

    void remove(int num) {
        TrieNode* node = root;

        for (int bit = maxBit; bit != 0; bit >>= 1) {
            node = (num & bit) == 0 ? node->left : node->right;
            --node->count;  // 删除时计数减1，简化编码减为0后并不删除节点
        }
    }

    int getMaxXor(int num) {
        int maxXor = 0;
        TrieNode* node = root;

        for (int bit = maxBit; bit != 0; bit >>= 1) {
            if ((num & bit) == 0) {  // num的当前bit是0，那么看right子树是否存在，存在则xor的结果该位为1
                if (node->right != NULL && node->right->count != 0) {
                    maxXor |= bit;
                    node = node->right;
                }
                else {
                    node = node->left;
                }
            }
            else {  // num的当前bit是1，那么看left子树是否存在，存在则xor的结果该位为1
                if (node->left != NULL && node->left->count != 0) {
                    maxXor |= bit;
                    node = node->left;
                }
                else {
                    node = node->right;
                }
            }
        }

        return maxXor;
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int size = nums.size(), left = 0, right = 0, maxXor = 0;
        Trie trie;

        sort(nums.begin(), nums.end());  // 答案与数组顺序无关，先排序

        for (; left < size; ++left) {  // 令x < y，则 |x - y| <= min(x, y) 化简为y <= 2 * x。遍历 x = nums[left]
            while (right < size && nums[right] <= 2 * nums[left]) {
                trie.insert(nums[right++]);  // 滑动窗口将[x, 2 * x]范围内的数加入trie
            }

            maxXor = max(maxXor, trie.getMaxXor(nums[left]));  // 然后通过trie求与x异或的最大结果

            trie.remove(nums[left]);  // 计算完成后将当前x移出trie
        }

        return maxXor;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,4,5 };
    check.checkInt(7, o.maximumStrongPairXor(nums));

    nums = { 10,100 };
    check.checkInt(0, o.maximumStrongPairXor(nums));

    nums = { 5,6,25,30 };
    check.checkInt(7, o.maximumStrongPairXor(nums));

    nums = { 500,520,2500,3000 };
    check.checkInt(1020, o.maximumStrongPairXor(nums));

    nums = { 1,2,3,4,5,10,100,10,100,500,520,2500,3000,5,6,25,30,1048575,1048574,1048573,1048572,1048571,1048570 };
    check.checkInt(1020, o.maximumStrongPairXor(nums));
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
