/* 范围中美丽整数的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你正整数 low ，high 和 k 。

如果一个数满足以下两个条件，那么它是 美丽的 ：

偶数数位的数目与奇数数位的数目相同。
这个整数可以被 k 整除。
请你返回范围 [low, high] 中美丽整数的数目。



示例 1：

输入：low = 10, high = 20, k = 3
输出：2
解释：给定范围中有 2 个美丽数字：[12,18]
- 12 是美丽整数，因为它有 1 个奇数数位和 1 个偶数数位，而且可以被 k = 3 整除。
- 18 是美丽整数，因为它有 1 个奇数数位和 1 个偶数数位，而且可以被 k = 3 整除。
以下是一些不是美丽整数的例子：
- 16 不是美丽整数，因为它不能被 k = 3 整除。
- 15 不是美丽整数，因为它的奇数数位和偶数数位的数目不相等。
给定范围内总共有 2 个美丽整数。
示例 2：

输入：low = 1, high = 10, k = 1
输出：1
解释：给定范围中有 1 个美丽数字：[10]
- 10 是美丽整数，因为它有 1 个奇数数位和 1 个偶数数位，而且可以被 k = 1 整除。
给定范围内总共有 1 个美丽整数。
示例 3：

输入：low = 5, high = 5, k = 2
输出：0
解释：给定范围中有 0 个美丽数字。
- 5 不是美丽整数，因为它的奇数数位和偶数数位的数目不相等。


提示：

0 < low <= high <= 109
0 < k <= 20
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        init(low - 1, k);
        int beautiLow = DFS(0, 0, 0, true, true);
        init(high, k);
        int beautiHigh = DFS(0, 0, 0, true, true);

        return beautiHigh - beautiLow;
    }

    void init(int num, int k) {
        limit = to_string(num);
        size = limit.size();
        mod = k;
        memo.clear();
        memo.resize((2 * size + 1) * size * k * 2 * 2, -1);
    }

    int DFS(int diff, int index, int value, bool isLeadZero, bool isLimit) {  // 一共size位，当前在index位，前面奇偶差是diff，前面余数是value，前面是否是前导0，前面是否在上限
        if (index == size) {
            return diff == 0 && value == 0 && !isLeadZero ? 1 : 0;  // 全0不是美丽数
        }

        int state = (diff + size) * size * mod * 2 * 2 + index * mod * 2 * 2 + value * 2 * 2 + (isLeadZero ? 1 : 0) * 2 + (isLimit ? 1 : 0);
        if (memo[state] != -1) {
            return memo[state];
        }

        int& ans = memo[state];
        ans = 0;

        if (size - index < abs(diff)) {  // 奇偶差已不够调整到相等
            return ans;
        }

        int upper = isLimit ? limit[index] - '0' : 9;

        for (int d = 0; d <= upper; ++d) {
            ans += DFS((isLeadZero && (d == 0)) ? 0 : diff + ((d & 1) == 0 ? 1 : -1), index + 1, (value * 10 + d) % mod, isLeadZero && (d == 0), isLimit && (d == upper));
        }

        return ans;
    }

private:
    int mod;
    int size;
    string limit;
    vector<int> memo;
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.numberOfBeautifulIntegers(10, 20, 3));
    check.checkInt(1, o.numberOfBeautifulIntegers(1, 10, 1));
    check.checkInt(0, o.numberOfBeautifulIntegers(5, 5, 2));
    check.checkInt(1310207, o.numberOfBeautifulIntegers(1, 1000000000, 19));
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
