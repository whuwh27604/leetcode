/* 第k个排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
示例 1:

输入: n = 3, k = 3
输出: "213"
示例 2:

输入: n = 4, k = 9
输出: "2314"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int factorials[8] = { 1,2,6,24,120,720,5040,40320 };
        vector<int> nums;
        string permutation;

        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        for (int i = 1; i < n; i++) {
            int index = (k - 1) / factorials[n - 1 - i];
            permutation += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k -= (index * factorials[n - 1 - i]);
        }

        permutation += to_string(nums[0]);

        return permutation;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("1", o.getPermutation(1, 1));
    check.checkString("12", o.getPermutation(2, 1));
    check.checkString("21", o.getPermutation(2, 2));
    check.checkString("123", o.getPermutation(3, 1));
    check.checkString("132", o.getPermutation(3, 2));
    check.checkString("213", o.getPermutation(3, 3));
    check.checkString("231", o.getPermutation(3, 4));
    check.checkString("312", o.getPermutation(3, 5));
    check.checkString("321", o.getPermutation(3, 6));
    check.checkString("2314", o.getPermutation(4, 9));
    check.checkString("987654321", o.getPermutation(9, 362880));
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
