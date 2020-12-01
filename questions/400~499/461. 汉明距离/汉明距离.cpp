/* 汉明距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

给出两个整数 x 和 y，计算它们之间的汉明距离。

注意：
0 ≤ x, y < 231.

示例:

输入: x = 1, y = 4

输出: 2

解释:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

上面的箭头指出了对应二进制位不同的位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/hamming-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int n = (x ^ y);
        while (n != 0) {
            count++;
            n &= (n - 1);  // n&(n-1)只把n中最后一个1变为0
        }
        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(2, o.hammingDistance(1, 4));
    check.checkInt(4, o.hammingDistance(0, 15));
    check.checkInt(31, o.hammingDistance(2147483647, 0));
    check.checkInt(0, o.hammingDistance(2147483647, 2147483647));
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
