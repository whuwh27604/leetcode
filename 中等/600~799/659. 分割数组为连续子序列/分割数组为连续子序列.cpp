/* 分割数组为连续子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个按升序排序的整数数组 num（可能包含重复数字），请你将它们分割成一个或多个子序列，其中每个子序列都由连续整数组成且长度至少为 3 。

如果可以完成上述分割，则返回 true ；否则，返回 false 。

 

示例 1：

输入: [1,2,3,3,4,5]
输出: True
解释:
你可以分割出这样两个连续子序列 :
1, 2, 3
3, 4, 5
 

示例 2：

输入: [1,2,3,3,4,4,5,5]
输出: True
解释:
你可以分割出这样两个连续子序列 :
1, 2, 3, 4, 5
3, 4, 5
 

示例 3：

输入: [1,2,3,4,4,5]
输出: False
 

提示：

输入的数组长度范围为 [1, 10000]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

// 贪心算法，能不新起一个序列就不要新起，总是优先接在已经存在的序列后面
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }

        unordered_map<long long, int> subsequences;  // key=序列结束的位置，value=结束在该位置的序列的个数
        unordered_map<long long, int> borrows;
        unordered_map<long long, int> numsCount;
        countNums(nums, numsCount);

        for (int num : nums) {
            if (subtractOne(borrows, num)) {  // 如果前面新起序列有借用数字，这里先还上
                continue;
            }

            subtractOne(numsCount, num);

            if (!subtractOne(subsequences, num - 1)) {  // 结束在num-1的序列个数减1
                if (!newSubsequence(subsequences, numsCount, borrows, num)) {
                    return false;  // 没有结束在num-1的序列，新起一个序列，不能成功则说明原数组无法分割为连续子系列
                }
                continue;
            }

            addOne(subsequences, num);  // 结束在num的序列个数加1
        }

        return true;
    }

    void countNums(vector<int>& nums, unordered_map<long long, int>& numsCount) {
        int i, size = nums.size(), count = 1;
        long long prev = nums[0], current;

        for (i = 1; i < size; i++) {
            current = nums[i];
            if (current == prev) {
                count++;
            }
            else {
                numsCount.insert({ prev, count });
                prev = current;
                count = 1;
            }
        }

        numsCount.insert({ prev, count });
    }

    bool newSubsequence(unordered_map<long long, int>& subsequences, unordered_map<long long, int>& numsCount, unordered_map<long long, int>& borrows, long long start) {
        if (!subtractOne(numsCount, ++start)) {  // 新起一个序列要有start、start+1、start+2三个数
            return false;
        }
        addOne(borrows, start);  // nums还没有遍历到这个数，先借用一下

        if (!subtractOne(numsCount, ++start)) {
            return false;
        }
        addOne(borrows, start);

        addOne(subsequences, start);  // 结束在start+2的序列个数加1

        return true;
    }

    void addOne(unordered_map<long long, int>& table, long long key) {
        auto iter = table.find(key);
        if (iter == table.end()) {
            table[key] = 1;
        }
        else {
            iter->second++;
        }
    }

    bool subtractOne(unordered_map<long long, int>& table, long long key) {
        auto iter = table.find(key);
        if (iter == table.end()) {
            return false;
        }

        if (--iter->second == 0) {
            table.erase(iter);
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3,3,4,5 };
    check.checkBool(true, o.isPossible(nums));

    nums = { 1,2,3,3,4,4,5,5 };
    check.checkBool(true, o.isPossible(nums));

    nums = { 1,2,3,4,4,5 };
    check.checkBool(false, o.isPossible(nums));

    nums = { 1,2,3 };
    check.checkBool(true, o.isPossible(nums));

    nums = { 1,2,3,4,5 };
    check.checkBool(true, o.isPossible(nums));

    nums = { 1,2,3,4,5,6,6,8,9,9 };
    check.checkBool(false, o.isPossible(nums));

    nums = { 1,2,3,3,4,4,5,6 };
    check.checkBool(true, o.isPossible(nums));

    nums = { 4,5,6,7,7,8,8,9,10,11 };
    check.checkBool(true, o.isPossible(nums));
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
