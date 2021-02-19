/* 青蛙过河.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一只青蛙想要过河。 假定河流被等分为 x 个单元格，并且在每一个单元格内都有可能放有一石子（也有可能没有）。 青蛙可以跳上石头，但是不可以跳入水中。

给定石子的位置列表（用单元格序号升序表示）， 请判定青蛙能否成功过河（即能否在最后一步跳至最后一个石子上）。 开始时， 青蛙默认已站在第一个石子上，并可以假定它第一步只能跳跃一个单位（即只能从单元格1跳至单元格2）。

如果青蛙上一步跳跃了 k 个单位，那么它接下来的跳跃距离只能选择为 k - 1、k 或 k + 1个单位。 另请注意，青蛙只能向前方（终点的方向）跳跃。

请注意：

石子的数量 ≥ 2 且 < 1100；
每一个石子的位置序号都是一个非负整数，且其 < 231；
第一个石子的位置永远是0。
示例 1:

[0,1,3,5,6,8,12,17]

总共有8个石子。
第一个石子处于序号为0的单元格的位置, 第二个石子处于序号为1的单元格的位置,
第三个石子在序号为3的单元格的位置， 以此定义整个数组...
最后一个石子处于序号为17的单元格的位置。

返回 true。即青蛙可以成功过河，按照如下方案跳跃：
跳1个单位到第2块石子, 然后跳2个单位到第3块石子, 接着
跳2个单位到第4块石子, 然后跳3个单位到第6块石子,
跳4个单位到第7块石子, 最后，跳5个单位到第8个石子（即最后一块石子）。
示例 2:

[0,1,2,3,4,8,9,11]

返回 false。青蛙没有办法过河。
这是因为第5和第6个石子之间的间距太大，没有可选的方案供青蛙跳跃过去。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/frog-jump
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) {
            return false;
        }

        unordered_map<int, int> indices;
        getStoneIndices(stones, indices);

        int i, j, size = stones.size();
        vector<vector<bool>> dp(size, vector<bool>(size, false));  // dp[i][j]表示从stones[j]是否能跳到stones[i]
        dp[1][0] = true;

        for (i = 1; i < size; ++i) {
            for (j = 0; j < i; ++j) {
                if (dp[i][j]) {  // 从j到i可达
                    if (i == size - 1) {
                        return true;
                    }

                    int k = stones[i] - stones[j];  // 从j到i跳动的单位
                    for (int p = -1; p <= 1; ++p) {
                        if (indices.count(stones[i] + k + p) != 0) {  // 如果下一个位置有石头
                            dp[indices[stones[i] + k + p]][indices[stones[i]]] = true;  // 那么从i到下一个石头可达
                        }
                    }
                }
            }
        }

        return false;
    }

    void getStoneIndices(vector<int>& stones, unordered_map<int, int>& indices) {
        for (int i = 0; i < (int)stones.size(); ++i) {
            indices[stones[i]] = i;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> stones = { 0,1,3,5,6,8,12,17 };
    check.checkBool(true, o.canCross(stones));

    stones = { 0,1,2,3,4,8,9,11 };
    check.checkBool(false, o.canCross(stones));

    stones = { 0,1 };
    check.checkBool(true, o.canCross(stones));

    stones = { 0,2 };
    check.checkBool(false, o.canCross(stones));
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
