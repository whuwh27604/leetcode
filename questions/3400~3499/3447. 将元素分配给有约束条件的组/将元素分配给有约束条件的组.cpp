/* 将元素分配给有约束条件的组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 groups，其中 groups[i] 表示第 i 组的大小。另给你一个整数数组 elements。

请你根据以下规则为每个组分配 一个 元素：

如果 groups[i] 能被 elements[j] 整除，则元素 j 可以分配给组 i。
如果有多个元素满足条件，则分配下标最小的元素  j 。
如果没有元素满足条件，则分配 -1 。
返回一个整数数组 assigned，其中 assigned[i] 是分配给组 i 的元素的索引，若无合适的元素，则为 -1。

注意：一个元素可以分配给多个组。



示例 1：

输入： groups = [8,4,3,2,4], elements = [4,2]

输出： [0,0,-1,1,0]

解释：

elements[0] = 4 被分配给组 0、1 和 4。
elements[1] = 2 被分配给组 3。
无法为组 2 分配任何元素，分配 -1 。
示例 2：

输入： groups = [2,3,5,7], elements = [5,3,3]

输出： [-1,1,0,-1]

解释：

elements[1] = 3 被分配给组 1。
elements[0] = 5 被分配给组 2。
无法为组 0 和组 3 分配任何元素，分配 -1 。
示例 3：

输入： groups = [10,21,30,41], elements = [2,1]

输出： [0,1,0,1]

解释：

elements[0] = 2 被分配给所有偶数值的组，而 elements[1] = 1 被分配给所有奇数值的组。



提示：

1 <= groups.length <= 105
1 <= elements.length <= 105
1 <= groups[i] <= 105
1 <= elements[i] <= 105
*/

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        unordered_set<int> visited;
        unordered_map<int, vector<int>> numIndices;
        int maxNum = 0;
        int size = (int)groups.size();
        vector<int> ans(size, -1);

        for (int i = 0; i < size; ++i) {
            numIndices[groups[i]].push_back(i);
            maxNum = max(maxNum, groups[i]);
        }

        for (int j = 0; j < (int)elements.size(); ++j) {
            int num = elements[j];
            if (visited.count(num) != 0) {
                continue;
            }

            if (num == 1) {
                for (int i = 0; i < size; ++i) {
                    if (ans[i] == -1) {
                        ans[i] = j;
                    }
                }

                break;
            }

            for (int n = num; n <= maxNum; n += num) {
                if (numIndices.count(n) != 0) {
                    for (int idx : numIndices[n]) {
                        if (ans[idx] == -1) {
                            ans[idx] = j;
                        }
                    }

                    numIndices.erase(n);
                }
            }

            visited.insert(num);
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> groups = { 8,4,3,2,4 };
    vector<int> elements = { 4,2 };
    vector<int> actual = o.assignElements(groups, elements);
    vector<int> expected = { 0,0,-1,1,0 };
    check.checkIntVector(expected, actual);

    groups = { 2,3,5,7 };
    elements = { 5,3,3 };
    actual = o.assignElements(groups, elements);
    expected = { -1,1,0,-1 };
    check.checkIntVector(expected, actual);

    groups = { 10,21,30,41 };
    elements = { 2,1 };
    actual = o.assignElements(groups, elements);
    expected = { 0,1,0,1 };
    check.checkIntVector(expected, actual);
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
