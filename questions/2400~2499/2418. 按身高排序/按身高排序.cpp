/* 按身高排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串数组 names ，和一个由 互不相同 的正整数组成的数组 heights 。两个数组的长度均为 n 。

对于每个下标 i，names[i] 和 heights[i] 表示第 i 个人的名字和身高。

请按身高 降序 顺序返回对应的名字数组 names 。

 

示例 1：

输入：names = ["Mary","John","Emma"], heights = [180,165,170]
输出：["Mary","Emma","John"]
解释：Mary 最高，接着是 Emma 和 John 。
示例 2：

输入：names = ["Alice","Bob","Bob"], heights = [155,185,150]
输出：["Bob","Alice","Bob"]
解释：第一个 Bob 最高，然后是 Alice 和第二个 Bob 。
 

提示：

n == names.length == heights.length
1 <= n <= 103
1 <= names[i].length <= 20
1 <= heights[i] <= 105
names[i] 由大小写英文字母组成
heights 中的所有值互不相同

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/sort-the-people
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, int>> heightIndices(n);
        vector<string> ans(n);

        for (int i = 0; i < n; ++i) {
            heightIndices[i] = { heights[i], i };
        }

        sort(heightIndices.begin(), heightIndices.end());

        for (int i = 0; i < n; ++i) {
            ans[i] = names[heightIndices[n - 1 - i].second];
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> names = { "Mary","John","Emma" };
    vector<int> heights = { 180,165,170 };
    vector<string> actual = o.sortPeople(names, heights);
    vector<string> expected = { "Mary","Emma","John" };
    check.checkStringVector(expected, actual);

    names = { "Alice","Bob","Bob" };
    heights = { 155,185,150 };
    actual = o.sortPeople(names, heights);
    expected = { "Bob","Alice","Bob" };
    check.checkStringVector(expected, actual);
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
