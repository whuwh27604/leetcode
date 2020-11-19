/* 存在重复元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组，判断是否存在重复元素。

如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

 

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contains-duplicate
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> existNum;
        for (unsigned int i = 0; i < nums.size(); i++) {
            if (existNum.find(nums[i]) != existNum.end()) {
                return true;
            }

            existNum.insert(nums[i]);
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3,1 };
    check.checkBool(true, o.containsDuplicate(nums));

    nums = { 1,2,3,4 };
    check.checkBool(false, o.containsDuplicate(nums));

    nums = { 1,1,1,3,3,4,3,2,4,2 };
    check.checkBool(true, o.containsDuplicate(nums));

    nums = {  };
    check.checkBool(false, o.containsDuplicate(nums));

    nums = { 1 };
    check.checkBool(false, o.containsDuplicate(nums));
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
