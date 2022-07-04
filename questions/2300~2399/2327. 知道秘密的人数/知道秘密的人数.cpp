/* 知道秘密的人数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在第 1 天，有一个人发现了一个秘密。

给你一个整数 delay ，表示每个人会在发现秘密后的 delay 天之后，每天 给一个新的人 分享 秘密。同时给你一个整数 forget ，表示每个人在发现秘密 forget 天之后会 忘记 这个秘密。一个人 不能 在忘记秘密那一天及之后的日子里分享秘密。

给你一个整数 n ，请你返回在第 n 天结束时，知道秘密的人数。由于答案可能会很大，请你将结果对 109 + 7 取余 后返回。

 

示例 1：

输入：n = 6, delay = 2, forget = 4
输出：5
解释：
第 1 天：假设第一个人叫 A 。（一个人知道秘密）
第 2 天：A 是唯一一个知道秘密的人。（一个人知道秘密）
第 3 天：A 把秘密分享给 B 。（两个人知道秘密）
第 4 天：A 把秘密分享给一个新的人 C 。（三个人知道秘密）
第 5 天：A 忘记了秘密，B 把秘密分享给一个新的人 D 。（三个人知道秘密）
第 6 天：B 把秘密分享给 E，C 把秘密分享给 F 。（五个人知道秘密）
示例 2：

输入：n = 4, delay = 1, forget = 3
输出：6
解释：
第 1 天：第一个知道秘密的人为 A 。（一个人知道秘密）
第 2 天：A 把秘密分享给 B 。（两个人知道秘密）
第 3 天：A 和 B 把秘密分享给 2 个新的人 C 和 D 。（四个人知道秘密）
第 4 天：A 忘记了秘密，B、C、D 分别分享给 3 个新的人。（六个人知道秘密）
 

提示：

2 <= n <= 1000
1 <= delay < forget <= n

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-people-aware-of-a-secret
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int left = delay, right = forget, sum = 0, mod = 1000000007;
        vector<int> dp(n + forget, 0);  // dp[i]表示第i天新增的人数，那么区间(i - forget, i - delay]的人都可以使第i天新增一人。将第一天平移到dp[forget]位置
        dp[forget] = 1;

        for (int day = forget + delay; day < n + forget; ++day) {
            sum = ((sum + dp[right++]) % mod + mod - dp[left++]) % mod;  // 求区间(i - forget, i - delay]的和，该区间每天往右平移一格，双指针简化到O(1)复杂度
            dp[day] = sum;
        }

        sum = 0;

        for (int day = n; day < n + forget; ++day) {  // 统计区间[n, n + forget)的人数，这些人在第n + forget - 1天（即原始的第n天）都知道秘密
            sum = (sum + dp[day]) % mod;
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(5, o.peopleAwareOfSecret(6, 2, 4));
    check.checkInt(6, o.peopleAwareOfSecret(4, 1, 3));
    check.checkInt(26, o.peopleAwareOfSecret(7, 1, 3));
    check.checkInt(42, o.peopleAwareOfSecret(8, 1, 3));
    check.checkInt(609178299, o.peopleAwareOfSecret(1000, 5, 100));
    check.checkInt(473146952, o.peopleAwareOfSecret(1000, 3, 100));
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
