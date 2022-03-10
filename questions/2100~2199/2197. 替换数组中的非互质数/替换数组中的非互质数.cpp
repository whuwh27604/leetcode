/* 替换数组中的非互质数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 。请你对数组执行下述操作：

从 nums 中找出 任意 两个 相邻 的 非互质 数。
如果不存在这样的数，终止 这一过程。
否则，删除这两个数，并 替换 为它们的 最小公倍数（Least Common Multiple，LCM）。
只要还能找出两个相邻的非互质数就继续 重复 这一过程。
返回修改后得到的 最终 数组。可以证明的是，以 任意 顺序替换相邻的非互质数都可以得到相同的结果。

生成的测试用例可以保证最终数组中的值 小于或者等于 108 。

两个数字 x 和 y 满足 非互质数 的条件是：GCD(x, y) > 1 ，其中 GCD(x, y) 是 x 和 y 的 最大公约数 。

 

示例 1 ：

输入：nums = [6,4,3,2,7,6,2]
输出：[12,7,6]
解释：
- (6, 4) 是一组非互质数，且 LCM(6, 4) = 12 。得到 nums = [12,3,2,7,6,2] 。
- (12, 3) 是一组非互质数，且 LCM(12, 3) = 12 。得到 nums = [12,2,7,6,2] 。
- (12, 2) 是一组非互质数，且 LCM(12, 2) = 12 。得到 nums = [12,7,6,2] 。
- (6, 2) 是一组非互质数，且 LCM(6, 2) = 6 。得到 nums = [12,7,6] 。
现在，nums 中不存在相邻的非互质数。
因此，修改后得到的最终数组是 [12,7,6] 。
注意，存在其他方法可以获得相同的最终数组。
示例 2 ：

输入：nums = [2,2,1,1,3,3,3]
输出：[2,1,1,3]
解释：
- (3, 3) 是一组非互质数，且 LCM(3, 3) = 3 。得到 nums = [2,2,1,1,3,3] 。
- (3, 3) 是一组非互质数，且 LCM(3, 3) = 3 。得到 nums = [2,2,1,1,3] 。
- (2, 2) 是一组非互质数，且 LCM(2, 2) = 2 。得到 nums = [2,1,1,3] 。
现在，nums 中不存在相邻的非互质数。
因此，修改后得到的最终数组是 [2,1,1,3] 。
注意，存在其他方法可以获得相同的最终数组。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 105
生成的测试用例可以保证最终数组中的值 小于或者等于 108 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/replace-non-coprime-numbers-in-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int i, size = nums.size(), num = nums[0], next = 1;
        vector<int> ans = { nums[0] };

        for (i = 1; i < size; ++i) {
            ans.push_back(nums[i]);

            while (ans.size() > 1) {
                int a = ans[ans.size() - 1], b = ans[ans.size() - 2], divisor = gcd(a, b);

                if (divisor == 1) {
                    break;
                }
                else {
                    ans.pop_back();
                    ans.back() *= (a / divisor);
                }
            }
        }

        return ans;
    }

    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 6,4,3,2,7,6,2 };
    vector<int> actual = o.replaceNonCoprimes(nums);
    vector<int> expected = { 12,7,6 };
    check.checkIntVector(expected, actual);

    nums = { 2,2,1,1,3,3,3 };
    actual = o.replaceNonCoprimes(nums);
    expected = { 2,1,1,3 };
    check.checkIntVector(expected, actual);

    nums = { 287,41,49,287,899,23,23,20677,5,825 };
    actual = o.replaceNonCoprimes(nums);
    expected = { 2009,20677,825 };
    check.checkIntVector(expected, actual);

    nums = { 3,7,3 };
    actual = o.replaceNonCoprimes(nums);
    expected = { 3,7,3 };
    check.checkIntVector(expected, actual);

    nums = { 2 };
    actual = o.replaceNonCoprimes(nums);
    expected = { 2 };
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
