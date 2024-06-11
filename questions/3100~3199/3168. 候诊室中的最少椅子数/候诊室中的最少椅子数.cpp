﻿/* 候诊室中的最少椅子数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s，模拟每秒钟的事件 i：

如果 s[i] == 'E'，表示有一位顾客进入候诊室并占用一把椅子。
如果 s[i] == 'L'，表示有一位顾客离开候诊室，从而释放一把椅子。
返回保证每位进入候诊室的顾客都能有椅子坐的 最少 椅子数，假设候诊室最初是 空的 。



示例 1：

输入：s = "EEEEEEE"

输出：7

解释：

每秒后都有一个顾客进入候诊室，没有人离开。因此，至少需要 7 把椅子。

示例 2：

输入：s = "ELELEEL"

输出：2

解释：

假设候诊室里有 2 把椅子。下表显示了每秒钟等候室的状态。

秒	事件	候诊室的人数	可用的椅子数
0	Enter	1	1
1	Leave	0	2
2	Enter	1	1
3	Leave	0	2
4	Enter	1	1
5	Enter	2	0
6	Leave	1	1
示例 3：

输入：s = "ELEELEELLL"

输出：3

解释：

假设候诊室里有 3 把椅子。下表显示了每秒钟等候室的状态。

秒	事件	候诊室的人数	可用的椅子数
0	Enter	1	2
1	Leave	0	3
2	Enter	1	2
3	Enter	2	1
4	Leave	1	2
5	Enter	2	1
6	Enter	3	0
7	Leave	2	1
8	Leave	1	2
9	Leave	0	3


提示：

1 <= s.length <= 50
s 仅由字母 'E' 和 'L' 组成。
s 表示一个有效的进出序列。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        int maxPerson = 0, person = 0;

        for (char c : s) {
            if (c == 'E') {
                ++person;
            }
            else {
                --person;
            }

            maxPerson = max(maxPerson, person);
        }

        return maxPerson;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(7, o.minimumChairs("EEEEEEE"));
    check.checkInt(2, o.minimumChairs("ELELEEL"));
    check.checkInt(3, o.minimumChairs("ELEELEELLL"));
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
