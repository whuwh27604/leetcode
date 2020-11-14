/* 拿硬币.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
桌上有 n 堆力扣币，每堆的数量保存在数组 coins 中。我们每次可以选择任意一堆，拿走其中的一枚或者两枚，求拿完所有力扣币的最少次数。

示例 1：

输入：[4,2,1]

输出：4

解释：第一堆力扣币最少需要拿 2 次，第二堆最少需要拿 1 次，第三堆最少需要拿 1 次，总共 4 次即可拿完。

示例 2：

输入：[2,3,10]

输出：8

限制：

1 <= n <= 4
1 <= coins[i] <= 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/na-ying-bi
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minCount(vector<int>& coins) {
        int i, len = coins.size(), totalCount = 0;
        int count[11] = { 0,1,1,2,2,3,3,4,4,5,5 };

        for (i = 0; i < len; i++) {
            totalCount += count[coins[i]];
        }

        return totalCount;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> coins = { 4,2,1 };
    check.checkInt(4, o.minCount(coins));

    coins = { 2,3,10 };
    check.checkInt(8, o.minCount(coins));

    coins = { 1 };
    check.checkInt(1, o.minCount(coins));

    coins = { 2 };
    check.checkInt(1, o.minCount(coins));

    coins = { 3 };
    check.checkInt(2, o.minCount(coins));

    coins = { 10 };
    check.checkInt(5, o.minCount(coins));
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
