/* 可被 K 整除的最小整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定正整数 K，你需要找出可以被 K 整除的、仅包含数字 1 的最小正整数 N。

返回 N 的长度。如果不存在这样的 N，就返回 -1。

 

示例 1：

输入：1
输出：1
解释：最小的答案是 N = 1，其长度为 1。
示例 2：

输入：2
输出：-1
解释：不存在可被 2 整除的正整数 N 。
示例 3：

输入：3
输出：3
解释：最小的答案是 N = 111，其长度为 3。
 

提示：

1 <= K <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-integer-divisible-by-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        /* 1、N产生的过程：n=1, 10n+1不断循环得到N
           2、假设N[i]=pK+r，则N[i+1]%K=(10N[i]+1)%K=(10(pK+r)+1)%K=(10pK+10r+1)%K=(10r+1)%K
           结论：N[i+1]%K的结果只和N[i]%K的余数r有关。想象一下手工计算11111....../K，其实就是取前面有限的几个1先对K取余，然后加上剩余的1再对K取余的过程 */
        if (K % 2 == 0 || K % 5 == 0) {
            return -1;  // K的末尾是0、2、4、5、6、8不可能整除
        }

        if (K == 1) {
            return 1;
        }

        unordered_set<int> remainders;
        int n = 1, len = 1;

        while (n != 0) {
            n = (n * 10 + 1) % K;
            ++len;
            
            if (remainders.count(n) == 0) {
                remainders.insert(n);  // 可以证明K的其它情况一定有解，不过比较麻烦，set记录一下出现过的余数
            }
            else {
                return -1;  // 出现循环则不可能整除
            }
        }

        return len;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.smallestRepunitDivByK(1));
    check.checkInt(-1, o.smallestRepunitDivByK(2));
    check.checkInt(-1, o.smallestRepunitDivByK(4));
    check.checkInt(-1, o.smallestRepunitDivByK(5));
    check.checkInt(-1, o.smallestRepunitDivByK(6));
    check.checkInt(-1, o.smallestRepunitDivByK(8));
    check.checkInt(-1, o.smallestRepunitDivByK(10));
    check.checkInt(3, o.smallestRepunitDivByK(3));
    check.checkInt(19926, o.smallestRepunitDivByK(19927));
    check.checkInt(45, o.smallestRepunitDivByK(99999));
    check.checkInt(99, o.smallestRepunitDivByK(79797));
    check.checkInt(4656, o.smallestRepunitDivByK(97797));
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
