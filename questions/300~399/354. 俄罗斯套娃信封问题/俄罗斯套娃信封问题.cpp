/* 俄罗斯套娃信封问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:
不允许旋转信封。

示例:

输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/russian-doll-envelopes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

// 首先按照weight升序排序，然后从height里面选出LIS就是最多的套娃。所以当weight相等时，height应该按降序排列，这样一旦选择了某个weight，相同weight的其它信封都不会出现在LIS里面。
bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] != v2[0] ? v1[0] < v2[0] : v1[1] > v2[1];
}

// 如果有相同的数，注意索引大的排在前面，这一点非常关键！因为如果先计算了索引小的，会影响后面一个数的正确性；而先计算了后面一个数不会影响前面数的正确性。
bool pairCompare(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first != p2.first ? p1.first < p2.first : p1.second > p2.second;
}

class BIT {
public:
    BIT(int n) {
        size = n;
        tree.resize(n + 1, 0);
    }

    int lowbit(int index) {
        return index & (-index);  // 保留最低位的1
    }

    void update(int index, int value) {  // 更新位置index的值
        while (index <= size) {
            tree[index] = max(tree[index], value);
            index += lowbit(index);
        }
    }

    int query(int index) {  // 查询区间[1,index]的最大值
        int value = 0;

        while (index != 0) {
            value = max(tree[index], value);
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
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), vectorCompare);

        vector<pair<int, int>> heightsIndices;
        getHeightsSequence(envelopes, heightsIndices);
        sort(heightsIndices.begin(), heightsIndices.end(), pairCompare);

        return getHeightsLIS(heightsIndices);
    }

    void getHeightsSequence(vector<vector<int>>& envelopes, vector<pair<int, int>>& heightsIndices) {
        int index = 1, prev = INT_MIN;

        for (auto& envelope : envelopes) {
            if (envelope[1] != prev) {  // 因为必须严格递增，所以连续的相同数没有意义，只保留一个就可以了
                heightsIndices.push_back({ envelope[1], index++ });
                prev = envelope[1];
            }
        }
    }

    int getHeightsLIS(vector<pair<int, int>>& heightsIndices) {
        BIT bit(heightsIndices.size());
        int maxLIS = 0;

        for (auto& heightIndex : heightsIndices) {
            // 因为heightsIndices是递增的，所以每次查询区间1到它前面一个索引的最大LIS，再加上自己就是新的最大LIS。这一步用log(n)复杂度优化了dp每次遍历前面所有LIS的过程
            int LIS = bit.query(heightIndex.second - 1) + 1;
            maxLIS = max(maxLIS, LIS);
            bit.update(heightIndex.second, LIS);  // 更新最大值受影响的区间
        }

        return maxLIS;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> envelopes = { {5,4},{6,4},{6,7},{2,3} };
    check.checkInt(3, o.maxEnvelopes(envelopes));

    envelopes = { {1,3},{1,4},{1,5},{2,3} };
    check.checkInt(1, o.maxEnvelopes(envelopes));

    envelopes = { {1,5},{1,4},{1,2},{2,3} };
    check.checkInt(2, o.maxEnvelopes(envelopes));

    envelopes = { {30,50},{12,2},{3,4},{12,15} };
    check.checkInt(3, o.maxEnvelopes(envelopes));

    envelopes = {  };
    check.checkInt(0, o.maxEnvelopes(envelopes));

    envelopes = { {30,50} };
    check.checkInt(1, o.maxEnvelopes(envelopes));

    envelopes = { {15,8},{2,20},{2,14},{4,17},{8,19},{8,9},{5,7},{11,19},{8,11},{13,11},{2,13},{11,19},{8,11},{13,11},{2,13},{11,19},{16,1},{18,13},{14,17},{18,19} };
    check.checkInt(5, o.maxEnvelopes(envelopes));
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
