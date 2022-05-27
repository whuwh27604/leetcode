/* 烹饪料理.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
欢迎各位勇者来到力扣城，城内设有烹饪锅供勇者制作料理，为自己恢复状态。

勇者背包内共有编号为 0 ~ 4 的五种食材，其中 materials[j] 表示第 j 种食材的数量。通过这些食材可以制作若干料理，cookbooks[i][j] 表示制作第 i 种料理需要第 j 种食材的数量，而 attribute[i] = [x,y] 表示第 i 道料理的美味度 x 和饱腹感 y。

在饱腹感不小于 limit 的情况下，请返回勇者可获得的最大美味度。如果无法满足饱腹感要求，则返回 -1。

注意：

每种料理只能制作一次。
示例 1：

输入：materials = [3,2,4,1,2]
cookbooks = [[1,1,0,1,2],[2,1,4,0,0],[3,2,4,1,0]]
attribute = [[3,2],[2,4],[7,6]]
limit = 5

输出：7

解释：
食材数量可以满足以下两种方案：
方案一：制作料理 0 和料理 1，可获得饱腹感 2+4、美味度 3+2
方案二：仅制作料理 2， 可饱腹感为 6、美味度为 7
因此在满足饱腹感的要求下，可获得最高美味度 7

示例 2：

输入：materials = [10,10,10,10,10]
cookbooks = [[1,1,1,1,1],[3,3,3,3,3],[10,10,10,10,10]]
attribute = [[5,5],[6,6],[10,10]]
limit = 1

输出：11

解释：通过制作料理 0 和 1，可满足饱腹感，并获得最高美味度 11

提示：

materials.length == 5
1 <= cookbooks.length == attribute.length <= 8
cookbooks[i].length == 5
attribute[i].length == 2
0 <= materials[i], cookbooks[i][j], attribute[i][j] <= 20
1 <= limit <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/UEcfPD
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
        int size = cookbooks.size(), mask, maxMask = (1 << size), maxTasty = -1;

        for (mask = 1; mask < maxMask; ++mask) {
            int tasty = 0, satiety = 0;

            if (possible(materials, cookbooks, attribute, mask, tasty, satiety) && satiety >= limit) {
                maxTasty = max(maxTasty, tasty);
            }
        }

        return maxTasty;
    }

    bool possible(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int mask, int& tasty, int& satiety) {
        vector<int> count(5, 0);

        for (int i = 0, bit = 1; i < (int)cookbooks.size(); ++i, bit <<= 1) {
            if ((mask & bit) != 0) {
                add(count, cookbooks[i]);
                tasty += attribute[i][0];
                satiety += attribute[i][1];
            }
        }

        return lessEqual(count, materials);
    }

    void add(vector<int>& v1, vector<int>& v2) {
        for (int i = 0; i < 5; ++i) {
            v1[i] += v2[i];
        }
    }

    bool lessEqual(vector<int>& v1, vector<int>& v2) {
        for (int i = 0; i < 5; ++i) {
            if (v1[i] > v2[i]) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> materials = { 3,2,4,1,2 };
    vector<vector<int>> cookbooks = { {1,1,0,1,2},{2,1,4,0,0},{3,2,4,1,0} };
    vector<vector<int>> attribute = { {3,2},{2,4},{7,6} };
    check.checkInt(7, o.perfectMenu(materials, cookbooks, attribute, 5));

    materials = { 10,10,10,10,10 };
    cookbooks = { {1,1,1,1,1},{3,3,3,3,3},{10,10,10,10,10} };
    attribute = { {5,5},{6,6},{10,10} };
    check.checkInt(11, o.perfectMenu(materials, cookbooks, attribute, 1));
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
