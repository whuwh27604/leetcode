/* 统计异或值在范围内的数对有多少.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums （下标 从 0 开始 计数）以及两个整数：low 和 high ，请返回 漂亮数对 的数目。

漂亮数对 是一个形如 (i, j) 的数对，其中 0 <= i < j < nums.length 且 low <= (nums[i] XOR nums[j]) <= high 。

 

示例 1：

输入：nums = [1,4,2,7], low = 2, high = 6
输出：6
解释：所有漂亮数对 (i, j) 列出如下：
    - (0, 1): nums[0] XOR nums[1] = 5
    - (0, 2): nums[0] XOR nums[2] = 3
    - (0, 3): nums[0] XOR nums[3] = 6
    - (1, 2): nums[1] XOR nums[2] = 6
    - (1, 3): nums[1] XOR nums[3] = 3
    - (2, 3): nums[2] XOR nums[3] = 5
示例 2：

输入：nums = [9,8,4,2,1], low = 5, high = 14
输出：8
解释：所有漂亮数对 (i, j) 列出如下：
​​​​​    - (0, 2): nums[0] XOR nums[2] = 13
    - (0, 3): nums[0] XOR nums[3] = 11
    - (0, 4): nums[0] XOR nums[4] = 8
    - (1, 2): nums[1] XOR nums[2] = 12
    - (1, 3): nums[1] XOR nums[3] = 10
    - (1, 4): nums[1] XOR nums[4] = 9
    - (2, 3): nums[2] XOR nums[3] = 6
    - (2, 4): nums[2] XOR nums[4] = 5
 

提示：

1 <= nums.length <= 2 * 104
1 <= nums[i] <= 2 * 104
1 <= low <= high <= 2 * 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-pairs-with-xor-in-a-range
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    TrieNode() : left(NULL), right(NULL), count(0) {}

    TrieNode* left;
    TrieNode* right;
    int count;
};

class Trie {
public:
    Trie(int _maxBits) {
        root = new TrieNode;
        maxBits = _maxBits;
    }

    void insert(int num) {
        TrieNode* current = root;
        int bit = (1 << (maxBits - 1));

        while (bit != 0) {
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

            ++current->count;  // count用来记录有多少个数经过这个节点
            bit >>= 1;
        }
    }

    int search(int num, int noGreater) {
        TrieNode* current = root;
        int bit = (1 << (maxBits - 1)), count = 0;

        while (current != NULL && bit != 1) {
            if ((noGreater & bit) == 0) {  // noGreater的当前bit是0，那么只能让xor结果为0，否则就比它大了
                current = (num & bit) == 0 ? current->left : current->right;  // 让xor结果为0，继续往后寻找
            }
            else {  // noGreater的当前bit是1，那么所有xor结果为0的数对都是答案
                if ((num & bit) == 0) {
                    if (current->left != NULL) {  // num是0，另外一个数也选0，xor结果为0
                        count += current->left->count;
                    }
                    current = current->right;  // 然后另外一个数选1，xor结果为1，等于noGreater，继续往后寻找
                }
                else {
                    if (current->right != NULL) {  // num是1，另外一个数也选1，xor结果为0
                        count += current->right->count;
                    }
                    current = current->left;  // 然后另外一个数选0，xor结果为1，等于noGreater，继续往后寻找
                }
            }

            bit >>= 1;
        }

        if (current != NULL) {  // bit==1
            if ((noGreater & bit) == 0) {
                if ((num & bit) == 0) {  // num是0，另外一个数也选0，xor结果为0
                    count += (current->left == NULL ? 0 : current->left->count);
                }
                else {  // num是1，另外一个数也选1，xor结果为0
                    count += (current->right == NULL ? 0 : current->right->count);
                }
            }
            else {  // 因为可以等于noGreater，所以最后一位的时候如果noGreater是1，那么xor结果是0或者1都可以
                count += (current->left == NULL ? 0 : current->left->count);
                count += (current->right == NULL ? 0 : current->right->count);
            }
        }

        return count;
    }

private:
    TrieNode* root;
    int maxBits;
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int maxBits = getMaxBits(max(*max_element(nums.begin(), nums.end()), high));
        Trie trie(maxBits);

        buildTrie(nums, trie);

        return (countPairsNoGreater(trie, nums, high) - countPairsNoGreater(trie, nums, low - 1)) / 2;
    }

    int getMaxBits(int maxNum) {
        int maxBits = 0;

        while (maxNum != 0) {
            maxNum >>= 1;
            ++maxBits;
        }

        return maxBits;
    }

    void buildTrie(vector<int>& nums, Trie& trie) {
        for (int num : nums) {
            trie.insert(num);
        }
    }

    int countPairsNoGreater(Trie& trie, vector<int>& nums, int noGreater) {
        int pairs = 0;

        for (int num : nums) {
            pairs += trie.search(num, noGreater);
        }

        return pairs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,4,2,7 };
    check.checkInt(6, o.countPairs(nums, 2, 6));

    nums = { 9,8,4,2,1 };
    check.checkInt(8, o.countPairs(nums, 5, 14));

    nums = { 1 };
    check.checkInt(0, o.countPairs(nums, 2, 6));

    nums = { 1,4 };
    check.checkInt(1, o.countPairs(nums, 2, 6));

    nums = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50 };
    check.checkInt(1225, o.countPairs(nums, 1, 100));

    nums = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50 };
    check.checkInt(654, o.countPairs(nums, 1, 32));

    nums = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50 };
    check.checkInt(444, o.countPairs(nums, 10, 32));

    nums = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50 };
    check.checkInt(233, o.countPairs(nums, 1, 10));

    nums = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50 };
    check.checkInt(210, o.countPairs(nums, 1, 9));
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
