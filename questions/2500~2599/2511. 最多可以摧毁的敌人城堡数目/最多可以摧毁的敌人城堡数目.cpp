/* 最多可以摧毁的敌人城堡数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n ，下标从 0 开始的整数数组 forts ，表示一些城堡。forts[i] 可以是 -1 ，0 或者 1 ，其中：

-1 表示第 i 个位置 没有 城堡。
0 表示第 i 个位置有一个 敌人 的城堡。
1 表示第 i 个位置有一个你控制的城堡。
现在，你需要决定，将你的军队从某个你控制的城堡位置 i 移动到一个空的位置 j ，满足：

0 <= i, j <= n - 1
军队经过的位置 只有 敌人的城堡。正式的，对于所有 min(i,j) < k < max(i,j) 的 k ，都满足 forts[k] == 0 。
当军队移动时，所有途中经过的敌人城堡都会被 摧毁 。

请你返回 最多 可以摧毁的敌人城堡数目。如果 无法 移动你的军队，或者没有你控制的城堡，请返回 0 。



示例 1：

输入：forts = [1,0,0,-1,0,0,0,0,1]
输出：4
解释：
- 将军队从位置 0 移动到位置 3 ，摧毁 2 个敌人城堡，位置分别在 1 和 2 。
- 将军队从位置 8 移动到位置 3 ，摧毁 4 个敌人城堡。
4 是最多可以摧毁的敌人城堡数目，所以我们返回 4 。
示例 2：

输入：forts = [0,0,1,-1]
输出：0
解释：由于无法摧毁敌人的城堡，所以返回 0 。


提示：

1 <= forts.length <= 1000
-1 <= forts[i] <= 1
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int captureForts(vector<int>& forts) {
        int i = 0, j = 0, size = forts.size(), maxForts = 0;

        while (i < size) {
            if (forts[i] != 0) {
                ++i;
            }
            else {
                for (j = i + 1; j < size && forts[j] == 0; ++j) {}
                if (i != 0 && j != size && forts[i - 1] + forts[j] == 0) {
                    maxForts = max(maxForts, j - i);
                }
                i = j;
            }
        }

        return maxForts;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> forts = { 1,0,0,-1,0,0,0,0,1 };
    check.checkInt(4, o.captureForts(forts));

    forts = { 0,0,1,-1 };
    check.checkInt(0, o.captureForts(forts));
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
