/* 循环码排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数 n 和 start。你的任务是返回任意 (0,1,2,,...,2^n-1) 的排列 p，并且满足：

p[0] = start
p[i] 和 p[i+1] 的二进制表示形式只有一位不同
p[0] 和 p[2^n -1] 的二进制表示形式也只有一位不同
 

示例 1：

输入：n = 2, start = 3
输出：[3,2,0,1]
解释：这个排列的二进制表示是 (11,10,00,01)
     所有的相邻元素都有一位是不同的，另一个有效的排列是 [3,1,0,2]
示例 2：

输出：n = 3, start = 2
输出：[2,6,7,5,4,0,1,3]
解释：这个排列的二进制表示是 (010,110,111,101,100,000,001,011)
 

提示：

1 <= n <= 16
0 <= start < 2^n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/circular-permutation-in-binary-representation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int i, size = 1 << n;
        vector<int> ans(size);

        for (i = 0; i < size; ++i) {
            ans[i] = i ^ (i >> 1) ^ start;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.circularPermutation(2, 3);
    vector<int> expected = { 3,2,0,1 };
    check.checkIntVector(expected, actual);

    actual = o.circularPermutation(3, 2);
    expected = { 2,3,1,0,4,5,7,6 };
    check.checkIntVector(expected, actual);

    actual = o.circularPermutation(1, 0);
    expected = { 0,1 };
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
