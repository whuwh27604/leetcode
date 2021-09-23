/* 可互换矩形的组数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
用一个下标从 0 开始的二维整数数组 rectangles 来表示 n 个矩形，其中 rectangles[i] = [widthi, heighti] 表示第 i 个矩形的宽度和高度。

如果两个矩形 i 和 j（i < j）的宽高比相同，则认为这两个矩形 可互换 。更规范的说法是，两个矩形满足 widthi/heighti == widthj/heightj（使用实数除法而非整数除法），则认为这两个矩形 可互换 。

计算并返回 rectangles 中有多少对 可互换 矩形。

 

示例 1：

输入：rectangles = [[4,8],[3,6],[10,20],[15,30]]
输出：6
解释：下面按下标（从 0 开始）列出可互换矩形的配对情况：
- 矩形 0 和矩形 1 ：4/8 == 3/6
- 矩形 0 和矩形 2 ：4/8 == 10/20
- 矩形 0 和矩形 3 ：4/8 == 15/30
- 矩形 1 和矩形 2 ：3/6 == 10/20
- 矩形 1 和矩形 3 ：3/6 == 15/30
- 矩形 2 和矩形 3 ：10/20 == 15/30
示例 2：

输入：rectangles = [[4,5],[7,8]]
输出：0
解释：不存在成对的可互换矩形。
 

提示：

n == rectangles.length
1 <= n <= 105
rectangles[i].length == 2
1 <= widthi, heighti <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-pairs-of-interchangeable-rectangles
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<long long, long long> rectCounts;
        long long count = 0;

        for (auto& rectangle : rectangles) {
            int divisor = gcd(rectangle[0], rectangle[1]);
            ++rectCounts[(((long long)rectangle[0] / divisor) << 32) | (rectangle[1] / divisor)];
        }

        for (auto& p : rectCounts) {
            count += (p.second * (p.second - 1) / 2);
        }

        return count;
    }

    int gcd(int x, int y) {
        return (y == 0) ? x : gcd(y, x % y);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> rectangles = { {4,8},{3,6},{10,20},{15,30} };
    check.checkLongLong(6, o.interchangeableRectangles(rectangles));

    rectangles = { {4,5},{7,8} };
    check.checkLongLong(0, o.interchangeableRectangles(rectangles));

    rectangles = { {1,1} };
    check.checkLongLong(0, o.interchangeableRectangles(rectangles));
    
    rectangles = { {4,8},{3,6},{10,20},{15,30},{1,3},{2,6},{3,9},{4,12},{5,15},{6,18} };
    check.checkLongLong(21, o.interchangeableRectangles(rectangles));
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
