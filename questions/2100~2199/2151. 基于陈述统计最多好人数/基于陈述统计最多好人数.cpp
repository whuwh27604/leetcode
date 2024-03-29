﻿/* 基于陈述统计最多好人数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
游戏中存在两种角色：

好人：该角色只说真话。
坏人：该角色可能说真话，也可能说假话。
给你一个下标从 0 开始的二维整数数组 statements ，大小为 n x n ，表示 n 个玩家对彼此角色的陈述。具体来说，statements[i][j] 可以是下述值之一：

0 表示 i 的陈述认为 j 是 坏人 。
1 表示 i 的陈述认为 j 是 好人 。
2 表示 i 没有对 j 作出陈述。
另外，玩家不会对自己进行陈述。形式上，对所有 0 <= i < n ，都有 statements[i][i] = 2 。

根据这 n 个玩家的陈述，返回可以认为是 好人 的 最大 数目。

 

示例 1：


输入：statements = [[2,1,2],[1,2,2],[2,0,2]]
输出：2
解释：每个人都做一条陈述。
- 0 认为 1 是好人。
- 1 认为 0 是好人。
- 2 认为 1 是坏人。
以 2 为突破点。
- 假设 2 是一个好人：
    - 基于 2 的陈述，1 是坏人。
    - 那么可以确认 1 是坏人，2 是好人。
    - 基于 1 的陈述，由于 1 是坏人，那么他在陈述时可能：
        - 说真话。在这种情况下会出现矛盾，所以假设无效。
        - 说假话。在这种情况下，0 也是坏人并且在陈述时说假话。
    - 在认为 2 是好人的情况下，这组玩家中只有一个好人。
- 假设 2 是一个坏人：
    - 基于 2 的陈述，由于 2 是坏人，那么他在陈述时可能：
        - 说真话。在这种情况下，0 和 1 都是坏人。
            - 在认为 2 是坏人但说真话的情况下，这组玩家中没有一个好人。
        - 说假话。在这种情况下，1 是好人。
            - 由于 1 是好人，0 也是好人。
            - 在认为 2 是坏人且说假话的情况下，这组玩家中有两个好人。
在最佳情况下，至多有两个好人，所以返回 2 。
注意，能得到此结论的方法不止一种。
示例 2：


输入：statements = [[2,0],[0,2]]
输出：1
解释：每个人都做一条陈述。
- 0 认为 1 是坏人。
- 1 认为 0 是坏人。
以 0 为突破点。
- 假设 0 是一个好人：
    - 基于与 0 的陈述，1 是坏人并说假话。
    - 在认为 0 是好人的情况下，这组玩家中只有一个好人。
- 假设 0 是一个坏人：
    - 基于 0 的陈述，由于 0 是坏人，那么他在陈述时可能：
        - 说真话。在这种情况下，0 和 1 都是坏人。
            - 在认为 0 是坏人但说真话的情况下，这组玩家中没有一个好人。
        - 说假话。在这种情况下，1 是好人。
            - 在认为 0 是坏人且说假话的情况下，这组玩家中只有一个好人。
在最佳情况下，至多有一个好人，所以返回 1 。
注意，能得到此结论的方法不止一种。
 

提示：

n == statements.length == statements[i].length
2 <= n <= 15
statements[i][j] 的值为 0、1 或 2
statements[i][i] == 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-good-people-based-on-statements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size(), maxGoods = 0;

        for (int i = 1; i < (1 << n); ++i) {
            vector<int> isGood(n, 0);
            int goods = getGoods(i, isGood);

            if (check(n, statements, isGood)) {
                maxGoods = max(maxGoods, goods);
            }
        }

        return maxGoods;
    }

    int getGoods(int state, vector<int>& isGood) {
        int goods = 0;

        for (int i = 0, bit = 1; i < (int)isGood.size(); ++i, bit <<= 1) {
            if ((bit & state) != 0) {
                ++goods;
                isGood[i] = 1;
            }
        }

        return goods;
    }

    bool check(int n, vector<vector<int>>& statements, vector<int>& isGood) {
        for (int i = 0; i < n; ++i) {
            if (isGood[i]) {
                for (int j = 0; j < n; ++j) {
                    if (statements[i][j] != 2 && (statements[i][j] ^ isGood[j]) == 1) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> statements = { {2,1,2},{1,2,2},{2,0,2} };
    check.checkInt(2, o.maximumGood(statements));

    statements = { {2,0},{0,2} };
    check.checkInt(1, o.maximumGood(statements));

    statements = { {2,1,0,0,2},{2,2,1,0,2},{0,2,2,1,0},{2,0,0,2,0},{2,0,0,1,2} };
    check.checkInt(1, o.maximumGood(statements));

    statements = {{2,1,0,0,2,2,1,0,0,2,2,1,0,0,2},{2,2,0,0,2,2,1,0,0,2,2,1,0,0,2},{2,1,2,0,2,2,1,0,0,2,2,1,0,0,2},{2,1,0,2,2,2,1,0,0,2,2,1,0,0,2},{2,1,0,0,2,2,1,0,0,2,2,1,0,0,2},{2,1,0,0,2,2,1,0,0,2,2,1,0,0,2},{2,1,0,0,2,2,2,0,0,2,2,1,0,0,2},{2,1,0,0,2,2,1,2,0,2,2,1,0,0,2},{2,1,0,0,2,2,1,0,2,2,2,1,0,0,2},{2,1,0,0,2,2,1,0,0,2,2,1,0,0,2},{2,1,0,0,2,2,1,0,0,2,2,1,0,0,2},{2,1,0,0,2,2,1,0,0,2,2,2,0,0,2},{2,1,0,0,2,2,1,0,0,2,2,1,2,0,2},{2,1,0,0,2,2,1,0,0,2,2,1,0,2,2},{2,1,0,0,2,2,1,0,0,2,2,1,0,0,2}};
    check.checkInt(9, o.maximumGood(statements));
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
