/* 合并相似的物品.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个二维整数数组 items1 和 items2 ，表示两个物品集合。每个数组 items 有以下特质：

items[i] = [valuei, weighti] 其中 valuei 表示第 i 件物品的 价值 ，weighti 表示第 i 件物品的 重量 。
items 中每件物品的价值都是 唯一的 。
请你返回一个二维数组 ret，其中 ret[i] = [valuei, weighti]， weighti 是所有价值为 valuei 物品的 重量之和 。

注意：ret 应该按价值 升序 排序后返回。

 

示例 1：

输入：items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]]
输出：[[1,6],[3,9],[4,5]]
解释：
value = 1 的物品在 items1 中 weight = 1 ，在 items2 中 weight = 5 ，总重量为 1 + 5 = 6 。
value = 3 的物品再 items1 中 weight = 8 ，在 items2 中 weight = 1 ，总重量为 8 + 1 = 9 。
value = 4 的物品在 items1 中 weight = 5 ，总重量为 5 。
所以，我们返回 [[1,6],[3,9],[4,5]] 。
示例 2：

输入：items1 = [[1,1],[3,2],[2,3]], items2 = [[2,1],[3,2],[1,3]]
输出：[[1,4],[2,4],[3,4]]
解释：
value = 1 的物品在 items1 中 weight = 1 ，在 items2 中 weight = 3 ，总重量为 1 + 3 = 4 。
value = 2 的物品在 items1 中 weight = 3 ，在 items2 中 weight = 1 ，总重量为 3 + 1 = 4 。
value = 3 的物品在 items1 中 weight = 2 ，在 items2 中 weight = 2 ，总重量为 2 + 2 = 4 。
所以，我们返回 [[1,4],[2,4],[3,4]] 。
示例 3：

输入：items1 = [[1,3],[2,2]], items2 = [[7,1],[2,2],[1,4]]
输出：[[1,7],[2,4],[7,1]]
解释：
value = 1 的物品在 items1 中 weight = 3 ，在 items2 中 weight = 4 ，总重量为 3 + 4 = 7 。
value = 2 的物品在 items1 中 weight = 2 ，在 items2 中 weight = 2 ，总重量为 2 + 2 = 4 。
value = 7 的物品在 items2 中 weight = 1 ，总重量为 1 。
所以，我们返回 [[1,7],[2,4],[7,1]] 。
 

提示：

1 <= items1.length, items2.length <= 1000
items1[i].length == items2[i].length == 2
1 <= valuei, weighti <= 1000
items1 中每个 valuei 都是 唯一的 。
items2 中每个 valuei 都是 唯一的 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/merge-similar-items
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<int> weights(1001, 0);

        getWeightSum(items1, weights);
        getWeightSum(items2, weights);

        return getValueWeights(weights);
    }

    void getWeightSum(vector<vector<int>>& items, vector<int>& weights) {
        for (auto& item : items) {
            weights[item[0]] += item[1];
        }
    }

    vector<vector<int>> getValueWeights(vector<int>& weights) {
        vector<vector<int>> valueWeights;

        for (int value = 1; value < 1001; ++value) {
            if (weights[value] != 0) {
                valueWeights.push_back({ value, weights[value] });
            }
        }

        return valueWeights;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> items1 = { {1,1},{4,5},{3,8} };
    vector<vector<int>> items2 = { {3,1},{1,5} };
    vector<vector<int>> actual = o.mergeSimilarItems(items1, items2);
    vector<vector<int>> expected = { {1,6},{3,9},{4,5} };
    check.checkIntVectorVector(expected, actual);

    items1 = { {1,1},{3,2},{2,3} };
    items2 = { {2,1},{3,2},{1,3} };
    actual = o.mergeSimilarItems(items1, items2);
    expected = { {1,4},{2,4},{3,4} };
    check.checkIntVectorVector(expected, actual);

    items1 = { {1,3},{2,2} };
    items2 = { {7,1},{2,2},{1,4} };
    actual = o.mergeSimilarItems(items1, items2);
    expected = { {1,7},{2,4},{7,1} };
    check.checkIntVectorVector(expected, actual);
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
