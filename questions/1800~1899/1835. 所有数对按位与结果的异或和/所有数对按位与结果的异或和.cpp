/* 所有数对按位与结果的异或和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
列表的 异或和（XOR sum）指对所有元素进行按位 XOR 运算的结果。如果列表中仅有一个元素，那么其 异或和 就等于该元素。

例如，[1,2,3,4] 的 异或和 等于 1 XOR 2 XOR 3 XOR 4 = 4 ，而 [3] 的 异或和 等于 3 。
给你两个下标 从 0 开始 计数的数组 arr1 和 arr2 ，两数组均由非负整数组成。

根据每个 (i, j) 数对，构造一个由 arr1[i] AND arr2[j]（按位 AND 运算）结果组成的列表。其中 0 <= i < arr1.length 且 0 <= j < arr2.length 。

返回上述列表的 异或和 。

 

示例 1：

输入：arr1 = [1,2,3], arr2 = [6,5]
输出：0
解释：列表 = [1 AND 6, 1 AND 5, 2 AND 6, 2 AND 5, 3 AND 6, 3 AND 5] = [0,1,2,0,2,1] ，
异或和 = 0 XOR 1 XOR 2 XOR 0 XOR 2 XOR 1 = 0 。
示例 2：

输入：arr1 = [12], arr2 = [4]
输出：4
解释：列表 = [12 AND 4] = [4] ，异或和 = 4 。
 

提示：

1 <= arr1.length, arr2.length <= 105
0 <= arr1[i], arr2[j] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-xor-sum-of-all-pairs-bitwise-and
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        /* 重要结论：(A & C) ^ (B & C) = (A ^ B) & C
           (A0 & B0) ^ (A0 & B1) ^ ... ^ (A0 & Bn)
           ^ (A1 & B0) ^ (A1 & B1) ^ ... ^ (A1 & Bn)
           ^ ...
           ^ (An & B0) ^ (An & B1) ^ ... ^ (An & Bn)
           = A0 & (B0 ^ B1 ^ ... ^ Bn)
           ^ A1 & (B0 ^ B1 ^ ... ^ Bn)
           ^ ...
           ^ An & (B0 ^ B1 ^ ... ^ Bn)
           =(A0 ^ A1 ^ ... ^ An) & (B0 ^ B1 ^ ... ^ Bn) */
        int a = 0, b = 0;

        for (int num : arr1) {
            a ^= num;
        }

        for (int num : arr2) {
            b ^= num;
        }

        return a & b;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr1 = { 1,2,3 };
    vector<int> arr2 = { 6,5 };
    check.checkInt(0, o.getXORSum(arr1, arr2));

    arr1 = { 12 };
    arr2 = { 4 };
    check.checkInt(4, o.getXORSum(arr1, arr2));
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
