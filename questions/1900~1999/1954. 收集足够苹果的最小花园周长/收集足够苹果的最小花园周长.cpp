/* 收集足够苹果的最小花园周长.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个用无限二维网格表示的花园，每一个 整数坐标处都有一棵苹果树。整数坐标 (i, j) 处的苹果树有 |i| + |j| 个苹果。

你将会买下正中心坐标是 (0, 0) 的一块 正方形土地 ，且每条边都与两条坐标轴之一平行。

给你一个整数 neededApples ，请你返回土地的 最小周长 ，使得 至少 有 neededApples 个苹果在土地 里面或者边缘上。

|x| 的值定义为：

如果 x >= 0 ，那么值为 x
如果 x < 0 ，那么值为 -x
 

示例 1：


输入：neededApples = 1
输出：8
解释：边长长度为 1 的正方形不包含任何苹果。
但是边长为 2 的正方形包含 12 个苹果（如上图所示）。
周长为 2 * 4 = 8 。
示例 2：

输入：neededApples = 13
输出：16
示例 3：

输入：neededApples = 1000000000
输出：5040
 

提示：

1 <= neededApples <= 1015

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-garden-perimeter-to-collect-enough-apples
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        /* 1、半边长为n的正方形，上面的苹果数为4((2n+n)*(n+1)-n)-4*2n=12n*n
           2、总的苹果数为12*(1*1+2*2+...+n*n)=12*n*(n+1)*(2n+1)/6=2n*(n+1)*(2n+1) */
        long long low = 1, high = (long long)cbrt(neededApples / 2) + 1, n = 1;

        while (low <= high) {
            long long middle = (low + high) / 2;

            if (2 * middle * (middle + 1) * (2 * middle + 1) >= neededApples) {
                n = middle;
                high = middle - 1;
            }
            else {
                low = middle + 1;
            }
        }

        return 8 * n;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkLongLong(8, o.minimumPerimeter(1));
    check.checkLongLong(16, o.minimumPerimeter(13));
    check.checkLongLong(5040, o.minimumPerimeter(1000000000));
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
