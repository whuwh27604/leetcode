/* 根据规则将箱子分类.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你四个整数 length ，width ，height 和 mass ，分别表示一个箱子的三个维度和质量，请你返回一个表示箱子 类别 的字符串。

如果满足以下条件，那么箱子是 "Bulky" 的：
箱子 至少有一个 维度大于等于 104 。
或者箱子的 体积 大于等于 109 。
如果箱子的质量大于等于 100 ，那么箱子是 "Heavy" 的。
如果箱子同时是 "Bulky" 和 "Heavy" ，那么返回类别为 "Both" 。
如果箱子既不是 "Bulky" ，也不是 "Heavy" ，那么返回类别为 "Neither" 。
如果箱子是 "Bulky" 但不是 "Heavy" ，那么返回类别为 "Bulky" 。
如果箱子是 "Heavy" 但不是 "Bulky" ，那么返回类别为 "Heavy" 。
注意，箱子的体积等于箱子的长度、宽度和高度的乘积。



示例 1：

输入：length = 1000, width = 35, height = 700, mass = 300
输出："Heavy"
解释：
箱子没有任何维度大于等于 104 。
体积为 24500000 <= 109 。所以不能归类为 "Bulky" 。
但是质量 >= 100 ，所以箱子是 "Heavy" 的。
由于箱子不是 "Bulky" 但是是 "Heavy" ，所以我们返回 "Heavy" 。
示例 2：

输入：length = 200, width = 50, height = 800, mass = 50
输出："Neither"
解释：
箱子没有任何维度大于等于 104 。
体积为 8 * 106 <= 109 。所以不能归类为 "Bulky" 。
质量小于 100 ，所以不能归类为 "Heavy" 。
由于不属于上述两者任何一类，所以我们返回 "Neither" 。


提示：

1 <= length, width, height <= 105
1 <= mass <= 103
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = length >= 10000 || width >= 10000 || height >= 10000
            || ((long long)length * width * height >= 1000000000);
        bool heavy = mass >= 100;

        if (bulky && heavy) {
            return "Both";
        }

        if (!bulky && !heavy) {
            return "Neither";
        }

        return bulky ? "Bulky" : "Heavy";
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("Heavy", o.categorizeBox(1000, 35, 700, 300));
    check.checkString("Neither", o.categorizeBox(200, 50, 800, 50));
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
