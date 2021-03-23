/* 有界数组中指定下标处的最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你三个正整数 n、index 和 maxSum 。你需要构造一个同时满足下述所有条件的数组 nums（下标 从 0 开始 计数）：

nums.length == n
nums[i] 是 正整数 ，其中 0 <= i < n
abs(nums[i] - nums[i+1]) <= 1 ，其中 0 <= i < n-1
nums 中所有元素之和不超过 maxSum
nums[index] 的值被 最大化
返回你所构造的数组中的 nums[index] 。

注意：abs(x) 等于 x 的前提是 x >= 0 ；否则，abs(x) 等于 -x 。

 

示例 1：

输入：n = 4, index = 2,  maxSum = 6
输出：2
解释：数组 [1,1,2,1] 和 [1,2,2,1] 满足所有条件。不存在其他在指定下标处具有更大值的有效数组。
示例 2：

输入：n = 6, index = 1,  maxSum = 10
输出：3
 

提示：

1 <= n <= maxSum <= 109
0 <= index < n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-value-at-a-given-index-in-a-bounded-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long left = 1, right = maxSum;

        while (left <= right) {
            long long middle = (left + right) / 2;
            long long sum = getSum(middle, index, n);

            if (sum > maxSum) {
                right = middle - 1;
            }
            else if (sum == maxSum) {
                return (int)middle;
            }
            else {
                left = middle + 1;
            }
        }

        return (int)right;
    }

    long long getSum(long long target, long long index, long long n) {
        long long sum = 0, leftmost, rightmost;

        if (target > index) {
            leftmost = target - index;
            sum += (target + leftmost) * (target - leftmost + 1) / 2;
        }
        else {
            sum += ((target + 1) * target / 2 + index - target + 1);
        }

        if (target > n - 1 - index) {
            rightmost = target - (n - 1 - index);
            sum += (target + rightmost) * (target - rightmost + 1) / 2;
        }
        else {
            sum += ((target + 1) * target / 2 + n - target - index);
        }

        return sum - target;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.maxValue(4, 2, 6));
    check.checkInt(3, o.maxValue(6, 1, 10));
    check.checkInt(4, o.maxValue(8, 7, 14));
    check.checkInt(7, o.maxValue(5, 0, 28));
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
