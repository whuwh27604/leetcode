/* 删除排序数组中的重复项.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

 

示例 1:

给定数组 nums = [1,1,2],

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。
 

说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size(), last = 0, current;
        if (size == 0) {
            return 0;
        }

        for (current = 1; current < size; ++current) {
            if (nums[current] != nums[last]) {
                nums[++last] = nums[current];
            }
        }

        return last + 1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> t1Nums = { 1,1,2 };
    vector<int> t1Expected = { 1,2 };
    int t1ExpectedLen = 2;
    check.checkInt(t1ExpectedLen, o.removeDuplicates(t1Nums));
    check.checkIntVectorInNums(t1Expected, t1Nums, t1ExpectedLen);

    vector<int> t2Nums = { 0,0,1,1,1,2,2,3,3,4 };
    vector<int> t2Expected = { 0,1,2,3,4 };
    int t2ExpectedLen = 5;
    check.checkInt(t2ExpectedLen, o.removeDuplicates(t2Nums));
    check.checkIntVectorInNums(t2Expected, t2Nums, t2ExpectedLen);

    vector<int> t3Nums;
    vector<int> t3Expected;
    int t3ExpectedLen = 0;
    check.checkInt(t3ExpectedLen, o.removeDuplicates(t3Nums));
    check.checkIntVectorInNums(t3Expected, t3Nums, t3ExpectedLen);

    vector<int> t4Nums = { 1 };
    vector<int> t4Expected = { 1 };
    int t4ExpectedLen = 1;
    check.checkInt(t4ExpectedLen, o.removeDuplicates(t4Nums));
    check.checkIntVectorInNums(t4Expected, t4Nums, t4ExpectedLen);

    vector<int> t5Nums = { 1,1 };
    vector<int> t5Expected = { 1 };
    int t5ExpectedLen = 1;
    check.checkInt(t5ExpectedLen, o.removeDuplicates(t5Nums));
    check.checkIntVectorInNums(t5Expected, t5Nums, t5ExpectedLen);

    vector<int> t6Nums = { 1,2,2,2 };
    vector<int> t6Expected = { 1,2 };
    int t6ExpectedLen = 2;
    check.checkInt(t6ExpectedLen, o.removeDuplicates(t6Nums));
    check.checkIntVectorInNums(t6Expected, t6Nums, t6ExpectedLen);
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
