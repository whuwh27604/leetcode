/* 爱吃香蕉的珂珂.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
珂珂喜欢吃香蕉。这里有 N 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 H 小时后回来。

珂珂可以决定她吃香蕉的速度 K （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 K 根。如果这堆香蕉少于 K 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  

珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）。

 

示例 1：

输入: piles = [3,6,7,11], H = 8
输出: 4
示例 2：

输入: piles = [30,11,23,4,20], H = 5
输出: 30
示例 3：

输入: piles = [30,11,23,4,20], H = 6
输出: 23
 

提示：

1 <= piles.length <= 10^4
piles.length <= H <= 10^9
1 <= piles[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/koko-eating-bananas
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int low = 1, high = findMaxPile(piles);

        while (low < high) {
            int speed = (low + high) / 2;
            if (canEatUp(piles, H, speed)) {
                high = speed;
            }
            else {
                low = speed + 1;
            }
        }

        return low;
    }

    int findMaxPile(vector<int>& piles) {
        int maxPile = 0;

        for (int pile : piles) {
            maxPile = maxPile > pile ? maxPile : pile;
        }

        return maxPile;
    }

    bool canEatUp(vector<int>& piles, int H, int speed) {
        int hours = 0;

        for (int pile : piles) {
            hours += ((pile - 1) / speed + 1);
        }

        return hours <= H;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> piles = { 3,6,7,11 };
    check.checkInt(4, o.minEatingSpeed(piles, 8));

    piles = { 30,11,23,4,20 };
    check.checkInt(30, o.minEatingSpeed(piles, 5));

    piles = { 30,11,23,4,20 };
    check.checkInt(23, o.minEatingSpeed(piles, 6));

    piles = { 30,11,23,4,20 };
    check.checkInt(20, o.minEatingSpeed(piles, 7));

    piles = { 30,11,23,4,20 };
    check.checkInt(15, o.minEatingSpeed(piles, 8));

    piles = { 30,11,23,4,20 };
    check.checkInt(12, o.minEatingSpeed(piles, 9));

    piles = { 30,11,23,4,20 };
    check.checkInt(11, o.minEatingSpeed(piles, 10));

    piles = { 30,11,23,4,20 };
    check.checkInt(10, o.minEatingSpeed(piles, 11));

    piles = { 30,11,23,4,20 };
    check.checkInt(10, o.minEatingSpeed(piles, 12));

    piles = { 30,11,23,4,20 };
    check.checkInt(8, o.minEatingSpeed(piles, 13));
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
