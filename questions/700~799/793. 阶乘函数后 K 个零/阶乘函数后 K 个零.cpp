/* 阶乘函数后 K 个零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
f(x) 是 x! 末尾是 0 的数量。回想一下 x! = 1 * 2 * 3 * ... * x，且 0! = 1 。

例如， f(3) = 0 ，因为 3! = 6 的末尾没有 0 ；而 f(11) = 2 ，因为 11!= 39916800 末端有 2 个 0 。
给定 k，找出返回能满足 f(x) = k 的非负整数 x 的数量。

 

示例 1：

输入：k = 0
输出：5
解释：0!, 1!, 2!, 3!, 和 4! 均符合 k = 0 的条件。
示例 2：

输入：k = 5
输出：0
解释：没有匹配到这样的 x!，符合 k = 5 的条件。
示例 3:

输入: k = 3
输出: 5
 

提示:

0 <= k <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/preimage-size-of-factorial-zeroes-function
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int preimageSizeFZF(int k) {
        long long low = 0, high = LLONG_MAX;

        while (low <= high) {
            long long mid = (high - low) / 2 + low;
            long long zeros = suffixZeros(mid);

            if (zeros == k) {
                return 5;
            }
            else if (zeros < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return 0;
    }

    long long suffixZeros(long long n) {
        long long zeros = 0;

        while (n != 0) {
            zeros += (n / 5);
            n /= 5;
        }

        return zeros;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(5, o.preimageSizeFZF(0));
    check.checkInt(0, o.preimageSizeFZF(5));
    check.checkInt(5, o.preimageSizeFZF(3));
    check.checkInt(5, o.preimageSizeFZF(38995104));
    check.checkInt(5, o.preimageSizeFZF(47560959));
    check.checkInt(5, o.preimageSizeFZF(1000000000));
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
