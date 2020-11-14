/* 比特位计数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

示例 1:

输入: 2
输出: [0,1,1]
示例 2:

输入: 5
输出: [0,1,1,2,1,2]
进阶:

给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
要求算法的空间复杂度为O(n)。
你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/counting-bits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> oneBits(num + 1, 0);

        for (int i = 1; i <= num; i++) {
            // i & (i - 1)把i的最后一个1清零，所以oneBits[i]和oneBits[i & (i - 1)]之间相差1个1
            oneBits[i] = oneBits[i & (i - 1)] + 1;
        }

        return oneBits;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.countBits(0);
    vector<int> expected = { 0 };
    check.checkIntVector(expected, actual);

    actual = o.countBits(1);
    expected = { 0,1 };
    check.checkIntVector(expected, actual);

    actual = o.countBits(16);
    expected = { 0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1 };
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
