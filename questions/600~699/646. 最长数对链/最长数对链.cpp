/* 最长数对链.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。

现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a, b) 后面。我们用这种形式来构造一个数对链。

给定一个对数集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。

示例 :

输入: [[1,2], [2,3], [3,4]]
输出: 2
解释: 最长的数对链是 [1,2] -> [3,4]
注意：

给出数对的个数在 [1, 1000] 范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-pair-chain
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] < v2[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), vectorCompare);  // 贪心算法，按第二个数排序，然后依次选择满足条件的数对

        int second = pairs[0][1], count = 1;

        for (int i = 1; i < (int)pairs.size(); i++) {
            if (pairs[i][0] > second) {
                count++;
                second = pairs[i][1];
            }
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> pairs = { {1,2},{2,3},{3,4} };
    check.checkInt(2, o.findLongestChain(pairs));

    pairs = { {1,2} };
    check.checkInt(1, o.findLongestChain(pairs));

    pairs = { {3,4},{2,3},{1,2} };
    check.checkInt(2, o.findLongestChain(pairs));

    pairs = { {1,4},{1,3},{3,4} };
    check.checkInt(1, o.findLongestChain(pairs));

    pairs = { {-10,-8},{-6,-4},{-5,0},{-4,7},{1,7},{6,10},{8,9},{9,10} };
    check.checkInt(4, o.findLongestChain(pairs));

    pairs = { {-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3} };
    check.checkInt(3, o.findLongestChain(pairs));
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
