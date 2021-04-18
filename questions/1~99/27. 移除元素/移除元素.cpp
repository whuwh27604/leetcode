/* 移除元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

 

示例 1:

给定 nums = [3,2,2,3], val = 3,

函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,1,2,2,3,0,4,2], val = 2,

函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

注意这五个元素可为任意顺序。

你不需要考虑数组中超出新长度后面的元素。
 

说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
int len = removeElement(nums, val);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last = 0;

        for (int num : nums) {
            if (num != val) {
                nums[last++] = num;
            }
        }

        return last;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> t1Nums = { 3,2,2,3 };
    int val = 3;
    vector<int> t1Expected = { 2,2 };
    int t1ExpectedLen = 2;
    check.checkInt(t1ExpectedLen, o.removeElement(t1Nums, val));
    check.checkIntVectorInNums(t1Expected, t1Nums, t1ExpectedLen);

    vector<int> t2Nums = { 0,1,2,2,3,0,4,2 };
    val = 2;
    vector<int> t2Expected = { 0,1,3,0,4 };
    int t2ExpectedLen = 5;
    check.checkInt(t2ExpectedLen, o.removeElement(t2Nums, val));
    check.checkIntVectorInNums(t2Expected, t2Nums, t2ExpectedLen);

    vector<int> t3Nums;
    val = 0;
    vector<int> t3Expected;
    int t3ExpectedLen = 0;
    check.checkInt(t3ExpectedLen, o.removeElement(t3Nums, val));
    check.checkIntVectorInNums(t3Expected, t3Nums, t3ExpectedLen);

    vector<int> t4Nums = { 1 };
    val = 2;
    vector<int> t4Expected = { 1 };
    int t4ExpectedLen = 1;
    check.checkInt(t4ExpectedLen, o.removeElement(t4Nums, val));
    check.checkIntVectorInNums(t4Expected, t4Nums, t4ExpectedLen);

    vector<int> t5Nums = { 1,1 };
    val = 1;
    vector<int> t5Expected;
    int t5ExpectedLen = 0;
    check.checkInt(t5ExpectedLen, o.removeElement(t5Nums, val));
    check.checkIntVectorInNums(t5Expected, t5Nums, t5ExpectedLen);

    vector<int> t6Nums = { 1,2,2,2 };
    val = 2;
    vector<int> t6Expected = { 1 };
    int t6ExpectedLen = 1;
    check.checkInt(t6ExpectedLen, o.removeElement(t6Nums, val));
    check.checkIntVectorInNums(t6Expected, t6Nums, t6ExpectedLen);

    vector<int> t7Nums = { 1 };
    val = 1;
    vector<int> t7Expected;
    int t7ExpectedLen = 0;
    check.checkInt(t7ExpectedLen, o.removeElement(t7Nums, val));
    check.checkIntVectorInNums(t7Expected, t7Nums, t7ExpectedLen);
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
