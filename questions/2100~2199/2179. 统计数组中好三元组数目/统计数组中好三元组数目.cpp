/* 统计数组中好三元组数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始且长度为 n 的整数数组 nums1 和 nums2 ，两者都是 [0, 1, ..., n - 1] 的 排列 。

好三元组 指的是 3 个 互不相同 的值，且它们在数组 nums1 和 nums2 中出现顺序保持一致。换句话说，如果我们将 pos1v 记为值 v 在 nums1 中出现的位置，pos2v 为值 v 在 nums2 中的位置，那么一个好三元组定义为 0 <= x, y, z <= n - 1 ，且 pos1x < pos1y < pos1z 和 pos2x < pos2y < pos2z 都成立的 (x, y, z) 。

请你返回好三元组的 总数目 。

 

示例 1：

输入：nums1 = [2,0,1,3], nums2 = [0,1,2,3]
输出：1
解释：
总共有 4 个三元组 (x,y,z) 满足 pos1x < pos1y < pos1z ，分别是 (2,0,1) ，(2,0,3) ，(2,1,3) 和 (0,1,3) 。
这些三元组中，只有 (0,1,3) 满足 pos2x < pos2y < pos2z 。所以只有 1 个好三元组。
示例 2：

输入：nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
输出：4
解释：总共有 4 个好三元组 (4,0,3) ，(4,0,2) ，(4,1,3) 和 (4,1,2) 。
 

提示：

n == nums1.length == nums2.length
3 <= n <= 105
0 <= nums1[i], nums2[i] <= n - 1
nums1 和 nums2 是 [0, 1, ..., n - 1] 的排列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-good-triplets-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class BIT {
public:
    BIT(int n) {
        size = n;
        tree.resize(n + 1, 0);
    }

    int lowbit(int index) {
        return index & (-index);  // 保留最低位的1
    }

    void update(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += lowbit(index);
        }
    }

    int query(int index) {
        int value = 0;

        while (index != 0) {
            value += tree[index];
            index -= lowbit(index);
        }

        return value;
    }

private:
    int size;
    vector<int> tree;
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> tokens(n), leftLess(n);

        getToken(n, nums1, tokens);  // 将nums1映射到0,1,2,3...
        mapping(n, tokens, nums2);  // 根据token转换nums2
        getLeftLess(n, nums2, leftLess);  // 求nums2里面每一个数左边小于它的数的个数

        return getGoodTriplets(n, nums2, leftLess);
    }

    void getToken(int n, vector<int>& nums, vector<int>& tokens) {
        for (int i = 0; i < n; ++i) {
            tokens[nums[i]] = i;
        }
    }

    void mapping(int n, vector<int>& tokens, vector<int>& nums) {
        for (int i = 0; i < n; ++i) {
            nums[i] = tokens[nums[i]];
        }
    }

    void getLeftLess(int n, vector<int>& nums, vector<int>& leftLess) {
        BIT bit(n + 1);  // nums的0,1,2...对应bit的1,2,3...位置

        for (int i = 0; i < n; ++i) {
            leftLess[i] = bit.query(nums[i]);  // 统计[1, nums[i]]的个数，也就是小于nums[i] + 1的个数
            bit.update(nums[i] + 1, 1);  // nums[i] + 1位置新增一个数
        }
    }

    long long getGoodTriplets(int n, vector<int>& nums, vector<int>& leftLess) {
        long long goodTriplets = 0;

        for (int i = 1; i < n - 1; ++i) {
            /* 左边小于nums[i]的个数是leftLess[i]，大于nums[i]的个数是i - leftLess[i]，总共大于nums[i]的个数是n - 1 - nums[i]，
               所以右边大于nums[i]的个数是n - 1 - nums[i] - (i - leftLess[i]) */
            goodTriplets += (leftLess[i] * ((long long)n - 1 - nums[i] - ((long long)i - leftLess[i])));
        }

        return goodTriplets;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 2,0,1,3 };
    vector<int> nums2 = { 0,1,2,3 };
    check.checkLongLong(1, o.goodTriplets(nums1, nums2));

    nums1 = { 4,0,1,3,2 };
    nums2 = { 4,1,0,2,3 };
    check.checkLongLong(4, o.goodTriplets(nums1, nums2));

    nums1 = { 0,1,2,3,4,5,6,7,8,9 };
    nums2 = { 0,1,2,3,4,5,6,7,8,9 };
    check.checkLongLong(120, o.goodTriplets(nums1, nums2));
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
