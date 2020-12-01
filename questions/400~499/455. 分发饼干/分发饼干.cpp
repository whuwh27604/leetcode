/* 分发饼干.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。对每个孩子 i ，都有一个胃口值 gi ，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j ，都有一个尺寸 sj 。如果 sj >= gi ，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

注意：

你可以假设胃口值为正。
一个小朋友最多只能拥有一块饼干。

示例 1:

输入: [1,2,3], [1,1]

输出: 1

解释:
你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
所以你应该输出1。
示例 2:

输入: [1,2], [1,2,3]

输出: 2

解释:
你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。
你拥有的饼干数量和尺寸都足以让所有孩子满足。
所以你应该输出2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/assign-cookies
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // 对每个最小的g，选择大于g的最小的s
        int Childrens = 0;
        unsigned int indexS = 0;
        for (unsigned int i = 0; i < g.size(); i++) {
            if (canBeContented(s, g[i], indexS)) {
                Childrens++;
            }

            if (indexS >= s.size()) {
                break;
            }
        }

        return Childrens;
    }

    bool canBeContented(vector<int>& s, int g, unsigned int& indexS) {
        while (indexS < s.size()) {
            if (s[indexS++] >= g) {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> g = { 1,2,3 };
    vector<int> s = { 1,1 };
    check.checkInt(1, o.findContentChildren(g, s));

    g = { 2,1 };
    s = { 3,2,1 };
    check.checkInt(2, o.findContentChildren(g, s));

    g = { 1,2,3 };
    s = {  };
    check.checkInt(0, o.findContentChildren(g, s));

    g = {  };
    s = { 1,1 };
    check.checkInt(0, o.findContentChildren(g, s));

    g = { 1,2,3 };
    s = { 3 };
    check.checkInt(1, o.findContentChildren(g, s));

    g = { 10,9,8,7,6,5,4,3,2,1 };
    s = { 5,4,3,2,1,0,-1,-2,-3,-4,-5 };
    check.checkInt(5, o.findContentChildren(g, s));
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
