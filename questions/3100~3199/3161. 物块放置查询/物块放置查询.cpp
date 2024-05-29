/* 物块放置查询.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一条无限长的数轴，原点在 0 处，沿着 x 轴 正 方向无限延伸。

给你一个二维数组 queries ，它包含两种操作：

操作类型 1 ：queries[i] = [1, x] 。在距离原点 x 处建一个障碍物。数据保证当操作执行的时候，位置 x 处 没有 任何障碍物。
操作类型 2 ：queries[i] = [2, x, sz] 。判断在数轴范围 [0, x] 内是否可以放置一个长度为 sz 的物块，这个物块需要 完全 放置在范围 [0, x] 内。如果物块与任何障碍物有重合，那么这个物块 不能 被放置，但物块可以与障碍物刚好接触。注意，你只是进行查询，并 不是 真的放置这个物块。每个查询都是相互独立的。
请你返回一个 boolean 数组results ，如果第 i 个操作类型 2 的操作你可以放置物块，那么 results[i] 为 true ，否则为 false 。



示例 1：

输入：queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]

输出：[false,true,true]

解释：



查询 0 ，在 x = 2 处放置一个障碍物。在 x = 3 之前任何大小不超过 2 的物块都可以被放置。

示例 2：

输入：queries = [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]

输出：[true,true,false]

解释：



查询 0 在 x = 7 处放置一个障碍物。在 x = 7 之前任何大小不超过 7 的物块都可以被放置。
查询 2 在 x = 2 处放置一个障碍物。现在，在 x = 7 之前任何大小不超过 5 的物块可以被放置，x = 2 之前任何大小不超过 2 的物块可以被放置。


提示：

1 <= queries.length <= 15 * 104
2 <= queries[i].length <= 3
1 <= queries[i][0] <= 2
1 <= x, sz <= min(5 * 104, 3 * queries.length)
输入保证操作 1 中，x 处不会有障碍物。
输入保证至少有一个操作类型 2 。
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class SegmentTree {
public:
    SegmentTree(vector<int>& nums) {
        size = (int)nums.size();
        tree.resize(2 * size, 0);
        init(nums);
    }

    void update(int index, int value) {
        index += size;
        tree[index] = value;
        index >>= 1;

        while (index != 0) {
            tree[index] = max(tree[index * 2], tree[index * 2 + 1]);
            index >>= 1;
        }
    }

    int query(int left, int right) {
        left += size;
        right += size;
        int maximun = 0;

        while (left <= right) {
            if ((left & 1) == 1) {
                maximun = max(maximun, tree[left]);
                ++left;
            }

            if ((right & 1) == 0) {
                maximun = max(maximun, tree[right]);
                --right;
            }

            left >>= 1;
            right >>= 1;
        }

        return maximun;
    }

private:
    void init(vector<int>& nums) {
        for (int i = 0, j = size; i < size; ++i, ++j) {
            tree[j] = nums[i];
        }

        for (int i = size - 1; i > 0; --i) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }

    vector<int> tree;
    int size;
};

class Section {
public:
	int start;
	int end;

	Section() : start(0), end(0) {}
	Section(int s, int e) : start(s), end(e) {}

	bool operator<(const Section& o) const {
		return start < o.start;
	}
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
		int size = (int)queries.size(), maxNum = min(50000, size * 3);
		set<Section> sections;
		sections.insert(Section(0, maxNum));  // 预置一个全段section
        vector<int> tmp(maxNum + 1, 0);
        SegmentTree tree(tmp);  // 用线段树维护区间最大值
        tree.update(maxNum, maxNum);  // 一个section的长度设置在坐标end的位置
		vector<bool> ans;

		for (auto& query : queries) {
			if (query[0] == 1) {
				buildObstacle(query[1], sections, tree);
			}
			else {
				ans.push_back(canPlaceBlock(query[1], query[2], sections, tree));
			}
		}

		return ans;
    }

	void buildObstacle(int x, set<Section>& sections, SegmentTree& tree) {
        Section sec(x, x);
        auto iter = sections.upper_bound(sec);
        --iter;  // 包含x的section
        int start = iter->start, end = iter->end;
        sections.erase(iter);  // 删除原来的section
        tree.update(end, 0);  // 该长度的section没有了
        sections.insert(Section(start, x));  // 新增前半段section
        tree.update(x, x - start);  // 新增长度
        sections.insert(Section(x, end));  // 新增后半段section
        tree.update(end, end - x);  // 新增长度
	}

	bool canPlaceBlock(int x, int sz, set<Section>& sections, SegmentTree& tree) {
        if (x < sz) {
            return false;
        }

        Section sec(x, x);
        auto iter = sections.upper_bound(sec);
        --iter;  // 包含x的section

        // 当前section前面的section的最大长度通过tree查询，当前section从start到x也可以放置block
        return tree.query(0, iter->start) >= sz || x - iter->start >= sz;
	}
};

int main()
{
	Solution o;
	CheckResult check;

    vector<vector<int>> queries = { {1,2},{2,3,3},{2,3,1},{2,2,2} };
    vector<bool> actual = o.getResults(queries);
    vector<bool> expected = { false,true,true };
    check.checkBoolVector(expected, actual);

    queries = { {1,7},{2,7,6},{1,2},{2,7,5},{2,7,6} };
    actual = o.getResults(queries);
    expected = { true,true,false };
    check.checkBoolVector(expected, actual);
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
