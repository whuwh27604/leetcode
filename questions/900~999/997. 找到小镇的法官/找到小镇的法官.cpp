/* 找到小镇的法官.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个小镇里，按从 1 到 N 标记了 N 个人。传言称，这些人中有一个是小镇上的秘密法官。

如果小镇的法官真的存在，那么：

小镇的法官不相信任何人。
每个人（除了小镇法官外）都信任小镇的法官。
只有一个人同时满足属性 1 和属性 2 。
给定数组 trust，该数组由信任对 trust[i] = [a, b] 组成，表示标记为 a 的人信任标记为 b 的人。

如果小镇存在秘密法官并且可以确定他的身份，请返回该法官的标记。否则，返回 -1。

 

示例 1：

输入：N = 2, trust = [[1,2]]
输出：2
示例 2：

输入：N = 3, trust = [[1,3],[2,3]]
输出：3
示例 3：

输入：N = 3, trust = [[1,3],[2,3],[3,1]]
输出：-1
示例 4：

输入：N = 3, trust = [[1,2],[2,3]]
输出：-1
示例 5：

输入：N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
输出：3
 

提示：

1 <= N <= 1000
trust.length <= 10000
trust[i] 是完全不同的
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-town-judge
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trustCount(N + 1, 0);
        vector<bool> trustOther(N + 1, false);

        for (auto& trustPair : trust) {
            trustOther[trustPair[0]] = true;
            ++trustCount[trustPair[1]];
        }

        for (int i = 1; i <= N; ++i) {
            if (trustCount[i] == N - 1 && !trustOther[i]) {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> trust = { {1,2} };
    check.checkInt(2, o.findJudge(2, trust));

    trust = { {1,3},{2,3} };
    check.checkInt(3, o.findJudge(3, trust));

    trust = { {1,3},{2,3},{3,1} };
    check.checkInt(-1, o.findJudge(3, trust));

    trust = { {1,2},{2,3} };
    check.checkInt(-1, o.findJudge(3, trust));

    trust = { {1,3},{1,4},{2,3},{2,4},{4,3} };
    check.checkInt(3, o.findJudge(4, trust));

    trust = { {1,3},{1,4},{2,3},{2,4},{4,3} };
    check.checkInt(-1, o.findJudge(5, trust));

    trust = {  };
    check.checkInt(-1, o.findJudge(3, trust));

    trust = {  };
    check.checkInt(1, o.findJudge(1, trust));

    trust = { {1,3},{1,4},{2,3},{2,4},{3,4} };
    check.checkInt(4, o.findJudge(4, trust));

    trust = { {1,3},{1,4},{2,3},{2,4},{3,4},{4,3} };
    check.checkInt(-1, o.findJudge(4, trust));
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
