/* 最后一块石头的重量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一堆石头，每块石头的重量都是正整数。

每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。

 

示例：

输入：[2,7,4,1,8,1]
输出：1
解释：
先选出 7 和 8，得到 1，所以数组转换为 [2,4,1,1,1]，
再选出 2 和 4，得到 2，所以数组转换为 [2,1,1,1]，
接着是 2 和 1，得到 1，所以数组转换为 [1,1,1]，
最后选出 1 和 1，得到 0，最终数组转换为 [1]，这就是最后剩下那块石头的重量。
 

提示：

1 <= stones.length <= 30
1 <= stones[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/last-stone-weight
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> sortedStones;

        for (int stone : stones) {
            sortedStones.push(stone);
        }

        while (sortedStones.size() > 1) {
            int x = sortedStones.top();
            sortedStones.pop();
            int y = sortedStones.top();
            sortedStones.pop();

            if (x != y) {
                sortedStones.push(x - y);
            }
        }

        return sortedStones.empty() ? 0 : sortedStones.top();
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> stones = { 2,7,4,1,8,1 };
    check.checkInt(1, o.lastStoneWeight(stones));

    stones = { 5 };
    check.checkInt(5, o.lastStoneWeight(stones));

    stones = { 5,5 };
    check.checkInt(0, o.lastStoneWeight(stones));

    stones = { 5,3 };
    check.checkInt(2, o.lastStoneWeight(stones));

    stones = { 1,3,6,10,15,21 };
    check.checkInt(0, o.lastStoneWeight(stones));

    stones = { 1,3,6,10,15,21,28 };
    check.checkInt(0, o.lastStoneWeight(stones));

    stones = { 1,3,6,10,15,21,28,29 };
    check.checkInt(1, o.lastStoneWeight(stones));
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
