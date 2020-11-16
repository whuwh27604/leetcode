/* 两数之和 II - 输入有序数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size(), left = 0, right = size - 1;

        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                break;
            }

            if (numbers[left] + numbers[right] > target) {
                right--;
            }
            else {
                left++;
            }
        }

        return { left + 1, right + 1 };
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> numbers = { 2,7,11,15 };
    vector<int> actual = o.twoSum(numbers, 9);
    vector<int> expected = { 1,2 };
    check.checkIntVector(expected, actual);

    actual = o.twoSum(numbers, 18);
    expected = { 2,3 };
    check.checkIntVector(expected, actual);

    actual = o.twoSum(numbers, 26);
    expected = { 3,4 };
    check.checkIntVector(expected, actual);
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
