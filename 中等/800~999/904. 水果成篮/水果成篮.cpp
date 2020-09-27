/* 水果成篮.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一排树中，第 i 棵树产生 tree[i] 型的水果。
你可以从你选择的任何树开始，然后重复执行以下步骤：

把这棵树上的水果放进你的篮子里。如果你做不到，就停下来。
移动到当前树右侧的下一棵树。如果右边没有树，就停下来。
请注意，在选择一颗树后，你没有任何选择：你必须执行步骤 1，然后执行步骤 2，然后返回步骤 1，然后执行步骤 2，依此类推，直至停止。

你有两个篮子，每个篮子可以携带任何数量的水果，但你希望每个篮子只携带一种类型的水果。

用这个程序你能收集的水果树的最大总量是多少？

 

示例 1：

输入：[1,2,1]
输出：3
解释：我们可以收集 [1,2,1]。
示例 2：

输入：[0,1,2,2]
输出：3
解释：我们可以收集 [1,2,2]
如果我们从第一棵树开始，我们将只能收集到 [0, 1]。
示例 3：

输入：[1,2,3,2,2]
输出：4
解释：我们可以收集 [2,3,2,2]
如果我们从第一棵树开始，我们将只能收集到 [1, 2]。
示例 4：

输入：[3,3,3,1,2,1,1,2,3,3,4]
输出：5
解释：我们可以收集 [1,2,1,1,2]
如果我们从第一棵树或第八棵树开始，我们将只能收集到 4 棵水果树。
 

提示：

1 <= tree.length <= 40000
0 <= tree[i] < tree.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fruit-into-baskets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int left = 0, right = 1, size = tree.size();
        int a = tree[0], countA = 1, maxTrees = 0;

        while (right < size && tree[right] == a) {
            ++countA;
            ++right;
        }

        if (right == size) {
            return size;
        }

        int b = tree[right++], countB = 1;

        while (right < size) {
            if (tree[right] == a) {
                ++countA;
            }
            else if (tree[right] == b) {
                ++countB;
            }
            else {
                maxTrees = max(maxTrees, right - left);

                while (countA != 0 && countB != 0) {  // 收缩窗口，a和b其中一个全部踢出
                    if (tree[left] == a) {
                        --countA;
                    }
                    else if (tree[left] == b) {
                        --countB;
                    }

                    ++left;
                }

                if (countA == 0) {
                    a = b;
                    countA = countB;
                }
                b = tree[right];
                countB = 1;
            }

            ++right;
        }

        return max(maxTrees, right - left);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> tree = { 1,2,1 };
    check.checkInt(3, o.totalFruit(tree));

    tree = { 0,1,2,2 };
    check.checkInt(3, o.totalFruit(tree));

    tree = { 3,3,3,1,2,1,1,2,3,3,4 };
    check.checkInt(5, o.totalFruit(tree));

    tree = { 1,2,3,2,2 };
    check.checkInt(4, o.totalFruit(tree));

    tree = { 1 };
    check.checkInt(1, o.totalFruit(tree));

    tree = { 1,1 };
    check.checkInt(2, o.totalFruit(tree));

    tree = { 1,2 };
    check.checkInt(2, o.totalFruit(tree));

    tree = { 1,0,1,4,1,4,1,2,3 };
    check.checkInt(5, o.totalFruit(tree));
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
