/* 最小化两个数组中的最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个数组 arr1 和 arr2 ，它们一开始都是空的。你需要往它们中添加正整数，使它们满足以下条件：

arr1 包含 uniqueCnt1 个 互不相同 的正整数，每个整数都 不能 被 divisor1 整除 。
arr2 包含 uniqueCnt2 个 互不相同 的正整数，每个整数都 不能 被 divisor2 整除 。
arr1 和 arr2 中的元素 互不相同 。
给你 divisor1 ，divisor2 ，uniqueCnt1 和 uniqueCnt2 ，请你返回两个数组中 最大元素 的 最小值 。



示例 1：

输入：divisor1 = 2, divisor2 = 7, uniqueCnt1 = 1, uniqueCnt2 = 3
输出：4
解释：
我们可以把前 4 个自然数划分到 arr1 和 arr2 中。
arr1 = [1] 和 arr2 = [2,3,4] 。
可以看出两个数组都满足条件。
最大值是 4 ，所以返回 4 。
示例 2：

输入：divisor1 = 3, divisor2 = 5, uniqueCnt1 = 2, uniqueCnt2 = 1
输出：3
解释：
arr1 = [1,2] 和 arr2 = [3] 满足所有条件。
最大值是 3 ，所以返回 3 。
示例 3：

输入：divisor1 = 2, divisor2 = 4, uniqueCnt1 = 8, uniqueCnt2 = 2
输出：15
解释：
最终数组为 arr1 = [1,3,5,7,9,11,13,15] 和 arr2 = [2,6] 。
上述方案是满足所有条件的最优解。


提示：

2 <= divisor1, divisor2 <= 105
1 <= uniqueCnt1, uniqueCnt2 < 109
2 <= uniqueCnt1 + uniqueCnt2 <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

typedef long long LL;

class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        LL low = 0, high = INT_MAX, ans = 0;

        while (low <= high) {
            LL mid = (low + high) / 2;
            if (check(divisor1, divisor2, uniqueCnt1, uniqueCnt2, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }

    bool check(LL divisor1, LL divisor2, LL uniqueCnt1, LL uniqueCnt2, LL maxNum) {
        LL d1Multi = maxNum / divisor1, d2Multi = maxNum / divisor2, d1d2Multi = maxNum / lcm(divisor1, divisor2);
        LL d1MultiOnly = d1Multi - d1d2Multi, d2MultiOnly = d2Multi - d1d2Multi;
        LL common = maxNum - d1Multi - d2Multi + d1d2Multi;
        LL cnt1 = uniqueCnt1 < d2MultiOnly ? 0 : uniqueCnt1 - d2MultiOnly;
        LL cnt2 = uniqueCnt2 < d1MultiOnly ? 0 : uniqueCnt2 - d1MultiOnly;

        return cnt1 + cnt2 <= common;
    }

    LL gcd(LL x, LL y) {
        return y == 0 ? x : gcd(y, x % y);
    }

    LL lcm(LL x, LL y) {
        return x * y / gcd(x, y);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.minimizeSet(2, 7, 1, 3));
    check.checkInt(3, o.minimizeSet(3, 5, 2, 1));
    check.checkInt(15, o.minimizeSet(2, 4, 8, 2));
    check.checkInt(217679202, o.minimizeSet(92761, 48337, 208563424, 9115778));
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
