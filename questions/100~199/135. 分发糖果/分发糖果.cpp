/* 分发糖果.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:

输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
示例 2:

输入: [1,2,2]
输出: 4
解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/candy
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        const int STATE_STABLE = 0;
        const int STATE_INCREASING = 1;
        const int STATE_DECREASING = 2;
        int i, size = ratings.size(), decreasingLen = 0, state = STATE_STABLE, prev = 1, candies = 1;

        for (i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                if (state == STATE_DECREASING) {
                    candies += calcDecreasingCandies(prev, decreasingLen);
                    prev = 1;
                }

                decreasingLen = 0;
                state = STATE_INCREASING;
                candies += ++prev;
            }
            else if (ratings[i] < ratings[i - 1]) {
                if (state == STATE_INCREASING || state == STATE_STABLE) {
                    decreasingLen = 2;
                }
                else {
                    decreasingLen += 1;
                }

                state = STATE_DECREASING;
            }
            else {
                if (state == STATE_DECREASING) {
                    candies += calcDecreasingCandies(prev, decreasingLen);
                }

                prev = 1;
                candies += 1;
                decreasingLen = 0;
                state = STATE_STABLE;
            }
        }

        if (state == STATE_DECREASING) {
            candies += calcDecreasingCandies(prev, decreasingLen);
        }

        return candies;
    }

    int calcDecreasingCandies(int prev, int decreasingLen) {
        if (prev >= decreasingLen) {
            return (decreasingLen - 1) * decreasingLen / 2;
        }
        else {
            return ((decreasingLen + 1) * decreasingLen / 2 - prev);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> ratings = { 4,3,3,2,1 };
    check.checkInt(9, o.candy(ratings));

    ratings = { 1,0,2 };
    check.checkInt(5, o.candy(ratings));

    ratings = { 1,2,2 };
    check.checkInt(4, o.candy(ratings));

    ratings = { 1,2,3,3,3,2,1 };
    check.checkInt(13, o.candy(ratings));

    ratings = { 1,2,3,4,4,4,4,4,3,2,1 };
    check.checkInt(23, o.candy(ratings));

    ratings = { 3,1,7,2,3,4,8,2,5,9 };
    check.checkInt(21, o.candy(ratings));
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
