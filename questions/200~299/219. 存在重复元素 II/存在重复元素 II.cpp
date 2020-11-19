/* 存在重复元素 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。

 

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contains-duplicate-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0) {
            return false;
        }

        unordered_set<int> inWindowNum;
        for (unsigned int i = 0; i < nums.size(); i++) {
            if (inWindowNum.find(nums[i]) != inWindowNum.end()) {
                return true;
            }

            inWindowNum.insert(nums[i]);

            if (inWindowNum.size() > (unsigned int)k) {
                inWindowNum.erase(nums[i - k]);
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3,1 };
    check.checkBool(true, o.containsNearbyDuplicate(nums, 3));

    nums = { 1,2,3,1 };
    check.checkBool(false, o.containsNearbyDuplicate(nums, 2));

    nums = { 1,0,1,1 };
    check.checkBool(true, o.containsNearbyDuplicate(nums, 1));

    nums = { 1,2,3,1,2,3 };
    check.checkBool(false, o.containsNearbyDuplicate(nums, 2));

    nums = { 1,2,3,1 };
    check.checkBool(false, o.containsNearbyDuplicate(nums, 0));

    nums = { 1 };
    check.checkBool(false, o.containsNearbyDuplicate(nums, 2));
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
