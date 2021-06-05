/* 形成目标数组的子数组最少增加次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 target 和一个数组 initial ，initial 数组与 target  数组有同样的维度，且一开始全部为 0 。

请你返回从 initial 得到  target 的最少操作次数，每次操作需遵循以下规则：

在 initial 中选择 任意 子数组，并将子数组中每个元素增加 1 。
答案保证在 32 位有符号整数以内。

 

示例 1：

输入：target = [1,2,3,2,1]
输出：3
解释：我们需要至少 3 次操作从 intial 数组得到 target 数组。
[0,0,0,0,0] 将下标为 0 到 4 的元素（包含二者）加 1 。
[1,1,1,1,1] 将下标为 1 到 3 的元素（包含二者）加 1 。
[1,2,2,2,1] 将下表为 2 的元素增加 1 。
[1,2,3,2,1] 得到了目标数组。
示例 2：

输入：target = [3,1,1,2]
输出：4
解释：(initial)[0,0,0,0] -> [1,1,1,1] -> [1,1,1,2] -> [2,1,1,2] -> [3,1,1,2] (target) 。
示例 3：

输入：target = [3,1,5,4,2]
输出：7
解释：(initial)[0,0,0,0,0] -> [1,1,1,1,1] -> [2,1,1,1,1] -> [3,1,1,1,1]
                                  -> [3,1,2,2,2] -> [3,1,3,3,2] -> [3,1,4,4,2] -> [3,1,5,4,2] (target)。
示例 4：

输入：target = [1,1,1,1]
输出：1
 

提示：

1 <= target.length <= 10^5
1 <= target[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int prev = 0, opers = 0;

        for (int num : target) {
            if (num > prev) {
                opers += (num - prev);
            }

            prev = num;
        }

        return opers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> target = { 1,2,3,2,1 };
    check.checkInt(3, o.minNumberOperations(target));

    target = { 3,1,1,2 };
    check.checkInt(4, o.minNumberOperations(target));

    target = { 3,1,5,4,2 };
    check.checkInt(7, o.minNumberOperations(target));

    target = { 1,1,1,1 };
    check.checkInt(1, o.minNumberOperations(target));

    target = { 5 };
    check.checkInt(5, o.minNumberOperations(target));
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
