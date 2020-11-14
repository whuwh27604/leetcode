/* 拥有最多糖果的孩子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 candies 和一个整数 extraCandies ，其中 candies[i] 代表第 i 个孩子拥有的糖果数目。

对每一个孩子，检查是否存在一种方案，将额外的 extraCandies 个糖果分配给孩子们之后，此孩子有 最多 的糖果。注意，允许有多个孩子同时拥有 最多 的糖果数目。

 

示例 1：

输入：candies = [2,3,5,1,3], extraCandies = 3
输出：[true,true,true,false,true]
解释：
孩子 1 有 2 个糖果，如果他得到所有额外的糖果（3个），那么他总共有 5 个糖果，他将成为拥有最多糖果的孩子。
孩子 2 有 3 个糖果，如果他得到至少 2 个额外糖果，那么他将成为拥有最多糖果的孩子。
孩子 3 有 5 个糖果，他已经是拥有最多糖果的孩子。
孩子 4 有 1 个糖果，即使他得到所有额外的糖果，他也只有 4 个糖果，无法成为拥有糖果最多的孩子。
孩子 5 有 3 个糖果，如果他得到至少 2 个额外糖果，那么他将成为拥有最多糖果的孩子。
示例 2：

输入：candies = [4,2,1,1,2], extraCandies = 1
输出：[true,false,false,false,false]
解释：只有 1 个额外糖果，所以不管额外糖果给谁，只有孩子 1 可以成为拥有糖果最多的孩子。
示例 3：

输入：candies = [12,1,12], extraCandies = 10
输出：[true,false,true]
 

提示：

2 <= candies.length <= 100
1 <= candies[i] <= 100
1 <= extraCandies <= 50

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kids-with-the-greatest-number-of-candies
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int i, len = candies.size(), maxCandies = 0;
        for (i = 0; i < len; i++) {
            if (candies[i] > maxCandies) {
                maxCandies = candies[i];
            }
        }
        maxCandies -= extraCandies;

        vector<bool> canBeMax;
        for (i = 0; i < len; i++) {
            if (candies[i] >= maxCandies) {
                canBeMax.push_back(true);
            }
            else {
                canBeMax.push_back(false);
            }
        }

        return canBeMax;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> candies = { 2,3,5,1,3 };
    vector<bool> actual = o.kidsWithCandies(candies, 3);
    vector<bool> expected = { true,true,true,false,true };
    check.checkBoolVector(expected, actual);

    candies = { 4,2,1,1,2 };
    actual = o.kidsWithCandies(candies, 1);
    expected = { true,false,false,false,false };
    check.checkBoolVector(expected, actual);

    candies = { 12,1,12 };
    actual = o.kidsWithCandies(candies, 10);
    expected = { true,false,true };
    check.checkBoolVector(expected, actual);

    candies = { 12,11 };
    actual = o.kidsWithCandies(candies, 1);
    expected = { true,true };
    check.checkBoolVector(expected, actual);

    candies = { 12,10 };
    actual = o.kidsWithCandies(candies, 1);
    expected = { true,false };
    check.checkBoolVector(expected, actual);

    candies = { 1,2,3,4,5 };
    actual = o.kidsWithCandies(candies, 10);
    expected = { true,true,true,true,true };
    check.checkBoolVector(expected, actual);
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
