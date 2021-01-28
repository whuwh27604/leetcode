/* 同积元组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由 不同 正整数组成的数组 nums ，请你返回满足 a * b = c * d 的元组 (a, b, c, d) 的数量。其中 a、b、c 和 d 都是 nums 中的元素，且 a != b != c != d 。

 

示例 1：

输入：nums = [2,3,4,6]
输出：8
解释：存在 8 个满足题意的元组：
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
示例 2：

输入：nums = [1,2,4,5,10]
输出：16
解释：存在 16 个满足题意的元组：
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,4,5)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
示例 3：

输入：nums = [2,3,4,6,8,12]
输出：40
示例 4：

输入：nums = [2,3,5,7]
输出：0
 

提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 104
nums 中的所有元素 互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/tuple-with-same-product
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int tuples = 0;
        unordered_map<int, int> productCount;

        getAllProducts(nums, productCount);

        for (auto iter = productCount.begin(); iter != productCount.end(); ++iter) {
            if (iter->second > 1) {
                tuples += (iter->second * (iter->second - 1) * 4);
            }
        }

        return tuples;
    }

    void getAllProducts(vector<int>& nums, unordered_map<int, int>& productCount) {
        int i, j, size = nums.size();

        for (i = 0; i < size - 1; ++i) {
            for (j = i + 1; j < size; ++j) {
                ++productCount[nums[i] * nums[j]];
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,3,4,6 };
    check.checkInt(8, o.tupleSameProduct(nums));

    nums = { 1,2,4,5,10 };
    check.checkInt(16, o.tupleSameProduct(nums));

    nums = { 2,3,4,6,8,12 };
    check.checkInt(40, o.tupleSameProduct(nums));

    nums = { 2,3,5,7 };
    check.checkInt(0, o.tupleSameProduct(nums));
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
