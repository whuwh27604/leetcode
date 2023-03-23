/* 将钱分给最多的儿童.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 money ，表示你总共有的钱数（单位为美元）和另一个整数 children ，表示你要将钱分配给多少个儿童。

你需要按照如下规则分配：

所有的钱都必须被分配。
每个儿童至少获得 1 美元。
没有人获得 4 美元。
请你按照上述规则分配金钱，并返回 最多 有多少个儿童获得 恰好 8 美元。如果没有任何分配方案，返回 -1 。



示例 1：

输入：money = 20, children = 3
输出：1
解释：
最多获得 8 美元的儿童数为 1 。一种分配方案为：
- 给第一个儿童分配 8 美元。
- 给第二个儿童分配 9 美元。
- 给第三个儿童分配 3 美元。
没有分配方案能让获得 8 美元的儿童数超过 1 。
示例 2：

输入：money = 16, children = 2
输出：2
解释：每个儿童都可以获得 8 美元。


提示：

1 <= money <= 200
2 <= children <= 30
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int distMoney(int money, int children) {
        if ((money == 4 && children == 1) || (money < children)) {  // 钱比人少或者只有一个人刚好有4块钱，返回失败
            return -1;
        }

        money -= children;  // 一人分一块
        int ans = money / 7;  // 还有多少人能分7块，就是分到8块的人
        if (ans == 0) {
            return ans;
        }

        if (ans > children) {  // 比实际人数还多，那么最后一个人不能分8块，要把剩下的钱全部给他
            return children - 1;
        }

        if (ans == children && money % 7 != 0) {  // 所有人都能分8块，但还有剩余的钱，那么最后一个人要超过8块
            return children - 1;
        }

        if (ans == children - 1 && money % 7 == 3) {  // 最后剩一个人，同时剩3块钱，那么有一个8块的人要被调整
            return ans - 1;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.distMoney(20, 3));
    check.checkInt(2, o.distMoney(16, 2));
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
