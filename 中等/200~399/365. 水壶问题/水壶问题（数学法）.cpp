/* 水壶问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？

如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。

你允许：

装满任意一个水壶
清空任意一个水壶
从一个水壶向另外一个水壶倒水，直到装满或者倒空
示例 1: (From the famous "Die Hard" example)

输入: x = 3, y = 5, z = 4
输出: True
示例 2:

输入: x = 2, y = 6, z = 5
输出: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/water-and-jug-problem
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if ((x + y) < z) {
            return false;
        }

        if ((x == 0) || (y == 0)) {
            return (z == 0) || ((x + y) == z);
        }

        return (z % gcd(x, y)) == 0;
    }

    int gcd(int x, int y) {
        return (y == 0) ? x : gcd(y, x % y);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.canMeasureWater(3, 5, 4));
    check.checkBool(false, o.canMeasureWater(2, 6, 5));
    check.checkBool(true, o.canMeasureWater(0, 0, 0));
    check.checkBool(false, o.canMeasureWater(0, 0, 1));
    check.checkBool(true, o.canMeasureWater(0, 1, 1));
    check.checkBool(false, o.canMeasureWater(0, 1, 3));
    check.checkBool(true, o.canMeasureWater(1, 0, 1));
    check.checkBool(false, o.canMeasureWater(1, 0, 3));
    check.checkBool(true, o.canMeasureWater(100, 200, 300));
    check.checkBool(false, o.canMeasureWater(100, 200, 299));
    check.checkBool(true, o.canMeasureWater(100000, 80000, 180000));
    check.checkBool(true, o.canMeasureWater(100000, 80000, 160000));
    check.checkBool(false, o.canMeasureWater(100000, 80000, 170000));
    check.checkBool(false, o.canMeasureWater(100000, 80000, 200000));
    check.checkBool(true, o.canMeasureWater(104707, 104711, 1));
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
