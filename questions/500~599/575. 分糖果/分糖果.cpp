/* 分糖果.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个偶数长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。你需要把这些糖果平均分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。

示例 1:

输入: candies = [1,1,2,2,3,3]
输出: 3
解析: 一共有三种种类的糖果，每一种都有两个。
     最优分配方案：妹妹获得[1,2,3],弟弟也获得[1,2,3]。这样使妹妹获得糖果的种类数最多。
示例 2 :

输入: candies = [1,1,2,3]
输出: 2
解析: 妹妹获得糖果[2,3],弟弟获得糖果[1,1]，妹妹有两种不同的糖果，弟弟只有一种。这样使得妹妹可以获得的糖果种类数最多。
注意:

数组的长度为[2, 10,000]，并且确定为偶数。
数组中数字的大小在范围[-100,000, 100,000]内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distribute-candies
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        /* 糖果种类和妹妹拿到的糖果颗数取小的一个 */
        unordered_set<int> candyTypeCount;
        for (unsigned int i = 0; i < candies.size(); i++) {
            candyTypeCount.insert(candies[i]);
        }

        return min(candyTypeCount.size(), (candies.size() / 2));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> candies = { 1,1,2,2,3,3 };
    check.checkInt(3, o.distributeCandies(candies));

    candies = { 1,1,2,3 };
    check.checkInt(2, o.distributeCandies(candies));

    candies = { 1,2,3,4,5,6 };
    check.checkInt(3, o.distributeCandies(candies));

    candies = { 1,1,1,1,1,1 };
    check.checkInt(1, o.distributeCandies(candies));

    candies = { 1,3 };
    check.checkInt(1, o.distributeCandies(candies));
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
