/* 装包裹的最小浪费空间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你 n 个包裹，你需要把它们装在箱子里，每个箱子装一个包裹。总共有 m 个供应商提供 不同尺寸 的箱子（每个规格都有无数个箱子）。如果一个包裹的尺寸 小于等于 一个箱子的尺寸，那么这个包裹就可以放入这个箱子之中。

包裹的尺寸用一个整数数组 packages 表示，其中 packages[i] 是第 i 个包裹的尺寸。供应商用二维数组 boxes 表示，其中 boxes[j] 是第 j 个供应商提供的所有箱子尺寸的数组。

你想要选择 一个供应商 并只使用该供应商提供的箱子，使得 总浪费空间最小 。对于每个装了包裹的箱子，我们定义 浪费的 空间等于 箱子的尺寸 - 包裹的尺寸 。总浪费空间 为 所有 箱子中浪费空间的总和。

比方说，如果你想要用尺寸数组为 [4,8] 的箱子装下尺寸为 [2,3,5] 的包裹，你可以将尺寸为 2 和 3 的两个包裹装入两个尺寸为 4 的箱子中，同时把尺寸为 5 的包裹装入尺寸为 8 的箱子中。总浪费空间为 (4-2) + (4-3) + (8-5) = 6 。
请你选择 最优 箱子供应商，使得 总浪费空间最小 。如果 无法 将所有包裹放入箱子中，请你返回 -1 。由于答案可能会 很大 ，请返回它对 109 + 7 取余 的结果。

 

示例 1：

输入：packages = [2,3,5], boxes = [[4,8],[2,8]]
输出：6
解释：选择第一个供应商最优，用两个尺寸为 4 的箱子和一个尺寸为 8 的箱子。
总浪费空间为 (4-2) + (4-3) + (8-5) = 6 。
示例 2：

输入：packages = [2,3,5], boxes = [[1,4],[2,3],[3,4]]
输出：-1
解释：没有箱子能装下尺寸为 5 的包裹。
示例 3：

输入：packages = [3,5,8,10,11,12], boxes = [[12],[11,9],[10,5,14]]
输出：9
解释：选择第三个供应商最优，用两个尺寸为 5 的箱子，两个尺寸为 10 的箱子和两个尺寸为 14 的箱子。
总浪费空间为 (5-3) + (5-5) + (10-8) + (10-10) + (14-11) + (14-12) = 9 。
 

提示：

n == packages.length
m == boxes.length
1 <= n <= 105
1 <= m <= 105
1 <= packages[i] <= 105
1 <= boxes[j].length <= 105
1 <= boxes[j][k] <= 105
sum(boxes[j].length) <= 105
boxes[j] 中的元素 互不相同 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-space-wasted-from-packaging
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        vector<long long> presums(packages.size() + 1);
        int maxBox = getMaxBox(boxes);
        vector<bool> isBox(maxBox + 1, false);
        vector<int> packagesInBox(maxBox + 1, 0);

        sort(packages.begin(), packages.end());
        getPresums(packages, presums);
        getBoxes(boxes, isBox);
        getPackagesInBox(packages, isBox, packagesInBox);

        return getMinWasted(packages, presums, boxes, packagesInBox);
    }

    void getPresums(vector<int>& packages, vector<long long>& presums) {
        presums[0] = 0;

        for (int i = 0; i < (int)packages.size(); ++i) {
            presums[i + 1] = presums[i] + packages[i];
        }
    }

    int getMaxBox(vector<vector<int>>& boxes) {
        int maxBox = 0;

        for (auto& suppliers : boxes) {
            for (int box : suppliers) {
                maxBox = max(maxBox, box);
            }
        }

        return maxBox;
    }

    void getBoxes(vector<vector<int>>& boxes, vector<bool>& isBox) {
        for (auto& suppliers : boxes) {
            for (int box : suppliers) {
                isBox[box] = true;
            }
        }
    }

    void getPackagesInBox(vector<int>& packages, vector<bool>& isBox, vector<int>& packagesInBox) {
        int box, package = 0, size = isBox.size();

        for (box = 1; box < size; ++box) {
            if (isBox[box]) {
                for (; package < (int)packages.size() && packages[package] <= box; ++package) {}

                packagesInBox[box] = package;
            }
        }
    }

    int getMinWasted(vector<int>& packages, vector<long long>& presums, vector<vector<int>>& boxes, vector<int>& packagesInBox) {
        long long minWasted = LLONG_MAX;

        for (auto& suppliers : boxes) {
            sort(suppliers.begin(), suppliers.end());

            if (suppliers.back() < packages.back()) {
                continue;
            }

            int prev = packagesInBox[suppliers[0]];
            long long wasted = (long long)suppliers[0] * prev - presums[prev];

            for (int i = 1; i < (int)suppliers.size(); ++i) {
                int current = packagesInBox[suppliers[i]];
                wasted += ((long long)suppliers[i] * ((long long)current - prev) - (presums[current] - presums[prev]));
                prev = current;
            }

            minWasted = min(minWasted, wasted);
        }

        return minWasted == LLONG_MAX ? -1 : (int)(minWasted % 1000000007);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> packages = { 2,3,5 };
    vector<vector<int>> boxes = { {4,8},{2,8} };
    check.checkInt(6, o.minWastedSpace(packages, boxes));

    packages = { 2,3,5 };
    boxes = { {1,4},{2,3},{3,4} };
    check.checkInt(-1, o.minWastedSpace(packages, boxes));

    packages = { 3,5,8,10,11,12 };
    boxes = { {12},{11,9},{10,5,14} };
    check.checkInt(9, o.minWastedSpace(packages, boxes));

    packages = { 3 };
    boxes = { {2} };
    check.checkInt(-1, o.minWastedSpace(packages, boxes));

    packages = { 3 };
    boxes = { {3} };
    check.checkInt(0, o.minWastedSpace(packages, boxes));
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
