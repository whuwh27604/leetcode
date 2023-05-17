/* 找出转圈游戏输家.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
n 个朋友在玩游戏。这些朋友坐成一个圈，按 顺时针方向 从 1 到 n 编号。从第 i 个朋友的位置开始顺时针移动 1 步会到达第 (i + 1) 个朋友的位置（1 <= i < n），而从第 n 个朋友的位置开始顺时针移动 1 步会回到第 1 个朋友的位置。

游戏规则如下：

第 1 个朋友接球。

接着，第 1 个朋友将球传给距离他顺时针方向 k 步的朋友。
然后，接球的朋友应该把球传给距离他顺时针方向 2 * k 步的朋友。
接着，接球的朋友应该把球传给距离他顺时针方向 3 * k 步的朋友，以此类推。
换句话说，在第 i 轮中持有球的那位朋友需要将球传递给距离他顺时针方向 i * k 步的朋友。

当某个朋友第 2 次接到球时，游戏结束。

在整场游戏中没有接到过球的朋友是 输家 。

给你参与游戏的朋友数量 n 和一个整数 k ，请按升序排列返回包含所有输家编号的数组 answer 作为答案。



示例 1：

输入：n = 5, k = 2
输出：[4,5]
解释：以下为游戏进行情况：
1）第 1 个朋友接球，第 1 个朋友将球传给距离他顺时针方向 2 步的玩家 —— 第 3 个朋友。
2）第 3 个朋友将球传给距离他顺时针方向 4 步的玩家 —— 第 2 个朋友。
3）第 2 个朋友将球传给距离他顺时针方向 6 步的玩家 —— 第 3 个朋友。
4）第 3 个朋友接到两次球，游戏结束。
示例 2：

输入：n = 4, k = 4
输出：[2,3,4]
解释：以下为游戏进行情况：
1）第 1 个朋友接球，第 1 个朋友将球传给距离他顺时针方向 4 步的玩家 —— 第 1 个朋友。
2）第 1 个朋友接到两次球，游戏结束。


提示：

1 <= k <= n <= 50
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> visited(n, false);
        vector<int> losers;
        int player = 0, round = 1;

        while (!visited[player]) {
            visited[player] = true;
            player = (player + k * round++) % n;
        }

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                losers.push_back(i + 1);
            }
        }

        return losers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.circularGameLosers(5, 2);
    vector<int> expected = { 4,5 };
    check.checkIntVector(expected, actual);

    actual = o.circularGameLosers(4, 4);
    expected = { 2,3,4 };
    check.checkIntVector(expected, actual);

    actual = o.circularGameLosers(1, 1);
    expected = {  };
    check.checkIntVector(expected, actual);
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
