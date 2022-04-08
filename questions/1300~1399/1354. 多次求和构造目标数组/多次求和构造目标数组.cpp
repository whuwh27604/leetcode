/* 多次求和构造目标数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 target 。一开始，你有一个数组 A ，它的所有元素均为 1 ，你可以执行以下操作：

令 x 为你数组里所有元素的和
选择满足 0 <= i < target.size 的任意下标 i ，并让 A 数组里下标为 i 处的值为 x 。
你可以重复该过程任意次
如果能从 A 开始构造出目标数组 target ，请你返回 True ，否则返回 False 。

 

示例 1：

输入：target = [9,3,5]
输出：true
解释：从 [1, 1, 1] 开始
[1, 1, 1], 和为 3 ，选择下标 1
[1, 3, 1], 和为 5， 选择下标 2
[1, 3, 5], 和为 9， 选择下标 0
[9, 3, 5] 完成
示例 2：

输入：target = [1,1,1,2]
输出：false
解释：不可能从 [1,1,1,1] 出发构造目标数组。
示例 3：

输入：target = [8,5]
输出：true
 

提示：

N == target.length
1 <= target.length <= 5 * 10^4
1 <= target[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-target-array-with-multiple-sums
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> nums;
        long long sum = 0, size = target.size();

        if (size == 1) {
            return target[0] == 1;
        }

        for (int num : target) {
            nums.push(num);
            sum += num;
        }

        while (sum != size) {
            int first = nums.top();
            nums.pop();

            sum -= first;
            if (first < sum) {
                return false;
            }

            first %= sum;
            if (first == 0) {
                return sum == 1;
            }

            nums.push(first);
            sum += first;
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> target = { 9,3,5 };
    check.checkBool(true, o.isPossible(target));

    target = { 8,5 };
    check.checkBool(true, o.isPossible(target));

    target = { 1 };
    check.checkBool(true, o.isPossible(target));

    target = { 1,1 };
    check.checkBool(true, o.isPossible(target));

    target = { 1000000000,1 };
    check.checkBool(true, o.isPossible(target));

    target = { 9 };
    check.checkBool(false, o.isPossible(target));

    target = { 1,1,1,2 };
    check.checkBool(false, o.isPossible(target));
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
