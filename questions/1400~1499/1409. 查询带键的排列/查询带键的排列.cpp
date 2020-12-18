/* 查询带键的排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个待查数组 queries ，数组中的元素为 1 到 m 之间的正整数。 请你根据以下规则处理所有待查项 queries[i]（从 i=0 到 i=queries.length-1）：

一开始，排列 P=[1,2,3,...,m]。
对于当前的 i ，请你找出待查项 queries[i] 在排列 P 中的位置（下标从 0 开始），然后将其从原位置移动到排列 P 的起始位置（即下标为 0 处）。注意， queries[i] 在 P 中的位置就是 queries[i] 的查询结果。
请你以数组形式返回待查数组  queries 的查询结果。

 

示例 1：

输入：queries = [3,1,2,1], m = 5
输出：[2,1,2,1]
解释：待查数组 queries 处理如下：
对于 i=0: queries[i]=3, P=[1,2,3,4,5], 3 在 P 中的位置是 2，接着我们把 3 移动到 P 的起始位置，得到 P=[3,1,2,4,5] 。
对于 i=1: queries[i]=1, P=[3,1,2,4,5], 1 在 P 中的位置是 1，接着我们把 1 移动到 P 的起始位置，得到 P=[1,3,2,4,5] 。
对于 i=2: queries[i]=2, P=[1,3,2,4,5], 2 在 P 中的位置是 2，接着我们把 2 移动到 P 的起始位置，得到 P=[2,1,3,4,5] 。
对于 i=3: queries[i]=1, P=[2,1,3,4,5], 1 在 P 中的位置是 1，接着我们把 1 移动到 P 的起始位置，得到 P=[1,2,3,4,5] 。
因此，返回的结果数组为 [2,1,2,1] 。
示例 2：

输入：queries = [4,1,2,2], m = 4
输出：[3,1,2,0]
示例 3：

输入：queries = [7,5,5,8,3], m = 8
输出：[6,5,0,7,5]
 

提示：

1 <= m <= 10^3
1 <= queries.length <= m
1 <= queries[i] <= m

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/queries-on-a-permutation-with-key
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class BIT {
public:
    BIT(int n) {
        size = n;
        tree.resize(n + 1, 0);
    }

    int lowbit(int index) {
        return index & (-index);  // 保留最低位的1
    }

    void update(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += lowbit(index);
        }
    }

    int query(int index) {
        int value = 0;

        while (index != 0) {
            value += tree[index];
            index -= lowbit(index);
        }

        return value;
    }

private:
    int size;
    vector<int> tree;
};

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int i, j, querySize = queries.size();
        vector<int> ans(querySize);
        vector<int> indices(m + 1);
        BIT bit(m + querySize);

        for (i = 1; i <= m; ++i) {
            indices[i] = i + querySize;  // 初始化索引
            bit.update(i + querySize, 1);  // 初始化每个位置到最前面有多少个数
        }

        i = 0, j = querySize;
        for (int num : queries) {
            int index = indices[num];  // 找到查询数num的当前索引
            ans[i++] = bit.query(index) - 1;  // 查询这个位置前面有多少个数，这个个数就是num最新的索引

            bit.update(index, -1);  // 把num从index位置移到j位置，先index位置的个数-1
            bit.update(j, 1);  // 再j位置的个数+1
            indices[num] = j--;  // 更新num的索引
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;
    
    vector<int> queries = { 3,1,2,1 };
    vector<int> actual = o.processQueries(queries, 5);
    vector<int> expected = { 2,1,2,1 };
    check.checkIntVector(expected, actual);

    queries = { 4,1,2,2 };
    actual = o.processQueries(queries, 4);
    expected = { 3,1,2,0 };
    check.checkIntVector(expected, actual);

    queries = { 7,5,5,8,3 };
    actual = o.processQueries(queries, 8);
    expected = { 6,5,0,7,5 };
    check.checkIntVector(expected, actual);

    queries = { 1,1,1 };
    actual = o.processQueries(queries, 1);
    expected = { 0,0,0 };
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
