/* 放置盒子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个立方体房间，其长度、宽度和高度都等于 n 个单位。请你在房间里放置 n 个盒子，每个盒子都是一个单位边长的立方体。放置规则如下：

你可以把盒子放在地板上的任何地方。
如果盒子 x 需要放置在盒子 y 的顶部，那么盒子 y 竖直的四个侧面都 必须 与另一个盒子或墙相邻。
给你一个整数 n ，返回接触地面的盒子的 最少 可能数量。

 

示例 1：



输入：n = 3
输出：3
解释：上图是 3 个盒子的摆放位置。
这些盒子放在房间的一角，对应左侧位置。
示例 2：



输入：n = 4
输出：3
解释：上图是 3 个盒子的摆放位置。
这些盒子放在房间的一角，对应左侧位置。
示例 3：



输入：n = 10
输出：6
解释：上图是 10 个盒子的摆放位置。
这些盒子放在房间的一角，对应后方位置。
 

提示：

1 <= n <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/building-boxes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumBoxes(int n) {
        // 1 + 3 + 6 + 10 + ... = n * (n + 1) * (n + 2) / 6
        // 1 + 2 + 3 + ... = n * (n + 1) / 2
        long long layer = (long long)pow((long long)n * 6, 1.0 / 3);  // 大概计算层数
        long long full = layer * (layer + 1) * (layer + 2) / 6;
        if (full == n) {  // 刚好满员，直接返回答案
            return (int)(layer * (layer + 1) / 2);
        }
        else if (full > n) {  // 满员情况下比实际需要多了，层数减1，然后看剩下的还需要多少
            layer -= 1;
        }

        long long left = n - layer * (layer + 1) * (layer + 2) / 6;
        long long add = (long long)pow(left * 2, 1.0 / 2);  // 大概计算最底层还需要放几个
        if (add * (add + 1) / 2 < left) {  // 还不够，再多放一个肯定够了
            add += 1;
        }

        return (int)(layer * (layer + 1) / 2 + add);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.minimumBoxes(1));
    check.checkInt(2, o.minimumBoxes(2));
    check.checkInt(3, o.minimumBoxes(3));
    check.checkInt(3, o.minimumBoxes(4));
    check.checkInt(4, o.minimumBoxes(5));
    check.checkInt(5, o.minimumBoxes(6));
    check.checkInt(5, o.minimumBoxes(7));
    check.checkInt(6, o.minimumBoxes(8));
    check.checkInt(6, o.minimumBoxes(9));
    check.checkInt(6, o.minimumBoxes(10));
    check.checkInt(7, o.minimumBoxes(11));
    check.checkInt(34, o.minimumBoxes(100));
    check.checkInt(161, o.minimumBoxes(1000));
    check.checkInt(756, o.minimumBoxes(10000));
    check.checkInt(3536, o.minimumBoxes(100000));
    check.checkInt(16443, o.minimumBoxes(1000000));
    check.checkInt(76518, o.minimumBoxes(10000000));
    check.checkInt(355458, o.minimumBoxes(100000000));
    check.checkInt(1650467, o.minimumBoxes(1000000000));
    check.checkInt(1650467, o.minimumBoxes(999999999));
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
