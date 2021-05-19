/* 超级丑数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
编写一段程序来查找第 n 个超级丑数。

超级丑数是指其所有质因数都是长度为 k 的质数列表 primes 中的正整数。

示例:

输入: n = 12, primes = [2,7,13,19]
输出: 32
解释: 给定长度为 4 的质数列表 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。
说明:

1 是任何给定 primes 的超级丑数。
 给定 primes 中的数字以升序排列。
0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000 。
第 n 个超级丑数确保在 32 位有符整数范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/super-ugly-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int i, j, k = primes.size();
        vector<int> uglyNums(n);
        uglyNums[0] = 1;
        vector<int> currents(k, 0);  // 记录每个prime当前在第几个倍数
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nums;

        for (i = 0; i < k; ++i) {
            nums.push({ primes[i],i });
        }

        for (j = 1; j < n; ++j) {
            uglyNums[j] = nums.top().first;
            int index = nums.top().second;
            nums.pop();

            ++currents[index];  // 被选中的这个数，它的下一个倍数参与排序
            long long next = (long long)primes[index] * uglyNums[currents[index]];
            if (next <= INT_MAX) {  // 题目限制了答案在int范围内
                nums.push({ (int)next, index });
            }

            if (uglyNums[j] == uglyNums[j - 1]) {
                j -= 1;  // 出现相同的数时，要回退计数。比如2的第7个倍数和7的第2个倍数会同时出现在队列
            }
        }

        return uglyNums[n - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> primes = { 2,7,13,19 };
    check.checkInt(1, o.nthSuperUglyNumber(1, primes));
    check.checkInt(2, o.nthSuperUglyNumber(2, primes));
    check.checkInt(4, o.nthSuperUglyNumber(3, primes));
    check.checkInt(7, o.nthSuperUglyNumber(4, primes));
    check.checkInt(8, o.nthSuperUglyNumber(5, primes));
    check.checkInt(32, o.nthSuperUglyNumber(12, primes));
    check.checkInt(85489664, o.nthSuperUglyNumber(1000, primes));
    
    primes = { 2,3,5,7 };
    check.checkInt(1, o.nthSuperUglyNumber(1, primes));
    check.checkInt(2, o.nthSuperUglyNumber(2, primes));
    check.checkInt(3, o.nthSuperUglyNumber(3, primes));
    check.checkInt(4, o.nthSuperUglyNumber(4, primes));
    check.checkInt(5, o.nthSuperUglyNumber(5, primes));
    check.checkInt(450, o.nthSuperUglyNumber(100, primes));
    check.checkInt(385875, o.nthSuperUglyNumber(1000, primes));
    check.checkInt(797343750, o.nthSuperUglyNumber(5000, primes));
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
