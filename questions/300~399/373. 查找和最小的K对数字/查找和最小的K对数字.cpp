/* 查找和最小的K对数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个以升序排列的整形数组 nums1 和 nums2, 以及一个整数 k。

定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2。

找到和最小的 k 对数字 (u1,v1), (u2,v2) ... (uk,vk)。

示例 1:

输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
输出: [1,2],[1,4],[1,6]
解释: 返回序列中的前 3 对数：
     [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
示例 2:

输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
输出: [1,1],[1,1]
解释: 返回序列中的前 2 对数：
     [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
示例 3:

输入: nums1 = [1,2], nums2 = [3], k = 3
输出: [1,3],[2,3]
解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

struct NumberPair {
    int index1;
    int value1;
    int index2;
    int value2;

    bool operator<(const NumberPair& o) const {
        return (o.value1 + o.value2) < (value1 + value2);
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> smallestPairs;

        if (nums1.size() < nums2.size()) {
            getKSmallestPairs(nums1, nums2, k, smallestPairs, false);
        }
        else {
            getKSmallestPairs(nums2, nums1, k, smallestPairs, true);
        }

        return smallestPairs;
    }

    void getKSmallestPairs(vector<int>& shorter, vector<int>& longer, int k, vector<vector<int>>& smallestPairs, bool needSwap) {
        int count = 0, shorterSize = shorter.size(), longerSize = longer.size();
        priority_queue<NumberPair> smallestFirstPairs;

        for (int i = 0; i < shorterSize; i++) {
            NumberPair numPair = { i,shorter[i],0,longer[0] };
            smallestFirstPairs.push(numPair);
        }

        while ((count++ < k) && !smallestFirstPairs.empty()) {
            NumberPair numPair = smallestFirstPairs.top();
            smallestFirstPairs.pop();
            if (needSwap) {
                smallestPairs.push_back({ numPair.value2, numPair.value1 });
            }
            else {
                smallestPairs.push_back({ numPair.value1, numPair.value2 });
            }

            if (++(numPair.index2) < longerSize) {
                numPair.value2 = longer[numPair.index2];
                smallestFirstPairs.push(numPair);
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums1 = { 1,7,11 };
    vector<int> nums2 = { 2,4,6 };
    vector<vector<int>> actual = o.kSmallestPairs(nums1, nums2, 3);
    vector<vector<int>> expected = { {1,2},{1,4},{1,6} };
    check.checkIntVectorVector(expected, actual);

    nums1 = { 1,1,2 };
    nums2 = { 1,2,3 };
    actual = o.kSmallestPairs(nums1, nums2, 2);
    expected = { {1,1},{1,1} };
    check.checkIntVectorVector(expected, actual);

    nums1 = { 1,2 };
    nums2 = { 3 };
    actual = o.kSmallestPairs(nums1, nums2, 3);
    expected = { {1,3},{2,3} };
    check.checkIntVectorVector(expected, actual);

    nums1 = {  };
    nums2 = {  };
    actual = o.kSmallestPairs(nums1, nums2, 3);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    nums1 = {  };
    nums2 = { 1 };
    actual = o.kSmallestPairs(nums1, nums2, 3);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    nums1 = { 1 };
    nums2 = { 1 };
    actual = o.kSmallestPairs(nums1, nums2, 0);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    nums1 = { 1 };
    nums2 = { 1 };
    actual = o.kSmallestPairs(nums1, nums2, 1);
    expected = { {1,1} };
    check.checkIntVectorVector(expected, actual);

    nums1 = { 1 };
    nums2 = { 1 };
    actual = o.kSmallestPairs(nums1, nums2, 2);
    expected = { {1,1} };
    check.checkIntVectorVector(expected, actual);

    nums1 = { 1 };
    nums2 = { 1,2 };
    actual = o.kSmallestPairs(nums1, nums2, 1);
    expected = { {1,1} };
    check.checkIntVectorVector(expected, actual);

    nums1 = { 1,2 };
    nums2 = { 1,2 };
    actual = o.kSmallestPairs(nums1, nums2, 5);
    expected = { {1,1},{1,2},{2,1},{2,2} };
    check.checkIntVectorVector(expected, actual);

    nums1 = { 1,2,3 };
    nums2 = { 1,2,3,4 };
    actual = o.kSmallestPairs(nums1, nums2, 2);
    expected = { {1,1},{2,1} };
    check.checkIntVectorVector(expected, actual);

    nums1 = { 1,2,3 };
    nums2 = { 1,2,3,4 };
    actual = o.kSmallestPairs(nums1, nums2, 3);
    expected = { {1,1},{2,1},{1,2} };
    check.checkIntVectorVector(expected, actual);

    nums1 = { 1,2,3 };
    nums2 = { 1,2,3,4 };
    actual = o.kSmallestPairs(nums1, nums2, 13);
    expected = { {1,1},{2,1},{1,2},{3,1},{2,2},{1,3},{3,2},{2,3},{1,4},{3,3},{2,4},{3,4} };
    check.checkIntVectorVector(expected, actual);

    nums1 = { 1,2,3,4,5 };
    nums2 = { 6,7,8,9,10 };
    actual = o.kSmallestPairs(nums1, nums2, 100);
    expected = { {1,6},{1,7},{2,6},{1,8},{2,7},{3,6},{1,9},{3,7},{4,6},{2,8},{2,9},{5,6},{3,8},{1,10},{4,7},{3,9},{2,10},{5,7},{4,8},{3,10},{4,9},{5,8},{4,10},{5,9},{5,10} };
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
