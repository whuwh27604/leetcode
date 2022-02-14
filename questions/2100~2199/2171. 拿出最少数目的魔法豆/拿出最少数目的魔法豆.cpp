/* 拿出最少数目的魔法豆.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 正 整数数组 beans ，其中每个整数表示一个袋子里装的魔法豆的数目。

请你从每个袋子中 拿出 一些豆子（也可以 不拿出），使得剩下的 非空 袋子中（即 至少 还有 一颗 魔法豆的袋子）魔法豆的数目 相等 。一旦魔法豆从袋子中取出，你不能将它放到任何其他的袋子中。

请你返回你需要拿出魔法豆的 最少数目。

 

示例 1：

输入：beans = [4,1,6,5]
输出：4
解释：
- 我们从有 1 个魔法豆的袋子中拿出 1 颗魔法豆。
  剩下袋子中魔法豆的数目为：[4,0,6,5]
- 然后我们从有 6 个魔法豆的袋子中拿出 2 个魔法豆。
  剩下袋子中魔法豆的数目为：[4,0,4,5]
- 然后我们从有 5 个魔法豆的袋子中拿出 1 个魔法豆。
  剩下袋子中魔法豆的数目为：[4,0,4,4]
总共拿出了 1 + 2 + 1 = 4 个魔法豆，剩下非空袋子中魔法豆的数目相等。
没有比取出 4 个魔法豆更少的方案。
示例 2：

输入：beans = [2,10,3,2]
输出：7
解释：
- 我们从有 2 个魔法豆的其中一个袋子中拿出 2 个魔法豆。
  剩下袋子中魔法豆的数目为：[0,10,3,2]
- 然后我们从另一个有 2 个魔法豆的袋子中拿出 2 个魔法豆。
  剩下袋子中魔法豆的数目为：[0,10,3,0]
- 然后我们从有 3 个魔法豆的袋子中拿出 3 个魔法豆。
  剩下袋子中魔法豆的数目为：[0,10,0,0]
总共拿出了 2 + 2 + 3 = 7 个魔法豆，剩下非空袋子中魔法豆的数目相等。
没有比取出 7 个魔法豆更少的方案。
 

提示：

1 <= beans.length <= 105
1 <= beans[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/removing-minimum-number-of-magic-beans
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int i, size = beans.size();
        vector<long long> presums(size + 1, 0);

        sort(beans.begin(), beans.end());

        for (i = 0; i < size; ++i) {
            presums[i + 1] = presums[i] + beans[i];
        }

        long long minRemoval = presums[size];

        for (i = 0; i < size; ++i) {
            long long removal = presums[i] + presums[size] - presums[i + 1] - beans[i] * ((long long)size - 1 - i);
            minRemoval = min(minRemoval, removal);
        }

        return minRemoval;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> beans = { 4,1,6,5 };
    check.checkLongLong(4, o.minimumRemoval(beans));

    beans = { 2,10,3,2 };
    check.checkLongLong(7, o.minimumRemoval(beans));

    beans = { 2 };
    check.checkLongLong(0, o.minimumRemoval(beans));

    beans = { 2,2 };
    check.checkLongLong(0, o.minimumRemoval(beans));

    beans = { 2,5 };
    check.checkLongLong(2, o.minimumRemoval(beans));

    beans = { 12,15 };
    check.checkLongLong(3, o.minimumRemoval(beans));

    beans = { 2,4,1,6,5,2,10,3,2,2,5,12,15,4,1,6,5,2,10,3,2,2,5,12,15,4,1,6,5,2,10,3,2,2,5,12,15,4,1,6,5,2,10,3,2,2,5,12,15,4,1,6,5,2,10,3,2,2,5,12,15 };
    check.checkLongLong(187, o.minimumRemoval(beans));
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
