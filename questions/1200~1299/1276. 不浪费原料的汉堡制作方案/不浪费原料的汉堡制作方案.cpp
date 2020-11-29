/* 不浪费原料的汉堡制作方案.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
圣诞活动预热开始啦，汉堡店推出了全新的汉堡套餐。为了避免浪费原料，请你帮他们制定合适的制作计划。

给你两个整数 tomatoSlices 和 cheeseSlices，分别表示番茄片和奶酪片的数目。不同汉堡的原料搭配如下：

巨无霸汉堡：4 片番茄和 1 片奶酪
小皇堡：2 片番茄和 1 片奶酪
请你以 [total_jumbo, total_small]（[巨无霸汉堡总数，小皇堡总数]）的格式返回恰当的制作方案，使得剩下的番茄片 tomatoSlices 和奶酪片 cheeseSlices 的数量都是 0。

如果无法使剩下的番茄片 tomatoSlices 和奶酪片 cheeseSlices 的数量为 0，就请返回 []。

 

示例 1：

输入：tomatoSlices = 16, cheeseSlices = 7
输出：[1,6]
解释：制作 1 个巨无霸汉堡和 6 个小皇堡需要 4*1 + 2*6 = 16 片番茄和 1 + 6 = 7 片奶酪。不会剩下原料。
示例 2：

输入：tomatoSlices = 17, cheeseSlices = 4
输出：[]
解释：只制作小皇堡和巨无霸汉堡无法用光全部原料。
示例 3：

输入：tomatoSlices = 4, cheeseSlices = 17
输出：[]
解释：制作 1 个巨无霸汉堡会剩下 16 片奶酪，制作 2 个小皇堡会剩下 15 片奶酪。
示例 4：

输入：tomatoSlices = 0, cheeseSlices = 0
输出：[0,0]
示例 5：

输入：tomatoSlices = 2, cheeseSlices = 1
输出：[0,1]
 

提示：

0 <= tomatoSlices <= 10^7
0 <= cheeseSlices <= 10^7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-burgers-with-no-waste-of-ingredients
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        // 4x+2y=tomatoSlices, x+y=cheeseSlices, x=(tomatoSlices-2*cheeseSlices)/2, y=(4*cheeseSlices-tomatoSlices)/2
        int x = tomatoSlices - 2 * cheeseSlices, y = 4 * cheeseSlices - tomatoSlices;

        if (x >= 0 && x % 2 == 0 && y >= 0 && y % 2 == 0) {
            return { x / 2, y / 2 };
        }

        return {};
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.numOfBurgers(16, 7);
    vector<int> expected = { 1,6 };
    check.checkIntVector(expected, actual);

    actual = o.numOfBurgers(17, 4);
    expected = {  };
    check.checkIntVector(expected, actual);

    actual = o.numOfBurgers(4, 17);
    expected = {  };
    check.checkIntVector(expected, actual);

    actual = o.numOfBurgers(0, 0);
    expected = { 0,0 };
    check.checkIntVector(expected, actual);

    actual = o.numOfBurgers(2, 1);
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
