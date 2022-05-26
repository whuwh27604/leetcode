/* 采集果实.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
欢迎各位勇者来到力扣新手村，本次训练内容为「采集果实」。

在新手村中，各位勇者需要采集一些果实来制作药剂。time[i] 表示勇者每次采集 1～limit 颗第 i 种类型的果实需要的时间（即每次最多可以采集 limit 颗果实）。

当前勇者需要完成「采集若干批果实」的任务， fruits[j] = [type, num] 表示第 j 批需要采集 num 颗 type 类型的果实。采集规则如下：

按 fruits 给定的顺序依次采集每一批次
采集完当前批次的果实才能开始采集下一批次
勇者完成当前批次的采集后将清空背包（即多余的果实将清空）
请计算并返回勇者完成采集任务最少需要的时间。

示例 1：

输入：time = [2,3,2], fruits = [[0,2],[1,4],[2,1]], limit = 3

输出：10

解释：
由于单次最多采集 3 颗
第 0 批需要采集 2 颗第 0 类型果实，需要采集 1 次，耗时为 2*1=2
第 1 批需要采集 4 颗第 1 类型果实，需要采集 2 次，耗时为 3*2=6
第 2 批需要采集 1 颗第 2 类型果实，需要采集 1 次，耗时为 2*1=2
返回总耗时 2+6+2=10

示例 2：

输入：time = [1], fruits = [[0,3],[0,5]], limit = 2

输出：5

解释：
由于单次最多采集 2 颗
第 0 批需要采集 3 颗第 0 类型果实，需要采集 2 次，耗时为 1*2=2
第 1 批需要采集 5 颗第 0 类型果实，需要采集 3 次，耗时为 1*3=3
需按照顺序依次采集，返回 2+3=5

提示：

1 <= time.length <= 100
1 <= time[i] <= 100
1 <= fruits.length <= 10^3
0 <= fruits[i][0] < time.length
1 <= fruits[i][1] < 10^3
1 <= limit <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/PTXy4P
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getMinimumTime(vector<int>& time, vector<vector<int>>& fruits, int limit) {
        int i, size = fruits.size(), totalTime = 0;

        for (i = 0; i < size; ++i) {
            totalTime += (int)ceil((double)fruits[i][1] / limit) * time[fruits[i][0]];
        }

        return totalTime;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> time = { 2,3,2 };
    vector<vector<int>> fruits = { {0,2},{1,4},{2,1} };
    check.checkInt(10, o.getMinimumTime(time, fruits, 3));

    time = { 1 };
    fruits = { {0,3},{0,5} };
    check.checkInt(5, o.getMinimumTime(time, fruits, 2));
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
