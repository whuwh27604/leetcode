/* 自由之路.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
视频游戏“辐射4”中，任务“通向自由”要求玩家到达名为“Freedom Trail Ring”的金属表盘，并使用表盘拼写特定关键词才能开门。

给定一个字符串 ring，表示刻在外环上的编码；给定另一个字符串 key，表示需要拼写的关键词。您需要算出能够拼写关键词中所有字符的最少步数。

最初，ring 的第一个字符与12:00方向对齐。您需要顺时针或逆时针旋转 ring 以使 key 的一个字符在 12:00 方向对齐，然后按下中心按钮，以此逐个拼写完 key 中的所有字符。

旋转 ring 拼出 key 字符 key[i] 的阶段中：

您可以将 ring 顺时针或逆时针旋转一个位置，计为1步。旋转的最终目的是将字符串 ring 的一个字符与 12:00 方向对齐，并且这个字符必须等于字符 key[i] 。
如果字符 key[i] 已经对齐到12:00方向，您需要按下中心按钮进行拼写，这也将算作 1 步。按完之后，您可以开始拼写 key 的下一个字符（下一阶段）, 直至完成所有拼写。
示例：

 


 
输入: ring = "godding", key = "gd"
输出: 4
解释:
 对于 key 的第一个字符 'g'，已经在正确的位置, 我们只需要1步来拼写这个字符。
 对于 key 的第二个字符 'd'，我们需要逆时针旋转 ring "godding" 2步使它变成 "ddinggo"。
 当然, 我们还需要1步进行拼写。
 因此最终的输出是 4。
提示：

ring 和 key 的字符串长度取值范围均为 1 至 100；
两个字符串中都只有小写字符，并且均可能存在重复字符；
字符串 key 一定可以由字符串 ring 旋转拼出。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/freedom-trail
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> positions('z' + 1, vector<int>{});
        getPositions(ring, positions);

        unsigned int i, j, k, sizeRing = ring.size(), sizeKey = key.size();
        vector<vector<int>> steps(sizeKey + 1, vector<int>(sizeRing, INT_MAX));  // steps[i][j]表示第i步从字符key[i]走到终点需要的最小步数，j表示key[i]在ring中的不同位置

        for (int position : positions[key[sizeKey - 1]]) {  // 初始化，最后一步，最后一个字符已经完成，需要0步
            steps[sizeKey][position] = 0;
        }

        for (i = sizeKey - 1; i > 0; --i) {  // 遍历每一个大的步骤
            char from = key[i - 1], to = key[i];  // 当前需要从key[i - 1]走到key[i]

            for (j = 0; j < positions[from].size(); ++j) {  // 枚举所有from所在的位置
                for (k = 0; k < positions[to].size(); ++k) {  // 枚举所有to所在的位置
                    /* 从from到to需要step步，由于正反都可以走，所以取小的。然后从to到终点我们已经知道了，两者相加就是从from到终点的最小值。
                       遍历所有从from到to可能的走法，取最小值就是从当前from到终点的最小值 */
                    int step = abs(positions[from][j] - positions[to][k]);
                    step = min(step, (int)sizeRing - step) + steps[i + 1][positions[to][k]] + 1;  // 按下这个字符需要一步，所以加1
                    steps[i][positions[from][j]] = min(steps[i][positions[from][j]], step);
                }
            }
        }

        char to = key[0];  // 最后，计算从ring[0]到key[0]需要的步数
        for (k = 0; k < positions[to].size(); ++k) {
            int step = min(positions[to][k], (int)sizeRing - positions[to][k]) + steps[1][positions[to][k]] + 1;
            steps[0][0] = min(steps[0][0], step);
        }

        return steps[0][0];
    }

    void getPositions(string& ring, vector<vector<int>>& positions) {
        for (unsigned int i = 0; i < ring.size(); ++i) {
            positions[ring[i]].push_back(i);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.findRotateSteps("godding", "gd"));
    check.checkInt(13, o.findRotateSteps("godding", "godding"));
    check.checkInt(1, o.findRotateSteps("a", "a"));
    check.checkInt(2, o.findRotateSteps("aa", "aa"));
    check.checkInt(10, o.findRotateSteps("edcba", "abcde"));
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
