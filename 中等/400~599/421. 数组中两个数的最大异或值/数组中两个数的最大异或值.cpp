/* 数组中两个数的最大异或值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非空数组，数组中元素为 a0, a1, a2, … , an-1，其中 0 ≤ ai < 231 。

找到 ai 和aj 最大的异或 (XOR) 运算结果，其中0 ≤ i,  j < n 。

你能在O(n)的时间解决这个问题吗？

示例:

输入: [3, 10, 5, 25, 2, 8]

输出: 28

解释: 最大的结果是 5 ^ 25 = 28.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <list>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    TrieNode() {
        left = NULL;
        right = NULL;
    }

    TrieNode* left;
    TrieNode* right;
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode root;
        createTrie(nums, &root);

        int maxXOR = 0;
        for (int num : nums) {
            int xorResult = getMaxXOR(num, &root);
            maxXOR = (maxXOR > xorResult) ? maxXOR : xorResult;
        }

        return maxXOR;
    }

    void createTrie(vector<int>& nums, TrieNode* root) {
        for (int num : nums) {
            TrieNode* current = root;
            int bit = 0x40000000;

            for (int i = 0; i < 31; i++) {
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

                bit >>= 1;
            }
        }
    }

    int getMaxXOR(int num, TrieNode* root) {
        TrieNode* another = root;
        int XORNumber = 0;
        int bit = 0x40000000;

        for (int i = 0; i < 31; i++) {
            XORNumber <<= 1;
            if ((num & bit) == 0) {
                if (another->right != NULL) {
                    XORNumber += 1;
                    another = another->right;
                }
                else {
                    another = another->left;
                }
            }
            else {
                if (another->left != NULL) {
                    XORNumber += 1;
                    another = another->left;
                }
                else {
                    another = another->right;
                }
            }

            bit >>= 1;
        }

        return XORNumber;
    }
};

int violenceCheck(vector<int>& nums) {
    int i, j, size = nums.size(), maximun = 0;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            int num = nums[i] ^ nums[j];
            maximun = (maximun > num) ? maximun : num;
        }
    }

    return maximun;
}

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3,10,5,25,2,8 };
    check.checkInt(28, o.findMaximumXOR(nums));

    nums = { 3 };
    check.checkInt(0, o.findMaximumXOR(nums));

    nums = { 0 };
    check.checkInt(0, o.findMaximumXOR(nums));

    nums = { 0,0 };
    check.checkInt(0, o.findMaximumXOR(nums));

    nums = { 0,INT_MAX };
    check.checkInt(INT_MAX, o.findMaximumXOR(nums));

    nums = { INT_MAX,INT_MAX };
    check.checkInt(0, o.findMaximumXOR(nums));

    nums = { 1,2,3,4,5 };
    check.checkInt(violenceCheck(nums), o.findMaximumXOR(nums));

    nums = { 1,2,5,7 };
    check.checkInt(violenceCheck(nums), o.findMaximumXOR(nums));

    nums = { 1,2,3,4,5,6,7,8,9,10 };
    check.checkInt(violenceCheck(nums), o.findMaximumXOR(nums));

    nums = { 0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };
    check.checkInt(violenceCheck(nums), o.findMaximumXOR(nums));

    nums = { 2147483647,2147483646,2147483645,2147483644,2147483643,2147483642,2147483641,2147483640 };
    check.checkInt(violenceCheck(nums), o.findMaximumXOR(nums));

    nums = { 8,10,2 };
    check.checkInt(violenceCheck(nums), o.findMaximumXOR(nums));
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
