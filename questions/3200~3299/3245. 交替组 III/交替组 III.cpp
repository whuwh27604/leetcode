/* 交替组 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 colors 和一个二维整数数组 queries 。colors表示一个由红色和蓝色瓷砖组成的环，第 i 块瓷砖的颜色为 colors[i] ：

colors[i] == 0 表示第 i 块瓷砖的颜色是 红色 。
colors[i] == 1 表示第 i 块瓷砖的颜色是 蓝色 。
环中连续若干块瓷砖的颜色如果是 交替 颜色（也就是说这组瓷砖中除了第一块和最后一块瓷砖以外，中间瓷砖的颜色与它 左边 和 右边 的颜色都不同），那么它被称为一个 交替组。

你需要处理两种类型的查询：

queries[i] = [1, sizei]，确定大小为sizei的 交替组 的数量。
queries[i] = [2, indexi, colori]，将colors[indexi]更改为colori。
返回数组 answer，数组中按顺序包含第一种类型查询的结果。

注意 ，由于 colors 表示一个 环 ，第一块 瓷砖和 最后一块 瓷砖是相邻的。



示例 1：

输入：colors = [0,1,1,0,1], queries = [[2,1,0],[1,4]]

输出：[2]

解释：

第一次查询：

将 colors[1] 改为 0。



第二次查询：

统计大小为 4 的交替组的数量：



示例 2：

输入：colors = [0,0,1,0,1,1], queries = [[1,3],[2,3,0],[1,5]]

输出：[2,0]

解释：



第一次查询：

统计大小为 3 的交替组的数量。



第二次查询：colors不变。

第三次查询：不存在大小为 5 的交替组。



提示：

4 <= colors.length <= 5 * 104
0 <= colors[i] <= 1
1 <= queries.length <= 5 * 104
queries[i][0] == 1 或 queries[i][0] == 2
对于所有的i：
queries[i][0] == 1： queries[i].length == 2, 3 <= queries[i][1] <= colors.length - 1
queries[i][0] == 2： queries[i].length == 3, 0 <= queries[i][1] <= colors.length - 1, 0 <= queries[i][2] <= 1
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class BIT {
public:
    BIT(int n) {
        maxLen = n;
        cntSum.resize(n + 1, 0);
        lenCntSum.resize(n + 1, 0);
    }

    int lowbit(int index) {
        return index & (-index);  // 保留最低位的1
    }

    void update(int len, int value) {
        int val = len * value;

        while (len <= maxLen) {
            cntSum[len] += value;
            lenCntSum[len] += val;
            len += lowbit(len);
        }
    }

    int queryCntSum(int len) {
        int sum = 0;

        while (len != 0) {
            sum += cntSum[len];
            len -= lowbit(len);
        }

        return sum;
    }

    int queryLenCntSum(int len) {
        int sum = 0;

        while (len != 0) {
            sum += lenCntSum[len];
            len -= lowbit(len);
        }

        return sum;
    }

private:
    int maxLen;
    vector<int> cntSum;
    vector<int> lenCntSum;
};

class AlterGroup {
public:
    int left;
    int right;
    int circle;

    AlterGroup(int l, int r, int c) : left(l), right(r), circle(c) {}

    bool operator<(const AlterGroup& s) const {
        return left < s.left;
    }

    int getLen() const {
        return right < left ? right - left + 1 + circle : right - left + 1;
    }
};

class Solution {
public:
    vector<int> numberOfAlternatingGroups(vector<int>& colors, vector<vector<int>>& queries) {
        int n = (int)colors.size();
        set<AlterGroup> groups;
        BIT tree(n);
        vector<int> ans;

        init(n, colors, groups, tree);

        for (auto& query : queries) {
            if (query.size() == 2) {
                int size = query[1];
                if (n % 2 == 0 && groups.size() == 1) {
                    ans.push_back(n);
                }
                else {
                    ans.push_back((tree.queryLenCntSum(n) - tree.queryLenCntSum(size - 1)) - (tree.queryCntSum(n) - tree.queryCntSum(size - 1)) * (size - 1));
                }
            }
            else {
                int idx = query[1], color = query[2];
                if (colors[idx] != color) {
                    colors[idx] = color;
                    modifyColor(n, idx, groups, tree);
                }
            }
        }

        return ans;
    }

    void init(int n, vector<int>& colors, set<AlterGroup>& groups, BIT& tree) {
        int prev = colors[0];
        AlterGroup group(0, 0, n);

        for (int i = 1; i < n; ++i) {
            int cur = colors[i];
            if ((prev ^ cur) == 0) {
                group.right = i - 1;
                add(group, groups, tree);
                group.left = i;
            }

            prev = cur;
        }

        if ((colors[n - 1] ^ colors[0]) == 0) {  // 首尾不相连
            group.right = n - 1;
            add(group, groups, tree);
        }
        else {  // 首尾相连
            if (groups.empty()) {  // 总共只有一个区间
                group.right = n - 1;
                add(group, groups, tree);
            }
            else {  // 有多个区间，先删除原来的第一个，最后一个区间连到原来的第一个
                group.right = groups.begin()->right;
                del(groups.begin(), groups, tree);
                add(group, groups, tree);
            }
        }
    }

    void modifyColor(int n, int idx, set<AlterGroup>& groups, BIT& tree) {
        auto cur = find(groups, idx);

        if (groups.size() == 1) {
            modify1(n, idx, cur, groups, tree);
        }
        else if (groups.size() == 2) {
            modify2(n, idx, cur, groups, tree);
        }
        else {
            modify3(n, idx, cur, groups, tree);
        }
    }

    void modify1(int n, int idx, set<AlterGroup>::iterator cur, set<AlterGroup>& groups, BIT& tree) {
        if ((n & 1) == 0) {  // 偶数个节点的环，从修改点断开
            AlterGroup s1(idx, idx, n), s2((idx + 1) % n, (idx - 1 + n) % n, n);
            del(cur, groups, tree);
            add(s1, groups, tree);
            add(s2, groups, tree);
        }
        else {  // 奇数个节点的环
            if (idx == cur->left || idx == cur->right) {  // 修改首尾端点后还是1个区间，只是首尾挪动了1
                AlterGroup s1 = *cur;
                s1.left = (idx == cur->left ? (idx + 1) % n : idx);
                s1.right = (idx == cur->left ? idx : (idx - 1 + n) % n);
                del(cur, groups, tree);
                add(s1, groups, tree);
            }
            else {  // 修改中间节点变为3个区间
                modifyMiddle(n, idx, cur, groups, tree);
            }
        }
    }

    void modify2(int n, int idx, set<AlterGroup>::iterator cur, set<AlterGroup>& groups, BIT& tree) {
        if (cur->getLen() == 1) {  // 当前区间只有1个节点，修改后变为一个环
            AlterGroup s1(0, n - 1, n);
            del(cur, groups, tree);
            del(groups.begin(), groups, tree);  // 清空所有区间
            add(s1, groups, tree);
        }
        else {
            if (idx == cur->left) {
                modifyLeft(n, idx, cur, groups, tree);
            }
            else if (idx == cur->right) {
                modifyRight(n, idx, cur, groups, tree);
            }
            else {
                modifyMiddle(n, idx, cur, groups, tree);
            }
        }
    }

    void modify3(int n, int idx, set<AlterGroup>::iterator cur, set<AlterGroup>& groups, BIT& tree) {
        if (cur->getLen() == 1) {  // 当前区间只有1个节点，修改后连通前后区间
            auto prev = cur;
            prev = (prev == groups.begin() ? --groups.end() : --prev);
            auto next = cur;
            next = (next == --groups.end() ? groups.begin() : ++next);
            AlterGroup s1(prev->left, next->right, n);
            del(prev, groups, tree);
            del(cur, groups, tree);
            del(next, groups, tree);
            add(s1, groups, tree);
        }
        else {
            if (idx == cur->left) {
                modifyLeft(n, idx, cur, groups, tree);
            }
            else if (idx == cur->right) {
                modifyRight(n, idx, cur, groups, tree);
            }
            else {
                modifyMiddle(n, idx, cur, groups, tree);
            }
        }
    }

    void modifyMiddle(int n, int idx, set<AlterGroup>::iterator cur, set<AlterGroup>& groups, BIT& tree) {
        AlterGroup s1(cur->left, (idx - 1 + n) % n, n), s2(idx, idx, n), s3((idx + 1) % n, cur->right, n);
        del(cur, groups, tree);
        add(s1, groups, tree);
        add(s2, groups, tree);
        add(s3, groups, tree);
    }

    void modifyLeft(int n, int idx, set<AlterGroup>::iterator cur, set<AlterGroup>& groups, BIT& tree) {
        auto prev = cur;
        prev = (prev == groups.begin() ? --groups.end() : --prev);
        AlterGroup s1(prev->left, idx, n), s2((idx + 1) % n, cur->right, n);
        del(prev, groups, tree);
        del(cur, groups, tree);
        add(s1, groups, tree);
        add(s2, groups, tree);
    }

    void modifyRight(int n, int idx, set<AlterGroup>::iterator cur, set<AlterGroup>& groups, BIT& tree) {
        auto next = cur;
        next = (next == --groups.end() ? groups.begin() : ++next);
        AlterGroup s1(cur->left, (idx - 1 + n) % n, n), s2(idx, next->right, n);
        del(cur, groups, tree);
        del(next, groups, tree);
        add(s1, groups, tree);
        add(s2, groups, tree);
    }

    set<AlterGroup>::iterator find(set<AlterGroup>& groups, int idx) {
        auto iter = groups.upper_bound(AlterGroup(idx, idx, 0));
        return iter == groups.begin() ? --groups.end() : --iter;
    }

    void add(AlterGroup& group, set<AlterGroup>& groups, BIT& tree) {
        tree.update(group.getLen(), 1);  // 长度为len的区间增加1个
        groups.insert(group);
    }

    void del(set<AlterGroup>::iterator group, set<AlterGroup>& groups, BIT& tree) {
        tree.update(group->getLen(), -1);  // 长度为len的区间减少1个
        groups.erase(group);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> colors = { 0,1,1,0,1 };
    vector<vector<int>> queries = { {2,1,0},{1,4} };
    vector<int> actual = o.numberOfAlternatingGroups(colors, queries);
    vector<int> expected = { 2 };
    check.checkIntVector(expected, actual);

    colors = { 0,0,1,0,1,1 };
    queries = { {1,3},{2,3,0},{1,5} };
    actual = o.numberOfAlternatingGroups(colors, queries);
    expected = { 2,0 };
    check.checkIntVector(expected, actual);

    colors = { 0,0,0,1 };
    queries = { {2,1,1},{1,3},{2,1,1},{2,0,1} };
    actual = o.numberOfAlternatingGroups(colors, queries);
    expected = { 4 };
    check.checkIntVector(expected, actual);

    colors = { 0,1,0,1 };
    queries = { {1,3},{2,2,1},{1,3},{1,3} };
    actual = o.numberOfAlternatingGroups(colors, queries);
    expected = { 4,1,1 };
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
