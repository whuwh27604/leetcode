/* 搭桥过河.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
欢迎各位勇者来到力扣城，本次试炼主题为「搭桥过河」。

勇者面前有一段长度为 num 的河流，河流可以划分为若干河道。每条河道上恰有一块浮木，wood[i] 记录了第 i 条河道上的浮木初始的覆盖范围。

当且仅当浮木与相邻河道的浮木覆盖范围有重叠时，勇者才可以在两条浮木间移动
勇者 仅能在岸上 通过花费一点「自然之力」，使任意一条浮木沿着河流移动一个单位距离
请问勇者跨越这条河流，最少需要花费多少「自然之力」。

示例 1：

输入： num = 10, wood = [[1,2],[4,7],[8,9]] 输出： 3 解释：如下图所示， 将 [1,2] 浮木移动至 [3,4]，花费 2「自然之力」， 将 [8,9] 浮木移动至 [7,8]，花费 1「自然之力」， 此时勇者可以顺着 [3,4]->[4,7]->[7,8] 跨越河流， 因此，勇者最少需要花费 3 点「自然之力」跨越这条河流wood (2).gif

示例 2：

输入： num = 10, wood = [[1,5],[1,1],[10,10],[6,7],[7,8]] 输出： 10 解释： 将 [1,5] 浮木移动至 [2,6]，花费 1「自然之力」， 将 [1,1] 浮木移动至 [6,6]，花费 5「自然之力」， 将 [10,10] 浮木移动至 [6,6]，花费 4「自然之力」， 此时勇者可以顺着 [2,6]->[6,6]->[6,6]->[6,7]->[7,8] 跨越河流， 因此，勇者最少需要花费 10 点「自然之力」跨越这条河流

示例 3：

输入： num = 5, wood = [[1,2],[2,4]] 输出： 0 解释：勇者不需要移动浮木，仍可以跨越这条河流

提示:

1 <= num <= 10^9
1 <= wood.length <= 10^5
wood[i].length == 2
1 <= wood[i][0] <= wood[i][1] <= num
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    typedef long long LL;

    long long buildBridge(int num, vector<vector<int>>& wood) {
        priority_queue<LL> L;
        priority_queue<LL, vector<LL>, greater<LL>> R;
        LL biasL = 0, biasR = 0, ans = 0;

        L.push(wood[0][0]);
        R.push(wood[0][0]);

        for (int i = 1; i < (int)wood.size(); ++i) {
            biasL -= (wood[i][1] - wood[i][0]);
            biasR += (wood[i - 1][1] - wood[i - 1][0]);
            LL left = L.top() + biasL;
            LL right = R.top() + biasR;
            int x = wood[i][0];

            if (x < left) {
                ans += (left - x);
                L.pop();
                L.push(x - biasL);
                L.push(x - biasL);
                R.push(left - biasR);
            }
            else if (x > right) {
                ans += (x - right);
                R.pop();
                R.push(x - biasR);
                R.push(x - biasR);
                L.push(right - biasL);
            }
            else {
                L.push(x - biasL);
                R.push(x - biasR);
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> wood = { {1,2},{4,7},{8,9} };
    check.checkLongLong(3, o.buildBridge(10, wood));

    wood = { {1,5},{1,1},{10,10},{6,7},{7,8} };
    check.checkLongLong(10, o.buildBridge(10, wood));

    wood = { {1,2},{2,4} };
    check.checkLongLong(0, o.buildBridge(5, wood));
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
