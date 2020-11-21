/* 格雷编码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。

给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。即使有多个不同答案，你也只需要返回其中一种。

格雷编码序列必须以 0 开头。

 

示例 1:

输入: 2
输出: [0,1,3,2]
解释:
00 - 0
01 - 1
11 - 3
10 - 2

对于给定的 n，其格雷编码序列并不唯一。
例如，[0,2,3,1] 也是一个有效的格雷编码序列。

00 - 0
10 - 2
11 - 3
01 - 1
示例 2:

输入: 0
输出: [0]
解释: 我们定义格雷编码序列必须以 0 开头。
     给定编码总位数为 n 的格雷编码序列，其长度为 2n。当 n = 0 时，长度为 20 = 1。
     因此，当 n = 0 时，其格雷编码序列为 [0]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gray-code
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int i, size = (int)pow(2, n);
        vector<int> grayCodes(size);

        for (i = 0; i < size; ++i) {
            grayCodes[i] = (i ^ (i >> 1));
        }

        return grayCodes;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.grayCode(0);
    vector<int> expected = { 0 };
    check.checkIntVector(expected, actual);

    actual = o.grayCode(1);
    expected = { 0,1 };
    check.checkIntVector(expected, actual);

    actual = o.grayCode(2);
    expected = { 0,1,3,2 };
    check.checkIntVector(expected, actual);

    actual = o.grayCode(3);
    expected = { 0,1,3,2,6,7,5,4 };
    check.checkIntVector(expected, actual);

    actual = o.grayCode(4);
    expected = { 0,1,3,2,6,7,5,4,12,13,15,14,10,11,9,8 };
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
