/* 增长的内存泄露.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数 memory1 和 memory2 分别表示两个内存条剩余可用内存的位数。现在有一个程序每秒递增的速度消耗着内存。

在第 i 秒（秒数从 1 开始），有 i 位内存被分配到 剩余内存较多 的内存条（如果两者一样多，则分配到第一个内存条）。如果两者剩余内存都不足 i 位，那么程序将 意外退出 。

请你返回一个数组，包含 [crashTime, memory1crash, memory2crash] ，其中 crashTime是程序意外退出的时间（单位为秒）， memory1crash 和 memory2crash 分别是两个内存条最后剩余内存的位数。

 

示例 1：

输入：memory1 = 2, memory2 = 2
输出：[3,1,0]
解释：内存分配如下：
- 第 1 秒，内存条 1 被占用 1 位内存。内存条 1 现在有 1 位剩余可用内存。
- 第 2 秒，内存条 2 被占用 2 位内存。内存条 2 现在有 0 位剩余可用内存。
- 第 3 秒，程序意外退出，两个内存条分别有 1 位和 0 位剩余可用内存。
示例 2：

输入：memory1 = 8, memory2 = 11
输出：[6,0,4]
解释：内存分配如下：
- 第 1 秒，内存条 2 被占用 1 位内存，内存条 2 现在有 10 位剩余可用内存。
- 第 2 秒，内存条 2 被占用 2 位内存，内存条 2 现在有 8 位剩余可用内存。
- 第 3 秒，内存条 1 被占用 3 位内存，内存条 1 现在有 5 位剩余可用内存。
- 第 4 秒，内存条 2 被占用 4 位内存，内存条 2 现在有 4 位剩余可用内存。
- 第 5 秒，内存条 1 被占用 5 位内存，内存条 1 现在有 0 位剩余可用内存。
- 第 6 秒，程序意外退出，两个内存条分别有 0 位和 4 位剩余可用内存。
 

提示：

0 <= memory1, memory2 <= 231 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/incremental-memory-leak
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int leak = 1;

        while (memory1 >= leak || memory2 >= leak) {
            if (memory1 >= memory2) {
                memory1 -= leak;
            }
            else {
                memory2 -= leak;
            }

            ++leak;
        }

        return { leak,memory1,memory2 };
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.memLeak(2, 2);
    vector<int> expected = { 3,1,0 };
    check.checkIntVector(expected, actual);

    actual = o.memLeak(8, 11);
    expected = { 6,0,4 };
    check.checkIntVector(expected, actual);

    actual = o.memLeak(0, 0);
    expected = { 1,0,0 };
    check.checkIntVector(expected, actual);

    actual = o.memLeak(INT_MAX, INT_MAX);
    expected = { 92681,88047,41707 };
    check.checkIntVector(expected, actual);

    actual = o.memLeak(INT_MAX - 1, INT_MAX);
    expected = { 92681,41706,88047 };
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
