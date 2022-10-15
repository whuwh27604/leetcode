/* 找出前缀异或的原始数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的 整数 数组 pref 。找出并返回满足下述条件且长度为 n 的数组 arr ：

pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].
注意 ^ 表示 按位异或（bitwise-xor）运算。

可以证明答案是 唯一 的。

 

示例 1：

输入：pref = [5,2,0,3,1]
输出：[5,7,2,3,2]
解释：从数组 [5,7,2,3,2] 可以得到如下结果：
- pref[0] = 5
- pref[1] = 5 ^ 7 = 2
- pref[2] = 5 ^ 7 ^ 2 = 0
- pref[3] = 5 ^ 7 ^ 2 ^ 3 = 3
- pref[4] = 5 ^ 7 ^ 2 ^ 3 ^ 2 = 1
示例 2：

输入：pref = [13]
输出：[13]
解释：pref[0] = arr[0] = 13
 

提示：

1 <= pref.length <= 105
0 <= pref[i] <= 106

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-the-original-array-of-prefix-xor
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int size = pref.size();
        vector<int> arr(size);
        arr[0] = pref[0];

        for (int i = 1; i < size; ++i) {
            arr[i] = pref[i] ^ pref[i - 1];
        }

        return arr;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> pref = { 5,2,0,3,1 };
    vector<int> actual = o.findArray(pref);
    vector<int> expected = { 5,7,2,3,2 };
    check.checkIntVector(expected, actual);

    pref = { 13 };
    actual = o.findArray(pref);
    expected = { 13 };
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
