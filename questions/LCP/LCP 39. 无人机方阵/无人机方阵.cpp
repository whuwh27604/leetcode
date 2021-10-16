/* 无人机方阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在 「力扣挑战赛」 开幕式的压轴节目 「无人机方阵」中，每一架无人机展示一种灯光颜色。 无人机方阵通过两种操作进行颜色图案变换：

调整无人机的位置布局
切换无人机展示的灯光颜色
给定两个大小均为 N*M 的二维数组 source 和 target 表示无人机方阵表演的两种颜色图案，由于无人机切换灯光颜色的耗能很大，请返回从 source 到 target 最少需要多少架无人机切换灯光颜色。

注意： 调整无人机的位置布局时无人机的位置可以随意变动。

示例 1：

输入：source = [[1,3],[5,4]], target = [[3,1],[6,5]]

输出：1

解释：
最佳方案为
将 [0,1] 处的无人机移动至 [0,0] 处；
将 [0,0] 处的无人机移动至 [0,1] 处；
将 [1,0] 处的无人机移动至 [1,1] 处；
将 [1,1] 处的无人机移动至 [1,0] 处，其灯光颜色切换为颜色编号为 6 的灯光；
因此从source 到 target 所需要的最少灯光切换次数为 1。


示例 2：

输入：source = [[1,2,3],[3,4,5]], target = [[1,3,5],[2,3,4]]

输出：0
解释：
仅需调整无人机的位置布局，便可完成图案切换。因此不需要无人机切换颜色

提示：
n == source.length == target.length
m == source[i].length == target[i].length
1 <= n, m <=100
1 <= source[i][j], target[i][j] <=10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/0jQkd0
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumSwitchingTimes(vector<vector<int>>& source, vector<vector<int>>& target) {
        int i, j, row = source.size(), column = source[0].size(), switchs = 0;
        vector<int> colors(10001, 0);

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                ++colors[source[i][j]];
                --colors[target[i][j]];
            }
        }

        for (int num : colors) {
            if (num > 0) {
                switchs += num;
            }
        }

        return switchs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> source = { {1,3},{5,4} };
    vector<vector<int>> target = { {3,1},{6,5} };
    check.checkInt(1, o.minimumSwitchingTimes(source, target));

    source = { {1,2,3},{3,4,5} };
    target = { {1,3,5},{2,3,4} };
    check.checkInt(0, o.minimumSwitchingTimes(source, target));
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
