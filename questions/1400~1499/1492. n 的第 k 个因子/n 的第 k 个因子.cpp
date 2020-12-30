/* n 的第 k 个因子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个正整数 n 和 k 。

如果正整数 i 满足 n % i == 0 ，那么我们就说正整数 i 是整数 n 的因子。

考虑整数 n 的所有因子，将它们 升序排列 。请你返回第 k 个因子。如果 n 的因子数少于 k ，请你返回 -1 。

 

示例 1：

输入：n = 12, k = 3
输出：3
解释：因子列表包括 [1, 2, 3, 4, 6, 12]，第 3 个因子是 3 。
示例 2：

输入：n = 7, k = 2
输出：7
解释：因子列表包括 [1, 7] ，第 2 个因子是 7 。
示例 3：

输入：n = 4, k = 4
输出：-1
解释：因子列表包括 [1, 2, 4] ，只有 3 个因子，所以我们应该返回 -1 。
示例 4：

输入：n = 1, k = 1
输出：1
解释：因子列表包括 [1] ，第 1 个因子为 1 。
示例 5：

输入：n = 1000, k = 3
输出：4
解释：因子列表包括 [1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 125, 200, 250, 500, 1000] 。
 

提示：

1 <= k <= n <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-kth-factor-of-n
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        int i, left = 0, right = n, root = (int)sqrt(n);
        vector<int> factors(n + 1);

        for (i = 1; i <= root; ++i) {
            if (n % i == 0) {
                factors[left++] = i;

                if (n / i != i) {
                    factors[right--] = n / i;
                }
            }
        }

        return k <= left ? factors[k - 1] : (k <= left + n - right ? factors[right + k - left] : -1);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.kthFactor(1, 1));
    check.checkInt(-1, o.kthFactor(1, 2));
    check.checkInt(1, o.kthFactor(2, 1));
    check.checkInt(2, o.kthFactor(2, 2));
    check.checkInt(-1, o.kthFactor(2, 3));
    check.checkInt(1, o.kthFactor(3, 1));
    check.checkInt(3, o.kthFactor(3, 2));
    check.checkInt(-1, o.kthFactor(3, 3));
    check.checkInt(1, o.kthFactor(4, 1));
    check.checkInt(2, o.kthFactor(4, 2));
    check.checkInt(4, o.kthFactor(4, 3));
    check.checkInt(-1, o.kthFactor(4, 4));
    check.checkInt(3, o.kthFactor(12, 3));
    check.checkInt(7, o.kthFactor(7, 2));
    check.checkInt(4, o.kthFactor(1000, 3));
    check.checkInt(-1, o.kthFactor(1000, 17));
    check.checkInt(1000, o.kthFactor(1000, 16));
    check.checkInt(25, o.kthFactor(1000, 8));
    check.checkInt(40, o.kthFactor(1000, 9));
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
