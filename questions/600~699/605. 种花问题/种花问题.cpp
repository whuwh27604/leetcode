/* 种花问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。

示例 1:

输入: flowerbed = [1,0,0,0,1], n = 1
输出: True
示例 2:

输入: flowerbed = [1,0,0,0,1], n = 2
输出: False
注意:

数组内已种好的花不会违反种植规则。
输入的数组长度范围为 [1, 20000]。
n 是非负整数，且不会超过输入数组的大小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/can-place-flowers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        int placeFlowers = 0;

        for (unsigned int i = 1; i < (flowerbed.size() - 1); i++) {
            if (flowerbed[i] == 1) {
                i++;
                continue;
            }

            if ((flowerbed[i - 1] == 0) && (flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                i++;
                placeFlowers++;
                if (placeFlowers >= n) {
                    break;
                }
            }
        }

        return (placeFlowers >= n);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> flowerbed = { 1,0,0,0,1 };
    check.checkBool(true, o.canPlaceFlowers(flowerbed, 1));
    check.checkBool(false, o.canPlaceFlowers(flowerbed, 2));

    flowerbed = { 1 };
    check.checkBool(true, o.canPlaceFlowers(flowerbed, 0));

    flowerbed = { 0 };
    check.checkBool(true, o.canPlaceFlowers(flowerbed, 1));

    flowerbed = { 1 };
    check.checkBool(false, o.canPlaceFlowers(flowerbed, 1));

    flowerbed = { 1,0 };
    check.checkBool(false, o.canPlaceFlowers(flowerbed, 1));

    flowerbed = { 0,0 };
    check.checkBool(true, o.canPlaceFlowers(flowerbed, 1));

    flowerbed = { 0,0 };
    check.checkBool(false, o.canPlaceFlowers(flowerbed, 2));

    flowerbed = { 0,0,0 };
    check.checkBool(true, o.canPlaceFlowers(flowerbed, 2));

    flowerbed = { 0,0,1 };
    check.checkBool(true, o.canPlaceFlowers(flowerbed, 1));

    flowerbed = { 1,0,0 };
    check.checkBool(true, o.canPlaceFlowers(flowerbed, 1));

    flowerbed = { 0,0,0,0,0 };
    check.checkBool(true, o.canPlaceFlowers(flowerbed, 3));

    flowerbed = { 0,0,0,0,0 };
    check.checkBool(false, o.canPlaceFlowers(flowerbed, 4));

    flowerbed = { 1,0,0,0,0,0,1 };
    check.checkBool(true, o.canPlaceFlowers(flowerbed, 2));

    flowerbed = { 1,0,0,0,0,0,1 };
    check.checkBool(false, o.canPlaceFlowers(flowerbed, 3));

    flowerbed = { 0,0,0,0,0,1,0,0 };
    check.checkBool(true, o.canPlaceFlowers(flowerbed, 0));
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
