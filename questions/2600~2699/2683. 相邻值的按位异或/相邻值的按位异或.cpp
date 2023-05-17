/* 相邻值的按位异或.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
下标从 0 开始、长度为 n 的数组 derived 是由同样长度为 n 的原始 二进制数组 original 通过计算相邻值的 按位异或（⊕）派生而来。

特别地，对于范围 [0, n - 1] 内的每个下标 i ：

如果 i = n - 1 ，那么 derived[i] = original[i] ⊕ original[0]
否则 derived[i] = original[i] ⊕ original[i + 1]
给你一个数组 derived ，请判断是否存在一个能够派生得到 derived 的 有效原始二进制数组 original 。

如果存在满足要求的原始二进制数组，返回 true ；否则，返回 false 。

二进制数组是仅由 0 和 1 组成的数组。


示例 1：

输入：derived = [1,1,0]
输出：true
解释：能够派生得到 [1,1,0] 的有效原始二进制数组是 [0,1,0] ：
derived[0] = original[0] ⊕ original[1] = 0 ⊕ 1 = 1
derived[1] = original[1] ⊕ original[2] = 1 ⊕ 0 = 1
derived[2] = original[2] ⊕ original[0] = 0 ⊕ 0 = 0
示例 2：

输入：derived = [1,1]
输出：true
解释：能够派生得到 [1,1] 的有效原始二进制数组是 [0,1] ：
derived[0] = original[0] ⊕ original[1] = 1
derived[1] = original[1] ⊕ original[0] = 1
示例 3：

输入：derived = [1,0]
输出：false
解释：不存在能够派生得到 [1,0] 的有效原始二进制数组。


提示：

n == derived.length
1 <= n <= 105
derived 中的值不是 0 就是 1 。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int original = 0;

        for (int num : derived) {
            original ^= num;
        }

        return original == 0;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> derived = { 1,1,0 };
    check.checkBool(true, o.doesValidArrayExist(derived));

    derived = { 1,1 };
    check.checkBool(true, o.doesValidArrayExist(derived));

    derived = { 1,0 };
    check.checkBool(false, o.doesValidArrayExist(derived));

    derived = { 0 };
    check.checkBool(true, o.doesValidArrayExist(derived));

    derived = { 1 };
    check.checkBool(false, o.doesValidArrayExist(derived));
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
