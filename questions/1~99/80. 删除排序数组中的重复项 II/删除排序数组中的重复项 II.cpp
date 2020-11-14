/* 删除排序数组中的重复项 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:

给定 nums = [1,1,1,2,2,3],

函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,1,2,3,3],

函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。

你不需要考虑数组中超出新长度后面的元素。
说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, len = nums.size(), tail = 0, count = 1;
        if (len <= 2) {
            return len;
        }

        for (i = 1; i < len; i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
                if (count == 2) {
                    nums[++tail] = nums[i];
                }
            }
            else {
                count = 1;
                nums[++tail] = nums[i];
            }
        }

        return tail + 1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,1,1,2,2,3 };
    vector<int> expected = { 1,1,2,2,3 };
    check.checkInt(5, o.removeDuplicates(nums));
    check.checkIntVectorInNums(expected, nums, 5);

    nums = { 0,0,1,1,1,1,2,3,3 };
    expected = { 0,0,1,1,2,3,3 };
    check.checkInt(7, o.removeDuplicates(nums));
    check.checkIntVectorInNums(expected, nums, 7);

    nums = {  };
    expected = {  };
    check.checkInt(0, o.removeDuplicates(nums));
    check.checkIntVectorInNums(expected, nums, 0);

    nums = { 1 };
    expected = { 1 };
    check.checkInt(1, o.removeDuplicates(nums));
    check.checkIntVectorInNums(expected, nums, 1);

    nums = { 1,1 };
    expected = { 1,1 };
    check.checkInt(2, o.removeDuplicates(nums));
    check.checkIntVectorInNums(expected, nums, 2);

    nums = { 1,2 };
    expected = { 1,2 };
    check.checkInt(2, o.removeDuplicates(nums));
    check.checkIntVectorInNums(expected, nums, 2);

    nums = { 1,1,1 };
    expected = { 1,1 };
    check.checkInt(2, o.removeDuplicates(nums));
    check.checkIntVectorInNums(expected, nums, 2);

    nums = { 1,2,3,3,3 };
    expected = { 1,2,3,3 };
    check.checkInt(4, o.removeDuplicates(nums));
    check.checkIntVectorInNums(expected, nums, 4);

    nums = { 1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,7,7,7,7,7,7,7,8 };
    expected = { 1,2,2,3,3,4,4,5,5,6,6,7,7,8 };
    check.checkInt(14, o.removeDuplicates(nums));
    check.checkIntVectorInNums(expected, nums, 14);
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
